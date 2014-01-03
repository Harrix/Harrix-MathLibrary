double MHL_TestFunction_Real(double *x, int VMHL_N)
{
    /*
    Общая тестовая функция для задач вещественной оптимизации. Включает в себя все тестовые функции.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Ackley(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_AdditivePotential(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_MultiplicativePotential(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_ReverseGriewank(x[0], x[1]);

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_ParaboloidOfRevolution(x, VMHL_N);

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Rastrigin(x, VMHL_N);

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Rosenbrock(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_HyperEllipsoid(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_RotatedHyperEllipsoid(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Wave(x[0]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Multiextremal(x[0]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Multiextremal2(x[0]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Sombrero(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Himmelblau(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Katnikov(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Multiextremal3(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Multiextremal4(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_StepFunction(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Rana(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_ShekelsFoxholes(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_EggHolder(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_RastriginWithChange(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_RastriginWithTurning(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Schwefel(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_Griewangk(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_InvertedRosenbrock(x[0], x[1]);
		
	if (VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_GaussianQuartic(x, VMHL_N);
		
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod)
        VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real()*MHL_TestFunction_RastriginNovgorod(x, VMHL_N);

    CountOfFitness++;//увеличиваем число вызовов целевой функции
    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_TestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Общая тестовая функция для задач вещественной оптимизации. Включает в себя все тестовые функции.
    Входные параметры:
     x - указатель на исходный массив;
     VMHL_N - размер массива x,
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Значение тестовой функции в точке x.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_TestFunction_Real(x, VMHL_N);

    return VMHL_Result;
}