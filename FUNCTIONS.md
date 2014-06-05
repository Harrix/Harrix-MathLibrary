Список функций библиотеки HarrixMathLibrary
===========================================

Вектора (Одномерные массивы)
----------------

- Функция добавляет к элементам выборки помеху, зависящую от значения элемента выборки (плюс-минус сколько-то процентов модуля разности минимального и максимального элемента выборки, умноженного на значение элемента).

```cpp
void MHL_DependentNoiseInVector(double *VMHL_ResultVector, double percent, int VMHL_N);
```

- Функция вычисляет евклидовую норму вектора.

```cpp
double MHL_EuclidNorma(double *a,int VMHL_N);
```

- Функция добавляет к элементам выборки аддитивную помеху (плюс-минус сколько-то процентов модуля разности минимального и максимального элемента выборки).

```cpp
void MHL_NoiseInVector(double *VMHL_ResultVector, double percent, int VMHL_N);
```

- Функция перегрупирует элементы массива так, чтобы произведение элементов в начале вектора было не больше Limit. Для чего вообще функция нужна? У нас имеется несколько групп (в количестве VMHL_N) с количеством элементов, равных числу из вектора. Нужно разделить группы на две группы так, чтобы в одной из них произведение количеств элементов было не больше Limit. При этом в Order сохраняем порядок элементов, а возвращаем количество элементов в первой подгруппе.

```cpp
int MHL_SeparateVectorLimitOnProductElements(int *VMHL_Vector, int *Order, int Limit, int VMHL_N);
```

- Функция перегрупирует элементы массива так, чтобы произведение элементов в начале вектора было не больше Limit. Для чего вообще функция нужна? У нас имеется несколько групп (в количестве VMHL_N) с количеством элементов, равных числу из вектора. Нужно разделить группы на две группы так, чтобы в одной из них произведение количеств элементов было не больше Limit. При этом в Order сохраняем порядок элементов, а возвращаем количество элементов в первой подгруппе. Алгоритм в данной функции немного другой, чем в функции MHL_SeparateVectorLimitOnProductElements.

```cpp
int MHL_SeparateVectorLimitOnProductElementsTwo(int *VMHL_Vector, int *Order, int Limit, int VMHL_N);
```

- Функция вмещает вектор VMHL_ResultVector в прямоугольную многомерной области, определяемой левыми границами и правыми границами. Если какая-то координата вектора выходит за границу, то значение этой координаты принимает граничное значение.

```cpp
template <class T> void TMHL_AcceptanceLimits(T *VMHL_ResultVector, T *Left, T *Right, int VMHL_N);
template <class T> void TMHL_AcceptanceLimits(T *VMHL_ResultVector, T Left, T Right, int VMHL_N);
```

- Если значения вектора VMHL_ResultVector[i] слева выходят за Left[i], то она ограничивается Left[i].

```cpp
template <class T> void TMHL_AcceptanceLimitsLeft(T *VMHL_ResultVector, T *Left, int VMHL_N);
template <class T> void TMHL_AcceptanceLimitsLeft(T *VMHL_ResultVector, T Left, int VMHL_N);
```

- Если значения вектора VMHL_ResultVector[i] справа выходят за Right[i], то она ограничивается Right[i].

```cpp
template <class T> void TMHL_AcceptanceLimitsRight(T *VMHL_ResultVector, T *Right, int VMHL_N);
template <class T> void TMHL_AcceptanceLimitsRight(T *VMHL_ResultVector, T Right, int VMHL_N);
```

- Функция меняет порядок элементов в массиве VMHL_Vector и сохраняет в другой VMHL_ResultVector согласно массиву Order, в котором записан новый порядок элементов. Функция-перезагрузка меняет порядок элементов в массиве VMHL_Vector согласно массиву Order, в котором записан новый порядок элементов.

```cpp
template <class T> void TMHL_ChangeOrderInVector(T *VMHL_Vector, T *VMHL_ResultVector, int *Order, int VMHL_N);
template <class T> void TMHL_ChangeOrderInVector(T *VMHL_Vector, int *Order, int VMHL_N);
```

- Функция проверяет наличие элемента а в векторе x.

```cpp
template <class T> int TMHL_CheckElementInVector(T *x, int VMHL_N, T a);
```

- Функция проверяет, какой вектор по среднему арифметическому больше.

```cpp
template <class T> int TMHL_CompareMeanOfVectors(T *a, T *b, int VMHL_N);
template <class T> int TMHL_CompareMeanOfVectors(T *a, T *b, int VMHL_N1, int VMHL_N2);
```

- Функция проверяет равенство векторов.

```cpp
template <class T> bool TMHL_EqualityOfVectors(T *a, T *b, int VMHL_N);
```

- Функция заполняет массив числами Фибоначчи.

```cpp
template <class T> void TMHL_FibonacciNumbersVector(T *VMHL_ResultVector, int VMHL_N);
```

- Функция заполняет вектор значениями, равных x.

```cpp
template <class T> void TMHL_FillVector(T *VMHL_ResultVector, int VMHL_N, T x);
```

- Функция ищет максимальный элемент в векторе (одномерном массиве).

```cpp
template <class T> T TMHL_MaximumOfVector(T *VMHL_Vector, int VMHL_N);
```

- Функция ищет минимальный элемент в векторе (одномерном массиве).

```cpp
template <class T> T TMHL_MinimumOfVector(T *VMHL_Vector, int VMHL_N);
```

- Функция перемешивает массив. Поочередно рассматриваются номера элементов массивов. С некоторой вероятностью рассматриваемый элемент массива меняется местами со случайным элементом массива.

```cpp
template <class T> void TMHL_MixingVector(T *VMHL_ResultVector, double P, int VMHL_N);
```

- Функция перемешивает массив вместе со сопряженным массивом. Поочередно рассматриваются номера элементов массивов. С некоторой вероятностью рассматриваемый элемент массива меняется местами со случайным элементом массива. Пары элементов первого массива и сопряженного остаются без изменения.

```cpp
template <class T, class T2> void TMHL_MixingVectorWithConjugateVector(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, double P, int VMHL_N);
```

- Функция подсчитывает число различных значений в векторе (одномерном массиве).

```cpp
template <class T> int TMHL_NumberOfDifferentValuesInVector(T *a, int VMHL_N);
```

- Функция ищет номер максимального элемента в векторе (одномерном массиве).

```cpp
template <class T> int TMHL_NumberOfMaximumOfVector(T *a, int VMHL_N);
```

- Функция ищет номер минимального элемента в векторе (одномерном массиве).

```cpp
template <class T> int TMHL_NumberOfMinimumOfVector(T *a, int VMHL_N);
```

- Функция подсчитывает число отрицательных значений в векторе (одномерном массиве).

```cpp
template <class T> int TMHL_NumberOfNegativeValues(T *a, int VMHL_N);
```

- Функция подсчитывает число положительных значений в векторе (одномерном массиве).

```cpp
template <class T> int TMHL_NumberOfPositiveValues(T *a, int VMHL_N);
```

- Функция подсчитывает число нулевых значений в векторе (одномерном массиве).

```cpp
template <class T> int TMHL_NumberOfZeroValues(T *a, int VMHL_N);
```

- Функция заполняет вектор значениями, равные номеру элемента, начиная с единицы.

```cpp
template <class T> void TMHL_OrdinalVector(T *VMHL_ResultVector, int VMHL_N);
```

- Функция заполняет вектор значениями, равные номеру элемента, начиная с нуля.

```cpp
template <class T> void TMHL_OrdinalVectorZero(T *VMHL_ResultVector, int VMHL_N);
```

- Функция вычисляет произведение элементов вектора.

```cpp
template <class T> T TMHL_ProductOfElementsOfVector(T *VMHL_Vector,int VMHL_N);
```

- Функция меняет порядок элементов в массиве на обратный. Преобразуется подаваемый массив.

```cpp
template <class T> void TMHL_ReverseVector(T *VMHL_ResultVector, int VMHL_N);
```

