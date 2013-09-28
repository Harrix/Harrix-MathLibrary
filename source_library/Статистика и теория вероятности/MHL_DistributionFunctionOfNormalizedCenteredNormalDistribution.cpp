double MHL_DistributionFunctionOfNormalizedCenteredNormalDistribution(double x, double Epsilon)
{
/*
Функция распределения нормированного и центрированного нормального распределения.
Входные параметры:
 x - входная переменная (правая граница интегрирования);
 Epsilon - погрешность (например, Epsilon = 0.00001 - больше не берите, а то будет большая погрешность).
Возвращаемое значение:
 Значение функции в точке.
*/
    double VMHL_Result=0;

    if (x<0)
    {
        VMHL_Result = 1 - (((1./sqrt(2.*MHL_PI))*MHL_IntegralOfSimpson(0,-x,Epsilon,MHL_ExpMSxD2))+0.5);
    }
    if (x>0)
    {
        VMHL_Result = (((1./sqrt(2.*MHL_PI))*MHL_IntegralOfSimpson(0,x,Epsilon,MHL_ExpMSxD2))+0.5);
    }

	return VMHL_Result;
}