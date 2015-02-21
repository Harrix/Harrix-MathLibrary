template <class T> void HML_RowInterchange(T **VHML_ResultMatrix, int VHML_M, int k, int l)
{
/*
Функция переставляет строки матрицы.
Входные параметры:
 VHML_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VHML_M - размер массива (число столбцов);
 k,l - номера переставляемых строк (нумерация с нуля).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_M;i++)
 HML_NumberInterchange (&(VHML_ResultMatrix[k][i]),&(VHML_ResultMatrix[l][i]));
}