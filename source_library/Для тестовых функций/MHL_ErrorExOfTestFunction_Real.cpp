double MHL_ErrorExOfTestFunction_Real(double *x, int VMHL_N)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
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

    double *Optimum=new double[VMHL_N];

    MHL_OptimumOfTestFunction_Real(Optimum, VMHL_N);

    if ((VMHL_TypeOfTestFunction==TestFunction_Ackley)||(VMHL_TypeOfTestFunction==TestFunction_ParaboloidOfRevolution)||(VMHL_TypeOfTestFunction==TestFunction_Rastrigin)||(VMHL_TypeOfTestFunction==TestFunction_Rosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_AdditivePotential)||(VMHL_TypeOfTestFunction==TestFunction_MultiplicativePotential)||(VMHL_TypeOfTestFunction==TestFunction_ReverseGriewank)||(VMHL_TypeOfTestFunction==TestFunction_HyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_RotatedHyperEllipsoid)||(VMHL_TypeOfTestFunction==TestFunction_Wave)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal2)||(VMHL_TypeOfTestFunction==TestFunction_Sombrero)||(VMHL_TypeOfTestFunction==TestFunction_Katnikov)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal3)||(VMHL_TypeOfTestFunction==TestFunction_Multiextremal4)||(VMHL_TypeOfTestFunction==TestFunction_StepFunction)||(VMHL_TypeOfTestFunction==TestFunction_Rana)||(VMHL_TypeOfTestFunction==TestFunction_ShekelsFoxholes)||(VMHL_TypeOfTestFunction==TestFunction_EggHolder)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithChange)||(VMHL_TypeOfTestFunction==TestFunction_RastriginWithTurning)||(VMHL_TypeOfTestFunction==TestFunction_Schwefel)||(VMHL_TypeOfTestFunction==TestFunction_Griewangk)||(VMHL_TypeOfTestFunction==TestFunction_InvertedRosenbrock)||(VMHL_TypeOfTestFunction==TestFunction_GaussianQuartic)||(VMHL_TypeOfTestFunction==TestFunction_RastriginNovgorod))
    {
        for (i=0;i<VMHL_N;i++)
            VMHL_Result_Ex+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
        VMHL_Result_Ex=sqrt(VMHL_Result_Ex)/double(VMHL_N);
    }
	
	if (VMHL_TypeOfTestFunction==TestFunction_Himmelblau)
    {
	double *Ex = new double[4];
	for (i=0;i<VMHL_N;i++) Ex[i]=0;
	
	Optimum[0]=( 3.0     ); Optimum[1]=( 2.0     );
	for (i=0;i<VMHL_N;i++)
        Ex[0]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[0]=sqrt(Ex[0])/double(VMHL_N);
	
	Optimum[0]=(-2.805118); Optimum[1]=( 3.131312);
	for (i=0;i<VMHL_N;i++)
        Ex[1]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[1]=sqrt(Ex[1])/double(VMHL_N);
	
	Optimum[0]=(-3.779310); Optimum[1]=(-3.283186);
	for (i=0;i<VMHL_N;i++)
        Ex[2]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[2]=sqrt(Ex[2])/double(VMHL_N);
	
	Optimum[0]=( 3.584428); Optimum[1]=(-1.848126);
	for (i=0;i<VMHL_N;i++)
        Ex[3]+=(x[i]-Optimum[i])*(x[i]-Optimum[i]);
    Ex[3]=sqrt(Ex[3])/double(VMHL_N);	
	
	VMHL_Result_Ex = TMHL_MinimumOfVector(Ex,4);
	
	delete [] Ex;
    }

    delete [] Optimum;

    return VMHL_Result_Ex;
}
//---------------------------------------------------------------------------
double MHL_ErrorExOfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type)
{
    /*
    Функция определяет значение ошибки по входным параметрам найденного решения
    в задаче оптимизации для тестовой функции вещественной оптимизации.
	Включает в себя все тестовые функции вещественной оптимизации.
    Входные параметры:
     x - указатель на исходный массив (найденное решение алгоритмом);
     VMHL_N - размер массива x;
     Type - тип тестовой функции.
    Возвращаемое значение:
     Значение ошибки по входным параметрам Ex.
    */
    double VMHL_Result = 0;

    VMHL_TypeOfTestFunction = Type;

    VMHL_Result = MHL_ErrorExOfTestFunction_Real(x, VMHL_N);

    return VMHL_Result;
}