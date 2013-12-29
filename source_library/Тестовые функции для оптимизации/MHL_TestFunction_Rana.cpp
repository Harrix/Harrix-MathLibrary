double MHL_TestFunction_Rana(double x, double y)
{
/*
Функция двух переменных: функция Rana.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VMHL_Result;
VMHL_Result=x*sin(sqrt(fabs(y+1.-x)))*cos(sqrt(fabs(y+1.+x))) + (y+1.)*cos(sqrt(fabs(y+1.-x)))*sin(sqrt(fabs(y+1.+x)));
return VMHL_Result;
}