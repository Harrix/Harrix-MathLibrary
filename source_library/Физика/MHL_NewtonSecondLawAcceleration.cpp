double MHL_NewtonSecondLawAcceleration(double F, double m)
{
/*
Функция вычисляет ускорение по второму закону Ньютона.
Входные параметры:
 F - сила, приложенная к телу;
 m - масса тела.
Возвращаемое значение:
 Ускорение тела.
*/
    double VMHL_Result;

    if (m<0) m*=-1;
    if (m==0) return 0;

    VMHL_Result = F/m;

    return VMHL_Result;
}