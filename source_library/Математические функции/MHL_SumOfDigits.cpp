int MHL_SumOfDigits(int a)
{
/*
Функция подсчитывает сумму цифр любого целого числа.
Входные параметры:
 a - целое число.
Возвращаемое значение:
 Cумма цифр.
*/
if (a<1) a=-a;
int VMHL_Result=0;
while (a>=1)
 {
 VMHL_Result+=a-int(int(a/10)*10.);
 a/=10;
 }
return VMHL_Result;
}