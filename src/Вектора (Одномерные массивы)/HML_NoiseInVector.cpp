void HML_NoiseInVector(double *VHML_ResultVector, double percent, int VHML_N)
{
/*
Функция добавляет к элементам выборки аддитивную помеху (плюс-минус сколько-то процентов
модуля разности минимального и максимального элемента выборки).
Входные параметры:
 VHML_ResultVector - указатель на массив;
 percent - процент шума;
 VHML_N - количество элементов в массивах.
Возвращаемое значение:
 Отсутствует.
*/
if (percent<0) percent=0;
int i;
double max=HML_MaximumOfVector(VHML_ResultVector,VHML_N);//Максимальное значение
double min=HML_MinimumOfVector(VHML_ResultVector,VHML_N);//Минимальное значение
double b=percent*(max-min)/100.;//Амплитуда шума
for (i=0;i<VHML_N;i++)
 VHML_ResultVector[i]+=HML_RandomUniform(-b/2.,b/2.);
}