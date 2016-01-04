template <class T> void HML_MatrixToCol(T **a, T *VHML_ResultVector, int VHML_N, int k)
{
/*
Функция копирует из матрицы (двумерного массива) в вектор столбец.
Входные параметры:
 a - указатель на матрицу;
 VHML_ResultVector - указатель на вектор;
 VHML_N - количество строк в матрице и одновременно размер массива b;
 k - номер копируемого столбца (начиная с 0).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=a[i][k];
}