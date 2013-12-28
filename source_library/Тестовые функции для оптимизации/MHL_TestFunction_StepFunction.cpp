double MHL_TestFunction_StepFunction(double *x, int VMHL_N)
{
/*
Функция многих переменных: Функция Step (модифицированная версия De Jong 3).
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VMHL_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
    double VMHL_Result=0;

    double H=0;

    for (int i=0;i<VMHL_N;i++)
        H+=fabs(int(x[i]));

    if (H!=0)
    {
        for (int i=0;i<VMHL_N;i++)
            VMHL_Result+=(int(x[i]))*(int(x[i]));
    }
    else
    {
        for (int i=0;i<VMHL_N;i++)
            VMHL_Result+=fabs(x[i]);
    }

    return VMHL_Result;
}