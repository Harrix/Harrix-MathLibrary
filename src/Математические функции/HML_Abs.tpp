template <class T> T HML_Abs(T x)
{
/*
Функция возвращает модуль числа.
Входные параметры:
 x - число.
Возвращаемое значение:
 Модуль числа.
*/
T VHML_Result;
T MinusOne=-1;

if (x>=0) 
	VHML_Result=x;
else 
	VHML_Result=x*MinusOne;
	
return VHML_Result;
}