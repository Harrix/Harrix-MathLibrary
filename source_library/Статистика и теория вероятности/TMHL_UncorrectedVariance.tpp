template <class T> T TMHL_UncorrectedVariance(T *x, int VMHL_N)
{
/*
Функция вычисляет неисправленная выборочную дисперсию выборки.
Входные параметры:
 x - указатель на исходную выборку;
 VMHL_N - размер массива.
Возвращаемое значение:
 Выборочная неисправленная дисперсия выборки.
*/
T xn;
T VMHL_Result=0;

//Найдем среднее арифметические выборки
xn=TMHL_Mean(x,VMHL_N);

for(int i=0;i<VMHL_N;i++)
 VMHL_Result+=(x[i]-xn)*(x[i]-xn);

VMHL_Result/=VMHL_N;
return VMHL_Result;
}