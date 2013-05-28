int MHL_RankSelection(double *VectorOfProbability, int VMHL_N)
{
/*
Ранговая селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов,
который можно получить из вектора пригодностей индивидов посредством функции MHL_MakeVectorOfRankForRankSelection
(для получения массива рангов) и потом функции MHL_MakeVectorOfProbabilityForProportionalSelectionV2
(для получения массива вероятностей выбора индивидов по рангам).
Входные параметры:
 VectorOfProbability - массив вероятностей выбора индивидов для ранговой селекции;
 VMHL_N - размер массива VectorProbability.
Возвращаемое значение:
 Номер выбранного индивида популяции.
*/
int VMHL_Result=MHL_SelectItemOnProbability(VectorOfProbability,VMHL_N);
return VMHL_Result;
}