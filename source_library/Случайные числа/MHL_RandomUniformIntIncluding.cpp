int MHL_RandomUniformIntIncluding(int n, int m)
{
/*
Случайное целое число в интервале [n,m] по равномерному закону распределения.
Входные параметры:
 n - левая граница;
 m - правая граница.
Возвращаемое значение:
 Случайное целое число от n до m включительно.
Примечание:
 В отличии от функции MHL_RandomUniformInt правая граница тоже включается, то есть может сгенерироваться m, а не m-1.
*/
int VMHL_Result;
VMHL_Result=n+int(MHL_RandomNumber()*(m+1-n));
if (VMHL_Result==m+1) VMHL_Result=m+1-1;
return VMHL_Result;
}