void MHL_MakeVectorOfProbabilityForRanklSelection(double *Rank, double *VMHL_ResultVector, int VMHL_N)
{
/*
Функция формирует вектор вероятностей выбора индивидов из вектора рангов для ранговой селекции.
Это служебная функция для использования функции ранговой селекции MHL_RankSelection.
Входные параметры:
 Rank - массив рангов, которые были посчитаны функцией MHL_MakeVectorOfRankForRankSelection;
 VMHL_ResultVector - вектор вероятностей выбора индивидов из популяции, который мы и формируем;
 VMHL_N - размер массива пригодностей.
Возвращаемое значение:
 Отсутствует.
*/
//Вектор Fitness мы не меняем. Поэтому проводим копирование.
TMHL_VectorToVector(Rank,VMHL_ResultVector,VMHL_N);

//Проводим нормировку вектора, с целью получения вектора вероятностей.
double sum=TMHL_SumVector(VMHL_ResultVector,VMHL_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=1./double(VMHL_N);
 }
else
 {
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]/=sum;
 }
}