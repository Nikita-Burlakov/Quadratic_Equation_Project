#include <stdio.h>

#include "get_nums.h"


void Get_Double(double* inp) {
    while (scanf("%lg", inp) != 1) {
        while (getchar() != '\n')
            ;
        printf("������������ ����. ������� �����\n");
    }
}


void Get_Coefs(double* a, double* b, double* c) {
    printf("�������� ���������� ���������\n");
    printf("������� ������ �����������\n");
    Get_Double(a);
    printf("������� ������ �����������\n");
    Get_Double(b);
    printf("������� ������ �����������\n");
    Get_Double(c);
}
