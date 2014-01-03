int MHL_DimensionTestFunction_Real(int i)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции вещественной оптимизации
    по номеру подзадачи (число подзадач по функции MHL_GetCountOfSubProblems_Binary).
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     i - номер подзадачи (начиная с нуля).
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции вещественной оптимизации.
    */
    int VMHL_Result = 0;

    //проверка
    if (i<0) i=0;
    //if (i>=MHL_GetCountOfSubProblems_Real()) i=MHL_GetCountOfSubProblems_Real()-1;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        if (i==0) VMHL_Result = 2;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        if (i==0) VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        if (i==0) VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        if (i==0) VMHL_Result = 1;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Rana)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_EggHolder)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)
    {
        if (i==0) VMHL_Result = 2;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Schwefel)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Griewangk)
    {
        if (i==0) VMHL_Result = 2;
        if (i==1) VMHL_Result = 3;
        if (i==2) VMHL_Result = 4;
        if (i==3) VMHL_Result = 5;
        if (i==4) VMHL_Result = 10;
        if (i==5) VMHL_Result = 20;
        if (i==6) VMHL_Result = 30;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)
    {
        if (i==0) VMHL_Result = 2;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_DimensionTestFunction_Real(int i, TypeOfTestFunction Type)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции вещественной оптимизации
    по номеру подзадачи (число подзадач по функции MHL_GetCountOfSubProblems_Binary).
    Входные параметры:
     i - номер подзадачи (начиная с нуля);
     Type - тип тестовой функции.
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции вещественной оптимизации.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_DimensionTestFunction_Real(i);

    return VMHL_Result;
}