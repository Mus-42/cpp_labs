#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 3 Task 13.b

int main(void) {
    // |x+y| = 1
    // ax + by + c = 0
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    const double eps = 1e-9;
    
    // x+y = 1  or  x+y = -1  
    // and  ax + by + c = 0
    // can have 0 or 2 or infinity solutions

    // y = 1 - x  or  y = -1 - x
    // ax + b (1 - x) + c = 0  or  ax + b (-1 - x) + c = 0
    // x = (c +- b)/(b - a)  

    if (fabs(a-b) < eps) {
        // 0 or inf

        // if y = 1 - x or y = -1 - x is a solution
        if (fabs(c - b) < eps || fabs(c + b) < eps) {
            printf("infinity solutions\n"); 
        } else {
            printf("no solutions\n");
        }
    } else {
        double x1 = (c + b) / (b - a);
        double x2 = (c - b) / (b - a);
        printf("2 solutions: (x1, y1) = (%lf, %lf), (x2, y2) = (%lf, %lf)\n", x1, 1-x1, x2, -1-x2);
    }
}