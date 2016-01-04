double HML_NewtonSecondLawForce(double a, double m)
{
/*
Функция вычисляет силу по второму закону Ньютона.
Входные параметры:
 a - ускорение тела;
 m - масса тела.
Возвращаемое значение:
 Сила, приложенная к телу.
*/
    double VHML_Result;

    if (m<0) m*=-1;
    if (m==0) return 0;

    VHML_Result = a*m;

    return VHML_Result;
}
