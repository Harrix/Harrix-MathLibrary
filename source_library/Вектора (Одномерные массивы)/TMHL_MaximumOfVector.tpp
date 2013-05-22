template <class T> T TMHL_MaximumOfVector(T *VMHL_Vector, int VMHL_N)
{
/*
Функция ищет максимальный элемент в векторе (одномерном массиве).
Входные параметры:
 VMHL_Vector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Максимальный элемент.
*/
T VMHL_Result;
VMHL_Result=VMHL_Vector[0];
for (int i=1;i<VMHL_N;i++)
    if (VMHL_Vector[i]>VMHL_Result)
        VMHL_Result=VMHL_Vector[i];

return VMHL_Result;
}