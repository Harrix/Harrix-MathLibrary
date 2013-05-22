int MHL_RandomUniformInt(int n, int m)
{
/*
Случайное целое число в интервале [n,m) по равномерному закону распределения.
Входные параметры:
 n - левая граница;
 m - правая граница.
Возвращаемое значение:
 Случайное целое число от n до m-1 включительно.
*/
int VMHL_Result;
VMHL_Result=n+int(MHL_RandomNumber()*(m-n));
if (VMHL_Result==m) VMHL_Result=m-1;
return VMHL_Result;
}