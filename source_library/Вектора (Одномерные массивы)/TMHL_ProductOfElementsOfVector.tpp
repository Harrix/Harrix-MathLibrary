template <class T> T TMHL_ProductOfElementsOfVector(T *VMHL_Vector,int VMHL_N)
{
/*
Функция вычисляет произведение элементов вектора.
Входные параметры:
 VMHL_Vector - указатель на исходный массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Произведение элементов массива.
*/
T VMHL_Result=1;
for (int i=0;i<VMHL_N;i++)
    VMHL_Result*=VMHL_Vector[i];

return VMHL_Result;
}