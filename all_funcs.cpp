#include <math.h>
#include <stdio.h>

#include "all_funcs.h"


//-------------------------------------------------------------------------


void Get_Double(double* inp) {
    while (scanf("%lg", inp) != 1) {
        while (getchar() != '\n')
            ;
        printf("Недопустимый ввод. Введите число\n");
    }
}


void Get_Coefs(double* a, double* b, double* c) {
    printf("РЕШАТЕЛЬ КВАДРАТНЫХ УРАВНЕНИЙ\n");
    printf("Введите первый коэффициент\n");
    Get_Double(a);
    printf("Введите второй коэффициент\n");
    Get_Double(b);
    printf("Введите третий коэффициент\n");
    Get_Double(c);
}


//-------------------------------------------------------------------------


int Quadratic_Equation(double a, double b, double c, double* x1, double* x2) {
    if (Eq_Doubles(a, 0)) {
        return Linear_Equation(b, c, x1);
    }
    else if (Eq_Doubles(b, 0)) {
        return Quadratic_Equation_wo_Second_Coef(a, c, x1, x2);
    }
    else if (Eq_Doubles(c, 0)) {
        return Quadratic_Equation_wo_Third_Coef(a, b, x1, x2);
    }
    else {
        return True_Quadratic_Equation(a, b, c, x1, x2);
    }

    return UNKNOWN_ERROR;
}


int Linear_Equation(double b, double c, double* x1) {
    bool b_is_null = Eq_Doubles(b, 0);
    bool c_is_null = Eq_Doubles(c, 0);

    if (b_is_null && c_is_null) {
        return INF_ROOT_NUM;
    }
    else if (b_is_null) {
        return 0;
    }
    else if (c_is_null) {
        *x1 = 0;
        return 1;
    }
    else {
        *x1 = -c/b;
        return 1;
    }

    return UNKNOWN_ERROR;
}


int Quadratic_Equation_wo_Second_Coef(double a, double c, double* x1, double* x2) {
    bool a_is_null = Eq_Doubles(a, 0);
    bool c_is_null = Eq_Doubles(c, 0);

    if (a_is_null && c_is_null) {
        return INF_ROOT_NUM;
    }
    else if (a_is_null) {
        return 0;
    }
    else if (c_is_null) {
        *x1 = 0;
        return 1;
    }
    else if (Diff_Signs (a,c)) {
        *x1 = sqrt(-c/a);
        *x2 = -*x1;
        return 2;
    }
    else {
        return 0;
    }

    return UNKNOWN_ERROR;
}


int Quadratic_Equation_wo_Third_Coef(double a, double b, double* x1, double* x2) {
    bool a_is_null = Eq_Doubles(a, 0);
    bool b_is_null = Eq_Doubles(b, 0);

    if (a_is_null && b_is_null) {
        return INF_ROOT_NUM;
    }
    else if (a_is_null) {
        *x1 = 0;
        return 1;
    }
    else if (b_is_null) {
        *x1 = 0;
        return 1;
    }
    else {
        *x1 = 0;
        *x2 = -b/a;
        return 2;
    }

    return UNKNOWN_ERROR;
}


int True_Quadratic_Equation(double a, double b, double c, double* x1, double* x2) {
    double discriminant = b*b - 4*a*c;
    double sqrt_discr = 0;

    if (discriminant < 0) {
        return 0;
    }
    else if (discriminant > 0) {
        sqrt_discr = sqrt(discriminant);
        *x1 = (-b - sqrt_discr) /a /2;
        *x2 = (-b + sqrt_discr) /a /2;
        return 2;
    }
    else {
        *x1 = -b/a/2;
        return 1;
    }

    return UNKNOWN_ERROR;
}


bool Eq_Doubles(double x, double y, double MIN_DIFF) {
    double diff;
    diff = (x > y) ? (x - y) : (y - x);
    if (diff < MIN_DIFF) {
        return true;
    }
    else {
        return false;
    }
}


bool Diff_Signs(double x, double y) {
    return ((x>0)&&(y<0)) || ((x<0)&&(y>0));
}


//-------------------------------------------------------------------------


void Print_Ans (int root_count, double x1, double x2) {
    switch(root_count)
    {
    case 0:
        printf("Нет корней\n");
        break;
    case 1:
        printf("x = %lg\n", x1);
        break;
    case 2:
        printf("x1 = %lg; x2 = %lg\n", x1, x2);
        break;
    case INF_ROOT_NUM:
        printf("Бесконечно много корней\n");
        break;
    default:
        printf("Неизвестная ошибка\n");
        break;
    }

    getchar();
}
