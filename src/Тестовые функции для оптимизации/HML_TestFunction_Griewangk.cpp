double HML_TestFunction_Griewangk(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Гриванка.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
double f=1;
int i;

for (i=0;i<VHML_N;i++) VHML_Result+=x[i]*x[i];
VHML_Result/=4000.;

for (i=0;i<VHML_N;i++) f=f*cos(x[i]/sqrt(i+1));

VHML_Result=VHML_Result-f+1.;

return VHML_Result;
}