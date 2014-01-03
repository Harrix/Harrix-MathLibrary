int MHL_GetCountOfSubProblems_Real()
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VMHL_Result = 1;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result = 7;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result = 7;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        VMHL_Result = 7;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        VMHL_Result = 1;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_GetCountOfSubProblems_Real(TypeOfTestFunction Type)
{
    /*
    Функция определяет число подзадач (включая основную задачу) для тестовой функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Число подзадач (включая основную задачу) для тестовой функции.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_GetCountOfSubProblems_Real();

    return VMHL_Result;
}