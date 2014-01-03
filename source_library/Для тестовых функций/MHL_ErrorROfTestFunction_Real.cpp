double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации. 
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VMHL_Result_R = 1;
    int i;

    double *Optimum=new double[VMHL_N];

    MHL_OptimumOfTestFunction_Real(Optimum, VMHL_N);

    if ((VMHL_TypeOfTestFunction==TestFunction_Ackley)||(VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VMHL_TypeOfTestFunction==TestFunction_Rastrigin)||(VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)||(VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_Wave)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)||(VMHL_TypeOfTestFunction==TestFunction_Sombrero)||(VMHL_TypeOfTestFunction==TestFunction_Katnikov)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)||(VMHL_TypeOfTestFunction==TestFunction_StepFunction)||(VMHL_TypeOfTestFunction==TestFunction_Rana)||(VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VMHL_TypeOfTestFunction==TestFunction_EggHolder)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VMHL_TypeOfTestFunction==TestFunction_Schwefel)||(VMHL_TypeOfTestFunction==TestFunction_Griewangk)||(VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod))
    {
        for (i=0;i<VMHL_N;i++)
        {
            if (fabs(x[i]-Optimum[i])>=MHL_PrecisionOfCalculationsOfTestFunction_Real()) VMHL_Result_R=0;
        }
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
	VMHL_Result_R = 0;
	double p=MHL_PrecisionOfCalculationsOfTestFunction_Real();
	
	if ( (fabs(x[0]-( 3.0     ))<p) && (fabs(x[1]-( 2.0     ))<p)  ) VMHL_Result_R = 1;
	if ( (fabs(x[0]-(-2.805118))<p) && (fabs(x[1]-( 3.131312))<p)  ) VMHL_Result_R = 1;
	if ( (fabs(x[0]-(-3.779310))<p) && (fabs(x[1]-(-3.283186))<p)  ) VMHL_Result_R = 1;
	if ( (fabs(x[0]-( 3.584428))<p) && (fabs(x[1]-(-1.848126))<p)  ) VMHL_Result_R = 1;
    }

    delete [] Optimum;

    return VMHL_Result_R;
}
//---------------------------------------------------------------------------
double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации. 
	Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorROfTestFunction_Real(x, VMHL_N);

    return VMHL_Result;
}