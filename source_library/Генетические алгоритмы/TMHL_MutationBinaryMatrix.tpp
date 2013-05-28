template <class T> void TMHL_MutationBinaryMatrix(T **VMHL_ResultMatrix, double ProbabilityOfMutation, int VMHL_N,int VMHL_M)
{
/*
Мутация для бинарной матрицы. Оператор генетического алгоритма.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 ProbabilityOfMutation - вероятность мутации;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
if (ProbabilityOfMutation>1) ProbabilityOfMutation=1;
if (ProbabilityOfMutation<0) ProbabilityOfMutation=0;

for(int i=0;i<VMHL_N;i++)
 for(int j=0;j<VMHL_M;j++)
 if (MHL_RandomNumber()<ProbabilityOfMutation)
  {
  //Инвертируем ген
  if (VMHL_ResultMatrix[i][j]==0) VMHL_ResultMatrix[i][j]=1; else VMHL_ResultMatrix[i][j]=0;
  }
}