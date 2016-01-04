int HML_LeastCommonMultipleEuclid(int A,int B)
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
int gcd,VHML_Result;
//НОК вычисляем на основе НОД
gcd=HML_GreatestCommonDivisorEuclid(A,B);
VHML_Result=(A*B)/gcd;
return VHML_Result;
}