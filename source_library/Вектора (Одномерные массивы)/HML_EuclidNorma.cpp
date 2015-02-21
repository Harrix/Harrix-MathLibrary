double HML_EuclidNorma(double *a,int VHML_N)
{
/*
Функция вычисляет евклидовую норму вектора.
Входные параметры:
 a - указатель на вектор;
 VHML_N -  размер массива.
Возвращаемое значение:
 Значение евклидовой нормы вектора.
*/
int i;
double VHML_Result=0;

for (i=0;i<VHML_N;i++)
 VHML_Result+=a[i]*a[i];

VHML_Result=sqrt(double(VHML_Result));
return VHML_Result;
}