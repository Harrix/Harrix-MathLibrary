double HML_DistributionFunctionOfNormalizedCenteredNormalDistribution(double x, double Epsilon)
{
/*
Функция распределения нормированного и центрированного нормального распределения.
Входные параметры:
 x - входная переменная (правая граница интегрирования);
 Epsilon - погрешность (например, Epsilon = 0.00001 - больше не берите, а то будет большая погрешность).
Возвращаемое значение:
 Значение функции в точке.
*/
    double VHML_Result=0;

    if (x<0)
    {
        VHML_Result = 1 - (((1./sqrt(2.*HML_PI))*HML_IntegralOfSimpson(0,-x,Epsilon,HML_ExpMSxD2))+0.5);
    }
    if (x>0)
    {
        VHML_Result = (((1./sqrt(2.*HML_PI))*HML_IntegralOfSimpson(0,x,Epsilon,HML_ExpMSxD2))+0.5);
    }

	return VHML_Result;
}