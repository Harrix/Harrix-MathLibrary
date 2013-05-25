template <class T> void TMHL_MatrixToRow(T **a, T *VMHL_ResultVector, int k, int VMHL_M)
{
/*
Функция копирует из матрицы (двумерного массива) в вектор строку.
Входные параметры:
 a - указатель на матрицу;
 VMHL_ResultVector - указатель на вектор;
 k - номер копируемой строки (начиная с 0);
 VMHL_M - количество столбцов в матрице и одновременно размер массива VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_M;i++) VMHL_ResultVector[i]=a[k][i];
}