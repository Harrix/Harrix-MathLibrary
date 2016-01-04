template <class T> void HML_GrayCodeToBinary(T *a,int *VHML_ResultVector, int VHML_N)
{
/*
Функция переводит бинарный код Грея в бинарный код.
Входные параметры:
 a - код Грея (массив заполнен 0 и 1);
 VHML_N - длина массива a.
Возвращаемое значение:
 Отсутствует.
*/
HML_GrayCodeToBinaryFromPart(a,VHML_ResultVector,0,VHML_N);
}