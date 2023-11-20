#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Lab 10 Task 6з

typedef struct {
    struct Point3D {
        double x, y, z;
    } top_left, bottom_right;
} AABB;

AABB aabb_input() {
    AABB aabb;
    scanf("%lf%lf%lf%lf%lf%lf", 
        &aabb.top_left.x, &aabb.top_left.y, &aabb.top_left.z, 
        &aabb.bottom_right.x, &aabb.bottom_right.y, &aabb.bottom_right.z
    );
    return aabb;
}

void aabb_print(AABB* aabb) {
    printf("(%lf %lf %lf) (%lf %lf %lf)",
        aabb->top_left.x, aabb->top_left.y, aabb->top_left.z, 
        aabb->bottom_right.x, aabb->bottom_right.y, aabb->bottom_right.z
    );
}

int main(void) {
    AABB aabb = aabb_input();
    aabb_print(&aabb);
}