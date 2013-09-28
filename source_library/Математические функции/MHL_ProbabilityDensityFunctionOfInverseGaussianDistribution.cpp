double MHL_ProbabilityDensityFunctionOfInverseGaussianDistribution (double x, double mu, double lambda)
{
/*
Функция вычисляет плотность вероятности распределения обратного гауссовскому распределению.
Входные параметры:
 x - входная переменная (x>0);
 mu - первый параметр распределения;
 lambda - второй параметр распределения.
Возвращаемое значение:
 Значение функции в точке.
*/
    double VMHL_Result=0;

    if ((mu>0)&&(x>0)&&(lambda>0))
    {
        VMHL_Result = sqrt(lambda/(2.*MHL_PI*x*x*x))*exp((-lambda*(x-mu)*(x-mu))/(2.*mu*mu*x));
    }

return VMHL_Result;
}