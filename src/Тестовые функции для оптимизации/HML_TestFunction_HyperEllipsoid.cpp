double HML_TestFunction_HyperEllipsoid(double *x, int VHML_N)
{
/*
Функция многих переменных: Гипер-эллипсоид.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;

for (int i=0;i<VHML_N;i++)
	VHML_Result += (i+1)*(i+1)*x[i]*x[i];

return VHML_Result;
}