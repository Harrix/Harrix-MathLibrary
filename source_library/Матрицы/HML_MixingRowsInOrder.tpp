template <class T> void HML_MixingRowsInOrder(T **VHML_ResultMatrix, int *b, int VHML_N, int VHML_M)
{
/*
Функция меняет строки матрицы в порядке, указанным в массиве b.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, в которой меняем порядок строк;
 b - вектор, в котором записаны номера, под которыми должны стать строки в матрице (от 0 до VHML_N-1);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
T **c;//Временный массив
c=new T*[VHML_N];
for (i=0;i<VHML_N;i++) c[i]=new T[VHML_M];

//Записываем в массив c в новом порядке
for (i=0;i<VHML_N;i++)
 for (j=0;j<VHML_M;j++)
  c[b[i]][j]=VHML_ResultMatrix[i][j];

//Заменяем основной массив промежуточным
HML_MatrixToMatrix(c,VHML_ResultMatrix,VHML_N,VHML_M);

for (i=0;i<VHML_N;i++) delete[] c[i];
delete[] c;
}