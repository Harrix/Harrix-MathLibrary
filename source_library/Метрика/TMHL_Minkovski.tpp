template <class T> T TMHL_Minkovski(T *x, T *y, int r, int VMHL_N)
{
/*
Функция вычисляет метрику Минковского.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 r - порядок метрики;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Значение метрики Минковского.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 {
 VMHL_Result+=pow(fabs(x[i]-y[i]),r);
}
VMHL_Result=pow(VMHL_Result,1./double(r));

return VMHL_Result;
}