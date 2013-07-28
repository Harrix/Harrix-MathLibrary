double MHL_BellShapedKernelTriangle(double z)
{
/*
Колоколообразное треугольное ядро.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
z=fabs(z);
if (z<=1)
    f=1.-z;
return f;
}