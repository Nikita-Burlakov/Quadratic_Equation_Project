#include <stdio.h>
#include <math.h>

enum Root_Count_Codes {
    NO_ROOTS =     0,
    ONE_ROOT =     1,
    TWO_ROOTS =    2,
    INF_ROOT_NUM = 3,
    ERROR =        4
};

enum Root_Count_Codes Quadratic_Equation               (double a, double b, double c, double* x1, double* x2);
enum Root_Count_Codes Linear_Equation                  (double b, double c, double* x1);
enum Root_Count_Codes Quadratic_Equation_wo_Second_Coef(double a, double c, double* x1);
enum Root_Count_Codes Quadratic_Equation_wo_Third_Coef (double a, double b, double* x1, double* x2);
enum Root_Count_Codes True_Quadratic_Equation          (double a, double b, double c, double* x1, double* x2);
void get_double (double* inp);
void get_coefs  (double* a, double* b, double* c);


int main() {

    double a  = 0;
    double b  = 0;
    double c  = 0;
    double x1 = 1111;
    double x2 = 1111;
    char root_count = 0;

    printf("РЕШАТЕЛЬ КВАДРАТНЫХ УРАВНЕНИЙ\n");
    get_coefs(&a, &b, &c);

    root_count = Quadratic_Equation(a, b, c, &x1, &x2);
    switch(root_count)
    {
    case NO_ROOTS:
        printf("Нет корней\n");
        break;
    case ONE_ROOT:
        printf("x = %lg\n", x1);
        break;
    case TWO_ROOTS:
        printf("x1 = %lg; x2 = %lg\n", x1, x2);
        break;
    case INF_ROOT_NUM:
        printf("Бесконечно много корней\n");
        break;
    default:
        printf("Неизвестная ошибка\n");
        break;
    }
    return 0;
}


enum Root_Count_Codes Quadratic_Equation(double a, double b, double c, double* x1, double* x2) {
    if (a == 0) {
        return Linear_Equation(b, c, x1);
    }
    if (b == 0) {
        return Quadratic_Equation_wo_Second_Coef(a, c, x1);
    }
    if (c == 0) {
        return Quadratic_Equation_wo_Third_Coef(a, b, x1, x2);
    }
    if (a != 0 && b != 0 && c != 0) {
        return True_Quadratic_Equation(a, b, c, x1, x2);
    }
    return ERROR;
}


enum Root_Count_Codes Linear_Equation(double b, double c, double* x1) {
    if (b == 0) {
        if (c == 0) {
            return INF_ROOT_NUM;
        }
        else {
            return NO_ROOTS;
        }
    }
    else {
        if (c == 0) {
            *x1 = 0;
            return ONE_ROOT;
        }
        else {
            *x1 = -c/b;
            return ONE_ROOT;
        }
    }
    return ERROR;
}


enum Root_Count_Codes Quadratic_Equation_wo_Second_Coef(double a, double c, double* x1) {
    if (a == 0) {
        if (c == 0) {
            return INF_ROOT_NUM;
        }
        else {
            return NO_ROOTS;
        }
    }
    else {
        if (c == 0) {
            *x1 = 0;
            return ONE_ROOT;
        }
        if (a*c > 0) {
            *x1 = sqrt(c/a);
            return ONE_ROOT;
        }
        if (a*c < 0) {
            return NO_ROOTS;
        }
    }
    return ERROR;
}


enum Root_Count_Codes Quadratic_Equation_wo_Third_Coef(double a, double b, double* x1, double* x2) {
    if (a == 0) {
        if (b == 0) {
            return INF_ROOT_NUM;
        }
        else {
            return ONE_ROOT;
        }
    }
    else {
        if (b == 0) {
            *x1 = 0;
            return ONE_ROOT;
        }
        else {
            *x1 = 0;
            *x2 = -b/a;
            return TWO_ROOTS;
        }
    }
    return ERROR;
}


enum Root_Count_Codes True_Quadratic_Equation(double a, double b, double c, double* x1, double* x2) {
    double discriminant = b*b - 4*a*c;
    double sqrt_discr = sqrt(discriminant);

    if (discriminant < 0) {
        return NO_ROOTS;
    }
    if (discriminant == 0) {
        *x1 = -b/a/2;
        return ONE_ROOT;
    }
    if (discriminant > 0) {
        *x1 = (-b - sqrt_discr) /a /2;
        *x2 = (-b + sqrt_discr) /a /2;
        return TWO_ROOTS;
    }
    return ERROR;
}


void get_double(double* inp) {
    while (scanf("%lg", inp) != 1) {
        while (getchar() != '\n');
        printf("Недопустимый ввод. Введите число\n");
    }
}


void get_coefs(double* a, double* b, double* c) {
    printf("Введите первый коэффициент\n");
    get_double(a);
    printf("Введите второй коэффициент\n");
    get_double(b);
    printf("Введите третий коэффициент\n");
    get_double(c);
}
