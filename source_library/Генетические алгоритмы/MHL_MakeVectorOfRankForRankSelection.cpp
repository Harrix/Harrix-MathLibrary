void MHL_MakeVectorOfRankForRankSelection(double *Fitness, double *VMHL_ResultVector, int VMHL_N)
{
/*
Проставляет ранги для элементов не сортированного массива, то есть номера,
начиная с 1, в отсортированном массиве.  Если в массиве есть несколько одинаковых
элементов, то ранги им присуждаются как среднеарифметические.
Это служебная функция для функции MHL_RankSelection.
Входные параметры:
 Fitness - массив пригодностей (можно подавать не массив пригодностей, а массив значений целевой функции, но только для задач безусловной оптимизации);
 VMHL_ResultVector - массив рангов, который мы и формируем;
 VMHL_N - размер массива пригодностей.
Возвращаемое значение:
 Отсутствует.
*/
int j,i,k;
double Sn;
double *F;
int *N;
F=new double[VMHL_N];
N=new int[VMHL_N];

TMHL_VectorToVector(Fitness,F,VMHL_N);

//Заполним номерами
TMHL_OrdinalVectorZero(N,VMHL_N);

//сортируем массив пригодностей со сопряженным массивом номеров индивидов
TMHL_BubbleSortWithConjugateVector (F,N,VMHL_N);

//расставляем ранги
for (i=0;i<VMHL_N;i++)
 VMHL_ResultVector[N[i]]=i+1;

//для одинаковых элементов ранги делаем одинаковыми как среднее арифметическое
for (i=0;i<VMHL_N-1;i++)
 {
 if (F[i]==F[i+1])
  {
  j=i+1;
  while ((F[i]==F[j])&&(j<VMHL_N)) j++;
  Sn=MHL_SumOfArithmeticalProgression(i+1,1,j-i);
  Sn/=double(j-i);
  for (k=0;k<VMHL_N;k++)
   if (Fitness[k]==F[i]) VMHL_ResultVector[k]=Sn;
  i=j-1;
  }
 }
delete[] N;
delete[] F;
}
//---------------------------------------------------------------------------