template <class T> void HML_ReverseVector(T *VHML_ResultVector, int VHML_N)
{
/*
Функция меняет порядок элементов в массиве на обратный. Преобразуется подаваемый массив.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N/2;i++)
 HML_NumberInterchange(&(VHML_ResultVector[i]),&(VHML_ResultVector[VHML_N-i-1]));
}