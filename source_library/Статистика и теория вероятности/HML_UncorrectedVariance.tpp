template <class T> T HML_UncorrectedVariance(T *x, int VHML_N)
{
/*
Функция вычисляет неисправленная выборочную дисперсию выборки.
Входные параметры:
 x - указатель на исходную выборку;
 VHML_N - размер массива.
Возвращаемое значение:
 Выборочная неисправленная дисперсия выборки.
*/
T xn;
T VHML_Result=0;

//Найдем среднее арифметические выборки
xn=HML_Mean(x,VHML_N);

for(int i=0;i<VHML_N;i++)
 VHML_Result+=(x[i]-xn)*(x[i]-xn);

VHML_Result/=VHML_N;
return VHML_Result;
}