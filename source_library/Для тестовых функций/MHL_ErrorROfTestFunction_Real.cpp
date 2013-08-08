double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации. 
	Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VMHL_Result_R = 1;
    int i;

    double *Optimum=new double[VMHL_N];

    MHL_OptimumOfTestFunction_Real(Optimum, VMHL_N);

    if (VMHL_TypeOfTestFunction==TestFunction_Ackley)
    {
        for (i=0;i<VMHL_N;i++)
        {
            if (fabs(x[i]-Optimum[i])<=MHL_PrecisionOfCalculationsOfTestFunction_Real()) VMHL_Result_R=0;
        }
    }

    if (VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)
    {
        for (i=0;i<VMHL_N;i++)
        {
            if (fabs(x[i]-Optimum[i])<=MHL_PrecisionOfCalculationsOfTestFunction_Real()) VMHL_Result_R=0;
        }
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rastrigin)
    {
        for (i=0;i<VMHL_N;i++)
        {
            if (fabs(x[i]-Optimum[i])<=MHL_PrecisionOfCalculationsOfTestFunction_Real()) VMHL_Result_R=0;
        }
    }

    if (VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)
    {
        for (i=0;i<VMHL_N;i++)
        {
            if (fabs(x[i]-Optimum[i])<=MHL_PrecisionOfCalculationsOfTestFunction_Real()) VMHL_Result_R=0;
        }
    }

    delete [] Optimum;

    return VMHL_Result_R;
}
//---------------------------------------------------------------------------
double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение надежности найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации. 
	Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение надежности R.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorROfTestFunction_Real(x, VMHL_N);

    return VMHL_Result;
}