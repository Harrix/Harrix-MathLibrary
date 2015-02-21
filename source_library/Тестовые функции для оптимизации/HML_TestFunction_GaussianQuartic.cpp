double HML_TestFunction_GaussianQuartic(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Gaussian quartic.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;

for (int i=0;i<VHML_N;i++) VHML_Result+=(i+1)*x[i]*x[i]*x[i]*x[i];

VHML_Result+=HML_RandomNormal(0, 1);

return VHML_Result;
}