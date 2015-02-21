template <class T> void HML_MutationBinaryMatrix(T **VHML_ResultMatrix, double ProbabilityOfMutation, int VHML_N,int VHML_M)
{
/*
Мутация для бинарной матрицы. Оператор генетического алгоритма.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 ProbabilityOfMutation - вероятность мутации;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
if (ProbabilityOfMutation>1) ProbabilityOfMutation=1;
if (ProbabilityOfMutation<0) ProbabilityOfMutation=0;

for(int i=0;i<VHML_N;i++)
 for(int j=0;j<VHML_M;j++)
 if (HML_RandomNumber()<ProbabilityOfMutation)
  {
  //Инвертируем ген
  if (VHML_ResultMatrix[i][j]==0) VHML_ResultMatrix[i][j]=1; else VHML_ResultMatrix[i][j]=0;
  }
}