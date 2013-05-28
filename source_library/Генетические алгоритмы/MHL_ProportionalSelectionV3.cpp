int MHL_ProportionalSelectionV3(double *Fitness, int VMHL_N)
{
/*
Пропорциональная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей (обязательно не отрицательными).
Входные параметры:
 Fitness - массив пригодностей (В отличии от MHL_ProportionalSelection вектор пригодностей должен быть именно вектором пригодностей, то есть все элементы Fitness должны быть больше нуля);
 VMHL_N - размер массива пригодностей.
Возвращаемое значение:
 Номер выбранной пригодности, а, соответственно, номер индивида популяции.
Примечание:
 Данная функция аналогична по действию (результат действия аналогичен):
 1. Связке функций MHL_MakeVectorOfProbabilityForProportionalSelectionV2 и MHL_ProportionalSelectionV2
 2. Функции MHL_ProportionalSelection
 Различия по временным затратам на выполнение. Эта реализация быстрее, чем MHL_SelectionProportional
 и почти равна связке функций MHL_MakeVectorOfProbabilityForProportionalSelectionV2 и MHL_ProportionalSelectionV2,
 но реализация отличается от формульной записи в угоду более простой записи в программировании, но ей тождественна.
*/
int VMHL_Result=-1;//номер выбранного родителя
double Sum,r,s=0;
int i;
//получим сумму всех значений пригодностей
Sum=TMHL_SumVector(Fitness,VMHL_N);
r=MHL_RandomUniform(0,Sum);//случайное число по сумме
i=0;
while ((VMHL_Result==-1)&&(i<VMHL_N))
 {
 //определяем выбранного индивида
 s+=Fitness[i];
 if (s>=r) VMHL_Result=i;
 i++;
 }
return VMHL_Result;
}