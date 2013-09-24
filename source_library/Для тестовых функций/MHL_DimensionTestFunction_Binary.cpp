int MHL_DimensionTestFunction_Binary(int i)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции бинарной оптимизации
    по номеру подзадачи (число подзадач по функции MHL_GetCountOfSubProblems_Binary).
    Включает в себя все тестовые функции бинарной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     i - номер подзадачи (начиная с нуля).
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции бинарной оптимизации.
    */
    int VMHL_Result = 0;

    //проверка
    if (i<0) i=0;
    if (i>MHL_GetCountOfSubProblems_Binary()) i=MHL_GetCountOfSubProblems_Binary();

    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        if (i==0) VMHL_Result = 20;
        if (i==1) VMHL_Result = 30;
        if (i==2) VMHL_Result = 40;
        if (i==3) VMHL_Result = 50;
        if (i==4) VMHL_Result = 60;
        if (i==5) VMHL_Result = 70;
        if (i==6) VMHL_Result = 80;
        if (i==7) VMHL_Result = 90;
        if (i==8) VMHL_Result = 100;
        if (i==9) VMHL_Result = 200;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int MHL_DimensionTestFunction_Binary(int i, TypeOfTestFunction Type)
{
    /*
    Функция определяет размерность тестовой задачи для тестовой функции бинарной оптимизации
    по номеру подзадачи (число подзадач по функции MHL_GetCountOfSubProblems_Binary).
    Входные параметры:
     i - номер подзадачи (начиная с нуля);
     Type - тип тестовой функции.
    Возвращаемое значение:
     Размерность тестовой задачи для тестовой функции бинарной оптимизации.
    */
    int VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_DimensionTestFunction_Binary(i);

    return VMHL_Result;
}