- Функция находит номер первого элемента в массиве, равного данному.

```cpp
template <class T> int TMHL_SearchElementInVector (T *X, T x, int VMHL_N);
```

- Функция возвращает номер первого ненулевого элемента массива.

```cpp
template <class T> int TMHL_SearchFirstNotZero(T *x, int VMHL_N);
```

- Функция возвращает номер первого нулевого элемента массива.

```cpp
template <class T> int TMHL_SearchFirstZero(T *x, int VMHL_N);
```

- Функция сдвигает циклически в векторе (одномерном массиве) все элементы влево на один элемент.

```cpp
template <class T> void TMHL_ShiftLeftVector(T *VMHL_Vector, int VMHL_N);
```

- Функция сдвигает циклически в векторе (одномерном массиве) все элементы вправо на один элемент.

```cpp
template <class T> void TMHL_ShiftRightVector(T *VMHL_Vector, int VMHL_N);
```

- Функция вычисляет сумму квадратов элементов вектора.

```cpp
template <class T> T TMHL_SumSquareVector(T *VMHL_Vector,int VMHL_N);
```

- Функция вычисляет сумму элементов вектора.

```cpp
template <class T> T TMHL_SumVector(T *VMHL_Vector,int VMHL_N);
```

- Функция вычитает поэлементно из одного массива другой и записывает результат в третий массив. Или в переопределенном виде функция вычитает поэлементно из одного массива другой и записывает результат в первый массив.

```cpp
template <class T> void TMHL_VectorMinusVector(T *a, T *b, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_VectorMinusVector(T *VMHL_ResultVector, T *b, int VMHL_N);
```

- Функция умножает вектор на число.

```cpp
template <class T> void TMHL_VectorMultiplyNumber(T *VMHL_ResultVector, int VMHL_N, T Number);
```

- Функция складывает поэлементно из одного массива другой и записывает результат в третий массив. Или в переопределенном виде функция складывает поэлементно из одного массива другой и записывает результат в первый массив.

```cpp
template <class T> void TMHL_VectorPlusVector(T *a, T *b, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_VectorPlusVector(T *VMHL_ResultVector, T *b, int VMHL_N);
```

- Функция копирует содержимое вектора (одномерного массива) в другой.

```cpp
template <class T> void TMHL_VectorToVector(T *VMHL_Vector, T *VMHL_ResultVector, int VMHL_N);
```

- Функция зануляет массив.

```cpp
template <class T> void TMHL_ZeroVector(T *VMHL_ResultVector,int VMHL_N);
```

Генетические алгоритмы
----------------

- Равномерное арифметическое скрещивание для вещественных векторов.

```cpp
void MHL_ArithmeticalCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, double w, int VMHL_N);
```

- BLX скрещивание для вещественных векторов.

```cpp
void MHL_BLXCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, double alpha, int VMHL_N);
```

- Служебная функция. Функция вычисляет целевую функцию бинарного вектора, в котором закодирован вещественный вектор. Использует внутренние служебные переменные. Функция для MHL_StandartRealGeneticAlgorithm. Использовать для своих целей не рекомендуется.

```cpp
double MHL_BinaryFitnessFunction(int*x, int VMHL_N);
```

- Расширенное линейчатое скрещивание для вещественных векторов.

```cpp
void MHL_ExtendedLineForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, double w, int VMHL_N);
```

- Плоское скрещивание для вещественных векторов.

```cpp
void MHL_FlatCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, int VMHL_N);
```

- Геометрическое скрещивание для вещественных векторов.

```cpp
void MHL_GeometricalCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, double w, int VMHL_N);
```

- Линейное скрещивание для вещественных векторов.

```cpp
void MHL_LinearCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, int VMHL_N);
```

- Функция формирует вектор вероятностей выбора индивидов из вектора значений функции пригодности. Формирование вектора происходит согласно правилам пропорционально селекции из ГА. Это служебная функция для использования функции пропорциональной селекции MHL_ProportionalSelectionV2.

```cpp
void MHL_MakeVectorOfProbabilityForProportionalSelectionV2(double *Fitness, double *VMHL_ResultVector, int VMHL_N);
```

- Функция формирует вектор вероятностей выбора индивидов из вектора рангов для ранговой селекции. Это служебная функция для использования функции ранговой селекции MHL_RankSelection.

```cpp
void MHL_MakeVectorOfProbabilityForRanklSelection(double *Rank, double *VMHL_ResultVector, int VMHL_N);
```

- Проставляет ранги для элементов не сортированного массива, то есть номера, начиная с 1, в отсортированном массиве.  Если в массиве есть несколько одинаковых элементов, то ранги им присуждаются как среднеарифметические. Это служебная функция для функции MHL_RankSelection.

```cpp
void MHL_MakeVectorOfRankForRankSelection(double *Fitness, double *VMHL_ResultVector, int VMHL_N);
```

- Проставляет ранги для элементов не сортированного массива, то есть номера, начиная с 0 (а не 1), в отсортированном массиве.  Если в массиве есть несколько одинаковых элементов, то ранги им присуждаются как среднеарифметические.

```cpp
void MHL_MakeVectorOfRankZeroForRankSelection(double *Fitness, double *VMHL_ResultVector, int VMHL_N);
```

- Нормировка вектора чисел в отрезок [0;1] посредством функции MHL_NormalizationNumberAll.

```cpp
void MHL_NormalizationVectorAll(double *x,int VMHL_N);
```

- Нормировка вектора чисел так, чтобы максимальный элемент имел значение 1, а минимальный 0.

```cpp
void MHL_NormalizationVectorMaxMin(double *VMHL_ResultVector,int VMHL_N);
```

- Нормировка вектора чисел в отрезок [0,1] так, чтобы сумма всех элементов была равна 1.

```cpp
void MHL_NormalizationVectorOne(double *VMHL_ResultVector,int VMHL_N);
```

- Функция вычисляет вероятности выбора индивидов из популяции с помощью турнирной селекции..

```cpp
double MHL_ProbabilityOfTournamentSelection(double *Fitness, double *VMHL_ResultVector_Probability, int T, int VMHL_N);
```

- Пропорциональная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей.

```cpp
int MHL_ProportionalSelection(double *Fitness, int VMHL_N);
```

- Пропорциональная селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов, который можно получить из вектора пригодностей индивидов посредством функции MHL_MakeVectorOfProbabilityForProportionalSelectionV2.

```cpp
int MHL_ProportionalSelectionV2(double *VectorOfProbability, int VMHL_N);
```

- Пропорциональная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей (обязательно не отрицательными).

```cpp
int MHL_ProportionalSelectionV3(double *Fitness, int VMHL_N);
```

- Ранговая селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов, который можно получить из вектора пригодностей индивидов посредством функции MHL_MakeVectorOfRankForRankSelection (для получения массива рангов) и потом функции MHL_MakeVectorOfProbabilityForProportionalSelectionV2 (для получения массива вероятностей выбора индивидов по рангам).

```cpp
int MHL_RankSelection(double *VectorOfProbability, int VMHL_N);
```

- Функция выбирает случайно номер элемента из вектора, где вероятность выбора каждого элемента определяется значением в векторе P.

```cpp
int MHL_SelectItemOnProbability(double *P, int VMHL_N);
```

- Одноточечное скрещивание для вещественных векторов.

```cpp
void MHL_SinglepointCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, int VMHL_N);
```

- Стандартный генетический алгоритм для решения задач на бинарных строках. Реализация алгоритма из документа <<Генетический алгоритм. Стандарт. v.3.0>>.

```cpp
int MHL_StandartBinaryGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
```

- Стандартный генетический алгоритм для решения задач на бинарных и вещественных строках. Реализация алгоритма из документа <<Генетический алгоритм. Стандарт. v.3.0>>.

```cpp
int MHL_StandartGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
int MHL_StandartGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
```

- Стандартный генетический алгоритм для решения задач на вещественных строках. Реализация алгоритма из документа <<Генетический алгоритм. Стандарт. v.3.0>>.

