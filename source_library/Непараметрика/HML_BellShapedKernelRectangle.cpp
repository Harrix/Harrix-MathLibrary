double HML_BellShapedKernelRectangle(double z)
{
/*
Колоколообразное прямоугольное ядро.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
z=fabs(z);
if (z<=1)
    f=0.5;
return f;
}