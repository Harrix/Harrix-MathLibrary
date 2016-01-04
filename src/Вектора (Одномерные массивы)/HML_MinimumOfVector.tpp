template <class T> T HML_MinimumOfVector(T *VHML_Vector, int VHML_N)
{
/*
Функция ищет минимальный элемент в векторе (одномерном массиве).
Входные параметры:
 VHML_Vector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Минимальный элемент.
*/
T VHML_Result;
VHML_Result=VHML_Vector[0];
for (int i=1;i<VHML_N;i++)
    if (VHML_Vector[i]<VHML_Result)
        VHML_Result=VHML_Vector[i];

return VHML_Result;
}