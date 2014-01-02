double MHL_TestFunction_Schwefel(double *x, int VMHL_N)
{
/*
Функция многих переменных: функция Швефеля.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VMHL_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VMHL_Result=418.9829*VMHL_N;

for (int i=0;i<VMHL_N;i++)
    VMHL_Result -= x[i]*sin(sqrt(fabs(x[i])));

return VMHL_Result;
}