int HML_RankSelection(double *VectorOfProbability, int VHML_N)
{
/*
Ранговая селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов,
который можно получить из вектора пригодностей индивидов посредством функции HML_MakeVectorOfRankForRankSelection
(для получения массива рангов) и потом функции HML_MakeVectorOfProbabilityForProportionalSelectionV2
(для получения массива вероятностей выбора индивидов по рангам).
Входные параметры:
 VectorOfProbability - массив вероятностей выбора индивидов для ранговой селекции;
 VHML_N - размер массива VectorProbability.
Возвращаемое значение:
 Номер выбранного индивида популяции.
*/
int VHML_Result=HML_SelectItemOnProbability(VectorOfProbability,VHML_N);
return VHML_Result;
}