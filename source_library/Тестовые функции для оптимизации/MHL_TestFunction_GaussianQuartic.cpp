double MHL_TestFunction_GaussianQuartic(double *x, int VMHL_N)
{
/*
Функция многих переменных: функция Gaussian quartic.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VMHL_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VMHL_Result=0;

for (int i=0;i<VMHL_N;i++) VMHL_Result+=(i+1)*x[i]*x[i]*x[i]*x[i];

VMHL_Result+=MHL_RandomNormal(0, 1);

return VMHL_Result;
}