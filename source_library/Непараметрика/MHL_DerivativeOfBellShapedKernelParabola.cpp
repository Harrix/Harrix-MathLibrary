double MHL_DerivativeOfBellShapedKernelParabola(double z)
{
/*
Производная колоколообразного параболического ядра.
Входные параметры:
 z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
if (z*z<=5) f=-0.134*z;
return f;
}