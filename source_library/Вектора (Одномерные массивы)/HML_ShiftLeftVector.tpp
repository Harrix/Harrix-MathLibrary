template <class T> void HML_ShiftLeftVector(T *VHML_Vector, int VHML_N)
{
/*
Функция сдвигает циклически в векторе (одномерном массиве) все элементы влево на один элемент.
Входные параметры:
 VHML_Vector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T Temp;
Temp=VHML_Vector[0];

for (int i=0;i<VHML_N-1;i++)
    VHML_Vector[i] = VHML_Vector[i+1];

VHML_Vector[VHML_N-1] = Temp;
}