```cpp
int MHL_StandartRealGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
```

- Турнирная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов. В переопределенной функции используется во входных параметрах дополнительный массив, так как функция часто вызывается, а постоянно создавать массив накладно.

```cpp
int MHL_TournamentSelection(double *Fitness, int SizeTournament, int VMHL_N);
int MHL_TournamentSelection(double *Fitness, int SizeTournament, int *Taken, int VMHL_N);
```

- Турнирная селекция с возвращением. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов.

```cpp
int MHL_TournamentSelectionWithReturn(double *Fitness, int SizeTournament, int VMHL_N);
```

- Двухточечное скрещивание для вещественных векторов.

```cpp
void MHL_TwopointCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, int VMHL_N);
```

- Равномерное скрещивание для вещественных векторов.

```cpp
void MHL_UniformCrossoverForReal(double*Parent1, double *Parent2, double *VMHL_ResultVector, int VMHL_N);
```

- Мутация для бинарной матрицы. Оператор генетического алгоритма.

```cpp
template <class T> void TMHL_MutationBinaryMatrix(T **VMHL_ResultMatrix, double ProbabilityOfMutation, int VMHL_N,int VMHL_M);
```

- Мутация для бинарного вектора. Оператор генетического алгоритма.

```cpp
template <class T> void TMHL_MutationBinaryVector(T *VMHL_ResultVector, double ProbabilityOfMutation, int VMHL_N);
```

- Одноточечное скрещивание. Оператор генетического алгоритма.

```cpp
template <class T> void TMHL_SinglepointCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
```

- Одноточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного одноточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.

```cpp
template <class T> void TMHL_SinglepointCrossoverWithCopying(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
```

- Двухточечное скрещивание. Оператор генетического алгоритма.

```cpp
template <class T> void TMHL_TwopointCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
```

- Двухточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного двухточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.

```cpp
template <class T> void TMHL_TwopointCrossoverWithCopying(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
```

- Равномерное скрещивание. Оператор генетического алгоритма.

```cpp
template <class T> void TMHL_UniformCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
```

Геометрия
----------------

- Функция представляет собой уравнение прямой по общему уравнению прямой вида Ax+By+C=0.

```cpp
double MHL_LineGeneralForm(double x, double A, double B, double C, int *solutionis);
double MHL_LineGeneralForm(double x, double A, double B, double C);
```

- Функция представляет собой уравнение прямой с угловым коэффициентом вида y=kx+b.

```cpp
double MHL_LineSlopeInterceptForm(double x, double k, double b);
```

- Функция представляет собой уравнение прямой по двум точкам.

```cpp
double MHL_LineTwoPoint(double x, double x1, double y1, double x2, double y2, int *solutionis);
double MHL_LineTwoPoint(double x, double x1, double y1, double x2, double y2);
```

- Функция представляет собой уравнение параболы вида: y=ax^2+bx+c.

```cpp
double MHL_Parabola(double x, double a, double b, double c);
```

- Функция определяет наличие пересечения двух отрезков на линии. Координаты отрезков могут быть перепутаны по порядку в каждом отрезке.

```cpp
template <class T> int TMHL_BoolCrossingTwoSegment(T b1,T c1,T b2,T c2);
```

Гиперболические функции
----------------

- Функция возвращает гиперболический косеканс.

```cpp
double MHL_Cosech(double x);
```

- Функция возвращает гиперболический косинус.

```cpp
double MHL_Cosh(double x);
```

- Функция возвращает гиперболический котангенс.

```cpp
double MHL_Cotanh(double x);
```

- Функция возвращает гиперболический секанс.

```cpp
double MHL_Sech(double x);
```

- Функция возвращает гиперболический синус.

```cpp
double MHL_Sinh(double x);
```

- Функция возвращает гиперболический тангенс.

```cpp
double MHL_Tanh(double x);
```

Дифференцирование
----------------

- Численное значение производной в точке (центральной разностной производной с шагом 2h).

```cpp
double MHL_CenterDerivative(double x, double h, double (*Function)(double));
```

- Численное значение производной в точке (разностная производная влево).

```cpp
double MHL_LeftDerivative(double x, double h, double (*Function)(double));
```

- Численное значение производной в точке (разностная производная вправо).

```cpp
double MHL_RightDerivative(double x, double h, double (*Function)(double));
```

Интегрирование
----------------

- Интегрирование по формуле прямоугольников с оценкой точности по правилу Рунге. Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.

```cpp
double MHL_IntegralOfRectangle(double a, double b, double Epsilon,double (*Function)(double));
```

- Интегрирование по формуле Симпсона с оценкой точности по правилу Рунге. Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.

```cpp
double MHL_IntegralOfSimpson(double a, double b, double Epsilon,double (*Function)(double));
```

- Интегрирование по формуле трапеции с оценкой точности по правилу Рунге. Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.

```cpp
double MHL_IntegralOfTrapezium(double a, double b, double Epsilon,double (*Function)(double));
```

Кодирование и декодирование
----------------

- Функция декодирует бинарную строку в действительный вектор, который и был закодирован методом <<Стандартный рефлексивный Грей-код>> (без использования временного массива). Перегруженная функция делает тоже самое, но с использованием временного массива (это позволяет не создавать каждый раз временный массив, что ускоряет работу).

```cpp
void MHL_BinaryGrayVectorToRealVector(int *x, int n, double *VMHL_ResultVector, double *Left, double *Right, int *Lengthi, int VMHL_N);
void MHL_BinaryGrayVectorToRealVector(int *x, double *VMHL_ResultVector,int *TempBinaryVector, double *Left, double *Right, int *Lengthi, int VMHL_N);
```

- Функция декодирует бинарную строку в действительный вектор, который и был закодирован методом <<Стандартное представление целого числа --- номер узла в сетке дискретизации>>.

```cpp
void MHL_BinaryVectorToRealVector(int *x, double *VMHL_ResultVector, double *Left, double *Right, int *Lengthi, int VMHL_N);
```

- Функция декодирует двоичное число в десятичное целое неотрицательное.

```cpp
template <class T> T TMHL_BinaryToDecimal(T *a, int VMHL_N);
```

- Функция декодирует двоичное число в десятичное целое неотрицательное. При этом двоичное число длины  берется как часть некой бинарной строки a.

```cpp
template <class T> T TMHL_BinaryToDecimalFromPart(T *a, int Begin, int n);
```

- Функция переводит бинарный код Грея в бинарный код.

```cpp
template <class T> void TMHL_GrayCodeToBinary(T *a,int *VMHL_ResultVector, int VMHL_N);
```

- Функция переводит бинарный код Грея в бинарный код. При этом бинарный код Грея берется как часть некой строки a, заполненной 0 и 1.

```cpp
template <class T> void TMHL_GrayCodeToBinaryFromPart(T *a, T *VMHL_ResultVector, int Begin, int n);
```

Комбинаторика
----------------

- Функция возвращает число сочетаний из n по m (без возвращения).

```cpp
template <class T> T TMHL_KCombinations(T k, T n);
```

Математические функции
----------------

- Функция возвращает ответ на главный вопрос жизни, вселенной и всего такого.

```cpp
double MHL_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything();
```

- Арифметическая прогрессия. n-ый член последовательности.

```cpp
double MHL_ArithmeticalProgression(double a1,double d,int n);
```

- Функция вычисляет выражение exp(-x*x/2).

```cpp
double MHL_ExpMSxD2(double x);
```

- Геометрическая прогрессия. n-ый член последовательности.

```cpp
double MHL_GeometricSeries(double u1,double q,int n);
```

- Функция находит наибольший общий делитель двух чисел по алгоритму Евклида.

```cpp
int MHL_GreatestCommonDivisorEuclid(int A,int B);
```

- Функция вычисляет, какой минимальной степенью двойки можно покрыть целое положительное число.

```cpp
int MHL_HowManyPowersOfTwo(int x);
```

