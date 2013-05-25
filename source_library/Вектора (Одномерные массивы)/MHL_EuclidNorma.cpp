double MHL_EuclidNorma(double *a,int VMHL_N)
{
/*
Функция вычисляет евклидовую норму вектора.
Входные параметры:
 a - указатель на вектор;
 VMHL_N -  размер массива.
Возвращаемое значение:
 Значение евклидовой нормы вектора.
*/
int i;
double VMHL_Result=0;

for (i=0;i<VMHL_N;i++)
 VMHL_Result+=a[i]*a[i];

VMHL_Result=sqrt(double(VMHL_Result));
return VMHL_Result;
}