double HML_GeometricSeries(double u1,double q,int n)
{
/*
Геометрическая прогрессия. n-ый член последовательности.
Входные параметры:
 u1 - начальный член прогрессии;
 q - шаг  прогрессии;
 n - номер последнего члена.
Возвращаемое значение:
 n-ый член последовательности.
*/
double qn1;
qn1=HML_PowerOf(q,n-1);
double VHML_Result=u1*qn1;
return VHML_Result;
}