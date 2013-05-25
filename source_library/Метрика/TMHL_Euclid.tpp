template <class T> T TMHL_Euclid(T *x, T *y, int VMHL_N)
{
/*
Функция вычисляет евклидово расстояние.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Значение метрики евклидово расстояние.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 VMHL_Result+=(x[i]-y[i])*(x[i]-y[i]);
VMHL_Result=sqrt(VMHL_Result);
return VMHL_Result;
}