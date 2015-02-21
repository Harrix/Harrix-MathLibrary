double HML_DistributionFunctionOfNormalDistribution(double x, double mu, double sigma, double Epsilon)
{
/*
Функция распределения нормального распределения.
Входные параметры:
 x - входная переменная (правая граница интегрирования);
 mu - математическое ожидание;
 sigma - стандартное отклонение (sigma>0);
 Epsilon - погрешность (например, Epsilon = 0.00001 - больше не берите, а то будет большая погрешность).
Возвращаемое значение:
 Значение функции в точке.
*/
    double VHML_Result=0;

    if (sigma>0)
        VHML_Result = HML_DistributionFunctionOfNormalizedCenteredNormalDistribution((x-mu)/sigma,Epsilon);

    return VHML_Result;
}