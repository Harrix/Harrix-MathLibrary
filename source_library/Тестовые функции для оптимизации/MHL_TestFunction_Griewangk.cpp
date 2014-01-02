double MHL_TestFunction_Griewangk(double *x, int VMHL_N)
{
/*
Функция многих переменных: функция Гриванка.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VMHL_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VMHL_Result=0;
double f=1;
int i;

for (i=0;i<VMHL_N;i++) VMHL_Result+=x[i]*x[i];
VMHL_Result/=4000.;

for (i=0;i<VMHL_N;i++) f=f*cos(x[i]/sqrt(i+1));

VMHL_Result=VMHL_Result-f+1.;

return VMHL_Result;
}