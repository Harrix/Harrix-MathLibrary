double MHL_FitnessOfOptimumOfTestFunction_Real(double VMHL_N)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     VMHL_N - размер массива x в решаемой задаче оптимизации.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VMHL_Result = -15.606060606060606;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VMHL_Result = -60.8872819100091;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VMHL_Result = 1.;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result = 0;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result = 0;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        VMHL_Result = 1.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VMHL_Result = 0.000103742;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VMHL_Result = 1.93374;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VMHL_Result = 1.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VMHL_Result = 0.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VMHL_Result = 0.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VMHL_Result = 0.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VMHL_Result = 0.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VMHL_Result = -1.;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        VMHL_Result = -511.7328819;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VMHL_Result = 0.99800384;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
		VMHL_Result = -959.64067;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
		VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
		VMHL_Result = 0;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
		VMHL_Result = 0;
        double *x;
        x=new double[int(VMHL_N)];
		for (int i=0;i<VMHL_N;i++) x[i]=420.968746;
		VMHL_Result=MHL_TestFunction_Schwefel(x,VMHL_N);
		delete [] x;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_FitnessOfOptimumOfTestFunction_Real(double VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     VMHL_N - размер массива x в решаемой задаче оптимизации;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_FitnessOfOptimumOfTestFunction_Real(VMHL_N);

    return VMHL_Result;
}