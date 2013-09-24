//ДЛЯ ГЕНЕРАТОРОВ СЛУЧАЙНЫХ ЧИСЕЛ
unsigned int MHL_Dummy;//Результат инициализации гстандартного генератора случайных чисел
TypeOfRandomNumberGenerator MHL_TypeOfRandomNumberGenerator;//тип генератора случайных чисел
MTRand mt((unsigned)time(NULL));//Инициализатор генератора случайных чисел Mersenne Twister
MTRand drand;//Для генерирования случайного числа в диапозоне [0,1).

//СЛУЖЕБНЫЕ ДОПОЛНИТЕЛЬНЫЕ ПЕРМЕННЫЕ
double (*VMHL_TempFunction)(double*,int);
int *VMHL_TempInt1;
int *VMHL_TempInt2;
int *VMHL_TempInt3;
int *VMHL_TempInt4;
double *VMHL_TempDouble1;
double *VMHL_TempDouble2;
double *VMHL_TempDouble3;

TypeOfTestFunction VMHL_TypeOfTestFunction;//для функций по работе с тестовыми функциями для анализа эффективности алгоритмов
int CountOfFitness;//количество вызовов тестовой функции при запуске алгоритма оптимизации