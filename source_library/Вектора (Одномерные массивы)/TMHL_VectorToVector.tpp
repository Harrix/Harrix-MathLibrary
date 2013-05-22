template <class T> void TMHL_VectorToVector(T *VMHL_Vector, T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция копирует содержимое вектора (одномерного массива) VMHL_Vector в массив VMHL_ResultVector.
Входные параметры:
 VMHL_Vector - указатель на исходный массив;
 VMHL_ResultVector - указатель на массив в который производится запись;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
    VMHL_ResultVector[i]=VMHL_Vector[i];
}