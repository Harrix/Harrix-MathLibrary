double HML_TestFunction_Schwefel(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Швефеля.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=418.9829*VHML_N;

for (int i=0;i<VHML_N;i++)
    VHML_Result -= x[i]*sin(sqrt(fabs(x[i])));

return VHML_Result;
}