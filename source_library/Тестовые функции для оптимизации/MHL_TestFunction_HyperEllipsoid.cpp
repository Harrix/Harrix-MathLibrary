double MHL_TestFunction_HyperEllipsoid(double *x, int VMHL_N)
{
/*
Функция многих переменных: Гипер-эллипсоид.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VMHL_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VMHL_Result=0;

for (int i=0;i<VMHL_N;i++)
	VMHL_Result += (i+1)*(i+1)*x[i]*x[i];

return VMHL_Result;
}