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