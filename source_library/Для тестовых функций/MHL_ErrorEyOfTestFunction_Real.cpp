double MHL_ErrorEyOfTestFunction_Real(double FitnessOfx, int VMHL_N)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VMHL_Result_Ey = 0;

    double FitnessOfOptimum=MHL_FitnessOfOptimumOfTestFunction_Real(VMHL_N);

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        VMHL_Result_Ey=fabs(MHL_MaximumOrMinimumOfTestFunction_Real()*FitnessOfx-FitnessOfOptimum);
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        VMHL_Result_Ey=fabs(MHL_MaximumOrMinimumOfTestFunction_Real()*FitnessOfx-FitnessOfOptimum);
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        VMHL_Result_Ey=fabs(MHL_MaximumOrMinimumOfTestFunction_Real()*FitnessOfx-FitnessOfOptimum);
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        VMHL_Result_Ey=fabs(MHL_MaximumOrMinimumOfTestFunction_Real()*FitnessOfx-FitnessOfOptimum);
    }

    return VMHL_Result_Ey;
}
//---------------------------------------------------------------------------
double MHL_ErrorEyOfTestFunction_Real(double FitnessOfx, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по значениям целевой функции найденного решения
    в задаче оптимизации для тестовой функции функции вещественной оптимизации.
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     FitnessOfx - значение целевой функции найденного решения алгоритмом оптимизации;
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по значениям целевой функции Ey.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorEyOfTestFunction_Real(FitnessOfx, VMHL_N);

    return VMHL_Result;
}