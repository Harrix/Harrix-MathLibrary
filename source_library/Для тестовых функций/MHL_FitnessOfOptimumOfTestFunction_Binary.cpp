double MHL_FitnessOfOptimumOfTestFunction_Binary(int VMHL_N)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции.
    Включает в себя все тестовые функции.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     VMHL_N - размер массива x в решаемой задаче оптимизации.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        VMHL_Result = VMHL_N;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
double MHL_FitnessOfOptimumOfTestFunction_Binary(int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение целевой функции в оптимуме для тестовой функции.
    Включает в себя все тестовые функции.
    Входные параметры:
     VMHL_N - размер массива x в решаемой задаче оптимизации;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение тестовой функции в оптимальной точке.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_FitnessOfOptimumOfTestFunction_Binary(VMHL_N);

    return VMHL_Result;
}