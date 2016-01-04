double HML_TestFunction_Ackley(double *x, int VHML_N)
{
/*
Функция многих переменных: Ackley.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result;
double f1,f2=0;
f1=exp(-0.2*sqrt(HML_SumSquareVector(x,VHML_N)/double(VHML_N)));
for (int i=0;i<VHML_N;i++) f2=f2+cos(2.*HML_PI*x[i]);
f2=exp(f2/double(VHML_N));
VHML_Result=20.+exp(1.)-20.*f1-f2;
return VHML_Result;
}