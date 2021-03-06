double HML_LeftDerivative(double x, double h, double (*Function)(double))
{
/*
Численное значение производной в точке (разностная производная влево).
Входные параметры:
 x - точка, в которой считается производная;
 h - малое приращение x;
 Function - функция, производная которой ищется.
Возвращаемое значение:
 Значение производной в точке.
Примечание:
 При h<=0 возвращается 0.
*/
if (h<=0) return 0;

return ((Function(x)-Function(x-h))/h);
}