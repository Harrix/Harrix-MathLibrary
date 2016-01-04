template <class T> T HML_SampleCovariance(T *x, T *y, int VHML_N)
{
/*
Функция вычисляет выборочную ковариацию выборки (несмещенная, исправленная).
Входные параметры:
 x - указатель на первую сравниваемую выборки;
 y - указатель на вторую сравниваемую выборки;
 VHML_N - размер массивов.
Выходной параметр:
 Значение выборочной ковариации.
*/
T xn,yn;
T VHML_Result=0;

//Найдем среднее арифметические двух выборок
xn=HML_Mean(x,VHML_N);
yn=HML_Mean(x,VHML_N);

for(int i=0;i<VHML_N;i++)
 VHML_Result+=(x[i]-xn)*(y[i]-yn);

VHML_Result/=VHML_N-1;
return VHML_Result;
}