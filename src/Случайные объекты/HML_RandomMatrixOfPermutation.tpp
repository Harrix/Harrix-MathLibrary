template <class T> void HML_RandomMatrixOfPermutation(T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция создает случайный массив строк-перестановок чисел от 1 до VHML_M.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
T MOne=-1;
int i, j, b1, b2, randomall;
HML_FillMatrix (VHML_ResultMatrix,VHML_N,VHML_M,MOne);
for (j=0;j<VHML_N;j++)
 {
 for (i=0;i<VHML_M;i++)
  {//начало заполнения цифрами
  randomall=HML_RandomUniformInt(0,VHML_M-i)+1;
  b1=0;
  b2=0;
  while (b1<randomall)
   {
   if (VHML_ResultMatrix[j][b2]==-1) b1=b1+1;
   b2=b2+1;
   }
  VHML_ResultMatrix[j][b2-1]=i+1;
  }//конец заполнения цифрами
 }
}