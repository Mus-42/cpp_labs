#include <iostream>
#include <numbers>
#include <cmath>

// Lab 16 Task 7

struct Vec2 {
    float x, y;
};

struct Shape {
    Shape() = default;

    virtual float area() const = 0;
    virtual Vec2 mass_center() const = 0;

    virtual ~Shape() = default;
};

struct Trapeze: Shape {
    float x00, x01, y0;
    float x10, x11, y1;

    Trapeze(float x00, float x01, float y0, float x10, float x11, float y1) noexcept : x00(x00), x01(x01), y0(y0), x10(x10), x11(x11), y1(y1) {}

    virtual float area() const override {
        return (std::fabsf(x00-x01) + std::fabsf(x10-x11)) * 0.5f * std::fabsf(y1-y0);
    }
    virtual Vec2 mass_center() const override {
        float w0 = std::fabsf(x00-x01);
        float w1 = std::fabsf(x10-x11);
        return { ((x00 + x01) * w0 + (x10 + x11) * w1) * 0.5f  / (w1 + w0), (y0 * w0 + y1 * w1) / (w1 + w0) };
    }
};

struct Parallelogram: Shape {
    // point 0, 2 should be at opposite corners

    float x0, y0;
    float x1, y1;
    float x2, y2;

    Parallelogram(float x0, float y0, float x1, float y1, float x2, float y2) noexcept : x0(x0), y0(y0), x1(x1), y1(y1), x2(x2), y2(y2) {}

    virtual float area() const override {
        return std::fabsf((x0-x1)*(y2-y1) - (x2-x1)*(y0-y1)); // cross-product based area calc.
    }
    virtual Vec2 mass_center() const override {
        return { (x0 + x2) / 2.f , (y0 + y2) / 2.f };
    }
};

struct Ellipse: Shape {
    float x0, y0, a, b;

    Ellipse(float x0, float y0, float a, float b) noexcept : x0(x0), y0(y0), a(a), b(b) {}

    virtual float area() const override {
        return std::numbers::pi_v<float> * a * b;
    }
    virtual Vec2 mass_center() const override {
        return { x0, y0 };
    }
};

Vec2 common_mass_center(Shape** shapes, size_t count) {
    Vec2 c = { 0.f, 0.f };
    float m = 0.f;

    for (size_t i = 0; i < count; i++) {
        auto a = shapes[i]->area();
        auto v = shapes[i]->mass_center();

        c.x += v.x * a;
        c.y += v.y * a;
        m += a;
    }

    c.x /= m;
    c.y /= m;

    return c;
}

int main() {
    auto t = Trapeze {
        0.f, 1.f, 0.f,
        1.f, 2.f, 1.f
    };

    auto p = Parallelogram {
        1.f, 0.f,
        0.f, 0.f,
        1.f, 1.f,
    };

    auto e = Ellipse {
        0.f, 0.f,
        1.f, 2.f
    };

    Shape* shapes[3] = { &t, &p, &e };

    auto center = common_mass_center(shapes, 3);

    std::cout << center.x << ' ' << center.y << std::endl; // 0.241453 0.120726
}