- Функция осуществляет обратную нормировку числа из интервала \left[0;1\right]   в интервал \left[-\infty;\infty \right] , которое было осуществлено функцией MHL_NormalizationNumberAll.

```cpp
double MHL_InverseNormalizationNumberAll(double x);
```

- Функция находит наименьшее общее кратное двух чисел по алгоритму Евклида.

```cpp
int MHL_LeastCommonMultipleEuclid(int A,int B);
```

- Функция возвращает смысл жизни.

```cpp
double MHL_MeaningOfLife();
```

- Функция генерирует определенный вектор k-значной логики, где каждый элемент может принимать разное максимальное значение, в полном переборе вариантов. Генерируется I вектор в этом полном переборе.

```cpp
void MHL_MixedMultiLogicVectorOfFullSearch(int *VMHL_Vector, int I, int *HowMuchInElements, int VMHL_N);
```

- Функция нормирует число из интервала \left[-\infty;\infty \right]  в интервал \left[0;1\right]. При этом в нуле возвращает 0.5, в -\infty возвращает 0, в \infty возвращает 1. Если x<y, то MHL_NormalizationNumberAll(x)<MHL_NormalizationNumberAll(y). Под бесконечностью принимается машинная бесконечность.

```cpp
double MHL_NormalizationNumberAll(double x);
```

- Функция проверяет четность целого числа.

```cpp
int MHL_Parity(int a);
```

- Функция вычисляет плотность вероятности распределения обратного гауссовскому распределению..

```cpp
double MHL_ProbabilityDensityFunctionOfInverseGaussianDistribution (double x, double mu, double lambda);
```

- Геометрическая прогрессия. Сумма первых n членов.

```cpp
double MHL_SumGeometricSeries(double u1,double q,int n);
```

- Арифметическая прогрессия. Сумма первых n членов.

```cpp
double MHL_SumOfArithmeticalProgression(double a1,double d,int n);
```

- Функция подсчитывает сумму цифр любого целого числа.

```cpp
int MHL_SumOfDigits(int a);
```

- Функция возвращает модуль числа.

```cpp
template <class T> T TMHL_Abs(T x);
```

- Функция проверяет не выходит ли число за заданные рамки [Left, Right]. Если выходит, то принимает граничные значения.

```cpp
template <class T> T TMHL_AcceptanceLimitsNumber(T Number, T Left, T Right);
```

- Функция проверяет не выходит ли число за левую рамку Left. Если выходит, то принимает граничное значения.

```cpp
template <class T> T TMHL_AcceptanceLimitsNumberLeft(T Number, T Left);
```

- Функция проверяет не выходит ли число за правую рамку Right. Если выходит, то принимает граничное значения.

```cpp
template <class T> T TMHL_AcceptanceLimitsNumberRight(T Number, T Right);
```

- Функция показывает, являются ли числа почти равными. Используйте с осторожностью.

```cpp
template <class T> bool TMHL_AlmostEqual(T x, T y);
template <class T> bool TMHL_AlmostEqual(T x, T y, double epsilon);
```

- Функция показывает, является ли число почти нулем. Используется для сравнения с нулем для вещественных чисел.

```cpp
template <class T> bool TMHL_AlmostZero(T x);
template <class T> bool TMHL_AlmostZero(T x, double epsilon);
```

- Функция вычисляет факториал числа.

```cpp
template <class T> T TMHL_Factorial(T x);
```

- Функция вычисляет число Фибоначчи, заданного номера.

```cpp
template <class T> T TMHL_FibonacciNumber(T n);
```

- Функция Хевисайда (функция одной переменной).

```cpp
template <class T> T TMHL_HeavisideFunction(T x);
```

- Функция возвращает максимальный элемент из двух.

```cpp
template <class T> T TMHL_Max(T a, T b);
```

- Функция возвращает минимальный элемент из двух.

```cpp
template <class T> T TMHL_Min(T a, T b);
```

- Функция меняет местами значения двух чисел.

```cpp
template <class T> void TMHL_NumberInterchange(T *a, T *b);
```

- Функция возводит произвольное число в целую степень.

```cpp
template <class T> T TMHL_PowerOf(T x, int n);
```

- Функция вычисляет знака числа.

```cpp
template <class T> int TMHL_Sign(T a);
```

- Функция вычисляет знака числа. При нуле возвращает 1.

```cpp
template <class T> int TMHL_SignNull(T a);
```

Матрицы
----------------

- Функция проверяет наличие одинаковых столбцов в матрице.

```cpp
template <class T> bool TMHL_CheckForIdenticalColsInMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
```

- Функция проверяет наличие одинаковых строк в матрице.

```cpp
template <class T> bool TMHL_CheckForIdenticalRowsInMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
```

- Функция переставляет столбцы матрицы.

```cpp
template <class T> void TMHL_ColInterchange(T **VMHL_ResultMatrix, int VMHL_N, int k, int l);
```

- Функция копирует в матрицу (двумерный массив) из вектора столбец.

```cpp
template <class T> void TMHL_ColToMatrix(T **VMHL_ResultMatrix, T *b, int VMHL_N, int k);
```

- Функция удаляет k столбец из матрицы (начиная с нуля). Все правостоящие столбцы сдвигаются влево  на единицу. Последний столбец зануляется.

```cpp
template <class T> void TMHL_DeleteColInMatrix(T **VMHL_ResultMatrix, int k, int VMHL_N, int VMHL_M);
```

- Функция удаляет k строку из матрицы (начиная с нуля). Все нижестоящие строки поднимаются на единицу. Последняя строка зануляется.

```cpp
template <class T> void TMHL_DeleteRowInMatrix(T **VMHL_ResultMatrix, int k, int VMHL_N, int VMHL_M);
```

- Функция проверяет равенство матриц.

```cpp
template <class T> bool TMHL_EqualityOfMatrixes (T **a, T **b,int VMHL_N,int VMHL_M);
```

- Функция заполняет матрицу значениями, равных x.

```cpp
template <class T> void TMHL_FillMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, T x);
```

- Функция формирует единичную квадратную матрицу.

```cpp
template <class T> void TMHL_IdentityMatrix(T **VMHL_ResultMatrix,int VMHL_N);
```

- Функция вычитает две матрицы. Или для переопределенной варианта функция вычитает два матрицы и результат записывает в первую матрицу. 

```cpp
template <class T> void TMHL_MatrixMinusMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixMinusMatrix(T **VMHL_ResultMatrix, T **b, int VMHL_N, int VMHL_M);
```

- Функция перемножает матрицы.

```cpp
template <class T> void TMHL_MatrixMultiplyMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S);
```

- Функция умножает матрицу на транспонированную матрицу.

```cpp
template <class T> void TMHL_MatrixMultiplyMatrixT(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S);
```

- Функция умножает матрицу на число.

```cpp
template <class T> void TMHL_MatrixMultiplyNumber(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, T Number);
```

- Функция суммирует две матрицы. Или для переопределенной варианта функция суммирует два матрицы и результат записывает в первую матрицу. 

```cpp
template <class T> void TMHL_MatrixPlusMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixPlusMatrix(T **VMHL_ResultMatrix, T **b, int VMHL_N, int VMHL_M);
```

- Функция транспонирует матрицу.

```cpp
template <class T> void TMHL_MatrixT(T **a, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
```

- Функция умножает транспонированную матрицу на матрицу.

```cpp
template <class T> void TMHL_MatrixTMultiplyMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S);
```

- Функция копирует из матрицы (двумерного массива) в вектор столбец.

```cpp
template <class T> void TMHL_MatrixToCol(T **a, T *VMHL_ResultVector, int VMHL_N, int k);
```

- Функция копирует содержимое матрицы (двумерного массива) a в массив VMHL_ResultMatrix.

```cpp
template <class T> void TMHL_MatrixToMatrix(T **a, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
```

- Функция копирует из матрицы (двумерного массива) в вектор строку.

```cpp
template <class T> void TMHL_MatrixToRow(T **a, T *VMHL_ResultVector, int k, int VMHL_M);
```

- Функция ищет максимальный элемент в матрице (двумерном массиве).

