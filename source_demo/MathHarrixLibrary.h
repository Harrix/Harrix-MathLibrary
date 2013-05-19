#ifndef MATHHARRIXLIBRARY_H
#define MATHHARRIXLIBRARY_H
// КОНСТАНТЫ
const double MHL_TAU=0.61803398874989484820;
const double MHL_E=2.71828182845904523536;
const double MHL_LOG2E=1.44269504088896340736;
const double MHL_LOG10E=0.434294481903251827651;
const double MHL_LN2=0.693147180559945309417;
const double MHL_LN10=2.30258509299404568402;
const double MHL_PI=3.14159265358979323846;
const double MHL_PI_2=1.57079632679489661923;
const double MHL_PI_4=0.785398163397448309616;
const double MHL_1_PI=0.318309886183790671538;
const double MHL_2_PI=0.636619772367581343076;
const double MHL_1_SQRTPI=0.564189583547756286948;
const double MHL_2_SQRTPI=1.12837916709551257390;
const double MHL_SQRT2=1.41421356237309504880;
const double MHL_SQRT_2=0.707106781186547524401;
const double MHL_INFINITY=1.7E308;
const double MHL_MINFINITY=-1.7E308;

//ДЛЯ ГЕНЕРАТОРА СЛУЧАЙНЫХ ЧИСЕЛ
void MHL_SeedRandom(void);//Инициализатор генератора случайных чисел
double MHL_RandomNumber(void);//Генерирует вещественное случайное число из интервала (0;1)

//ПЕРЕМЕННЫЕ ПЕРЕЧИСЛЯЕМОГО ТИПА
enum EMHL_TypeSort {BubbleSort};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Вектора (Одномерные массивы)
template <class T> void TMHL_FillVector(T *VMHL_ResultVector, int VMHL_N, T x);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Вектора (Одномерные массивы)
//*****************************************************************
template <class T> void TMHL_FillVector(T *VMHL_ResultVector, int VMHL_N, T x)
{
/*
Функция заполняет вектор значениями, равных x.
Входные параметры:
 VMHL_ResultVector - указатель на преобразуемый массив;
 VMHL_N - количество элементов в массиве;
 x - число, которым заполняется вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=x;
}
//---------------------------------------------------------------------------

#endif // MATHHARRIXLIBRARY_H