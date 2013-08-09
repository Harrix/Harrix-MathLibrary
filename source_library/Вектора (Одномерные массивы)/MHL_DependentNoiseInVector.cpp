void MHL_DependentNoiseInVector(double *VMHL_ResultVector, double percent, int VMHL_N)
{
/*
Функция добавляет к элементам выборки помеху, зависящую от значения элемента выборки
(плюс-минус сколько-то процентов модуля разности минимального и максимального элемента выборки,
умноженного на значение элемента).
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 percent - процент шума;
 VMHL_N - количество элементов в массивах.
Возвращаемое значение:
 Отсутствует.
*/
if (percent<0) percent=0;
int i;
double max=TMHL_MaximumOfVector(VMHL_ResultVector,VMHL_N);//Максимальное значение
double min=TMHL_MinimumOfVector(VMHL_ResultVector,VMHL_N);//Минимальное значение
double b=percent*(max-min)/100.;//Амплитуда шума
for (i=0;i<VMHL_N;i++)
 VMHL_ResultVector[i]+=VMHL_ResultVector[i]*MHL_RandomUniform(-b/2.,b/2.);
}