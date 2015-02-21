template <class T> void HML_ColInterchange(T **VHML_ResultMatrix, int VHML_N, int k, int l)
{
/*
Функция переставляет столбцы матрицы.
Входные параметры:
 VHML_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VHML_N - размер массива (число строки);
 k,l - номера переставляемых столбцов (нумерация с нуля).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 HML_NumberInterchange (&(VHML_ResultMatrix[i][k]),&(VHML_ResultMatrix[i][l]));
}