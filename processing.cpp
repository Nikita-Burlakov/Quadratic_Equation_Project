#include <math.h>

#include "processing.h"


enum Root_Count_Codes Quadratic_Equation(double a, double b, double c, double* x1, double* x2) {
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


enum Root_Count_Codes Linear_Equation(double b, double c, double* x1) {
    bool b_is_null = Eq_Doubles(b, 0);
    bool c_is_null = Eq_Doubles(c, 0);

    if (b_is_null && c_is_null) {
        return INF_ROOT_NUM;
    }
    else if (b_is_null) {
        return NO_ROOTS;
    }
    else if (c_is_null) {
        *x1 = 0;
        return ONE_ROOT;
    }
    else {
        *x1 = -c/b;
        return ONE_ROOT;
    }

    return UNKNOWN_ERROR;
}


enum Root_Count_Codes Quadratic_Equation_wo_Second_Coef(double a, double c, double* x1, double* x2) {
    bool a_is_null = Eq_Doubles(a, 0);
    bool c_is_null = Eq_Doubles(c, 0);

    if (a_is_null && c_is_null) {
        return INF_ROOT_NUM;
    }
    else if (a_is_null) {
        return NO_ROOTS;
    }
    else if (c_is_null) {
        *x1 = 0;
        return ONE_ROOT;
    }
    else if (Diff_Signs (a,c)) {
        *x1 = sqrt(-c/a);
        *x2 = -*x1;
        return TWO_ROOTS;
    }
    else {
        return NO_ROOTS;
    }

    return UNKNOWN_ERROR;
}


enum Root_Count_Codes Quadratic_Equation_wo_Third_Coef(double a, double b, double* x1, double* x2) {
    bool a_is_null = Eq_Doubles(a, 0);
    bool b_is_null = Eq_Doubles(b, 0);

    if (a_is_null && b_is_null) {
        return INF_ROOT_NUM;
    }
    else if (a_is_null) {
        *x1 = 0;
        return ONE_ROOT;
    }
    else if (b_is_null) {
        *x1 = 0;
        return ONE_ROOT;
    }
    else {
        *x1 = 0;
        *x2 = -b/a;
        return TWO_ROOTS;
    }

    return UNKNOWN_ERROR;
}


enum Root_Count_Codes True_Quadratic_Equation(double a, double b, double c, double* x1, double* x2) {
    double discriminant = b*b - 4*a*c;
    double sqrt_discr = 0;

    if (discriminant < 0) {
        return NO_ROOTS;
    }
    else if (discriminant > 0) {
        sqrt_discr = sqrt(discriminant);
        *x1 = (-b - sqrt_discr) /a /2;
        *x2 = (-b + sqrt_discr) /a /2;

        return TWO_ROOTS;
    }
    else {
        *x1 = -b/a/2;
        return ONE_ROOT;
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
