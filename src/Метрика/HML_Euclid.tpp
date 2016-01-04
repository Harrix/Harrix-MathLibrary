template <class T> T HML_Euclid(T *x, T *y, int VHML_N)
{
/*
Функция вычисляет евклидово расстояние.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VHML_N - размер массивов.
Возвращаемое значение:
 Значение метрики евклидово расстояние.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 VHML_Result+=(x[i]-y[i])*(x[i]-y[i]);
VHML_Result=sqrt(VHML_Result);
return VHML_Result;
}