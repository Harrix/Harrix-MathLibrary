double MHL_PrecisionOfCalculationsOfTestFunction_Real()
{
    /*
    Функция определяет точность для подсчета надежности в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VMHL_Result_E = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VMHL_Result_E=0.05;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result_E=0.01;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result_E=0.025;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result_E=0.01;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VMHL_Result_E=0.025;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VMHL_Result_E=0.025;
    }

    return VMHL_Result_E;
}
//---------------------------------------------------------------------------
double MHL_PrecisionOfCalculationsOfTestFunction_Real(TypeOfTestFunction Type)
{
    /*
    Функция определяет точность для подсчета надежности в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации.
    Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции бинарной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_PrecisionOfCalculationsOfTestFunction_Real();

    return VMHL_Result;
}