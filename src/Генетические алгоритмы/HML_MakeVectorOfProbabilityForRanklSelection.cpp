void HML_MakeVectorOfProbabilityForRanklSelection(double *Rank, double *VHML_ResultVector, int VHML_N)
{
/*
Функция формирует вектор вероятностей выбора индивидов из вектора рангов для ранговой селекции.
Это служебная функция для использования функции ранговой селекции HML_RankSelection.
Входные параметры:
 Rank - массив рангов, которые были посчитаны функцией HML_MakeVectorOfRankForRankSelection;
 VHML_ResultVector - вектор вероятностей выбора индивидов из популяции, который мы и формируем;
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Отсутствует.
*/
//Вектор Fitness мы не меняем. Поэтому проводим копирование.
HML_VectorToVector(Rank,VHML_ResultVector,VHML_N);

//Проводим нормировку вектора, с целью получения вектора вероятностей.
double sum=HML_SumVector(VHML_ResultVector,VHML_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1./double(VHML_N);
 }
else
 {
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]/=sum;
 }
}