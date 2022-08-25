const int INF_ROOT_NUM =  3;
const int UNKNOWN_ERROR = 4;


void Get_Double (double* inp);
void Get_Coefs  (double* a, double* b, double* c);

int Quadratic_Equation               (double a, double b, double c, double* x1, double* x2);
int Linear_Equation                  (double b, double c, double* x1);
int Quadratic_Equation_wo_Second_Coef(double a, double c, double* x1, double* x2);
int Quadratic_Equation_wo_Third_Coef (double a, double b, double* x1, double* x2);
int True_Quadratic_Equation          (double a, double b, double c, double* x1, double* x2);
bool Eq_Doubles (double x, double y, double MIN_DIFF = 1e-10);
bool Diff_Signs (double x, double y);

void Print_Ans  (int root_count, double x1, double x2);
