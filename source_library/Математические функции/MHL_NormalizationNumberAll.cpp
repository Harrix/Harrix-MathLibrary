double MHL_NormalizationNumberAll(double x)
{
/*
Функция нормирует число из интервала [бесконечность;+бесконечность] в интервал [0;1].
При этом в нуле возвращает 0.5, в -бесконечность возвращает 0, в +бесконечность
возвращает 1. Если x<y, то MHL_NormalizationNumberAll(x)<MHL_NormalizationNumberAll(y).
Под бесконечностью принимается машинная бесконечность.
Входные параметры:
 x - число.
Возвращаемое значение:
 Нормированное число.
*/
if (x==0) return 0.5;
if (x>=MHL_INFINITY) return 1.;
if (x<=MHL_MINFINITY) return 0.;
return ((1./(1.+1./fabs(x))*TMHL_Sign(x)+1.)/2.);
}