template <class T> T HML_CityBlock(T *x, T *y, int VHML_N)
{
/*
Функция вычисляет манхэттенское расстояние между двумя массивами.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VHML_N - размер массивов.
Возвращаемое значение:
 Значение метрики манхэттенское расстояние.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 VHML_Result+=HML_Abs(x[i]-y[i]);
return VHML_Result;
}