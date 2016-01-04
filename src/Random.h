//ДЛЯ ГЕНЕРАТОРОВ СЛУЧАЙНЫХ ЧИСЕЛ
enum TypeOfRandomNumberGenerator { StandardRandomNumberGenerator, MersenneTwisterRandomNumberGenerator };//тип генератора случайных чисел: стандартный или MersenneTwister:
void HML_SeedRandom(void);//Инициализатор генератора случайных чисел
double HML_RandomNumber(void);//Генерирует вещественное случайное число из интервала (0;1)
void HML_SetRandomNumberGenerator(TypeOfRandomNumberGenerator T);//Переназначить генератор случайных чисел на другой