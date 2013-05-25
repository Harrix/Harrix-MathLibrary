template <class T> T TMHL_Chebychev(T *x, T *y, int VMHL_N)
{
/*
Функция вычисляет расстояние Чебышева.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Значение метрики расстояние Чебышева.
*/
T VMHL_Result=0;
T Temp;
for (int i=0;i<VMHL_N;i++)
 {
 Temp=TMHL_Abs(x[i]-y[i]);
 if (Temp>VMHL_Result) VMHL_Result=Temp;
}
return VMHL_Result;
}