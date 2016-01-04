template <class T> T HML_Chebychev(T *x, T *y, int VHML_N)
{
/*
Функция вычисляет расстояние Чебышева.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VHML_N - размер массивов.
Возвращаемое значение:
 Значение метрики расстояние Чебышева.
*/
T VHML_Result=0;
T Temp;
for (int i=0;i<VHML_N;i++)
 {
 Temp=HML_Abs(x[i]-y[i]);
 if (Temp>VHML_Result) VHML_Result=Temp;
}
return VHML_Result;
}