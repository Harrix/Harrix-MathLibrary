template <class T> void TMHL_RandomMatrixOfPermutation(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция создает случайный массив строк-перестановок чисел от 1 до VMHL_M.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
T MOne=-1;
int i, j, b1, b2, randomall;
TMHL_FillMatrix (VMHL_ResultMatrix,VMHL_N,VMHL_M,MOne);
for (j=0;j<VMHL_N;j++)
 {
 for (i=0;i<VMHL_M;i++)
  {//начало заполнения цифрами
  randomall=MHL_RandomUniformInt(0,VMHL_M-i)+1;
  b1=0;
  b2=0;
  while (b1<randomall)
   {
   if (VMHL_ResultMatrix[j][b2]==-1) b1=b1+1;
   b2=b2+1;
   }
  VMHL_ResultMatrix[j][b2-1]=i+1;
  }//конец заполнения цифрами
 }
}