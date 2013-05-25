int MHL_HowManyPowersOfTwo(int x)
{
/*
Функция вычисляет, какой минимальной степенью двойки можно покрыть целое положительное число.
Входные параметры:
 x - целое число.
Возвращаемое значение:
 Минимальная степень двойки можно покрыть целое положительное число: min(2^VMHL_Result)>x
*/
x=abs(x);
double m=1;
int VMHL_Result=0;
while (m<x)
 {
 m*=2;
 VMHL_Result++;
 }
return VMHL_Result;
}