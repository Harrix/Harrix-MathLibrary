double MHL_TestFunction_RastriginNovgorod(double *x, int VMHL_N)
{
/*
Функция многих переменных: функция Растригина новгородская.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VMHL_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VMHL_Result=0;

for (int i=0;i<VMHL_N;i++) 
    VMHL_Result+=x[i]*x[i]-cos(18.*x[i]*x[i]);

VMHL_Result+=VMHL_N;

return VMHL_Result;
}