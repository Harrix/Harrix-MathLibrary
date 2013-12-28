int MHL_CountOfFitnessOfTestFunction_Real(int Dimension)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
	Для тестовых функций вещественного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 2; 3; 4; 5; 10; 20; 30.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Wave)
    {
        if (Dimension==1)  VMHL_Result = 64;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal)
    {
        if (Dimension==1)  VMHL_Result = 64;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)
    {
        if (Dimension==1)  VMHL_Result = 64;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Sombrero)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Katnikov)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)
    {
        if (Dimension==2)  VMHL_Result = 324;
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_StepFunction)
    {
        if (Dimension==2)  VMHL_Result = 324;
        if (Dimension==3)  VMHL_Result = 729;
        if (Dimension==4)  VMHL_Result = 1225;
        if (Dimension==5)  VMHL_Result = 1849;
        if (Dimension==10) VMHL_Result = 5776;
        if (Dimension==20) VMHL_Result = 15876;
        if (Dimension==30) VMHL_Result = 28224;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_CountOfFitnessOfTestFunction_Real(int Dimension, TypeOfTestFunction Type)
{
    /*
    Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
	Для тестовых функций вещественного типа.
    Входные параметры:
     Dimension - размерность тестовой задачи. Может принимать значения: 2; 3; 4; 5; 10; 20; 30;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Количество вычислений целевой функции для тестовых задач.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_CountOfFitnessOfTestFunction_Real(Dimension);

    return VMHL_Result;
}