template <class T> void HML_ShiftRightVector(T *VHML_Vector, int VHML_N)
{
/*
Функция сдвигает циклически в векторе (одномерном массиве) все элементы вправо на один элемент.
Входные параметры:
 VHML_Vector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T Temp;
Temp=VHML_Vector[VHML_N-1];

for (int i=VHML_N-1;i>0;i--)
    VHML_Vector[i] = VHML_Vector[i-1];

VHML_Vector[0] = Temp;
}