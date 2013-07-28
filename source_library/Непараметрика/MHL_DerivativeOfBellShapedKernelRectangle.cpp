double MHL_DerivativeOfBellShapedKernelRectangle(double z)
{
/*
Производная колоколообразного прямоугольного ядра.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
if (z==1) f=-1.7E308;
if (z==-1) f=1.7E308;
return f;
}