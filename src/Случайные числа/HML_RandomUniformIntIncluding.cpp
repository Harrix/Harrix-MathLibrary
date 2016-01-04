int HML_RandomUniformIntIncluding(int n, int m)
{
/*
Случайное целое число в интервале [n,m] по равномерному закону распределения.
Входные параметры:
 n - левая граница;
 m - правая граница.
Возвращаемое значение:
 Случайное целое число от n до m включительно.
Примечание:
 В отличии от функции HML_RandomUniformInt правая граница тоже включается, то есть может сгенерироваться m, а не m-1.
*/
int VHML_Result;
VHML_Result=n+int(HML_RandomNumber()*(m+1-n));
if (VHML_Result==m+1) VHML_Result=m+1-1;
return VHML_Result;
}