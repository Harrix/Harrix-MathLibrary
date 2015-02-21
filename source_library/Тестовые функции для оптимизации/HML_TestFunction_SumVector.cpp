double HML_TestFunction_SumVector(int *x, int VHML_N)
{
/*
Сумма всех элементов бинарного вектора.
Тестовая функция бинарной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
for (int i=0;i<VHML_N;i++) VHML_Result+=x[i];
return VHML_Result;
}
