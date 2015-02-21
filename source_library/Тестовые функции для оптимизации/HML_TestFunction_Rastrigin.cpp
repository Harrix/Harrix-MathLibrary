double HML_TestFunction_Rastrigin(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Растригина.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
for (int i=0;i<VHML_N;i++) VHML_Result+=x[i]*x[i]-10.*cos(2.*HML_PI*x[i]);
VHML_Result+=10*VHML_N;
return VHML_Result;
}