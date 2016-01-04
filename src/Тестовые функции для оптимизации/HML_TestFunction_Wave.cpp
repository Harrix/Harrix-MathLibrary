double HML_TestFunction_Wave(double x)
{
/*
Функция одной переменных: волна.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x).
*/
double VHML_Result;
VHML_Result = (exp(-x*x)+0.01*cos(200*x));
return VHML_Result;
}