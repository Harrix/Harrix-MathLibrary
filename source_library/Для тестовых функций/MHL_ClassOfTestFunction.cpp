int MHL_ClassOfTestFunction(TypeOfTestFunction Type)
{
    /*
    Функция выдает принадлежность тестовой функции к классу функций: бинарной, вещественной или иной оптимизации.
    Входные параметры:
     Type - тип тестовой функции.
     Смотреть виды в переменных перечисляемого типа в начале HarrixMathLibrary.h файла.
    Возвращаемое значение:
     Класс тестовой функции:
      1 - бинарной оптимизации;
      2 - вещественной оптимизации.
    */
    int VMHL_Result=0;

    if (Type==TestFunction_SumVector)
        return 1;

    if (Type==TestFunction_Ackley)
        return 2;
		
	if (Type==TestFunction_AdditivePotential)
        return 2;
		
    if (Type==TestFunction_MultiplicativePotential)
        return 2;
		
	if (Type==TestFunction_ReverseGriewank)
        return 2;

    if (Type==TestFunction_ParaboloidOfRevolution)
        return 2;

    if (Type==TestFunction_Rastrigin)
        return 2;

    if (Type==TestFunction_Rosenbrock)
        return 2;
		
	if (Type==TestFunction_HyperEllipsoid)
        return 2;
		
	if (Type==TestFunction_RotatedHyperEllipsoid)
        return 2;
		
	if (Type==TestFunction_Wave)
        return 2;
		
	if (Type==TestFunction_Multiextremal)
        return 2;
		
	if (Type==TestFunction_Multiextremal2)
        return 2;

    return VMHL_Result;
}