```cpp
template <class T> T TMHL_MaximumOfMatrix(T **a, int VMHL_N, int VMHL_M);
```

- Функция ищет минимальный элемент в матрице (двумерном массиве).

```cpp
template <class T> T TMHL_MinimumOfMatrix(T **a, int VMHL_N, int VMHL_M);
```

- Функция меняет строки матрицы в порядке, указанным в массиве b.

```cpp
template <class T> void TMHL_MixingRowsInOrder(T **VMHL_ResultMatrix, int *b, int VMHL_N, int VMHL_M);
```

- Функция подсчитывает число различных значений в матрице.

```cpp
template <class T> int TMHL_NumberOfDifferentValuesInMatrix(T **a, int VMHL_N, int VMHL_M);
```

- Функция переставляет строки матрицы.

```cpp
template <class T> void TMHL_MatrixToRow(T **a, T *VMHL_ResultVector, int k, int VMHL_M);
```

- Функция копирует в матрицу (двумерный массив) из вектора строку.

```cpp
template <class T> void TMHL_RowToMatrix(T **VMHL_ResultMatrix, T *b, int k, int VMHL_M);
```

- Функция вычисляет сумму элементов матрицы.

```cpp
template <class T> T TMHL_SumMatrix(T **a,int VMHL_N,int VMHL_M);
```

- Функция зануляет матрицу.

```cpp
template <class T> void TMHL_ZeroMatrix(T **VMHL_ResultMatrix,int VMHL_N,int VMHL_M);
```

Метрика
----------------

- Функция вычисляет расстояние Чебышева.

```cpp
template <class T> T TMHL_Chebychev(T *x, T *y, int VMHL_N);
```

- Функция вычисляет манхэттенское расстояние между двумя массивами.

```cpp
template <class T> T TMHL_CityBlock(T *x, T *y, int VMHL_N);
```

- Функция вычисляет евклидово расстояние.

```cpp
template <class T> T TMHL_Euclid(T *x, T *y, int VMHL_N);
```

- Функция вычисляет метрику Минковского.

```cpp
template <class T> T TMHL_Minkovski(T *x, T *y, int r, int VMHL_N);
```

Модели
----------------

- Итерационная модель маятника Максвелла с затухающими колебаниями с управлением. Вызов данной процедуры прогоняет только одну итерацию, то есть одно наблюдение. Последующий вызов процедуры покажет положение маятника в следующий момент времени. Самим параметры менять не надо при вызове следующей итерации, так как процедура сама все поменяет (кроме, естественно, управляющего ускорения).

```cpp
int MHL_PendulumOfMaxwell(double *Data);
```

Непараметрика
----------------

- Колоколообразное экспоненциальное ядро.

```cpp
double MHL_BellShapedKernelExp(double z);
```

- Колоколообразное параболическое ядро.

```cpp
double MHL_BellShapedKernelParabola(double z);
```

- Колоколообразное прямоугольное ядро.

```cpp
double MHL_BellShapedKernelRectangle(double z);
```

- Колоколообразное треугольное ядро.

```cpp
double MHL_BellShapedKernelTriangle(double z);
```

- Производная колоколообразного экспоненциального ядра.

```cpp
double MHL_DerivativeOfBellShapedKernelExp(double z);
```

- Производная колоколообразного параболического ядра.

```cpp
double MHL_DerivativeOfBellShapedKernelParabola(double z);
```

- Производная колоколообразного прямоугольного ядра.

```cpp
double MHL_DerivativeOfBellShapedKernelRectangle(double z);
```

- Производная колоколообразного треугольного ядра.

```cpp
double MHL_DerivativeOfBellShapedKernelTriangle(double z);
```

- Создание вектор непараметрической оценки производной в точках выборках. Служебная функция. Нужна для функции MHL_NonparametricEstimatorOfDerivative3.

```cpp
void MHL_MakingVectorForNonparametricEstimatorOfDerivative3(double *VMHL_ResultVector, double *X, double *Y, int VMHL_N, double C, int V);
```

- Создание вектор непараметрической оценки производной в точках выборках. Служебная функция. Нужна для функции MHL_NonparametricEstimatorOfDerivative6.

