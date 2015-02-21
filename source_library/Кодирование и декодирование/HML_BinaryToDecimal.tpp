template <class T> T HML_BinaryToDecimal(T *a, int VHML_N)
{
/*
Функция декодирует двоичное число в десятичное целое неотрицательное.
Входные параметры:
 a - двоичное число;
 VHML_N - длина двоичного числа.
Возвращаемое значение:
 Число в десятичной системе исчисления.
*/
T VHML_Result;
VHML_Result=HML_BinaryToDecimalFromPart(a,0,VHML_N);
return VHML_Result;
}