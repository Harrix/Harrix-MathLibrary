template <class T> void TMHL_ShiftRightVector(T *VMHL_Vector, int VMHL_N)
{
/*
Функция сдвигает циклически в векторе (одномерном массиве) все элементы вправо на один элемент.
Входные параметры:
 VMHL_Vector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T Temp;
Temp=VMHL_Vector[VMHL_N-1];

for (int i=VMHL_N-1;i>0;i--)
    VMHL_Vector[i] = VMHL_Vector[i-1];

VMHL_Vector[0] = Temp;
}