```cpp
void MHL_MakingVectorForNonparametricEstimatorOfDerivative6(double *VMHL_ResultVector, double *X, double *Y, int VMHL_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.

```cpp
double MHL_NonparametricEstimatorOfDerivative(double x, double *X, double *Y, int VMHL_N, double C, int V, bool *b);
double MHL_NonparametricEstimatorOfDerivative(double x, double *X, double *Y, int VMHL_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. Отличается от MHL_NonparametricEstimatorOfDerivative тем, что производная считается только в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической оценке регрессии в вновь полученной выборке.

```cpp
double MHL_NonparametricEstimatorOfDerivative2(double x, double *X, double *Y, int VMHL_N, double C, int V, bool *b);
double MHL_NonparametricEstimatorOfDerivative2(double x, double *X, double *Y, int VMHL_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. Отличается от MHL_NonparametricEstimatorOfDerivative тем, что производная считается только в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической оценке регрессии в вновь полученной выборке. В отличии от MHL_NonparametricEstimatorOfDerivative2 пересчет выборки производной производится в другой функции MHL_MakingVectorForNonparametricEstimatorOfDerivative3.

```cpp
double MHL_NonparametricEstimatorOfDerivative3(double x, double *X, double *dY, int VMHL_N, double C, int V, bool *b);
double MHL_NonparametricEstimatorOfDerivative3(double x, double *X, double *dY, int VMHL_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. Авторская разработка. Немного модифицирована формула по сравнению с MHL_NonparametricEstimatorOfDerivative. Хорошо работает на концах выборки.

```cpp
double MHL_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VMHL_N, double C, int V, bool *b);
double MHL_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VMHL_N, double C, int V);
```

- Авторская разработка. Немного модифицирована формула по сравнению с MHL_NonparametricEstimatorOfDerivative. Хорошо работает на концах выборки. Отличается от MHL_NonparametricEstimatorOfDerivative4 тем, что производная считается только в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической оценке регрессии в вновь полученной выборке.

```cpp
double MHL_NonparametricEstimatorOfDerivative5(double x, double *X, double *Y, int VMHL_N, double C, int V, bool *b);
double MHL_NonparametricEstimatorOfDerivative5(double x, double *X, double *Y, int VMHL_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. Отличается от MHL_NonparametricEstimatorOfDerivative тем, что производная считается только в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической оценке регрессии в вновь полученной выборке. В отличии от MHL_NonparametricEstimatorOfDerivative2 пересчет выборки производной производится в другой функции MHL_MakingVectorForNonparametricEstimatorOfDerivative3. Авторская разработка. Немного модифицирована формула по сравнению с MHL_NonparametricEstimatorOfDerivative.

```cpp
double MHL_NonparametricEstimatorOfDerivative6(double x, double *X, double *dY, int VMHL_N, double C, int V, bool *b);
double MHL_NonparametricEstimatorOfDerivative6(double x, double *X, double *dY, int VMHL_N, double C, int V);
```

- Непараметрическая оценка регрессии при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. В общем, это аппроксимация функции.

```cpp
double MHL_NonparametricEstimatorOfRegression(double x, double *X, double *Y, int VMHL_N, double C, int V, bool *b);
double MHL_NonparametricEstimatorOfRegression(double x, double *X, double *Y, int VMHL_N, double C, int V);
```

Нечеткие системы
----------------

- Определяет центр тяжести трапециевидного нечеткого числа.

```cpp
double MHL_CentroidOfTrapeziformFuzzyNumber(double a,double b,double c,double d);
```

- Функция находит максимальное значение функции принадлежности нечеткого числа, образуемого минимизацией двух трапециевидных нечетких чисел. Необходимо для нечеткого вывода.

```cpp
double MHL_MaxiMinTrapeziformFuzzyNumbers (double *Data);
```

- Трапециевидное нечеткое число. Точнее его функция принадлежности.

```cpp
double MHL_TrapeziformFuzzyNumber(double x,double a,double b,double c,double d);
```

- Трапециевидное усечённое нечеткое число. Точнее его функция принадлежности. Данное число соответствует операции редукции при нечетком выводе.

```cpp
double MHL_TrapeziformTruncatedFuzzyNumber(double x, double a, double b, double c, double d, double m);
```

Оптимизация
----------------

- Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации на бинарных строках. В простонародье его называют <<методом научного тыка>>. Алгоритм оптимизации. Ищет максимум функции пригодности FitnessFunction.

```cpp
int MHL_BinaryMonteCarloAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
```

- Метод дихотомии. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.

```cpp
void MHL_DichotomyOptimization (double Left, double Right, double (*Function)(double), double Interval, double Epsilon, double *VMHL_Result_X,double *VMHL_Result_Y);
```

- Метод Фибоначчи. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.

```cpp
void MHL_FibonacciOptimization (double Left, double Right, double (*Function)(double), int Count, double *VMHL_Result_X,double *VMHL_Result_Y);
```

- Метод золотого сечения. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.

```cpp
void MHL_GoldenSectionOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VMHL_Result_X,double *VMHL_Result_Y);
```

- Метод квадратичной интерполяции. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.

```cpp
void MHL_QuadraticFitOptimization (double Left, double Right, double (*Function)(double), double Epsilon, double Epsilon2, double *VMHL_Result_X,double *VMHL_Result_Y);
```

- Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации на вещественных строках. В простонародье его называют "методом научного тыка".
Алгоритм оптимизации. Ищет максимум функции пригодности FitnessFunction.

```cpp
int MHL_RealMonteCarloAlgorithm(int *Parameters, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
```

- Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации на вещественных строках. Ищет минимум. От функции MHL_RealMonteCarloAlgorithm отличается тем, что ищет минимум, а не максимум, и не у многомерной функции, а одномерной. Вводится, чтобы было продолжением однотипных методов оптимизации одномерных унимодальных функций.

```cpp
void MHL_RealMonteCarloOptimization (double Left, double Right, double (*Function)(double), int Count, double *VMHL_Result_X,double *VMHL_Result_Y);
```

- Метод равномерного поиска. Метод одномерной оптимизации функции на интервале. Ищет минимум.

```cpp
void MHL_UniformSearchOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VMHL_Result_X,double *VMHL_Result_Y);
```

- Метод равномерного поиска. Метод одномерной оптимизации функции на интервале. Ищет минимум. От MHL_UniformSearchOptimization отличается тем, что вместо параметра шага равномерного прохода используется число вычислений целевой функции, но они взаимозаменяемы.

```cpp
void MHL_UniformSearchOptimizationN (double Left, double Right, double (*Function)(double), int Count, double *VMHL_Result_X,double *VMHL_Result_Y);
```

Оптимизация - свалка алгоритмов
----------------

- Генетический алгоритм для решения задач на бинарных строках с турнирной селекцией с возвращением, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но и она измененная, и размер турнира может изменяться.

```cpp
int MHL_BinaryGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм с двойным количеством поколений для решения задач на бинарных строках. На четных поколениях целевая функция высчитывается как среднеарифметическое родителей.

```cpp
int MHL_BinaryGeneticAlgorithmTwiceGenerations(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм для решения задач на бинарных строках, в котором есть только два вида скрещивания: одноточечное и двухточечное скрещивание с возможностью полного копирования одного из родителей. Равномерное скрещивание отсутствует.

```cpp
int MHL_BinaryGeneticAlgorithmWCC(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм для решения задач на бинарных строках с изменяющимся соотношением числа поколений и размера популяции. Отличается от стандартного генетического алгоритма, тем, что размер популяции и число поколений рассчитывается из числа вычислений целевой функции не как одинаковые величины (извлечение квадратного корня), а через некоторое соотношение.

```cpp
int MHL_BinaryGeneticAlgorithmWDPOfNOfGPS(double *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм для решения задач на бинарных строках с турнирной селекцией, где размер турнира изменяется от 2 до размера популяции. Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но размер турнира может изменяться.

```cpp
int MHL_BinaryGeneticAlgorithmWDTS(double *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм для решения задач на вещественных строках  с турнирной селекцией с возвращением, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но и она измененная, и размер турнира может изменяться.

```cpp
int MHL_RealGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм с двойным количеством поколений для решения задач на вещественных строках. На четных поколениях целевая функция высчитывается как среднеарифметическое родителей.

```cpp
int MHL_RealGeneticAlgorithmTwiceGenerations(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм для решения задач на вещественных строках, в котором есть только два вида скрещивания: одноточечное и двухточечное скрещивание с возможностью полного копирования одного из родителей. Равномерное скрещивание отсутствует.

```cpp
int MHL_RealGeneticAlgorithmWCC(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм для решения задач на вещественных строках с изменяющимся соотношением числа поколений и размера популяции. Отличается от стандартного генетического алгоритма, тем, что размер популяции и число поколений рассчитывается из числа вычислений целевой функции не как одинаковые величины (извлечение квадратного корня), а через некоторое соотношение.

```cpp
int MHL_RealGeneticAlgorithmWDPOfNOfGPS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
```

- Генетический алгоритм для решения задач на вещественных строках  с турнирной селекцией, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но размер турнира может изменяться.

```cpp
int MHL_RealGeneticAlgorithmWDTS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
```

Перевод единиц измерений
----------------

- Функция переводит угол из градусной меры в радианную.

```cpp
double MHL_DegToRad(double VMHL_X);
```

- Функция переводит угол из радианной меры в градусную.

```cpp
double MHL_RadToDeg(double VMHL_X);
```

Случайные объекты
----------------

- Функция с вероятностью P (или 0.5 в переопределенной функции) возвращает 1. В противном случае возвращает 0.

```cpp
int MHL_BitNumber(double P);
int MHL_BitNumber();
```

- Функция заполняет матрицу случайными вещественными числами из определенного интервала [Left;Right].

```cpp
void MHL_RandomRealMatrix(double **VMHL_ResultMatrix, double Left, double Right, int VMHL_N, int VMHL_M);
```

- Функция заполняет матрицу случайными вещественными числами из определенного интервала. При этом элементы каждого столбца изменяются в своих пределах.

```cpp
void MHL_RandomRealMatrixInCols(double **VMHL_ResultMatrix, double *Left, double *Right, int VMHL_N, int VMHL_M);
```

- Функция заполняет матрицу случайными вещественными числами из определенного интервала. При этом каждый элемент изменяется в своих пределах.

```cpp
void MHL_RandomRealMatrixInElements(double **VMHL_ResultMatrix, double **Left, double **Right, int VMHL_N, int VMHL_M);
```

- Функция заполняет матрицу случайными вещественными числами из определенного интервала. При этом элементы каждой строки изменяются в своих пределах.

```cpp
void MHL_RandomRealMatrixInRows(double **VMHL_ResultMatrix, double *Left, double *Right, int VMHL_N, int VMHL_M);
```

- Функция заполняет массив случайными вещественными числами из определенного интервала [Left;Right].

```cpp
void MHL_RandomRealVector(double *VMHL_ResultVector, double Left, double Right, int VMHL_N);
```

- Функция заполняет массив случайными вещественными числами из определенного интервала, где на каждую координату свои границы изменения.

```cpp
void MHL_RandomRealVectorInElements(double *VMHL_ResultVector, double *Left, double *Right, int VMHL_N);
```

- Функция заполняет вектор случайными значениями вероятностей. Сумма всех элементов вектора равна 1.

```cpp
void MHL_RandomVectorOfProbability(double *VMHL_ResultVector, int VMHL_N);
```

- Функция формирует случайный вектор Бернулли.

```cpp
template <class T> void TMHL_BernulliVector(T *VMHL_ResultVector, int VMHL_N);
```

- Функция предлагает случайный способ расставить N объектов в VMHL_N корзин при условии, что в каждой корзине может располагаться только один предмет.

```cpp
template <class T> void TMHL_RandomArrangingObjectsIntoBaskets(T *VMHL_ResultVector, int N, int VMHL_N);
```

- Функция заполняет матрицу случайно нулями и единицами.

```cpp
template <class T> void TMHL_RandomBinaryMatrix(T **VMHL_ResultMatrix,int VMHL_N,int VMHL_M);
```

- Функция заполняет вектор (одномерный массив) случайно нулями и единицами.

```cpp
template <class T> void TMHL_RandomBinaryVector(T *VMHL_ResultVector,int VMHL_N);
```

- Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).

```cpp
template <class T> void TMHL_RandomIntMatrix(T **VMHL_ResultMatrix, T n, T m, int VMHL_N, int VMHL_M);
```

- Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m). При этом элементы каждого столбца изменяются в своих пределах.

```cpp
template <class T> void TMHL_RandomIntMatrixInCols(T **VMHL_ResultMatrix, T *n, T *m, int VMHL_N, int VMHL_M);
```

- Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m). При этом каждый элемент изменяется в своих пределах.

```cpp
template <class T> void TMHL_RandomIntMatrixInElements(T **VMHL_ResultMatrix, T **n, T **m, int VMHL_N, int VMHL_M);
```

- Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m). При этом элементы каждой строки изменяются в своих пределах.

```cpp
template <class T> void TMHL_RandomIntMatrixInRows(T **VMHL_ResultMatrix, T *n, T *m, int VMHL_N, int VMHL_M);
```

- Функция заполняет массив случайными целыми числами из определенного интервала [n,m).

```cpp
template <class T> void TMHL_RandomIntVector(T *VMHL_ResultVector, T n, T m, int VMHL_N);
```

- Функция заполняет массив случайными целыми  числами из определенного интервала [n_i,m_i). При этом для каждого элемента массива свой интервал изменения.

```cpp
template <class T> void TMHL_RandomIntVectorInElements(T *VMHL_ResultVector, T *n, T *m, int VMHL_N);
```

- Функция создает случайный массив строк-перестановок чисел от 1 до VMHL_M.

```cpp
template <class T> void TMHL_RandomMatrixOfPermutation(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
```

- Функция создает случайную строку-перестановку чисел от 1 до VMHL_N (включительно).

```cpp
template <class T> void TMHL_RandomVectorOfPermutation(T *VMHL_ResultVector, int VMHL_N);
```

Случайные числа
----------------

- Случайное число по нормальному закону распределения.

```cpp
double MHL_RandomNormal(double Mean, double StdDev);
```

- Случайное вещественное число в интервале [a;b] по равномерному закону распределения.

```cpp
double MHL_RandomUniform(double a, double b);
```

- Случайное целое число в интервале [n,m) по равномерному закону распределения.

```cpp
int MHL_RandomUniformInt(int n, int m);
```

- Случайное целое число в интервале [n,m] по равномерному закону распределения.

```cpp
int MHL_RandomUniformIntIncluding(int n, int m);
```

Сортировка
----------------

- Функция сортирует массив в порядке убывания методом <<Сортировка пузырьком>>.

```cpp
template <class T> void TMHL_BubbleDescendingSort(T *VMHL_ResultVector, int VMHL_N);
```

- Функция сортирует массив в порядке возрастания методом <<Сортировка пузырьком>>.

```cpp
template <class T> void TMHL_BubbleSort(T *VMHL_ResultVector, int VMHL_N);
```

- Функция сортирует матрицу по какому-то столбцу под номером в порядке возрастания методом <<Сортировка пузырьком>>. При этом все остальные столбцы являются как бы сопряженным с данным столбцом. То есть элементы в этом столбце сортируются, а все строки остаются прежними.

```cpp
template <class T> void TMHL_BubbleSortColWithOtherConjugateColsInMatrix(T **VMHL_ResultMatrix,int Col, int VMHL_N, int VMHL_M);
```

- Функция сортирует каждый столбец матрицы в отдельности.

```cpp
template <class T> void TMHL_BubbleSortEveryColInMatrix(T **VMHL_ResultMatrix,int VMHL_N, int VMHL_M);
```

- Функция сортирует каждую строку матрицы в отдельности.

```cpp
template <class T> void TMHL_BubbleSortEveryRowInMatrix(T **VMHL_ResultMatrix,int VMHL_N, int VMHL_M);
```

- Функция сортирует массив в порядке возрастания методом <<Сортировка пузырьком>> в группах данного массива. Имеется массив. Он делится на группы элементов по m элементов. Первые m элементов принадлежат первой группе, следующие m элементов --- следующей и т.д. (Разумеется, в последней группе может и не оказаться m элементов). Потом в каждой группе элементы сортируются по возрастанию.

```cpp
template <class T> void TMHL_BubbleSortInGroups(T *VMHL_ResultVector, int VMHL_N, int m);
```

- Функция сортирует матрицу по какой-то строке под номером в порядке возрастания методом <<Сортировка пузырьком>>. При этом все остальные строки являются как бы сопряжеными с данной строкой. То есть элементы в этой строке сортируются, а все столбцы остаются прежними.

```cpp
template <class T> void TMHL_BubbleSortRowWithOtherConjugateRowsInMatrix(T **VMHL_ResultMatrix,int Row, int VMHL_N, int VMHL_M);
```

- Функция сортирует массив вместе с сопряженный массивом в порядке возрастания методом <<Сортировка пузырьком>>. Пары элементов первого массива и сопряженного остаются без изменения.

```cpp
template <class T, class T2> void TMHL_BubbleSortWithConjugateVector(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, int VMHL_N);
```

- Функция сортирует массив вместе с двумя сопряженными массивами в порядке возрастания методом <<Сортировка пузырьком>>. Пары элементов первого массива и сопряженного остаются без изменения.

```cpp
template <class T, class T2, class T3> void TMHL_BubbleSortWithTwoConjugateVectors(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, T3 *VMHL_ResultVector3, int VMHL_N);
```

Статистика и теория вероятности
----------------

- Плотность распределения вероятности нормированного и центрированного нормального распределения.

```cpp
double MHL_DensityOfDistributionOfNormalizedCenteredNormalDistribution(double x);
```

- Функция распределения нормального распределения.

```cpp
double MHL_DistributionFunctionOfNormalDistribution(double x, double mu, double sigma, double Epsilon);
```

- Функция распределения нормированного и центрированного нормального распределения.

```cpp
double MHL_DistributionFunctionOfNormalizedCenteredNormalDistribution(double x, double Epsilon);
```

- Функция возвращает левую границу интервала критический значений статистики W для критерия Вилкоксена по табличным данным.

```cpp
double MHL_LeftBorderOfWilcoxonWFromTable(int m, int n, double Q);
```

- Функция возвращает правую границу интервала критический значений статистики W для критерия Вилкоксена по табличным данным.

```cpp
double MHL_RightBorderOfWilcoxonWFromTable(int m, int n, double Q);
```

- Функция переводит среднеквадратичное уклонение в значение дисперсии случайной величины.

```cpp
double MHL_StdDevToVariance(double StdDev);
```

- Функция переводит значение дисперсии случайной величины в среднеквадратичное уклонение.

```cpp
double MHL_VarianceToStdDev(double Variance);
```

- Функция проверяет однородность выборок по критерию Вилкосена W.

```cpp
int MHL_WilcoxonW(double *a, double *b, int VMHL_N1, int VMHL_N2, double Q);
```

- Функция вычисляет среднее арифметическое массива.

```cpp
template <class T> T TMHL_Mean(T *x, int VMHL_N);
```

- Функция вычисляет среднее арифметическое массива с фильтром, то есть при подсчете не учитываются значения ниже LowerFilter и выше UpperFilter.

```cpp
template <class T> T TMHL_MeanOfFilter(T *x, int VMHL_N, T UpperFilter, T LowerFilter);
```

- Функция вычисляет среднее арифметическое массива с нижним фильтром, то есть при подсчете не учитываются значения ниже LowerFilter.

```cpp
template <class T> T TMHL_MeanOfLowerFilter(T *x, int VMHL_N, T LowerFilter);
```

- Функция вычисляет среднее арифметическое массива с верхним фильтром, то есть при подсчете не учитываются значения выше UpperFilter.

```cpp
template <class T> T TMHL_MeanOfUpperFilter(T *x, int VMHL_N, T UpperFilter);
```

- Функция вычисляет медиану выборки.

```cpp
template <class T> T TMHL_Median(T *x, int VMHL_N);
```

- Функция вычисляет выборочную ковариацию выборки (несмещенная, исправленная).

```cpp
template <class T> T TMHL_SampleCovariance(T *x, T *y, int VMHL_N);
```

- Функция вычисляет неисправленная выборочную дисперсию выборки..

```cpp
template <class T> T TMHL_UncorrectedVariance(T *x, int VMHL_N);
```

- Функция вычисляет выборочную дисперсию выборки (несмещенная, исправленная).

```cpp
template <class T> T TMHL_Variance(T *x, int VMHL_N);
```

Тестовые функции для оптимизации
----------------

- Функция многих переменных: Ackley. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Ackley(double *x, int VMHL_N);
```

- Функция двух переменных: аддитивная потенциальная функция. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_AdditivePotential(double x, double y);
```

- Функция двух переменных: функция Bosom. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Bosom(double x, double y);
```

- Функция двух переменных: функция Egg Holder. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_EggHolder(double x, double y);
```

- Функция многих переменных: функция Gaussian quartic. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_GaussianQuartic(double *x, int VMHL_N);
```

- Функция многих переменных: функция Гриванка. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Griewangk(double *x, int VMHL_N);
```

- Функция двух переменных: функция Химмельблау. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Himmelblau(double x, double y);
```

- Функция многих переменных: Гипер-эллипсоид. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_HyperEllipsoid(double *x, int VMHL_N);
```

- Функция двух переменных: перевернутая функция Розенброка. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_InvertedRosenbrock(double x, double y);
```

- Функция двух переменных: функция Катникова. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Katnikov(double x, double y);
```

- Функция одной переменных: функция Multiextremal. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Multiextremal(double x);
```

- Функция одной переменных: функция Multiextremal2. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Multiextremal2(double x);
```

- Функция двух переменных: функция Multiextremal3. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Multiextremal3(double x, double y);
```

- Функция двух переменных: функция Multiextremal4. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Multiextremal4(double x, double y);
```

- Функция двух переменных: мультипликативная потенциальная функция. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_MultiplicativePotential(double x, double y);
```

- Функция многих переменных: Эллиптический параболоид. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_ParaboloidOfRevolution(double *x, int VMHL_N);
```

- Функция двух переменных: функция Rana. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Rana(double x, double y);
```

- Функция многих переменных: функция Растригина. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Rastrigin(double *x, int VMHL_N);
```

- Функция многих переменных: функция Растригина новгородская. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_RastriginNovgorod(double *x, int VMHL_N);
```

- Функция двух переменных: функция Растригина с изменением коэффициентов. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_RastriginWithChange(double x, double y);
```

- Функция двух переменных: функция Растригина овражная с поворотом осей. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_RastriginWithTurning(double x, double y);
```

- Функция двух переменных: функция ReverseGriewank. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_ReverseGriewank(double x, double y);
```

- Функция многих переменных: функция Розенброка. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Rosenbrock(double *x, int VMHL_N);
```

- Функция многих переменных: Развернутый гипер-эллипсоид. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_RotatedHyperEllipsoid(double *x, int VMHL_N);
```

- Функция многих переменных: функция Швефеля. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Schwefel(double *x, int VMHL_N);
```

- Функция двух переменных: функция <<Лисьи норы>> Шекеля. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_ShekelsFoxholes(double x, double y);
```

- Функция двух переменных: функция Сомбреро. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Sombrero(double x, double y);
```

- Функция многих переменных: Функция Step (модифицированная версия De Jong 3). Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_StepFunction(double *x, int VMHL_N);
```

- Сумма всех элементов бинарного вектора. Тестовая функция бинарной оптимизации.

```cpp
double MHL_TestFunction_SumVector(int *x, int VMHL_N);
```

- Функция одной переменных: волна. Тестовая функция вещественной оптимизации.

```cpp
double MHL_TestFunction_Wave(double x);
```

Тригонометрические функции
----------------

- Функция возвращает косинус угла в радианах.

```cpp
double MHL_Cos(double x);
```

- Функция возвращает косинус угла в градусах.

```cpp
double MHL_CosDeg(double x);
```

- Функция возвращает косеканс угла в радианах.

```cpp
double MHL_Cosec(double x);
```

- Функция возвращает косеканс угла в градусах.

```cpp
double MHL_CosecDeg(double x);
```

- Функция возвращает котангенс угла в радианах.

```cpp
double MHL_Cotan(double x);
```

- Функция возвращает котангенс угла в градусах.

```cpp
double MHL_CotanDeg(double x);
```

- Функция возвращает секанс угла в радианах.

```cpp
double MHL_Sec(double x);
```

- Функция возвращает секанс угла в градусах.

```cpp
double MHL_SecDeg(double x);
```

- Функция возвращает синус угла в радианах.

```cpp
double MHL_Sin(double x);
```

- Функция возвращает синус угла в градусах.

```cpp
double MHL_SinDeg(double x);
```

- Функция возвращает тангенс угла в радианах.

```cpp
double MHL_Tan(double x);
```

- Функция возвращает тангенс угла в градусах.

```cpp
double MHL_TanDeg(double x);
```

Уравнения
----------------

- Функция решает квадратное уравнение вида: a\cdot x^2+b\cdot x+c=0. Ответ представляет собой два действительных числа.

```cpp
int MHL_QuadraticEquation(double a, double b, double c, double *x1, double *x2);
```

- Функция решает квадратное уравнение вида: a\cdot x^2+b\cdot x+c=0. Ответ представляет собой два действительных числа. Отличается от MHL_QuadraticEquation только тем, что возвращается количество решений, а не его наличие.

```cpp
int MHL_QuadraticEquationCount(double a, double b, double c, double *x1, double *x2);
```

Физика
----------------

- Функция вычисляет ускорение по второму закону Ньютона.

```cpp
double MHL_NewtonSecondLawAcceleration(double F, double m);
```

- Функция вычисляет силу по второму закону Ньютона.

```cpp
double MHL_NewtonSecondLawForce(double a, double m);
```

Цвет
----------------

- Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала B.

```cpp
int MHL_AlphaBlendingColorToColorB(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала G.

```cpp
int MHL_AlphaBlendingColorToColorG(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала R.

```cpp
int MHL_AlphaBlendingColorToColorR(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала B.

```cpp
int MHL_ColorFromGradientB(double position, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала G.

```cpp
int MHL_ColorFromGradientG(double position, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала R.

```cpp
int MHL_ColorFromGradientR(double position, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала B.

```cpp
int MHL_GiveRainbowColorB(double position);
```

- Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала G.

```cpp
int MHL_GiveRainbowColorG(double position);
```

- Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала R.

```cpp
int MHL_GiveRainbowColorR(double position);
```

- Функция переводит цвет в серый цвет. Выдает значение канала B.

```cpp
int MHL_GreyscaleB(int R, int G, int B);
```

- Функция переводит цвет в серый цвет. Выдает значение канала G.

```cpp
int MHL_GreyscaleG(int R, int G, int B);
```

- Функция переводит цвет в серый цвет. Выдает значение канала R.

```cpp
int MHL_GreyscaleR(int R, int G, int B);
```

- Функция инвертирует цвет. Выдает значение канала B.

```cpp
int MHL_NegativeColorB(int R, int G, int B);
```

- Функция инвертирует цвет. Выдает значение канала G.

```cpp
int MHL_NegativeColorG(int R, int G, int B);
```

- Функция инвертирует цвет. Выдает значение канала R.

```cpp
int MHL_NegativeColorR(int R, int G, int B);
```

