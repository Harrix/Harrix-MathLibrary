template <class T> void TMHL_ZeroVector(T *VMHL_ResultVector,int VMHL_N)
{
/*
Функция зануляет массив.
Входные параметры:
 VMHL_ResultVector - указатель на преобразуемый массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
    VMHL_ResultVector[i]=0;
}