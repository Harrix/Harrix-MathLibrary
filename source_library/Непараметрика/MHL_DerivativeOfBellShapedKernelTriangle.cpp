double MHL_DerivativeOfBellShapedKernelTriangle(double z)
{
/*
Производная колоколообразного треугольного ядра.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
if ((z<=1)&&(z>=0)) f=-1.;
if ((z<0)&&(z>=-1)) f=1.;
return f;
}