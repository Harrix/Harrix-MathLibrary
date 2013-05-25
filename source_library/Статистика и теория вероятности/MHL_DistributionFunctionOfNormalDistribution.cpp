double MHL_DistributionFunctionOfNormalDistribution(double x, double Epsilon)
{
/*
Функция распределения нормированного и центрированного нормального распределения.
Входные параметры:
 x - входная переменная (правая граница интегрирования);
 Epsilon - погрешность (например, Epsilon=0.001).
Возвращаемое значение:
 Значение функции в точке.
*/
return ((1./sqrt(2.*MHL_PI))*MHL_IntegralOfSimpson(0,x,Epsilon,MHL_ExpMSxD2));
}