double HML_DensityOfDistributionOfNormalizedCenteredNormalDistribution(double x)
{
/*
Плотность распределения вероятности нормированного и центрированного нормального распределения.
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
return ((1./sqrt(2.*HML_PI))*HML_ExpMSxD2(x));
}