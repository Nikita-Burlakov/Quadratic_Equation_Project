void Print_Ans (char root_count, double x1, double x2) {
    switch(root_count)
    {
    case NO_ROOTS:
        printf("��� ������\n");
        break;
    case ONE_ROOT:
        printf("x = %lg\n", x1);
        break;
    case TWO_ROOTS:
        printf("x1 = %lg; x2 = %lg\n", x1, x2);
        break;
    case INF_ROOT_NUM:
        printf("���������� ����� ������\n");
        break;
    default:
        printf("����������� ������\n");
        break;
    }

    getchar();
}
