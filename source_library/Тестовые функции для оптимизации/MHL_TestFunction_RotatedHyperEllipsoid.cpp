double MHL_TestFunction_RotatedHyperEllipsoid(double *x, int VMHL_N)
{
/*
Функция многих переменных: Развернутый гипер-эллипсоид.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VMHL_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VMHL_Result=0;
double f;

for (int i=0;i<VMHL_N;i++)
 {
 f=0;
 for (int j=0;j<i+1;j++)
    f += x[j];
 VMHL_Result += f*f;
 }

return VMHL_Result;
}