template <class T> void TMHL_ShiftLeftVector(T *VMHL_Vector, int VMHL_N)
{
/*
Функция сдвигает циклически в векторе (одномерном массиве) все элементы влево на один элемент.
Входные параметры:
 VMHL_Vector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T Temp;
Temp=VMHL_Vector[0];

for (int i=0;i<VMHL_N-1;i++)
    VMHL_Vector[i] = VMHL_Vector[i+1];

VMHL_Vector[VMHL_N-1] = Temp;
}