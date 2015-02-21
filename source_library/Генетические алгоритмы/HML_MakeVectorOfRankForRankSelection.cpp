void HML_MakeVectorOfRankForRankSelection(double *Fitness, double *VHML_ResultVector, int VHML_N)
{
/*
Проставляет ранги для элементов не сортированного массива, то есть номера,
начиная с 1, в отсортированном массиве.  Если в массиве есть несколько одинаковых
элементов, то ранги им присуждаются как среднеарифметические.
Это служебная функция для функции HML_RankSelection.
Входные параметры:
 Fitness - массив пригодностей (можно подавать не массив пригодностей, а массив значений целевой функции, но только для задач безусловной оптимизации);
 VHML_ResultVector - массив рангов, который мы и формируем;
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Отсутствует.
*/
int j,i,k;
double Sn;
double *F;
int *N;
F=new double[VHML_N];
N=new int[VHML_N];

HML_VectorToVector(Fitness,F,VHML_N);

//Заполним номерами
HML_OrdinalVectorZero(N,VHML_N);

//сортируем массив пригодностей со сопряженным массивом номеров индивидов
HML_BubbleSortWithConjugateVector (F,N,VHML_N);

//расставляем ранги
for (i=0;i<VHML_N;i++)
 VHML_ResultVector[N[i]]=i+1;

//для одинаковых элементов ранги делаем одинаковыми как среднее арифметическое
for (i=0;i<VHML_N-1;i++)
 {
 if (F[i]==F[i+1])
  {
  j=i+1;
  while ((F[i]==F[j])&&(j<VHML_N)) j++;
  Sn=HML_SumOfArithmeticalProgression(i+1,1,j-i);
  Sn/=double(j-i);
  for (k=0;k<VHML_N;k++)
   if (Fitness[k]==F[i]) VHML_ResultVector[k]=Sn;
  i=j-1;
  }
 }
delete[] N;
delete[] F;
}
//---------------------------------------------------------------------------