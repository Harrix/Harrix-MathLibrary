template <class T> void TMHL_RowInterchange(T **VMHL_ResultMatrix, int VMHL_M, int k, int l)
{
/*
Функция переставляет строки матрицы.
Входные параметры:
 VMHL_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VMHL_M - размер массива (число столбцов);
 k,l - номера переставляемых строк (нумерация с нуля).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_M;i++)
 TMHL_NumberInterchange (&(VMHL_ResultMatrix[k][i]),&(VMHL_ResultMatrix[l][i]));
}