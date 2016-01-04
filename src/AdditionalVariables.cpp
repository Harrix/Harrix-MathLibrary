//ДЛЯ ГЕНЕРАТОРОВ СЛУЧАЙНЫХ ЧИСЕЛ
unsigned int HML_Dummy;//Результат инициализации стандартного генератора случайных чисел
TypeOfRandomNumberGenerator HML_TypeOfRandomNumberGenerator;//тип генератора случайных чисел
MTRand mt((unsigned)time(NULL));//Инициализатор генератора случайных чисел Mersenne Twister
MTRand drand;//Для генерирования случайного числа в диапазоне [0,1).

//СЛУЖЕБНЫЕ ДОПОЛНИТЕЛЬНЫЕ ПЕРМЕННЫЕ
double (*VHML_TempFunction)(double*,int);
int *VHML_TempInt1;
int *VHML_TempInt2;
int *VHML_TempInt3;
int *VHML_TempInt4;
double *VHML_TempDouble1;
double *VHML_TempDouble2;
double *VHML_TempDouble3;