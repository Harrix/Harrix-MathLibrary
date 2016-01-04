template <class T> void HML_MatrixToRow(T **a, T *VHML_ResultVector, int k, int VHML_M)
{
/*
Функция копирует из матрицы (двумерного массива) в вектор строку.
Входные параметры:
 a - указатель на матрицу;
 VHML_ResultVector - указатель на вектор;
 k - номер копируемой строки (начиная с 0);
 VHML_M - количество столбцов в матрице и одновременно размер массива VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_M;i++) VHML_ResultVector[i]=a[k][i];
}