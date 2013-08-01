double MHL_ErrorExOfTestFunction_Binary(int *x, int VMHL_N)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции. Включает в себя все тестовые функции.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VMHL_Result_Ex = 0;
    int i;

    int *Optimum=new int[VMHL_N];

    MHL_OptimumOfTestFunction_Binary(Optimum, VMHL_N);


    if (VMHL_TypeOfTestFunction==TestFunction_SumVector)
    {
        for (i=0;i<VMHL_N;i++)
            VMHL_Result_Ex+=fabs(x[i]-Optimum[i]);
    }

    delete [] Optimum;

    return VMHL_Result_Ex;
}
//---------------------------------------------------------------------------
double MHL_ErrorExOfTestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции. Включает в себя все тестовые функции.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorExOfTestFunction_Binary(x, VMHL_N);

    return VMHL_Result;
}