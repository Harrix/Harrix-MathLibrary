double HML_TestFunction_RastriginNovgorod(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Растригина новгородская.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;

for (int i=0;i<VHML_N;i++) 
    VHML_Result+=x[i]*x[i]-cos(18.*x[i]*x[i]);

VHML_Result+=VHML_N;

return VHML_Result;
}