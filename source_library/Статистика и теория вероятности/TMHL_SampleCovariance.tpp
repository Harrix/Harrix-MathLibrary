template <class T> T TMHL_SampleCovariance(T *x, T *y, int VMHL_N)
{
/*
Функция вычисляет выборочную ковариацию выборки (несмещенная, исправленная).
Входные параметры:
 x - указатель на первую сравниваемую выборки;
 y - указатель на вторую сравниваемую выборки;
 VMHL_N - размер массивов.
Выходной параметр:
 Значение выборочной ковариации.
*/
T xn,yn;
T VMHL_Result=0;

//Найдем среднее арифметические двух выборок
xn=TMHL_Mean(x,VMHL_N);
yn=TMHL_Mean(x,VMHL_N);

for(int i=0;i<VMHL_N;i++)
 VMHL_Result+=(x[i]-xn)*(y[i]-yn);

VMHL_Result/=VMHL_N-1;
return VMHL_Result;
}