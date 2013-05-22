template <class T> T TMHL_SumVector(T *VMHL_Vector,int VMHL_N)
{
/*
Функция вычисляет сумму элементов вектора.
Входные параметры:
 VMHL_Vector - указатель на исходный массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Сумма элементов массива.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
    VMHL_Result+=VMHL_Vector[i];

return VMHL_Result;
}