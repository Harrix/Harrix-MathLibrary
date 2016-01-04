template <class T> int HML_NumberOfPositiveValues(T *a, int VHML_N)
{
/*
Функция подсчитывает число положительных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на исходный массив;
 VHML_N - количество элементов в массиве.
Выходной параметр:
 Число положительных значений в массиве.
*/
int VHML_Result=0;
for (int i=0;i<VHML_N;i++)
    if (a[i]>0)
        VHML_Result++;

return VHML_Result;
}