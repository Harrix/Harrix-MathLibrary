template <class T> void TMHL_GrayCodeToBinary(T *a,int *VMHL_ResultVector, int VMHL_N)
{
/*
Функция переводит бинарный код Грея в бинарный код.
Входные параметры:
 a - код Грея (массив заполнен 0 и 1);
 VMHL_N - длина массива a.
Возвращаемое значение:
 Отсутствует.
*/
TMHL_GrayCodeToBinaryFromPart(a,VMHL_ResultVector,0,VMHL_N);
}