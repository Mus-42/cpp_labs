#include <string>
#include <string_view>
#include <iostream>

// lab17 Task 2

class Human {
public:
    Human() noexcept = default;

    Human(std::string name, unsigned age, bool gender) noexcept : m_name(std::move(name)), m_age(age), m_gender(gender) {}

protected:
    std::string m_name;
    unsigned m_age;
    bool m_gender;
};

class HumanWithUniversity: public Human {
public:
    HumanWithUniversity() noexcept = default;
    HumanWithUniversity(std::string name, unsigned age, bool gender, std::string university) noexcept : Human(name, age, gender), m_university(std::move(university)) {}

    std::string_view get_university() const {
        return m_university;
    }
protected:
    std::string m_university;
};

class Student: virtual public HumanWithUniversity {
public:
    Student() noexcept = default;
    Student(std::string name, unsigned age, bool gender, std::string university, unsigned course) noexcept : HumanWithUniversity(name, age, gender, university), m_course(course) {}

protected:
    unsigned m_course;
};

class Lecturer: virtual public HumanWithUniversity {
public:
    Lecturer() noexcept = default;
    Lecturer(std::string name, unsigned age, bool gender, std::string university, std::string job_pos, unsigned salary) noexcept :
        HumanWithUniversity(name, age, gender, university), m_job_pos(std::move(job_pos)), m_salry(salary)  {}


protected:
    std::string m_job_pos;
    unsigned m_salry;
};

class Postgraduate: public Student, Lecturer {
public:
    Postgraduate() noexcept = default;

    Postgraduate(std::string name, unsigned age, bool gender, std::string university, unsigned course, std::string job_pos, unsigned salary) noexcept :
        Student(name, age, gender, university, course), Lecturer(name, age, gender, university, job_pos, salary) {}
};

int main() {
    auto s = Student("mimsus", 42, false, "KNU", 2);
    auto l = Lecturer("viktor", 26, true, "LNU", "st1", 1);
    auto p = Postgraduate("bibr", 26, true, "KPI", 4, "st0", 0);

    HumanWithUniversity* humans[3] = {&s, &l, &p};
    for (auto& h : humans) {
        std::cout << h->get_university() << std::endl;
    }
}