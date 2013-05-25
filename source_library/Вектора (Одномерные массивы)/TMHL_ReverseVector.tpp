template <class T> void TMHL_ReverseVector(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция меняет порядок элементов в массиве на обратный. Преобразуется подаваемый массив.
Входные параметры:
 VMHL_ResultVector - указатель на преобразуемый массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N/2;i++)
 TMHL_NumberInterchange(&(VMHL_ResultVector[i]),&(VMHL_ResultVector[VMHL_N-i-1]));
}