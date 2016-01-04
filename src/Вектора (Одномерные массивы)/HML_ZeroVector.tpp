template <class T> void HML_ZeroVector(T *VHML_ResultVector,int VHML_N)
{
/*
Функция зануляет массив.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=0;
}