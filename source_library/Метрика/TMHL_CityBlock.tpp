template <class T> T TMHL_CityBlock(T *x, T *y, int VMHL_N)
{
/*
Функция вычисляет манхэттенское расстояние между двумя массивами.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Значение метрики манхэттенское расстояние.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 VMHL_Result+=TMHL_Abs(x[i]-y[i]);
return VMHL_Result;
}