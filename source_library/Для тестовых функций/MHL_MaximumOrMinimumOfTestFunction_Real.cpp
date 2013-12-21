double MHL_MaximumOrMinimumOfTestFunction_Real()
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции вещественной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     1 - задача на нахождение максимума;
     -1 - задача на нахождение минимума.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        VMHL_Result=1;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result=-1;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result=-1;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        VMHL_Result=1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        VMHL_Result=-1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        VMHL_Result=1;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_MaximumOrMinimumOfTestFunction_Real(TypeOfTestFunction Type)
{
    /*
    Функция сообщает - ищется максимум или минимум в задаче оптимизации
    для тестовой функции вещественной оптимизации.
    Требуется для использования в других функций.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_MaximumOrMinimumOfTestFunction_Real();

    return VMHL_Result;
}