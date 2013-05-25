template <class T> void TMHL_MatrixToCol(T **a, T *VMHL_ResultVector, int VMHL_N, int k)
{
/*
Функция копирует из матрицы (двумерного массива) в вектор столбец.
Входные параметры:
 a - указатель на матрицу;
 VMHL_ResultVector - указатель на вектор;
 VMHL_N - количество строк в матрице и одновременно размер массива b;
 k - номер копируемого столбца (начиная с 0).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=a[i][k];
}