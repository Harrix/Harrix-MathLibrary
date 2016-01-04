double HML_TestFunction_RotatedHyperEllipsoid(double *x, int VHML_N)
{
/*
Функция многих переменных: Развернутый гипер-эллипсоид.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
double f;

for (int i=0;i<VHML_N;i++)
 {
 f=0;
 for (int j=0;j<i+1;j++)
    f += x[j];
 VHML_Result += f*f;
 }

return VHML_Result;
}