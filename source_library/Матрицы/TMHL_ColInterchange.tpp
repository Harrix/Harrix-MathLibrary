template <class T> void TMHL_ColInterchange(T **VMHL_ResultMatrix, int VMHL_N, int k, int l)
{
/*
Функция переставляет столбцы матрицы.
Входные параметры:
 VMHL_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VMHL_N - размер массива (число строки);
 k,l - номера переставляемых столбцов (нумерация с нуля).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 TMHL_NumberInterchange (&(VMHL_ResultMatrix[i][k]),&(VMHL_ResultMatrix[i][l]));
}