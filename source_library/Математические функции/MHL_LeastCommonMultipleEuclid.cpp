int MHL_LeastCommonMultipleEuclid(int A,int B)
{
/*
Функция находит наименьшее общее кратное двух чисел по алгоритму Евклида.
Входные параметры:
 A - первое число;
 B - второе число.
Возвращаемое значение:
 НОК(A,B)
*/
A=abs(A);
B=abs(B);
int gcd,VMHL_Result;
//НОК вычисляем на основе НОД
gcd=MHL_GreatestCommonDivisorEuclid(A,B);
VMHL_Result=(A*B)/gcd;
return VMHL_Result;
}