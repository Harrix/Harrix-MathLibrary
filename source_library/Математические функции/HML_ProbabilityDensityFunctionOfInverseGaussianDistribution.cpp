double HML_ProbabilityDensityFunctionOfInverseGaussianDistribution (double x, double mu, double lambda)
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
    double VHML_Result=0;

    if ((mu>0)&&(x>0)&&(lambda>0))
    {
        VHML_Result = sqrt(lambda/(2.*HML_PI*x*x*x))*exp((-lambda*(x-mu)*(x-mu))/(2.*mu*mu*x));
    }

return VHML_Result;
}