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
template <class T> int TMHL_CheckElementInVector(T *x, int VMHL_N, T a);
template <class T> bool TMHL_EqualityOfVectors(T *a, T *b, int VMHL_N);
template <class T> void TMHL_FibonacciNumbersVector(T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_FillVector(T *VMHL_ResultVector, int VMHL_N, T x);
template <class T> T TMHL_MaximumOfVector(T *VMHL_Vector, int VMHL_N);
template <class T> T TMHL_MinimumOfVector(T *VMHL_Vector, int VMHL_N);
template <class T> int TMHL_NumberOfMaximumOfVector(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfMinimumOfVector(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfNegativeValues(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfPositiveValues(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfZeroValues(T *a, int VMHL_N);
template <class T> void TMHL_OrdinalVector(T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_OrdinalVectorZero(T *VMHL_ResultVector, int VMHL_N);
template <class T> int TMHL_SearchFirstNotZero(T *x, int VMHL_N);
template <class T> int TMHL_SearchFirstZero(T *x, int VMHL_N);
template <class T> T TMHL_SumSquareVector(T *VMHL_Vector,int VMHL_N);
template <class T> T TMHL_SumVector(T *VMHL_Vector,int VMHL_N);
template <class T> void TMHL_VectorMinusVector(T *a, T *b, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_VectorMinusVector(T *VMHL_ResultVector, T *b, int VMHL_N);
template <class T> void TMHL_VectorMultiplyNumber(T *VMHL_ResultVector, int VMHL_N, T Number);
template <class T> void TMHL_VectorPlusVector(T *a, T *b, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_VectorPlusVector(T *VMHL_ResultVector, T *b, int VMHL_N);
template <class T> void TMHL_VectorToVector(T *VMHL_Vector, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_ZeroVector(T *VMHL_ResultVector,int VMHL_N);

//Гиперболические функции
double MHL_Cosech(double x);
double MHL_Cosh(double x);
double MHL_Cotanh(double x);
double MHL_Sech(double x);
double MHL_Sinh(double x);
double MHL_Tanh(double x);

//Перевод единиц измерений
double MHL_DegToRad(double VMHL_X);
double MHL_RadToDeg(double VMHL_X);

//Случайные объекты
int MHL_BitNumber(double P);
int MHL_BitNumber();
void MHL_RandomRealMatrix(double **VMHL_ResultMatrix, double Left, double Right, int VMHL_N, int VMHL_M);
void MHL_RandomRealMatrixInCols(double **VMHL_ResultMatrix, double *Left, double *Right, int VMHL_N, int VMHL_M);
void MHL_RandomRealMatrixInElements(double **VMHL_ResultMatrix, double **Left, double **Right, int VMHL_N, int VMHL_M);
void MHL_RandomRealMatrixInRows(double **VMHL_ResultMatrix, double *Left, double *Right, int VMHL_N, int VMHL_M);
void MHL_RandomRealVector(double *VMHL_ResultVector, double Left, double Right, int VMHL_N);
void MHL_RandomRealVectorInElements(double *VMHL_ResultVector, double *Left, double *Right, int VMHL_N);
void MHL_RandomVectorOfProbability(double *VMHL_ResultVector, int VMHL_N);

//Случайные числа
double MHL_RandomNormal(double Mean, double StdDev);
double MHL_RandomUniform(double a, double b);
int MHL_RandomUniformInt(int n, int m);

//Тригонометрические функции
double MHL_Cos(double x);
double MHL_CosDeg(double x);
double MHL_Cosec(double x);
double MHL_CosecDeg(double x);
double MHL_Cotan(double x);
double MHL_CotanDeg(double x);
double MHL_Sec(double x);
double MHL_SecDeg(double x);
double MHL_Sin(double x);
double MHL_SinDeg(double x);
double MHL_Tan(double x);
double MHL_TanDeg(double x);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Вектора (Одномерные массивы)
//*****************************************************************
template <class T> int TMHL_CheckElementInVector(T *x, int VMHL_N, T a)
{
/*
Функция проверяет наличие элемента а в векторе x.
Входные параметры:
 x - указатель на вектор;
 VMHL_N - размер массива;
 a - проверяемый элемент.
Возвращаемое значение:
 Номер (начиная с нуля) первого элемента, равного искомому. Если такого элемента нет, то возвращается -1.
*/
int VMHL_Result=-1;
int i=0;
while ((i<VMHL_N)&&(VMHL_Result==-1))
 {
 if (x[i]==a) VMHL_Result=i;//нашли
 i++;
 }
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> bool TMHL_EqualityOfVectors(T *a, T *b, int VMHL_N)
{
/*
Функция проверяет равенство векторов.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_N - размер векторов.
Возвращаемое значение:
 true - вектора совпадают;
 false - вектора не совпадают.
*/
int VMHL_Result=true;
for (int i=0;i<VMHL_N;i++)
 if (a[i]!=b[i]) VMHL_Result=false;

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_FibonacciNumbersVector(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция заполняет массив числами Фибоначчи.
Входные параметры:
 VMHL_ResultVector - указатель на массив, в который записывается результат;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
if (VMHL_N>=1) VMHL_ResultVector[0]=1;
if (VMHL_N>=2) VMHL_ResultVector[1]=1;
if (VMHL_N>2)
 {
 for (int i=2;i<VMHL_N;i++)
  VMHL_ResultVector[i]=VMHL_ResultVector[i-1]+VMHL_ResultVector[i-2];
 }
}
//---------------------------------------------------------------------------
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
template <class T> T TMHL_MaximumOfVector(T *VMHL_Vector, int VMHL_N)
{
/*
Функция ищет максимальный элемент в векторе (одномерном массиве).
Входные параметры:
 VMHL_Vector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Максимальный элемент.
*/
T VMHL_Result;
VMHL_Result=VMHL_Vector[0];
for (int i=1;i<VMHL_N;i++)
    if (VMHL_Vector[i]>VMHL_Result)
        VMHL_Result=VMHL_Vector[i];

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_MinimumOfVector(T *VMHL_Vector, int VMHL_N)
{
/*
Функция ищет минимальный элемент в векторе (одномерном массиве).
Входные параметры:
 VMHL_Vector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Минимальный элемент.
*/
T VMHL_Result;
VMHL_Result=VMHL_Vector[0];
for (int i=1;i<VMHL_N;i++)
    if (VMHL_Vector[i]<VMHL_Result)
        VMHL_Result=VMHL_Vector[i];

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_NumberOfMaximumOfVector(T *a, int VMHL_N)
{
/*
Функция ищет номер максимального элемента в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Номер максимального элемента.
*/
T Max;
Max=a[0];
int VMHL_Result=0;
for (int i=1;i<VMHL_N;i++)
 if (a[i]>Max)
  {
  Max=a[i];
  VMHL_Result=i;
  }
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_NumberOfMinimumOfVector(T *a, int VMHL_N)
{
/*
Функция ищет номер минимального элемента в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Номер минимального элемента.
*/
T Min;
Min=a[0];
int VMHL_Result=0;
for (int i=1;i<VMHL_N;i++)
 if (a[i]<Min)
  {
  Min=a[i];
  VMHL_Result=i;
  }
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_NumberOfNegativeValues(T *a, int VMHL_N)
{
/*
Функция подсчитывает число отрицательных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на исходный массив;
 VMHL_N - количество элементов в массиве.
Выходной параметр:
 Число отрицательных значений в массиве.
*/
int VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
	if (a[i]<0)
		VMHL_Result++;
		
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_NumberOfPositiveValues(T *a, int VMHL_N)
{
/*
Функция подсчитывает число положительных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на исходный массив;
 VMHL_N - количество элементов в массиве.
Выходной параметр:
 Число положительных значений в массиве.
*/
int VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
    if (a[i]>0)
        VMHL_Result++;

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_NumberOfZeroValues(T *a, int VMHL_N)
{
/*
Функция подсчитывает число нулевых значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на исходный массив;
 VMHL_N - количество элементов в массиве.
Выходной параметр:
 Число нулевых значений в массиве.
*/
int VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
    if (a[i]==0)
        VMHL_Result++;

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_OrdinalVector(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция заполняет вектор значениями, равные номеру элемента, начиная с единицы.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (одномерный массив), который и заполняется;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
    VMHL_ResultVector[i]=i+1;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_OrdinalVectorZero(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция заполняет вектор значениями, равные номеру элемента, начиная с нуля.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (одномерный массив), который и заполняется;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) 
    VMHL_ResultVector[i]=i;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_SearchFirstNotZero(T *x, int VMHL_N)
{
/*
Функция возвращает номер первого ненулевого элемента массива.
Входные параметры:
 x - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Номер первого ненулевого элемента массива (начиная с нуля). Если такого элемента нет, то возвращается -1.
*/
int VMHL_Result=-1;
int i=0;
while ((i<VMHL_N)&&(VMHL_Result==-1))
 {
 if (x[i]!=0)
  VMHL_Result=i;//нашли
 i++;
 }
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_SearchFirstZero(T *x, int VMHL_N)
{
/*
Функция возвращает номер первого нулевого элемента массива.
Входные параметры:
 x - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Номер первого нулевого элемента массива (начиная с нуля). Если такого элемента нет, то возвращается -1.
*/
int VMHL_Result=-1;
int i=0;
while ((i<VMHL_N)&&(VMHL_Result==-1))
 {
 if (x[i]==0)
  VMHL_Result=i;//нашли
 i++;
 }
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_SumSquareVector(T *VMHL_Vector,int VMHL_N)
{
/*
Функция вычисляет сумму квадратов элементов вектора.
Входные параметры:
 VMHL_Vector - указатель на исходный массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Сумма элементов массива.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
    VMHL_Result+=VMHL_Vector[i]*VMHL_Vector[i];

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_SumVector(T *VMHL_Vector,int VMHL_N)
{
/*
Функция вычисляет сумму элементов вектора.
Входные параметры:
 VMHL_Vector - указатель на исходный массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Сумма элементов массива.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
    VMHL_Result+=VMHL_Vector[i];

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_VectorMinusVector(T *a, T *b, T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция вычитает поэлементно из одного массива другой и записывает результат в третий массив.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_ResultVector - вектор разности;
 VMHL_N - размер векторов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
    VMHL_ResultVector[i]=a[i]-b[i];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_VectorMinusVector(T *VMHL_ResultVector, T *b, int VMHL_N)
{
/*
Функция вычитает поэлементно из одного массива другой и записывает результат в первый массив.
Входные параметры:
 VMHL_ResultVector - первый вектор, из которого вычитают второй вектор;
 b - вторый вектор;
 VMHL_N - размер векторов.
Возвращаемое значение:
 Отсутствует
*/
for (int i=0;i<VMHL_N;i++)
    VMHL_ResultVector[i]-=b[i];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_VectorMultiplyNumber(T *VMHL_ResultVector, int VMHL_N, T Number)
{
/*
Функция умножает вектор на число.
Входные параметры:
 VMHL_ResultVector - вектор (в нем и сохраняется результат);
 VMHL_N - размер вектора;
 Number - число, на которое умножается вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) 
   VMHL_ResultVector[i]*=Number;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_VectorPlusVector(T *a, T *b, T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция складывает поэлементно из одного массива другой и записывает результат в третий массив.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_ResultVector - вектор разности;
 VMHL_N - размер векторов.
Возвращаемое значение:
 Отсутствует
*/
for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=a[i]+b[i];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_VectorPlusVector(T *VMHL_ResultVector, T *b, int VMHL_N)
{
/*
Функция складывает поэлементно из одного массива другой и записывает результат в первый массив.
Входные параметры:
 VMHL_ResultVector - первый вектор, к которому прибавляют второй вектор;
 b - вторый вектор;
 VMHL_N - размер векторов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]+=b[i];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_VectorToVector(T *VMHL_Vector, T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция копирует содержимое вектора (одномерного массива) VMHL_Vector в массив VMHL_ResultVector.
Входные параметры:
 VMHL_Vector - указатель на исходный массив;
 VMHL_ResultVector - указатель на массив в который производится запись;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
    VMHL_ResultVector[i]=VMHL_Vector[i];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_ZeroVector(T *VMHL_ResultVector,int VMHL_N)
{
/*
Функция зануляет массив.
Входные параметры:
 VMHL_ResultVector - указатель на преобразуемый массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
    VMHL_ResultVector[i]=0;
}
//---------------------------------------------------------------------------
//*****************************************************************
//Гиперболические функции
//*****************************************************************
//*****************************************************************
//Перевод единиц измерений
//*****************************************************************
//*****************************************************************
//Случайные объекты
//*****************************************************************
//*****************************************************************
//Случайные числа
//*****************************************************************
//*****************************************************************
//Тригонометрические функции
//*****************************************************************

#endif // MATHHARRIXLIBRARY_H