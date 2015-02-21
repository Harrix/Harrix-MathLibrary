template <class T> T HML_PowerOf(T x, int n)
{
/*
Функция возводит произвольное число в целую степень.
Входные параметры:
 x - основание степени;
 n - показатель степени.
Возвращаемое значение:
 Cтепень числа.
*/
T VHML_Result=1;
if (n>0)
 for (int i=0;i<n;i++) VHML_Result*=x;
if (n<0)
 for (int i=0;i<n;i++) VHML_Result/=x;
return VHML_Result;
}