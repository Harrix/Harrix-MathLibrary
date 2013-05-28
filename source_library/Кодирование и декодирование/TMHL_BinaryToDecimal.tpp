template <class T> T TMHL_BinaryToDecimal(T *a, int VMHL_N)
{
/*
Функция декодирует двоичное число в десятичное целое неотрицательное.
Входные параметры:
 a - двоичное число;
 VMHL_N - длина двоичного числа.
Возвращаемое значение:
 Число в десятичной системе исчисления.
*/
T VMHL_Result;
VMHL_Result=TMHL_BinaryToDecimalFromPart(a,0,VMHL_N);
return VMHL_Result;
}