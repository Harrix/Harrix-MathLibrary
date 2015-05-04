//HarrixMathLibrary
//Версия 4.1
//Сборник различных математических функций и шаблонов с открытым кодом на языке C++.
//https://github.com/Harrix/HarrixMathLibrary
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixMathLibrary.h"
#include "mtrand.h"//генератор случайных чисел Mersenne Twister

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

void HML_SeedRandom(void)
{
/*
Инициализатор генератора случайных чисел.
В данном случае используется самый простой его вариант со всеми его недостатками.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Отсутствуют.
*/
//StandardRandomNumberGenerator
//Инициализатор стандартного генератора случайных чисел
//В качестве начального значения для ГСЧ используем текущее время
HML_Dummy=(unsigned)time(NULL);
srand(HML_Dummy);//Стандартная инициализация
rand();//первый вызов для контроля

//MersenneTwisterRandomNumberGenerator
//Инициализатор генератора случайных чисел Mersenne Twister
//В качестве начального значения для ГСЧ используем текущее время
//Инициализациz происходит еще при подключении данного файла

//Назначаем генератор по умолчанию как Mersenne Twister
HML_TypeOfRandomNumberGenerator = MersenneTwisterRandomNumberGenerator;
}
//---------------------------------------------------------------------------
double HML_RandomNumber(void)
{
/*
Генератор случайных чисел (ГСЧ).
Есть два варианта генератора случайных чисел, который можно переключать
функцией HML_SetRandomNumberGenerator.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Случайное вещественное число из интервала (0;1) или [0;1) по равномерному закону распределения.
*/
    if (HML_TypeOfRandomNumberGenerator==StandardRandomNumberGenerator)
        return (double)rand()/(RAND_MAX+1);
    if (HML_TypeOfRandomNumberGenerator==MersenneTwisterRandomNumberGenerator)
        return drand();

    return 0;
}
//---------------------------------------------------------------------------

void HML_SetRandomNumberGenerator(TypeOfRandomNumberGenerator T)
{
/*
Функция переназначает генератор случайных чисел.
Входные параметры:
 TypeOfRandomNumberGenerator - тип генератора случайных чисел:
  StandardRandomNumberGenerator - стандартный генератор случайных чисел;
  MersenneTwisterRandomNumberGenerator - генератор случайных чисел Mersenne Twister.
Возвращаемое значение:
 Отсутствует.
*/
    HML_TypeOfRandomNumberGenerator = T;
}
//---------------------------------------------------------------------------

//*****************************************************************
//Вектора (Одномерные массивы)
//*****************************************************************
void HML_DependentNoiseInVector(double *VHML_ResultVector, double percent, int VHML_N)
{
/*
Функция добавляет к элементам выборки помеху, зависящую от значения элемента выборки
(плюс-минус сколько-то процентов модуля разности минимального и максимального элемента выборки,
умноженного на значение элемента).
Входные параметры:
 VHML_ResultVector - указатель на массив;
 percent - процент шума;
 VHML_N - количество элементов в массивах.
Возвращаемое значение:
 Отсутствует.
*/
if (percent<0) percent=0;
int i;
double max=HML_MaximumOfVector(VHML_ResultVector,VHML_N);//Максимальное значение
double min=HML_MinimumOfVector(VHML_ResultVector,VHML_N);//Минимальное значение
double b=percent*(max-min)/100.;//Амплитуда шума
for (i=0;i<VHML_N;i++)
 VHML_ResultVector[i]+=VHML_ResultVector[i]*HML_RandomUniform(-b/2.,b/2.);
}
//---------------------------------------------------------------------------

double HML_EuclidNorma(double *a,int VHML_N)
{
/*
Функция вычисляет евклидовую норму вектора.
Входные параметры:
 a - указатель на вектор;
 VHML_N -  размер массива.
Возвращаемое значение:
 Значение евклидовой нормы вектора.
*/
int i;
double VHML_Result=0;

for (i=0;i<VHML_N;i++)
 VHML_Result+=a[i]*a[i];

VHML_Result=sqrt(double(VHML_Result));
return VHML_Result;
}
//---------------------------------------------------------------------------

void HML_NoiseInVector(double *VHML_ResultVector, double percent, int VHML_N)
{
/*
Функция добавляет к элементам выборки аддитивную помеху (плюс-минус сколько-то процентов
модуля разности минимального и максимального элемента выборки).
Входные параметры:
 VHML_ResultVector - указатель на массив;
 percent - процент шума;
 VHML_N - количество элементов в массивах.
Возвращаемое значение:
 Отсутствует.
*/
if (percent<0) percent=0;
int i;
double max=HML_MaximumOfVector(VHML_ResultVector,VHML_N);//Максимальное значение
double min=HML_MinimumOfVector(VHML_ResultVector,VHML_N);//Минимальное значение
double b=percent*(max-min)/100.;//Амплитуда шума
for (i=0;i<VHML_N;i++)
 VHML_ResultVector[i]+=HML_RandomUniform(-b/2.,b/2.);
}
//---------------------------------------------------------------------------

int HML_SeparateVectorLimitOnProductElements(int *VHML_Vector, int *Order, int Limit, int VHML_N)
{
    /*
Функция перегрупирует элементы массива так, чтобы произведение элементов в начале вектора было не больше Limit.
Для чего вообще функция нужна? У нас имеется несколько групп (в количестве VHML_N) с количеством элементов,
равных числу из вектора. Нужно разделить группы на две группы так, чтобы в одной из них произведение количеств элементов
было не больше Limit. При этом в Order сохраняем порядок элементов, а возвращаем количество элементов в первой подгруппе.
Задача возникла при построении таблицы, в которой надо показать все возможные комбинации (поэтому и произведение
учитывается), когда из каждой группы берем по одному элементу, а по горизонтали слишком много элементов не расставим.
Входные параметры:
 VHML_Vector - указатель на вектор, в котором хранится количество элементов в каждой группе (все должн быть положительны);
 Order - массив, в котором сохраняется новый порядок элементов. То есть это строка перестановка, где значение элемента
 говорит, что на этой позиции должен находится соответствующая группа из VHML_Vector.
 Limit - какое максимальное произведение элементов должно быть в первой группе.
 VHML_N - размер массива VHML_Vector и Order.
Возвращаемое значение:
 Количество первых элементов в Order, которые относятся к первой группировке групп.
 Если это невозможно, то возвращается -1 (в случае, если минимальный элемент).
Примечание. Да, функция специфическая.
*/
    int VHML_Result=-1;
    int *VHML_VectorTemp = new int[VHML_N];//временная копия массива
    int *VHML_NumberTemp = new int[VHML_N];//тут номера элементов будем хранить
    HML_VectorToVector(VHML_Vector,VHML_VectorTemp,VHML_N);
    HML_ZeroVector(Order,VHML_N);
    HML_OrdinalVectorZero(VHML_NumberTemp,VHML_N);

    //Отсортируем массив
    HML_BubbleSortWithConjugateVector(VHML_VectorTemp, VHML_NumberTemp, VHML_N);
    //скопируем в итоговый массив Order
    HML_VectorToVector(VHML_NumberTemp,Order,VHML_N);

    if (VHML_VectorTemp[0]>Limit)
    {
        VHML_Result=-1;
    }
    else
    {
        int p=1;
        int pTemp;
        int num=0;
        for (int i=0;i<VHML_N;i++)
        {
          pTemp=p*VHML_Vector[i];
          if (pTemp>Limit)
          {
            break;
          }
          else
          {
              p=pTemp;
              num=i;
          }
        }
        VHML_Result=num+1;
    }

    delete [] VHML_VectorTemp;
    delete [] VHML_NumberTemp;
    return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_SeparateVectorLimitOnProductElementsTwo(int *VHML_Vector, int *Order, int Limit, int VHML_N)
{
    /*
Функция перегрупирует элементы массива так, чтобы произведение элементов в начале вектора было не больше Limit.
Алгоритм в данной функции немного другой, чем в функции HML_SeparateVectorLimitOnProductElements.
Для чего вообще функция нужна? У нас имеется несколько групп (в количестве VHML_N) с количеством элементов,
равных числу из вектора. Нужно разделить группы на две группы так, чтобы в одной из них произведение количеств элементов
было не больше Limit. При этом в Order сохраняем порядок элементов, а возвращаем количество элементов в первой подгруппе.
Задача возникла при построении таблицы, в которой надо показать все возможные комбинации (поэтому и произведение
учитывается), когда из каждой группы берем по одному элементу, а по горизонтали слишком много элементов не расставим.
Входные параметры:
 VHML_Vector - указатель на вектор, в котором хранится количество элементов в каждой группе (все должн быть положительны);
 Order - массив, в котором сохраняется новый порядок элементов. То есть это строка перестановка, где значение элемента
 говорит, что на этой позиции должен находится соответствующая группа из VHML_Vector.
 Limit - какое максимальное произведение элементов должно быть в первой группе.
 VHML_N - размер массива VHML_Vector и Order.
Возвращаемое значение:
 Количество первых элементов в Order, которые относятся к первой группировке групп.
 Если это невозможно, то возвращается -1 (в случае, если минимальный элемент).
Примечание. Да, функция специфическая.
*/
    int VHML_Result=-1;
    int *VHML_VectorTemp = new int[VHML_N];//временная копия массива
    int *VHML_NumberTemp = new int[VHML_N];//тут номера элементов будем хранить
    HML_VectorToVector(VHML_Vector,VHML_VectorTemp,VHML_N);
    HML_ZeroVector(Order,VHML_N);
    HML_OrdinalVectorZero(VHML_NumberTemp,VHML_N);

    //Отсортируем массив
    HML_BubbleSortWithConjugateVector(VHML_VectorTemp, VHML_NumberTemp, VHML_N);
    HML_ReverseVector(VHML_VectorTemp,VHML_N);
    HML_ReverseVector(VHML_NumberTemp,VHML_N);
    //скопируем в итоговый массив Order
    HML_VectorToVector(VHML_NumberTemp,Order,VHML_N);

    if (VHML_VectorTemp[VHML_N-1]>Limit)
    {
        VHML_Result=-1;
    }
    else
    {
        if (VHML_VectorTemp[0]>Limit)
        {
           while (VHML_VectorTemp[0]>Limit)
           {
               HML_ShiftLeftVector(VHML_VectorTemp,VHML_N);
               HML_ShiftLeftVector(VHML_NumberTemp,VHML_N);
               HML_ShiftLeftVector(Order,VHML_N);
           }
        }

        int p=1;
        int pTemp;
        int num=0;
        for (int i=0;i<VHML_N;i++)
        {
          pTemp=p*VHML_Vector[i];
          if (pTemp>Limit)
          {
            break;
          }
          else
          {
              p=pTemp;
              num=i;
          }
        }
        VHML_Result=num+1;
    }

    delete [] VHML_VectorTemp;
    delete [] VHML_NumberTemp;
    return VHML_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Генетические алгоритмы
//*****************************************************************
void HML_ArithmeticalCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N)
{
/*
Равномерное арифметическое скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 w - параметр скрещивания, который означает долю какого-то родителя в потомке: [0;1];
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
    int i;
    int k=HML_RandomUniformInt(0,2);//0 или 1

    if (w<0) w=0;
    if (w>1) w=1;

    if (k==0)//какой потомок "выживет": первый вариант или второй
     {
     for (i=0;i<VHML_N;i++) VHML_ResultVector[i]=w*Parent1[i]+(1.-w)*Parent2[i];
     }
    else
     {
     for (i=0;i<VHML_N;i++) VHML_ResultVector[i]=w*Parent2[i]+(1.-w)*Parent1[i];
     }
}
//---------------------------------------------------------------------------

void HML_BLXCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double alpha, int VHML_N)
{
/*
BLX скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 alpha - параметр скрещивания: [0;1];
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок только один.
*/
    double cmin,cmax,I;

    if (alpha<0) alpha=0;
    if (alpha>1) alpha=1;

    for (int i=0;i<VHML_N;i++)
    {
        cmin=HML_Min(Parent1[i],Parent2[i]);
        cmax=HML_Max(Parent1[i],Parent2[i]);
        I=cmax-cmin;
        VHML_ResultVector[i]=HML_RandomUniform(cmin-I*alpha,cmax+I*alpha);
    }
}
//---------------------------------------------------------------------------

double HML_BinaryFitnessFunction(int*x, int VHML_N)
{
/*
Служебная функция. Функция вычисляет целевую функцию бинарного вектора, в котором
закодирован вещественный вектор. Использует внутренние служебные переменные.
Функция для HML_StandartRealGeneticAlgorithm. Использовать для своих целей не рекомендуется.
Входные параметры:
 x - бинарный вектор;
 VHML_N - количество элементов в векторе.
Возвращаемое значение:
 Значение целевой функции бинарного вектора.
Примечание. Используемые переменные, переодеваемые из HML_StandartRealGeneticAlgorithm:
 VHML_TempFunction - указатель на целевая функция для вещественного решения;
 VHML_TempInt1 - указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование ;
 VHML_TempDouble1 - указатель на массив левых границ изменения вещественной переменной;
 VHML_TempDouble2 - указатель на массив правых границ изменения вещественной переменной;
 VHML_TempDouble3 - указатель на массив, в котором можно сохранить вещественный индивид при его раскодировании из бинарной строки;
 VHML_TempInt2 - указатель на размерность вещественного вектора;
 VHML_TempInt3 - указатель на тип преобразования вещественной задачи оптимизации в бинарное.
*/
double VHML_Result;
int RealLength=*VHML_TempInt2;//Размерность вещественного вектора
int TypOfConverting=*VHML_TempInt3;//Тип преобразования

if (VHML_N>0) VHML_Result=0;//строчка только для того, чтобы компилятор не говорил, что VHML_N не используется

//Переведем вектор из бинарного в вещественный
if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
 HML_BinaryVectorToRealVector(x,VHML_TempDouble3,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);

if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 HML_BinaryGrayVectorToRealVector(x,VHML_TempDouble3,VHML_TempInt4,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);

//Посчитаем значение целевой функции вещественного вектора
VHML_Result=VHML_TempFunction(VHML_TempDouble3,RealLength);

return VHML_Result;
}
//---------------------------------------------------------------------------

void HML_ExtendedLineForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N)
{
/*
Расширенное линейчатое скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 w - параметр скрещивания, который означает долю второго родителя в потомке: [-0.25;1.25];
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок только один.
*/
    if (w<-0.25) w=-0.25;
    if (w> 1.25) w= 1.25;

    for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=Parent1[i]+w*(Parent2[i]-Parent1[i]);
}
//---------------------------------------------------------------------------

void HML_FlatCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Плоское скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок только один.
*/
    double a,b;
     for (int i=0;i<VHML_N;i++)
     {
         a = Parent1[i];
         b = Parent2[i];
         if (a>b) HML_NumberInterchange(&a,&b);
         VHML_ResultVector[i]=HML_RandomUniform(a,b);
     }
}
//---------------------------------------------------------------------------

void HML_GeometricalCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N)
{
/*
Геометрическое скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 w - параметр скрещивания, который означает своеобразную долю какого-то родителя в потомке: [0;1];
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
    int i;
    int k=HML_RandomUniformInt(0,2);//0 или 1

    if (w<0) w=0;
    if (w>1) w=1;

    if (k==0)//какой потомок "выживет": первый вариант или второй
     {
     for (i=0;i<VHML_N;i++) VHML_ResultVector[i]=pow(Parent1[i],w)*pow(Parent2[i],1.-w);
     }
    else
     {
     for (i=0;i<VHML_N;i++) VHML_ResultVector[i]=pow(Parent2[i],w)*pow(Parent1[i],1.-w);
     }
}
//---------------------------------------------------------------------------

void HML_LinearCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Линейное скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
    int i;
    int k=HML_RandomUniformInt(0,3);//0 или 1

    if (k==0) for (i=0;i<VHML_N;i++) VHML_ResultVector[i]= 0.5*Parent1[i]+0.5*Parent2[i];
    if (k==1) for (i=0;i<VHML_N;i++) VHML_ResultVector[i]= 1.5*Parent1[i]-0.5*Parent2[i];
    if (k==2) for (i=0;i<VHML_N;i++) VHML_ResultVector[i]=-0.5*Parent1[i]+1.5*Parent2[i];
}
//---------------------------------------------------------------------------

void HML_MakeVectorOfProbabilityForProportionalSelectionV2(double *Fitness, double *VHML_ResultVector, int VHML_N)
{
/*
Функция формирует вектор вероятностей выбора индивидов из вектора значений функции пригодности.
Формирование вектора происходит согласно правилам пропорционально селекции из ГА.
Это служебная функция для использования функции пропорциональной селекции HML_ProportionalSelectionV2.
Входные параметры:
 Fitness - массив пригодностей (можно подавать не массив пригодностей, а массив значений целевой функции, но только для задач безусловной оптимизации);
 VHML_ResultVector - вектор вероятностей выбора индивидов из популяции, который мы и формируем;
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Отсутствует.
*/
//Вектор Fitness мы не меняем. Поэтому проводим копирование.
HML_VectorToVector(Fitness,VHML_ResultVector,VHML_N);

//Проводим нормировку вектора, с целью получения вектора вероятностей.
//Нормировка вектора чисел такая, чтобы максимальный элемент имел значение 1, а минимальный 0.
//После данный нормализованный вектор сжимается так чтобы сумма всех элементов стала равна 1.
HML_NormalizationVectorOne (VHML_ResultVector,VHML_N);
}
//---------------------------------------------------------------------------

void HML_MakeVectorOfProbabilityForRanklSelection(double *Rank, double *VHML_ResultVector, int VHML_N)
{
/*
Функция формирует вектор вероятностей выбора индивидов из вектора рангов для ранговой селекции.
Это служебная функция для использования функции ранговой селекции HML_RankSelection.
Входные параметры:
 Rank - массив рангов, которые были посчитаны функцией HML_MakeVectorOfRankForRankSelection;
 VHML_ResultVector - вектор вероятностей выбора индивидов из популяции, который мы и формируем;
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Отсутствует.
*/
//Вектор Fitness мы не меняем. Поэтому проводим копирование.
HML_VectorToVector(Rank,VHML_ResultVector,VHML_N);

//Проводим нормировку вектора, с целью получения вектора вероятностей.
double sum=HML_SumVector(VHML_ResultVector,VHML_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1./double(VHML_N);
 }
else
 {
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]/=sum;
 }
}
//---------------------------------------------------------------------------

void HML_MakeVectorOfRankForRankSelection(double *Fitness, double *VHML_ResultVector, int VHML_N)
{
/*
Проставляет ранги для элементов не сортированного массива, то есть номера,
начиная с 1, в отсортированном массиве.  Если в массиве есть несколько одинаковых
элементов, то ранги им присуждаются как среднеарифметические.
Это служебная функция для функции HML_RankSelection.
Входные параметры:
 Fitness - массив пригодностей (можно подавать не массив пригодностей, а массив значений целевой функции, но только для задач безусловной оптимизации);
 VHML_ResultVector - массив рангов, который мы и формируем;
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Отсутствует.
*/
int j,i,k;
double Sn;
double *F;
int *N;
F=new double[VHML_N];
N=new int[VHML_N];

HML_VectorToVector(Fitness,F,VHML_N);

//Заполним номерами
HML_OrdinalVectorZero(N,VHML_N);

//сортируем массив пригодностей со сопряженным массивом номеров индивидов
HML_BubbleSortWithConjugateVector (F,N,VHML_N);

//расставляем ранги
for (i=0;i<VHML_N;i++)
 VHML_ResultVector[N[i]]=i+1;

//для одинаковых элементов ранги делаем одинаковыми как среднее арифметическое
for (i=0;i<VHML_N-1;i++)
 {
 if (F[i]==F[i+1])
  {
  j=i+1;
  while ((F[i]==F[j])&&(j<VHML_N)) j++;
  Sn=HML_SumOfArithmeticalProgression(i+1,1,j-i);
  Sn/=double(j-i);
  for (k=0;k<VHML_N;k++)
   if (Fitness[k]==F[i]) VHML_ResultVector[k]=Sn;
  i=j-1;
  }
 }
delete[] N;
delete[] F;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void HML_MakeVectorOfRankZeroForRankSelection(double *Fitness, double *VHML_ResultVector, int VHML_N)
{
/*
Проставляет ранги для элементов не сортированного массива, то есть номера,
начиная с 0 (а не 1), в отсортированном массиве.  Если в массиве есть несколько одинаковых
элементов, то ранги им присуждаются как среднеарифметические.
Это модифицированная функция. Оригинальная функция HML_MakeVectorOfRankForRankSelectionпроставляет ранги с 1.
Входные параметры:
 Fitness - массив пригодностей (можно подавать не массив пригодностей, а массив значений целевой функции, но только для задач безусловной оптимизации);
 VHML_ResultVector - массив рангов, который мы и формируем;
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Отсутствует.
*/
int j,i,k;
double Sn;
double *F;
int *N;
F=new double[VHML_N];
N=new int[VHML_N];

HML_VectorToVector(Fitness,F,VHML_N);

//Заполним номерами
HML_OrdinalVectorZero(N,VHML_N);

//сортируем массив пригодностей со сопряженным массивом номеров индивидов
HML_BubbleSortWithConjugateVector (F,N,VHML_N);

//расставляем ранги
for (i=0;i<VHML_N;i++)
 VHML_ResultVector[N[i]]=i;//VHML_ResultVector[N[i]]=i+1;

//для одинаковых элементов ранги делаем одинаковыми как среднее арифметическое
for (i=0;i<VHML_N-1;i++)
 {
 if (F[i]==F[i+1])
  {
  j=i+1;
  while ((F[i]==F[j])&&(j<VHML_N)) j++;
  Sn=HML_SumOfArithmeticalProgression(i,1,j-i);
  Sn/=double(j-i);
  for (k=0;k<VHML_N;k++)
   if (Fitness[k]==F[i]) VHML_ResultVector[k]=Sn;
  i=j-1;
  }
 }
delete[] N;
delete[] F;
}
//---------------------------------------------------------------------------

void HML_NormalizationVectorAll(double *x,int VHML_N)
{
/*
Нормировка вектора чисел в отрезок [0;1] посредством функции HML_NormalizationNumberAll.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 x[i]=HML_NormalizationNumberAll(x[i]);
}
//---------------------------------------------------------------------------

void HML_NormalizationVectorMaxMin(double *VHML_ResultVector,int VHML_N)
{
/*
Нормировка вектора чисел так, чтобы максимальный элемент имел значение 1, а минимальный 0.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
double max=HML_MaximumOfVector(VHML_ResultVector,VHML_N);//максимальное значение
double min=HML_MinimumOfVector(VHML_ResultVector,VHML_N);//минимальное значение
int vbool=0;
if (max<HML_MINFINITY)
 {
 //Если все числа очень маленькие
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1.0;
 vbool=1;
 }
if ((min>HML_INFINITY)&&(vbool==0))
 {
 //Если все числа очень большие
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1.0;
 vbool=1;
 }
if ((min==max)&&(vbool==0))
 {
 //Если все числа равны
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1.0;
 vbool=1;
 }
if (vbool==0)
 {
 double d=max-min;
 for (int i=0;i<VHML_N;i++)
  VHML_ResultVector[i]=(VHML_ResultVector[i]-min)/d;
 }
}
//---------------------------------------------------------------------------

void HML_NormalizationVectorOne(double *VHML_ResultVector,int VHML_N)
{
/*
Нормировка вектора чисел в отрезок [0,1] так, чтобы сумма всех элементов была равна 1.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив), который и будет преобразовываться;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
//вначале отнормируем в интервал
HML_NormalizationVectorMaxMin (VHML_ResultVector,VHML_N);
//Вычислим сумму вектора
double sum=HML_SumVector(VHML_ResultVector,VHML_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1./double(VHML_N);
 }
else
 {
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]/=sum;
 }
}
//---------------------------------------------------------------------------

double HML_ProbabilityOfTournamentSelection(double *Fitness, double *VHML_ResultVector_Probability, int T, int VHML_N)
{
/*
Функция вычисляет вероятности выбора индивидов из популяции с помощью турнирной селекции.
Входные параметры:
 Fitness - указатель на вектор значений целевой функции (не пригодности) индивидов;
 VHML_ResultVector_Probability - указатель на вектор, в который будет проводиться запись;
 T - размер турнира;
 VHML_N -  размер массивов.
Возвращаемое значение:
 Сумму вектора вероятностей Probability.
Примечание:
 Данная функция не нужна для работы турнирной селекции через функцию HML_TournamentSelection
 в генетическом алгоритме. Функция предназначена для научных изысканий по исследованию работы
 различных видов селекций.
*/
    int i,j,minTn1,j0;
    double n1,n0,s,KC1,KC2,VHML_Result;

    //пробегаем по всем индивидам
    for (i=0;i<VHML_N;i++)
    {
        n0=0;//количество индивидов, которые выигрывают данный индивид
        n1=0;//количество индивидов, которые равны данному индивиду
        //Далее посчитаем их
        for (j=0;j<VHML_N;j++) if (Fitness[j]>Fitness[i]) n0++;
        for (j=0;j<VHML_N;j++) if (Fitness[j]==Fitness[i]) n1++;


        j0=HML_Max(1,int(T-(VHML_N-n1-n0)));
        minTn1=HML_Min(T,int(n1));
        s=0;
        //пробегаем по всем допустимым сочетаниям
        //точная формула в справке
        for (j=j0-1;j<minTn1;j++)
        {
                KC1=HML_KCombinations(j+1,int(n1));// число возможных сочетаний
                KC2=HML_KCombinations(T-(j+1),int(VHML_N-n1-n0));// число возможных сочетаний
                s+=KC1*KC2;
        }

        VHML_ResultVector_Probability[i]=s/(n1*HML_KCombinations(T,VHML_N));
    }


    VHML_Result=HML_SumVector(VHML_ResultVector_Probability,VHML_N);
    return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_ProportionalSelection(double *Fitness, int VHML_N)
{
/*
Пропорциональная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей.
Входные параметры:
 Fitness - массив пригодностей (можно подавать не массив пригодностей, а массив значений целевой функции, но только для задач безусловной оптимизации);
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Номер выбранной пригодности, а, соответственно, номер индивида популяции.
Примечание:
 Использовать реализацию оператора ГА в виде этой функции нецелесообразно ввиду того, что при каждом запуске
 создается дополнительный массив.
 Данная функция аналогична по действию (результат действия аналогичен):
 1. Связке функций HML_MakeVectorOfProbabilityForProportionalSelectionV2 и HML_ProportionalSelectionV2
 2. Функции HML_ProportionalSelectionV3
 Различия по временным затратам на выполнение. У этой реализации самое большое время выполнения.
*/
//Выбор в пропорциональной селекции производится согласно вектору вероятностей выбора индивидов.
//Создадим этот вектор
double *VectorOfProbability;
VectorOfProbability=new double[VHML_N];

//Вектор Fitness мы не меняем. Поэтому проводим копирование.
HML_VectorToVector(Fitness,VectorOfProbability,VHML_N);

//Проводим нормировку вектора, с целью получения вектора вероятностей.
//Нормировка вектора чисел такая, чтобы максимальный элемент имел значение 1, а минимальный 0.
//После данный нормализованный вектор сжимается так чтобы сумма всех элементов стала равна 1.
HML_NormalizationVectorOne (VectorOfProbability,VHML_N);

//Зная теперь вероятность выбора каждого индивида, проводим случайный выбор индивида.
int VHML_Result=HML_SelectItemOnProbability(VectorOfProbability,VHML_N);

delete [] VectorOfProbability;

//Возвращаем номер выбранного индивида
return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_ProportionalSelectionV2(double *VectorOfProbability, int VHML_N)
{
/*
Пропорциональная селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов,
который можно получить из вектора пригодностей индивидов посредством функции HML_MakeVectorOfProbabilityForProportionalSelectionV2.
Входные параметры:
 VectorOfProbability - массив вероятностей выбора индивидов для порпоциональной селекции;
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Номер выбранной пригодности, а, соответственно, номер индивида популяции.
Примечание:
 Связка данной функции и HML_MakeVectorOfProbabilityForProportionalSelectionV2 аналогична по действию (результат действия аналогичен):
 1. Функции HML_ProportionalSelection
 2. Функции HML_ProportionalSelectionV3
 Различия по временным затратам на выполнение. У этой связки выполнение быстрее, чем у HML_ProportionalSelection.
*/
int VHML_Result=HML_SelectItemOnProbability(VectorOfProbability,VHML_N);
return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_ProportionalSelectionV3(double *Fitness, int VHML_N)
{
/*
Пропорциональная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей (обязательно не отрицательными).
Входные параметры:
 Fitness - массив пригодностей (В отличии от HML_ProportionalSelection вектор пригодностей должен быть именно вектором пригодностей, то есть все элементы Fitness должны быть больше нуля);
 VHML_N - размер массива пригодностей.
Возвращаемое значение:
 Номер выбранной пригодности, а, соответственно, номер индивида популяции.
Примечание:
 Данная функция аналогична по действию (результат действия аналогичен):
 1. Связке функций HML_MakeVectorOfProbabilityForProportionalSelectionV2 и HML_ProportionalSelectionV2
 2. Функции HML_ProportionalSelection
 Различия по временным затратам на выполнение. Эта реализация быстрее, чем HML_SelectionProportional
 и почти равна связке функций HML_MakeVectorOfProbabilityForProportionalSelectionV2 и HML_ProportionalSelectionV2,
 но реализация отличается от формульной записи в угоду более простой записи в программировании, но ей тождественна.
*/
int VHML_Result=-1;//номер выбранного родителя
double Sum,r,s=0;
int i;
//получим сумму всех значений пригодностей
Sum=HML_SumVector(Fitness,VHML_N);
r=HML_RandomUniform(0,Sum);//случайное число по сумме
i=0;
while ((VHML_Result==-1)&&(i<VHML_N))
 {
 //определяем выбранного индивида
 s+=Fitness[i];
 if (s>=r) VHML_Result=i;
 i++;
 }
return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_RankSelection(double *VectorOfProbability, int VHML_N)
{
/*
Ранговая селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов,
который можно получить из вектора пригодностей индивидов посредством функции HML_MakeVectorOfRankForRankSelection
(для получения массива рангов) и потом функции HML_MakeVectorOfProbabilityForProportionalSelectionV2
(для получения массива вероятностей выбора индивидов по рангам).
Входные параметры:
 VectorOfProbability - массив вероятностей выбора индивидов для ранговой селекции;
 VHML_N - размер массива VectorProbability.
Возвращаемое значение:
 Номер выбранного индивида популяции.
*/
int VHML_Result=HML_SelectItemOnProbability(VectorOfProbability,VHML_N);
return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_SelectItemOnProbability(double *P, int VHML_N)
{
/*
Функция выбирает случайно номер элемента из вектора, где вероятность выбора каждого элемента
определяется значением в векторе P.
Входные параметры:
 P - вектор вероятностей выбора каждого элемента, то есть его компоненты должны быть из отрезка [0;1], а сумма их равна 1;
 VHML_N - размер вектора.
Возвращаемое значение:
 Номер выбранного элемента.
Примечание:
 Проверка на правильность вектора P не проводится, так как функция обычно вызывается
 многократно, а проводить постоянно проверку накладно. Всё на Вашей совести.
*/
int i=0;
int VHML_Result=-1;//номер выбранного элемента
double s=0;
double r;
r=HML_RandomNumber();//случайное число
while ((VHML_Result==-1)&&(i<VHML_N))
 {
 //определяем выбранный элемент
 s+=P[i];
 if (s>r) VHML_Result=i;
 i++;
 }
return VHML_Result;
}
//---------------------------------------------------------------------------

void HML_SinglepointCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Одноточечное скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
HML_SinglepointCrossover(Parent1, Parent2, VHML_ResultVector, VHML_N);
}
//---------------------------------------------------------------------------

int HML_StandartBinaryGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result)
{
/*
Стандартный генетический алгоритм для решения задач на бинарных строках. Реализация алгоритма из документа "Генетический алгоритм. Стандарт. v.3.0".
https://github.com/Harrix/Standard-Genetic-Algorithm
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина бинарной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида).
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (бинарный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=50;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
*/
//Считываем из Parameters параметры алгоритма
int ChromosomeLength=Parameters[0];//Длина хромосомы
int CountOfFitness=Parameters[1];//Число вычислений целевой функции
int TypeOfSel=Parameters[2];//Тип селекции
int TypeOfCros=Parameters[3];//Тип скрещивания
int TypeOfMutation=Parameters[4];//Тип мутации
int TypeOfForm=Parameters[5];//Тип формирования нового поколения

//Проверим данные
if (ChromosomeLength<1)	return 0;//Слишком маленькая длина хромосомы
if (CountOfFitness<1)	return 0;//Слишком маленькое число вычислений целевой функции
if (!((TypeOfSel==0)||(TypeOfSel==1)||(TypeOfSel==2))) return 0;//Тип селекции указан не верно
if (!((TypeOfCros==0)||(TypeOfCros==1)||(TypeOfCros==2))) return 0;//Тип скрещивания указан не верно
if (!((TypeOfMutation==0)||(TypeOfMutation==1)||(TypeOfMutation==2))) return 0;//Тип мутации указан не верно
if (!((TypeOfForm==0)||(TypeOfForm==1))) return 0;//Тип формирования нового поколения указан не верно

//Теперь определим остальные параметры алгоритма, исходя из полученной информации
//Размер популяции и число поколений должны быть приблизительно равны (насколько это возможно)
int NumberOfGenerations=int(sqrt(double(CountOfFitness)));//Число поколений
int PopulationSize=int(CountOfFitness/NumberOfGenerations);//Размер популяции
int SizeOfTournament=2;//В стандартном генетическом алгоритме на бинарных строках размер турнира равен 2

//Переменные
int I,i,j;//Счетчики
int NumberOfMaximumFitness;//Номер лучшего индивида в текущей популяции
double MaximumFitness;//Значение целевой функции лучшего индивида в текущей популяции
double BestFitness;//Значение целевой функции лучшего индивида за всё время работы алгоритма
int NumberOfParent1;//Номер первого выбранного родителя
int NumberOfParent2;//Номер второго выбранного родителя
double ProbabilityOfMutation;//Вероятность мутации

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Популяция индивидов
int **Population;
Population=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) Population[i]=new int[ChromosomeLength];
//Популяция потомков
int **ChildrenPopulation;
ChildrenPopulation=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) ChildrenPopulation[i]=new int[ChromosomeLength];
//Массив значений целевой функции индивидов
double *Fitness;
Fitness=new double[PopulationSize];
//Массив значений целевой функции потомков
double *ChildrenFitness;
ChildrenFitness=new double[PopulationSize];
//Массив для хранения произвольного индивида
int *TempIndividual;
TempIndividual=new int[ChromosomeLength];
//Массив для хранения лучшего индивида за всё время работы алгоритма
int *BestIndividual;
BestIndividual=new int[ChromosomeLength];
//Для пропорциональной и ранговой селекции нужен массив вероятностей выбора индивидов
double *VectorOfProbability;
VectorOfProbability=new double[PopulationSize];
//Для ранговой селекции нужен массив рангов индивидов
double *Rank;
Rank=new double[PopulationSize];
//Для турнирной селекции нужен служебный массив, содержащий информация о том, в турнире или нет индивид;
int *Taken;
Taken=new int[PopulationSize];
//Массив для хранения первого родителя
int *Parent1;
Parent1=new int[ChromosomeLength];
//Массив для хранения второго родителя
int *Parent2;
Parent2=new int[ChromosomeLength];
//Массив для хранения потомка от скрещивания двух родителей
int *Child;
Child=new int[ChromosomeLength];

//Инициализация начальной популяции
HML_RandomBinaryMatrix(Population,PopulationSize,ChromosomeLength);

//Вычислим значение целевой функции для каждого индивида
for (i=0;i<PopulationSize;i++)
 {
 //Копируем индивида во временного индивида, так как целевая функция работает с вектором, а не матрицей
 HML_MatrixToRow(Population,TempIndividual,i,ChromosomeLength);
 try
  {
  Fitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
  }
 catch(...)
  {
  return 0;//Генетический алгоритм не смог посчитать значение целевая функции индивида
  }
 }

//Определим наилучшего индивида и запомним его
NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(Fitness,PopulationSize);
MaximumFitness=HML_MaximumOfVector(Fitness,PopulationSize);
HML_MatrixToRow(Population,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
BestFitness=MaximumFitness;//Запоминаем его значение целевой функции

for (I=1;I<NumberOfGenerations;I++)
 {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

 //Подготовка массивов для оператора селекции
 if (TypeOfSel==1)
  {
  //Для ранговой селекции нужен массив рангов индивидов
  HML_MakeVectorOfRankForRankSelection(Fitness,Rank,PopulationSize);
  //Для ранговой селекции нужен массив вероятностей выбора индивидов из рангов
  HML_MakeVectorOfProbabilityForRanklSelection(Rank,VectorOfProbability,PopulationSize);
  }
 if (TypeOfSel==0)//Для пропорциональной нужен массив вероятностей выбора индивидов
  HML_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorOfProbability,PopulationSize);

 for (j=0;j<PopulationSize;j++)
  {//Формирование популяции потомков
  if (TypeOfSel==0)//Пропорциональная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==1)//Ранговая селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_RankSelection(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_RankSelection(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==2)//Турнирная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   NumberOfParent2=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   }

  //Копируем родителей из популяции
  HML_MatrixToRow(Population,Parent1,NumberOfParent1,ChromosomeLength);//Первого родителя
  HML_MatrixToRow(Population,Parent2,NumberOfParent2,ChromosomeLength);//Второго родителя

  //Теперь путем скрещивания получаем потомка
  if (TypeOfCros==0)//Одноточечное скрещивание
   HML_SinglepointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==1)//Двухточечное скрещивание
   HML_TwopointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==2)//Равномерное скрещивание
   HML_UniformCrossover(Parent1,Parent2,Child,ChromosomeLength);

  //Переместим потомка в массив потомков
  HML_RowToMatrix(ChildrenPopulation,Child,j,ChromosomeLength);
  }//Формирование популяции потомков

 //Мутируем получившуюся популяцию потомков
 //Но вначале определим вероятность мутации
 if (TypeOfMutation==0)//Слабая
  ProbabilityOfMutation=1./(3.*double(ChromosomeLength));
 if (TypeOfMutation==1)//Средняя
  ProbabilityOfMutation=1./double(ChromosomeLength);
 if (TypeOfMutation==2)//Сильняя
  ProbabilityOfMutation=HML_Min(3./double(ChromosomeLength),1.);
 HML_MutationBinaryMatrix(ChildrenPopulation,ProbabilityOfMutation,PopulationSize,ChromosomeLength);//Мутируем

 //Вычислим значение целевой функции для каждого потомка
 for (i=0;i<PopulationSize;i++)
  {
  //Копируем потомка во временного индивида, так как целевой функция работает с вектором, а не матрицей
  HML_MatrixToRow(ChildrenPopulation,TempIndividual,i,ChromosomeLength);
  try
   {
   ChildrenFitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
   }
  catch(...)
   {
   return 0;//Генетический алгоритм не смог посчитать значение целевой функции потомка
   }
  }

 //Определим наилучшего потомка и запомним его
 MaximumFitness=HML_MaximumOfVector(ChildrenFitness,PopulationSize);

 //Является ли лучшее решение на данном поколении лучше лучшего решения за всё время работы алгоритма
 if (MaximumFitness>BestFitness)
  {
  //Если всё-таки лучше
  NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(ChildrenFitness,PopulationSize);
  HML_MatrixToRow(ChildrenPopulation,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
  BestFitness=MaximumFitness;//Запоминаем его значение целевой функции
  }

 //Теперь сформируем новое поколение
 if (TypeOfForm==0)//Только потомки
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  }
 if (TypeOfForm==1)//Только потомки и копия лучшего индивида
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_RowToMatrix(Population,BestIndividual,0,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  Fitness[0]=BestFitness;
  }

 }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

//Генетический алгоритм закончил свою работу
//Выдадим найденное лучшее решение за время запуска алгоритма и его значение целевой функции
HML_VectorToVector(BestIndividual,VHML_ResultVector,ChromosomeLength);
*VHML_Result=BestFitness;

//Удалим все дополнительные массивы
for (i=0;i<PopulationSize;i++) delete [] Population[i];
 delete [] Population;
for (i=0;i<PopulationSize;i++) delete [] ChildrenPopulation[i];
 delete [] ChildrenPopulation;
delete [] Fitness;
delete [] ChildrenFitness;
delete [] TempIndividual;
delete [] BestIndividual;
delete [] VectorOfProbability;
delete [] Rank;
delete [] Taken;
delete [] Parent1;
delete [] Parent2;
delete [] Child;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_StandartGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result)
{
/*
Стандартный генетический алгоритм для решения задач на бинарных строках. Реализация алгоритма из документа "Генетический алгоритм. Стандарт. v.3.0".
https://github.com/Harrix/Standard-Genetic-Algorithm
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина бинарной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида).
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (бинарный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=50;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
*/
int VHML_Success;//Успешен ли будет запуск cГА

VHML_Success=HML_StandartBinaryGeneticAlgorithm(Parameters, FitnessFunction, VHML_ResultVector, VHML_Result);

return VHML_Success;
}
//---------------------------------------------------------------------------
int HML_StandartGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result)
{
/*
Стандартный генетический алгоритм на вещественных строках.
Реализация алгоритма из документа "Генетический алгоритм. Стандарт. v.3.0".
https://github.com/Harrix/Standard-Genetic-Algorithm
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина вещественной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида)
  [6] - тип преобразования задачи вещественной оптимизации в задачу бинарной оптимизации (TypOfConverting);
        0 - IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации);
        1 - GrayСodeConverting (Стандартный рефлексивный Грей-код).
 NumberOfParts - указатель на массив: на сколько частей делить каждую вещественную координату при дискретизации (размерность Parameters[0]);
  Желательно брать по формуле NumberOfParts[i]=(2^k)-1, где k - натуральное число, например, 12.
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (вещественный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=2;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0;
*/
int VHML_Success;//Успешен ли будет запуск cГА

VHML_Success=HML_StandartRealGeneticAlgorithm(Parameters, NumberOfParts, Left, Right, FitnessFunction, VHML_ResultVector, VHML_Result);

return VHML_Success;
}
//---------------------------------------------------------------------------

int HML_StandartRealGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result)
{
/*
Стандартный генетический алгоритм для решения задач на вещественных строках.
Реализация алгоритма из документа "Генетический алгоритм. Стандарт. v.3.0".
https://github.com/Harrix/Standard-Genetic-Algorithm
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина вещественной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида)
  [6] - тип преобразования задачи вещественной оптимизации в задачу бинарной оптимизации (TypeOfConverting);
        0 - IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации);
        1 - GrayСodeConverting (Стандартный рефлексивный Грей-код).
 NumberOfParts - указатель на массив: на сколько частей делить каждую вещественную координату при дискретизации (размерность Parameters[0]);
  Желательно брать по формуле NumberOfParts[i]=(2^k)-1, где k - натуральное число, например, 12.
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (вещественный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=2;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0;
*/
//Переменные
int i;//Счетчик
int ChromosomeLength;//Длина бинарной строки
int VHML_Success;//Успешен ли будет запуск cГА на бинарных строках

//Считываем из Parameters необходимые параметры алгоритма
int RealLength=Parameters[0];//Размерность вещественного вектора
int TypOfConverting=Parameters[6];//Тип преобразования задачи в бинарную задачу оптимизацию

//Проверим данные
for (i=0;i<RealLength;i++) if (Left[i]>Right[i]) return 0;//Левая граница не может быть больше правой
for (i=0;i<RealLength;i++) if (NumberOfParts[i]<1) return 0;//На слишком мало частей предложено делить каждую координату
if (!((TypOfConverting==0)||(TypOfConverting==1))) return 0;//Тип преобразования указан не верно

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Массив значений, сколько бит приходится в бинарной хромосоме на кодирование
//каждой вещественной координаты
int *Lengthi;
Lengthi=new int[RealLength];
//Параметры стандартного генетического алгоритма на бинарных строках
int *ParametersOfStandartBinaryGeneticAlgorithm;
//Указатель на массив, в который записываются решения при вычислении целевой функции
double *RealVector;
RealVector=new double[RealLength];

//Процесс преобразования задачи вещественной оптимизации в задачу бинарной оптимизации
//Определим длину бинарной хромосомы. При этом число точек для кодирования на одну больше, чем интервалов,
//на которые мы хотим разбить каждую вещественную координату.
for (int i=0;i<RealLength;i++)
 Lengthi[i]=HML_HowManyPowersOfTwo(NumberOfParts[i]+1);

ChromosomeLength=HML_SumVector(Lengthi,RealLength);//Просуммируем элементы вектора

//Бинарное решение бинарной задачи оптимизации
int *BinaryDecision;
BinaryDecision=new int[ChromosomeLength];

//Создадим еще один массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную
int *TempBinaryVector;
TempBinaryVector=new int[ChromosomeLength];//GrayСodeConverting (Стандартный рефлексивный Грей-код)

//Определим параметры стандартного генетического алгоритма на бинарных строках
ParametersOfStandartBinaryGeneticAlgorithm=new int[6];
ParametersOfStandartBinaryGeneticAlgorithm[0]=ChromosomeLength;//Длина хромосомы
ParametersOfStandartBinaryGeneticAlgorithm[1]=Parameters[1];//Число вычислений целевой функции
ParametersOfStandartBinaryGeneticAlgorithm[2]=Parameters[2];//Тип селекции
ParametersOfStandartBinaryGeneticAlgorithm[3]=Parameters[3];//Тип скрещивания
ParametersOfStandartBinaryGeneticAlgorithm[4]=Parameters[4];//Тип мутации
ParametersOfStandartBinaryGeneticAlgorithm[5]=Parameters[5];//Тип формирования нового поколения

//сГА на бинарных строках работает с функцией типа double (*)(int*,int)
//то есть в качестве входных параметров только решение и его размерность
//но для вычисления значения целевой функции еще требуются дополнительные переменные
//целевая функция для вещественного решения и так далее.
//Делаем их доступными, используя служебные дополнительные указатели библиотеки
VHML_TempFunction=FitnessFunction;//указатель на целевая функция для вещественного решения
VHML_TempInt1=Lengthi;//указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование
VHML_TempDouble1=Left;//указатель на массив левых границ изменения вещественной переменной
VHML_TempDouble2=Right;//указатель на массив правых границ изменения вещественной переменной
VHML_TempDouble3=RealVector;//указатель на массив, в котором можно сохранить вещественный индивид
//при его раскодировании из бинарной строки
VHML_TempInt2=&RealLength;//указатель на размерность вещественного вектора
VHML_TempInt3=&TypOfConverting;//указатель на тип преобразования
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=TempBinaryVector;//массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную

//Выполнение стандартного генетического алгоритма на бинарных строках
try
 {
 //Выполнение стандартного генетического алгоритма на бинарных строках
 VHML_Success=HML_StandartBinaryGeneticAlgorithm(ParametersOfStandartBinaryGeneticAlgorithm,HML_BinaryFitnessFunction,BinaryDecision,VHML_Result);
 }
catch(...)
 {
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками
 }

if (VHML_Success==1)
 {
 //VHML_Result уже записан и определен, а вот VHML_ResultVector (конечное решение) еще нет
 //так как есть только бинарное решение, а не вещественное, которое нам и нужно

 //Преобразование бинарного решения в вещественное
 if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
  HML_BinaryVectorToRealVector(BinaryDecision,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
  HML_BinaryGrayVectorToRealVector(BinaryDecision,ChromosomeLength,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 }
else
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками, но не в результате генерирования исключений

//Удалим массивы для запуска стандартного генетического алгоритма на бинарных строках
delete [] ParametersOfStandartBinaryGeneticAlgorithm;
delete [] Lengthi;
delete [] BinaryDecision;
delete [] RealVector;
delete [] TempBinaryVector;

//Обнулим дополнительные указатели
VHML_TempFunction=NULL;
VHML_TempInt1=NULL;
VHML_TempDouble1=NULL;
VHML_TempDouble2=NULL;
VHML_TempInt2=NULL;
VHML_TempDouble3=NULL;
VHML_TempInt3=NULL;
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=NULL;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_TournamentSelection(double *Fitness, int SizeTournament, int VHML_N)
{
/*
Турнирная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов.
Входные параметры:
 Fitness - массив пригодностей индивидов;
 SizeTournament - размер турнира;
 VHML_N - размер массива.
Возвращаемое значение:
 Номер выбранного индивида популяции.
Примечание:
 Является стандартной реализацией турнирной селекции. Это турнирная селекция без возвращения.
*/
if (SizeTournament<2) SizeTournament=2;
if (SizeTournament>VHML_N) SizeTournament=VHML_N;

int j;//Счетчик
int p;//Текущее число свободнных участников
int r;//случайное число для определения победителя
int g=0;//Номер выбранного участника

int *Taken;//Информация о том, в турнире или нет индивид
Taken=new int[VHML_N];
HML_ZeroVector(Taken,VHML_N);// Пока никого

int VHML_Result;//победитель (номер) для турнирной селекции
VHML_Result=HML_RandomUniformInt(0,VHML_N);//первый участник
Taken[VHML_Result]=1;//отметили первого участника

for (int i=1;i<SizeTournament;i++)
 {//выбор еще одного участника турнира
 r=HML_RandomUniformInt(0,VHML_N-i);//на один меньше можно выбрать, чем в предыдущий раз
 p=0;//Текущее число свободнных участников
 j=0;//Счетчик

 while (p!=r+1)
  {
  //Ищем нашего участника
  if (Taken[j]==0)
   {
   //Нашли свободного участника. Возможно это наш.
   p++;
   g=j;
   }
  j++;
  }

 //Теперь g - номер нашего участника
 Taken[g]=1;//Отметим

 // Выйграл ли новый участник лучшего представителя турнира
 if (Fitness[g]>Fitness[VHML_Result]) VHML_Result=g;
 }//выбор еще одного участника турнира

delete [] Taken;

return VHML_Result;
}
//---------------------------------------------------------------------------
int HML_TournamentSelection(double *Fitness, int SizeTournament, int *Taken, int VHML_N)
{
/*
Турнирная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов.
Входные параметры:
 Fitness - массив пригодностей индивидов;
 SizeTournament - размер турнира
 Taken - Информация о том, в турнире или нет индивид (служебный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Номер выбранного индивида популяции.
Примечание:
 Является стандартной реализацией турнирной селекции. Это турнирная селекция без возвращения.
Примечание:
 В работе функции используется вспомогательный массив Taken. Так как функция вызывается часто, то
каждый раз создавать массив затратно. Поэтому можно в перегруженной функции передать этот массив
в качестве параметра.
*/
if (SizeTournament<2) SizeTournament=2;
if (SizeTournament>VHML_N) SizeTournament=VHML_N;

int j;//Счетчик
int p;//Текущее число свободнных участников
int r;//случайное число для определения победителя
int g=0;//Номер выбранного участника

HML_ZeroVector(Taken,VHML_N);// Пока никого

int VHML_Result;//победитель (номер) для турнирной селекции
VHML_Result=HML_RandomUniformInt(0,VHML_N);//первый участник
Taken[VHML_Result]=1;//отметили первого участника

for (int i=1;i<SizeTournament;i++)
 {//выбор еще одного участника турнира
 r=HML_RandomUniformInt(0,VHML_N-i);//на один меньше можно выбрать, чем в предыдущий раз
 p=0;//Текущее число свободнных участников
 j=0;//Счетчик

 while (p!=r+1)
  {
  //Ищем нашего участника
  if (Taken[j]==0)
   {
   //Нашли свободного участника. Возможно это наш.
   p++;
   g=j;
   }
  j++;
  }

 //Теперь g - номер нашего участника
 Taken[g]=1;//Отметим

 // Выйграл ли новый участник лучшего представителя турнира
 if (Fitness[g]>Fitness[VHML_Result]) VHML_Result=g;
 }//выбор еще одного участника турнира

return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_TournamentSelectionWithReturn(double *Fitness, int SizeTournament, int VHML_N)
{
/*
Турнирная селекция с возвращением. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов.
Входные параметры:
 Fitness - массив пригодностей индивидов;
 VHML_N - размер массива VectorProbability;
 SizeTournament - размер турнира.
Возвращаемое значение:
 Номер выбранного индивида популяции.
Примечание:
 Не является стандартной реализацией турнирной селекции, так как в классичсекой турнирной селекции
в один турнир один и тот же индивид может попасть только один раз.
*/
if (SizeTournament<2) SizeTournament=2;
if (SizeTournament>VHML_N) SizeTournament=VHML_N;
int VHML_Result;//победитель (номер) для турнирной селекции
int r; //случайное число для определения победителя

//турнирная  селекция с возвращением.
VHML_Result=HML_RandomUniformInt(0,VHML_N);//первый участник

for (int i=1;i<SizeTournament;i++)
 {//выбор еще одного участника турнира
 r=HML_RandomUniformInt(0,VHML_N);
 if (Fitness[r]>Fitness[VHML_Result]) VHML_Result=r;
 }//выбор еще одного участника турнира

return VHML_Result;
}
//---------------------------------------------------------------------------

void HML_TwopointCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Двухточечное скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
HML_TwopointCrossover(Parent1, Parent2, VHML_ResultVector, VHML_N);
}
//---------------------------------------------------------------------------

void HML_UniformCrossoverForReal(double*Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Равномерное скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
HML_UniformCrossover(Parent1, Parent2, VHML_ResultVector, VHML_N);
}
//---------------------------------------------------------------------------


//*****************************************************************
//Геометрия
//*****************************************************************
double HML_LineGeneralForm(double x, double A, double B, double C, int *solutionis)
{
/*
Функция представляет собой уравнение прямой по общему уравнению прямой вида Ax+By+C=0.
Возвращается значение y для x.
Входные параметры:
 x - значение точки для которой считаем значение прямой;
 A - множитель из уравнения прямой Ax+By+C=0;
 B - множитель из уравнения прямой Ax+By+C=0;
 C - слагаемое из уравнения прямой Ax+By+C=0;
 solutionis - сюда возвращается результат решения задачи:
  0 - решений нет;
  1 - решение есть;
  2 - любое число является решением (прямая параллельна оси Oy)
Возвращаемое значение:
 Значение y прямой для данного x.
*/
    double y=0;
    if (B!=0)
    {
        if (A!=0)
        {
            y=(-A/B)*x-C/B;//обычное уравнение прямой
        }
        else
        {//A==0 B!=0 уравнение вида By+C=0
            y=-C/B;//прямая параллельная Ox
        }
    }
    else
    {//в уравнении y не участвует: уравнение вида Ax+C=0
        if (A!=0)
        {
            if (x==-C/A)
            {
                y=0;
                *solutionis=2;//решением является любое число. Это прямая паралельна Oy  и у нас задан правильный x
            }
            else
            {
                y=0;
                *solutionis=0;//решений нет
            }
        }
        else
        { //уравнение типа С=0 тут вообще нет ни x, но y
            y=0;
            *solutionis=0;//решений нет
        }
    }

    *solutionis=1;
    return y;
}
//---------------------------------------------------------------------------
double HML_LineGeneralForm(double x, double A, double B, double C)
{
/*
Функция представляет собой уравнение прямой по общему уравнению прямой вида Ax+By+C=0.
Возвращается значение y для x.
Входные параметры:
 x - значение точки для которой считаем значение прямой;
 A - множитель из уравнения прямой Ax+By+C=0;
 B - множитель из уравнения прямой Ax+By+C=0;
 C - слагаемое из уравнения прямой Ax+By+C=0.
Возвращаемое значение:
 Значение y прямой для данного x.
*/
    double y=0;
    int solutionis;
    y=HML_LineGeneralForm(x, A, B, C, &solutionis);
    return y;
}
//---------------------------------------------------------------------------

double HML_LineSlopeInterceptForm(double x, double k, double b)
{
/*
Функция представляет собой уравнение прямой с угловым коэффициентом вида y=kx+b.
Возвращается значение y для x.
Входные параметры:
 x - значение точки для которой считаем значение прямой;
 k - угловой коэффициент из уравнения прямой y=kx+b;
 b - слагаемое из уравнения прямой y=kx+b;
Возвращаемое значение:
 Значение y прямой для данного x.
*/
    double y=0;

    y=k*x+b;

    return y;
}
//---------------------------------------------------------------------------

double HML_LineTwoPoint(double x, double x1, double y1, double x2, double y2, int *solutionis)
{
/*
Функция представляет собой уравнение прямой по двум точкам.
Возвращается значение y для x.
Входные параметры:
 x - значение точки для которой считаем значение прямой;
 x1 - абцисса первой точки;
 y1 - ордината первой точки;
 x2 - абцисса второй точки;
 y2 - ордината второй точки;
 solutionis - сюда возвращается результат решения задачи:
  0 - решения нет;
  1 - решение есть;
  2 - любое число является решением (прямая параллельна оси Oy).
Возвращаемое значение:
 Значение y прямой для данного x.
*/
double y=0;

if ((x1==x2)&&(y1==y2))
{
    //это одна и та же точка, так что выдадим любое решение
    y=y1;
    *solutionis=2;
}
else
{
    if (y1==y2)
    {
     // это прямая параллельна оси Ox
        y=y1;
        *solutionis=1;
    }
    else
    {
        if (x1==x2)
        {
            //это прямая параллельная оси Oy
            if (x==x1)
            {
                y=y1;
                *solutionis=2;
            }
            else
            {
                y=0;
                *solutionis=0;
            }
        }
        else
        {
            y=(x-x1)*(y2-y1)/(x2-x1)+y1;
        }
    }
}

*solutionis=1;
return y;
}
//---------------------------------------------------------------------------
double HML_LineTwoPoint(double x, double x1, double y1, double x2, double y2)
{
/*
Функция представляет собой уравнение прямой по двум точкам.
Возвращается значение y для x.
Входные параметры:
 x - значение точки для которой считаем значение прямой;
 x1 - абцисса первой точки;
 y1 - ордината первой точки;
 x2 - абцисса второй точки;
 y2 - ордината второй точки.
Возвращаемое значение:
 Значение y прямой для данного x.
*/
double y=0;

int solutionis;

y=HML_LineTwoPoint(x, x1, y1, x2, y2, &solutionis);

return y;
}
//---------------------------------------------------------------------------

double HML_Parabola(double x, double a, double b, double c)
{
/*
Функция представляет собой уравнение параболы вида: y=ax^2+bx+c.
Возвращается значение y для x.
Входные параметры:
 x - значение точки для которой считаем значение параболы;
 a - множитель из уравнения y=ax^2+bx+c;
 b - множитель из уравнения y=ax^2+bx+c;
 c - слагаемое из уравнения y=ax^2+bx+c.
Возвращаемое значение:
 Значение y параболы для данного x.
*/
    double y=0;

    y=a*x*x+b*x+c;

    return y;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Гиперболические функции
//*****************************************************************
double HML_Cosech(double x)
{
/*
Функция возвращает гиперболический косеканс.
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Гиперболический косеканс.
*/
return 2./(exp(x)-exp(-x));
}
//---------------------------------------------------------------------------

double HML_Cosh(double x)
{
/*
Функция возвращает гиперболический косинус.
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Гиперболический косинус.
*/
return (exp(x)+exp(-x))/2.;
}
//---------------------------------------------------------------------------

double HML_Cotanh(double x)
{
/*
Функция возвращает гиперболический котангенс.
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Гиперболический котангенс.
*/
return (exp(x)+exp(-x))/(exp(x)-exp(-x));
}
//---------------------------------------------------------------------------

double HML_Sech(double x)
{
/*
Функция возвращает гиперболический секанс.
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Гиперболический секанс.
*/
return 2./(exp(x)+exp(-x));
}
//---------------------------------------------------------------------------

double HML_Sinh(double x)
{
/*
Функция возвращает гиперболический синус.
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Гиперболический синус.
*/
return (exp(x)-exp(-x))/2.;
}
//---------------------------------------------------------------------------

double HML_Tanh(double x)
{
/*
Функция возвращает гиперболический тангенс.
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Гиперболический тангенс.
*/
return (exp(x)-exp(-x))/(exp(x)+exp(-x));
}

//---------------------------------------------------------------------------


//*****************************************************************
//Дифференцирование
//*****************************************************************
double HML_CenterDerivative(double x, double h, double (*Function)(double))
{
/*
Численное значение производной в точке (центральной разностной производной с шагом 2h).
Входные параметры:
 x - точка, в которой считается производная;
 h - малое приращение x;
 Function - функция, производная которой ищется.
Возвращаемое значение:
 Значение производной в точке.
Примечание:
 При h<=0 возвращается 0.
*/
if (h<=0) return 0;

return ((Function(x+h)-Function(x-h))/(2*h));
}
//---------------------------------------------------------------------------

double HML_LeftDerivative(double x, double h, double (*Function)(double))
{
/*
Численное значение производной в точке (разностная производная влево).
Входные параметры:
 x - точка, в которой считается производная;
 h - малое приращение x;
 Function - функция, производная которой ищется.
Возвращаемое значение:
 Значение производной в точке.
Примечание:
 При h<=0 возвращается 0.
*/
if (h<=0) return 0;

return ((Function(x)-Function(x-h))/h);
}
//---------------------------------------------------------------------------

double HML_RightDerivative(double x, double h, double (*Function)(double))
{
/*
Численное значение производной в точке (разностная производная вправо).
Входные параметры:
 x - точка, в которой считается производная;
 h - малое приращение x;
 Function - функция, производная которой ищется.
Возвращаемое значение:
 Значение производной в точке.
Примечание:
 При h<=0 возвращается 0.
*/
if (h<=0) return 0;

return ((Function(x+h)-Function(x))/h);
}
//---------------------------------------------------------------------------


//*****************************************************************
//Интегрирование
//*****************************************************************
double HML_IntegralOfRectangle(double a, double b, double Epsilon,double (*Function)(double))
{
/*
Интегрирование по формуле прямоугольников с оценкой точности по правилу Рунге.
Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.
Входные параметры:
 a - начало отрезка интегрирования;
 b - конец отрезка интегрирования;
 Epsilon - погрешность;
 Function - подынтегральная функция.
Возвращаемое значение:
 Значение определенного интеграла.
Примечание: значимые цифры в ответе определяются Epsilon.
*/
int i,n;
double h, s1, VHML_Result;
n=1;
h=b-a;
VHML_Result=h*Function((a+b)/2.);
do
 {
 n=2*n;
 s1=VHML_Result;
 h=h/2.;
 VHML_Result=0;
 i=1;
 do
  {
  VHML_Result=VHML_Result+Function(a+h/2.+h*(i-1.));//вычисляем интегральную сумму
  i=i+1;
  }
 while (i<=n);
 VHML_Result=VHML_Result*h;
 }
while (fabs(VHML_Result-s1)>3.*Epsilon);
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_IntegralOfSimpson(double a, double b, double Epsilon,double (*Function)(double))
{
/*
Интегрирование по формуле Симпсона с оценкой точности по правилу Рунге.
Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.
Входные параметры:
 a - начало отрезка интегрирования;
 b - конец отрезка интегрирования;
 Epsilon - погрешность;
 Function - подынтегральная функция.
Возвращаемое значение:
 Значение определенного интеграла.
Примечание: значимые цифры в ответе определяются Epsilon.
*/
double h,s,s1,VHML_Result,s3,x;
VHML_Result=1.;
h=b-a;
s=Function(a)+Function(b);
do
 {
 s3=VHML_Result;
 h=h/2.;
 s1=0;
 x=a+h;
 do
  {
  s1=s1+2.*Function(x);
  x=x+2.*h;
  }
 while (x<b);
 s=s+s1;
 VHML_Result=(s+s1)*h/3.;
 x=fabs(s3-VHML_Result)/15.;
}
while (x>Epsilon);
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_IntegralOfTrapezium(double a, double b, double Epsilon,double (*Function)(double))
{
/*
Интегрирование по формуле трапеции с оценкой точности по правилу Рунге.
Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.
Входные параметры:
 a - начало отрезка интегрирования;
 b - конец отрезка интегрирования;
 Epsilon - погрешность;
 Function - подынтегральная функция.
Возвращаемое значение:
 Значение определенного интеграла.
Примечание: значимые цифры в ответе определяются Epsilon.
*/
int i,n;
double h, s1, VHML_Result;
n=1;
h=b-a;
VHML_Result=h*(Function(a)+Function(b))/2.;
do
 {
 s1=VHML_Result;
 VHML_Result=0;
 i=1;
 do
  {
  VHML_Result=VHML_Result+Function(a-h/2.+h*i);//вычисляем интегральную сумму
  i=i+1;
  }
 while (i<=n);
 VHML_Result=s1/2.+VHML_Result*h/2.;
 n=2*n;
 h=h/2.;
 }
while (fabs(VHML_Result-s1)>3.*Epsilon);
return VHML_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Кодирование и декодирование
//*****************************************************************
void HML_BinaryGrayVectorToRealVector(int *x, int n, double *VHML_ResultVector, double *Left, double *Right, int *Lengthi, int VHML_N)
{
/*
Функция декодирует бинарную строку в действительный вектор, который и был закодирован
методом "Стандартный рефлексивный Грей-код" (без использования временного массива).
Входные параметры:
 a - бинарная строка представляющая собой Грей-код нескольких закодированных вещественных координат;
 n - длина бинарной строки;
 VHML_ResultVector - вещественный вектор, в который мы и записываем результат, размера n;
 Left - массив левых границ изменения каждой вещественной координаты (размер VHML_N);
 Right - массив правых границ изменения каждой вещественной координаты (размер VHML_N);
 Lengthi - массив значений, сколько на каждую координату отводится бит в бинарной строке (размер массива Lengthi VHML_N);
 VHML_N - длина вещественного вектора.
Возвращаемое значение:
 Отсутствует.
Примечание:
 К криптографии данная функция не имеет отношения.
*/
int len;//Сколько на текущую координату отводится бит в бинарной строке
int Begin=0;//Номер бита в бинарной строке, с которой начинается текущая закодированная вещественная координата
int *TempBinaryVector;
TempBinaryVector=new int[n];

//Вначале нужно перевести бинарную строку кода Грея в бинарную строку
for (int i=0;i<VHML_N;i++)
 {
 len=Lengthi[i];
 HML_GrayCodeToBinaryFromPart(x,TempBinaryVector,Begin,len);
 Begin+=len;
 }

//Переводим наш полученный бинарный код в вещественный вектор
HML_BinaryVectorToRealVector(TempBinaryVector,VHML_ResultVector,Left,Right,Lengthi,VHML_N);

delete [] TempBinaryVector;
}
//---------------------------------------------------------------------------
void HML_BinaryGrayVectorToRealVector(int *x, double *VHML_ResultVector,int *TempBinaryVector, double *Left, double *Right, int *Lengthi, int VHML_N)
{
/*
Функция декодирует бинарную строку в действительный вектор, который и был закодирован
методом "Стандартный рефлексивный Грей-код".
Входные параметры:
 a - бинарная строка представляющая собой Грей-код нескольких закодированных вещественных координат;
 VHML_ResultVector - вещественный вектор, в который мы и записываем результат;
 TempBinaryVector - указатель на временный массив  размера n;
 Left - массив левых границ изменения каждой вещественной координаты размера VHML_N;
 Right - массив правых границ изменения каждой вещественной координаты размера VHML_N;
 Lengthi - массив значений, сколько на каждую координату отводится бит в бинарной строке. Размер массива VHML_N;
 VHML_N - длина вещественного вектора.
Возвращаемое значение:
 Отсутствует.
Примечание:
 К криптографии данная функция не имеет отношения.
*/
int len;//Сколько на текущую координату отводится бит в бинарной строке
int Begin=0;//Номер бита в бинарной строке, с которой начинается текущая закодированная вещественная координата

//Вначале нужно перевести бинарную строку кода Грея в бинарную строку
for (int i=0;i<VHML_N;i++)
 {
 len=Lengthi[i];
 HML_GrayCodeToBinaryFromPart(x,TempBinaryVector,Begin,len);
 Begin+=len;
 }

//Переводим наш полученный бинарный код в вещественный вектор
HML_BinaryVectorToRealVector(TempBinaryVector,VHML_ResultVector,Left,Right,Lengthi,VHML_N);
}
//---------------------------------------------------------------------------

void HML_BinaryVectorToRealVector(int *x, double *VHML_ResultVector, double *Left, double *Right, int *Lengthi, int VHML_N)
{
/*
Функция декодирует бинарную строку в действительный вектор, который и был закодирован
методом "Стандартное представление целого числа – номер узла в сетке дискретизации".
Входные параметры:
 a - бинарная строка;
 VHML_ResultVector - вещественный вектор, в который мы и записываем результат;
 Left - массив левых границ изменения каждой вещественной координаты;
 Right - массив правых границ изменения каждой вещественной координаты;
 Lengthi - массив значений, сколько на каждую координату отводится бит в бинарной строке;
 VHML_N - длина вещественного вектора.
Возвращаемое значение:
 Отсутствует.
Примечание:
 К криптографии данная функция не имеет отношения.
Примечание:
 Вектор входный параметров действительно избыточен, но каждый раз пересчитывать затратно, так как функция вызывается в ГА часто.
*/
int len;//Сколько на текущую координату отводится бит в бинарной строке
double l;//Левая граница текущей координаты вещественного вектора
double r;//Правая граница текущей координаты вещественного вектора
double count;//Сколько может быть закодировано целых чисел двоичным числом длины len
int Begin=0;//Номер бита в бинарной строке, с которой начинается текущая закодированная вещественная координата

for (int i=0;i<VHML_N;i++)
 {
 len=Lengthi[i];
 count=double(HML_PowerOf(2,len));
 l=Left[i];
 r=Right[i];
 VHML_ResultVector[i]=l+(r-l)*double(HML_BinaryToDecimalFromPart(x,Begin,len))/count;
 Begin+=len;
 }
}
//---------------------------------------------------------------------------


//*****************************************************************
//Комбинаторика
//*****************************************************************

//*****************************************************************
//Математические функции
//*****************************************************************
double HML_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything()
{
/*
Функция возвращает ответ на главный вопрос жизни, вселенной и всего такого.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Ответ на главный вопрос жизни, вселенной и всего такого.
*/
return 42.;
}
//---------------------------------------------------------------------------

double HML_ArithmeticalProgression(double a1,double d,int n)
{
/*
Арифметическая прогрессия. n-ый член последовательности.
Входные параметры:
 a1 - начальный член прогрессии;
 d - шаг арифметической прогрессии;
 n - номер последнего члена.
Возвращаемое значение:
 n-ый член последовательности.
*/
double VHML_Result=a1+d*(n-1.);
return  VHML_Result;
}
//---------------------------------------------------------------------------

double HML_ExpMSxD2(double x)
{
/*
Функция вычисляет выражение exp(-x*x/2).
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
return exp(-x*x/2.);
}
//---------------------------------------------------------------------------

double HML_GeometricSeries(double u1,double q,int n)
{
/*
Геометрическая прогрессия. n-ый член последовательности.
Входные параметры:
 u1 - начальный член прогрессии;
 q - шаг  прогрессии;
 n - номер последнего члена.
Возвращаемое значение:
 n-ый член последовательности.
*/
double qn1;
qn1=HML_PowerOf(q,n-1);
double VHML_Result=u1*qn1;
return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_GreatestCommonDivisorEuclid(int A,int B)
{
/*
Функция находит наибольший общий делитель двух чисел по алгоритму Евклида.
Входные параметры:
 A - первое число;
 B - второе число.
Возвращаемое значение:
 НОД(A,B)
*/
int a,b;
//A должен быть не меньше B
if (A>=B)
 {
 a=abs(A);
 b=abs(B);
 }
else
 {
 a=abs(B);
 b=abs(A);
 }
while((a!=0)&&(b!=0))
 {
 if (a>=b)
  a=a%b;
 else
  b=b%a;
 }
int VHML_Result=a+b;
return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_HowManyPowersOfTwo(int x)
{
/*
Функция вычисляет, какой минимальной степенью двойки можно покрыть целое положительное число.
Входные параметры:
 x - целое число.
Возвращаемое значение:
 Минимальная степень двойки можно покрыть целое положительное число: min(2^VHML_Result)>x
*/
x=abs(x);
double m=1;
int VHML_Result=0;
while (m<x)
 {
 m*=2;
 VHML_Result++;
 }
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_InverseNormalizationNumberAll(double x)
{
/*
Функция осуществляет обратную нормировку числа из интервала [0;1]  в интервал [-бесконечность;+бесконечность],
которое было осуществлено функцией HML_NormalizationNumberAll.
Под бесконечностью принимается машинная бесконечность.
Входные параметры:
 x - число в интервале [0;1].
Возвращаемое значение:
 Перенормированное число.
*/
if (x==0.5)
 return 0.;
if (x>=1)
 return HML_INFINITY;
if (x<=0)
 return HML_MINFINITY;
if (x>0.5)
 return (1./((1./(2.*x-1.))-1.));
else
 return (1./(1.-(1./(1.-2.*x))));
}
//---------------------------------------------------------------------------

int HML_LeastCommonMultipleEuclid(int A,int B)
{
/*
Функция находит наименьшее общее кратное двух чисел по алгоритму Евклида.
Входные параметры:
 A - первое число;
 B - второе число.
Возвращаемое значение:
 НОК(A,B)
*/
A=abs(A);
B=abs(B);
int gcd,VHML_Result;
//НОК вычисляем на основе НОД
gcd=HML_GreatestCommonDivisorEuclid(A,B);
VHML_Result=(A*B)/gcd;
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_MeaningOfLife()
{
/*
Функция возвращает смысл жизни.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Смысл жизни.
*/
return 42.;
}
//---------------------------------------------------------------------------

void HML_MixedMultiLogicVectorOfFullSearch(int *VHML_Vector, int I, int *HowMuchInElements, int VHML_N)
{
/*
Функция генерирует определенный вектор k-значной логики, где каждый элемент может
принимать разное максимальное значение, в полном переборе вариантов.
Генерируется I вектор в этом полном переборе.
Входные параметры:
 VHML_Vector - выходной вектор, в который записывается результат;
 I - номер в массиве в полном переборе, начиная с нуля (от 0 и до произведения всех элементов массива HowMuchInElements - 1);
 HowMuchInElements - сколько значений может принимать элемент в векторе. То есть элемент может быть 0 и HowMuchInElements[i] - 1;
 VHML_N - количество элементов в массиве.
Возвращаемое значение:
 Отсутствует.
*/
    int *CountInBlock = new int[VHML_N];

    int CountOfAllVariants = HML_ProductOfElementsOfVector(HowMuchInElements, VHML_N);

    CountInBlock[0] = CountOfAllVariants/HowMuchInElements[0];

    for (int i=1;i<VHML_N;i++)
        CountInBlock[i] = CountInBlock[i-1]/HowMuchInElements[i];

    for (int i=0;i<VHML_N;i++)
        VHML_Vector[i] = (I/CountInBlock[i])%HowMuchInElements[i];

    delete [] CountInBlock;
}
//---------------------------------------------------------------------------

double HML_NormalizationNumberAll(double x)
{
/*
Функция нормирует число из интервала [бесконечность;+бесконечность] в интервал [0;1].
При этом в нуле возвращает 0.5, в -бесконечность возвращает 0, в +бесконечность
возвращает 1. Если x<y, то HML_NormalizationNumberAll(x)<HML_NormalizationNumberAll(y).
Под бесконечностью принимается машинная бесконечность.
Входные параметры:
 x - число.
Возвращаемое значение:
 Нормированное число.
*/
if (x==0) return 0.5;
if (x>=HML_INFINITY) return 1.;
if (x<=HML_MINFINITY) return 0.;
return ((1./(1.+1./fabs(x))*HML_Sign(x)+1.)/2.);
}
//---------------------------------------------------------------------------

int HML_Parity(int a)
{
/*
Функция проверяет четность целого числа.
Входные параметры:
 a - исходное число.
Возвращаемое значение:
 1 - четное;
 0 - нечетное.
*/
if (a%2==0)
 return 1;
else
 return 0;
}
//---------------------------------------------------------------------------

double HML_ProbabilityDensityFunctionOfInverseGaussianDistribution (double x, double mu, double lambda)
{
/*
Функция вычисляет плотность вероятности распределения обратного гауссовскому распределению.
Входные параметры:
 x - входная переменная (x>0);
 mu - первый параметр распределения;
 lambda - второй параметр распределения.
Возвращаемое значение:
 Значение функции в точке.
*/
    double VHML_Result=0;

    if ((mu>0)&&(x>0)&&(lambda>0))
    {
        VHML_Result = sqrt(lambda/(2.*HML_PI*x*x*x))*exp((-lambda*(x-mu)*(x-mu))/(2.*mu*mu*x));
    }

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_SumGeometricSeries(double u1,double q,int n)
{
/*
Геометрическая прогрессия. Сумма первых n членов.
Входные параметры:
 u1 - начальный член прогрессии;
 q - шаг  прогрессии;
 n - номер последнего члена.
Возвращаемое значение:
 Сумма первых n членов.
*/
double qn;
qn=HML_PowerOf(q,n);
double VHML_Result=u1*(1.-qn)/(1.-q);
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_SumOfArithmeticalProgression(double a1,double d,int n)
{
/*
Арифметическая прогрессия. Сумма первых n членов.
Входные параметры:
 a1 - начальный член прогрессии;
 d - шаг арифметической прогрессии;
 n - номер последнего члена.
Возвращаемое значение:
 Сумма первых n членов.
*/
double VHML_Result=(2.*a1+d*(n-1.))*n/2.;
return  VHML_Result;
}
//---------------------------------------------------------------------------

int HML_SumOfDigits(int a)
{
/*
Функция подсчитывает сумму цифр любого целого числа.
Входные параметры:
 a - целое число.
Возвращаемое значение:
 Cумма цифр.
*/
if (a<1) a=-a;
int VHML_Result=0;
while (a>=1)
 {
 VHML_Result+=a-int(int(a/10)*10.);
 a/=10;
 }
return VHML_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Матрицы
//*****************************************************************

//*****************************************************************
//Метрика
//*****************************************************************

//*****************************************************************
//Модели
//*****************************************************************
int HML_PendulumOfMaxwell(double *Data)
{
/*
Итерационная модель маятника Максвелла с затухающими колебаниями с управлением.
Вызов данной процедуры прогоняет только одну итерацию, то есть одно
наблюдение. Последующий вызов процедуры покажет положение маятника в следующий
момент времени. Самим параметры менять не надо при вызове следующей итерации,
так как процедура сама все поменяет (кроме, естественно, управляющего ускорения).
Входные параметры:
 Data - параметры маятника
  [0] - текущее положение маятника. Сюда запишется положение маятника на
  следующей итерации.
  [1] - текущая скорость маятника. Сюда запишется скорость маятника на
  следующей итерации.
  [2] - текущее значение управляющего ускорения. Если равно 0, то управления нет.
  [3] - Сюда запишется значение ускорения маятника на данной итерации.
  [4] - Сюда запишется, сколько на данной итерации произошло неупругих соударений.
  [5] - масса диска.
  [6] - масса оси.
  [7] - радиус диска.
  [8] - радиус оси.
  [9] - длина нити.
  [10] - коэффициент затухания.
  [11] - интервал наблюдений.
  [12] - минимальная амплитуда отскока в нижней точке. Критерий остановки.
Возвращаемое значение:
 1 - все хорошо
 0 - введены недопустимые данные
*/
//из массива данных определяем параметры маятника
    double x=Data[0];
    double v=Data[1];
    double w=Data[2];
    double m=Data[5];
    double maxis=Data[6];
    double R=Data[7];
    double r=Data[8];
    double l=Data[9];
    double k=Data[10];
    double dt=Data[11];
    double e=Data[12];
    //проверка данных
    if (x>l) return 0;
    if (x<R) return 0;
    if (m<=0) return 0;
    if (maxis<0) return 0;
    if (R<=0) return 0;
    if (r<=0) return 0;
    if (r>R) return 0;
    if (l<=R) return 0;
    if (k<0) return 0;
    if (k>=1.) return 0;
    if (dt<=0) return 0;
    if (e<0) return 0;
    //конец проверки данных
    try
    {
        double a,xnew,vnew,xpart,t1,t3,D1,D2;
        bool P1=true,P2=true;
        a=(m*r*r*(HML_G-w))/(0.5*(m*R*R+maxis*r*r)+(m+maxis)*r*r);//текущее ускорение
        if (((x==R)&&(v<0))||((x==l)&&(v>0))) v=-v*(1.-k);//если маятник находится в крайних точках,
        //скорость меняет свой знак
        int i=0,iv=0;
        while ((P1==true)||(P2==true))
        {
            //за промежуток времени маятник может совершить много колебаний. Они просчитываются все
            P1=true;
            P2=true;
            i++;
            //просчитываем, "долетит" маятник до крайних точек за оставшееся время
            D1=v*v-2*a*(x-l);
            D2=v*v-2*a*(x-R);
            if (D1<0) P1=false;
            if (D2<0) P2=false;
            if (P1==true)
            {
                if (a!=0)
                    t1=(-v+sqrt(D1))/a;
                else
                    if (v!=0)
                        t1=(l-x)/v;
                    else
                        t1=-1;
                if (!((t1>0)&&(t1<dt))) P1=false;
            }
            if (P2==true)
            {
                if (a!=0)
                    t3=(-v-sqrt(D2))/a;
                else
                    if (v!=0)
                        t3=(R-x)/v;
                    else
                        t3=-1;
                if (!((t3>0)&&(t3<dt))) P2=false;
            }
            if ((P1==true)&&(P2==false))
            {
                if (x==l)
                {
                    xpart=fabs(v*(t1/2.)+0.5*a*(t1/2.)*(t1/2.));
                    if (xpart<e) v=0;
                }
                x=l;
                v=v+a*t1;
                v=-v*(1.-k);
                dt=dt-t1;
            }
            if ((P2==true)&&(P1==false))
            {
                x=R;
                v=v+a*t3;
                v=-v*(1.-k);
                dt=dt-t3;
                iv++;
            }
        }
        xnew=x+v*dt+0.5*dt*dt*a;//новое положение маятника
        vnew=v+a*dt;//новая скорость маятника
        if ((xnew>l-e)&&(iv==0))//не остановился ли маятник
        {
            xnew=l;
            vnew=0.;
        }
        //проверка на всякий случай, чтобы маятник не улетел за границы дозволенного
        if (xnew<R) xnew=R;
        if (xnew>l) xnew=l;
        //обновляем входные данные массива
        Data[0]=xnew;
        Data[1]=vnew;
        Data[3]=a;
        Data[4]=i-1;
        //если всё прошло хорошо, то возвращается 1
        return 1;
    }
    catch(...)
    {
        //если что-то пошло не так, то возвращается 0
        return 0;
    }
}
//---------------------------------------------------------------------------


//*****************************************************************
//Непараметрика
//*****************************************************************
double HML_BellShapedKernelExp(double z)
{
/*
Колоколообразное экспоненциальное ядро.
Входные параметры:
 z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
z=fabs(z);
if (z<=2.47638181818)
    f=0.05968*(exp(z)+exp(-z))-0.154293*z*z+0.2311;
return f;
}
//---------------------------------------------------------------------------

double HML_BellShapedKernelParabola(double z)
{
/*
Колоколообразное параболическое ядро.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
if (z*z<=5)
    f=0.335-0.067*z*z;
return f;
}
//---------------------------------------------------------------------------

double HML_BellShapedKernelRectangle(double z)
{
/*
Колоколообразное прямоугольное ядро.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
z=fabs(z);
if (z<=1)
    f=0.5;
return f;
}
//---------------------------------------------------------------------------

double HML_BellShapedKernelTriangle(double z)
{
/*
Колоколообразное треугольное ядро.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
z=fabs(z);
if (z<=1)
    f=1.-z;
return f;
}
//---------------------------------------------------------------------------

double HML_DerivativeOfBellShapedKernelExp(double z)
{
/*
Производная колоколообразного экспоненциального ядра.
Входные параметры:
 z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
if (fabs(z)<=2.47638181818) f=0.05968*(exp(z)-exp(-z))-0.308586*z;
return f;
}
//---------------------------------------------------------------------------

double HML_DerivativeOfBellShapedKernelParabola(double z)
{
/*
Производная колоколообразного параболического ядра.
Входные параметры:
 z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
if (z*z<=5) f=-0.134*z;
return f;
}
//---------------------------------------------------------------------------

double HML_DerivativeOfBellShapedKernelRectangle(double z)
{
/*
Производная колоколообразного прямоугольного ядра.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
if (z==1) f=-1.7E308;
if (z==-1) f=1.7E308;
return f;
}
//---------------------------------------------------------------------------

double HML_DerivativeOfBellShapedKernelTriangle(double z)
{
/*
Производная колоколообразного треугольного ядра.
Входные параметры:
z - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
double f=0;
if ((z<=1)&&(z>=0)) f=-1.;
if ((z<0)&&(z>=-1)) f=1.;
return f;
}
//---------------------------------------------------------------------------

void HML_MakingVectorForNonparametricEstimatorOfDerivative3(double *VHML_ResultVector, double *X, double *Y, int VHML_N, double C, int V)
{
/*
Создание вектор непараметрической оценки производной в точках выборках. Служебная функция.
Нужна для функции HML_NonparametricEstimatorOfDerivative3.
Входные параметры:
 VHML_ResultVector - сюда сохраняется результат (количество элементов, как и в других векторах VHML_N);
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Отсутствует.
*/
    bool b2;
    for (int i=0;i<VHML_N;i++)
     {
     //непараметрическая оценка производной
     VHML_ResultVector[i]=HML_NonparametricEstimatorOfDerivative(X[i], X, Y, VHML_N, C, V, &b2);
     }
}
//---------------------------------------------------------------------------

void HML_MakingVectorForNonparametricEstimatorOfDerivative6(double *VHML_ResultVector, double *X, double *Y, int VHML_N, double C, int V)
{
/*
Создание вектор непараметрической оценки производной в точках выборках. Служебная функция.
Нужна для функции HML_NonparametricEstimatorOfDerivative6.
Входные параметры:
 VHML_ResultVector - сюда сохраняется результат (количество элементов, как и в других векторах VHML_N);
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Отсутствует.
*/
    bool b2;
    for (int i=0;i<VHML_N;i++)
     {
     //непараметрическая оценка производной
     VHML_ResultVector[i]=HML_NonparametricEstimatorOfDerivative5(X[i], X, Y, VHML_N, C, V, &b2);
     }
}
//---------------------------------------------------------------------------

double HML_NonparametricEstimatorOfDerivative(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное;
 b - сюда возвращается 1, если все прошло хорошо и 0, если C не захватывает никаких
 точек выборки (тогда функция возвращает 0).
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    if ((V!=0)&&(V!=1)&&(V!=2)&&(V!=3)) V=2;
    double (*F)(double);
    double (*dF)(double);
    //выбираем тип колоколообразного ядра
    if (V==0) F=HML_BellShapedKernelRectangle;
    if (V==1) F=HML_BellShapedKernelTriangle;
    if (V==2) F=HML_BellShapedKernelParabola;
    if (V==3) F=HML_BellShapedKernelExp;
    if (V==0) dF=HML_DerivativeOfBellShapedKernelRectangle;
    if (V==1) dF=HML_DerivativeOfBellShapedKernelTriangle;
    if (V==2) dF=HML_DerivativeOfBellShapedKernelParabola;
    if (V==3) dF=HML_DerivativeOfBellShapedKernelExp;

    double A=0,B=0,E=0,D=0;
    for (int i=0;i<VHML_N;i++)
    {
        A+=Y[i]*dF((x-X[i])/C);
        B+=F((x-X[i])/C);
        E+=dF((x-X[i])/C);
        D+=Y[i]*F((x-X[i])/C);
    }

    //так как по формуле происходит деление на коэффициент размытия, то он не должен равняться 0
    if ((C==0)||(B==0))
    {
        *b=false;
        return 0;
    }
    else
    {
        *b=true;
        return ((A*B-E*D)/(C*B*B));
    }
}
//---------------------------------------------------------------------------
double HML_NonparametricEstimatorOfDerivative(double x, double *X, double *Y, int VHML_N, double C, int V)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double Result=0;
    bool b;
    Result = HML_NonparametricEstimatorOfDerivative(x, X, Y, VHML_N, C, V, &b);
    return Result;
}
//---------------------------------------------------------------------------

double HML_NonparametricEstimatorOfDerivative2(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только
в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической
оценке регрессии в вновь полученной выборке.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное;
 b - сюда возвращается 1, если все прошло хорошо и 0, если C не захватывает никаких
 точек выборки (тогда функция возвращает 0).
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double *dY=new double [VHML_N];
    double dy=0;

    bool b2;
    for (int i=0;i<VHML_N;i++)
     {
     //непараметрическая оценка производной
     dY[i]=HML_NonparametricEstimatorOfDerivative(X[i], X, Y, VHML_N, C, V, &b2);
     }

    //непараметрическая оценка регрессии
    dy=HML_NonparametricEstimatorOfRegression(x, X, dY, VHML_N, C, V, b);

    delete [] dY;

    return dy;
}
//---------------------------------------------------------------------------
double HML_NonparametricEstimatorOfDerivative2(double x, double *X, double *Y, int VHML_N, double C, int V)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только
в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической
оценке регрессии в вновь полученной выборке.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double Result=0;
    bool b;
    Result = HML_NonparametricEstimatorOfDerivative2(x, X, Y, VHML_N, C, V, &b);
    return Result;
}
//---------------------------------------------------------------------------

double HML_NonparametricEstimatorOfDerivative3(double x, double *X, double *dY, int VHML_N, double C, int V, bool *b)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только
в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической
оценке регрессии в вновь полученной выборке.
В отличии от HML_NonparametricEstimatorOfDerivative2 пересчет выборки производной производится в другой функции. Поэтому работает быстрее, но по формулам одно и тоже, что и HML_NonparametricEstimatorOfDerivative2.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 dY - выборка пересчитанных значений оценок производной через функцию HML_MakingVectorForNonparametricEstimatorOfDerivative3;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное;
 b - сюда возвращается 1, если все прошло хорошо и 0, если C не захватывает никаких
 точек выборки (тогда функция возвращает 0).
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double dy=0;

    //непараметрическая оценка регрессии
    dy=HML_NonparametricEstimatorOfRegression(x, X, dY, VHML_N, C, V, b);

    return dy;
}
//---------------------------------------------------------------------------
double HML_NonparametricEstimatorOfDerivative3(double x, double *X, double *dY, int VHML_N, double C, int V)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только
в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической
оценке регрессии в вновь полученной выборке.
В отличии от HML_NonparametricEstimatorOfDerivative2 пересчет выборки производной производится в другой функции. Поэтому работает быстрее, но по формулам одно и тоже, что и HML_NonparametricEstimatorOfDerivative2.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 dY - выборка пересчитанных значений оценок производной через функцию HML_MakingVectorForNonparametricEstimatorOfDerivative6;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double Result=0;
    bool b;
    Result = HML_NonparametricEstimatorOfDerivative3(x, X, dY, VHML_N, C, V, &b);
    return Result;
}
//---------------------------------------------------------------------------

double HML_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Авторская разработка. Немного модифицирована формула по сравнению с HML_NonparametricEstimatorOfDerivative.
Хорошо работает на концах выборки.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное;
 b - сюда возвращается 1, если все прошло хорошо и 0, если C не захватывает никаких
 точек выборки (тогда функция возвращает 0).
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    if ((V!=0)&&(V!=1)&&(V!=2)&&(V!=3)) V=2;
    double (*F)(double);
    double (*dF)(double);
    //выбираем тип колоколообразного ядра
    if (V==0) F=HML_BellShapedKernelRectangle;
    if (V==1) F=HML_BellShapedKernelTriangle;
    if (V==2) F=HML_BellShapedKernelParabola;
    if (V==3) F=HML_BellShapedKernelExp;
    if (V==0) dF=HML_DerivativeOfBellShapedKernelRectangle;
    if (V==1) dF=HML_DerivativeOfBellShapedKernelTriangle;
    if (V==2) dF=HML_DerivativeOfBellShapedKernelParabola;
    if (V==3) dF=HML_DerivativeOfBellShapedKernelExp;

    double A=0,B=0,D=0;
    for (int i=0;i<VHML_N;i++)
    {
        A+=Y[i]*dF((x-X[i])/C);
        B+=F((x-X[i])/C);
        D+=Y[i]*F((x-X[i])/C);
    }

    //так как по формуле происходит деление на коэффициент размытия, то он не должен равняться 0
    if ((C==0)||(B==0))
    {
        *b=false;
        return 0;
    }
    else
    {
        *b=true;
        return ((A*B-C*D)/(C*B*B));
    }
}
//---------------------------------------------------------------------------
double HML_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VHML_N, double C, int V)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Авторская разработка. Немного модифицированна формула по сравнению с HML_NonparametricEstimatorOfDerivative.
Хорошо работает на концах выборки.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double Result=0;
    bool b;
    Result = HML_NonparametricEstimatorOfDerivative4(x, X, Y, VHML_N, C, V, &b);
    return Result;
}
//---------------------------------------------------------------------------

double HML_NonparametricEstimatorOfDerivative5(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только
в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической
оценке регрессии в вновь полученной выборке.
Авторская разработка. Немного модифицирована формула по сравнению с HML_NonparametricEstimatorOfDerivative.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное;
 b - сюда возвращается 1, если все прошло хорошо и 0, если C не захватывает никаких
 точек выборки (тогда функция возвращает 0).
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double *dY=new double [VHML_N];
    double dy=0;

    bool b2;
    for (int i=0;i<VHML_N;i++)
     {
     //непараметрическая оценка производной
     dY[i]=HML_NonparametricEstimatorOfDerivative4(X[i], X, Y, VHML_N, C, V, &b2);
     }

    //непараметрическая оценка регрессии
    dy=HML_NonparametricEstimatorOfRegression(x, X, dY, VHML_N, C, V, b);

    delete [] dY;

    return dy;
}
//---------------------------------------------------------------------------
double HML_NonparametricEstimatorOfDerivative5(double x, double *X, double *Y, int VHML_N, double C, int V)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только
в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической
оценке регрессии в вновь полученной выборке.
Авторская разработка. Немного модифицирована формула по сравнению с HML_NonparametricEstimatorOfDerivative.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double Result=0;
    bool b;
    Result = HML_NonparametricEstimatorOfDerivative5(x, X, Y, VHML_N, C, V, &b);
    return Result;
}
//---------------------------------------------------------------------------

double HML_NonparametricEstimatorOfDerivative6(double x, double *X, double *dY, int VHML_N, double C, int V, bool *b)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только
в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической
оценке регрессии в вновь полученной выборке.
В отличии от HML_NonparametricEstimatorOfDerivative5 пересчет выборки производной производится в другой функции. Поэтому работает быстрее, но по формулам одно и тоже, что и HML_NonparametricEstimatorOfDerivative5.
Авторская разработка. Немного модифицирована формула по сравнению с HML_NonparametricEstimatorOfDerivative.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 dY - выборка пересчитанных значений оценок производной через функцию HML_MakingVectorForNonparametricEstimatorOfDerivative6;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное;
 b - сюда возвращается 1, если все прошло хорошо и 0, если C не захватывает никаких
 точек выборки (тогда функция возвращает 0).
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double dy=0;

    //непараметрическая оценка регрессии
    dy=HML_NonparametricEstimatorOfRegression(x, X, dY, VHML_N, C, V, b);

    return dy;
}
//---------------------------------------------------------------------------
double HML_NonparametricEstimatorOfDerivative6(double x, double *X, double *dY, int VHML_N, double C, int V)
{
/*
Непараметрическая оценка производной при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только
в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической
оценке регрессии в вновь полученной выборке.
В отличии от HML_NonparametricEstimatorOfDerivative5 пересчет выборки производной производится в другой функции. Поэтому работает быстрее, но по формулам одно и тоже, что и HML_NonparametricEstimatorOfDerivative5.
Авторская разработка. Немного модифицирована формула по сравнению с HML_NonparametricEstimatorOfDerivative.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 dY - выборка пересчитанных значений оценок производной через функцию HML_MakingVectorForNonparametricEstimatorOfDerivative6;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Восстановленное значение производной функции в точке.
*/
    double Result=0;
    bool b;
    Result = HML_NonparametricEstimatorOfDerivative6(x, X, dY, VHML_N, C, V, &b);
    return Result;
}
//---------------------------------------------------------------------------

double HML_NonparametricEstimatorOfRegression(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b)
{
/*
Непараметрическая оценка регрессии при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
В общем, это аппроксимация функции.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное;
 b - сюда возвращается 1, если все прошло хорошо и 0, если C не захватывает никаких
 точек выборки (тогда функция возвращает 0).
Возвращаемое значение:
 Восстановленное значение функции в точке.
*/
    if ((V!=0)&&(V!=1)&&(V!=2)&&(V!=3)) V=2;
    double (*F)(double);
    //выбираем тип колоколообразного ядра
    if (V==0) F=HML_BellShapedKernelRectangle;
    if (V==1) F=HML_BellShapedKernelTriangle;
    if (V==2) F=HML_BellShapedKernelParabola;
    if (V==3) F=HML_BellShapedKernelExp;

    double s1=0,s2=0;
    for (int i=0;i<VHML_N;i++)
    {
        //вычисляем две суммы по выборке
        s1+=Y[i]*F((x-X[i])/C);
        s2+=F((x-X[i])/C);
    }

    if (s2==0)
    {
        //если s2==0, то значит, что при данном коэффициенте размытия в данной точке, колоколообразная функция
        //не захватила ни одной точки выборки. Тогда возвращается 0
        *b=false;
        return 0;
    }
    else
    {
        *b=true;
        return s1/s2;
    }
}
//---------------------------------------------------------------------------
double HML_NonparametricEstimatorOfRegression(double x, double *X, double *Y, int VHML_N, double C, int V)
{
/*
Непараметрическая оценка регрессии при равномерном законе распределения элементов
выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.
Входные параметры:
 x - входная переменная;
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное;
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Восстановленное значение функции в точке.
*/
    double Result=0;
    bool b;
    Result = HML_NonparametricEstimatorOfRegression(x, X, Y, VHML_N, C, V, &b);
    return Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Нечеткие системы
//*****************************************************************
double HML_CentroidOfTrapeziformFuzzyNumber(double a,double b,double c,double d)
{
/*
Определяет центр тяжести трапециевидного нечеткого числа.
Входные параметры:
 a - левая крайняя граница.
 b - начало устойчивой области.
 с - конец устойчивой области.
 d - правая крайняя граница.
Возвращаемое значение:
 Центр тяжести трапециевидного числа.
*/
    double f,f1,f2;
    f1=a*a+b*b-c*c-d*d+b*a-c*d;
    f2=a+b-c-d;
    if (f2==0)
        f=(d-a)/2.;
    else
        f=f1/(3.*f2);
    return f;
}
//---------------------------------------------------------------------------

double HML_MaxiMinTrapeziformFuzzyNumbers (double *Data)
{
/*
Функция находит максимальное значение функции принадлежности нечеткого числа,
образуемого минимизацией двух трапециевидных нечетких чисел. Необходимо для
нечеткого вывода.
Входные параметры:
 Data - данные о нечетких числах
 [0] - a1, левая крайняя граница первого нечеткого трапециевидного числа.
 [1] - b1, начало устойчивой области первого нечеткого трапециевидного числа.
 [2] - с1, конец устойчивой области первого нечеткого трапециевидного числа.
 [3] - d1, правая крайняя граница первого нечеткого трапециевидного числа.
 [4] - a2, левая крайняя граница второго нечеткого трапециевидного числа.
 [5] - b2, начало устойчивой области второго нечеткого трапециевидного числа.
 [6] - с2, конец устойчивой области второго нечеткого трапециевидного числа.
 [7] - d2, правая крайняя граница второго нечеткого трапециевидного числа.
Возвращаемое значение:
 Максимальное значение функции принадлежности нечеткого числа.
*/
    bool b;
    double x;
    double a1=Data[0];
    double b1=Data[1];
    double c1=Data[2];
    double d1=Data[3];
    double a2=Data[4];
    double b2=Data[5];
    double c2=Data[6];
    double d2=Data[7];

    //пересекаются ли отрезки [b1,c1] и [b2,c2]
    b=HML_BoolCrossingTwoSegment(b1,c1,b2,c2);

    if (b==true) return 1;
    if (b1>c2)
    {
        //меняем трапециевидные числа местами
        HML_NumberInterchange(&a1,&a2);
        HML_NumberInterchange(&b1,&b2);
        HML_NumberInterchange(&c1,&c2);
        HML_NumberInterchange(&d1,&d2);
    }

    //пересекаются ли отрезки
    b=HML_BoolCrossingTwoSegment(c1,d1,a2,b2);
    if (b==false) return 0;
    x=(a2*c1-d1*b2)/(a2-b2+c1-d1);
    return ((d1-x)/(d1-c1));
}
//---------------------------------------------------------------------------

double HML_TrapeziformFuzzyNumber(double x,double a,double b,double c,double d)
{
/*
Трапециевидное нечеткое число. Точнее его функция принадлежности.
Входные параметры:
 x - действительное число, для которого считаем функцию принадлежности.
 a - левая крайняя граница;
 b - начало устойчивой области;
 с - конец устойчивой области;
 d - правая крайняя граница.
Возвращаемое значение:
 Значение функции принадлежности.
*/
double f=0;

if (x<a) f=0.;
if ((x>=a)&&(x<b)) f=(x-a)/(b-a);
if ((x>=b)&&(x<=c)) f=1.;
if ((x>c)&&(x<=d)) f=(d-x)/(d-c);
if (x>d) f=0.;

return f;
}
//---------------------------------------------------------------------------

double HML_TrapeziformTruncatedFuzzyNumber(double x, double a, double b, double c, double d, double m)
{
/*
Трапециевидное усечённое нечеткое число. Точнее его функция принадлежности.
Данное число соответствует операции редукции при нечетком выводе.
Входные параметры:
 x - действительное число, для которого считаем функцию принадлежности.
 a - левая крайняя граница.
 b - начало устойчивой области.
 с - конец устойчивой области.
 d - правая крайняя граница.
 m - функция принадлежности не может быть выше этого значения [0;1].
Возвращаемое значение:
 Значение функции принадлежности.
*/
    m = HML_AcceptanceLimitsNumber(m,0.,1.);

    double f=HML_TrapeziformFuzzyNumber(x,a,b,c,d);

    if (f>m)
        f=m;//процесс усечения

    return f;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Оптимизация
//*****************************************************************
int HML_BinaryMonteCarloAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result)
{
/*
Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации для решения задач на бинарных строках. В простонародье его называют "методом научного тыка".
Алгоритм оптимизации. Ищет максимум функции пригодности FitnessFunction.
Входные параметры:
 Parameters
  [0] - длина бинарной строки (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений функции пригодности (CountOfFitness);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (бинарный вектор);
 VHML_Result - значение функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=20;
 Parameters[1]=100*100;
*/
//Считываем из Parameters параметры алгоритма
int LengthBinarString=Parameters[0];//Длина бинарной строки
int CountOfFitness=Parameters[1];//Число вычислений функции целевой

//Проверим данные
if (LengthBinarString<1) return 0;//Слишком маленькая длина бинарной строки
if (CountOfFitness<1) return 0;//Слишком маленькое число вычислений функции целевой

//Переменные
int i;//Счетчик
double TempFitness;//Значение функции целевой произвольного решения
double BestFitness;//Значение функции целевой лучшего решения за всё время работы алгоритма

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Массив для хранения произвольного решения
int *TempIndividual;
TempIndividual=new int[LengthBinarString];
//Массив для хранения лучшего решения за всё время работы алгоритма
int *BestIndividual;
BestIndividual=new int[LengthBinarString];

//Получим первое решение (оно пока и лучшее)
HML_RandomBinaryVector(BestIndividual,LengthBinarString);

//Вычислим значение функции целевой
try
 {
 BestFitness=FitnessFunction(BestIndividual,LengthBinarString);
 }
catch(...)
 {
 return 0;//Алгоритм не смог посчитать значение функции целевой
 }

for (i=1;i<CountOfFitness;i++)
 {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

 //Получим новое случайное решение
 HML_RandomBinaryVector(TempIndividual,LengthBinarString);

 //Вычислим значение функции целевой
 try
  {
  TempFitness=FitnessFunction(TempIndividual,LengthBinarString);
  }
 catch(...)
  {
  return 0;//Алгоритм не смог посчитать значение функции целевой
  }

 //Является ли данное решение лучше лучшего решения за всё время работы алгоритма
 if (TempFitness>BestFitness)
  {
  //Если всё-таки лучше
  HML_VectorToVector(TempIndividual,BestIndividual,LengthBinarString);
  BestFitness=TempFitness;//Запоминаем его значение функции целевой
  }

 }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

//Алгоритм закончил свою работу
//Выдадим найденное лучшее решение за время запуска алгоритма и его значение функции целевой
HML_VectorToVector(BestIndividual,VHML_ResultVector,LengthBinarString);
*VHML_Result=BestFitness;

//Удалим все дополнительные массивы
delete [] TempIndividual;
delete [] BestIndividual;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

void HML_DichotomyOptimization (double Left, double Right, double (*Function)(double), double Interval, double Epsilon, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод дихотомии. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Interval - длина конечного интервала неопределенности (точность поиска);
 Epsilon - малое число;
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
Примечание:
 Epsilon должен быть меньше, чем Interval/2, иначе возвращается левая граница просто.
*/
if (Epsilon>=Interval/2.)
 {
 //зануляем результаты
 *VHML_Result_X=Left;
 *VHML_Result_Y=Function(*VHML_Result_X);
 }
else
 {
 double l,v;
 while (fabs(Right-Left)>=Interval)
  {
  l=(Left+Right)/2.-Epsilon;
  v=(Left+Right)/2.+Epsilon;
  if (Function(l)<Function(v))
   Right=v;
  else
   Left=l;
  }
 *VHML_Result_X=(Left+Right)/2.;
 *VHML_Result_Y=Function(*VHML_Result_X);
 }
}
//---------------------------------------------------------------------------

void HML_FibonacciOptimization (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод Фибоначчи. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Count - число вычислений целевой функции;
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение: 
 Отсутствует.
*/
double l,v,fl,fv,Fib1,Fib2;
int i=1,n;
n=Count-1;

Fib1=HML_FibonacciNumber(n-i-1);
Fib2=HML_FibonacciNumber(n-i+1);
l=Left+(Fib1/Fib2)*(Right-Left);

Fib1=HML_FibonacciNumber(n-i  );
Fib2=HML_FibonacciNumber(n-i+1);
v=Left+(Fib1/Fib2)*(Right-Left);

fl=Function(l);
fv=Function(v);
for (i=2;i<n;i++)
 {
 if (Function(l)<Function(v))
  {
  Right=v;
  v=l;
  fv=fl;

  Fib1=HML_FibonacciNumber(n-i-1);
  Fib2=HML_FibonacciNumber(n-i+1);
  l=Left+(Fib1/Fib2)*(Right-Left);

  fl=Function(l);
  }
 else
  {
  Left=l;
  l=v;
  fl=fv;

  Fib1=HML_FibonacciNumber(n-i  );
  Fib2=HML_FibonacciNumber(n-i+1);
  v=Left+(Fib1/Fib2)*(Right-Left);

  fv=Function(v);
  }
 }
*VHML_Result_X=(Left+Right)/2.;
*VHML_Result_Y=Function(*VHML_Result_X);
}
//---------------------------------------------------------------------------

void HML_GoldenSectionOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод золотого сечения. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 b - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Interval - длина конечного интервала неопределенности (точность поиска);
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение: 
 Отсутствует.
*/
double l,v,fl,fv;
l=Left+(1.-HML_TAU)*(Right-Left);
v=Left+HML_TAU*(Right-Left);
fl=Function(l);
fv=Function(v);
while (fabs(Right-Left)>=Interval)
 {
 if (Function(l)<Function(v))
  {
  Right=v;
  v=l;
  fv=fl;
  l=Left+(1.-HML_TAU)*(Right-Left);
  fl=Function(l);
  }
 else
  {
  Left=l;
  l=v;
  fl=fv;
  v=Left+HML_TAU*(Right-Left);
  fv=Function(v);
  }
 }
*VHML_Result_X=(Left+Right)/2.;
*VHML_Result_Y=Function(*VHML_Result_X);
}
//---------------------------------------------------------------------------

void HML_QuadraticFitOptimization (double Left, double Right, double (*Function)(double), double Epsilon, double Epsilon2, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод квадратичной интерполяции. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Epsilon - точность;
 Epsilon2 - шаг, фактически еще одно малое число;
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
*/
double x,h,x1,x2,x3,k,f1,f2,f3,fx,fp1,fp2,fp3,p[4],X=Left;
double error=0;
int ko;
h=Epsilon2;
x1=(Left+Right)/2.-h;
x2=(Left+Right)/2.;
x3=(Left+Right)/2.+h;
f1=Function(x1);
f2=Function(x2);
f3=Function(x3);
if (f1<f2)
 k=-1.;
else
 k=1.;
while (!((f1>=f2)&&(f2<=f3)))
 {
 x1=x1+k*h;
 x2=x2+k*h;
 x3=x3+k*h;
 f1=Function(x1);
 f2=Function(x2);
 f3=Function(x3);
 if (x1<Left) error=Left;
 if (x3>Right) error=Right;
 if (error!=0) break;
 }
if (error==0)
{
 x=0.5*((x2*x2-x3*x3)*f1+(x3*x3-x1*x1)*f2+(x1*x1-x2*x2)*f3)/((x2-x3)*f1+(x3-x1)*f2+(x1-x2)*f3);
 fx=Function(x);
 while ((fabs(fx-f2)>Epsilon)&&(X!=x))
  {
  X=x;
  p[0]=x1;
  p[1]=x2;
  p[2]=x3;
  p[3]=x;
  HML_BubbleSort(p, 4);
  fp1=Function(p[0]);
  fp2=Function(p[1]);
  fp3=Function(p[2]);
  if (!((fp1>=fp2)&&(fp2<=fp3)))
   ko=1;
  else
   ko=0;
  x1=p[0+ko];
  x2=p[1+ko];
  x3=p[2+ko];
  x=0.5*((x2*x2-x3*x3)*f1+(x3*x3-x1*x1)*f2+(x1*x1-x2*x2)*f3)/((x2-x3)*f1+(x3-x1)*f2+(x1-x2)*f3);
  fx=Function(x);
  }
 *VHML_Result_X=x;
 *VHML_Result_Y=fx;
}
else
 {
    *VHML_Result_X=error;
    *VHML_Result_Y=Function(error);
 }
}
//---------------------------------------------------------------------------

int HML_RealMonteCarloAlgorithm(int *Parameters, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result)
{
/*
Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации на вещественных строках. В простонародье его называют "методом научного тыка".
Алгоритм оптимизации. Ищет максимум функции пригодности FitnessFunction.
Входные параметры:
 Parameters
  [0] - длина вещественной строки (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений функции пригодности (CountOfFitness);
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (вещественный вектор);
 VHML_Result - значение функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=5;
 Parameters[1]=50*50;
*/
//Считываем из Parameters параметры алгоритма
int LengthBinarString=Parameters[0];//Длина вещественной строки
int CountOfFitness=Parameters[1];//Число вычислений функции целевой

//Проверим данные
if (LengthBinarString<1) return 0;//Слишком маленькая длина вещественной строки
if (CountOfFitness<1) return 0;//Слишком маленькое число вычислений функции целевой

//Переменные
int i;//Счетчик
double TempFitness;//Значение функции пригодности произвольного решения
double BestFitness;//Значение функции пригодности лучшего решения за всё время работы алгоритма

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Массив для хранения произвольного решения
double *TempIndividual;
TempIndividual=new double[LengthBinarString];
//Массив для хранения лучшего решения за всё время работы алгоритма
double *BestIndividual;
BestIndividual=new double[LengthBinarString];

//Получим первое решение (оно пока и лучшее)
HML_RandomRealVectorInElements(BestIndividual,Left,Right,LengthBinarString);

//Вычислим значение функции целевой
try
 {
 BestFitness=FitnessFunction(BestIndividual,LengthBinarString);
 }
catch(...)
 {
 return 0;//Алгоритм не смог посчитать значение функции целевой
 }

for (i=1;i<CountOfFitness;i++)
 {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

 //Получим новое случайное решение
 HML_RandomRealVectorInElements(TempIndividual,Left,Right,LengthBinarString);

 //Вычислим значение функции целевой
 try
  {
  TempFitness=FitnessFunction(TempIndividual,LengthBinarString);
  }
 catch(...)
  {
  return 0;//Алгоритм не смог посчитать значение функции целевой
  }

 //Является ли данное решение лучше лучшего решения за всё время работы алгоритма
 if (TempFitness>BestFitness)
  {
  //Если всё-таки лучше
  HML_VectorToVector(TempIndividual,BestIndividual,LengthBinarString);
  BestFitness=TempFitness;//Запоминаем его значение функции целевой
  }

 }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

//Алгоритм закончил свою работу
//Выдадим найденное лучшее решение за время запуска алгоритма и его значение функции целевой
HML_VectorToVector(BestIndividual,VHML_ResultVector,LengthBinarString);
*VHML_Result=BestFitness;

//Удалим все дополнительные массивы
delete [] TempIndividual;
delete [] BestIndividual;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

void HML_RealMonteCarloOptimization (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации для решения задач на вещественных строках. Ищет минимум.
От функции HML_RealMonteCarloAlgorithm отличается тем, что ищет минимум, а не максимум, и не у многомерной функции,
а одномерной. Вводится, чтобы было продолжением однотипных методов оптимизации одномерных унимодальных функций.
Входные параметры:
 Left - начало интервала поиска
 Right - конец интервала поиска
 Function - унимодальная функция, минимум которой ищется
 Count - число вычислений целевой функции
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
*/
int i;
double min,fmin,f,x;
min=HML_RandomUniform(Left,Right);
fmin=Function(min);
for (i=1;i<Count;i++)
 {
 x=HML_RandomUniform(Left,Right);
 f=Function(x);
 if (f<fmin)
  {
  min=x;
  fmin=f;
  }
 }
*VHML_Result_X=min;
*VHML_Result_Y=fmin;
}
//---------------------------------------------------------------------------

void HML_UniformSearchOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод равномерного поиска. Метод одномерной оптимизации функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Interval - длина шага, с которым будет проводится поиск;
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
*/
int i,n;
double min,fmin,f,x;
n=ceil(fabs(Right-Left)/Interval);
min=Left;
fmin=Function(min);
x=Left;
for (i=1;i<n;i++)
 {
 x+=Interval;
 f=Function(x);
 if (f<fmin)
  {
  min=x;
  fmin=f;
  }
 }
*VHML_Result_X=min;
*VHML_Result_Y=fmin;
}
//---------------------------------------------------------------------------

void HML_UniformSearchOptimizationN (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод равномерного поиска. Метод одномерной оптимизации функции на интервале. Ищет минимум. От HML_UniformSearchOptimization отличается тем, что вместо параметра шага равномерного прохода используется число вычислений целевой функции, но они взаимозаменяемы.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Count - число вычислений целевой функции;
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
*/
int i,n;
double min,fmin,f,x;
double Interval=ceil(fabs(Right-Left)/double(Count));
n=Count;
min=Left;
fmin=Function(min);
x=Left;
for (i=1;i<n;i++)
 {
 x+=Interval;
 f=Function(x);
 if (f<fmin)
  {
  min=x;
  fmin=f;
  }
 }
*VHML_Result_X=min;
*VHML_Result_Y=fmin;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Оптимизация - свалка алгоритмов
//*****************************************************************
int HML_BinaryGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result)
{
/*
Генетический алгоритм для решения задач на бинарных строках с турнирной селекцией с возвращением, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но и она измененная, и размер турнира может изменяться.
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Тип алгоритма: добавочный алгоритм оптимизации.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина бинарной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - размер турнирной селекции с возвращением (SizeOfTournament): от 2 до sqrt(CountOfFitness);
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида).
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (бинарный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=50;
 Parameters[1]=100*100;
 Parameters[2]=10;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
*/
//Считываем из Parameters параметры алгоритма
int ChromosomeLength=Parameters[0];//Длина хромосомы
int CountOfFitness=Parameters[1];//Число вычислений целевой функции
int TypeOfSel=2;//Тип селекции = Турнирная
int SizeOfTournament=Parameters[2];//Размер турнира
int TypeOfCros=Parameters[3];//Тип скрещивания
int TypeOfMutation=Parameters[4];//Тип мутации
int TypeOfForm=Parameters[5];//Тип формирования нового поколения

//Проверим данные
if (ChromosomeLength<1)	return 0;//Слишком маленькая длина хромосомы
if (CountOfFitness<1)	return 0;//Слишком маленькое число вычислений целевой функции
//if (!((TypeOfSel==0)||(TypeOfSel==1)||(TypeOfSel==2))) return 0;//Тип селекции указан не верно
if (!((TypeOfCros==0)||(TypeOfCros==1)||(TypeOfCros==2))) return 0;//Тип скрещивания указан не верно
if (!((TypeOfMutation==0)||(TypeOfMutation==1)||(TypeOfMutation==2))) return 0;//Тип мутации указан не верно
if (!((TypeOfForm==0)||(TypeOfForm==1))) return 0;//Тип формирования нового поколения указан не верно

//Теперь определим остальные параметры алгоритма, исходя из полученной информации
//Размер популяции и число поколений должны быть приблизительно равны (насколько это возможно)
int NumberOfGenerations=int(sqrt(double(CountOfFitness)));//Число поколений
int PopulationSize=int(CountOfFitness/NumberOfGenerations);//Размер популяции

//Переменные
int I,i,j;//Счетчики
int NumberOfMaximumFitness;//Номер лучшего индивида в текущей популяции
double MaximumFitness;//Значение целевой функции лучшего индивида в текущей популяции
double BestFitness;//Значение целевой функции лучшего индивида за всё время работы алгоритма
int NumberOfParent1;//Номер первого выбранного родителя
int NumberOfParent2;//Номер второго выбранного родителя
double ProbabilityOfMutation;//Вероятность мутации

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Популяция индивидов
int **Population;
Population=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) Population[i]=new int[ChromosomeLength];
//Популяция потомков
int **ChildrenPopulation;
ChildrenPopulation=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) ChildrenPopulation[i]=new int[ChromosomeLength];
//Массив значений целевой функции индивидов
double *Fitness;
Fitness=new double[PopulationSize];
//Массив значений целевой функции потомков
double *ChildrenFitness;
ChildrenFitness=new double[PopulationSize];
//Массив для хранения произвольного индивида
int *TempIndividual;
TempIndividual=new int[ChromosomeLength];
//Массив для хранения лучшего индивида за всё время работы алгоритма
int *BestIndividual;
BestIndividual=new int[ChromosomeLength];
//Для пропорциональной и ранговой селекции нужен массив вероятностей выбора индивидов
double *VectorOfProbability;
VectorOfProbability=new double[PopulationSize];
//Для ранговой селекции нужен массив рангов индивидов
double *Rank;
Rank=new double[PopulationSize];
//Для турнирной селекции нужен служебный массив, содержащий информация о том, в турнире или нет индивид;
int *Taken;
Taken=new int[PopulationSize];
//Массив для хранения первого родителя
int *Parent1;
Parent1=new int[ChromosomeLength];
//Массив для хранения второго родителя
int *Parent2;
Parent2=new int[ChromosomeLength];
//Массив для хранения потомка от скрещивания двух родителей
int *Child;
Child=new int[ChromosomeLength];

//Инициализация начальной популяции
HML_RandomBinaryMatrix(Population,PopulationSize,ChromosomeLength);

//Вычислим значение целевой функции для каждого индивида
for (i=0;i<PopulationSize;i++)
 {
 //Копируем индивида во временного индивида, так как целевая функция работает с вектором, а не матрицей
 HML_MatrixToRow(Population,TempIndividual,i,ChromosomeLength);
 try
  {
  Fitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
  }
 catch(...)
  {
  return 0;//Генетический алгоритм не смог посчитать значение целевая функции индивида
  }
 }

//Определим наилучшего индивида и запомним его
NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(Fitness,PopulationSize);
MaximumFitness=HML_MaximumOfVector(Fitness,PopulationSize);
HML_MatrixToRow(Population,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
BestFitness=MaximumFitness;//Запоминаем его значение целевой функции

for (I=1;I<NumberOfGenerations;I++)
 {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

 //Подготовка массивов для оператора селекции
 if (TypeOfSel==1)
  {
  //Для ранговой селекции нужен массив рангов индивидов
  HML_MakeVectorOfRankForRankSelection(Fitness,Rank,PopulationSize);
  //Для ранговой селекции нужен массив вероятностей выбора индивидов из рангов
  HML_MakeVectorOfProbabilityForRanklSelection(Rank,VectorOfProbability,PopulationSize);
  }
 if (TypeOfSel==0)//Для пропорциональной нужен массив вероятностей выбора индивидов
  HML_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorOfProbability,PopulationSize);

 for (j=0;j<PopulationSize;j++)
  {//Формирование популяции потомков
  if (TypeOfSel==0)//Пропорциональная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==1)//Ранговая селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_RankSelection(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_RankSelection(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==2)//Турнирная селекция с возвращением
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_TournamentSelectionWithReturn(Fitness,SizeOfTournament,PopulationSize);
   NumberOfParent2=HML_TournamentSelectionWithReturn(Fitness,SizeOfTournament,PopulationSize);
   }

  //Копируем родителей из популяции
  HML_MatrixToRow(Population,Parent1,NumberOfParent1,ChromosomeLength);//Первого родителя
  HML_MatrixToRow(Population,Parent2,NumberOfParent2,ChromosomeLength);//Второго родителя

  //Теперь путем скрещивания получаем потомка
  if (TypeOfCros==0)//Одноточечное скрещивание
   HML_SinglepointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==1)//Двухточечное скрещивание
   HML_TwopointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==2)//Равномерное скрещивание
   HML_UniformCrossover(Parent1,Parent2,Child,ChromosomeLength);

  //Переместим потомка в массив потомков
  HML_RowToMatrix(ChildrenPopulation,Child,j,ChromosomeLength);
  }//Формирование популяции потомков

 //Мутируем получившуюся популяцию потомков
 //Но вначале определим вероятность мутации
 if (TypeOfMutation==0)//Слабая
  ProbabilityOfMutation=1./(3.*double(ChromosomeLength));
 if (TypeOfMutation==1)//Средняя
  ProbabilityOfMutation=1./double(ChromosomeLength);
 if (TypeOfMutation==2)//Сильняя
  ProbabilityOfMutation=HML_Min(3./double(ChromosomeLength),1.);
 HML_MutationBinaryMatrix(ChildrenPopulation,ProbabilityOfMutation,PopulationSize,ChromosomeLength);//Мутируем

 //Вычислим значение целевой функции для каждого потомка
 for (i=0;i<PopulationSize;i++)
  {
  //Копируем потомка во временного индивида, так как целевой функция работает с вектором, а не матрицей
  HML_MatrixToRow(ChildrenPopulation,TempIndividual,i,ChromosomeLength);
  try
   {
   ChildrenFitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
   }
  catch(...)
   {
   return 0;//Генетический алгоритм не смог посчитать значение целевой функции потомка
   }
  }

 //Определим наилучшего потомка и запомним его
 MaximumFitness=HML_MaximumOfVector(ChildrenFitness,PopulationSize);

 //Является ли лучшее решение на данном поколении лучше лучшего решения за всё время работы алгоритма
 if (MaximumFitness>BestFitness)
  {
  //Если всё-таки лучше
  NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(ChildrenFitness,PopulationSize);
  HML_MatrixToRow(ChildrenPopulation,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
  BestFitness=MaximumFitness;//Запоминаем его значение целевой функции
  }

 //Теперь сформируем новое поколение
 if (TypeOfForm==0)//Только потомки
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  }
 if (TypeOfForm==1)//Только потомки и копия лучшего индивида
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_RowToMatrix(Population,BestIndividual,0,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  Fitness[0]=BestFitness;
  }

 }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

//Генетический алгоритм закончил свою работу
//Выдадим найденное лучшее решение за время запуска алгоритма и его значение целевой функции
HML_VectorToVector(BestIndividual,VHML_ResultVector,ChromosomeLength);
*VHML_Result=BestFitness;

//Удалим все дополнительные массивы
for (i=0;i<PopulationSize;i++) delete [] Population[i];
 delete [] Population;
for (i=0;i<PopulationSize;i++) delete [] ChildrenPopulation[i];
 delete [] ChildrenPopulation;
delete [] Fitness;
delete [] ChildrenFitness;
delete [] TempIndividual;
delete [] BestIndividual;
delete [] VectorOfProbability;
delete [] Rank;
delete [] Taken;
delete [] Parent1;
delete [] Parent2;
delete [] Child;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_BinaryGeneticAlgorithmTwiceGenerations(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result)
{
    /*
Генетический алгоритм с двойным количеством поколений для решения задач на бинарных строках.
На четных поколениях целевая функция высчитывается как среднеарифметическое родителей.
https://github.com/Harrix/HarrixOptimizationAlgorithms
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина бинарной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида).
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (бинарный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=50;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
*/
    //Считываем из Parameters параметры алгоритма
    int ChromosomeLength=Parameters[0];//Длина хромосомы
    int CountOfFitness=Parameters[1];//Число вычислений целевой функции
    int TypeOfSel=Parameters[2];//Тип селекции
    int TypeOfCros=Parameters[3];//Тип скрещивания
    int TypeOfMutation=Parameters[4];//Тип мутации
    int TypeOfForm=Parameters[5];//Тип формирования нового поколения

    //Проверим данные
    if (ChromosomeLength<1)	return 0;//Слишком маленькая длина хромосомы
    if (CountOfFitness<1)	return 0;//Слишком маленькое число вычислений целевой функции
    if (!((TypeOfSel==0)||(TypeOfSel==1)||(TypeOfSel==2))) return 0;//Тип селекции указан не верно
    if (!((TypeOfCros==0)||(TypeOfCros==1)||(TypeOfCros==2))) return 0;//Тип скрещивания указан не верно
    if (!((TypeOfMutation==0)||(TypeOfMutation==1)||(TypeOfMutation==2))) return 0;//Тип мутации указан не верно
    if (!((TypeOfForm==0)||(TypeOfForm==1))) return 0;//Тип формирования нового поколения указан не верно

    //Теперь определим остальные параметры алгоритма, исходя из полученной информации
    //Размер популяции и число поколений должны быть приблизительно равны (насколько это возможно)
    int NumberOfGenerations=int(sqrt(double(CountOfFitness)));//Число поколений
    int PopulationSize=int(CountOfFitness/NumberOfGenerations);//Размер популяции
    int SizeOfTournament=2;//В стандартном генетическом алгоритме на бинарных строках размер турнира равен 2

    //Переменные
    int I,i,j;//Счетчики
    int NumberOfMaximumFitness;//Номер лучшего индивида в текущей популяции
    double MaximumFitness;//Значение целевой функции лучшего индивида в текущей популяции
    double BestFitness;//Значение целевой функции лучшего индивида за всё время работы алгоритма
    int NumberOfParent1;//Номер первого выбранного родителя
    int NumberOfParent2;//Номер второго выбранного родителя
    double ProbabilityOfMutation;//Вероятность мутации

    //Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
    //Популяция индивидов
    int **Population;
    Population=new int*[PopulationSize];
    for (i=0;i<PopulationSize;i++) Population[i]=new int[ChromosomeLength];
    //Популяция потомков
    int **ChildrenPopulation;
    ChildrenPopulation=new int*[PopulationSize];
    for (i=0;i<PopulationSize;i++) ChildrenPopulation[i]=new int[ChromosomeLength];
    //Массив значений целевой функции индивидов
    double *Fitness;
    Fitness=new double[PopulationSize];
    //Массив значений целевой функции потомков
    double *ChildrenFitness;
    ChildrenFitness=new double[PopulationSize];
    //Массив для хранения произвольного индивида
    int *TempIndividual;
    TempIndividual=new int[ChromosomeLength];
    //Массив для хранения лучшего индивида за всё время работы алгоритма
    int *BestIndividual;
    BestIndividual=new int[ChromosomeLength];
    //Для пропорциональной и ранговой селекции нужен массив вероятностей выбора индивидов
    double *VectorOfProbability;
    VectorOfProbability=new double[PopulationSize];
    //Для ранговой селекции нужен массив рангов индивидов
    double *Rank;
    Rank=new double[PopulationSize];
    //Для турнирной селекции нужен служебный массив, содержащий информация о том, в турнире или нет индивид;
    int *Taken;
    Taken=new int[PopulationSize];
    //Массив для хранения первого родителя
    int *Parent1;
    Parent1=new int[ChromosomeLength];
    //Массив для хранения второго родителя
    int *Parent2;
    Parent2=new int[ChromosomeLength];
    //Массив для хранения потомка от скрещивания двух родителей
    int *Child;
    Child=new int[ChromosomeLength];

    //Массивы для сохранения информации, кто родитель у потомка
    int *MemoryFirstParent;
    MemoryFirstParent=new int[PopulationSize];
    int *MemorySecondParent;
    MemorySecondParent=new int[PopulationSize];
    //Массивы для сохранения информации, какая пригодность была у родителей
    double *MemoryFitnessFirstParent;
    MemoryFitnessFirstParent=new double[PopulationSize];
    double *MemoryFitnessSecondParent;
    MemoryFitnessSecondParent=new double[PopulationSize];

    //Инициализация начальной популяции
    HML_RandomBinaryMatrix(Population,PopulationSize,ChromosomeLength);

    //Вычислим значение целевой функции для каждого индивида
    for (i=0;i<PopulationSize;i++)
    {
        //Копируем индивида во временного индивида, так как целевая функция работает с вектором, а не матрицей
        HML_MatrixToRow(Population,TempIndividual,i,ChromosomeLength);
        try
        {
            Fitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
        }
        catch(...)
        {
            return 0;//Генетический алгоритм не смог посчитать значение целевая функции индивида
        }
    }

    //Определим наилучшего индивида и запомним его
    NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(Fitness,PopulationSize);
    MaximumFitness=HML_MaximumOfVector(Fitness,PopulationSize);
    HML_MatrixToRow(Population,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
    BestFitness=MaximumFitness;//Запоминаем его значение целевой функции

    for (I=1;I<NumberOfGenerations*2-1;I++)
    {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

        //Подготовка массивов для оператора селекции
        if (TypeOfSel==1)
        {
            //Для ранговой селекции нужен массив рангов индивидов
            HML_MakeVectorOfRankForRankSelection(Fitness,Rank,PopulationSize);
            //Для ранговой селекции нужен массив вероятностей выбора индивидов из рангов
            HML_MakeVectorOfProbabilityForRanklSelection(Rank,VectorOfProbability,PopulationSize);
        }
        if (TypeOfSel==0)//Для пропорциональной нужен массив вероятностей выбора индивидов
            HML_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorOfProbability,PopulationSize);

        for (j=0;j<PopulationSize;j++)
        {//Формирование популяции потомков
            if (TypeOfSel==0)//Пропорциональная селекция
            {
                //Выбираем двух родителей (точнее их номера)
                NumberOfParent1=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
                NumberOfParent2=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
            }
            if (TypeOfSel==1)//Ранговая селекция
            {
                //Выбираем двух родителей (точнее их номера)
                NumberOfParent1=HML_RankSelection(VectorOfProbability,PopulationSize);
                NumberOfParent2=HML_RankSelection(VectorOfProbability,PopulationSize);
            }
            if (TypeOfSel==2)//Турнирная селекция
            {
                //Выбираем двух родителей (точнее их номера)
                NumberOfParent1=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
                NumberOfParent2=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
            }

            //Сохраняем информацию кто родитель у потомка
            MemoryFirstParent[j]=NumberOfParent1;
            MemorySecondParent[j]=NumberOfParent2;
            //Сохраняем информацию пригодностей родителей
            MemoryFitnessFirstParent[j]=Fitness[NumberOfParent1];
            MemoryFitnessSecondParent[j]=Fitness[NumberOfParent2];

            //Копируем родителей из популяции
            HML_MatrixToRow(Population,Parent1,NumberOfParent1,ChromosomeLength);//Первого родителя
            HML_MatrixToRow(Population,Parent2,NumberOfParent2,ChromosomeLength);//Второго родителя

            //Теперь путем скрещивания получаем потомка
            if (TypeOfCros==0)//Одноточечное скрещивание
                HML_SinglepointCrossover(Parent1,Parent2,Child,ChromosomeLength);
            if (TypeOfCros==1)//Двухточечное скрещивание
                HML_TwopointCrossover(Parent1,Parent2,Child,ChromosomeLength);
            if (TypeOfCros==2)//Равномерное скрещивание
                HML_UniformCrossover(Parent1,Parent2,Child,ChromosomeLength);

            //Переместим потомка в массив потомков
            HML_RowToMatrix(ChildrenPopulation,Child,j,ChromosomeLength);
        }//Формирование популяции потомков

        //Мутируем получившуюся популяцию потомков
        //Но вначале определим вероятность мутации
        if (TypeOfMutation==0)//Слабая
            ProbabilityOfMutation=1./(3.*double(ChromosomeLength));
        if (TypeOfMutation==1)//Средняя
            ProbabilityOfMutation=1./double(ChromosomeLength);
        if (TypeOfMutation==2)//Сильняя
            ProbabilityOfMutation=HML_Min(3./double(ChromosomeLength),1.);
        HML_MutationBinaryMatrix(ChildrenPopulation,ProbabilityOfMutation,PopulationSize,ChromosomeLength);//Мутируем

        if (I%2==0)
        {
            //Вычислим значение целевой функции для каждого потомка
            for (i=0;i<PopulationSize;i++)
            {
                //Копируем потомка во временного индивида, так как целевой функция работает с вектором, а не матрицей
                HML_MatrixToRow(ChildrenPopulation,TempIndividual,i,ChromosomeLength);
                try
                {
                    ChildrenFitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
                }
                catch(...)
                {
                    return 0;//Генетический алгоритм не смог посчитать значение целевой функции потомка
                }
            }

            //Определим наилучшего потомка и запомним его
            MaximumFitness=HML_MaximumOfVector(ChildrenFitness,PopulationSize);

            //Является ли лучшее решение на данном поколении лучше лучшего решения за всё время работы алгоритма
            if (MaximumFitness>BestFitness)
            {
                //Если всё-таки лучше
                NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(ChildrenFitness,PopulationSize);
                HML_MatrixToRow(ChildrenPopulation,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
                BestFitness=MaximumFitness;//Запоминаем его значение целевой функции
            }
        }
        else
        {
            //Вычислим значение целевой функции для каждого потомка
            for (i=0;i<PopulationSize;i++)
            {
                ChildrenFitness[i]=(MemoryFitnessFirstParent[i]+MemoryFitnessSecondParent[i])/2.;
            }
        }

        //Теперь сформируем новое поколение
        if (TypeOfForm==0)//Только потомки
        {
            HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
            HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
        }
        if (TypeOfForm==1)//Только потомки и копия лучшего индивида
        {
            HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
            HML_RowToMatrix(Population,BestIndividual,0,ChromosomeLength);
            HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
            Fitness[0]=BestFitness;
        }

    }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

    //Генетический алгоритм закончил свою работу
    //Выдадим найденное лучшее решение за время запуска алгоритма и его значение целевой функции
    HML_VectorToVector(BestIndividual,VHML_ResultVector,ChromosomeLength);
    *VHML_Result=BestFitness;

    //Удалим все дополнительные массивы
    for (i=0;i<PopulationSize;i++) delete [] Population[i];
    delete [] Population;
    for (i=0;i<PopulationSize;i++) delete [] ChildrenPopulation[i];
    delete [] ChildrenPopulation;
    delete [] Fitness;
    delete [] ChildrenFitness;
    delete [] TempIndividual;
    delete [] BestIndividual;
    delete [] VectorOfProbability;
    delete [] Rank;
    delete [] Taken;
    delete [] Parent1;
    delete [] Parent2;
    delete [] Child;
    delete [] MemoryFirstParent;
    delete [] MemorySecondParent;
    delete [] MemoryFitnessFirstParent;
    delete [] MemoryFitnessSecondParent;

    return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_BinaryGeneticAlgorithmWCC(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result)
{
/*
Генетический алгоритм для решения задач на бинарных строках, в котором есть только два вида скрещивания: одноточечное и двухточечное скрещивание с возможностью полного копирования одного из родителей. Равномерное скрещивание отсутствует.
Исследовательский алгоритм оптимизации.
https://github.com/Harrix/HarrixOptimizationAlgorithms
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина бинарной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossoverWithCopying (Одноточечное скрещивание с возможностью полного копирования одного из родителей);
        1 - TwopointCrossoverWithCopying (Двухточечное скрещивание с возможностью полного копирования одного из родителей).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида).
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (бинарный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=50;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=0;
 Parameters[4]=1;
 Parameters[5]=1;
*/
//Считываем из Parameters параметры алгоритма
int ChromosomeLength=Parameters[0];//Длина хромосомы
int CountOfFitness=Parameters[1];//Число вычислений целевой функции
int TypeOfSel=Parameters[2];//Тип селекции
int TypeOfCros=Parameters[3];//Тип скрещивания
int TypeOfMutation=Parameters[4];//Тип мутации
int TypeOfForm=Parameters[5];//Тип формирования нового поколения

//Проверим данные
if (ChromosomeLength<1)	return 0;//Слишком маленькая длина хромосомы
if (CountOfFitness<1)	return 0;//Слишком маленькое число вычислений целевой функции
if (!((TypeOfSel==0)||(TypeOfSel==1)||(TypeOfSel==2))) return 0;//Тип селекции указан не верно
if (!((TypeOfCros==0)||(TypeOfCros==1))) return 0;//Тип скрещивания указан не верно
if (!((TypeOfMutation==0)||(TypeOfMutation==1)||(TypeOfMutation==2))) return 0;//Тип мутации указан не верно
if (!((TypeOfForm==0)||(TypeOfForm==1))) return 0;//Тип формирования нового поколения указан не верно

//Теперь определим остальные параметры алгоритма, исходя из полученной информации
//Размер популяции и число поколений должны быть приблизительно равны (насколько это возможно)
int NumberOfGenerations=int(sqrt(double(CountOfFitness)));//Число поколений
int PopulationSize=int(CountOfFitness/NumberOfGenerations);//Размер популяции
int SizeOfTournament=2;//В стандартном генетическом алгоритме на бинарных строках размер турнира равен 2

//Переменные
int I,i,j;//Счетчики
int NumberOfMaximumFitness;//Номер лучшего индивида в текущей популяции
double MaximumFitness;//Значение целевой функции лучшего индивида в текущей популяции
double BestFitness;//Значение целевой функции лучшего индивида за всё время работы алгоритма
int NumberOfParent1;//Номер первого выбранного родителя
int NumberOfParent2;//Номер второго выбранного родителя
double ProbabilityOfMutation;//Вероятность мутации

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Популяция индивидов
int **Population;
Population=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) Population[i]=new int[ChromosomeLength];
//Популяция потомков
int **ChildrenPopulation;
ChildrenPopulation=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) ChildrenPopulation[i]=new int[ChromosomeLength];
//Массив значений целевой функции индивидов
double *Fitness;
Fitness=new double[PopulationSize];
//Массив значений целевой функции потомков
double *ChildrenFitness;
ChildrenFitness=new double[PopulationSize];
//Массив для хранения произвольного индивида
int *TempIndividual;
TempIndividual=new int[ChromosomeLength];
//Массив для хранения лучшего индивида за всё время работы алгоритма
int *BestIndividual;
BestIndividual=new int[ChromosomeLength];
//Для пропорциональной и ранговой селекции нужен массив вероятностей выбора индивидов
double *VectorOfProbability;
VectorOfProbability=new double[PopulationSize];
//Для ранговой селекции нужен массив рангов индивидов
double *Rank;
Rank=new double[PopulationSize];
//Для турнирной селекции нужен служебный массив, содержащий информация о том, в турнире или нет индивид;
int *Taken;
Taken=new int[PopulationSize];
//Массив для хранения первого родителя
int *Parent1;
Parent1=new int[ChromosomeLength];
//Массив для хранения второго родителя
int *Parent2;
Parent2=new int[ChromosomeLength];
//Массив для хранения потомка от скрещивания двух родителей
int *Child;
Child=new int[ChromosomeLength];

//Инициализация начальной популяции
HML_RandomBinaryMatrix(Population,PopulationSize,ChromosomeLength);

//Вычислим значение целевой функции для каждого индивида
for (i=0;i<PopulationSize;i++)
 {
 //Копируем индивида во временного индивида, так как целевая функция работает с вектором, а не матрицей
 HML_MatrixToRow(Population,TempIndividual,i,ChromosomeLength);
 try
  {
  Fitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
  }
 catch(...)
  {
  return 0;//Генетический алгоритм не смог посчитать значение целевая функции индивида
  }
 }

//Определим наилучшего индивида и запомним его
NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(Fitness,PopulationSize);
MaximumFitness=HML_MaximumOfVector(Fitness,PopulationSize);
HML_MatrixToRow(Population,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
BestFitness=MaximumFitness;//Запоминаем его значение целевой функции

for (I=1;I<NumberOfGenerations;I++)
 {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

 //Подготовка массивов для оператора селекции
 if (TypeOfSel==1)
  {
  //Для ранговой селекции нужен массив рангов индивидов
  HML_MakeVectorOfRankForRankSelection(Fitness,Rank,PopulationSize);
  //Для ранговой селекции нужен массив вероятностей выбора индивидов из рангов
  HML_MakeVectorOfProbabilityForRanklSelection(Rank,VectorOfProbability,PopulationSize);
  }
 if (TypeOfSel==0)//Для пропорциональной нужен массив вероятностей выбора индивидов
  HML_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorOfProbability,PopulationSize);

 for (j=0;j<PopulationSize;j++)
  {//Формирование популяции потомков
  if (TypeOfSel==0)//Пропорциональная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==1)//Ранговая селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_RankSelection(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_RankSelection(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==2)//Турнирная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   NumberOfParent2=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   }

  //Копируем родителей из популяции
  HML_MatrixToRow(Population,Parent1,NumberOfParent1,ChromosomeLength);//Первого родителя
  HML_MatrixToRow(Population,Parent2,NumberOfParent2,ChromosomeLength);//Второго родителя

  //Теперь путем скрещивания получаем потомка
  if (TypeOfCros==0)//Одноточечное скрещивание
   HML_TwopointCrossoverWithCopying(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==1)//Двухточечное скрещивание
   HML_SinglepointCrossoverWithCopying(Parent1,Parent2,Child,ChromosomeLength);

  //Переместим потомка в массив потомков
  HML_RowToMatrix(ChildrenPopulation,Child,j,ChromosomeLength);
  }//Формирование популяции потомков

 //Мутируем получившуюся популяцию потомков
 //Но вначале определим вероятность мутации
 if (TypeOfMutation==0)//Слабая
  ProbabilityOfMutation=1./(3.*double(ChromosomeLength));
 if (TypeOfMutation==1)//Средняя
  ProbabilityOfMutation=1./double(ChromosomeLength);
 if (TypeOfMutation==2)//Сильняя
  ProbabilityOfMutation=HML_Min(3./double(ChromosomeLength),1.);
 HML_MutationBinaryMatrix(ChildrenPopulation,ProbabilityOfMutation,PopulationSize,ChromosomeLength);//Мутируем

 //Вычислим значение целевой функции для каждого потомка
 for (i=0;i<PopulationSize;i++)
  {
  //Копируем потомка во временного индивида, так как целевой функция работает с вектором, а не матрицей
  HML_MatrixToRow(ChildrenPopulation,TempIndividual,i,ChromosomeLength);
  try
   {
   ChildrenFitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
   }
  catch(...)
   {
   return 0;//Генетический алгоритм не смог посчитать значение целевой функции потомка
   }
  }

 //Определим наилучшего потомка и запомним его
 MaximumFitness=HML_MaximumOfVector(ChildrenFitness,PopulationSize);

 //Является ли лучшее решение на данном поколении лучше лучшего решения за всё время работы алгоритма
 if (MaximumFitness>BestFitness)
  {
  //Если всё-таки лучше
  NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(ChildrenFitness,PopulationSize);
  HML_MatrixToRow(ChildrenPopulation,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
  BestFitness=MaximumFitness;//Запоминаем его значение целевой функции
  }

 //Теперь сформируем новое поколение
 if (TypeOfForm==0)//Только потомки
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  }
 if (TypeOfForm==1)//Только потомки и копия лучшего индивида
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_RowToMatrix(Population,BestIndividual,0,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  Fitness[0]=BestFitness;
  }

 }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

//Генетический алгоритм закончил свою работу
//Выдадим найденное лучшее решение за время запуска алгоритма и его значение целевой функции
HML_VectorToVector(BestIndividual,VHML_ResultVector,ChromosomeLength);
*VHML_Result=BestFitness;

//Удалим все дополнительные массивы
for (i=0;i<PopulationSize;i++) delete [] Population[i];
 delete [] Population;
for (i=0;i<PopulationSize;i++) delete [] ChildrenPopulation[i];
 delete [] ChildrenPopulation;
delete [] Fitness;
delete [] ChildrenFitness;
delete [] TempIndividual;
delete [] BestIndividual;
delete [] VectorOfProbability;
delete [] Rank;
delete [] Taken;
delete [] Parent1;
delete [] Parent2;
delete [] Child;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_BinaryGeneticAlgorithmWDPOfNOfGPS(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result)
{
/*
Генетический алгоритм для решения задач на бинарных строках с изменяющимся соотношением числа поколений и размера популяции.
Отличается от стандартного генетического алгоритма, тем, что размер популяции и число поколений рассчитывается
из числа вычислений целевой функции не как одинаковые величины (извлечение квадратного корня), а через некоторое соотношение.
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Тип алгоритма: исследовательский алгоритм оптимизации.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина бинарной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Averagen (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида).
  [6] - "доля" (Proportion) числа поколений от общего числа вычислений целевой функции.
        Определяется как возведение числа вычислений целевой функции в степень Proportion.
        Может принимать значения в интервале [0;1].
        Число поколений = int(CountOfFitness^Proportion).
        Размер популяции = int(CountOfFitness/Число поколений).
        При Proportion=0.5 получим обычный стандартный генетический алгоритм.
        Чем меньше Proportion, тем меньше число поколений будет.
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (бинарный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=50;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0.5;
*/
//Считываем из Parameters параметры алгоритма
int ChromosomeLength=Parameters[0];//Длина хромосомы
int CountOfFitness=Parameters[1];//Число вычислений целевой функции
int TypeOfSel=Parameters[2];//Тип селекции
int TypeOfCros=Parameters[3];//Тип скрещивания
int TypeOfMutation=Parameters[4];//Тип мутации
int TypeOfForm=Parameters[5];//Тип формирования нового поколения
double Proportion=Parameters[6];//"доля" числа поколений от общего числа вычислений целевой функции

//Проверим данные
if (ChromosomeLength<1)	return 0;//Слишком маленькая длина хромосомы
if (CountOfFitness<1)	return 0;//Слишком маленькое число вычислений целевой функции
if (!((TypeOfSel==0)||(TypeOfSel==1)||(TypeOfSel==2))) return 0;//Тип селекции указан не верно
if (!((TypeOfCros==0)||(TypeOfCros==1)||(TypeOfCros==2))) return 0;//Тип скрещивания указан не верно
if (!((TypeOfMutation==0)||(TypeOfMutation==1)||(TypeOfMutation==2))) return 0;//Тип мутации указан не верно
if (!((TypeOfForm==0)||(TypeOfForm==1))) return 0;//Тип формирования нового поколения указан не верно
if ((Proportion<0)||(Proportion>1)) return 0;//"доля" числа поколений может быть в интервале [0;1].

//Теперь определим остальные параметры алгоритма, исходя из полученной информации
//Размер популяции и число поколений должны быть приблизительно равны (насколько это возможно)
int NumberOfGenerations=int(pow(double(CountOfFitness),Proportion));//Число поколений
int PopulationSize=int(CountOfFitness/NumberOfGenerations);//Размер популяции
int SizeOfTournament=2;//В стандартном генетическом алгоритме на бинарных строках размер турнира равен 2

//Переменные
int I,i,j;//Счетчики
int NumberOfMaximumFitness;//Номер лучшего индивида в текущей популяции
double MaximumFitness;//Значение целевой функции лучшего индивида в текущей популяции
double BestFitness;//Значение целевой функции лучшего индивида за всё время работы алгоритма
int NumberOfParent1;//Номер первого выбранного родителя
int NumberOfParent2;//Номер второго выбранного родителя
double ProbabilityOfMutation;//Вероятность мутации

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Популяция индивидов
int **Population;
Population=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) Population[i]=new int[ChromosomeLength];
//Популяция потомков
int **ChildrenPopulation;
ChildrenPopulation=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) ChildrenPopulation[i]=new int[ChromosomeLength];
//Массив значений целевой функции индивидов
double *Fitness;
Fitness=new double[PopulationSize];
//Массив значений целевой функции потомков
double *ChildrenFitness;
ChildrenFitness=new double[PopulationSize];
//Массив для хранения произвольного индивида
int *TempIndividual;
TempIndividual=new int[ChromosomeLength];
//Массив для хранения лучшего индивида за всё время работы алгоритма
int *BestIndividual;
BestIndividual=new int[ChromosomeLength];
//Для пропорциональной и ранговой селекции нужен массив вероятностей выбора индивидов
double *VectorOfProbability;
VectorOfProbability=new double[PopulationSize];
//Для ранговой селекции нужен массив рангов индивидов
double *Rank;
Rank=new double[PopulationSize];
//Для турнирной селекции нужен служебный массив, содержащий информация о том, в турнире или нет индивид;
int *Taken;
Taken=new int[PopulationSize];
//Массив для хранения первого родителя
int *Parent1;
Parent1=new int[ChromosomeLength];
//Массив для хранения второго родителя
int *Parent2;
Parent2=new int[ChromosomeLength];
//Массив для хранения потомка от скрещивания двух родителей
int *Child;
Child=new int[ChromosomeLength];

//Инициализация начальной популяции
HML_RandomBinaryMatrix(Population,PopulationSize,ChromosomeLength);

//Вычислим значение целевой функции для каждого индивида
for (i=0;i<PopulationSize;i++)
 {
 //Копируем индивида во временного индивида, так как целевая функция работает с вектором, а не матрицей
 HML_MatrixToRow(Population,TempIndividual,i,ChromosomeLength);
 try
  {
  Fitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
  }
 catch(...)
  {
  return 0;//Генетический алгоритм не смог посчитать значение целевая функции индивида
  }
 }

//Определим наилучшего индивида и запомним его
NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(Fitness,PopulationSize);
MaximumFitness=HML_MaximumOfVector(Fitness,PopulationSize);
HML_MatrixToRow(Population,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
BestFitness=MaximumFitness;//Запоминаем его значение целевой функции

for (I=1;I<NumberOfGenerations;I++)
 {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

 //Подготовка массивов для оператора селекции
 if (TypeOfSel==1)
  {
  //Для ранговой селекции нужен массив рангов индивидов
  HML_MakeVectorOfRankForRankSelection(Fitness,Rank,PopulationSize);
  //Для ранговой селекции нужен массив вероятностей выбора индивидов из рангов
  HML_MakeVectorOfProbabilityForRanklSelection(Rank,VectorOfProbability,PopulationSize);
  }
 if (TypeOfSel==0)//Для пропорциональной нужен массив вероятностей выбора индивидов
  HML_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorOfProbability,PopulationSize);

 for (j=0;j<PopulationSize;j++)
  {//Формирование популяции потомков
  if (TypeOfSel==0)//Пропорциональная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==1)//Ранговая селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_RankSelection(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_RankSelection(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==2)//Турнирная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   NumberOfParent2=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   }

  //Копируем родителей из популяции
  HML_MatrixToRow(Population,Parent1,NumberOfParent1,ChromosomeLength);//Первого родителя
  HML_MatrixToRow(Population,Parent2,NumberOfParent2,ChromosomeLength);//Второго родителя

  //Теперь путем скрещивания получаем потомка
  if (TypeOfCros==0)//Одноточечное скрещивание
   HML_SinglepointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==1)//Двухточечное скрещивание
   HML_TwopointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==2)//Равномерное скрещивание
   HML_UniformCrossover(Parent1,Parent2,Child,ChromosomeLength);

  //Переместим потомка в массив потомков
  HML_RowToMatrix(ChildrenPopulation,Child,j,ChromosomeLength);
  }//Формирование популяции потомков

 //Мутируем получившуюся популяцию потомков
 //Но вначале определим вероятность мутации
 if (TypeOfMutation==0)//Слабая
  ProbabilityOfMutation=1./(3.*double(ChromosomeLength));
 if (TypeOfMutation==1)//Средняя
  ProbabilityOfMutation=1./double(ChromosomeLength);
 if (TypeOfMutation==2)//Сильняя
  ProbabilityOfMutation=HML_Min(3./double(ChromosomeLength),1.);
 HML_MutationBinaryMatrix(ChildrenPopulation,ProbabilityOfMutation,PopulationSize,ChromosomeLength);//Мутируем

 //Вычислим значение целевой функции для каждого потомка
 for (i=0;i<PopulationSize;i++)
  {
  //Копируем потомка во временного индивида, так как целевой функция работает с вектором, а не матрицей
  HML_MatrixToRow(ChildrenPopulation,TempIndividual,i,ChromosomeLength);
  try
   {
   ChildrenFitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
   }
  catch(...)
   {
   return 0;//Генетический алгоритм не смог посчитать значение целевой функции потомка
   }
  }

 //Определим наилучшего потомка и запомним его
 MaximumFitness=HML_MaximumOfVector(ChildrenFitness,PopulationSize);

 //Является ли лучшее решение на данном поколении лучше лучшего решения за всё время работы алгоритма
 if (MaximumFitness>BestFitness)
  {
  //Если всё-таки лучше
  NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(ChildrenFitness,PopulationSize);
  HML_MatrixToRow(ChildrenPopulation,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
  BestFitness=MaximumFitness;//Запоминаем его значение целевой функции
  }

 //Теперь сформируем новое поколение
 if (TypeOfForm==0)//Только потомки
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  }
 if (TypeOfForm==1)//Только потомки и копия лучшего индивида
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_RowToMatrix(Population,BestIndividual,0,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  Fitness[0]=BestFitness;
  }

 }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

//Генетический алгоритм закончил свою работу
//Выдадим найденное лучшее решение за время запуска алгоритма и его значение целевой функции
HML_VectorToVector(BestIndividual,VHML_ResultVector,ChromosomeLength);
*VHML_Result=BestFitness;

//Удалим все дополнительные массивы
for (i=0;i<PopulationSize;i++) delete [] Population[i];
 delete [] Population;
for (i=0;i<PopulationSize;i++) delete [] ChildrenPopulation[i];
 delete [] ChildrenPopulation;
delete [] Fitness;
delete [] ChildrenFitness;
delete [] TempIndividual;
delete [] BestIndividual;
delete [] VectorOfProbability;
delete [] Rank;
delete [] Taken;
delete [] Parent1;
delete [] Parent2;
delete [] Child;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_BinaryGeneticAlgorithmWDTS(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result)
{
/*
Генетический алгоритм для решения задач на бинарных строках с турнирной селекцией, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но размер турнира может изменяться.
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Тип алгоритма: добавочный алгоритм оптимизации.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина бинарной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - размер турнирной селекции (SizeOfTournament): от 2 до sqrt(CountOfFitness);
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида).
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (бинарный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=50;
 Parameters[1]=100*100;
 Parameters[2]=10;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
*/
//Считываем из Parameters параметры алгоритма
int ChromosomeLength=Parameters[0];//Длина хромосомы
int CountOfFitness=Parameters[1];//Число вычислений целевой функции
int TypeOfSel=2;//Тип селекции = Турнирная
int SizeOfTournament=Parameters[2];//Размер турнира
int TypeOfCros=Parameters[3];//Тип скрещивания
int TypeOfMutation=Parameters[4];//Тип мутации
int TypeOfForm=Parameters[5];//Тип формирования нового поколения

//Проверим данные
if (ChromosomeLength<1)	return 0;//Слишком маленькая длина хромосомы
if (CountOfFitness<1)	return 0;//Слишком маленькое число вычислений целевой функции
//if (!((TypeOfSel==0)||(TypeOfSel==1)||(TypeOfSel==2))) return 0;//Тип селекции указан не верно
if (!((TypeOfCros==0)||(TypeOfCros==1)||(TypeOfCros==2))) return 0;//Тип скрещивания указан не верно
if (!((TypeOfMutation==0)||(TypeOfMutation==1)||(TypeOfMutation==2))) return 0;//Тип мутации указан не верно
if (!((TypeOfForm==0)||(TypeOfForm==1))) return 0;//Тип формирования нового поколения указан не верно

//Теперь определим остальные параметры алгоритма, исходя из полученной информации
//Размер популяции и число поколений должны быть приблизительно равны (насколько это возможно)
int NumberOfGenerations=int(sqrt(double(CountOfFitness)));//Число поколений
int PopulationSize=int(CountOfFitness/NumberOfGenerations);//Размер популяции

//Переменные
int I,i,j;//Счетчики
int NumberOfMaximumFitness;//Номер лучшего индивида в текущей популяции
double MaximumFitness;//Значение целевой функции лучшего индивида в текущей популяции
double BestFitness;//Значение целевой функции лучшего индивида за всё время работы алгоритма
int NumberOfParent1;//Номер первого выбранного родителя
int NumberOfParent2;//Номер второго выбранного родителя
double ProbabilityOfMutation;//Вероятность мутации

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Популяция индивидов
int **Population;
Population=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) Population[i]=new int[ChromosomeLength];
//Популяция потомков
int **ChildrenPopulation;
ChildrenPopulation=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) ChildrenPopulation[i]=new int[ChromosomeLength];
//Массив значений целевой функции индивидов
double *Fitness;
Fitness=new double[PopulationSize];
//Массив значений целевой функции потомков
double *ChildrenFitness;
ChildrenFitness=new double[PopulationSize];
//Массив для хранения произвольного индивида
int *TempIndividual;
TempIndividual=new int[ChromosomeLength];
//Массив для хранения лучшего индивида за всё время работы алгоритма
int *BestIndividual;
BestIndividual=new int[ChromosomeLength];
//Для пропорциональной и ранговой селекции нужен массив вероятностей выбора индивидов
double *VectorOfProbability;
VectorOfProbability=new double[PopulationSize];
//Для ранговой селекции нужен массив рангов индивидов
double *Rank;
Rank=new double[PopulationSize];
//Для турнирной селекции нужен служебный массив, содержащий информация о том, в турнире или нет индивид;
int *Taken;
Taken=new int[PopulationSize];
//Массив для хранения первого родителя
int *Parent1;
Parent1=new int[ChromosomeLength];
//Массив для хранения второго родителя
int *Parent2;
Parent2=new int[ChromosomeLength];
//Массив для хранения потомка от скрещивания двух родителей
int *Child;
Child=new int[ChromosomeLength];

//Инициализация начальной популяции
HML_RandomBinaryMatrix(Population,PopulationSize,ChromosomeLength);

//Вычислим значение целевой функции для каждого индивида
for (i=0;i<PopulationSize;i++)
 {
 //Копируем индивида во временного индивида, так как целевая функция работает с вектором, а не матрицей
 HML_MatrixToRow(Population,TempIndividual,i,ChromosomeLength);
 try
  {
  Fitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
  }
 catch(...)
  {
  return 0;//Генетический алгоритм не смог посчитать значение целевая функции индивида
  }
 }

//Определим наилучшего индивида и запомним его
NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(Fitness,PopulationSize);
MaximumFitness=HML_MaximumOfVector(Fitness,PopulationSize);
HML_MatrixToRow(Population,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
BestFitness=MaximumFitness;//Запоминаем его значение целевой функции

for (I=1;I<NumberOfGenerations;I++)
 {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

 //Подготовка массивов для оператора селекции
 if (TypeOfSel==1)
  {
  //Для ранговой селекции нужен массив рангов индивидов
  HML_MakeVectorOfRankForRankSelection(Fitness,Rank,PopulationSize);
  //Для ранговой селекции нужен массив вероятностей выбора индивидов из рангов
  HML_MakeVectorOfProbabilityForRanklSelection(Rank,VectorOfProbability,PopulationSize);
  }
 if (TypeOfSel==0)//Для пропорциональной нужен массив вероятностей выбора индивидов
  HML_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorOfProbability,PopulationSize);

 for (j=0;j<PopulationSize;j++)
  {//Формирование популяции потомков
  if (TypeOfSel==0)//Пропорциональная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==1)//Ранговая селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_RankSelection(VectorOfProbability,PopulationSize);
   NumberOfParent2=HML_RankSelection(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==2)//Турнирная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   NumberOfParent2=HML_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   }

  //Копируем родителей из популяции
  HML_MatrixToRow(Population,Parent1,NumberOfParent1,ChromosomeLength);//Первого родителя
  HML_MatrixToRow(Population,Parent2,NumberOfParent2,ChromosomeLength);//Второго родителя

  //Теперь путем скрещивания получаем потомка
  if (TypeOfCros==0)//Одноточечное скрещивание
   HML_SinglepointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==1)//Двухточечное скрещивание
   HML_TwopointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==2)//Равномерное скрещивание
   HML_UniformCrossover(Parent1,Parent2,Child,ChromosomeLength);

  //Переместим потомка в массив потомков
  HML_RowToMatrix(ChildrenPopulation,Child,j,ChromosomeLength);
  }//Формирование популяции потомков

 //Мутируем получившуюся популяцию потомков
 //Но вначале определим вероятность мутации
 if (TypeOfMutation==0)//Слабая
  ProbabilityOfMutation=1./(3.*double(ChromosomeLength));
 if (TypeOfMutation==1)//Средняя
  ProbabilityOfMutation=1./double(ChromosomeLength);
 if (TypeOfMutation==2)//Сильняя
  ProbabilityOfMutation=HML_Min(3./double(ChromosomeLength),1.);
 HML_MutationBinaryMatrix(ChildrenPopulation,ProbabilityOfMutation,PopulationSize,ChromosomeLength);//Мутируем

 //Вычислим значение целевой функции для каждого потомка
 for (i=0;i<PopulationSize;i++)
  {
  //Копируем потомка во временного индивида, так как целевой функция работает с вектором, а не матрицей
  HML_MatrixToRow(ChildrenPopulation,TempIndividual,i,ChromosomeLength);
  try
   {
   ChildrenFitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
   }
  catch(...)
   {
   return 0;//Генетический алгоритм не смог посчитать значение целевой функции потомка
   }
  }

 //Определим наилучшего потомка и запомним его
 MaximumFitness=HML_MaximumOfVector(ChildrenFitness,PopulationSize);

 //Является ли лучшее решение на данном поколении лучше лучшего решения за всё время работы алгоритма
 if (MaximumFitness>BestFitness)
  {
  //Если всё-таки лучше
  NumberOfMaximumFitness=HML_NumberOfMaximumOfVector(ChildrenFitness,PopulationSize);
  HML_MatrixToRow(ChildrenPopulation,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
  BestFitness=MaximumFitness;//Запоминаем его значение целевой функции
  }

 //Теперь сформируем новое поколение
 if (TypeOfForm==0)//Только потомки
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  }
 if (TypeOfForm==1)//Только потомки и копия лучшего индивида
  {
  HML_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  HML_RowToMatrix(Population,BestIndividual,0,ChromosomeLength);
  HML_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  Fitness[0]=BestFitness;
  }

 }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

//Генетический алгоритм закончил свою работу
//Выдадим найденное лучшее решение за время запуска алгоритма и его значение целевой функции
HML_VectorToVector(BestIndividual,VHML_ResultVector,ChromosomeLength);
*VHML_Result=BestFitness;

//Удалим все дополнительные массивы
for (i=0;i<PopulationSize;i++) delete [] Population[i];
 delete [] Population;
for (i=0;i<PopulationSize;i++) delete [] ChildrenPopulation[i];
 delete [] ChildrenPopulation;
delete [] Fitness;
delete [] ChildrenFitness;
delete [] TempIndividual;
delete [] BestIndividual;
delete [] VectorOfProbability;
delete [] Rank;
delete [] Taken;
delete [] Parent1;
delete [] Parent2;
delete [] Child;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_RealGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result)
{
/*
Генетический алгоритм для решения задач на вещественных строках  с турнирной селекцией с возвращением, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но и она измененная, и размер турнира может изменяться.
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Тип алгоритма: добавочный алгоритм оптимизации.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина вещественной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - размер турнирной селекции с возвращением (SizeOfTournament): от 2 до sqrt(CountOfFitness);
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида)
  [6] - тип преобразования задачи вещественной оптимизации в задачу бинарной оптимизации (TypeOfConverting);
        0 - IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации);
        1 - GrayСodeConverting (Стандартный рефлексивный Грей-код).
 NumberOfParts - указатель на массив: на сколько частей делить каждую вещественную координату при дискретизации (размерность Parameters[0]);
  Желательно брать по формуле NumberOfParts[i]=(2^k)-1, где k - натуральное число, например, 12.
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (вещественный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=2;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0;
*/
//Переменные
int i;//Счетчик
int ChromosomeLength;//Длина бинарной строки
int VHML_Success;//Успешен ли будет запуск cГА на бинарных строках

//Считываем из Parameters необходимые параметры алгоритма
int RealLength=Parameters[0];//Размерность вещественного вектора
int TypOfConverting=Parameters[6];//Тип преобразования задачи в бинарную задачу оптимизацию

//Проверим данные
for (i=0;i<RealLength;i++) if (Left[i]>Right[i]) return 0;//Левая граница не может быть больше правой
for (i=0;i<RealLength;i++) if (NumberOfParts[i]<1) return 0;//На слишком мало частей предложено делить каждую координату
if (!((TypOfConverting==0)||(TypOfConverting==1))) return 0;//Тип преобразования указан не верно

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Массив значений, сколько бит приходится в бинарной хромосоме на кодирование
//каждой вещественной координаты
int *Lengthi;
Lengthi=new int[RealLength];
//Параметры стандартного генетического алгоритма на бинарных строках
double *ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn;
//Указатель на массив, в который записываются решения при вычислении целевой функции
double *RealVector;
RealVector=new double[RealLength];

//Процесс преобразования задачи вещественной оптимизации в задачу бинарной оптимизации
//Определим длину бинарной хромосомы. При этом число точек для кодирования на одну больше, чем интервалов,
//на которые мы хотим разбить каждую вещественную координату.
for (int i=0;i<RealLength;i++)
 Lengthi[i]=HML_HowManyPowersOfTwo(NumberOfParts[i]+1);

ChromosomeLength=HML_SumVector(Lengthi,RealLength);//Просуммируем элементы вектора

//Бинарное решение бинарной задачи оптимизации
int *BinaryDecision;
BinaryDecision=new int[ChromosomeLength];

//Создадим еще один массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную
int *TempBinaryVector;
TempBinaryVector=new int[ChromosomeLength];//GrayСodeConverting (Стандартный рефлексивный Грей-код)

//Определим параметры стандартного генетического алгоритма на бинарных строках
ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn=new double[6];
ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn[0]=ChromosomeLength;//Длина хромосомы
ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn[1]=Parameters[1];//Число вычислений целевой функции
ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn[2]=Parameters[2];//Размер турнира
ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn[3]=Parameters[3];//Тип скрещивания
ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn[4]=Parameters[4];//Тип мутации
ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn[5]=Parameters[5];//Тип формирования нового поколения

//сГА на бинарных строках работает с функцией типа double (*)(int*,int)
//то есть в качестве входных параметров только решение и его размерность
//но для вычисления значения целевой функции еще требуются дополнительные переменные
//целевая функция для вещественного решения и так далее.
//Делаем их доступными, используя служебные дополнительные указатели библиотеки
VHML_TempFunction=FitnessFunction;//указатель на целевая функция для вещественного решения
VHML_TempInt1=Lengthi;//указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование
VHML_TempDouble1=Left;//указатель на массив левых границ изменения вещественной переменной
VHML_TempDouble2=Right;//указатель на массив правых границ изменения вещественной переменной
VHML_TempDouble3=RealVector;//указатель на массив, в котором можно сохранить вещественный индивид
//при его раскодировании из бинарной строки
VHML_TempInt2=&RealLength;//указатель на размерность вещественного вектора
VHML_TempInt3=&TypOfConverting;//указатель на тип преобразования
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=TempBinaryVector;//массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную

//Выполнение стандартного генетического алгоритма на бинарных строках
try
 {
 //Выполнение стандартного генетического алгоритма на бинарных строках
 VHML_Success=HML_BinaryGeneticAlgorithmTournamentSelectionWithReturn(ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn,HML_BinaryFitnessFunction,BinaryDecision,VHML_Result);
 }
catch(...)
 {
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками
 }

if (VHML_Success==1)
 {
 //VHML_Result уже записан и определен, а вот VHML_ResultVector (конечное решение) еще нет
 //так как есть только бинарное решение, а не вещественное, которое нам и нужно

 //Преобразование бинарного решения в вещественное
 if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
  HML_BinaryVectorToRealVector(BinaryDecision,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
  HML_BinaryGrayVectorToRealVector(BinaryDecision,ChromosomeLength,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 }
else
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками, но не в результате генерирования исключений

//Удалим массивы для запуска стандартного генетического алгоритма на бинарных строках
delete [] ParametersOfBinaryGeneticAlgorithmTournamentSelectionWithReturn;
delete [] Lengthi;
delete [] BinaryDecision;
delete [] RealVector;
delete [] TempBinaryVector;

//Обнулим дополнительные указатели
VHML_TempFunction=NULL;
VHML_TempInt1=NULL;
VHML_TempDouble1=NULL;
VHML_TempDouble2=NULL;
VHML_TempInt2=NULL;
VHML_TempDouble3=NULL;
VHML_TempInt3=NULL;
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=NULL;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_RealGeneticAlgorithmTwiceGenerations(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result)
{
    /*
Генетический алгоритм с двойным количеством поколений для решения задач на вещественных строках.
На четных поколениях целевая функция высчитывается как среднеарифметическое родителей.
https://github.com/Harrix/HarrixOptimizationAlgorithms
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина вещественной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида)
  [6] - тип преобразования задачи вещественной оптимизации в задачу бинарной оптимизации (TypeOfConverting);
        0 - IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации);
        1 - GrayСodeConverting (Стандартный рефлексивный Грей-код).
 NumberOfParts - указатель на массив: на сколько частей делить каждую вещественную координату при дискретизации (размерность Parameters[0]);
  Желательно брать по формуле NumberOfParts[i]=(2^k)-1, где k - натуральное число, например, 12.
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (вещественный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=2;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0;
*/
    //Переменные
    int i;//Счетчик
    int ChromosomeLength;//Длина бинарной строки
    int VHML_Success;//Успешен ли будет запуск cГА на бинарных строках

    //Считываем из Parameters необходимые параметры алгоритма
    int RealLength=Parameters[0];//Размерность вещественного вектора
    int TypOfConverting=Parameters[6];//Тип преобразования задачи в бинарную задачу оптимизацию

    //Проверим данные
    for (i=0;i<RealLength;i++) if (Left[i]>Right[i]) return 0;//Левая граница не может быть больше правой
    for (i=0;i<RealLength;i++) if (NumberOfParts[i]<1) return 0;//На слишком мало частей предложено делить каждую координату
    if (!((TypOfConverting==0)||(TypOfConverting==1))) return 0;//Тип преобразования указан не верно

    //Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
    //Массив значений, сколько бит приходится в бинарной хромосоме на кодирование
    //каждой вещественной координаты
    int *Lengthi;
    Lengthi=new int[RealLength];
    //Параметры стандартного генетического алгоритма на бинарных строках
    int *ParametersOfAlgorithm;
    //Указатель на массив, в который записываются решения при вычислении целевой функции
    double *RealVector;
    RealVector=new double[RealLength];

    //Процесс преобразования задачи вещественной оптимизации в задачу бинарной оптимизации
    //Определим длину бинарной хромосомы. При этом число точек для кодирования на одну больше, чем интервалов,
    //на которые мы хотим разбить каждую вещественную координату.
    for (int i=0;i<RealLength;i++)
        Lengthi[i]=HML_HowManyPowersOfTwo(NumberOfParts[i]+1);

    ChromosomeLength=HML_SumVector(Lengthi,RealLength);//Просуммируем элементы вектора

    //Бинарное решение бинарной задачи оптимизации
    int *BinaryDecision;
    BinaryDecision=new int[ChromosomeLength];

    //Создадим еще один массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную
    int *TempBinaryVector;
    TempBinaryVector=new int[ChromosomeLength];//GrayСodeConverting (Стандартный рефлексивный Грей-код)

    //Определим параметры стандартного генетического алгоритма на бинарных строках
    ParametersOfAlgorithm=new int[6];
    ParametersOfAlgorithm[0]=ChromosomeLength;//Длина хромосомы
    ParametersOfAlgorithm[1]=Parameters[1];//Число вычислений целевой функции
    ParametersOfAlgorithm[2]=Parameters[2];//Тип селекции
    ParametersOfAlgorithm[3]=Parameters[3];//Тип скрещивания
    ParametersOfAlgorithm[4]=Parameters[4];//Тип мутации
    ParametersOfAlgorithm[5]=Parameters[5];//Тип формирования нового поколения

    //сГА на бинарных строках работает с функцией типа double (*)(int*,int)
    //то есть в качестве входных параметров только решение и его размерность
    //но для вычисления значения целевой функции еще требуются дополнительные переменные
    //целевая функция для вещественного решения и так далее.
    //Делаем их доступными, используя служебные дополнительные указатели библиотеки
    VHML_TempFunction=FitnessFunction;//указатель на целевая функция для вещественного решения
    VHML_TempInt1=Lengthi;//указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование
    VHML_TempDouble1=Left;//указатель на массив левых границ изменения вещественной переменной
    VHML_TempDouble2=Right;//указатель на массив правых границ изменения вещественной переменной
    VHML_TempDouble3=RealVector;//указатель на массив, в котором можно сохранить вещественный индивид
    //при его раскодировании из бинарной строки
    VHML_TempInt2=&RealLength;//указатель на размерность вещественного вектора
    VHML_TempInt3=&TypOfConverting;//указатель на тип преобразования
    if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
        VHML_TempInt4=TempBinaryVector;//массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную

    //Выполнение стандартного генетического алгоритма на бинарных строках
    try
    {
        //Выполнение стандартного генетического алгоритма на бинарных строках
        VHML_Success=HML_BinaryGeneticAlgorithmTwiceGenerations(ParametersOfAlgorithm,HML_BinaryFitnessFunction,BinaryDecision,VHML_Result);
    }
    catch(...)
    {
        return 0;//Генетический алгоритм на бинарных строках завершился с ошибками
    }

    if (VHML_Success==1)
    {
        //VHML_Result уже записан и определен, а вот VHML_ResultVector (конечное решение) еще нет
        //так как есть только бинарное решение, а не вещественное, которое нам и нужно

        //Преобразование бинарного решения в вещественное
        if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
            HML_BinaryVectorToRealVector(BinaryDecision,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
        if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
            HML_BinaryGrayVectorToRealVector(BinaryDecision,ChromosomeLength,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
    }
    else
        return 0;//Генетический алгоритм на бинарных строках завершился с ошибками, но не в результате генерирования исключений

    //Удалим массивы для запуска стандартного генетического алгоритма на бинарных строках
    delete [] ParametersOfAlgorithm;
    delete [] Lengthi;
    delete [] BinaryDecision;
    delete [] RealVector;
    delete [] TempBinaryVector;

    //Обнулим дополнительные указатели
    VHML_TempFunction=NULL;
    VHML_TempInt1=NULL;
    VHML_TempDouble1=NULL;
    VHML_TempDouble2=NULL;
    VHML_TempInt2=NULL;
    VHML_TempDouble3=NULL;
    VHML_TempInt3=NULL;
    if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
        VHML_TempInt4=NULL;

    return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_RealGeneticAlgorithmWCC(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result)
{
/*
Генетический алгоритм для решения задач на вещественных строках, в котором есть только два вида скрещивания: одноточечное и двухточечное скрещивание с возможностью полного копирования одного из родителей. Равномерное скрещивание отсутствует.
Исследовательский алгоритм оптимизации.
https://github.com/Harrix/HarrixOptimizationAlgorithms
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина вещественной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossoverWithCopying (Одноточечное скрещивание с возможностью полного копирования одного из родителей);
        1 - TwopointCrossoverWithCopying (Двухточечное скрещивание с возможностью полного копирования одного из родителей).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида)
  [6] - тип преобразования задачи вещественной оптимизации в задачу бинарной оптимизации (TypeOfConverting);
        0 - IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации);
        1 - GrayСodeConverting (Стандартный рефлексивный Грей-код).
 NumberOfParts - указатель на массив: на сколько частей делить каждую вещественную координату при дискретизации (размерность Parameters[0]);
  Желательно брать по формуле NumberOfParts[i]=(2^k)-1, где k - натуральное число, например, 12.
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (вещественный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=2;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=0;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0;
*/
//Переменные
int i;//Счетчик
int ChromosomeLength;//Длина бинарной строки
int VHML_Success;//Успешен ли будет запуск cГА на бинарных строках

//Считываем из Parameters необходимые параметры алгоритма
int RealLength=Parameters[0];//Размерность вещественного вектора
int TypOfConverting=Parameters[6];//Тип преобразования задачи в бинарную задачу оптимизацию

//Проверим данные
for (i=0;i<RealLength;i++) if (Left[i]>Right[i]) return 0;//Левая граница не может быть больше правой
for (i=0;i<RealLength;i++) if (NumberOfParts[i]<1) return 0;//На слишком мало частей предложено делить каждую координату
if (!((TypOfConverting==0)||(TypOfConverting==1))) return 0;//Тип преобразования указан не верно

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Массив значений, сколько бит приходится в бинарной хромосоме на кодирование
//каждой вещественной координаты
int *Lengthi;
Lengthi=new int[RealLength];
//Параметры стандартного генетического алгоритма на бинарных строках
int *ParametersOfBinaryGeneticAlgorithmWCC;
//Указатель на массив, в который записываются решения при вычислении целевой функции
double *RealVector;
RealVector=new double[RealLength];

//Процесс преобразования задачи вещественной оптимизации в задачу бинарной оптимизации
//Определим длину бинарной хромосомы. При этом число точек для кодирования на одну больше, чем интервалов,
//на которые мы хотим разбить каждую вещественную координату.
for (int i=0;i<RealLength;i++)
 Lengthi[i]=HML_HowManyPowersOfTwo(NumberOfParts[i]+1);

ChromosomeLength=HML_SumVector(Lengthi,RealLength);//Просуммируем элементы вектора

//Бинарное решение бинарной задачи оптимизации
int *BinaryDecision;
BinaryDecision=new int[ChromosomeLength];

//Создадим еще один массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную
int *TempBinaryVector;
TempBinaryVector=new int[ChromosomeLength];//GrayСodeConverting (Стандартный рефлексивный Грей-код)

//Определим параметры стандартного генетического алгоритма на бинарных строках
ParametersOfBinaryGeneticAlgorithmWCC=new int[6];
ParametersOfBinaryGeneticAlgorithmWCC[0]=ChromosomeLength;//Длина хромосомы
ParametersOfBinaryGeneticAlgorithmWCC[1]=Parameters[1];//Число вычислений целевой функции
ParametersOfBinaryGeneticAlgorithmWCC[2]=Parameters[2];//Тип селекции
ParametersOfBinaryGeneticAlgorithmWCC[3]=Parameters[3];//Тип скрещивания
ParametersOfBinaryGeneticAlgorithmWCC[4]=Parameters[4];//Тип мутации
ParametersOfBinaryGeneticAlgorithmWCC[5]=Parameters[5];//Тип формирования нового поколения

//сГА на бинарных строках работает с функцией типа double (*)(int*,int)
//то есть в качестве входных параметров только решение и его размерность
//но для вычисления значения целевой функции еще требуются дополнительные переменные
//целевая функция для вещественного решения и так далее.
//Делаем их доступными, используя служебные дополнительные указатели библиотеки
VHML_TempFunction=FitnessFunction;//указатель на целевая функция для вещественного решения
VHML_TempInt1=Lengthi;//указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование
VHML_TempDouble1=Left;//указатель на массив левых границ изменения вещественной переменной
VHML_TempDouble2=Right;//указатель на массив правых границ изменения вещественной переменной
VHML_TempDouble3=RealVector;//указатель на массив, в котором можно сохранить вещественный индивид
//при его раскодировании из бинарной строки
VHML_TempInt2=&RealLength;//указатель на размерность вещественного вектора
VHML_TempInt3=&TypOfConverting;//указатель на тип преобразования
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=TempBinaryVector;//массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную

//Выполнение стандартного генетического алгоритма на бинарных строках
try
 {
 //Выполнение стандартного генетического алгоритма на бинарных строках
 VHML_Success=HML_BinaryGeneticAlgorithmWCC(ParametersOfBinaryGeneticAlgorithmWCC,HML_BinaryFitnessFunction,BinaryDecision,VHML_Result);
 }
catch(...)
 {
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками
 }

if (VHML_Success==1)
 {
 //VHML_Result уже записан и определен, а вот VHML_ResultVector (конечное решение) еще нет
 //так как есть только бинарное решение, а не вещественное, которое нам и нужно

 //Преобразование бинарного решения в вещественное
 if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
  HML_BinaryVectorToRealVector(BinaryDecision,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
  HML_BinaryGrayVectorToRealVector(BinaryDecision,ChromosomeLength,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 }
else
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками, но не в результате генерирования исключений

//Удалим массивы для запуска стандартного генетического алгоритма на бинарных строках
delete [] ParametersOfBinaryGeneticAlgorithmWCC;
delete [] Lengthi;
delete [] BinaryDecision;
delete [] RealVector;
delete [] TempBinaryVector;

//Обнулим дополнительные указатели
VHML_TempFunction=NULL;
VHML_TempInt1=NULL;
VHML_TempDouble1=NULL;
VHML_TempDouble2=NULL;
VHML_TempInt2=NULL;
VHML_TempDouble3=NULL;
VHML_TempInt3=NULL;
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=NULL;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_RealGeneticAlgorithmWDPOfNOfGPS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result)
{
/*
Генетический алгоритм для решения задач на вещественных строках с изменяющимся соотношением числа поколений и размера популяции.
Отличается от стандартного генетического алгоритма, тем, что размер популяции и число поколений рассчитывается
из числа вычислений целевой функции не как одинаковые величины (извлечение квадратного корня), а через некоторое соотношение.
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Тип алгоритма: исследовательский алгоритм оптимизации.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина вещественной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида)
  [6] - тип преобразования задачи вещественной оптимизации в задачу бинарной оптимизации (TypeOfConverting);
        0 - IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации);
        1 - GrayСodeConverting (Стандартный рефлексивный Грей-код).
  [7] - "доля" (Proportion) числа поколений от общего числа вычислений целевой функции.
        Определяется как возведение числа вычислений целевой функции в степень Proportion.
        Может принимать значения в интервале [0;1].
        Число поколений = int(CountOfFitness^Proportion).
        Размер популяции = int(CountOfFitness/Число поколений).
        При Proportion=0.5 получим обычный стандартный генетический алгоритм.
        Чем меньше Proportion, тем меньше число поколений будет.
 NumberOfParts - указатель на массив: на сколько частей делить каждую вещественную координату при дискретизации (размерность Parameters[0]);
  Желательно брать по формуле NumberOfParts[i]=(2^k)-1, где k - натуральное число, например, 12.
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (вещественный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=2;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0;
 Parameters[7]=0.5;
*/
//Переменные
int i;//Счетчик
int ChromosomeLength;//Длина бинарной строки
int VHML_Success;//Успешен ли будет запуск cГА на бинарных строках

//Считываем из Parameters необходимые параметры алгоритма
int RealLength=Parameters[0];//Размерность вещественного вектора
int TypOfConverting=Parameters[6];//Тип преобразования задачи в бинарную задачу оптимизацию

//Проверим данные
for (i=0;i<RealLength;i++) if (Left[i]>Right[i]) return 0;//Левая граница не может быть больше правой
for (i=0;i<RealLength;i++) if (NumberOfParts[i]<1) return 0;//На слишком мало частей предложено делить каждую координату
if (!((TypOfConverting==0)||(TypOfConverting==1))) return 0;//Тип преобразования указан не верно

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Массив значений, сколько бит приходится в бинарной хромосоме на кодирование
//каждой вещественной координаты
int *Lengthi;
Lengthi=new int[RealLength];
//Параметры стандартного генетического алгоритма на бинарных строках
double *ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS;
//Указатель на массив, в который записываются решения при вычислении целевой функции
double *RealVector;
RealVector=new double[RealLength];

//Процесс преобразования задачи вещественной оптимизации в задачу бинарной оптимизации
//Определим длину бинарной хромосомы. При этом число точек для кодирования на одну больше, чем интервалов,
//на которые мы хотим разбить каждую вещественную координату.
for (int i=0;i<RealLength;i++)
 Lengthi[i]=HML_HowManyPowersOfTwo(NumberOfParts[i]+1);

ChromosomeLength=HML_SumVector(Lengthi,RealLength);//Просуммируем элементы вектора

//Бинарное решение бинарной задачи оптимизации
int *BinaryDecision;
BinaryDecision=new int[ChromosomeLength];

//Создадим еще один массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную
int *TempBinaryVector;
TempBinaryVector=new int[ChromosomeLength];//GrayСodeConverting (Стандартный рефлексивный Грей-код)

//Определим параметры стандартного генетического алгоритма на бинарных строках
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS=new double[7];
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[0]=ChromosomeLength;//Длина хромосомы
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[1]=Parameters[1];//Число вычислений целевой функции
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[2]=Parameters[2];//Тип селекции
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[3]=Parameters[3];//Тип скрещивания
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[4]=Parameters[4];//Тип мутации
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[5]=Parameters[5];//Тип формирования нового поколения
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[6]=Parameters[7];//"доля" числа поколений

//сГА на бинарных строках работает с функцией типа double (*)(int*,int)
//то есть в качестве входных параметров только решение и его размерность
//но для вычисления значения целевой функции еще требуются дополнительные переменные
//целевая функция для вещественного решения и так далее.
//Делаем их доступными, используя служебные дополнительные указатели библиотеки
VHML_TempFunction=FitnessFunction;//указатель на целевая функция для вещественного решения
VHML_TempInt1=Lengthi;//указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование
VHML_TempDouble1=Left;//указатель на массив левых границ изменения вещественной переменной
VHML_TempDouble2=Right;//указатель на массив правых границ изменения вещественной переменной
VHML_TempDouble3=RealVector;//указатель на массив, в котором можно сохранить вещественный индивид
//при его раскодировании из бинарной строки
VHML_TempInt2=&RealLength;//указатель на размерность вещественного вектора
VHML_TempInt3=&TypOfConverting;//указатель на тип преобразования
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=TempBinaryVector;//массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную

//Выполнение стандартного генетического алгоритма на бинарных строках
try
 {
 //Выполнение стандартного генетического алгоритма на бинарных строках
 VHML_Success=HML_BinaryGeneticAlgorithmWDPOfNOfGPS(ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS,HML_BinaryFitnessFunction,BinaryDecision,VHML_Result);
 }
catch(...)
 {
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками
 }

if (VHML_Success==1)
 {
 //VHML_Result уже записан и определен, а вот VHML_ResultVector (конечное решение) еще нет
 //так как есть только бинарное решение, а не вещественное, которое нам и нужно

 //Преобразование бинарного решения в вещественное
 if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
  HML_BinaryVectorToRealVector(BinaryDecision,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
  HML_BinaryGrayVectorToRealVector(BinaryDecision,ChromosomeLength,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 }
else
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками, но не в результате генерирования исключений

//Удалим массивы для запуска стандартного генетического алгоритма на бинарных строках
delete [] ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS;
delete [] Lengthi;
delete [] BinaryDecision;
delete [] RealVector;
delete [] TempBinaryVector;

//Обнулим дополнительные указатели
VHML_TempFunction=NULL;
VHML_TempInt1=NULL;
VHML_TempDouble1=NULL;
VHML_TempDouble2=NULL;
VHML_TempInt2=NULL;
VHML_TempDouble3=NULL;
VHML_TempInt3=NULL;
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=NULL;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------

int HML_RealGeneticAlgorithmWDTS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result)
{
/*
Генетический алгоритм для решения задач на вещественных строках  с турнирной селекцией, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но размер турнира может изменяться.
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Тип алгоритма: добавочный алгоритм оптимизации.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина вещественной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - размер турнирной селекции (SizeOfTournament): от 2 до sqrt(CountOfFitness);
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двухточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида)
  [6] - тип преобразования задачи вещественной оптимизации в задачу бинарной оптимизации (TypeOfConverting);
        0 - IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации);
        1 - GrayСodeConverting (Стандартный рефлексивный Грей-код).
 NumberOfParts - указатель на массив: на сколько частей делить каждую вещественную координату при дискретизации (размерность Parameters[0]);
  Желательно брать по формуле NumberOfParts[i]=(2^k)-1, где k - натуральное число, например, 12.
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VHML_ResultVector - найденное решение (вещественный вектор);
 VHML_Result - значение целевой функции в точке, определенной вектором VHML_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VHML_ResultVector и в VHML_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=2;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0;
*/
//Переменные
int i;//Счетчик
int ChromosomeLength;//Длина бинарной строки
int VHML_Success;//Успешен ли будет запуск cГА на бинарных строках

//Считываем из Parameters необходимые параметры алгоритма
int RealLength=Parameters[0];//Размерность вещественного вектора
int TypOfConverting=Parameters[6];//Тип преобразования задачи в бинарную задачу оптимизацию

//Проверим данные
for (i=0;i<RealLength;i++) if (Left[i]>Right[i]) return 0;//Левая граница не может быть больше правой
for (i=0;i<RealLength;i++) if (NumberOfParts[i]<1) return 0;//На слишком мало частей предложено делить каждую координату
if (!((TypOfConverting==0)||(TypOfConverting==1))) return 0;//Тип преобразования указан не верно

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Массив значений, сколько бит приходится в бинарной хромосоме на кодирование
//каждой вещественной координаты
int *Lengthi;
Lengthi=new int[RealLength];
//Параметры стандартного генетического алгоритма на бинарных строках
double *ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS;
//Указатель на массив, в который записываются решения при вычислении целевой функции
double *RealVector;
RealVector=new double[RealLength];

//Процесс преобразования задачи вещественной оптимизации в задачу бинарной оптимизации
//Определим длину бинарной хромосомы. При этом число точек для кодирования на одну больше, чем интервалов,
//на которые мы хотим разбить каждую вещественную координату.
for (int i=0;i<RealLength;i++)
 Lengthi[i]=HML_HowManyPowersOfTwo(NumberOfParts[i]+1);

ChromosomeLength=HML_SumVector(Lengthi,RealLength);//Просуммируем элементы вектора

//Бинарное решение бинарной задачи оптимизации
int *BinaryDecision;
BinaryDecision=new int[ChromosomeLength];

//Создадим еще один массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную
int *TempBinaryVector;
TempBinaryVector=new int[ChromosomeLength];//GrayСodeConverting (Стандартный рефлексивный Грей-код)

//Определим параметры стандартного генетического алгоритма на бинарных строках
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS=new double[6];
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[0]=ChromosomeLength;//Длина хромосомы
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[1]=Parameters[1];//Число вычислений целевой функции
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[2]=Parameters[2];//Размер турнира
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[3]=Parameters[3];//Тип скрещивания
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[4]=Parameters[4];//Тип мутации
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[5]=Parameters[5];//Тип формирования нового поколения

//сГА на бинарных строках работает с функцией типа double (*)(int*,int)
//то есть в качестве входных параметров только решение и его размерность
//но для вычисления значения целевой функции еще требуются дополнительные переменные
//целевая функция для вещественного решения и так далее.
//Делаем их доступными, используя служебные дополнительные указатели библиотеки
VHML_TempFunction=FitnessFunction;//указатель на целевая функция для вещественного решения
VHML_TempInt1=Lengthi;//указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование
VHML_TempDouble1=Left;//указатель на массив левых границ изменения вещественной переменной
VHML_TempDouble2=Right;//указатель на массив правых границ изменения вещественной переменной
VHML_TempDouble3=RealVector;//указатель на массив, в котором можно сохранить вещественный индивид
//при его раскодировании из бинарной строки
VHML_TempInt2=&RealLength;//указатель на размерность вещественного вектора
VHML_TempInt3=&TypOfConverting;//указатель на тип преобразования
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=TempBinaryVector;//массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную

//Выполнение стандартного генетического алгоритма на бинарных строках
try
 {
 //Выполнение стандартного генетического алгоритма на бинарных строках
 VHML_Success=HML_BinaryGeneticAlgorithmWDTS(ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS,HML_BinaryFitnessFunction,BinaryDecision,VHML_Result);
 }
catch(...)
 {
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками
 }

if (VHML_Success==1)
 {
 //VHML_Result уже записан и определен, а вот VHML_ResultVector (конечное решение) еще нет
 //так как есть только бинарное решение, а не вещественное, которое нам и нужно

 //Преобразование бинарного решения в вещественное
 if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
  HML_BinaryVectorToRealVector(BinaryDecision,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
  HML_BinaryGrayVectorToRealVector(BinaryDecision,ChromosomeLength,VHML_ResultVector,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);
 }
else
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками, но не в результате генерирования исключений

//Удалим массивы для запуска стандартного генетического алгоритма на бинарных строках
delete [] ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS;
delete [] Lengthi;
delete [] BinaryDecision;
delete [] RealVector;
delete [] TempBinaryVector;

//Обнулим дополнительные указатели
VHML_TempFunction=NULL;
VHML_TempInt1=NULL;
VHML_TempDouble1=NULL;
VHML_TempDouble2=NULL;
VHML_TempInt2=NULL;
VHML_TempDouble3=NULL;
VHML_TempInt3=NULL;
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VHML_TempInt4=NULL;

return 1;//Всё успешно
}
//---------------------------------------------------------------------------


//*****************************************************************
//Перевод единиц измерений
//*****************************************************************
double HML_DegToRad(double VHML_X)
{
/*
Функция переводит угол из градусной меры в радианную.
Входные параметры:
 VHML_X - градусная мера угла.
Возвращаемое значение:
 Радианная мера угла.
*/
return (HML_PI*VHML_X)/180.;
}
//---------------------------------------------------------------------------

double HML_RadToDeg(double VHML_X)
{
/*
Функция переводит угол из радианной меры в градусную.
Входные параметры:
 VHML_X - радианная мера угла.
Возвращаемое значение:
 Градусная мера угла.
*/
return (180.*VHML_X)/HML_PI;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Случайные объекты
//*****************************************************************
int HML_BitNumber(double P)
{
/*
Функция с вероятностью P возвращает 1. В противном случае возвращает 0.
Входные параметры:
 P - вероятность появления 1.
Возвращаемое значение:
 1 или 0.
*/
if (HML_RandomNumber()<=P)
 return 1;
else
 return 0;
}
//---------------------------------------------------------------------------
int HML_BitNumber()
{
/*
Функция с вероятностью 0.5 возвращает 1. В противном случае возвращает 0.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 1 или 0.
*/
if (HML_RandomNumber()<=0.5)
 return 1;
else
 return 0;
}
//---------------------------------------------------------------------------

void HML_RandomRealMatrix(double **VHML_ResultMatrix, double Left, double Right, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными вещественными числами из определенного интервала [Left;Right].
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 Left - левая граница интервала;
 Right - правая граница интервала;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    for (int j=0;j<VHML_M;j++)
        VHML_ResultMatrix[i][j]=HML_RandomUniform(Left,Right);
}
//---------------------------------------------------------------------------

void HML_RandomRealMatrixInCols(double **VHML_ResultMatrix, double *Left, double *Right, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными вещественными числами из определенного интервала.
При этом элементы каждого столбца изменяются в своих пределах.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 Left - левые границы интервала изменения элементов столбцов (размер VHML_M);
 Right - правые границы интервала изменения элементов столбцов (размер VHML_M);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniform(Left[j],Right[j]);
}
//---------------------------------------------------------------------------

void HML_RandomRealMatrixInElements(double **VHML_ResultMatrix, double **Left, double **Right, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными вещественными числами из определенного интервала.
При этом каждый элемент изменяется в своих пределах.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 Left - левые границы интервала изменения каждого элемента (размер VHML_N x VHML_M);
 Right - правые границы интервала изменения каждого элемента (размер VHML_N x VHML_M);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniform(Left[i][j],Right[i][j]);
}

//---------------------------------------------------------------------------

void HML_RandomRealMatrixInRows(double **VHML_ResultMatrix, double *Left, double *Right, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными вещественными числами из определенного интервала.
При этом элементы каждой строки изменяются в своих пределах.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 Left - левые границы интервала изменения элементов строки (размер VHML_N);
 Right - правые границы интервала изменения элементов строки (размер VHML_N);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniform(Left[i],Right[i]);
}
//---------------------------------------------------------------------------

void HML_RandomRealVector(double *VHML_ResultVector, double Left, double Right, int VHML_N)
{
/*
Функция заполняет массив случайными вещественными числами из определенного интервала [Left;Right].
Входные параметры:
 VHML_ResultVector - указатель на массив;
 Left - левая граница интервала;
 Right - правая граница интервала;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomUniform(Left,Right);
}
//---------------------------------------------------------------------------

void HML_RandomRealVectorInElements(double *VHML_ResultVector, double *Left, double *Right, int VHML_N)
{
/*
Функция заполняет массив случайными вещественными числами из определенного интервала, где на каждую координату свои границы изменения.
Входные параметры:
 VHML_ResultVector - указатель на массив;
 Left - левые границы интервалов (размер VHML_N);
 Right - правые границы интервалов (размер VHML_N)
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomUniform(Left[i],Right[i]);
}
//---------------------------------------------------------------------------

void HML_RandomVectorOfProbability(double *VHML_ResultVector, int VHML_N)
{
/*
Функция заполняет вектор случайными значениями вероятностей. Сумма всех элементов вектора равна 1.
Входные параметры:
 VHML_ResultVector - указатель на вектор вероятностей (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomNumber();
//Вычислим сумму вектора
double sum=HML_SumVector(VHML_ResultVector,VHML_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1./double(VHML_N);
 }
else
 {
 //Нормализуем
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]/=sum;
 }
}
//---------------------------------------------------------------------------


//*****************************************************************
//Случайные числа
//*****************************************************************
double HML_RandomNormal(double Mean, double StdDev)
{
/*
Случайное число по нормальному закону распределения.
Входные параметры:
 Mean - математическое ожидание;
 StdDev - среднеквадратичное отклонение.
Возвращаемое значение:
 Случайное число по нормальному закону.
*/
double VHML_Result,
s=0.449871,
t=-0.386595,
a=0.19600,
b=0.25472,
r1=0.27597,
r2=0.27846;
double u,v,x,y,q;
bool B;
B=false;
do
 {
 u=HML_RandomNumber();
 v=HML_RandomNumber();
 v=1.7156*(v-0.5);
 x=u-s;
 y=fabs(v)-t;
 q=x*x+y*(a*y-b*x);
 if (q<r1)
  B=true;
 else
  if ((q<=r2)&&(v*v<-4.0*log(u)*u*u))
   B=true;
 }
while (B!=true);
if (u==0) return Mean;
VHML_Result=v/u;
VHML_Result=VHML_Result*StdDev+Mean;
return VHML_Result;
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_RandomUniform(double a, double b)
{
/*
Случайное вещественное число в интервале [a;b] по равномерному закону распределения.
Входные параметры:
 a - левая граница;
 b - правая граница.
Возвращаемое значение:
 Случайное вещественное число в интервале [a;b].
*/
return (a+HML_RandomNumber()*(b-a));
}
//---------------------------------------------------------------------------

int HML_RandomUniformInt(int n, int m)
{
/*
Случайное целое число в интервале [n,m) по равномерному закону распределения.
Входные параметры:
 n - левая граница;
 m - правая граница.
Возвращаемое значение:
 Случайное целое число от n до m-1 включительно.
*/
int VHML_Result;
VHML_Result=n+int(HML_RandomNumber()*(m-n));
if (VHML_Result==m) VHML_Result=m-1;
return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_RandomUniformIntIncluding(int n, int m)
{
/*
Случайное целое число в интервале [n,m] по равномерному закону распределения.
Входные параметры:
 n - левая граница;
 m - правая граница.
Возвращаемое значение:
 Случайное целое число от n до m включительно.
Примечание:
 В отличии от функции HML_RandomUniformInt правая граница тоже включается, то есть может сгенерироваться m, а не m-1.
*/
int VHML_Result;
VHML_Result=n+int(HML_RandomNumber()*(m+1-n));
if (VHML_Result==m+1) VHML_Result=m+1-1;
return VHML_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Сортировка
//*****************************************************************

//*****************************************************************
//Статистика и теория вероятности
//*****************************************************************
double HML_DensityOfDistributionOfNormalizedCenteredNormalDistribution(double x)
{
/*
Плотность распределения вероятности нормированного и центрированного нормального распределения.
Входные параметры:
 x - входная переменная.
Возвращаемое значение:
 Значение функции в точке.
*/
return ((1./sqrt(2.*HML_PI))*HML_ExpMSxD2(x));
}
//---------------------------------------------------------------------------

double HML_DistributionFunctionOfNormalDistribution(double x, double mu, double sigma, double Epsilon)
{
/*
Функция распределения нормального распределения.
Входные параметры:
 x - входная переменная (правая граница интегрирования);
 mu - математическое ожидание;
 sigma - стандартное отклонение (sigma>0);
 Epsilon - погрешность (например, Epsilon = 0.00001 - больше не берите, а то будет большая погрешность).
Возвращаемое значение:
 Значение функции в точке.
*/
    double VHML_Result=0;

    if (sigma>0)
        VHML_Result = HML_DistributionFunctionOfNormalizedCenteredNormalDistribution((x-mu)/sigma,Epsilon);

    return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_DistributionFunctionOfNormalizedCenteredNormalDistribution(double x, double Epsilon)
{
/*
Функция распределения нормированного и центрированного нормального распределения.
Входные параметры:
 x - входная переменная (правая граница интегрирования);
 Epsilon - погрешность (например, Epsilon = 0.00001 - больше не берите, а то будет большая погрешность).
Возвращаемое значение:
 Значение функции в точке.
*/
    double VHML_Result=0;

    if (x<0)
    {
        VHML_Result = 1 - (((1./sqrt(2.*HML_PI))*HML_IntegralOfSimpson(0,-x,Epsilon,HML_ExpMSxD2))+0.5);
    }
    if (x>0)
    {
        VHML_Result = (((1./sqrt(2.*HML_PI))*HML_IntegralOfSimpson(0,x,Epsilon,HML_ExpMSxD2))+0.5);
    }

	return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_LeftBorderOfWilcoxonWFromTable(int m, int n, double Q)
{
    /*
    Функция возвращает левую границу интервала критический значений статистики W для критерия Вилкоксена по табличным данным.
    Входные параметры:
     m - объем первой выборки (не больше 25);
     n - объем второй выборки (не больше 25);
     Q - уровень значимости. Может принимать значения:
      0.001;
      0.005;
      0.01;
      0.025;
      0.05;
      0.1.
    Возвращаемое значение:
     Левая граница интервала критический значений статистики W для критерия Вилкоксена.
    Примечание:
     Если размеры выборок не из таблицы, если не правильный выбран уровень значимости, то возвратится -1.
    */
    double VHML_Result=-1;

    if (n<m)  HML_NumberInterchange(&n,&m);//вначале должна идти выборка с меньшим объемом

    if (m==1)
    {
        if (n==9)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==10)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==11)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==12)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==13)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==14)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==15)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==16)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==17)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==18)
        {
            if (Q==0.10) VHML_Result = 1;
        }

        if (n==19)
        {
            if (Q==0.05) VHML_Result = 1;
            if (Q==0.10) VHML_Result = 2;
        }

        if (n==20)
        {
            if (Q==0.05) VHML_Result = 1;
            if (Q==0.10) VHML_Result = 2;
        }

        if (n==21)
        {
            if (Q==0.05) VHML_Result = 1;
            if (Q==0.10) VHML_Result = 2;
        }

        if (n==22)
        {
            if (Q==0.05) VHML_Result = 1;
            if (Q==0.10) VHML_Result = 2;
        }

        if (n==23)
        {
            if (Q==0.05) VHML_Result = 1;
            if (Q==0.10) VHML_Result = 2;
        }

        if (n==24)
        {
            if (Q==0.05) VHML_Result = 1;
            if (Q==0.10) VHML_Result = 2;
        }

        if (n==25)
        {
            if (Q==0.05) VHML_Result = 1;
            if (Q==0.10) VHML_Result = 2;
        }
    }

    if (m==2)
    {
        if (n==3)
        {
            if (Q==0.10) VHML_Result = 3;
        }

        if (n==4)
        {
            if (Q==0.10) VHML_Result = 3;
        }

        if (n==5)
        {
            if (Q==0.05) VHML_Result = 3;
            if (Q==0.10) VHML_Result = 4;
        }

        if (n==6)
        {
            if (Q==0.05) VHML_Result = 3;
            if (Q==0.10) VHML_Result = 4;
        }

        if (n==7)
        {
            if (Q==0.05) VHML_Result = 3;
            if (Q==0.10) VHML_Result = 4;
        }

        if (n==8)
        {
            if (Q==0.025) VHML_Result = 3;
            if (Q==0.05)  VHML_Result = 4;
            if (Q==0.10)  VHML_Result = 5;
        }

        if (n==9)
        {
            if (Q==0.025) VHML_Result = 3;
            if (Q==0.05)  VHML_Result = 4;
            if (Q==0.10)  VHML_Result = 5;
        }

        if (n==10)
        {
            if (Q==0.025) VHML_Result = 3;
            if (Q==0.05)  VHML_Result = 4;
            if (Q==0.10)  VHML_Result = 6;
        }

        if (n==11)
        {
            if (Q==0.025) VHML_Result = 3;
            if (Q==0.05)  VHML_Result = 4;
            if (Q==0.10)  VHML_Result = 6;
        }

        if (n==12)
        {
            if (Q==0.025) VHML_Result = 4;
            if (Q==0.05)  VHML_Result = 5;
            if (Q==0.10)  VHML_Result = 7;
        }

        if (n==13)
        {
            if (Q==0.010) VHML_Result = 3;
            if (Q==0.025) VHML_Result = 4;
            if (Q==0.05)  VHML_Result = 5;
            if (Q==0.10)  VHML_Result = 7;
        }

        if (n==14)
        {
            if (Q==0.010) VHML_Result = 3;
            if (Q==0.025) VHML_Result = 4;
            if (Q==0.05)  VHML_Result = 6;
            if (Q==0.10)  VHML_Result = 8;
        }

        if (n==15)
        {
            if (Q==0.010) VHML_Result = 3;
            if (Q==0.025) VHML_Result = 4;
            if (Q==0.05)  VHML_Result = 6;
            if (Q==0.10)  VHML_Result = 8;
        }

        if (n==16)
        {
            if (Q==0.010) VHML_Result = 3;
            if (Q==0.025) VHML_Result = 4;
            if (Q==0.05)  VHML_Result = 6;
            if (Q==0.10)  VHML_Result = 8;
        }

        if (n==17)
        {
            if (Q==0.010) VHML_Result = 3;
            if (Q==0.025) VHML_Result = 5;
            if (Q==0.05)  VHML_Result = 6;
            if (Q==0.10)  VHML_Result = 9;
        }

        if (n==18)
        {
            if (Q==0.010) VHML_Result = 3;
            if (Q==0.025) VHML_Result = 5;
            if (Q==0.05)  VHML_Result = 7;
            if (Q==0.10)  VHML_Result = 9;
        }

        if (n==19)
        {
            if (Q==0.005) VHML_Result = 3;
            if (Q==0.010) VHML_Result = 4;
            if (Q==0.025) VHML_Result = 5;
            if (Q==0.05)  VHML_Result = 7;
            if (Q==0.10)  VHML_Result = 10;
        }

        if (n==20)
        {
            if (Q==0.005) VHML_Result = 3;
            if (Q==0.010) VHML_Result = 4;
            if (Q==0.025) VHML_Result = 5;
            if (Q==0.05)  VHML_Result = 7;
            if (Q==0.10)  VHML_Result = 10;
        }

        if (n==21)
        {
            if (Q==0.005) VHML_Result = 3;
            if (Q==0.010) VHML_Result = 4;
            if (Q==0.025) VHML_Result = 6;
            if (Q==0.05)  VHML_Result = 8;
            if (Q==0.10)  VHML_Result = 11;
        }

        if (n==22)
        {
            if (Q==0.005) VHML_Result = 3;
            if (Q==0.010) VHML_Result = 4;
            if (Q==0.025) VHML_Result = 6;
            if (Q==0.05)  VHML_Result = 8;
            if (Q==0.10)  VHML_Result = 11;
        }

        if (n==23)
        {
            if (Q==0.005) VHML_Result = 3;
            if (Q==0.010) VHML_Result = 4;
            if (Q==0.025) VHML_Result = 6;
            if (Q==0.05)  VHML_Result = 8;
            if (Q==0.10)  VHML_Result = 12;
        }

        if (n==24)
        {
            if (Q==0.005) VHML_Result = 3;
            if (Q==0.010) VHML_Result = 4;
            if (Q==0.025) VHML_Result = 6;
            if (Q==0.05)  VHML_Result = 9;
            if (Q==0.10)  VHML_Result = 12;
        }

        if (n==25)
        {
            if (Q==0.005) VHML_Result = 3;
            if (Q==0.010) VHML_Result = 4;
            if (Q==0.025) VHML_Result = 6;
            if (Q==0.05)  VHML_Result = 9;
            if (Q==0.10)  VHML_Result = 12;
        }
    }

    if (m==3)
    {
        if (n==3)
        {
            if (Q==0.05)  VHML_Result = 6;
            if (Q==0.10)  VHML_Result = 7;
        }

        if (n==4)
        {
            if (Q==0.05)  VHML_Result = 6;
            if (Q==0.10)  VHML_Result = 7;
        }

        if (n==5)
        {
            if (Q==0.025) VHML_Result = 6;
            if (Q==0.05)  VHML_Result = 7;
            if (Q==0.10)  VHML_Result = 8;
        }

        if (n==6)
        {
            if (Q==0.025) VHML_Result = 7;
            if (Q==0.05)  VHML_Result = 8;
            if (Q==0.10)  VHML_Result = 9;
        }

        if (n==7)
        {
            if (Q==0.010) VHML_Result = 6;
            if (Q==0.025) VHML_Result = 7;
            if (Q==0.05)  VHML_Result = 8;
            if (Q==0.10)  VHML_Result = 10;
        }

        if (n==8)
        {
            if (Q==0.010) VHML_Result = 6;
            if (Q==0.025) VHML_Result = 8;
            if (Q==0.05)  VHML_Result = 9;
            if (Q==0.10)  VHML_Result = 11;
        }

        if (n==9)
        {
            if (Q==0.005) VHML_Result = 6;
            if (Q==0.010) VHML_Result = 7;
            if (Q==0.025) VHML_Result = 8;
            if (Q==0.05)  VHML_Result = 10;
            if (Q==0.10)  VHML_Result = 11;
        }

        if (n==10)
        {
            if (Q==0.005) VHML_Result = 6;
            if (Q==0.010) VHML_Result = 7;
            if (Q==0.025) VHML_Result = 9;
            if (Q==0.05)  VHML_Result = 10;
            if (Q==0.10)  VHML_Result = 12;
        }

        if (n==11)
        {
            if (Q==0.005) VHML_Result = 6;
            if (Q==0.010) VHML_Result = 7;
            if (Q==0.025) VHML_Result = 9;
            if (Q==0.05)  VHML_Result = 11;
            if (Q==0.10)  VHML_Result = 13;
        }

        if (n==12)
        {
            if (Q==0.005) VHML_Result = 7;
            if (Q==0.010) VHML_Result = 8;
            if (Q==0.025) VHML_Result = 10;
            if (Q==0.05)  VHML_Result = 11;
            if (Q==0.10)  VHML_Result = 14;
        }

        if (n==13)
        {
            if (Q==0.005) VHML_Result = 7;
            if (Q==0.010) VHML_Result = 8;
            if (Q==0.025) VHML_Result = 10;
            if (Q==0.05)  VHML_Result = 12;
            if (Q==0.10)  VHML_Result = 15;
        }

        if (n==14)
        {
            if (Q==0.005) VHML_Result = 7;
            if (Q==0.010) VHML_Result = 8;
            if (Q==0.025) VHML_Result = 11;
            if (Q==0.05)  VHML_Result = 13;
            if (Q==0.10)  VHML_Result = 16;
        }

        if (n==15)
        {
            if (Q==0.005) VHML_Result = 8;
            if (Q==0.010) VHML_Result = 9;
            if (Q==0.025) VHML_Result = 11;
            if (Q==0.05)  VHML_Result = 13;
            if (Q==0.10)  VHML_Result = 16;
        }

        if (n==16)
        {
            if (Q==0.005) VHML_Result = 8;
            if (Q==0.010) VHML_Result = 9;
            if (Q==0.025) VHML_Result = 12;
            if (Q==0.05)  VHML_Result = 14;
            if (Q==0.10)  VHML_Result = 17;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 6;
            if (Q==0.005) VHML_Result = 8;
            if (Q==0.010) VHML_Result = 10;
            if (Q==0.025) VHML_Result = 12;
            if (Q==0.05)  VHML_Result = 15;
            if (Q==0.10)  VHML_Result = 18;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 6;
            if (Q==0.005) VHML_Result = 8;
            if (Q==0.010) VHML_Result = 10;
            if (Q==0.025) VHML_Result = 13;
            if (Q==0.05)  VHML_Result = 15;
            if (Q==0.10)  VHML_Result = 19;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 6;
            if (Q==0.005) VHML_Result = 9;
            if (Q==0.010) VHML_Result = 10;
            if (Q==0.025) VHML_Result = 13;
            if (Q==0.05)  VHML_Result = 16;
            if (Q==0.10)  VHML_Result = 20;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 6;
            if (Q==0.005) VHML_Result = 9;
            if (Q==0.010) VHML_Result = 11;
            if (Q==0.025) VHML_Result = 14;
            if (Q==0.05)  VHML_Result = 17;
            if (Q==0.10)  VHML_Result = 21;
        }
		
		if (n==21)
        {
            if (Q==0.001) VHML_Result = 7;
            if (Q==0.005) VHML_Result = 9;
            if (Q==0.010) VHML_Result = 11;
            if (Q==0.025) VHML_Result = 14;
            if (Q==0.05)  VHML_Result = 17;
            if (Q==0.10)  VHML_Result = 21;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 7;
            if (Q==0.005) VHML_Result = 10;
            if (Q==0.010) VHML_Result = 12;
            if (Q==0.025) VHML_Result = 15;
            if (Q==0.05)  VHML_Result = 18;
            if (Q==0.10)  VHML_Result = 22;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 7;
            if (Q==0.005) VHML_Result = 10;
            if (Q==0.010) VHML_Result = 12;
            if (Q==0.025) VHML_Result = 15;
            if (Q==0.05)  VHML_Result = 19;
            if (Q==0.10)  VHML_Result = 23;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 7;
            if (Q==0.005) VHML_Result = 10;
            if (Q==0.010) VHML_Result = 12;
            if (Q==0.025) VHML_Result = 16;
            if (Q==0.05)  VHML_Result = 19;
            if (Q==0.10)  VHML_Result = 24;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 7;
            if (Q==0.005) VHML_Result = 11;
            if (Q==0.010) VHML_Result = 13;
            if (Q==0.025) VHML_Result = 16;
            if (Q==0.05)  VHML_Result = 20;
            if (Q==0.10)  VHML_Result = 25;
        }
    }

    if (m==4)
    {
        if (n==4)
        {
            if (Q==0.025) VHML_Result = 10;
            if (Q==0.05)  VHML_Result = 11;
            if (Q==0.10)  VHML_Result = 13;
        }

        if (n==5)
        {
            if (Q==0.010) VHML_Result = 10;
            if (Q==0.025) VHML_Result = 11;
            if (Q==0.05)  VHML_Result = 12;
            if (Q==0.10)  VHML_Result = 14;
        }

        if (n==6)
        {
            if (Q==0.005) VHML_Result = 10;
            if (Q==0.010) VHML_Result = 11;
            if (Q==0.025) VHML_Result = 12;
            if (Q==0.05)  VHML_Result = 13;
            if (Q==0.10)  VHML_Result = 15;
        }

        if (n==7)
        {
            if (Q==0.005) VHML_Result = 10;
            if (Q==0.010) VHML_Result = 11;
            if (Q==0.025) VHML_Result = 13;
            if (Q==0.05)  VHML_Result = 14;
            if (Q==0.10)  VHML_Result = 16;
        }

        if (n==8)
        {
            if (Q==0.005) VHML_Result = 11;
            if (Q==0.010) VHML_Result = 12;
            if (Q==0.025) VHML_Result = 14;
            if (Q==0.05)  VHML_Result = 15;
            if (Q==0.10)  VHML_Result = 17;
        }

        if (n==9)
        {
            if (Q==0.005) VHML_Result = 11;
            if (Q==0.010) VHML_Result = 13;
            if (Q==0.025) VHML_Result = 14;
            if (Q==0.05)  VHML_Result = 16;
            if (Q==0.10)  VHML_Result = 19;
        }

        if (n==10)
        {
            if (Q==0.001) VHML_Result = 10;
            if (Q==0.005) VHML_Result = 12;
            if (Q==0.010) VHML_Result = 13;
            if (Q==0.025) VHML_Result = 15;
            if (Q==0.05)  VHML_Result = 17;
            if (Q==0.10)  VHML_Result = 20;
        }

        if (n==11)
        {
            if (Q==0.001) VHML_Result = 10;
            if (Q==0.005) VHML_Result = 12;
            if (Q==0.010) VHML_Result = 14;
            if (Q==0.025) VHML_Result = 16;
            if (Q==0.05)  VHML_Result = 18;
            if (Q==0.10)  VHML_Result = 21;
        }

        if (n==12)
        {
            if (Q==0.001) VHML_Result = 10;
            if (Q==0.005) VHML_Result = 13;
            if (Q==0.010) VHML_Result = 15;
            if (Q==0.025) VHML_Result = 17;
            if (Q==0.05)  VHML_Result = 19;
            if (Q==0.10)  VHML_Result = 22;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 11;
            if (Q==0.005) VHML_Result = 13;
            if (Q==0.010) VHML_Result = 15;
            if (Q==0.025) VHML_Result = 18;
            if (Q==0.05)  VHML_Result = 20;
            if (Q==0.10)  VHML_Result = 23;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 11;
            if (Q==0.005) VHML_Result = 14;
            if (Q==0.010) VHML_Result = 16;
            if (Q==0.025) VHML_Result = 19;
            if (Q==0.05)  VHML_Result = 21;
            if (Q==0.10)  VHML_Result = 25;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 11;
            if (Q==0.005) VHML_Result = 15;
            if (Q==0.010) VHML_Result = 17;
            if (Q==0.025) VHML_Result = 20;
            if (Q==0.05)  VHML_Result = 22;
            if (Q==0.10)  VHML_Result = 26;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 12;
            if (Q==0.005) VHML_Result = 15;
            if (Q==0.010) VHML_Result = 17;
            if (Q==0.025) VHML_Result = 21;
            if (Q==0.05)  VHML_Result = 24;
            if (Q==0.10)  VHML_Result = 27;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 12;
            if (Q==0.005) VHML_Result = 16;
            if (Q==0.010) VHML_Result = 18;
            if (Q==0.025) VHML_Result = 21;
            if (Q==0.05)  VHML_Result = 25;
            if (Q==0.10)  VHML_Result = 28;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 13;
            if (Q==0.005) VHML_Result = 16;
            if (Q==0.010) VHML_Result = 19;
            if (Q==0.025) VHML_Result = 22;
            if (Q==0.05)  VHML_Result = 26;
            if (Q==0.10)  VHML_Result = 30;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 13;
            if (Q==0.005) VHML_Result = 17;
            if (Q==0.010) VHML_Result = 19;
            if (Q==0.025) VHML_Result = 23;
            if (Q==0.05)  VHML_Result = 27;
            if (Q==0.10)  VHML_Result = 31;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 13;
            if (Q==0.005) VHML_Result = 18;
            if (Q==0.010) VHML_Result = 20;
            if (Q==0.025) VHML_Result = 24;
            if (Q==0.05)  VHML_Result = 28;
            if (Q==0.10)  VHML_Result = 32;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 14;
            if (Q==0.005) VHML_Result = 18;
            if (Q==0.010) VHML_Result = 21;
            if (Q==0.025) VHML_Result = 25;
            if (Q==0.05)  VHML_Result = 29;
            if (Q==0.10)  VHML_Result = 33;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 14;
            if (Q==0.005) VHML_Result = 19;
            if (Q==0.010) VHML_Result = 21;
            if (Q==0.025) VHML_Result = 26;
            if (Q==0.05)  VHML_Result = 30;
            if (Q==0.10)  VHML_Result = 35;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 14;
            if (Q==0.005) VHML_Result = 19;
            if (Q==0.010) VHML_Result = 22;
            if (Q==0.025) VHML_Result = 27;
            if (Q==0.05)  VHML_Result = 31;
            if (Q==0.10)  VHML_Result = 36;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 15;
            if (Q==0.005) VHML_Result = 20;
            if (Q==0.010) VHML_Result = 23;
            if (Q==0.025) VHML_Result = 27;
            if (Q==0.05)  VHML_Result = 32;
            if (Q==0.10)  VHML_Result = 38;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 15;
            if (Q==0.005) VHML_Result = 20;
            if (Q==0.010) VHML_Result = 23;
            if (Q==0.025) VHML_Result = 28;
            if (Q==0.05)  VHML_Result = 33;
            if (Q==0.10)  VHML_Result = 38;
        }
    }

    if (m==5)
    {
        if (n==5)
        {
            if (Q==0.005) VHML_Result = 15;
            if (Q==0.010) VHML_Result = 16;
            if (Q==0.025) VHML_Result = 17;
            if (Q==0.05)  VHML_Result = 19;
            if (Q==0.10)  VHML_Result = 20;
        }

        if (n==6)
        {
            if (Q==0.005) VHML_Result = 16;
            if (Q==0.010) VHML_Result = 17;
            if (Q==0.025) VHML_Result = 18;
            if (Q==0.05)  VHML_Result = 20;
            if (Q==0.10)  VHML_Result = 22;
        }

        if (n==7)
        {
            if (Q==0.005) VHML_Result = 16;
            if (Q==0.010) VHML_Result = 18;
            if (Q==0.025) VHML_Result = 20;
            if (Q==0.05)  VHML_Result = 21;
            if (Q==0.10)  VHML_Result = 23;
        }

        if (n==8)
        {
            if (Q==0.001) VHML_Result = 15;
            if (Q==0.005) VHML_Result = 17;
            if (Q==0.010) VHML_Result = 19;
            if (Q==0.025) VHML_Result = 21;
            if (Q==0.05)  VHML_Result = 23;
            if (Q==0.10)  VHML_Result = 25;
        }

        if (n==9)
        {
            if (Q==0.001) VHML_Result = 16;
            if (Q==0.005) VHML_Result = 18;
            if (Q==0.010) VHML_Result = 20;
            if (Q==0.025) VHML_Result = 22;
            if (Q==0.05)  VHML_Result = 24;
            if (Q==0.10)  VHML_Result = 27;
        }

        if (n==10)
        {
            if (Q==0.001) VHML_Result = 16;
            if (Q==0.005) VHML_Result = 19;
            if (Q==0.010) VHML_Result = 21;
            if (Q==0.025) VHML_Result = 23;
            if (Q==0.05)  VHML_Result = 26;
            if (Q==0.10)  VHML_Result = 28;
        }

        if (n==11)
        {
            if (Q==0.001) VHML_Result = 17;
            if (Q==0.005) VHML_Result = 20;
            if (Q==0.010) VHML_Result = 22;
            if (Q==0.025) VHML_Result = 24;
            if (Q==0.05)  VHML_Result = 27;
            if (Q==0.10)  VHML_Result = 30;
        }

        if (n==12)
        {
            if (Q==0.001) VHML_Result = 17;
            if (Q==0.005) VHML_Result = 21;
            if (Q==0.010) VHML_Result = 23;
            if (Q==0.025) VHML_Result = 26;
            if (Q==0.05)  VHML_Result = 28;
            if (Q==0.10)  VHML_Result = 32;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 18;
            if (Q==0.005) VHML_Result = 22;
            if (Q==0.010) VHML_Result = 24;
            if (Q==0.025) VHML_Result = 27;
            if (Q==0.05)  VHML_Result = 30;
            if (Q==0.10)  VHML_Result = 33;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 18;
            if (Q==0.005) VHML_Result = 22;
            if (Q==0.010) VHML_Result = 25;
            if (Q==0.025) VHML_Result = 28;
            if (Q==0.05)  VHML_Result = 31;
            if (Q==0.10)  VHML_Result = 35;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 19;
            if (Q==0.005) VHML_Result = 23;
            if (Q==0.010) VHML_Result = 26;
            if (Q==0.025) VHML_Result = 29;
            if (Q==0.05)  VHML_Result = 33;
            if (Q==0.10)  VHML_Result = 37;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 20;
            if (Q==0.005) VHML_Result = 24;
            if (Q==0.010) VHML_Result = 27;
            if (Q==0.025) VHML_Result = 30;
            if (Q==0.05)  VHML_Result = 34;
            if (Q==0.10)  VHML_Result = 38;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 20;
            if (Q==0.005) VHML_Result = 25;
            if (Q==0.010) VHML_Result = 28;
            if (Q==0.025) VHML_Result = 32;
            if (Q==0.05)  VHML_Result = 35;
            if (Q==0.10)  VHML_Result = 40;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 21;
            if (Q==0.005) VHML_Result = 26;
            if (Q==0.010) VHML_Result = 29;
            if (Q==0.025) VHML_Result = 33;
            if (Q==0.05)  VHML_Result = 37;
            if (Q==0.10)  VHML_Result = 42;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 22;
            if (Q==0.005) VHML_Result = 27;
            if (Q==0.010) VHML_Result = 30;
            if (Q==0.025) VHML_Result = 34;
            if (Q==0.05)  VHML_Result = 38;
            if (Q==0.10)  VHML_Result = 43;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 22;
            if (Q==0.005) VHML_Result = 28;
            if (Q==0.010) VHML_Result = 31;
            if (Q==0.025) VHML_Result = 35;
            if (Q==0.05)  VHML_Result = 40;
            if (Q==0.10)  VHML_Result = 45;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 23;
            if (Q==0.005) VHML_Result = 29;
            if (Q==0.010) VHML_Result = 32;
            if (Q==0.025) VHML_Result = 37;
            if (Q==0.05)  VHML_Result = 41;
            if (Q==0.10)  VHML_Result = 47;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 23;
            if (Q==0.005) VHML_Result = 29;
            if (Q==0.010) VHML_Result = 33;
            if (Q==0.025) VHML_Result = 38;
            if (Q==0.05)  VHML_Result = 43;
            if (Q==0.10)  VHML_Result = 48;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 24;
            if (Q==0.005) VHML_Result = 30;
            if (Q==0.010) VHML_Result = 34;
            if (Q==0.025) VHML_Result = 39;
            if (Q==0.05)  VHML_Result = 44;
            if (Q==0.10)  VHML_Result = 50;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 25;
            if (Q==0.005) VHML_Result = 31;
            if (Q==0.010) VHML_Result = 35;
            if (Q==0.025) VHML_Result = 40;
            if (Q==0.05)  VHML_Result = 45;
            if (Q==0.10)  VHML_Result = 51;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 25;
            if (Q==0.005) VHML_Result = 32;
            if (Q==0.010) VHML_Result = 36;
            if (Q==0.025) VHML_Result = 42;
            if (Q==0.05)  VHML_Result = 47;
            if (Q==0.10)  VHML_Result = 53;
        }
    }

    if (m==6)
    {
        if (n==6)
        {
            if (Q==0.005) VHML_Result = 23;
            if (Q==0.010) VHML_Result = 24;
            if (Q==0.025) VHML_Result = 26;
            if (Q==0.05)  VHML_Result = 28;
            if (Q==0.10)  VHML_Result = 30;
        }

        if (n==7)
        {
            if (Q==0.001) VHML_Result = 21;
            if (Q==0.005) VHML_Result = 24;
            if (Q==0.010) VHML_Result = 25;
            if (Q==0.025) VHML_Result = 27;
            if (Q==0.05)  VHML_Result = 29;
            if (Q==0.10)  VHML_Result = 32;
        }

        if (n==8)
        {
            if (Q==0.001) VHML_Result = 22;
            if (Q==0.005) VHML_Result = 25;
            if (Q==0.010) VHML_Result = 27;
            if (Q==0.025) VHML_Result = 29;
            if (Q==0.05)  VHML_Result = 31;
            if (Q==0.10)  VHML_Result = 34;
        }

        if (n==9)
        {
            if (Q==0.001) VHML_Result = 23;
            if (Q==0.005) VHML_Result = 26;
            if (Q==0.010) VHML_Result = 28;
            if (Q==0.025) VHML_Result = 31;
            if (Q==0.05)  VHML_Result = 33;
            if (Q==0.10)  VHML_Result = 36;
        }

        if (n==10)
        {
            if (Q==0.001) VHML_Result = 24;
            if (Q==0.005) VHML_Result = 27;
            if (Q==0.010) VHML_Result = 29;
            if (Q==0.025) VHML_Result = 32;
            if (Q==0.05)  VHML_Result = 35;
            if (Q==0.10)  VHML_Result = 38;
        }

        if (n==11)
        {
            if (Q==0.001) VHML_Result = 25;
            if (Q==0.005) VHML_Result = 28;
            if (Q==0.010) VHML_Result = 30;
            if (Q==0.025) VHML_Result = 34;
            if (Q==0.05)  VHML_Result = 37;
            if (Q==0.10)  VHML_Result = 40;
        }

        if (n==12)
        {
            if (Q==0.001) VHML_Result = 25;
            if (Q==0.005) VHML_Result = 30;
            if (Q==0.010) VHML_Result = 32;
            if (Q==0.025) VHML_Result = 35;
            if (Q==0.05)  VHML_Result = 38;
            if (Q==0.10)  VHML_Result = 42;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 26;
            if (Q==0.005) VHML_Result = 31;
            if (Q==0.010) VHML_Result = 33;
            if (Q==0.025) VHML_Result = 37;
            if (Q==0.05)  VHML_Result = 40;
            if (Q==0.10)  VHML_Result = 44;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 27;
            if (Q==0.005) VHML_Result = 32;
            if (Q==0.010) VHML_Result = 34;
            if (Q==0.025) VHML_Result = 38;
            if (Q==0.05)  VHML_Result = 42;
            if (Q==0.10)  VHML_Result = 46;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 28;
            if (Q==0.005) VHML_Result = 33;
            if (Q==0.010) VHML_Result = 36;
            if (Q==0.025) VHML_Result = 40;
            if (Q==0.05)  VHML_Result = 44;
            if (Q==0.10)  VHML_Result = 48;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 29;
            if (Q==0.005) VHML_Result = 34;
            if (Q==0.010) VHML_Result = 37;
            if (Q==0.025) VHML_Result = 42;
            if (Q==0.05)  VHML_Result = 46;
            if (Q==0.10)  VHML_Result = 50;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 30;
            if (Q==0.005) VHML_Result = 36;
            if (Q==0.010) VHML_Result = 39;
            if (Q==0.025) VHML_Result = 43;
            if (Q==0.05)  VHML_Result = 47;
            if (Q==0.10)  VHML_Result = 52;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 31;
            if (Q==0.005) VHML_Result = 37;
            if (Q==0.010) VHML_Result = 40;
            if (Q==0.025) VHML_Result = 45;
            if (Q==0.05)  VHML_Result = 49;
            if (Q==0.10)  VHML_Result = 55;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 32;
            if (Q==0.005) VHML_Result = 38;
            if (Q==0.010) VHML_Result = 41;
            if (Q==0.025) VHML_Result = 46;
            if (Q==0.05)  VHML_Result = 51;
            if (Q==0.10)  VHML_Result = 57;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 33;
            if (Q==0.005) VHML_Result = 39;
            if (Q==0.010) VHML_Result = 43;
            if (Q==0.025) VHML_Result = 48;
            if (Q==0.05)  VHML_Result = 53;
            if (Q==0.10)  VHML_Result = 59;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 33;
            if (Q==0.005) VHML_Result = 40;
            if (Q==0.010) VHML_Result = 44;
            if (Q==0.025) VHML_Result = 50;
            if (Q==0.05)  VHML_Result = 55;
            if (Q==0.10)  VHML_Result = 61;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 34;
            if (Q==0.005) VHML_Result = 42;
            if (Q==0.010) VHML_Result = 45;
            if (Q==0.025) VHML_Result = 51;
            if (Q==0.05)  VHML_Result = 57;
            if (Q==0.10)  VHML_Result = 63;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 35;
            if (Q==0.005) VHML_Result = 43;
            if (Q==0.010) VHML_Result = 47;
            if (Q==0.025) VHML_Result = 53;
            if (Q==0.05)  VHML_Result = 58;
            if (Q==0.10)  VHML_Result = 65;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 36;
            if (Q==0.005) VHML_Result = 44;
            if (Q==0.010) VHML_Result = 48;
            if (Q==0.025) VHML_Result = 54;
            if (Q==0.05)  VHML_Result = 60;
            if (Q==0.10)  VHML_Result = 67;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 37;
            if (Q==0.005) VHML_Result = 45;
            if (Q==0.010) VHML_Result = 50;
            if (Q==0.025) VHML_Result = 56;
            if (Q==0.05)  VHML_Result = 62;
            if (Q==0.10)  VHML_Result = 69;
        }
    }

    if (m==7)
    {
        if (n==7)
        {
            if (Q==0.001) VHML_Result = 29;
            if (Q==0.005) VHML_Result = 32;
            if (Q==0.010) VHML_Result = 34;
            if (Q==0.025) VHML_Result = 36;
            if (Q==0.05)  VHML_Result = 39;
            if (Q==0.10)  VHML_Result = 41;
        }

        if (n==8)
        {
            if (Q==0.001) VHML_Result = 30;
            if (Q==0.005) VHML_Result = 34;
            if (Q==0.010) VHML_Result = 35;
            if (Q==0.025) VHML_Result = 38;
            if (Q==0.05)  VHML_Result = 41;
            if (Q==0.10)  VHML_Result = 44;
        }

        if (n==9)
        {
            if (Q==0.001) VHML_Result = 31;
            if (Q==0.005) VHML_Result = 35;
            if (Q==0.010) VHML_Result = 37;
            if (Q==0.025) VHML_Result = 40;
            if (Q==0.05)  VHML_Result = 43;
            if (Q==0.10)  VHML_Result = 46;
        }

        if (n==10)
        {
            if (Q==0.001) VHML_Result = 33;
            if (Q==0.005) VHML_Result = 37;
            if (Q==0.010) VHML_Result = 39;
            if (Q==0.025) VHML_Result = 42;
            if (Q==0.05)  VHML_Result = 45;
            if (Q==0.10)  VHML_Result = 49;
        }

        if (n==11)
        {
            if (Q==0.001) VHML_Result = 34;
            if (Q==0.005) VHML_Result = 38;
            if (Q==0.010) VHML_Result = 40;
            if (Q==0.025) VHML_Result = 44;
            if (Q==0.05)  VHML_Result = 47;
            if (Q==0.10)  VHML_Result = 51;
        }

        if (n==12)
        {
            if (Q==0.001) VHML_Result = 35;
            if (Q==0.005) VHML_Result = 40;
            if (Q==0.010) VHML_Result = 42;
            if (Q==0.025) VHML_Result = 46;
            if (Q==0.05)  VHML_Result = 49;
            if (Q==0.10)  VHML_Result = 54;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 36;
            if (Q==0.005) VHML_Result = 41;
            if (Q==0.010) VHML_Result = 44;
            if (Q==0.025) VHML_Result = 48;
            if (Q==0.05)  VHML_Result = 52;
            if (Q==0.10)  VHML_Result = 56;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 37;
            if (Q==0.005) VHML_Result = 43;
            if (Q==0.010) VHML_Result = 45;
            if (Q==0.025) VHML_Result = 50;
            if (Q==0.05)  VHML_Result = 54;
            if (Q==0.10)  VHML_Result = 59;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 38;
            if (Q==0.005) VHML_Result = 44;
            if (Q==0.010) VHML_Result = 47;
            if (Q==0.025) VHML_Result = 52;
            if (Q==0.05)  VHML_Result = 56;
            if (Q==0.10)  VHML_Result = 61;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 39;
            if (Q==0.005) VHML_Result = 46;
            if (Q==0.010) VHML_Result = 49;
            if (Q==0.025) VHML_Result = 54;
            if (Q==0.05)  VHML_Result = 58;
            if (Q==0.10)  VHML_Result = 64;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 41;
            if (Q==0.005) VHML_Result = 47;
            if (Q==0.010) VHML_Result = 51;
            if (Q==0.025) VHML_Result = 56;
            if (Q==0.05)  VHML_Result = 61;
            if (Q==0.10)  VHML_Result = 66;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 42;
            if (Q==0.005) VHML_Result = 49;
            if (Q==0.010) VHML_Result = 52;
            if (Q==0.025) VHML_Result = 58;
            if (Q==0.05)  VHML_Result = 63;
            if (Q==0.10)  VHML_Result = 69;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 43;
            if (Q==0.005) VHML_Result = 50;
            if (Q==0.010) VHML_Result = 54;
            if (Q==0.025) VHML_Result = 60;
            if (Q==0.05)  VHML_Result = 65;
            if (Q==0.10)  VHML_Result = 71;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 44;
            if (Q==0.005) VHML_Result = 52;
            if (Q==0.010) VHML_Result = 56;
            if (Q==0.025) VHML_Result = 62;
            if (Q==0.05)  VHML_Result = 67;
            if (Q==0.10)  VHML_Result = 74;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 46;
            if (Q==0.005) VHML_Result = 53;
            if (Q==0.010) VHML_Result = 58;
            if (Q==0.025) VHML_Result = 64;
            if (Q==0.05)  VHML_Result = 69;
            if (Q==0.10)  VHML_Result = 76;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 47;
            if (Q==0.005) VHML_Result = 55;
            if (Q==0.010) VHML_Result = 59;
            if (Q==0.025) VHML_Result = 66;
            if (Q==0.05)  VHML_Result = 72;
            if (Q==0.10)  VHML_Result = 79;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 48;
            if (Q==0.005) VHML_Result = 57;
            if (Q==0.010) VHML_Result = 61;
            if (Q==0.025) VHML_Result = 68;
            if (Q==0.05)  VHML_Result = 74;
            if (Q==0.10)  VHML_Result = 81;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 49;
            if (Q==0.005) VHML_Result = 58;
            if (Q==0.010) VHML_Result = 63;
            if (Q==0.025) VHML_Result = 70;
            if (Q==0.05)  VHML_Result = 76;
            if (Q==0.10)  VHML_Result = 84;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 50;
            if (Q==0.005) VHML_Result = 60;
            if (Q==0.010) VHML_Result = 64;
            if (Q==0.025) VHML_Result = 72;
            if (Q==0.05)  VHML_Result = 78;
            if (Q==0.10)  VHML_Result = 86;
        }
    }

    if (m==8)
    {
        if (n==8)
        {
            if (Q==0.001) VHML_Result = 40;
            if (Q==0.005) VHML_Result = 43;
            if (Q==0.010) VHML_Result = 45;
            if (Q==0.025) VHML_Result = 49;
            if (Q==0.05)  VHML_Result = 51;
            if (Q==0.10)  VHML_Result = 55;
        }

        if (n==9)
        {
            if (Q==0.001) VHML_Result = 41;
            if (Q==0.005) VHML_Result = 45;
            if (Q==0.010) VHML_Result = 47;
            if (Q==0.025) VHML_Result = 51;
            if (Q==0.05)  VHML_Result = 54;
            if (Q==0.10)  VHML_Result = 58;
        }

        if (n==10)
        {
            if (Q==0.001) VHML_Result = 42;
            if (Q==0.005) VHML_Result = 47;
            if (Q==0.010) VHML_Result = 49;
            if (Q==0.025) VHML_Result = 53;
            if (Q==0.05)  VHML_Result = 56;
            if (Q==0.10)  VHML_Result = 60;
        }

        if (n==11)
        {
            if (Q==0.001) VHML_Result = 44;
            if (Q==0.005) VHML_Result = 49;
            if (Q==0.010) VHML_Result = 51;
            if (Q==0.025) VHML_Result = 55;
            if (Q==0.05)  VHML_Result = 59;
            if (Q==0.10)  VHML_Result = 63;
        }

        if (n==12)
        {
            if (Q==0.001) VHML_Result = 45;
            if (Q==0.005) VHML_Result = 51;
            if (Q==0.010) VHML_Result = 53;
            if (Q==0.025) VHML_Result = 58;
            if (Q==0.05)  VHML_Result = 62;
            if (Q==0.10)  VHML_Result = 66;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 47;
            if (Q==0.005) VHML_Result = 53;
            if (Q==0.010) VHML_Result = 56;
            if (Q==0.025) VHML_Result = 60;
            if (Q==0.05)  VHML_Result = 64;
            if (Q==0.10)  VHML_Result = 69;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 48;
            if (Q==0.005) VHML_Result = 54;
            if (Q==0.010) VHML_Result = 58;
            if (Q==0.025) VHML_Result = 62;
            if (Q==0.05)  VHML_Result = 67;
            if (Q==0.10)  VHML_Result = 72;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 50;
            if (Q==0.005) VHML_Result = 56;
            if (Q==0.010) VHML_Result = 60;
            if (Q==0.025) VHML_Result = 65;
            if (Q==0.05)  VHML_Result = 69;
            if (Q==0.10)  VHML_Result = 75;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 51;
            if (Q==0.005) VHML_Result = 58;
            if (Q==0.010) VHML_Result = 62;
            if (Q==0.025) VHML_Result = 67;
            if (Q==0.05)  VHML_Result = 72;
            if (Q==0.10)  VHML_Result = 78;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 53;
            if (Q==0.005) VHML_Result = 60;
            if (Q==0.010) VHML_Result = 64;
            if (Q==0.025) VHML_Result = 70;
            if (Q==0.05)  VHML_Result = 75;
            if (Q==0.10)  VHML_Result = 81;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 54;
            if (Q==0.005) VHML_Result = 62;
            if (Q==0.010) VHML_Result = 66;
            if (Q==0.025) VHML_Result = 72;
            if (Q==0.05)  VHML_Result = 77;
            if (Q==0.10)  VHML_Result = 84;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 56;
            if (Q==0.005) VHML_Result = 64;
            if (Q==0.010) VHML_Result = 68;
            if (Q==0.025) VHML_Result = 74;
            if (Q==0.05)  VHML_Result = 80;
            if (Q==0.10)  VHML_Result = 87;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 57;
            if (Q==0.005) VHML_Result = 66;
            if (Q==0.010) VHML_Result = 70;
            if (Q==0.025) VHML_Result = 77;
            if (Q==0.05)  VHML_Result = 83;
            if (Q==0.10)  VHML_Result = 90;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 59;
            if (Q==0.005) VHML_Result = 68;
            if (Q==0.010) VHML_Result = 72;
            if (Q==0.025) VHML_Result = 79;
            if (Q==0.05)  VHML_Result = 85;
            if (Q==0.10)  VHML_Result = 92;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 60;
            if (Q==0.005) VHML_Result = 70;
            if (Q==0.010) VHML_Result = 74;
            if (Q==0.025) VHML_Result = 81;
            if (Q==0.05)  VHML_Result = 88;
            if (Q==0.10)  VHML_Result = 95;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 62;
            if (Q==0.005) VHML_Result = 71;
            if (Q==0.010) VHML_Result = 76;
            if (Q==0.025) VHML_Result = 84;
            if (Q==0.05)  VHML_Result = 90;
            if (Q==0.10)  VHML_Result = 98;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 64;
            if (Q==0.005) VHML_Result = 73;
            if (Q==0.010) VHML_Result = 78;
            if (Q==0.025) VHML_Result = 86;
            if (Q==0.05)  VHML_Result = 93;
            if (Q==0.10)  VHML_Result = 101;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 65;
            if (Q==0.005) VHML_Result = 75;
            if (Q==0.010) VHML_Result = 81;
            if (Q==0.025) VHML_Result = 89;
            if (Q==0.05)  VHML_Result = 96;
            if (Q==0.10)  VHML_Result = 104;
        }
    }

    if (m==9)
    {
        if (n==9)
        {
            if (Q==0.001) VHML_Result = 52;
            if (Q==0.005) VHML_Result = 56;
            if (Q==0.010) VHML_Result = 59;
            if (Q==0.025) VHML_Result = 62;
            if (Q==0.05)  VHML_Result = 66;
            if (Q==0.10)  VHML_Result = 70;
        }

        if (n==10)
        {
            if (Q==0.001) VHML_Result = 53;
            if (Q==0.005) VHML_Result = 58;
            if (Q==0.010) VHML_Result = 61;
            if (Q==0.025) VHML_Result = 65;
            if (Q==0.05)  VHML_Result = 69;
            if (Q==0.10)  VHML_Result = 73;
        }

        if (n==11)
        {
            if (Q==0.001) VHML_Result = 55;
            if (Q==0.005) VHML_Result = 61;
            if (Q==0.010) VHML_Result = 63;
            if (Q==0.025) VHML_Result = 68;
            if (Q==0.05)  VHML_Result = 72;
            if (Q==0.10)  VHML_Result = 76;
        }

        if (n==12)
        {
            if (Q==0.001) VHML_Result = 57;
            if (Q==0.005) VHML_Result = 63;
            if (Q==0.010) VHML_Result = 66;
            if (Q==0.025) VHML_Result = 71;
            if (Q==0.05)  VHML_Result = 75;
            if (Q==0.10)  VHML_Result = 80;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 59;
            if (Q==0.005) VHML_Result = 65;
            if (Q==0.010) VHML_Result = 68;
            if (Q==0.025) VHML_Result = 73;
            if (Q==0.05)  VHML_Result = 78;
            if (Q==0.10)  VHML_Result = 83;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 60;
            if (Q==0.005) VHML_Result = 67;
            if (Q==0.010) VHML_Result = 71;
            if (Q==0.025) VHML_Result = 76;
            if (Q==0.05)  VHML_Result = 81;
            if (Q==0.10)  VHML_Result = 86;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 62;
            if (Q==0.005) VHML_Result = 69;
            if (Q==0.010) VHML_Result = 73;
            if (Q==0.025) VHML_Result = 79;
            if (Q==0.05)  VHML_Result = 84;
            if (Q==0.10)  VHML_Result = 90;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 64;
            if (Q==0.005) VHML_Result = 72;
            if (Q==0.010) VHML_Result = 76;
            if (Q==0.025) VHML_Result = 82;
            if (Q==0.05)  VHML_Result = 87;
            if (Q==0.10)  VHML_Result = 93;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 66;
            if (Q==0.005) VHML_Result = 74;
            if (Q==0.010) VHML_Result = 78;
            if (Q==0.025) VHML_Result = 84;
            if (Q==0.05)  VHML_Result = 90;
            if (Q==0.10)  VHML_Result = 97;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 68;
            if (Q==0.005) VHML_Result = 76;
            if (Q==0.010) VHML_Result = 81;
            if (Q==0.025) VHML_Result = 87;
            if (Q==0.05)  VHML_Result = 93;
            if (Q==0.10)  VHML_Result = 100;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 70;
            if (Q==0.005) VHML_Result = 78;
            if (Q==0.010) VHML_Result = 83;
            if (Q==0.025) VHML_Result = 90;
            if (Q==0.05)  VHML_Result = 96;
            if (Q==0.10)  VHML_Result = 103;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 71;
            if (Q==0.005) VHML_Result = 81;
            if (Q==0.010) VHML_Result = 85;
            if (Q==0.025) VHML_Result = 93;
            if (Q==0.05)  VHML_Result = 99;
            if (Q==0.10)  VHML_Result = 107;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 73;
            if (Q==0.005) VHML_Result = 83;
            if (Q==0.010) VHML_Result = 88;
            if (Q==0.025) VHML_Result = 95;
            if (Q==0.05)  VHML_Result = 102;
            if (Q==0.10)  VHML_Result = 110;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 75;
            if (Q==0.005) VHML_Result = 85;
            if (Q==0.010) VHML_Result = 90;
            if (Q==0.025) VHML_Result = 98;
            if (Q==0.05)  VHML_Result = 105;
            if (Q==0.10)  VHML_Result = 113;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 77;
            if (Q==0.005) VHML_Result = 88;
            if (Q==0.010) VHML_Result = 93;
            if (Q==0.025) VHML_Result = 101;
            if (Q==0.05)  VHML_Result = 108;
            if (Q==0.10)  VHML_Result = 117;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 79;
            if (Q==0.005) VHML_Result = 90;
            if (Q==0.010) VHML_Result = 95;
            if (Q==0.025) VHML_Result = 104;
            if (Q==0.05)  VHML_Result = 111;
            if (Q==0.10)  VHML_Result = 120;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 81;
            if (Q==0.005) VHML_Result = 92;
            if (Q==0.010) VHML_Result = 98;
            if (Q==0.025) VHML_Result = 107;
            if (Q==0.05)  VHML_Result = 114;
            if (Q==0.10)  VHML_Result = 123;
        }
    }

    if (m==10)
    {
        if (n==10)
        {
            if (Q==0.001) VHML_Result = 65;
            if (Q==0.005) VHML_Result = 71;
            if (Q==0.010) VHML_Result = 74;
            if (Q==0.025) VHML_Result = 78;
            if (Q==0.05)  VHML_Result = 82;
            if (Q==0.10)  VHML_Result = 87;
        }

        if (n==11)
        {
            if (Q==0.001) VHML_Result = 67;
            if (Q==0.005) VHML_Result = 73;
            if (Q==0.010) VHML_Result = 77;
            if (Q==0.025) VHML_Result = 81;
            if (Q==0.05)  VHML_Result = 86;
            if (Q==0.10)  VHML_Result = 91;
        }

        if (n==12)
        {
            if (Q==0.001) VHML_Result = 69;
            if (Q==0.005) VHML_Result = 76;
            if (Q==0.010) VHML_Result = 79;
            if (Q==0.025) VHML_Result = 84;
            if (Q==0.05)  VHML_Result = 89;
            if (Q==0.10)  VHML_Result = 94;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 72;
            if (Q==0.005) VHML_Result = 79;
            if (Q==0.010) VHML_Result = 82;
            if (Q==0.025) VHML_Result = 88;
            if (Q==0.05)  VHML_Result = 92;
            if (Q==0.10)  VHML_Result = 98;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 74;
            if (Q==0.005) VHML_Result = 81;
            if (Q==0.010) VHML_Result = 85;
            if (Q==0.025) VHML_Result = 91;
            if (Q==0.05)  VHML_Result = 96;
            if (Q==0.10)  VHML_Result = 102;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 76;
            if (Q==0.005) VHML_Result = 84;
            if (Q==0.010) VHML_Result = 88;
            if (Q==0.025) VHML_Result = 94;
            if (Q==0.05)  VHML_Result = 99;
            if (Q==0.10)  VHML_Result = 106;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 78;
            if (Q==0.005) VHML_Result = 86;
            if (Q==0.010) VHML_Result = 91;
            if (Q==0.025) VHML_Result = 97;
            if (Q==0.05)  VHML_Result = 103;
            if (Q==0.10)  VHML_Result = 109;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 80;
            if (Q==0.005) VHML_Result = 89;
            if (Q==0.010) VHML_Result = 93;
            if (Q==0.025) VHML_Result = 100;
            if (Q==0.05)  VHML_Result = 106;
            if (Q==0.10)  VHML_Result = 113;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 82;
            if (Q==0.005) VHML_Result = 92;
            if (Q==0.010) VHML_Result = 96;
            if (Q==0.025) VHML_Result = 103;
            if (Q==0.05)  VHML_Result = 110;
            if (Q==0.10)  VHML_Result = 117;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 84;
            if (Q==0.005) VHML_Result = 94;
            if (Q==0.010) VHML_Result = 99;
            if (Q==0.025) VHML_Result = 107;
            if (Q==0.05)  VHML_Result = 113;
            if (Q==0.10)  VHML_Result = 121;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 87;
            if (Q==0.005) VHML_Result = 97;
            if (Q==0.010) VHML_Result = 102;
            if (Q==0.025) VHML_Result = 110;
            if (Q==0.05)  VHML_Result = 117;
            if (Q==0.10)  VHML_Result = 125;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 89;
            if (Q==0.005) VHML_Result = 99;
            if (Q==0.010) VHML_Result = 105;
            if (Q==0.025) VHML_Result = 113;
            if (Q==0.05)  VHML_Result = 120;
            if (Q==0.10)  VHML_Result = 128;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 91;
            if (Q==0.005) VHML_Result = 102;
            if (Q==0.010) VHML_Result = 108;
            if (Q==0.025) VHML_Result = 116;
            if (Q==0.05)  VHML_Result = 123;
            if (Q==0.10)  VHML_Result = 132;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 93;
            if (Q==0.005) VHML_Result = 105;
            if (Q==0.010) VHML_Result = 110;
            if (Q==0.025) VHML_Result = 119;
            if (Q==0.05)  VHML_Result = 127;
            if (Q==0.10)  VHML_Result = 136;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 95;
            if (Q==0.005) VHML_Result = 107;
            if (Q==0.010) VHML_Result = 113;
            if (Q==0.025) VHML_Result = 122;
            if (Q==0.05)  VHML_Result = 130;
            if (Q==0.10)  VHML_Result = 140;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 98;
            if (Q==0.005) VHML_Result = 110;
            if (Q==0.010) VHML_Result = 116;
            if (Q==0.025) VHML_Result = 126;
            if (Q==0.05)  VHML_Result = 134;
            if (Q==0.10)  VHML_Result = 144;
        }

    }

    if (m==11)
    {
        if (n==11)
        {
            if (Q==0.001) VHML_Result = 81;
            if (Q==0.005) VHML_Result = 87;
            if (Q==0.010) VHML_Result = 91;
            if (Q==0.025) VHML_Result = 96;
            if (Q==0.05)  VHML_Result = 100;
            if (Q==0.10)  VHML_Result = 106;
        }

        if (n==12)
        {
            if (Q==0.001) VHML_Result = 83;
            if (Q==0.005) VHML_Result = 90;
            if (Q==0.010) VHML_Result = 94;
            if (Q==0.025) VHML_Result = 99;
            if (Q==0.05)  VHML_Result = 104;
            if (Q==0.10)  VHML_Result = 110;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 86;
            if (Q==0.005) VHML_Result = 93;
            if (Q==0.010) VHML_Result = 97;
            if (Q==0.025) VHML_Result = 103;
            if (Q==0.05)  VHML_Result = 108;
            if (Q==0.10)  VHML_Result = 114;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 88;
            if (Q==0.005) VHML_Result = 96;
            if (Q==0.010) VHML_Result = 100;
            if (Q==0.025) VHML_Result = 106;
            if (Q==0.05)  VHML_Result = 112;
            if (Q==0.10)  VHML_Result = 118;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 90;
            if (Q==0.005) VHML_Result = 99;
            if (Q==0.010) VHML_Result = 103;
            if (Q==0.025) VHML_Result = 110;
            if (Q==0.05)  VHML_Result = 116;
            if (Q==0.10)  VHML_Result = 123;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 93;
            if (Q==0.005) VHML_Result = 102;
            if (Q==0.010) VHML_Result = 107;
            if (Q==0.025) VHML_Result = 113;
            if (Q==0.05)  VHML_Result = 120;
            if (Q==0.10)  VHML_Result = 127;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 95;
            if (Q==0.005) VHML_Result = 105;
            if (Q==0.010) VHML_Result = 110;
            if (Q==0.025) VHML_Result = 117;
            if (Q==0.05)  VHML_Result = 123;
            if (Q==0.10)  VHML_Result = 131;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 98;
            if (Q==0.005) VHML_Result = 108;
            if (Q==0.010) VHML_Result = 113;
            if (Q==0.025) VHML_Result = 121;
            if (Q==0.05)  VHML_Result = 127;
            if (Q==0.10)  VHML_Result = 135;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 100;
            if (Q==0.005) VHML_Result = 111;
            if (Q==0.010) VHML_Result = 116;
            if (Q==0.025) VHML_Result = 124;
            if (Q==0.05)  VHML_Result = 131;
            if (Q==0.10)  VHML_Result = 139;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 103;
            if (Q==0.005) VHML_Result = 114;
            if (Q==0.010) VHML_Result = 119;
            if (Q==0.025) VHML_Result = 128;
            if (Q==0.05)  VHML_Result = 135;
            if (Q==0.10)  VHML_Result = 144;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 106;
            if (Q==0.005) VHML_Result = 117;
            if (Q==0.010) VHML_Result = 123;
            if (Q==0.025) VHML_Result = 131;
            if (Q==0.05)  VHML_Result = 139;
            if (Q==0.10)  VHML_Result = 148;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 108;
            if (Q==0.005) VHML_Result = 120;
            if (Q==0.010) VHML_Result = 126;
            if (Q==0.025) VHML_Result = 135;
            if (Q==0.05)  VHML_Result = 143;
            if (Q==0.10)  VHML_Result = 152;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 111;
            if (Q==0.005) VHML_Result = 123;
            if (Q==0.010) VHML_Result = 129;
            if (Q==0.025) VHML_Result = 139;
            if (Q==0.05)  VHML_Result = 147;
            if (Q==0.10)  VHML_Result = 156;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 113;
            if (Q==0.005) VHML_Result = 126;
            if (Q==0.010) VHML_Result = 132;
            if (Q==0.025) VHML_Result = 142;
            if (Q==0.05)  VHML_Result = 151;
            if (Q==0.10)  VHML_Result = 161;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 116;
            if (Q==0.005) VHML_Result = 129;
            if (Q==0.010) VHML_Result = 136;
            if (Q==0.025) VHML_Result = 146;
            if (Q==0.05)  VHML_Result = 155;
            if (Q==0.10)  VHML_Result = 165;
        }
    }

    if (m==12)
    {
        if (n==12)
        {
            if (Q==0.001) VHML_Result = 98;
            if (Q==0.005) VHML_Result = 105;
            if (Q==0.010) VHML_Result = 109;
            if (Q==0.025) VHML_Result = 115;
            if (Q==0.05)  VHML_Result = 120;
            if (Q==0.10)  VHML_Result = 127;
        }

        if (n==13)
        {
            if (Q==0.001) VHML_Result = 101;
            if (Q==0.005) VHML_Result = 109;
            if (Q==0.010) VHML_Result = 113;
            if (Q==0.025) VHML_Result = 119;
            if (Q==0.05)  VHML_Result = 125;
            if (Q==0.10)  VHML_Result = 131;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 103;
            if (Q==0.005) VHML_Result = 112;
            if (Q==0.010) VHML_Result = 116;
            if (Q==0.025) VHML_Result = 123;
            if (Q==0.05)  VHML_Result = 129;
            if (Q==0.10)  VHML_Result = 136;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 106;
            if (Q==0.005) VHML_Result = 115;
            if (Q==0.010) VHML_Result = 120;
            if (Q==0.025) VHML_Result = 127;
            if (Q==0.05)  VHML_Result = 133;
            if (Q==0.10)  VHML_Result = 141;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 109;
            if (Q==0.005) VHML_Result = 119;
            if (Q==0.010) VHML_Result = 124;
            if (Q==0.025) VHML_Result = 131;
            if (Q==0.05)  VHML_Result = 138;
            if (Q==0.10)  VHML_Result = 145;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 112;
            if (Q==0.005) VHML_Result = 122;
            if (Q==0.010) VHML_Result = 127;
            if (Q==0.025) VHML_Result = 135;
            if (Q==0.05)  VHML_Result = 142;
            if (Q==0.10)  VHML_Result = 150;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 115;
            if (Q==0.005) VHML_Result = 125;
            if (Q==0.010) VHML_Result = 131;
            if (Q==0.025) VHML_Result = 139;
            if (Q==0.05)  VHML_Result = 146;
            if (Q==0.10)  VHML_Result = 155;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 118;
            if (Q==0.005) VHML_Result = 129;
            if (Q==0.010) VHML_Result = 134;
            if (Q==0.025) VHML_Result = 143;
            if (Q==0.05)  VHML_Result = 150;
            if (Q==0.10)  VHML_Result = 159;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 120;
            if (Q==0.005) VHML_Result = 132;
            if (Q==0.010) VHML_Result = 138;
            if (Q==0.025) VHML_Result = 147;
            if (Q==0.05)  VHML_Result = 155;
            if (Q==0.10)  VHML_Result = 164;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 123;
            if (Q==0.005) VHML_Result = 136;
            if (Q==0.010) VHML_Result = 142;
            if (Q==0.025) VHML_Result = 151;
            if (Q==0.05)  VHML_Result = 159;
            if (Q==0.10)  VHML_Result = 169;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 126;
            if (Q==0.005) VHML_Result = 139;
            if (Q==0.010) VHML_Result = 145;
            if (Q==0.025) VHML_Result = 155;
            if (Q==0.05)  VHML_Result = 163;
            if (Q==0.10)  VHML_Result = 173;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 129;
            if (Q==0.005) VHML_Result = 142;
            if (Q==0.010) VHML_Result = 149;
            if (Q==0.025) VHML_Result = 159;
            if (Q==0.05)  VHML_Result = 168;
            if (Q==0.10)  VHML_Result = 178;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 132;
            if (Q==0.005) VHML_Result = 146;
            if (Q==0.010) VHML_Result = 153;
            if (Q==0.025) VHML_Result = 163;
            if (Q==0.05)  VHML_Result = 172;
            if (Q==0.10)  VHML_Result = 183;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 135;
            if (Q==0.005) VHML_Result = 149;
            if (Q==0.010) VHML_Result = 156;
            if (Q==0.025) VHML_Result = 167;
            if (Q==0.05)  VHML_Result = 176;
            if (Q==0.10)  VHML_Result = 187;
        }
    }

    if (m==13)
    {
        if (n==13)
        {
            if (Q==0.001) VHML_Result = 117;
            if (Q==0.005) VHML_Result = 125;
            if (Q==0.010) VHML_Result = 130;
            if (Q==0.025) VHML_Result = 136;
            if (Q==0.05)  VHML_Result = 142;
            if (Q==0.10)  VHML_Result = 149;
        }

        if (n==14)
        {
            if (Q==0.001) VHML_Result = 120;
            if (Q==0.005) VHML_Result = 129;
            if (Q==0.010) VHML_Result = 134;
            if (Q==0.025) VHML_Result = 141;
            if (Q==0.05)  VHML_Result = 147;
            if (Q==0.10)  VHML_Result = 154;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 123;
            if (Q==0.005) VHML_Result = 133;
            if (Q==0.010) VHML_Result = 138;
            if (Q==0.025) VHML_Result = 145;
            if (Q==0.05)  VHML_Result = 152;
            if (Q==0.10)  VHML_Result = 159;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 126;
            if (Q==0.005) VHML_Result = 136;
            if (Q==0.010) VHML_Result = 142;
            if (Q==0.025) VHML_Result = 150;
            if (Q==0.05)  VHML_Result = 156;
            if (Q==0.10)  VHML_Result = 165;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 129;
            if (Q==0.005) VHML_Result = 140;
            if (Q==0.010) VHML_Result = 146;
            if (Q==0.025) VHML_Result = 154;
            if (Q==0.05)  VHML_Result = 161;
            if (Q==0.10)  VHML_Result = 170;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 133;
            if (Q==0.005) VHML_Result = 144;
            if (Q==0.010) VHML_Result = 150;
            if (Q==0.025) VHML_Result = 158;
            if (Q==0.05)  VHML_Result = 166;
            if (Q==0.10)  VHML_Result = 175;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 136;
            if (Q==0.005) VHML_Result = 148;
            if (Q==0.010) VHML_Result = 154;
            if (Q==0.025) VHML_Result = 163;
            if (Q==0.05)  VHML_Result = 171;
            if (Q==0.10)  VHML_Result = 180;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 139;
            if (Q==0.005) VHML_Result = 151;
            if (Q==0.010) VHML_Result = 158;
            if (Q==0.025) VHML_Result = 167;
            if (Q==0.05)  VHML_Result = 175;
            if (Q==0.10)  VHML_Result = 185;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 142;
            if (Q==0.005) VHML_Result = 155;
            if (Q==0.010) VHML_Result = 162;
            if (Q==0.025) VHML_Result = 171;
            if (Q==0.05)  VHML_Result = 180;
            if (Q==0.10)  VHML_Result = 190;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 145;
            if (Q==0.005) VHML_Result = 159;
            if (Q==0.010) VHML_Result = 166;
            if (Q==0.025) VHML_Result = 176;
            if (Q==0.05)  VHML_Result = 185;
            if (Q==0.10)  VHML_Result = 195;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 149;
            if (Q==0.005) VHML_Result = 163;
            if (Q==0.010) VHML_Result = 170;
            if (Q==0.025) VHML_Result = 180;
            if (Q==0.05)  VHML_Result = 189;
            if (Q==0.10)  VHML_Result = 200;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 152;
            if (Q==0.005) VHML_Result = 166;
            if (Q==0.010) VHML_Result = 174;
            if (Q==0.025) VHML_Result = 185;
            if (Q==0.05)  VHML_Result = 194;
            if (Q==0.10)  VHML_Result = 205;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 155;
            if (Q==0.005) VHML_Result = 170;
            if (Q==0.010) VHML_Result = 178;
            if (Q==0.025) VHML_Result = 189;
            if (Q==0.05)  VHML_Result = 199;
            if (Q==0.10)  VHML_Result = 211;
        }
    }

    if (m==14)
    {
        if (n==14)
        {
            if (Q==0.001) VHML_Result = 137;
            if (Q==0.005) VHML_Result = 147;
            if (Q==0.010) VHML_Result = 152;
            if (Q==0.025) VHML_Result = 160;
            if (Q==0.05)  VHML_Result = 166;
            if (Q==0.10)  VHML_Result = 174;
        }

        if (n==15)
        {
            if (Q==0.001) VHML_Result = 141;
            if (Q==0.005) VHML_Result = 151;
            if (Q==0.010) VHML_Result = 156;
            if (Q==0.025) VHML_Result = 164;
            if (Q==0.05)  VHML_Result = 171;
            if (Q==0.10)  VHML_Result = 179;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 144;
            if (Q==0.005) VHML_Result = 155;
            if (Q==0.010) VHML_Result = 161;
            if (Q==0.025) VHML_Result = 169;
            if (Q==0.05)  VHML_Result = 176;
            if (Q==0.10)  VHML_Result = 185;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 148;
            if (Q==0.005) VHML_Result = 159;
            if (Q==0.010) VHML_Result = 165;
            if (Q==0.025) VHML_Result = 174;
            if (Q==0.05)  VHML_Result = 182;
            if (Q==0.10)  VHML_Result = 190;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 151;
            if (Q==0.005) VHML_Result = 163;
            if (Q==0.010) VHML_Result = 170;
            if (Q==0.025) VHML_Result = 179;
            if (Q==0.05)  VHML_Result = 187;
            if (Q==0.10)  VHML_Result = 196;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 155;
            if (Q==0.005) VHML_Result = 168;
            if (Q==0.010) VHML_Result = 174;
            if (Q==0.025) VHML_Result = 183;
            if (Q==0.05)  VHML_Result = 192;
            if (Q==0.10)  VHML_Result = 202;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 159;
            if (Q==0.005) VHML_Result = 172;
            if (Q==0.010) VHML_Result = 178;
            if (Q==0.025) VHML_Result = 188;
            if (Q==0.05)  VHML_Result = 197;
            if (Q==0.10)  VHML_Result = 207;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 162;
            if (Q==0.005) VHML_Result = 176;
            if (Q==0.010) VHML_Result = 183;
            if (Q==0.025) VHML_Result = 193;
            if (Q==0.05)  VHML_Result = 202;
            if (Q==0.10)  VHML_Result = 213;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 166;
            if (Q==0.005) VHML_Result = 180;
            if (Q==0.010) VHML_Result = 187;
            if (Q==0.025) VHML_Result = 198;
            if (Q==0.05)  VHML_Result = 207;
            if (Q==0.10)  VHML_Result = 218;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 169;
            if (Q==0.005) VHML_Result = 184;
            if (Q==0.010) VHML_Result = 192;
            if (Q==0.025) VHML_Result = 203;
            if (Q==0.05)  VHML_Result = 212;
            if (Q==0.10)  VHML_Result = 224;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 173;
            if (Q==0.005) VHML_Result = 188;
            if (Q==0.010) VHML_Result = 196;
            if (Q==0.025) VHML_Result = 207;
            if (Q==0.05)  VHML_Result = 218;
            if (Q==0.10)  VHML_Result = 229;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 177;
            if (Q==0.005) VHML_Result = 192;
            if (Q==0.010) VHML_Result = 200;
            if (Q==0.025) VHML_Result = 212;
            if (Q==0.05)  VHML_Result = 223;
            if (Q==0.10)  VHML_Result = 235;
        }
    }

    if (m==15)
    {
        if (n==15)
        {
            if (Q==0.001) VHML_Result = 160;
            if (Q==0.005) VHML_Result = 171;
            if (Q==0.010) VHML_Result = 176;
            if (Q==0.025) VHML_Result = 184;
            if (Q==0.05)  VHML_Result = 192;
            if (Q==0.10)  VHML_Result = 200;
        }

        if (n==16)
        {
            if (Q==0.001) VHML_Result = 163;
            if (Q==0.005) VHML_Result = 175;
            if (Q==0.010) VHML_Result = 181;
            if (Q==0.025) VHML_Result = 190;
            if (Q==0.05)  VHML_Result = 197;
            if (Q==0.10)  VHML_Result = 206;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 167;
            if (Q==0.005) VHML_Result = 180;
            if (Q==0.010) VHML_Result = 186;
            if (Q==0.025) VHML_Result = 195;
            if (Q==0.05)  VHML_Result = 203;
            if (Q==0.10)  VHML_Result = 212;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 171;
            if (Q==0.005) VHML_Result = 184;
            if (Q==0.010) VHML_Result = 190;
            if (Q==0.025) VHML_Result = 200;
            if (Q==0.05)  VHML_Result = 208;
            if (Q==0.10)  VHML_Result = 218;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 175;
            if (Q==0.005) VHML_Result = 189;
            if (Q==0.010) VHML_Result = 195;
            if (Q==0.025) VHML_Result = 205;
            if (Q==0.05)  VHML_Result = 214;
            if (Q==0.10)  VHML_Result = 224;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 179;
            if (Q==0.005) VHML_Result = 193;
            if (Q==0.010) VHML_Result = 200;
            if (Q==0.025) VHML_Result = 210;
            if (Q==0.05)  VHML_Result = 220;
            if (Q==0.10)  VHML_Result = 230;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 183;
            if (Q==0.005) VHML_Result = 198;
            if (Q==0.010) VHML_Result = 205;
            if (Q==0.025) VHML_Result = 216;
            if (Q==0.05)  VHML_Result = 225;
            if (Q==0.10)  VHML_Result = 236;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 187;
            if (Q==0.005) VHML_Result = 202;
            if (Q==0.010) VHML_Result = 210;
            if (Q==0.025) VHML_Result = 221;
            if (Q==0.05)  VHML_Result = 231;
            if (Q==0.10)  VHML_Result = 242;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 191;
            if (Q==0.005) VHML_Result = 207;
            if (Q==0.010) VHML_Result = 214;
            if (Q==0.025) VHML_Result = 226;
            if (Q==0.05)  VHML_Result = 236;
            if (Q==0.10)  VHML_Result = 248;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 195;
            if (Q==0.005) VHML_Result = 211;
            if (Q==0.010) VHML_Result = 219;
            if (Q==0.025) VHML_Result = 231;
            if (Q==0.05)  VHML_Result = 242;
            if (Q==0.10)  VHML_Result = 254;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 199;
            if (Q==0.005) VHML_Result = 216;
            if (Q==0.010) VHML_Result = 224;
            if (Q==0.025) VHML_Result = 237;
            if (Q==0.05)  VHML_Result = 248;
            if (Q==0.10)  VHML_Result = 260;
        }
    }

    if (m==16)
    {
        if (n==16)
        {
            if (Q==0.001) VHML_Result = 184;
            if (Q==0.005) VHML_Result = 196;
            if (Q==0.010) VHML_Result = 202;
            if (Q==0.025) VHML_Result = 211;
            if (Q==0.05)  VHML_Result = 219;
            if (Q==0.10)  VHML_Result = 229;
        }

        if (n==17)
        {
            if (Q==0.001) VHML_Result = 188;
            if (Q==0.005) VHML_Result = 201;
            if (Q==0.010) VHML_Result = 207;
            if (Q==0.025) VHML_Result = 217;
            if (Q==0.05)  VHML_Result = 225;
            if (Q==0.10)  VHML_Result = 235;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 192;
            if (Q==0.005) VHML_Result = 206;
            if (Q==0.010) VHML_Result = 212;
            if (Q==0.025) VHML_Result = 222;
            if (Q==0.05)  VHML_Result = 231;
            if (Q==0.10)  VHML_Result = 242;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 196;
            if (Q==0.005) VHML_Result = 210;
            if (Q==0.010) VHML_Result = 218;
            if (Q==0.025) VHML_Result = 228;
            if (Q==0.05)  VHML_Result = 237;
            if (Q==0.10)  VHML_Result = 248;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 201;
            if (Q==0.005) VHML_Result = 215;
            if (Q==0.010) VHML_Result = 223;
            if (Q==0.025) VHML_Result = 234;
            if (Q==0.05)  VHML_Result = 243;
            if (Q==0.10)  VHML_Result = 255;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 205;
            if (Q==0.005) VHML_Result = 220;
            if (Q==0.010) VHML_Result = 228;
            if (Q==0.025) VHML_Result = 239;
            if (Q==0.05)  VHML_Result = 249;
            if (Q==0.10)  VHML_Result = 261;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 209;
            if (Q==0.005) VHML_Result = 225;
            if (Q==0.010) VHML_Result = 233;
            if (Q==0.025) VHML_Result = 245;
            if (Q==0.05)  VHML_Result = 255;
            if (Q==0.10)  VHML_Result = 267;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 214;
            if (Q==0.005) VHML_Result = 230;
            if (Q==0.010) VHML_Result = 238;
            if (Q==0.025) VHML_Result = 251;
            if (Q==0.05)  VHML_Result = 261;
            if (Q==0.10)  VHML_Result = 274;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 218;
            if (Q==0.005) VHML_Result = 235;
            if (Q==0.010) VHML_Result = 244;
            if (Q==0.025) VHML_Result = 256;
            if (Q==0.05)  VHML_Result = 267;
            if (Q==0.10)  VHML_Result = 280;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 222;
            if (Q==0.005) VHML_Result = 240;
            if (Q==0.010) VHML_Result = 249;
            if (Q==0.025) VHML_Result = 262;
            if (Q==0.05)  VHML_Result = 273;
            if (Q==0.10)  VHML_Result = 287;
        }
    }

    if (m==17)
    {
        if (n==17)
        {
            if (Q==0.001) VHML_Result = 210;
            if (Q==0.005) VHML_Result = 223;
            if (Q==0.010) VHML_Result = 230;
            if (Q==0.025) VHML_Result = 240;
            if (Q==0.05)  VHML_Result = 249;
            if (Q==0.10)  VHML_Result = 259;
        }

        if (n==18)
        {
            if (Q==0.001) VHML_Result = 214;
            if (Q==0.005) VHML_Result = 228;
            if (Q==0.010) VHML_Result = 235;
            if (Q==0.025) VHML_Result = 246;
            if (Q==0.05)  VHML_Result = 255;
            if (Q==0.10)  VHML_Result = 266;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 219;
            if (Q==0.005) VHML_Result = 234;
            if (Q==0.010) VHML_Result = 241;
            if (Q==0.025) VHML_Result = 252;
            if (Q==0.05)  VHML_Result = 262;
            if (Q==0.10)  VHML_Result = 273;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 223;
            if (Q==0.005) VHML_Result = 239;
            if (Q==0.010) VHML_Result = 246;
            if (Q==0.025) VHML_Result = 258;
            if (Q==0.05)  VHML_Result = 268;
            if (Q==0.10)  VHML_Result = 280;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 228;
            if (Q==0.005) VHML_Result = 244;
            if (Q==0.010) VHML_Result = 252;
            if (Q==0.025) VHML_Result = 264;
            if (Q==0.05)  VHML_Result = 274;
            if (Q==0.10)  VHML_Result = 287;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 233;
            if (Q==0.005) VHML_Result = 249;
            if (Q==0.010) VHML_Result = 258;
            if (Q==0.025) VHML_Result = 270;
            if (Q==0.05)  VHML_Result = 281;
            if (Q==0.10)  VHML_Result = 294;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 238;
            if (Q==0.005) VHML_Result = 255;
            if (Q==0.010) VHML_Result = 263;
            if (Q==0.025) VHML_Result = 276;
            if (Q==0.05)  VHML_Result = 287;
            if (Q==0.10)  VHML_Result = 300;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 242;
            if (Q==0.005) VHML_Result = 260;
            if (Q==0.010) VHML_Result = 269;
            if (Q==0.025) VHML_Result = 282;
            if (Q==0.05)  VHML_Result = 294;
            if (Q==0.10)  VHML_Result = 307;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 247;
            if (Q==0.005) VHML_Result = 265;
            if (Q==0.010) VHML_Result = 275;
            if (Q==0.025) VHML_Result = 288;
            if (Q==0.05)  VHML_Result = 300;
            if (Q==0.10)  VHML_Result = 314;
        }

       }

    if (m==18)
    {
        if (n==18)
        {
            if (Q==0.001) VHML_Result = 237;
            if (Q==0.005) VHML_Result = 252;
            if (Q==0.010) VHML_Result = 259;
            if (Q==0.025) VHML_Result = 270;
            if (Q==0.05)  VHML_Result = 280;
            if (Q==0.10)  VHML_Result = 291;
        }

        if (n==19)
        {
            if (Q==0.001) VHML_Result = 242;
            if (Q==0.005) VHML_Result = 258;
            if (Q==0.010) VHML_Result = 265;
            if (Q==0.025) VHML_Result = 277;
            if (Q==0.05)  VHML_Result = 287;
            if (Q==0.10)  VHML_Result = 299;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 247;
            if (Q==0.005) VHML_Result = 263;
            if (Q==0.010) VHML_Result = 271;
            if (Q==0.025) VHML_Result = 283;
            if (Q==0.05)  VHML_Result = 294;
            if (Q==0.10)  VHML_Result = 306;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 252;
            if (Q==0.005) VHML_Result = 269;
            if (Q==0.010) VHML_Result = 277;
            if (Q==0.025) VHML_Result = 290;
            if (Q==0.05)  VHML_Result = 301;
            if (Q==0.10)  VHML_Result = 313;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 257;
            if (Q==0.005) VHML_Result = 275;
            if (Q==0.010) VHML_Result = 283;
            if (Q==0.025) VHML_Result = 296;
            if (Q==0.05)  VHML_Result = 307;
            if (Q==0.10)  VHML_Result = 321;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 262;
            if (Q==0.005) VHML_Result = 280;
            if (Q==0.010) VHML_Result = 289;
            if (Q==0.025) VHML_Result = 303;
            if (Q==0.05)  VHML_Result = 314;
            if (Q==0.10)  VHML_Result = 328;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 267;
            if (Q==0.005) VHML_Result = 286;
            if (Q==0.010) VHML_Result = 295;
            if (Q==0.025) VHML_Result = 309;
            if (Q==0.05)  VHML_Result = 321;
            if (Q==0.10)  VHML_Result = 335;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 273;
            if (Q==0.005) VHML_Result = 292;
            if (Q==0.010) VHML_Result = 301;
            if (Q==0.025) VHML_Result = 316;
            if (Q==0.05)  VHML_Result = 328;
            if (Q==0.10)  VHML_Result = 343;
        }
    }


    if (m==19)
    {
        if (n==19)
        {
            if (Q==0.001) VHML_Result = 267;
            if (Q==0.005) VHML_Result = 283;
            if (Q==0.010) VHML_Result = 291;
            if (Q==0.025) VHML_Result = 303;
            if (Q==0.05)  VHML_Result = 313;
            if (Q==0.10)  VHML_Result = 325;
        }

        if (n==20)
        {
            if (Q==0.001) VHML_Result = 272;
            if (Q==0.005) VHML_Result = 289;
            if (Q==0.010) VHML_Result = 297;
            if (Q==0.025) VHML_Result = 309;
            if (Q==0.05)  VHML_Result = 320;
            if (Q==0.10)  VHML_Result = 333;
        }

        if (n==21)
        {
            if (Q==0.001) VHML_Result = 277;
            if (Q==0.005) VHML_Result = 295;
            if (Q==0.010) VHML_Result = 303;
            if (Q==0.025) VHML_Result = 316;
            if (Q==0.05)  VHML_Result = 328;
            if (Q==0.10)  VHML_Result = 341;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 283;
            if (Q==0.005) VHML_Result = 301;
            if (Q==0.010) VHML_Result = 310;
            if (Q==0.025) VHML_Result = 323;
            if (Q==0.05)  VHML_Result = 335;
            if (Q==0.10)  VHML_Result = 349;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 288;
            if (Q==0.005) VHML_Result = 307;
            if (Q==0.010) VHML_Result = 316;
            if (Q==0.025) VHML_Result = 330;
            if (Q==0.05)  VHML_Result = 342;
            if (Q==0.10)  VHML_Result = 357;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 294;
            if (Q==0.005) VHML_Result = 313;
            if (Q==0.010) VHML_Result = 323;
            if (Q==0.025) VHML_Result = 337;
            if (Q==0.05)  VHML_Result = 350;
            if (Q==0.10)  VHML_Result = 364;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 299;
            if (Q==0.005) VHML_Result = 319;
            if (Q==0.010) VHML_Result = 329;
            if (Q==0.025) VHML_Result = 344;
            if (Q==0.05)  VHML_Result = 357;
            if (Q==0.10)  VHML_Result = 372;
        }

    }


        if (m==20)
        {
            if (n==20)
            {
                if (Q==0.001) VHML_Result = 298;
                if (Q==0.005) VHML_Result = 315;
                if (Q==0.010) VHML_Result = 324;
                if (Q==0.025) VHML_Result = 337;
                if (Q==0.05)  VHML_Result = 348;
                if (Q==0.10)  VHML_Result = 361;
            }

            if (n==21)
            {
                if (Q==0.001) VHML_Result = 304;
                if (Q==0.005) VHML_Result = 322;
                if (Q==0.010) VHML_Result = 331;
                if (Q==0.025) VHML_Result = 344;
                if (Q==0.05)  VHML_Result = 356;
                if (Q==0.10)  VHML_Result = 370;
            }

            if (n==22)
            {
                if (Q==0.001) VHML_Result = 309;
                if (Q==0.005) VHML_Result = 328;
                if (Q==0.010) VHML_Result = 337;
                if (Q==0.025) VHML_Result = 351;
                if (Q==0.05)  VHML_Result = 364;
                if (Q==0.10)  VHML_Result = 378;
            }

            if (n==23)
            {
                if (Q==0.001) VHML_Result = 315;
                if (Q==0.005) VHML_Result = 335;
                if (Q==0.010) VHML_Result = 344;
                if (Q==0.025) VHML_Result = 359;
                if (Q==0.05)  VHML_Result = 371;
                if (Q==0.10)  VHML_Result = 386;
            }

            if (n==24)
            {
                if (Q==0.001) VHML_Result = 321;
                if (Q==0.005) VHML_Result = 341;
                if (Q==0.010) VHML_Result = 351;
                if (Q==0.025) VHML_Result = 366;
                if (Q==0.05)  VHML_Result = 379;
                if (Q==0.10)  VHML_Result = 394;
            }

            if (n==25)
            {
                if (Q==0.001) VHML_Result = 327;
                if (Q==0.005) VHML_Result = 348;
                if (Q==0.010) VHML_Result = 358;
                if (Q==0.025) VHML_Result = 373;
                if (Q==0.05)  VHML_Result = 387;
                if (Q==0.10)  VHML_Result = 403;
            }
        }

    if (m==21)
    {
        if (n==21)
        {
            if (Q==0.001) VHML_Result = 331;
            if (Q==0.005) VHML_Result = 349;
            if (Q==0.010) VHML_Result = 359;
            if (Q==0.025) VHML_Result = 373;
            if (Q==0.05)  VHML_Result = 385;
            if (Q==0.10)  VHML_Result = 399;
        }

        if (n==22)
        {
            if (Q==0.001) VHML_Result = 337;
            if (Q==0.005) VHML_Result = 356;
            if (Q==0.010) VHML_Result = 366;
            if (Q==0.025) VHML_Result = 381;
            if (Q==0.05)  VHML_Result = 393;
            if (Q==0.10)  VHML_Result = 408;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 343;
            if (Q==0.005) VHML_Result = 363;
            if (Q==0.010) VHML_Result = 373;
            if (Q==0.025) VHML_Result = 388;
            if (Q==0.05)  VHML_Result = 401;
            if (Q==0.10)  VHML_Result = 417;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 349;
            if (Q==0.005) VHML_Result = 370;
            if (Q==0.010) VHML_Result = 381;
            if (Q==0.025) VHML_Result = 396;
            if (Q==0.05)  VHML_Result = 410;
            if (Q==0.10)  VHML_Result = 425;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 356;
            if (Q==0.005) VHML_Result = 377;
            if (Q==0.010) VHML_Result = 388;
            if (Q==0.025) VHML_Result = 404;
            if (Q==0.05)  VHML_Result = 418;
            if (Q==0.10)  VHML_Result = 434;
        }
    }

    if (m==22)
    {
        if (n==22)
        {
            if (Q==0.001) VHML_Result = 365;
            if (Q==0.005) VHML_Result = 386;
            if (Q==0.010) VHML_Result = 396;
            if (Q==0.025) VHML_Result = 411;
            if (Q==0.05)  VHML_Result = 424;
            if (Q==0.10)  VHML_Result = 439;
        }

        if (n==23)
        {
            if (Q==0.001) VHML_Result = 372;
            if (Q==0.005) VHML_Result = 393;
            if (Q==0.010) VHML_Result = 403;
            if (Q==0.025) VHML_Result = 419;
            if (Q==0.05)  VHML_Result = 432;
            if (Q==0.10)  VHML_Result = 448;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 379;
            if (Q==0.005) VHML_Result = 400;
            if (Q==0.010) VHML_Result = 411;
            if (Q==0.025) VHML_Result = 427;
            if (Q==0.05)  VHML_Result = 441;
            if (Q==0.10)  VHML_Result = 457;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 385;
            if (Q==0.005) VHML_Result = 408;
            if (Q==0.010) VHML_Result = 419;
            if (Q==0.025) VHML_Result = 435;
            if (Q==0.05)  VHML_Result = 450;
            if (Q==0.10)  VHML_Result = 467;
        }
    }

    if (m==23)
    {
        if (n==23)
        {
            if (Q==0.001) VHML_Result = 402;
            if (Q==0.005) VHML_Result = 424;
            if (Q==0.010) VHML_Result = 434;
            if (Q==0.025) VHML_Result = 451;
            if (Q==0.05)  VHML_Result = 465;
            if (Q==0.10)  VHML_Result = 481;
        }

        if (n==24)
        {
            if (Q==0.001) VHML_Result = 402;
            if (Q==0.005) VHML_Result = 431;
            if (Q==0.010) VHML_Result = 443;
            if (Q==0.025) VHML_Result = 459;
            if (Q==0.05)  VHML_Result = 474;
            if (Q==0.10)  VHML_Result = 491;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 416;
            if (Q==0.005) VHML_Result = 439;
            if (Q==0.010) VHML_Result = 451;
            if (Q==0.025) VHML_Result = 468;
            if (Q==0.05)  VHML_Result = 483;
            if (Q==0.10)  VHML_Result = 500;
        }
    }

    if (m==24)
    {
        if (n==24)
        {
            if (Q==0.001) VHML_Result = 440;
            if (Q==0.005) VHML_Result = 464;
            if (Q==0.010) VHML_Result = 475;
            if (Q==0.025) VHML_Result = 492;
            if (Q==0.05)  VHML_Result = 507;
            if (Q==0.10)  VHML_Result = 525;
        }

        if (n==25)
        {
            if (Q==0.001) VHML_Result = 448;
            if (Q==0.005) VHML_Result = 472;
            if (Q==0.010) VHML_Result = 484;
            if (Q==0.025) VHML_Result = 501;
            if (Q==0.05)  VHML_Result = 517;
            if (Q==0.10)  VHML_Result = 535;
        }
    }

    if (m==25)
    {
        if (n==25)
        {
            if (Q==0.001) VHML_Result = 480;
            if (Q==0.005) VHML_Result = 505;
            if (Q==0.010) VHML_Result = 517;
            if (Q==0.025) VHML_Result = 536;
            if (Q==0.05)  VHML_Result = 552;
            if (Q==0.10)  VHML_Result = 570;
        }
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_RightBorderOfWilcoxonWFromTable(int m, int n, double Q)
{
    /*
    Функция возвращает правую границу интервала критический значений статистики W для критерия Вилкоксена по табличным данным.
    Входные параметры:
     m - объем первой выборки (не больше 25);
     n - объем второй выборки (не больше 25);
     Q - уровень значимости. Может принимать значения:
      0.001;
      0.005;
      0.01;
      0.025;
      0.05;
      0.1.
    Возвращаемое значение:
     Правая граница интервала критический значений статистики W для критерия Вилкоксена.
    Примечание:
     Если размеры выборок не из таблицы, если не правильный выбран уровень значимости, то возвратится -1.
    */
    double VHML_Result=-1;

    if (n<m)  HML_NumberInterchange(&n,&m);//вначале должна идти выборка с меньшим объемом

    //Получим леdую границу
    double LeftBorder=HML_LeftBorderOfWilcoxonWFromTable(m, n, Q);

    if (LeftBorder==-1) return -1;

    if (m==1)
    {
        if (n==2)  VHML_Result = 4;
        if (n==3)  VHML_Result = 5;
        if (n==4)  VHML_Result = 6;
        if (n==5)  VHML_Result = 7;
        if (n==6)  VHML_Result = 8;
        if (n==7)  VHML_Result = 9;
        if (n==8)  VHML_Result = 10;
        if (n==9)  VHML_Result = 11;
        if (n==10) VHML_Result = 12;
        if (n==11) VHML_Result = 13;
        if (n==12) VHML_Result = 14;
        if (n==13) VHML_Result = 15;
        if (n==14) VHML_Result = 16;
        if (n==15) VHML_Result = 17;
        if (n==16) VHML_Result = 18;
        if (n==17) VHML_Result = 19;
        if (n==18) VHML_Result = 20;
        if (n==19) VHML_Result = 21;
        if (n==20) VHML_Result = 22;
        if (n==21) VHML_Result = 23;
        if (n==22) VHML_Result = 24;
        if (n==23) VHML_Result = 25;
        if (n==24) VHML_Result = 26;
        if (n==25) VHML_Result = 27;
    }

    if (m==2)
    {
        if (n==2)  VHML_Result = 10;
        if (n==3)  VHML_Result = 12;
        if (n==4)  VHML_Result = 14;
        if (n==5)  VHML_Result = 16;
        if (n==6)  VHML_Result = 18;
        if (n==7)  VHML_Result = 20;
        if (n==8)  VHML_Result = 22;
        if (n==9)  VHML_Result = 24;
        if (n==10) VHML_Result = 26;
        if (n==11) VHML_Result = 28;
        if (n==12) VHML_Result = 30;
        if (n==13) VHML_Result = 32;
        if (n==14) VHML_Result = 34;
        if (n==15) VHML_Result = 36;
        if (n==16) VHML_Result = 38;
        if (n==17) VHML_Result = 40;
        if (n==18) VHML_Result = 42;
        if (n==19) VHML_Result = 44;
        if (n==20) VHML_Result = 46;
        if (n==21) VHML_Result = 48;
        if (n==22) VHML_Result = 50;
        if (n==23) VHML_Result = 52;
        if (n==24) VHML_Result = 54;
        if (n==25) VHML_Result = 56;
    }

    if (m==3)
    {
        if (n==3)  VHML_Result = 21;
        if (n==4)  VHML_Result = 24;
        if (n==5)  VHML_Result = 27;
        if (n==6)  VHML_Result = 30;
        if (n==7)  VHML_Result = 33;
        if (n==8)  VHML_Result = 36;
        if (n==9)  VHML_Result = 39;
        if (n==10) VHML_Result = 42;
        if (n==11) VHML_Result = 45;
        if (n==12) VHML_Result = 48;
        if (n==13) VHML_Result = 51;
        if (n==14) VHML_Result = 54;
        if (n==15) VHML_Result = 57;
        if (n==16) VHML_Result = 60;
        if (n==17) VHML_Result = 63;
        if (n==18) VHML_Result = 66;
        if (n==19) VHML_Result = 69;
        if (n==20) VHML_Result = 72;
        if (n==21) VHML_Result = 75;
        if (n==22) VHML_Result = 78;
        if (n==23) VHML_Result = 81;
        if (n==24) VHML_Result = 84;
        if (n==25) VHML_Result = 87;
    }

    if (m==4)
    {
        if (n==4)  VHML_Result = 36;
        if (n==5)  VHML_Result = 40;
        if (n==6)  VHML_Result = 44;
        if (n==7)  VHML_Result = 48;
        if (n==8)  VHML_Result = 52;
        if (n==9)  VHML_Result = 56;
        if (n==10) VHML_Result = 60;
        if (n==11) VHML_Result = 64;
        if (n==12) VHML_Result = 68;
        if (n==13) VHML_Result = 72;
        if (n==14) VHML_Result = 76;
        if (n==15) VHML_Result = 80;
        if (n==16) VHML_Result = 84;
        if (n==17) VHML_Result = 88;
        if (n==18) VHML_Result = 92;
        if (n==19) VHML_Result = 96;
        if (n==20) VHML_Result = 100;
        if (n==21) VHML_Result = 104;
        if (n==22) VHML_Result = 108;
        if (n==23) VHML_Result = 112;
        if (n==24) VHML_Result = 116;
        if (n==25) VHML_Result = 120;
    }

    if (m==5)
    {
        if (n==5)  VHML_Result = 55;
        if (n==6)  VHML_Result = 60;
        if (n==7)  VHML_Result = 65;
        if (n==8)  VHML_Result = 70;
        if (n==9)  VHML_Result = 75;
        if (n==10) VHML_Result = 80;
        if (n==11) VHML_Result = 85;
        if (n==12) VHML_Result = 90;
        if (n==13) VHML_Result = 95;
        if (n==14) VHML_Result = 100;
        if (n==15) VHML_Result = 105;
        if (n==16) VHML_Result = 110;
        if (n==17) VHML_Result = 115;
        if (n==18) VHML_Result = 120;
        if (n==19) VHML_Result = 125;
        if (n==20) VHML_Result = 130;
        if (n==21) VHML_Result = 135;
        if (n==22) VHML_Result = 140;
        if (n==23) VHML_Result = 145;
        if (n==24) VHML_Result = 150;
        if (n==25) VHML_Result = 155;
    }

    if (m==6)
    {
        if (n==6)  VHML_Result = 78;
        if (n==7)  VHML_Result = 84;
        if (n==8)  VHML_Result = 90;
        if (n==9)  VHML_Result = 96;
        if (n==10) VHML_Result = 102;
        if (n==11) VHML_Result = 108;
        if (n==12) VHML_Result = 114;
        if (n==13) VHML_Result = 120;
        if (n==14) VHML_Result = 126;
        if (n==15) VHML_Result = 132;
        if (n==16) VHML_Result = 138;
        if (n==17) VHML_Result = 144;
        if (n==18) VHML_Result = 150;
        if (n==19) VHML_Result = 156;
        if (n==20) VHML_Result = 162;
        if (n==21) VHML_Result = 168;
        if (n==22) VHML_Result = 174;
        if (n==23) VHML_Result = 180;
        if (n==24) VHML_Result = 186;
        if (n==25) VHML_Result = 192;
    }

    if (m==7)
    {
        if (n==7)  VHML_Result = 105;
        if (n==8)  VHML_Result = 112;
        if (n==9)  VHML_Result = 119;
        if (n==10) VHML_Result = 126;
        if (n==11) VHML_Result = 133;
        if (n==12) VHML_Result = 140;
        if (n==13) VHML_Result = 147;
        if (n==14) VHML_Result = 154;
        if (n==15) VHML_Result = 161;
        if (n==16) VHML_Result = 168;
        if (n==17) VHML_Result = 175;
        if (n==18) VHML_Result = 182;
        if (n==19) VHML_Result = 189;
        if (n==20) VHML_Result = 196;
        if (n==21) VHML_Result = 203;
        if (n==22) VHML_Result = 210;
        if (n==23) VHML_Result = 217;
        if (n==24) VHML_Result = 224;
        if (n==25) VHML_Result = 231;
    }

    if (m==8)
    {
        if (n==8)  VHML_Result = 136;
        if (n==9)  VHML_Result = 144;
        if (n==10) VHML_Result = 152;
        if (n==11) VHML_Result = 160;
        if (n==12) VHML_Result = 168;
        if (n==13) VHML_Result = 176;
        if (n==14) VHML_Result = 184;
        if (n==15) VHML_Result = 192;
        if (n==16) VHML_Result = 200;
        if (n==17) VHML_Result = 208;
        if (n==18) VHML_Result = 216;
        if (n==19) VHML_Result = 224;
        if (n==20) VHML_Result = 232;
        if (n==21) VHML_Result = 240;
        if (n==22) VHML_Result = 248;
        if (n==23) VHML_Result = 256;
        if (n==24) VHML_Result = 264;
        if (n==25) VHML_Result = 272;
    }

    if (m==9)
    {
        if (n==9)  VHML_Result = 171;
        if (n==10) VHML_Result = 180;
        if (n==11) VHML_Result = 189;
        if (n==12) VHML_Result = 198;
        if (n==13) VHML_Result = 207;
        if (n==14) VHML_Result = 216;
        if (n==15) VHML_Result = 225;
        if (n==16) VHML_Result = 234;
        if (n==17) VHML_Result = 243;
        if (n==18) VHML_Result = 252;
        if (n==19) VHML_Result = 261;
        if (n==20) VHML_Result = 270;
        if (n==21) VHML_Result = 279;
        if (n==22) VHML_Result = 288;
        if (n==23) VHML_Result = 297;
        if (n==24) VHML_Result = 306;
        if (n==25) VHML_Result = 315;
    }

    if (m==10)
    {
        if (n==10) VHML_Result = 210;
        if (n==11) VHML_Result = 220;
        if (n==12) VHML_Result = 230;
        if (n==13) VHML_Result = 240;
        if (n==14) VHML_Result = 250;
        if (n==15) VHML_Result = 260;
        if (n==16) VHML_Result = 270;
        if (n==17) VHML_Result = 280;
        if (n==18) VHML_Result = 290;
        if (n==19) VHML_Result = 300;
        if (n==20) VHML_Result = 310;
        if (n==21) VHML_Result = 320;
        if (n==22) VHML_Result = 330;
        if (n==23) VHML_Result = 340;
        if (n==24) VHML_Result = 350;
        if (n==25) VHML_Result = 360;
    }

    if (m==11)
    {
        if (n==11) VHML_Result = 253;
        if (n==12) VHML_Result = 264;
        if (n==13) VHML_Result = 275;
        if (n==14) VHML_Result = 286;
        if (n==15) VHML_Result = 297;
        if (n==16) VHML_Result = 308;
        if (n==17) VHML_Result = 319;
        if (n==18) VHML_Result = 330;
        if (n==19) VHML_Result = 341;
        if (n==20) VHML_Result = 352;
        if (n==21) VHML_Result = 363;
        if (n==22) VHML_Result = 374;
        if (n==23) VHML_Result = 385;
        if (n==24) VHML_Result = 396;
        if (n==25) VHML_Result = 407;
    }

    if (m==12)
    {
        if (n==12) VHML_Result = 300;
        if (n==13) VHML_Result = 312;
        if (n==14) VHML_Result = 324;
        if (n==15) VHML_Result = 336;
        if (n==16) VHML_Result = 348;
        if (n==17) VHML_Result = 360;
        if (n==18) VHML_Result = 372;
        if (n==19) VHML_Result = 384;
        if (n==20) VHML_Result = 396;
        if (n==21) VHML_Result = 408;
        if (n==22) VHML_Result = 420;
        if (n==23) VHML_Result = 432;
        if (n==24) VHML_Result = 444;
        if (n==25) VHML_Result = 456;
    }

    if (m==13)
    {
        if (n==13) VHML_Result = 351;
        if (n==14) VHML_Result = 364;
        if (n==15) VHML_Result = 377;
        if (n==16) VHML_Result = 390;
        if (n==17) VHML_Result = 403;
        if (n==18) VHML_Result = 416;
        if (n==19) VHML_Result = 429;
        if (n==20) VHML_Result = 442;
        if (n==21) VHML_Result = 455;
        if (n==22) VHML_Result = 468;
        if (n==23) VHML_Result = 481;
        if (n==24) VHML_Result = 494;
        if (n==25) VHML_Result = 507;
    }

    if (m==14)
    {
        if (n==14) VHML_Result = 406;
        if (n==15) VHML_Result = 420;
        if (n==16) VHML_Result = 434;
        if (n==17) VHML_Result = 448;
        if (n==18) VHML_Result = 462;
        if (n==19) VHML_Result = 476;
        if (n==20) VHML_Result = 490;
        if (n==21) VHML_Result = 504;
        if (n==22) VHML_Result = 518;
        if (n==23) VHML_Result = 532;
        if (n==24) VHML_Result = 546;
        if (n==25) VHML_Result = 560;
    }

    if (m==15)
    {
        if (n==15) VHML_Result = 465;
        if (n==16) VHML_Result = 480;
        if (n==17) VHML_Result = 495;
        if (n==18) VHML_Result = 510;
        if (n==19) VHML_Result = 525;
        if (n==20) VHML_Result = 540;
        if (n==21) VHML_Result = 555;
        if (n==22) VHML_Result = 570;
        if (n==23) VHML_Result = 585;
        if (n==24) VHML_Result = 600;
        if (n==25) VHML_Result = 615;
    }

    if (m==16)
    {
        if (n==16) VHML_Result = 528;
        if (n==17) VHML_Result = 544;
        if (n==18) VHML_Result = 560;
        if (n==19) VHML_Result = 576;
        if (n==20) VHML_Result = 592;
        if (n==21) VHML_Result = 608;
        if (n==22) VHML_Result = 624;
        if (n==23) VHML_Result = 640;
        if (n==24) VHML_Result = 656;
        if (n==25) VHML_Result = 672;
    }

    if (m==17)
    {
        if (n==17) VHML_Result = 595;
        if (n==18) VHML_Result = 612;
        if (n==19) VHML_Result = 629;
        if (n==20) VHML_Result = 646;
        if (n==21) VHML_Result = 663;
        if (n==22) VHML_Result = 680;
        if (n==23) VHML_Result = 697;
        if (n==24) VHML_Result = 714;
        if (n==25) VHML_Result = 731;
    }

    if (m==18)
    {
        if (n==18) VHML_Result = 666;
        if (n==19) VHML_Result = 684;
        if (n==20) VHML_Result = 702;
        if (n==21) VHML_Result = 720;
        if (n==22) VHML_Result = 738;
        if (n==23) VHML_Result = 756;
        if (n==24) VHML_Result = 774;
        if (n==25) VHML_Result = 792;
    }

    if (m==19)
    {
        if (n==19) VHML_Result = 741;
        if (n==20) VHML_Result = 760;
        if (n==21) VHML_Result = 779;
        if (n==22) VHML_Result = 798;
        if (n==23) VHML_Result = 817;
        if (n==24) VHML_Result = 836;
        if (n==25) VHML_Result = 855;
    }

    if (m==20)
    {
        if (n==20) VHML_Result = 820;
        if (n==21) VHML_Result = 840;
        if (n==22) VHML_Result = 860;
        if (n==23) VHML_Result = 880;
        if (n==24) VHML_Result = 900;
        if (n==25) VHML_Result = 920;
    }

    if (m==21)
    {
        if (n==21) VHML_Result = 903;
        if (n==22) VHML_Result = 924;
        if (n==23) VHML_Result = 945;
        if (n==24) VHML_Result = 966;
        if (n==25) VHML_Result = 987;
    }

    if (m==22)
    {
        if (n==22) VHML_Result = 990;
        if (n==23) VHML_Result = 1012;
        if (n==24) VHML_Result = 1034;
        if (n==25) VHML_Result = 1056;
    }

    if (m==23)
    {
        if (n==23) VHML_Result = 1081;
        if (n==24) VHML_Result = 1104;
        if (n==25) VHML_Result = 1127;
    }

    if (m==24)
    {
        if (n==24) VHML_Result = 1176;
        if (n==25) VHML_Result = 1200;
    }

    if (m==25)
    {
        if (n==25) VHML_Result = 1275;
    }

    return (VHML_Result-LeftBorder);
}
//---------------------------------------------------------------------------

double HML_StdDevToVariance(double StdDev)
{
/*
Функция переводит среднеквадратичное уклонение в значение дисперсии случайной величины.
Входные параметры:
 StdDev - среднеквадратичное уклонение.
Возвращаемое значение:
 Значение выборочной дисперсии случайной величины.
*/
return StdDev*StdDev;
}
//---------------------------------------------------------------------------

double HML_VarianceToStdDev(double Variance)
{
/*
Функция переводит значение выборочной дисперсии случайной величины в среднеквадратичное уклонение.
Входные параметры:
 Variance - значение дисперсии случайной величины.
Возвращаемое значение:
 Значение среднеквадратичного уклонения.
*/
return sqrt(Variance);
}
//---------------------------------------------------------------------------

int HML_WilcoxonW(double *a, double *b, int VHML_N1, int VHML_N2, double Q)
{
/*
Функция проверяет однородность выборок по критерию Вилкосена W.
Входные параметры:
 a - первая выборка;
 b - вторая выборка;
 VHML_N1 - размер первой выборки;
 VHML_N2 - размер второй выборки;
 Q - уровень значимости. Может принимать значения:
  0.002;
  0.01;
  0.02;
  0.05;
  0.1;
  0.2.
Возвращаемое значение:
 -2 - уровень значимости выбран неправильно (не из допустимого множества);
 -1 - объемы выборок не позволяют провести проверку при данном уровне значимости (или они не положительные);
 0 - выборки не однородны  при данном уровне значимости;
 1 - выборки однородны  при данном уровне значимости;
*/
int VHML_Result;

double Lr, Rr, Wr;

VHML_Result = HML_WilcoxonW(a, b,VHML_N1, VHML_N2, Q, &Lr, &Rr, &Wr);

return VHML_Result;
}
//---------------------------------------------------------------------------

int HML_WilcoxonW(double *a, double *b, int VHML_N1, int VHML_N2, double Q, double *Lr, double *Rr, double *Wr)
{
/*
Функция проверяет однородность выборок по критерию Вилкосена W.
Входные параметры:
 a - первая выборка;
 b - вторая выборка;
 VHML_N1 - размер первой выборки;
 VHML_N2 - размер второй выборки;
 Q - уровень значимости. Может принимать значения:
  0.002;
  0.01;
  0.02;
  0.05;
  0.1;
  0.2.
 Lr - сюда возвращается значение левой границы интервала критический значений статистики W для критерия Вилкоксена;
 Rr - сюда возвращается значение правой границы интервала критический значений статистики W для критерия Вилкоксена;
 Wr - сюда возвращается значение посчитанная статистика W для критерия Вилкоксена;

Возвращаемое значение:
 -2 - уровень значимости выбран неправильно (не из допустимого множества);
 -1 - объемы выборок не позволяют провести проверку при данном уровне значимости (или они не положительные);
 0 - выборки не однородны  при данном уровне значимости;
 1 - выборки однородны  при данном уровне значимости;
*/
int VHML_Result=-2;

bool checkQ=false;
if (Q==0.002) checkQ=true;
if (Q==0.01)  checkQ=true;
if (Q==0.02)  checkQ=true;
if (Q==0.05)  checkQ=true;
if (Q==0.1)   checkQ=true;
if (Q==0.2)   checkQ=true;
if (checkQ==false) return VHML_Result;// уровень значимости выбран не допустимого множества

//проверим правильность размеров выборки
VHML_Result=-1;
if (VHML_N1<=0) return VHML_Result;
if (VHML_N2<=0) return VHML_Result;
//Если одной выборки много по числу элементов, а второй мало, то статистика выдаст некорректные результаты
if ((VHML_N1>25)&&(VHML_N2<5)) return VHML_Result;
if ((VHML_N2>25)&&(VHML_N1<5)) return VHML_Result;

int i;
double *All=new double[VHML_N1+VHML_N2];//объединенный массив
double *Rank=new double[VHML_N1+VHML_N2];//ранги

double W=0;//значение статистики критерия Вилкосена

//заполняем объединенный массив
for (i=0;i<VHML_N1;i++) All[i]=a[i];//заливаем первую выборку
for (i=0;i<VHML_N2;i++) All[i+VHML_N1]=b[i];//заливаем вторую выборку

//проставляем ранги
HML_MakeVectorOfRankForRankSelection(All, Rank,VHML_N1+VHML_N2);

//подсчитываем значение статистики W критерия Вилкосена
if (VHML_N1<=VHML_N2)
    for (i=0;i<VHML_N1;i++) W += Rank[i];
else
    for (i=0;i<VHML_N2;i++) W += Rank[i+VHML_N1];

//Границы интервала критический значений статистики W для критерия Вилкоксена
double Left;
double Right;

if ((VHML_N1<=25)&&(VHML_N2<=25))
{
    //Берем значения из таблицы
    Left=HML_LeftBorderOfWilcoxonWFromTable(VHML_N1,VHML_N2,Q/2.);
    Right=HML_RightBorderOfWilcoxonWFromTable(VHML_N1,VHML_N2,Q/2.);
    if ((Left==-1)||(Right==-1)) return -1;//При таких размерах нельзя провести корректную проверку
}
else
{
    //В таблице значений для таких объемов выборки нет, поэтому проводим пересчет
    double m,n;
    if (VHML_N1<=VHML_N2)
    {
        m=VHML_N1;
        n=VHML_N2;
    }
    else
    {
        m=VHML_N2;
        n=VHML_N1;
    }

    double MW2=2*m*(m+n+1)/2.;

    double f1=(m*(m+n+1)-1)/2.;
    double f2=sqrt(m*n*(m+n+1)/12.);

    double h;
    //Берем значения обратной функции нормального распределения при значении 1-Q/2, так как
    //мы учитываем две критические границы
    if (Q==0.002) h=3.090232;//0.999
    if (Q==0.01)  h=2.575829;//0.995
    if (Q==0.02)  h=2.326348;//0.99
    if (Q==0.05)  h=1.959964;//0.975
    if (Q==0.1)   h=1.644854;//0.95
    if (Q==0.2)   h=1.281552;//0.9

    Left=int(f1-h*f2);
    Right=MW2-Left;
}

//Теперь проведем непосредственно проверку гипотезу об однородности выборок
if ((W>=Left)&&(W<=Right))
    VHML_Result = 1;//выборки однородны
else
    VHML_Result = 0;//выборки не однородны

delete [] All;
delete [] Rank;

*Lr = Left;
*Rr = Right;
*Wr = W;

return VHML_Result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//*****************************************************************
//Тестовые функции для оптимизации
//*****************************************************************
double HML_TestFunction_Ackley(double *x, int VHML_N)
{
/*
Функция многих переменных: Ackley.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result;
double f1,f2=0;
f1=exp(-0.2*sqrt(HML_SumSquareVector(x,VHML_N)/double(VHML_N)));
for (int i=0;i<VHML_N;i++) f2=f2+cos(2.*HML_PI*x[i]);
f2=exp(f2/double(VHML_N));
VHML_Result=20.+exp(1.)-20.*f1-f2;
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_AdditivePotential(double x, double y)
{
/*
Функция двух переменных: аддитивная потенциальная функция.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
double z1=-(1./((x-1.)*(x-1.)+0.2))-(1./(2.*(x-2.)*(x-2.)+0.15))-(1./(3.*(x-3.)*(x-3.)+0.3));
double z2=-(1./((y-1.)*(y-1.)+0.2))-(1./(2.*(y-2.)*(y-2.)+0.15))-(1./(3.*(y-3.)*(y-3.)+0.3));
VHML_Result=z1+z2;
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Bosom(double x, double y)
{
/*
Функция двух переменных: функция Bosom.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
double sk1=-((x-4)*(x-4)+(y-4)*(y-4))*((x-4)*(x-4)+(y-4)*(y-4));
double sk2=-((x+4)*(x+4)+(y+4)*(y+4))*((x+4)*(x+4)+(y+4)*(y+4));

VHML_Result=exp(sk1/1000.)+exp(sk2/1000.)+0.15*exp(sk1)+0.15*exp(sk2);
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_EggHolder(double x, double y)
{
/*
Функция двух переменных: функция Egg Holder.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;

VHML_Result=-x*sin(sqrt(fabs(x-(y+47.))))-(y+47)*sin(sqrt(fabs(x/2.+47+y)));

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_GaussianQuartic(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Gaussian quartic.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;

for (int i=0;i<VHML_N;i++) VHML_Result+=(i+1)*x[i]*x[i]*x[i]*x[i];

VHML_Result+=HML_RandomNormal(0, 1);

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Griewangk(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Гриванка.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
double f=1;
int i;

for (i=0;i<VHML_N;i++) VHML_Result+=x[i]*x[i];
VHML_Result/=4000.;

for (i=0;i<VHML_N;i++) f=f*cos(x[i]/sqrt(i+1));

VHML_Result=VHML_Result-f+1.;

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Himmelblau(double x, double y)
{
/*
Функция двух переменных: функция Химмельблау.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
VHML_Result=(x*x+y-11)*(x*x+y-11)+(x+y*y-7)*(x+y*y-7);
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_HyperEllipsoid(double *x, int VHML_N)
{
/*
Функция многих переменных: Гипер-эллипсоид.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;

for (int i=0;i<VHML_N;i++)
	VHML_Result += (i+1)*(i+1)*x[i]*x[i];

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_InvertedRosenbrock(double x, double y)
{
/*
Функция двух переменных: перевернутая функция Розенброка.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;

VHML_Result=-100./(100.*(x*x-y)+(1.-x)*(1.-x)+600.);

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Katnikov(double x, double y)
{
/*
Функция двух переменных: функция Катникова.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
double A=0.8;
VHML_Result=0.5*(x*x+y*y)*(2*A+A*cos(1.5*x)*cos(3.14*y)+A*cos(sqrt(5)*x)*cos(3.5*y));
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Multiextremal(double x)
{
/*
Функция одной переменных: функция Multiextremal.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x).
*/
double VHML_Result;
VHML_Result = (0.05*(x-1.)*(x-1.)+(3.-2.9*exp(-2.77257*x*x))*(1-cos(x*(4.-50*exp(-2.77257*x*x)))));
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Multiextremal2(double x)
{
/*
Функция одной переменных: функция Multiextremal2.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x).
*/
double VHML_Result;
VHML_Result = 1.-0.5*cos(1.5*(10.*x-0.3))*cos(31.4*x)+0.5*cos(sqrt(5.)*10.*x)*cos(35.*x);
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Multiextremal3(double x, double y)
{
/*
Функция двух переменных: функция Multiextremal3.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
VHML_Result=x*x*fabs(sin(2.*x))+y*y*fabs(sin(2.*y))-1./(5.*x*x+5.*y*y+0.2)+5.;
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Multiextremal4(double x, double y)
{
/*
Функция двух переменных: функция Multiextremal4.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
VHML_Result=0.5*(x*x+x*y+y*y)*(1.+0.5*cos(1.5*x)*cos(3.2*x*y)*cos(3.14*y)+0.5*cos(2.2*x)*cos(4.8*x*y)*cos(3.5*y));
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_MultiplicativePotential(double x, double y)
{
/*
Функция двух переменных: мультипликативная потенциальная функция.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
double z1=-(1./((x-1.)*(x-1.)+0.2))-(1./(2.*(x-2.)*(x-2.)+0.15))-(1./(3.*(x-3.)*(x-3.)+0.3));
double z2=-(1./((y-1.)*(y-1.)+0.2))-(1./(2.*(y-2.)*(y-2.)+0.15))-(1./(3.*(y-3.)*(y-3.)+0.3));
VHML_Result=-z1*z2;
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_ParaboloidOfRevolution(double *x, int VHML_N)
{
/*
Функция многих переменных: Эллиптический параболоид.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
for (int i=0;i<VHML_N;i++) VHML_Result+=x[i]*x[i];
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Rana(double x, double y)
{
/*
Функция двух переменных: функция Rana.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
VHML_Result=x*sin(sqrt(fabs(y+1.-x)))*cos(sqrt(fabs(y+1.+x))) + (y+1.)*cos(sqrt(fabs(y+1.-x)))*sin(sqrt(fabs(y+1.+x)));
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Rastrigin(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Растригина.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
for (int i=0;i<VHML_N;i++) VHML_Result+=x[i]*x[i]-10.*cos(2.*HML_PI*x[i]);
VHML_Result+=10*VHML_N;
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_RastriginNovgorod(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Растригина новгородская.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;

for (int i=0;i<VHML_N;i++) 
    VHML_Result+=x[i]*x[i]-cos(18.*x[i]*x[i]);

VHML_Result+=VHML_N;

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_RastriginWithChange(double x, double y)
{
/*
Функция двух переменных: функция Растригина с изменением коэффициентов.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;

VHML_Result=0.1*x*x+0.1*y*y-4.*cos(0.8*x)-4.*cos(0.8*y)+8.;

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_RastriginWithTurning(double x, double y)
{
/*
Функция двух переменных: функция Растригина овражная с поворотом осей.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;

double alpha=HML_PI_2;
double kx=1.5;
double ky=0.8;

double A,B;
A=x*cos(alpha)-y*sin(alpha);
B=x*sin(alpha)+y*cos(alpha);

VHML_Result=(0.1*kx*A)*(0.1*kx*A)+(0.1*ky*B)*(0.1*ky*B)-4.*cos(0.8*kx*A)-4.*cos(0.8*ky*B)+8.;

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_ReverseGriewank(double x, double y)
{
/*
Функция двух переменных: функция ReverseGriewank.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;

VHML_Result = 1./((x*x+y*y)/200.-cos(x)*cos(y/sqrt(2.))+2.);

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Rosenbrock(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Розенброка.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
for (int i=0;i<VHML_N-1;i++) VHML_Result+=100.*(x[i+1]-x[i]*x[i])*(x[i+1]-x[i]*x[i])+(1.-x[i])*(1.-x[i]);
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_RotatedHyperEllipsoid(double *x, int VHML_N)
{
/*
Функция многих переменных: Развернутый гипер-эллипсоид.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
double f;

for (int i=0;i<VHML_N;i++)
 {
 f=0;
 for (int j=0;j<i+1;j++)
    f += x[j];
 VHML_Result += f*f;
 }

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Schwefel(double *x, int VHML_N)
{
/*
Функция многих переменных: функция Швефеля.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=418.9829*VHML_N;

for (int i=0;i<VHML_N;i++)
    VHML_Result -= x[i]*sin(sqrt(fabs(x[i])));

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_ShekelsFoxholes(double x, double y)
{
/*
Функция двух переменных: функция "Лисьи норы" Шекеля.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
double K=500.;
double f1,f2;
int j,k;
int a[2][25];

a[0][0]=-32;
a[0][1]=-16;
a[0][2]=0;
a[0][3]=16;
a[0][4]=32;
a[0][5]=-32;
a[0][6]=-16;
a[0][7]=0;
a[0][8]=16;
a[0][9]=32;
a[0][10]=-32;
a[0][11]=-16;
a[0][12]=0;
a[0][13]=16;
a[0][14]=32;
a[0][15]=-32;
a[0][16]=-16;
a[0][17]=0;
a[0][18]=16;
a[0][19]=32;
a[0][20]=-32;
a[0][21]=-16;
a[0][22]=0;
a[0][23]=16;
a[0][24]=32;

a[1][0]=-32;
a[1][1]=-32;
a[1][2]=-32;
a[1][3]=-32;
a[1][4]=-32;
a[1][5]=-16;
a[1][6]=-16;
a[1][7]=-16;
a[1][8]=-16;
a[1][9]=-16;
a[1][10]=0;
a[1][11]=0;
a[1][12]=0;
a[1][13]=0;
a[1][14]=0;
a[1][15]=16;
a[1][16]=16;
a[1][17]=16;
a[1][18]=16;
a[1][19]=16;
a[1][20]=32;
a[1][21]=32;
a[1][22]=32;
a[1][23]=32;
a[1][24]=32;

VHML_Result=1./K;
for (j=0;j<25;j++)
 {
 f1=1;
 for (k=0;k<6;k++) f1=f1*(x-a[0][j]);
 f2=1;
 for (k=0;k<6;k++) f2=f2*(y-a[1][j]);
 VHML_Result+=1./(j+1.+f1+f2);
 }
 
VHML_Result=1./VHML_Result;

return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_Sombrero(double x, double y)
{
/*
Функция одной переменных: функция Сомбреро.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - первая вещественная переменная;
 y - вторая вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x,y).
*/
double VHML_Result;
VHML_Result = 1.-sin(sqrt(x*x+y*y))*sin(sqrt(x*x+y*y));
VHML_Result /= (1.+0.001*(x*x+y*y));
return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_StepFunction(double *x, int VHML_N)
{
/*
Функция многих переменных: Функция Step (модифицированная версия De Jong 3).
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
    double VHML_Result=0;

    double H=0;

    for (int i=0;i<VHML_N;i++)
        H+=fabs(int(x[i]));

    if (H!=0)
    {
        for (int i=0;i<VHML_N;i++)
            VHML_Result+=(int(x[i]))*(int(x[i]));
    }
    else
    {
        for (int i=0;i<VHML_N;i++)
            VHML_Result+=fabs(x[i]);
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_TestFunction_SumVector(int *x, int VHML_N)
{
/*
Сумма всех элементов бинарного вектора.
Тестовая функция бинарной оптимизации.
Входные параметры:
 x - указатель на исходный массив;
 VHML_N - размер массива x.
Возвращаемое значение:
 Значение тестовой функции в точке x.
*/
double VHML_Result=0;
for (int i=0;i<VHML_N;i++) VHML_Result+=x[i];
return VHML_Result;
}

//---------------------------------------------------------------------------

double HML_TestFunction_Wave(double x)
{
/*
Функция одной переменных: волна.
Тестовая функция вещественной оптимизации.
Входные параметры:
 x - вещественная переменная.
Возвращаемое значение:
 Значение тестовой функции в точке (x).
*/
double VHML_Result;
VHML_Result = (exp(-x*x)+0.01*cos(200*x));
return VHML_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Тригонометрические функции
//*****************************************************************
double HML_Cos(double x)
{
/*
Функция возвращает косинус угла в радианах.
Входные параметры:
 x - угол в радианах.
Возвращаемое значение:
 Косинус угла.
Примечание:
 Вводится только для того, чтобы множество тригонометрических функций было полным.
*/
return cos(x);
}
//---------------------------------------------------------------------------

double HML_CosDeg(double x)
{
/*
Функция возвращает косинус угла в градусах.
Входные параметры:
 x - угол в градусах.
Возвращаемое значение:
 Косинус угла.
*/
return cos(HML_DegToRad(x));
}
//---------------------------------------------------------------------------

double HML_Cosec(double x)
{
/*
Функция возвращает косеканс угла в радианах.
Входные параметры:
 x - угол в радианах.
Возвращаемое значение:
 Косеканс угла.
*/
return 1./sin(x);
}
//---------------------------------------------------------------------------

double HML_CosecDeg(double x)
{
/*
Функция возвращает косеканс угла в градусах.
Входные параметры:
 x - угол в градусах.
Возвращаемое значение:
 Косеканс угла.
*/
return 1./sin(HML_DegToRad(x));
}
//---------------------------------------------------------------------------

double HML_Cotan(double x)
{
/*
Функция возвращает котангенс угла в радианах.
Входные параметры:
 x - угол в радианах.
Возвращаемое значение:
 Котангенс угла.
*/
return 1./tan(x);
}
//---------------------------------------------------------------------------

double HML_CotanDeg(double x)
{
/*
Функция возвращает котангенс угла в градусах.
Входные параметры:
 x - угол в градусах.
Возвращаемое значение:
 Котангенс угла.
*/
return 1./tan(HML_DegToRad(x));
}
//---------------------------------------------------------------------------

double HML_Sec(double x)
{
/*
Функция возвращает секанс угла в радианах.
Входные параметры:
 x - угол в радианах.
Возвращаемое значение:
 Секанс угла.
*/
return 1./cos(x);
}
//---------------------------------------------------------------------------

double HML_SecDeg(double x)
{
/*
Функция возвращает секанс угла в градусах.
Входные параметры:
 x - угол в градусах.
Возвращаемое значение:
 Секанс угла.
*/
return 1./cos(HML_DegToRad(x));
}
//---------------------------------------------------------------------------

double HML_Sin(double x)
{
/*
Функция возвращает синус угла в радианах.
Входные параметры:
 x - угол в радианах.
Возвращаемое значение:
 Синус угла.
Примечание:
 Вводится только для того, чтобы множество тригонометрических функций было полным.
*/
return sin(x);
}
//---------------------------------------------------------------------------

double HML_SinDeg(double x)
{
/*
Функция возвращает синус угла в градусах.
Входные параметры:
 x - угол в градусах.
Возвращаемое значение:
 Синус угла.
*/
return sin(HML_DegToRad(x));
}
//---------------------------------------------------------------------------

double HML_Tan(double x)
{
/*
Функция возвращает тангенс угла в радианах.
Входные параметры:
 x - угол в радианах.
Возвращаемое значение:
 Тангенс угла.
Примечание:
 Вводится только для того, чтобы множество тригонометрических функций было полным.
*/
return tan(x);
}
//---------------------------------------------------------------------------

double HML_TanDeg(double x)
{
/*
Функция возвращает тангенс угла в градусах.
Входные параметры:
 x - угол в градусах.
Возвращаемое значение:
 Тангенс угла.
*/
return tan(HML_DegToRad(x));
}
//---------------------------------------------------------------------------


//*****************************************************************
//Уравнения
//*****************************************************************
int HML_QuadraticEquation(double a, double b, double c, double *x1, double *x2)
{
/*
Функция решает квадратное уравнение вида: a*x*x+b*x+c=0.
Ответ представляет собой два действительных числа.
Входные параметры:
 a - параметр уравнения;
 b - параметр уравнения;
 c - параметр уравнения;
 x1 - первый корень;
 x2 - второй корень.
Возвращаемое значение:
 1 - все хорошо;
 0 - решения нет.
*/
    if (!HML_AlmostZero(a))
    {
        double D;
        D=b*b-4*a*c;
        if ((D>0)||(HML_AlmostZero(D)))
        {
            *x1=(-b+sqrt(D))/(2.*a);
            *x2=(-b-sqrt(D))/(2.*a);
        }
        else
        {
            *x1=0;
            *x2=0;
            return 0;
        }
    }
    else
    {
        if (!HML_AlmostZero(b))
        {//если a==0 то это линейное уравнение
            if (!HML_AlmostZero(c))
            {// уравнение типа bx+c=0
                *x1=-c/b;
                *x2=-c/b;
            }
            else
            {//уравнение типа bx=0
                *x1=0;
                *x2=0;
            }
        }
        else
        {//a==0 b==0
            if (!HML_AlmostZero(c))
            {// у нас получилось уравнение вида, например, 5=0
                *x1=0;
                *x2=0;
                return 0;
            }
            else
            {// у нас получилось уравнение 0=0
                //любой x будет решением. А чем ноль хуже остальных?)
                *x1=0;
                *x2=0;
                return 1;
            }
        }
    }
    return 1;
}
//---------------------------------------------------------------------------

int HML_QuadraticEquationCount(double a, double b, double c, double *x1, double *x2)
{
/*
Функция решает квадратное уравнение вида: a*x*x+b*x+c=0.
Ответ представляет собой два действительных числа.
Отличается от HML_QuadraticEquation только тем, что возвращается количество решений, а не его наличие.
Входные параметры:
 a - параметр уравнения;
 b - параметр уравнения;
 c - параметр уравнения;
 x1 - первый корень;
 x2 - второй корень.
Возвращаемое значение:
 Количество решений задачи: 0, 1 или  2.
*/
    int Result;

    int GoodOrNot=HML_QuadraticEquation(a,b,c,x1,x2);

    if (GoodOrNot==0)
        Result = 0;
    else
    {
        if (*x1==*x2)
            Result = 1;
        else
            Result = 2;
    }

    return Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Физика
//*****************************************************************
double HML_NewtonSecondLawAcceleration(double F, double m)
{
/*
Функция вычисляет ускорение по второму закону Ньютона.
Входные параметры:
 F - сила, приложенная к телу;
 m - масса тела.
Возвращаемое значение:
 Ускорение тела.
*/
    double VHML_Result;

    if (m<0) m*=-1;
    if (m==0) return 0;

    VHML_Result = F/m;

    return VHML_Result;
}
//---------------------------------------------------------------------------

double HML_NewtonSecondLawForce(double a, double m)
{
/*
Функция вычисляет силу по второму закону Ньютона.
Входные параметры:
 a - ускорение тела;
 m - масса тела.
Возвращаемое значение:
 Сила, приложенная к телу.
*/
    double VHML_Result;

    if (m<0) m*=-1;
    if (m==0) return 0;

    VHML_Result = a*m;

    return VHML_Result;
}

//---------------------------------------------------------------------------


//*****************************************************************
//Цвет
//*****************************************************************
int HML_AddColorB(int R, int G, int B, double p)
{
    /*
    Функция увеличивает яркость цвета через прибавление к каждому каналу числа p. Выдает значение канала B.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - на сколько увеличиваем яркость. Число должно быть в интервале [0,255];
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,0.,255.);

    //int Rnew=R+p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=G+p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    int Bnew=B+p;
    Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Bnew;
}
//---------------------------------------------------------------------------

int HML_AddColorG(int R, int G, int B, double p)
{
    /*
    Функция увеличивает яркость цвета через прибавление к каждому каналу числа p. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - на сколько увеличиваем яркость. Число должно быть в интервале [0,255];
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,0.,255.);

    //int Rnew=R+p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    int Gnew=G+p;
    Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=B+p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Gnew;
}
//---------------------------------------------------------------------------

int HML_AddColorR(int R, int G, int B, double p)
{
    /*
    Функция увеличивает яркость цвета через прибавление к каждому каналу числа p. Выдает значение канала R.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - на сколько увеличиваем яркость. Число должно быть в интервале [0,255];
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,0.,255.);

    int Rnew=R+p;
    Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=G+p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=B+p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Rnew;
}
//---------------------------------------------------------------------------

int HML_AlphaBlendingColorToColorB(double alpha, int R1, int G1, int B1, int R2, int G2, int B2)
{
    /*
    Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала B.
    Входные параметры:
     alpha - прозрачность второго накладываемого цвета из интервала [0;1];
     R1,G1,B1 - RGB код первого цвета градиента, например. Каждый параметр должен быть в интервале [0,255];
     R2,G2,B2 - RGB код второго цвета градиента, например: Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
	alpha = HML_AcceptanceLimitsNumber(alpha,0.,1.);
    R1 = HML_AcceptanceLimitsNumber(R1,0,255);
    G1 = HML_AcceptanceLimitsNumber(G1,0,255);
    B1 = HML_AcceptanceLimitsNumber(B1,0,255);
    R2 = HML_AcceptanceLimitsNumber(R2,0,255);
    G2 = HML_AcceptanceLimitsNumber(G2,0,255);
    B2 = HML_AcceptanceLimitsNumber(B2,0,255);

    //int R=alpha*R2+(1-alpha)*R1;
    //G=alpha*G2+(1-alpha)*G1;
    int B=alpha*B2+(1-alpha)*B1;

    return B;
}
//---------------------------------------------------------------------------

int HML_AlphaBlendingColorToColorG(double alpha, int R1, int G1, int B1, int R2, int G2, int B2)
{
    /*
    Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала G.
    Входные параметры:
     alpha - прозрачность второго накладываемого цвета из интервала [0;1];
     R1,G1,B1 - RGB код первого цвета градиента, например. Каждый параметр должен быть в интервале [0,255];
     R2,G2,B2 - RGB код второго цвета градиента, например: Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
	alpha = HML_AcceptanceLimitsNumber(alpha,0.,1.);
    R1 = HML_AcceptanceLimitsNumber(R1,0,255);
    G1 = HML_AcceptanceLimitsNumber(G1,0,255);
    B1 = HML_AcceptanceLimitsNumber(B1,0,255);
    R2 = HML_AcceptanceLimitsNumber(R2,0,255);
    G2 = HML_AcceptanceLimitsNumber(G2,0,255);
    B2 = HML_AcceptanceLimitsNumber(B2,0,255);

    //int R=alpha*R2+(1-alpha)*R1;
    int G=alpha*G2+(1-alpha)*G1;
    //B=alpha*B2+(1-alpha)*B1;

    return G;
}
//---------------------------------------------------------------------------

int HML_AlphaBlendingColorToColorR(double alpha, int R1, int G1, int B1, int R2, int G2, int B2)
{
    /*
    Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала R.
    Входные параметры:
     alpha - прозрачность второго накладываемого цвета из интервала [0;1];
     R1,G1,B1 - RGB код первого цвета градиента, например. Каждый параметр должен быть в интервале [0,255];
     R2,G2,B2 - RGB код второго цвета градиента, например: Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
	alpha = HML_AcceptanceLimitsNumber(alpha,0.,1.);
    R1 = HML_AcceptanceLimitsNumber(R1,0,255);
    G1 = HML_AcceptanceLimitsNumber(G1,0,255);
    B1 = HML_AcceptanceLimitsNumber(B1,0,255);
    R2 = HML_AcceptanceLimitsNumber(R2,0,255);
    G2 = HML_AcceptanceLimitsNumber(G2,0,255);
    B2 = HML_AcceptanceLimitsNumber(B2,0,255);

    int R=alpha*R2+(1-alpha)*R1;
    //G=alpha*G2+(1-alpha)*G1;
    //B=alpha*B2+(1-alpha)*B1;

    return R;
}
//---------------------------------------------------------------------------

int HML_ColorFromGradientB(double position, int R1, int G1, int B1, int R2, int G2, int B2)
{
    /*
    Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала B.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента;
     R1,G1,B1 - RGB код первого цвета градиента. Каждый параметр должен быть в интервале [0,255];
     R2,G2,B2 - RGB код второго цвета градиента. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    position = HML_AcceptanceLimitsNumber(position,0.,1.);
    R1 = HML_AcceptanceLimitsNumber(R1,0,255);
    G1 = HML_AcceptanceLimitsNumber(G1,0,255);
    B1 = HML_AcceptanceLimitsNumber(B1,0,255);
    R2 = HML_AcceptanceLimitsNumber(R2,0,255);
    G2 = HML_AcceptanceLimitsNumber(G2,0,255);
    B2 = HML_AcceptanceLimitsNumber(B2,0,255);

    //int R=R1+position*(R2-R1);
    //int G=G1+position*(G2-G1);
    int B=B1+position*(B2-B1);

    return B;
}
//---------------------------------------------------------------------------

int HML_ColorFromGradientG(double position, int R1, int G1, int B1, int R2, int G2, int B2)
{
    /*
    Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала G.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента;
     R1,G1,B1 - RGB код первого цвета градиента. Каждый параметр должен быть в интервале [0,255];
     R2,G2,B2 - RGB код второго цвета градиента. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    position = HML_AcceptanceLimitsNumber(position,0.,1.);
    R1 = HML_AcceptanceLimitsNumber(R1,0,255);
    G1 = HML_AcceptanceLimitsNumber(G1,0,255);
    B1 = HML_AcceptanceLimitsNumber(B1,0,255);
    R2 = HML_AcceptanceLimitsNumber(R2,0,255);
    G2 = HML_AcceptanceLimitsNumber(G2,0,255);
    B2 = HML_AcceptanceLimitsNumber(B2,0,255);

    //int R=R1+position*(R2-R1);
    int G=G1+position*(G2-G1);
    //int B=B1+position*(B2-B1);

    return G;
}
//---------------------------------------------------------------------------

int HML_ColorFromGradientR(double position, int R1, int G1, int B1, int R2, int G2, int B2)
{
    /*
    Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала R.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента;
     R1,G1,B1 - RGB код первого цвета градиента. Каждый параметр должен быть в интервале [0,255];
     R2,G2,B2 - RGB код второго цвета градиента. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    position = HML_AcceptanceLimitsNumber(position,0.,1.);
    R1 = HML_AcceptanceLimitsNumber(R1,0,255);
    G1 = HML_AcceptanceLimitsNumber(G1,0,255);
    B1 = HML_AcceptanceLimitsNumber(B1,0,255);
    R2 = HML_AcceptanceLimitsNumber(R2,0,255);
    G2 = HML_AcceptanceLimitsNumber(G2,0,255);
    B2 = HML_AcceptanceLimitsNumber(B2,0,255);

    int R=R1+position*(R2-R1);
    //int G=G1+position*(G2-G1);
    //int B=B1+position*(B2-B1);

    return R;
}
//---------------------------------------------------------------------------

int HML_DivideColorB(int R, int G, int B, double p)
{
    /*
    Функция уменьшает яркость цвета через деление каждого канала на число p. Выдает значение канала B.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - во сколько уменьшаем яркость. Число должно быть в интервале [1,256];
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,1.,256.);

    //int Rnew=double(R)/p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=double(G)/p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    int Bnew=double(B)/p;
    Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Bnew;
}
//---------------------------------------------------------------------------

int HML_DivideColorG(int R, int G, int B, double p)
{
    /*
    Функция уменьшает яркость цвета через деление каждого канала на число p. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - во сколько уменьшаем яркость. Число должно быть в интервале [1,256];
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,1.,256.);

    //int Rnew=double(R)/p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    int Gnew=double(G)/p;
    Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=double(B)/p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Gnew;
}
//---------------------------------------------------------------------------

int HML_DivideColorR(int R, int G, int B, double p)
{
    /*
    Функция уменьшает яркость цвета через деление каждого канала на число p. Выдает значение канала R.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - во сколько уменьшаем яркость. Число должно быть в интервале [1,256];
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,1.,256.);

    int Rnew=double(R)/p;
    Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=double(G)/p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=double(B)/p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Rnew;
}
//---------------------------------------------------------------------------

int HML_GiveRainbowColorB(double position)
{
    /*
    Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала B.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента.
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    position = HML_AcceptanceLimitsNumber(position,0.,1.);

    int B=0;//

    int nmax=6;// number of color bars
    double m=nmax* position;
    int n=int(m); // integer of m
    double f=m-n;  // fraction of m
    int t=int(f*255);

    switch( n){
    case 0: {
        B = 0;
        break;
    };
    case 1: {
        B = 0;
        break;
    };
    case 2: {
        B = t;
        break;
    };
    case 3: {
        B = 255;
        break;
    };
    case 4: {
        B = 255;
        break;
    };
    case 5: {
        B = 255 - t;
        break;
    };

    }; // case

    return B;
}
//---------------------------------------------------------------------------

int HML_GiveRainbowColorG(double position)
{
    /*
    Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала G.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента.
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    position = HML_AcceptanceLimitsNumber(position,0.,1.);

    int G=0;//

    int nmax=6;// number of color bars
    double m=nmax* position;
    int n=int(m); // integer of m
    double f=m-n;  // fraction of m
    int t=int(f*255);

    switch( n){
    case 0: {
        G = t;
        break;
    };
    case 1: {
        G = 255;
        break;
    };
    case 2: {
        G = 255;
        break;
    };
    case 3: {
        G = 255 - t;
        break;
    };
    case 4: {
        G = 0;
        break;
    };
    case 5: {
        G = 0;
        break;
    };

    }; // case

    return G;
}
//---------------------------------------------------------------------------

int HML_GiveRainbowColorR(double position)
{
    /*
    Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала R.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента.
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    position = HML_AcceptanceLimitsNumber(position,0.,1.);

    int R=0;//

    int nmax=6;// number of color bars
    double m=nmax* position;
    int n=int(m); // integer of m
    double f=m-n;  // fraction of m
    int t=int(f*255);

    switch( n){
    case 0: {
        R = 255;
        break;
    };
    case 1: {
        R = 255 - t;
        break;
    };
    case 2: {
        R = 0;
        break;
    };
    case 3: {
        R = 0;
        break;
    };
    case 4: {
        R = t;
        break;
    };
    case 5: {
        R = 255;
        break;
    };

    }; // case

    return R;
}
//---------------------------------------------------------------------------

int HML_GreyscaleB(int R, int G, int B)
{
    /*
    Функция переводит цвет в серый цвет. Выдает значение канала B.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);

    //int Rnew=(R+G+B)/3;
    //int Gnew=(R+G+B)/3;
    int Bnew=(R+G+B)/3;

    return Bnew;
}
//---------------------------------------------------------------------------

int HML_GreyscaleG(int R, int G, int B)
{
    /*
    Функция переводит цвет в серый цвет. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);

    //int Rnew=(R+G+B)/3;
    int Gnew=(R+G+B)/3;
    //int Bnew=(R+G+B)/3;

    return Gnew;
}
//---------------------------------------------------------------------------

int HML_GreyscaleR(int R, int G, int B)
{
    /*
    Функция переводит цвет в серый цвет. Выдает значение канала R.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);

    int Rnew=(R+G+B)/3;
    //int Gnew=(R+G+B)/3;
    //int Bnew=(R+G+B)/3;

    return Rnew;
}
//---------------------------------------------------------------------------

int HML_MultiplyColorB(int R, int G, int B, double p)
{
    /*
    Функция увеличивает яркость цвета через умножение каждого канала числа на p. Выдает значение канала B.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - во сколько увеличиваем яркость. Число должно быть в интервале [1,256];
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,1.,256.);

    //int Rnew=R*p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=G*p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    int Bnew=B*p;
    Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Bnew;
}
//---------------------------------------------------------------------------

int HML_MultiplyColorG(int R, int G, int B, double p)
{
    /*
    Функция увеличивает яркость цвета через умножение каждого канала числа на p. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - во сколько увеличиваем яркость. Число должно быть в интервале [1,256];
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,1.,256.);

    //int Rnew=R*p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    int Gnew=G*p;
    Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=B*p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Gnew;
}
//---------------------------------------------------------------------------

int HML_MultiplyColorR(int R, int G, int B, double p)
{
    /*
    Функция увеличивает яркость цвета через умножение каждого канала числа на p. Выдает значение канала R.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - во сколько увеличиваем яркость. Число должно быть в интервале [1,256];
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,1.,256.);

    int Rnew=R*p;
    Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=G*p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=B*p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Rnew;
}
//---------------------------------------------------------------------------

int HML_NegativeColorB(int R, int G, int B)
{
    /*
    Функция инвертирует цвет. Выдает значение канала B.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);

    //int Rnew=255-R;
    //int Gnew=255-G;
    int Bnew=255-B;

    return Bnew;
}
//---------------------------------------------------------------------------

int HML_NegativeColorG(int R, int G, int B)
{
    /*
    Функция инвертирует цвет. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);

    //int Rnew=255-R;
    int Gnew=255-G;
    //int Bnew=255-B;

    return Gnew;
}
//---------------------------------------------------------------------------

int HML_NegativeColorR(int R, int G, int B)
{
    /*
    Функция инвертирует цвет. Выдает значение канала R.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);

    int Rnew=255-R;
    //int Gnew=255-G;
    //int Bnew=255-B;

    return Rnew;
}
//---------------------------------------------------------------------------

int HML_SubtractColorB(int R, int G, int B, double p)
{
    /*
    Функция уменьшает яркость цвета через отнимание от каждого канала числа p. Выдает значение канала B.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - на сколько уменьшаем яркость. Число должно быть в интервале [0,255];
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,0.,255.);

    //int Rnew=R-p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=G-p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    int Bnew=B-p;
    Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Bnew;
}
//---------------------------------------------------------------------------

int HML_SubtractColorG(int R, int G, int B, double p)
{
    /*
    Функция уменьшает яркость цвета через отнимание от каждого канала числа p. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - на сколько уменьшаем яркость. Число должно быть в интервале [0,255];
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,0.,255.);

    //int Rnew=R-p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    int Gnew=G-p;
    Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=B-p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Gnew;
}
//---------------------------------------------------------------------------

int HML_SubtractColorR(int R, int G, int B, double p)
{
    /*
    Функция уменьшает яркость цвета через отнимание от каждого канала числа p. Выдает значение канала R.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - на сколько уменьшаем яркость. Число должно быть в интервале [0,255];
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,0.,255.);

    int Rnew=R-p;
    Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=G-p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=B-p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Rnew;
}
//---------------------------------------------------------------------------


