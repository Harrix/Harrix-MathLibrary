int HML_RandomUniformInt(int n, int m)
{
/*
Случайное целое число в интервале [n,m) по равномерному закону распределения.
Входные параметры:
 n - левая граница;
 m - правая граница.
Возвращаемое значение:
 Случайное целое число от n до m-1 включительно.
*/
int VHML_Result;
VHML_Result=n+int(HML_RandomNumber()*(m-n));
if (VHML_Result==m) VHML_Result=m-1;
return VHML_Result;
}