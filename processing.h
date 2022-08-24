enum Root_Count_Codes Quadratic_Equation               (double a, double b, double c, double* x1, double* x2);
enum Root_Count_Codes Linear_Equation                  (double b, double c, double* x1);
enum Root_Count_Codes Quadratic_Equation_wo_Second_Coef(double a, double c, double* x1, double* x2);
enum Root_Count_Codes Quadratic_Equation_wo_Third_Coef (double a, double b, double* x1, double* x2);
enum Root_Count_Codes True_Quadratic_Equation          (double a, double b, double c, double* x1, double* x2);
bool Eq_Doubles (double x, double y, double MIN_DIFF = 1e-10);
bool Diff_Signs (double x, double y);
