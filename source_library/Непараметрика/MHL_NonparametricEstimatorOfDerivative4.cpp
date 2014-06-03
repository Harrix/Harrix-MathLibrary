double MHL_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VMHL_N, double C, int V, bool *b)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Авторская разработка. Немного модифицирована формула по сравнению с MHL_NonparametricEstimatorOfDerivative.
Хорошо работает на концах выборки.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VMHL_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное;
 b - сюда возвращается 1, если все прошло хорошо и 0, если C не захватывает никаких
 точек выборки (тогда функция возвращает 0).
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    if ((V!=0)&&(V!=1)&&(V!=2)&&(V!=3)) V=2;
    double (*F)(double);
    double (*dF)(double);
    //выбираем тип колоколообразного ядра
    if (V==0) F=MHL_BellShapedKernelRectangle;
    if (V==1) F=MHL_BellShapedKernelTriangle;
    if (V==2) F=MHL_BellShapedKernelParabola;
    if (V==3) F=MHL_BellShapedKernelExp;
    if (V==0) dF=MHL_DerivativeOfBellShapedKernelRectangle;
    if (V==1) dF=MHL_DerivativeOfBellShapedKernelTriangle;
    if (V==2) dF=MHL_DerivativeOfBellShapedKernelParabola;
    if (V==3) dF=MHL_DerivativeOfBellShapedKernelExp;

    double A=0,B=0,D=0;
    for (int i=0;i<VMHL_N;i++)
    {
        A+=Y[i]*dF((x-X[i])/C);
        B+=F((x-X[i])/C);
        D+=Y[i]*F((x-X[i])/C);
    }

    //так как по формуле происходит деление на коэффициент размытия, то он не должен равняться 0
    if ((C==0)||(B==0))
    {
        *b=false;
        return 0;
    }
    else
    {
        *b=true;
        return ((A*B-C*D)/(C*B*B));
    }
}
//---------------------------------------------------------------------------
double MHL_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VMHL_N, double C, int V)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Авторская разработка. Немного модифицированна формула по сравнению с MHL_NonparametricEstimatorOfDerivative.
Хорошо работает на концах выборки.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VMHL_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double Result=0;
    bool b;
    Result = MHL_NonparametricEstimatorOfDerivative4(x, X, Y, VMHL_N, C, V, &b);
    return Result;
}