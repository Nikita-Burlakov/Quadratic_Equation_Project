#include <stdio.h>
#include <math.h>
#include <TXLib.h>

#include "get_nums.h"
#include "processing.h"
#include "print_ans.h"


int main() {

    double a  = 0;
    double b  = 0;
    double c  = 0;
    double x1 = 1111;
    double x2 = 1111;
    int root_count = 0;

    Get_Coefs(&a, &b, &c);

    root_count = Quadratic_Equation(a, b, c, &x1, &x2);

    Print_Ans(root_count, x1, x2);

    return 0;
}
