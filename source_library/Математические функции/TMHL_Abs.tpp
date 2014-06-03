template <class T> T TMHL_Abs(T x)
{
/*
Функция возвращает модуль числа.
Входные параметры:
 x - число.
Возвращаемое значение:
 Модуль числа.
*/
T VMHL_Result;
T MinusOne=-1;

if (x>=0) 
	VMHL_Result=x;
else 
	VMHL_Result=x*MinusOne;
	
return VMHL_Result;
}