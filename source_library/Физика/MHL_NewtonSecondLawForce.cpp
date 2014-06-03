double MHL_NewtonSecondLawForce(double a, double m)
{
/*
Функция вычисляет силу по второму закону Ньютона.
Входные параметры:
 a - ускорение тела;
 m - масса тела.
Возвращаемое значение:
 Сила, приложенная к телу.
*/
    double VMHL_Result;

    if (m<0) m*=-1;
    if (m==0) return 0;

    VMHL_Result = a*m;

    return VMHL_Result;
}
