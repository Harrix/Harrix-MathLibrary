template <class T> T HML_Minkovski(T *x, T *y, int r, int VHML_N)
{
/*
Функция вычисляет метрику Минковского.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 r - порядок метрики;
 VHML_N - размер массивов.
Возвращаемое значение:
 Значение метрики Минковского.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 {
 VHML_Result+=pow(fabs(x[i]-y[i]),r);
}
VHML_Result=pow(VHML_Result,1./double(r));

return VHML_Result;
}