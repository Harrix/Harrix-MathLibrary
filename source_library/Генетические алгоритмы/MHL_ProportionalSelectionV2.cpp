int MHL_ProportionalSelectionV2(double *VectorOfProbability, int VMHL_N)
{
/*
Пропорциональная селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов,
который можно получить из вектора пригодностей индивидов посредством функции MHL_MakeVectorOfProbabilityForProportionalSelectionV2.
Входные параметры:
 VectorOfProbability - массив вероятностей выбора индивидов для порпоциональной селекции;
 VMHL_N - размер массива пригодностей.
Возвращаемое значение:
 Номер выбранной пригодности, а, соответственно, номер индивида популяции.
Примечание:
 Связка данной функции и MHL_MakeVectorOfProbabilityForProportionalSelectionV2 аналогична по действию (результат действия аналогичен):
 1. Функции MHL_ProportionalSelection
 2. Функции MHL_ProportionalSelectionV3
 Различия по временным затратам на выполнение. У этой связки выполнение быстрее, чем у MHL_ProportionalSelection.
*/
int VMHL_Result=MHL_SelectItemOnProbability(VectorOfProbability,VMHL_N);
return VMHL_Result;
}