int HML_ProportionalSelectionV3(double *Fitness, int VHML_N)
{
/*
Пропорциональная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей (обязательно не отрицательными).
Входные параметры:
 Fitness - массив пригодностей (В отличии от HML_ProportionalSelection вектор пригодностей должен быть именно вектором пригодностей, то есть все элементы Fitness должны быть больше нуля);
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Номер выбранной пригодности, а, соответственно, номер индивида популяции.
Примечание:
 Данная функция аналогична по действию (результат действия аналогичен):
 1. Связке функций HML_MakeVectorOfProbabilityForProportionalSelectionV2 и HML_ProportionalSelectionV2
 2. Функции HML_ProportionalSelection
 Различия по временным затратам на выполнение. Эта реализация быстрее, чем HML_SelectionProportional
 и почти равна связке функций HML_MakeVectorOfProbabilityForProportionalSelectionV2 и HML_ProportionalSelectionV2,
 но реализация отличается от формульной записи в угоду более простой записи в программировании, но ей тождественна.
*/
int VHML_Result=-1;//номер выбранного родителя
double Sum,r,s=0;
int i;
//получим сумму всех значений пригодностей
Sum=HML_SumVector(Fitness,VHML_N);
r=HML_RandomUniform(0,Sum);//случайное число по сумме
i=0;
while ((VHML_Result==-1)&&(i<VHML_N))
 {
 //определяем выбранного индивида
 s+=Fitness[i];
 if (s>=r) VHML_Result=i;
 i++;
 }
return VHML_Result;
}