double MHL_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VMHL_N)
{
    /*
    Функция определяет на сколько частей нужно делить каждую координату в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации и какая при этом требуется
    точность для подсчета надежности. Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Обязательно вызвать один раз перед ее использованием функцию MHL_DefineTestFunction,
    в которой определяется конкретный тип задачи оптимизации.
    Входные параметры:
     NumberOfParts - указатель на массив, куда будет записываться результат;
     VMHL_N - размер массива x.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VMHL_Result_E = 0;
    int i;

    if ((VMHL_TypeOfTestFunction==TestFunction_Ackley)||(VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VMHL_TypeOfTestFunction==TestFunction_Rastrigin)||(VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)||(VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_Wave)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal))
    {
        for (i=0;i<VMHL_N;i++) NumberOfParts[i]=4095;
    }

    VMHL_Result_E=MHL_PrecisionOfCalculationsOfTestFunction_Real();

    return VMHL_Result_E;
}
//---------------------------------------------------------------------------
double MHL_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет на сколько частей нужно делить каждую координату в задаче оптимизации
    для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации и какая при этом требуется
    точность для подсчета надежности. Более точную информацию ищите в описаниях тестовых функций:
    https://github.com/Harrix/HarrixTestFunctions
    Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     NumberOfParts - указатель на массив, куда будет записываться результат;
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Точность вычислений.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_NumberOfPartsOfTestFunction_Real(NumberOfParts, VMHL_N);

    return VMHL_Result;
}