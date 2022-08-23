#include <stdio.h>
#include <math.h>

enum Root_Count_Codes {
    INF_ROOT_NUM = 3,
    ERROR = 4
};

char Quadratic_Equation(double a, double b, double c, double* x1, double* x2);
char True_Quadratic_Equation(double a, double b, double c, double* x1, double* x2);

int main() {

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 1111;
    double x2 = 1111;
    char root_count = 0;

    printf("Enter 3 coefficients of the quadratic equation\n");
    scanf("%lg %lg %lg", &a, &b, &c);

    root_count = Quadratic_Equation(a, b, c, &x1, &x2);
    if (root_count == 0) {
        printf("No roots\n");
    }
    if (root_count == 1) {
        printf("x = %lg\n", x1);
    }
    if (root_count == 2) {
        printf("x1 = %lg; x2 = %lg\n", x1, x2);
    }
    if (root_count == INF_ROOT_NUM) {
        printf("Infinite number of roots\n");
    }
    if (root_count == ERROR) {
        printf("Error: incorrect input\n");
    }
    return 0;
}


char Quadratic_Equation(double a, double b, double c, double* x1, double* x2) {

    if (a == 0 && b == 0 && c == 0) {
        return INF_ROOT_NUM;
    }
    if (a == 0 && b == 0 && c != 0) {
        return 0;
    }
    if (a == 0 && b != 0 && c == 0) {
        *x1 = 0;
        return 1;
    }
    if (a == 0 && b != 0 && c != 0) {
        *x1 = -c/b;
        return 1;
    }
    //---------------------------------------------------------------
    if (a != 0 && b == 0 && c == 0) {
        *x1 = 0;
        return 1;
    }
    if (a != 0 && b == 0 && c > 0) {
        *x1 = sqrt(a);
        return 1;
    }
    if (a != 0 && b == 0 && c < 0) {
        return 0;
    }
    if (a != 0 && b != 0 && c == 0) {
        *x1 = 0;
        *x2 = -b/a;
        return 2;
    }
    //---------------------------------------------------------------
    if (a != 0 && b != 0 && c != 0) {
        return True_Quadratic_Equation(a, b, c, x1, x2);
    }

    return ERROR;
}


char True_Quadratic_Equation(double a, double b, double c, double* x1, double* x2) {

    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return 0;
    }
    if (discriminant == 0) {
        *x1 = -b/a/2;
        return 1;
    }
    if (discriminant > 0) {
        *x1 = (-b - sqrt(discriminant)) /a /2;
        *x2 = (-b + sqrt(discriminant)) /a /2;
        return 2;
    }
    return ERROR;
}
