template <class T> void TMHL_MixingRowsInOrder(T **VMHL_ResultMatrix, int *b, int VMHL_N, int VMHL_M)
{
/*
Функция меняет строки матрицы в порядке, указанным в массиве b.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, в которой меняем порядок строк;
 b - вектор, в котором записаны номера, под которыми должны стать строки в матрице (от 0 до VMHL_N-1);
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
T **c;//Временный массив
c=new T*[VMHL_N];
for (i=0;i<VMHL_N;i++) c[i]=new T[VMHL_M];

//Записываем в массив c в новом порядке
for (i=0;i<VMHL_N;i++)
 for (j=0;j<VMHL_M;j++)
  c[b[i]][j]=VMHL_ResultMatrix[i][j];

//Заменяем основной массив промежуточным
TMHL_MatrixToMatrix(c,VMHL_ResultMatrix,VMHL_N,VMHL_M);

for (i=0;i<VMHL_N;i++) delete[] c[i];
delete[] c;
}