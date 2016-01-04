template <class T> void HML_VectorToVector(T *VHML_Vector, T *VHML_ResultVector, int VHML_N)
{
/*
Функция копирует содержимое вектора (одномерного массива) VHML_Vector в массив VHML_ResultVector.
Входные параметры:
 VHML_Vector - указатель на исходный массив;
 VHML_ResultVector - указатель на массив в который производится запись;
 VHML_N - размер массивов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=VHML_Vector[i];
}