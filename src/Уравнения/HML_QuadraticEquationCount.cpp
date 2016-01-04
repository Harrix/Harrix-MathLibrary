int HML_QuadraticEquationCount(double a, double b, double c, double *x1, double *x2)
{
/*
Функция решает квадратное уравнение вида: a*x*x+b*x+c=0.
Ответ представляет собой два действительных числа.
Отличается от HML_QuadraticEquation только тем, что возвращается количество решений, а не его наличие.
Входные параметры:
 a - параметр уравнения;
 b - параметр уравнения;
 c - параметр уравнения;
 x1 - первый корень;
 x2 - второй корень.
Возвращаемое значение:
 Количество решений задачи: 0, 1 или  2.
*/
    int Result;

    int GoodOrNot=HML_QuadraticEquation(a,b,c,x1,x2);

    if (GoodOrNot==0)
        Result = 0;
    else
    {
        if (*x1==*x2)
            Result = 1;
        else
            Result = 2;
    }

    return Result;
}