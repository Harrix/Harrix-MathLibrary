Список функций библиотеки HarrixMathLibrary
===========================================

Вектора (Одномерные массивы)
----------------

- Функция вмещает вектор VHML_ResultVector в прямоугольную многомерной области, определяемой левыми границами и правыми границами. Если какая-то координата вектора выходит за границу, то значение этой координаты принимает граничное значение.

```cpp
template <class T> void HML_AcceptanceLimits(T *VHML_ResultVector, T *Left, T *Right, int VHML_N);
template <class T> void HML_AcceptanceLimits(T *VHML_ResultVector, T Left, T Right, int VHML_N);
```

- Если значения вектора VHML_ResultVector[i] слева выходят за Left[i], то она ограничивается Left[i].

```cpp
template <class T> void HML_AcceptanceLimitsLeft(T *VHML_ResultVector, T *Left, int VHML_N);
template <class T> void HML_AcceptanceLimitsLeft(T *VHML_ResultVector, T Left, int VHML_N);
```

- Если значения вектора VHML_ResultVector[i] справа выходят за Right[i], то она ограничивается Right[i].

```cpp
template <class T> void HML_AcceptanceLimitsRight(T *VHML_ResultVector, T *Right, int VHML_N);
template <class T> void HML_AcceptanceLimitsRight(T *VHML_ResultVector, T Right, int VHML_N);
```

- Функция меняет порядок элементов в массиве VHML_Vector и сохраняет в другой VHML_ResultVector согласно массиву Order, в котором записан новый порядок элементов. Функция-перезагрузка меняет порядок элементов в массиве VHML_Vector согласно массиву Order, в котором записан новый порядок элементов.

```cpp
template <class T> void HML_ChangeOrderInVector(T *VHML_Vector, T *VHML_ResultVector, int *Order, int VHML_N);
template <class T> void HML_ChangeOrderInVector(T *VHML_Vector, int *Order, int VHML_N);
```

- Функция проверяет наличие элемента а в векторе x.

```cpp
template <class T> int HML_CheckElementInVector(T *x, int VHML_N, T a);
```

- Функция проверяет, какой вектор по среднему арифметическому больше.

```cpp
template <class T> int HML_CompareMeanOfVectors(T *a, T *b, int VHML_N);
template <class T> int HML_CompareMeanOfVectors(T *a, T *b, int VHML_N1, int VHML_N2);
```

- Функция добавляет к элементам выборки помеху, зависящую от значения элемента выборки (плюс-минус сколько-то процентов модуля разности минимального и максимального элемента выборки, умноженного на значение элемента).

```cpp
void HML_DependentNoiseInVector(double *VHML_ResultVector, double percent, int VHML_N);
```

- Функция проверяет равенство векторов.

```cpp
template <class T> bool HML_EqualityOfVectors(T *a, T *b, int VHML_N);
```

- Функция вычисляет евклидовую норму вектора.

```cpp
double HML_EuclidNorma(double *a,int VHML_N);
```

- Функция заполняет массив числами Фибоначчи.

```cpp
template <class T> void HML_FibonacciNumbersVector(T *VHML_ResultVector, int VHML_N);
```

- Функция заполняет вектор значениями, равных x.

```cpp
template <class T> void HML_FillVector(T *VHML_ResultVector, int VHML_N, T x);
```

- Функция ищет максимальный элемент в векторе (одномерном массиве).

```cpp
template <class T> T HML_MaximumOfVector(T *VHML_Vector, int VHML_N);
```

- Функция ищет минимальный элемент в векторе (одномерном массиве).

```cpp
template <class T> T HML_MinimumOfVector(T *VHML_Vector, int VHML_N);
```

- Функция перемешивает массив. Поочередно рассматриваются номера элементов массивов. С некоторой вероятностью рассматриваемый элемент массива меняется местами со случайным элементом массива.

```cpp
template <class T> void HML_MixingVector(T *VHML_ResultVector, double P, int VHML_N);
```

- Функция перемешивает массив вместе со сопряженным массивом. Поочередно рассматриваются номера элементов массивов. С некоторой вероятностью рассматриваемый элемент массива меняется местами со случайным элементом массива. Пары элементов первого массива и сопряженного остаются без изменения.

```cpp
template <class T, class T2> void HML_MixingVectorWithConjugateVector(T *VHML_ResultVector, T2 *VHML_ResultVector2, double P, int VHML_N);
```

- Функция добавляет к элементам выборки аддитивную помеху (плюс-минус сколько-то процентов модуля разности минимального и максимального элемента выборки).

```cpp
void HML_NoiseInVector(double *VHML_ResultVector, double percent, int VHML_N);
```

- Функция подсчитывает число различных значений в векторе (одномерном массиве).

```cpp
template <class T> int HML_NumberOfDifferentValuesInVector(T *a, int VHML_N);
```

- Функция ищет номер максимального элемента в векторе (одномерном массиве).

```cpp
template <class T> int HML_NumberOfMaximumOfVector(T *a, int VHML_N);
```

- Функция ищет номер минимального элемента в векторе (одномерном массиве).

```cpp
template <class T> int HML_NumberOfMinimumOfVector(T *a, int VHML_N);
```

- Функция подсчитывает число отрицательных значений в векторе (одномерном массиве).

```cpp
template <class T> int HML_NumberOfNegativeValues(T *a, int VHML_N);
```

- Функция подсчитывает число положительных значений в векторе (одномерном массиве).

```cpp
template <class T> int HML_NumberOfPositiveValues(T *a, int VHML_N);
```

- Функция подсчитывает число нулевых значений в векторе (одномерном массиве).

```cpp
template <class T> int HML_NumberOfZeroValues(T *a, int VHML_N);
```

- Функция заполняет вектор значениями, равные номеру элемента, начиная с единицы.

```cpp
template <class T> void HML_OrdinalVector(T *VHML_ResultVector, int VHML_N);
```

- Функция заполняет вектор значениями, равные номеру элемента, начиная с нуля.

```cpp
template <class T> void HML_OrdinalVectorZero(T *VHML_ResultVector, int VHML_N);
```

- Функция вычисляет произведение элементов вектора.

```cpp
template <class T> T HML_ProductOfElementsOfVector(T *VHML_Vector,int VHML_N);
```

- Функция меняет порядок элементов в массиве на обратный. Преобразуется подаваемый массив.

```cpp
template <class T> void HML_ReverseVector(T *VHML_ResultVector, int VHML_N);
```

- Функция находит номер первого элемента в массиве, равного данному.

```cpp
template <class T> int HML_SearchElementInVector (T *X, T x, int VHML_N);
```

- Функция возвращает номер первого ненулевого элемента массива.

```cpp
template <class T> int HML_SearchFirstNotZero(T *x, int VHML_N);
```

- Функция возвращает номер первого нулевого элемента массива.

```cpp
template <class T> int HML_SearchFirstZero(T *x, int VHML_N);
```

- Функция перегрупирует элементы массива так, чтобы произведение элементов в начале вектора было не больше Limit. Для чего вообще функция нужна? У нас имеется несколько групп (в количестве VHML_N) с количеством элементов, равных числу из вектора. Нужно разделить группы на две группы так, чтобы в одной из них произведение количеств элементов было не больше Limit. При этом в Order сохраняем порядок элементов, а возвращаем количество элементов в первой подгруппе.

```cpp
int HML_SeparateVectorLimitOnProductElements(int *VHML_Vector, int *Order, int Limit, int VHML_N);
```

- Функция перегрупирует элементы массива так, чтобы произведение элементов в начале вектора было не больше Limit. Для чего вообще функция нужна? У нас имеется несколько групп (в количестве VHML_N) с количеством элементов, равных числу из вектора. Нужно разделить группы на две группы так, чтобы в одной из них произведение количеств элементов было не больше Limit. При этом в Order сохраняем порядок элементов, а возвращаем количество элементов в первой подгруппе. Алгоритм в данной функции немного другой, чем в функции HML_SeparateVectorLimitOnProductElements.

```cpp
int HML_SeparateVectorLimitOnProductElementsTwo(int *VHML_Vector, int *Order, int Limit, int VHML_N);
```

- Функция сдвигает циклически в векторе (одномерном массиве) все элементы влево на один элемент.

```cpp
template <class T> void HML_ShiftLeftVector(T *VHML_Vector, int VHML_N);
```

- Функция сдвигает циклически в векторе (одномерном массиве) все элементы вправо на один элемент.

```cpp
template <class T> void HML_ShiftRightVector(T *VHML_Vector, int VHML_N);
```

- Функция вычисляет сумму квадратов элементов вектора.

```cpp
template <class T> T HML_SumSquareVector(T *VHML_Vector,int VHML_N);
```

- Функция вычисляет сумму элементов вектора.

```cpp
template <class T> T HML_SumVector(T *VHML_Vector,int VHML_N);
```

- Функция вычитает поэлементно из одного массива другой и записывает результат в третий массив. Или в переопределенном виде функция вычитает поэлементно из одного массива другой и записывает результат в первый массив.

```cpp
template <class T> void HML_VectorMinusVector(T *a, T *b, T *VHML_ResultVector, int VHML_N);
template <class T> void HML_VectorMinusVector(T *VHML_ResultVector, T *b, int VHML_N);
```

- Функция умножает вектор на число.

```cpp
template <class T> void HML_VectorMultiplyNumber(T *VHML_ResultVector, int VHML_N, T Number);
```

- Функция складывает поэлементно из одного массива другой и записывает результат в третий массив. Или в переопределенном виде функция складывает поэлементно из одного массива другой и записывает результат в первый массив.

```cpp
template <class T> void HML_VectorPlusVector(T *a, T *b, T *VHML_ResultVector, int VHML_N);
template <class T> void HML_VectorPlusVector(T *VHML_ResultVector, T *b, int VHML_N);
```

- Функция копирует содержимое вектора (одномерного массива) в другой.

```cpp
template <class T> void HML_VectorToVector(T *VHML_Vector, T *VHML_ResultVector, int VHML_N);
```

- Функция зануляет массив.

```cpp
template <class T> void HML_ZeroVector(T *VHML_ResultVector,int VHML_N);
```

Генетические алгоритмы
----------------

- Равномерное арифметическое скрещивание для вещественных векторов.

```cpp
void HML_ArithmeticalCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N);
```

- BLX скрещивание для вещественных векторов.

```cpp
void HML_BLXCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double alpha, int VHML_N);
```

- Служебная функция. Функция вычисляет целевую функцию бинарного вектора, в котором закодирован вещественный вектор. Использует внутренние служебные переменные. Функция для HML_StandartRealGeneticAlgorithm. Использовать для своих целей не рекомендуется.

```cpp
double HML_BinaryFitnessFunction(int*x, int VHML_N);
```

- Расширенное линейчатое скрещивание для вещественных векторов.

```cpp
void HML_ExtendedLineForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N);
```

- Плоское скрещивание для вещественных векторов.

```cpp
void HML_FlatCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
```

- Геометрическое скрещивание для вещественных векторов.

```cpp
void HML_GeometricalCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N);
```

- Линейное скрещивание для вещественных векторов.

```cpp
void HML_LinearCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
```

- Функция формирует вектор вероятностей выбора индивидов из вектора значений функции пригодности. Формирование вектора происходит согласно правилам пропорционально селекции из ГА. Это служебная функция для использования функции пропорциональной селекции HML_ProportionalSelectionV2.

```cpp
void HML_MakeVectorOfProbabilityForProportionalSelectionV2(double *Fitness, double *VHML_ResultVector, int VHML_N);
```

- Функция формирует вектор вероятностей выбора индивидов из вектора рангов для ранговой селекции. Это служебная функция для использования функции ранговой селекции HML_RankSelection.

```cpp
void HML_MakeVectorOfProbabilityForRanklSelection(double *Rank, double *VHML_ResultVector, int VHML_N);
```

- Проставляет ранги для элементов не сортированного массива, то есть номера, начиная с 1, в отсортированном массиве.  Если в массиве есть несколько одинаковых элементов, то ранги им присуждаются как среднеарифметические. Это служебная функция для функции HML_RankSelection.

```cpp
void HML_MakeVectorOfRankForRankSelection(double *Fitness, double *VHML_ResultVector, int VHML_N);
```

- Проставляет ранги для элементов не сортированного массива, то есть номера, начиная с 0 (а не 1), в отсортированном массиве.  Если в массиве есть несколько одинаковых элементов, то ранги им присуждаются как среднеарифметические.

```cpp
void HML_MakeVectorOfRankZeroForRankSelection(double *Fitness, double *VHML_ResultVector, int VHML_N);
```

- Мутация для бинарной матрицы. Оператор генетического алгоритма.

```cpp
template <class T> void HML_MutationBinaryMatrix(T **VHML_ResultMatrix, double ProbabilityOfMutation, int VHML_N,int VHML_M);
```

- Мутация для бинарного вектора. Оператор генетического алгоритма.

```cpp
template <class T> void HML_MutationBinaryVector(T *VHML_ResultVector, double ProbabilityOfMutation, int VHML_N);
```

- Нормировка вектора чисел в отрезок [0;1] посредством функции HML_NormalizationNumberAll.

```cpp
void HML_NormalizationVectorAll(double *x,int VHML_N);
```

- Нормировка вектора чисел так, чтобы максимальный элемент имел значение 1, а минимальный 0.

```cpp
void HML_NormalizationVectorMaxMin(double *VHML_ResultVector,int VHML_N);
```

- Нормировка вектора чисел в отрезок [0,1] так, чтобы сумма всех элементов была равна 1.

```cpp
void HML_NormalizationVectorOne(double *VHML_ResultVector,int VHML_N);
```

- Функция вычисляет вероятности выбора индивидов из популяции с помощью турнирной селекции..

```cpp
double HML_ProbabilityOfTournamentSelection(double *Fitness, double *VHML_ResultVector_Probability, int T, int VHML_N);
```

- Пропорциональная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей.

```cpp
int HML_ProportionalSelection(double *Fitness, int VHML_N);
```

- Пропорциональная селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов, который можно получить из вектора пригодностей индивидов посредством функции HML_MakeVectorOfProbabilityForProportionalSelectionV2.

```cpp
int HML_ProportionalSelectionV2(double *VectorOfProbability, int VHML_N);
```

- Пропорциональная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей (обязательно не отрицательными).

```cpp
int HML_ProportionalSelectionV3(double *Fitness, int VHML_N);
```

- Ранговая селекция. Оператор генетического алгоритма. Работает с вектором вероятностей выбора индивидов, который можно получить из вектора пригодностей индивидов посредством функции HML_MakeVectorOfRankForRankSelection (для получения массива рангов) и потом функции HML_MakeVectorOfProbabilityForProportionalSelectionV2 (для получения массива вероятностей выбора индивидов по рангам).

```cpp
int HML_RankSelection(double *VectorOfProbability, int VHML_N);
```

- Функция выбирает случайно номер элемента из вектора, где вероятность выбора каждого элемента определяется значением в векторе P.

```cpp
int HML_SelectItemOnProbability(double *P, int VHML_N);
```

- Одноточечное скрещивание. Оператор генетического алгоритма.

```cpp
template <class T> void HML_SinglepointCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
```

- Одноточечное скрещивание для вещественных векторов.

```cpp
void HML_SinglepointCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
```

- Одноточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного одноточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.

```cpp
template <class T> void HML_SinglepointCrossoverWithCopying(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
```

- Стандартный генетический алгоритм для решения задач на бинарных строках. Реализация алгоритма из документа <<Генетический алгоритм. Стандарт. v.3.0>>.

```cpp
int HML_StandartBinaryGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
```

- Стандартный генетический алгоритм для решения задач на бинарных и вещественных строках. Реализация алгоритма из документа <<Генетический алгоритм. Стандарт. v.3.0>>.

```cpp
int HML_StandartGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
int HML_StandartGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
```

- Стандартный генетический алгоритм для решения задач на вещественных строках. Реализация алгоритма из документа <<Генетический алгоритм. Стандарт. v.3.0>>.

```cpp
int HML_StandartRealGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
```

- Турнирная селекция. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов. В переопределенной функции используется во входных параметрах дополнительный массив, так как функция часто вызывается, а постоянно создавать массив накладно.

```cpp
int HML_TournamentSelection(double *Fitness, int SizeTournament, int VHML_N);
int HML_TournamentSelection(double *Fitness, int SizeTournament, int *Taken, int VHML_N);
```

- Турнирная селекция с возвращением. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов.

```cpp
int HML_TournamentSelectionWithReturn(double *Fitness, int SizeTournament, int VHML_N);
```

- Двухточечное скрещивание. Оператор генетического алгоритма.

```cpp
template <class T> void HML_TwopointCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
```

- Двухточечное скрещивание для вещественных векторов.

```cpp
void HML_TwopointCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
```

- Двухточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного двухточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.

```cpp
template <class T> void HML_TwopointCrossoverWithCopying(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
```

- Равномерное скрещивание. Оператор генетического алгоритма.

```cpp
template <class T> void HML_UniformCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
```

- Равномерное скрещивание для вещественных векторов.

```cpp
void HML_UniformCrossoverForReal(double*Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
```

Геометрия
----------------

- Функция определяет наличие пересечения двух отрезков на линии. Координаты отрезков могут быть перепутаны по порядку в каждом отрезке.

```cpp
template <class T> int HML_BoolCrossingTwoSegment(T b1,T c1,T b2,T c2);
```

- Функция представляет собой уравнение прямой по общему уравнению прямой вида Ax+By+C=0.

```cpp
double HML_LineGeneralForm(double x, double A, double B, double C, int *solutionis);
double HML_LineGeneralForm(double x, double A, double B, double C);
```

- Функция представляет собой уравнение прямой с угловым коэффициентом вида y=kx+b.

```cpp
double HML_LineSlopeInterceptForm(double x, double k, double b);
```

- Функция представляет собой уравнение прямой по двум точкам.

```cpp
double HML_LineTwoPoint(double x, double x1, double y1, double x2, double y2, int *solutionis);
double HML_LineTwoPoint(double x, double x1, double y1, double x2, double y2);
```

- Функция представляет собой уравнение параболы вида: y=ax^2+bx+c.

```cpp
double HML_Parabola(double x, double a, double b, double c);
```

Гиперболические функции
----------------

- Функция возвращает гиперболический косеканс.

```cpp
double HML_Cosech(double x);
```

- Функция возвращает гиперболический косинус.

```cpp
double HML_Cosh(double x);
```

- Функция возвращает гиперболический котангенс.

```cpp
double HML_Cotanh(double x);
```

- Функция возвращает гиперболический секанс.

```cpp
double HML_Sech(double x);
```

- Функция возвращает гиперболический синус.

```cpp
double HML_Sinh(double x);
```

- Функция возвращает гиперболический тангенс.

```cpp
double HML_Tanh(double x);
```

Дифференцирование
----------------

- Численное значение производной в точке (центральной разностной производной с шагом 2h).

```cpp
double HML_CenterDerivative(double x, double h, double (*Function)(double));
```

- Численное значение производной в точке (разностная производная влево).

```cpp
double HML_LeftDerivative(double x, double h, double (*Function)(double));
```

- Численное значение производной в точке (разностная производная вправо).

```cpp
double HML_RightDerivative(double x, double h, double (*Function)(double));
```

Интегрирование
----------------

- Интегрирование по формуле прямоугольников с оценкой точности по правилу Рунге. Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.

```cpp
double HML_IntegralOfRectangle(double a, double b, double Epsilon,double (*Function)(double));
```

- Интегрирование по формуле Симпсона с оценкой точности по правилу Рунге. Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.

```cpp
double HML_IntegralOfSimpson(double a, double b, double Epsilon,double (*Function)(double));
```

- Интегрирование по формуле трапеции с оценкой точности по правилу Рунге. Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.

```cpp
double HML_IntegralOfTrapezium(double a, double b, double Epsilon,double (*Function)(double));
```

Кодирование и декодирование
----------------

- Функция декодирует бинарную строку в действительный вектор, который и был закодирован методом <<Стандартный рефлексивный Грей-код>> (без использования временного массива). Перегруженная функция делает тоже самое, но с использованием временного массива (это позволяет не создавать каждый раз временный массив, что ускоряет работу).

```cpp
void HML_BinaryGrayVectorToRealVector(int *x, int n, double *VHML_ResultVector, double *Left, double *Right, int *Lengthi, int VHML_N);
void HML_BinaryGrayVectorToRealVector(int *x, double *VHML_ResultVector,int *TempBinaryVector, double *Left, double *Right, int *Lengthi, int VHML_N);
```

- Функция декодирует двоичное число в десятичное целое неотрицательное.

```cpp
template <class T> T HML_BinaryToDecimal(T *a, int VHML_N);
```

- Функция декодирует двоичное число в десятичное целое неотрицательное. При этом двоичное число длины  берется как часть некой бинарной строки a.

```cpp
template <class T> T HML_BinaryToDecimalFromPart(T *a, int Begin, int n);
```

- Функция декодирует бинарную строку в действительный вектор, который и был закодирован методом <<Стандартное представление целого числа --- номер узла в сетке дискретизации>>.

```cpp
void HML_BinaryVectorToRealVector(int *x, double *VHML_ResultVector, double *Left, double *Right, int *Lengthi, int VHML_N);
```

- Функция переводит бинарный код Грея в бинарный код.

```cpp
template <class T> void HML_GrayCodeToBinary(T *a,int *VHML_ResultVector, int VHML_N);
```

- Функция переводит бинарный код Грея в бинарный код. При этом бинарный код Грея берется как часть некой строки a, заполненной 0 и 1.

```cpp
template <class T> void HML_GrayCodeToBinaryFromPart(T *a, T *VHML_ResultVector, int Begin, int n);
```

Комбинаторика
----------------

- Функция возвращает число сочетаний из n по m (без возвращения).

```cpp
template <class T> T HML_KCombinations(T k, T n);
```

Математические функции
----------------

- Функция возвращает модуль числа.

```cpp
template <class T> T HML_Abs(T x);
```

- Функция проверяет не выходит ли число за заданные рамки [Left, Right]. Если выходит, то принимает граничные значения.

```cpp
template <class T> T HML_AcceptanceLimitsNumber(T Number, T Left, T Right);
```

- Функция проверяет не выходит ли число за левую рамку Left. Если выходит, то принимает граничное значения.

```cpp
template <class T> T HML_AcceptanceLimitsNumberLeft(T Number, T Left);
```

- Функция проверяет не выходит ли число за правую рамку Right. Если выходит, то принимает граничное значения.

```cpp
template <class T> T HML_AcceptanceLimitsNumberRight(T Number, T Right);
```

- Функция показывает, являются ли числа почти равными. Используйте с осторожностью.

```cpp
template <class T> bool HML_AlmostEqual(T x, T y);
template <class T> bool HML_AlmostEqual(T x, T y, double epsilon);
```

- Функция показывает, является ли число почти нулем. Используется для сравнения с нулем для вещественных чисел.

```cpp
template <class T> bool HML_AlmostZero(T x);
template <class T> bool HML_AlmostZero(T x, double epsilon);
```

- Функция возвращает ответ на главный вопрос жизни, вселенной и всего такого.

```cpp
double HML_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything();
```

- Арифметическая прогрессия. n-ый член последовательности.

```cpp
double HML_ArithmeticalProgression(double a1,double d,int n);
```

- Функция вычисляет выражение exp(-x*x/2).

```cpp
double HML_ExpMSxD2(double x);
```

- Функция вычисляет факториал числа.

```cpp
template <class T> T HML_Factorial(T x);
```

- Функция вычисляет число Фибоначчи, заданного номера.

```cpp
template <class T> T HML_FibonacciNumber(T n);
```

- Геометрическая прогрессия. n-ый член последовательности.

```cpp
double HML_GeometricSeries(double u1,double q,int n);
```

- Функция находит наибольший общий делитель двух чисел по алгоритму Евклида.

```cpp
int HML_GreatestCommonDivisorEuclid(int A,int B);
```

- Функция Хевисайда (функция одной переменной).

```cpp
template <class T> T HML_HeavisideFunction(T x);
```

- Функция вычисляет, какой минимальной степенью двойки можно покрыть целое положительное число.

```cpp
int HML_HowManyPowersOfTwo(int x);
```

- Функция осуществляет обратную нормировку числа из интервала \left[0;1\right]   в интервал \left[-\infty;\infty \right] , которое было осуществлено функцией HML_NormalizationNumberAll.

```cpp
double HML_InverseNormalizationNumberAll(double x);
```

- Функция находит наименьшее общее кратное двух чисел по алгоритму Евклида.

```cpp
int HML_LeastCommonMultipleEuclid(int A,int B);
```

- Функция вычисляет логарифм факториала числа.

```cpp
template <class T> T HML_LogFactorial(T x);
```

- Функция возвращает максимальный элемент из двух (до десяти).

```cpp
template <class T> T HML_Max(T a, T b);
template <class T> T HML_Max(T a, T b, T c);
template <class T> T HML_Max(T a, T b, T c, T d);
template <class T> T HML_Max(T a, T b, T c, T d, T e);
template <class T> T HML_Max(T a, T b, T c, T d, T e, T f);
template <class T> T HML_Max(T a, T b, T c, T d, T e, T f, T g);
template <class T> T HML_Max(T a, T b, T c, T d, T e, T f, T g, T h);
template <class T> T HML_Max(T a, T b, T c, T d, T e, T f, T g, T h, T i);
template <class T> T HML_Max(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j);
```

- Функция возвращает смысл жизни.

```cpp
double HML_MeaningOfLife();
```

- Функция возвращает минимальный элемент из двух (до десяти элементов).

```cpp
template <class T> T HML_Min(T a, T b);
template <class T> T HML_Min(T a, T b, T c);
template <class T> T HML_Min(T a, T b, T c, T d);
template <class T> T HML_Min(T a, T b, T c, T d, T e);
template <class T> T HML_Min(T a, T b, T c, T d, T e, T f);
template <class T> T HML_Min(T a, T b, T c, T d, T e, T f, T g);
template <class T> T HML_Min(T a, T b, T c, T d, T e, T f, T g, T h);
template <class T> T HML_Min(T a, T b, T c, T d, T e, T f, T g, T h, T i);
template <class T> T HML_Min(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j);
```

- Функция генерирует определенный вектор k-значной логики, где каждый элемент может принимать разное максимальное значение, в полном переборе вариантов. Генерируется I вектор в этом полном переборе.

```cpp
void HML_MixedMultiLogicVectorOfFullSearch(int *VHML_Vector, int I, int *HowMuchInElements, int VHML_N);
```

- Функция нормирует число из интервала \left[-\infty;\infty \right]  в интервал \left[0;1\right]. При этом в нуле возвращает 0.5, в -\infty возвращает 0, в \infty возвращает 1. Если x<y, то HML_NormalizationNumberAll(x)<HML_NormalizationNumberAll(y). Под бесконечностью принимается машинная бесконечность.

```cpp
double HML_NormalizationNumberAll(double x);
```

- Функция меняет местами значения двух чисел.

```cpp
template <class T> void HML_NumberInterchange(T *a, T *b);
template <class T> void HML_NumberInterchange(T &a, T &b);
```

- Функция проверяет четность целого числа.

```cpp
int HML_Parity(int a);
```

- Функция возводит произвольное число в целую степень.

```cpp
template <class T> T HML_PowerOf(T x, int n);
```

- Функция вычисляет плотность вероятности распределения обратного гауссовскому распределению..

```cpp
double HML_ProbabilityDensityFunctionOfInverseGaussianDistribution (double x, double mu, double lambda);
```

- Функция вычисляет знака числа.

```cpp
template <class T> int HML_Sign(T a);
```

- Функция вычисляет знака числа. При нуле возвращает 1.

```cpp
template <class T> int HML_SignNull(T a);
```

- Геометрическая прогрессия. Сумма первых n членов.

```cpp
double HML_SumGeometricSeries(double u1,double q,int n);
```

- Арифметическая прогрессия. Сумма первых n членов.

```cpp
double HML_SumOfArithmeticalProgression(double a1,double d,int n);
```

- Функция подсчитывает сумму цифр любого целого числа.

```cpp
int HML_SumOfDigits(int a);
```

- Функция меняет местами значения двух чисел.

```cpp
template <class T> void HML_Swap(T &a, T &b);
```

Матрицы
----------------

- Функция проверяет наличие одинаковых столбцов в матрице.

```cpp
template <class T> bool HML_CheckForIdenticalColsInMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M);
```

- Функция проверяет наличие одинаковых строк в матрице.

```cpp
template <class T> bool HML_CheckForIdenticalRowsInMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M);
```

- Функция умножает столбец матрицы на число.

```cpp
template <class T> void HML_ColInMatrixMultiplyNumber(T **VHML_ResultMatrix, int k, int VHML_N, T Number);
```

- Функция переставляет столбцы матрицы.

```cpp
template <class T> void HML_ColInterchange(T **VHML_ResultMatrix, int VHML_N, int k, int l);
```

- Функция копирует в матрицу (двумерный массив) из вектора столбец.

```cpp
template <class T> void HML_ColToMatrix(T **VHML_ResultMatrix, T *b, int VHML_N, int k);
```

- Функция удаляет k столбец из матрицы (начиная с нуля). Все правостоящие столбцы сдвигаются влево  на единицу. Последний столбец зануляется.

```cpp
template <class T> void HML_DeleteColInMatrix(T **VHML_ResultMatrix, int k, int VHML_N, int VHML_M);
```

- Функция удаляет k строку из матрицы (начиная с нуля). Все нижестоящие строки поднимаются на единицу. Последняя строка зануляется.

```cpp
template <class T> void HML_DeleteRowInMatrix(T **VHML_ResultMatrix, int k, int VHML_N, int VHML_M);
```

- Функция проверяет равенство матриц.

```cpp
template <class T> bool HML_EqualityOfMatrixes (T **a, T **b,int VHML_N,int VHML_M);
```

- Функция заполняет матрицу значениями, равных x.

```cpp
template <class T> void HML_FillMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M, T x);
```

- Функция формирует единичную квадратную матрицу.

```cpp
template <class T> void HML_IdentityMatrix(T **VHML_ResultMatrix,int VHML_N);
```

- Функция вычитает две матрицы. Или для переопределенной варианта функция вычитает два матрицы и результат записывает в первую матрицу. 

```cpp
template <class T> void HML_MatrixMinusMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M);
template <class T> void HML_MatrixMinusMatrix(T **VHML_ResultMatrix, T **b, int VHML_N, int VHML_M);
```

- Функция перемножает матрицы.

```cpp
template <class T> void HML_MatrixMultiplyMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S);
```

- Функция умножает матрицу на транспонированную матрицу.

```cpp
template <class T> void HML_MatrixMultiplyMatrixT(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S);
```

- Функция умножает матрицу на число.

```cpp
template <class T> void HML_MatrixMultiplyNumber(T **VHML_ResultMatrix, int VHML_N, int VHML_M, T Number);
```

- Функция суммирует две матрицы. Или для переопределенной варианта функция суммирует два матрицы и результат записывает в первую матрицу. 

```cpp
template <class T> void HML_MatrixPlusMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M);
template <class T> void HML_MatrixPlusMatrix(T **VHML_ResultMatrix, T **b, int VHML_N, int VHML_M);
```

- Функция транспонирует матрицу.

```cpp
template <class T> void HML_MatrixT(T **a, T **VHML_ResultMatrix, int VHML_N, int VHML_M);
```

- Функция умножает транспонированную матрицу на матрицу.

```cpp
template <class T> void HML_MatrixTMultiplyMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S);
```

- Функция копирует из матрицы (двумерного массива) в вектор столбец.

```cpp
template <class T> void HML_MatrixToCol(T **a, T *VHML_ResultVector, int VHML_N, int k);
```

- Функция копирует содержимое матрицы (двумерного массива) a в массив VHML_ResultMatrix.

```cpp
template <class T> void HML_MatrixToMatrix(T **a, T **VHML_ResultMatrix, int VHML_N, int VHML_M);
```

- Функция копирует из матрицы (двумерного массива) в вектор строку.

```cpp
template <class T> void HML_MatrixToRow(T **a, T *VHML_ResultVector, int k, int VHML_M);
```

- Функция ищет максимальный элемент в матрице (двумерном массиве).

```cpp
template <class T> T HML_MaximumOfMatrix(T **a, int VHML_N, int VHML_M);
```

- Функция ищет минимальный элемент в матрице (двумерном массиве).

```cpp
template <class T> T HML_MinimumOfMatrix(T **a, int VHML_N, int VHML_M);
```

- Функция меняет строки матрицы в порядке, указанным в массиве b.

```cpp
template <class T> void HML_MixingRowsInOrder(T **VHML_ResultMatrix, int *b, int VHML_N, int VHML_M);
```

- Функция подсчитывает число различных значений в матрице.

```cpp
template <class T> int HML_NumberOfDifferentValuesInMatrix(T **a, int VHML_N, int VHML_M);
```

- Функция умножает строку матрицы на число.

```cpp
template <class T> void HML_RowInMatrixMultiplyNumber(T **VHML_ResultMatrix, int k, int VHML_M, T Number);
```

- Функция переставляет строки матрицы.

```cpp
template <class T> void HML_MatrixToRow(T **a, T *VHML_ResultVector, int k, int VHML_M);
```

- Функция копирует в матрицу (двумерный массив) из вектора строку.

```cpp
template <class T> void HML_RowToMatrix(T **VHML_ResultMatrix, T *b, int k, int VHML_M);
```

- Функция вычисляет сумму элементов матрицы.

```cpp
template <class T> T HML_SumMatrix(T **a,int VHML_N,int VHML_M);
```

- Функция зануляет матрицу.

```cpp
template <class T> void HML_ZeroMatrix(T **VHML_ResultMatrix,int VHML_N,int VHML_M);
```

Метрика
----------------

- Функция вычисляет расстояние Чебышева.

```cpp
template <class T> T HML_Chebychev(T *x, T *y, int VHML_N);
```

- Функция вычисляет манхэттенское расстояние между двумя массивами.

```cpp
template <class T> T HML_CityBlock(T *x, T *y, int VHML_N);
```

- Функция вычисляет евклидово расстояние.

```cpp
template <class T> T HML_Euclid(T *x, T *y, int VHML_N);
```

- Функция вычисляет метрику Минковского.

```cpp
template <class T> T HML_Minkovski(T *x, T *y, int r, int VHML_N);
```

Модели
----------------

- Итерационная модель маятника Максвелла с затухающими колебаниями с управлением. Вызов данной процедуры прогоняет только одну итерацию, то есть одно наблюдение. Последующий вызов процедуры покажет положение маятника в следующий момент времени. Самим параметры менять не надо при вызове следующей итерации, так как процедура сама все поменяет (кроме, естественно, управляющего ускорения).

```cpp
int HML_PendulumOfMaxwell(double *Data);
```

Непараметрика
----------------

- Колоколообразное экспоненциальное ядро.

```cpp
double HML_BellShapedKernelExp(double z);
```

- Колоколообразное параболическое ядро.

```cpp
double HML_BellShapedKernelParabola(double z);
```

- Колоколообразное прямоугольное ядро.

```cpp
double HML_BellShapedKernelRectangle(double z);
```

- Колоколообразное треугольное ядро.

```cpp
double HML_BellShapedKernelTriangle(double z);
```

- Производная колоколообразного экспоненциального ядра.

```cpp
double HML_DerivativeOfBellShapedKernelExp(double z);
```

- Производная колоколообразного параболического ядра.

```cpp
double HML_DerivativeOfBellShapedKernelParabola(double z);
```

- Производная колоколообразного прямоугольного ядра.

```cpp
double HML_DerivativeOfBellShapedKernelRectangle(double z);
```

- Производная колоколообразного треугольного ядра.

```cpp
double HML_DerivativeOfBellShapedKernelTriangle(double z);
```

- Создание вектор непараметрической оценки производной в точках выборках. Служебная функция. Нужна для функции HML_NonparametricEstimatorOfDerivative3.

```cpp
void HML_MakingVectorForNonparametricEstimatorOfDerivative3(double *VHML_ResultVector, double *X, double *Y, int VHML_N, double C, int V);
```

- Создание вектор непараметрической оценки производной в точках выборках. Служебная функция. Нужна для функции HML_NonparametricEstimatorOfDerivative6.

```cpp
void HML_MakingVectorForNonparametricEstimatorOfDerivative6(double *VHML_ResultVector, double *X, double *Y, int VHML_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход.

```cpp
double HML_NonparametricEstimatorOfDerivative(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative(double x, double *X, double *Y, int VHML_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической оценке регрессии в вновь полученной выборке.

```cpp
double HML_NonparametricEstimatorOfDerivative2(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative2(double x, double *X, double *Y, int VHML_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической оценке регрессии в вновь полученной выборке. В отличии от HML_NonparametricEstimatorOfDerivative2 пересчет выборки производной производится в другой функции HML_MakingVectorForNonparametricEstimatorOfDerivative3.

```cpp
double HML_NonparametricEstimatorOfDerivative3(double x, double *X, double *dY, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative3(double x, double *X, double *dY, int VHML_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. Авторская разработка. Немного модифицирована формула по сравнению с HML_NonparametricEstimatorOfDerivative. Хорошо работает на концах выборки.

```cpp
double HML_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VHML_N, double C, int V);
```

- Авторская разработка. Немного модифицирована формула по сравнению с HML_NonparametricEstimatorOfDerivative. Хорошо работает на концах выборки. Отличается от HML_NonparametricEstimatorOfDerivative4 тем, что производная считается только в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической оценке регрессии в вновь полученной выборке.

```cpp
double HML_NonparametricEstimatorOfDerivative5(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative5(double x, double *X, double *Y, int VHML_N, double C, int V);
```

- Непараметрическая оценка производной при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. Отличается от HML_NonparametricEstimatorOfDerivative тем, что производная считается только в точках  выборки, а потом в остальных точках вычисляется как в обычной непараметрической оценке регрессии в вновь полученной выборке. В отличии от HML_NonparametricEstimatorOfDerivative2 пересчет выборки производной производится в другой функции HML_MakingVectorForNonparametricEstimatorOfDerivative3. Авторская разработка. Немного модифицирована формула по сравнению с HML_NonparametricEstimatorOfDerivative.

```cpp
double HML_NonparametricEstimatorOfDerivative6(double x, double *X, double *dY, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative6(double x, double *X, double *dY, int VHML_N, double C, int V);
```

- Непараметрическая оценка регрессии при равномерном законе распределения элементов выборки в точке. Рассматривается одномерный случай: 1 вход и 1 выход. В общем, это аппроксимация функции.

```cpp
double HML_NonparametricEstimatorOfRegression(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfRegression(double x, double *X, double *Y, int VHML_N, double C, int V);
```

Нечеткие системы
----------------

- Определяет центр тяжести трапециевидного нечеткого числа.

```cpp
double HML_CentroidOfTrapeziformFuzzyNumber(double a,double b,double c,double d);
```

- Функция находит максимальное значение функции принадлежности нечеткого числа, образуемого минимизацией двух трапециевидных нечетких чисел. Необходимо для нечеткого вывода.

```cpp
double HML_MaxiMinTrapeziformFuzzyNumbers (double *Data);
```

- Трапециевидное нечеткое число. Точнее его функция принадлежности.

```cpp
double HML_TrapeziformFuzzyNumber(double x,double a,double b,double c,double d);
```

- Трапециевидное усечённое нечеткое число. Точнее его функция принадлежности. Данное число соответствует операции редукции при нечетком выводе.

```cpp
double HML_TrapeziformTruncatedFuzzyNumber(double x, double a, double b, double c, double d, double m);
```

Оптимизация
----------------

- Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации на бинарных строках. В простонародье его называют <<методом научного тыка>>. Алгоритм оптимизации. Ищет максимум функции пригодности FitnessFunction.

```cpp
int HML_BinaryMonteCarloAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
```

- Метод дихотомии. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.

```cpp
void HML_DichotomyOptimization (double Left, double Right, double (*Function)(double), double Interval, double Epsilon, double *VHML_Result_X,double *VHML_Result_Y);
```

- Метод Фибоначчи. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.

```cpp
void HML_FibonacciOptimization (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y);
```

- Метод золотого сечения. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.

```cpp
void HML_GoldenSectionOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VHML_Result_X,double *VHML_Result_Y);
```

- Метод квадратичной интерполяции. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.

```cpp
void HML_QuadraticFitOptimization (double Left, double Right, double (*Function)(double), double Epsilon, double Epsilon2, double *VHML_Result_X,double *VHML_Result_Y);
```

- Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации на вещественных строках. В простонародье его называют "методом научного тыка".
Алгоритм оптимизации. Ищет максимум функции пригодности FitnessFunction.

```cpp
int HML_RealMonteCarloAlgorithm(int *Parameters, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
```

- Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации на вещественных строках. Ищет минимум. От функции HML_RealMonteCarloAlgorithm отличается тем, что ищет минимум, а не максимум, и не у многомерной функции, а одномерной. Вводится, чтобы было продолжением однотипных методов оптимизации одномерных унимодальных функций.

```cpp
void HML_RealMonteCarloOptimization (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y);
```

- Метод равномерного поиска. Метод одномерной оптимизации функции на интервале. Ищет минимум.

```cpp
void HML_UniformSearchOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VHML_Result_X,double *VHML_Result_Y);
```

- Метод равномерного поиска. Метод одномерной оптимизации функции на интервале. Ищет минимум. От HML_UniformSearchOptimization отличается тем, что вместо параметра шага равномерного прохода используется число вычислений целевой функции, но они взаимозаменяемы.

```cpp
void HML_UniformSearchOptimizationN (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y);
```

Оптимизация - свалка алгоритмов
----------------

- Генетический алгоритм для решения задач на бинарных строках с турнирной селекцией с возвращением, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но и она измененная, и размер турнира может изменяться.

```cpp
int HML_BinaryGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм с двойным количеством поколений для решения задач на бинарных строках. На четных поколениях целевая функция высчитывается как среднеарифметическое родителей.

```cpp
int HML_BinaryGeneticAlgorithmTwiceGenerations(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм для решения задач на бинарных строках, в котором есть только два вида скрещивания: одноточечное и двухточечное скрещивание с возможностью полного копирования одного из родителей. Равномерное скрещивание отсутствует.

```cpp
int HML_BinaryGeneticAlgorithmWCC(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм для решения задач на бинарных строках с изменяющимся соотношением числа поколений и размера популяции. Отличается от стандартного генетического алгоритма, тем, что размер популяции и число поколений рассчитывается из числа вычислений целевой функции не как одинаковые величины (извлечение квадратного корня), а через некоторое соотношение.

```cpp
int HML_BinaryGeneticAlgorithmWDPOfNOfGPS(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм для решения задач на бинарных строках с турнирной селекцией, где размер турнира изменяется от 2 до размера популяции. Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но размер турнира может изменяться.

```cpp
int HML_BinaryGeneticAlgorithmWDTS(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм для решения задач на вещественных строках  с турнирной селекцией с возвращением, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но и она измененная, и размер турнира может изменяться.

```cpp
int HML_RealGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм с двойным количеством поколений для решения задач на вещественных строках. На четных поколениях целевая функция высчитывается как среднеарифметическое родителей.

```cpp
int HML_RealGeneticAlgorithmTwiceGenerations(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм для решения задач на вещественных строках, в котором есть только два вида скрещивания: одноточечное и двухточечное скрещивание с возможностью полного копирования одного из родителей. Равномерное скрещивание отсутствует.

```cpp
int HML_RealGeneticAlgorithmWCC(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм для решения задач на вещественных строках с изменяющимся соотношением числа поколений и размера популяции. Отличается от стандартного генетического алгоритма, тем, что размер популяции и число поколений рассчитывается из числа вычислений целевой функции не как одинаковые величины (извлечение квадратного корня), а через некоторое соотношение.

```cpp
int HML_RealGeneticAlgorithmWDPOfNOfGPS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
```

- Генетический алгоритм для решения задач на вещественных строках  с турнирной селекцией, где размер турнира изменяется от 2 до размера популяции.
Отличается от стандартного генетического алгоритма, тем, что присутствует только турнирная селекция, но размер турнира может изменяться.

```cpp
int HML_RealGeneticAlgorithmWDTS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
```

Перевод единиц измерений
----------------

- Функция переводит угол из градусной меры в радианную.

```cpp
double HML_DegToRad(double VHML_X);
```

- Функция переводит угол из радианной меры в градусную.

```cpp
double HML_RadToDeg(double VHML_X);
```

Случайные объекты
----------------

- Функция формирует случайный вектор Бернулли.

```cpp
template <class T> void HML_BernulliVector(T *VHML_ResultVector, int VHML_N);
```

- Функция с вероятностью P (или 0.5 в переопределенной функции) возвращает 1. В противном случае возвращает 0.

```cpp
int HML_BitNumber(double P);
int HML_BitNumber();
```

- Функция предлагает случайный способ расставить N объектов в VHML_N корзин при условии, что в каждой корзине может располагаться только один предмет.

```cpp
template <class T> void HML_RandomArrangingObjectsIntoBaskets(T *VHML_ResultVector, int N, int VHML_N);
```

- Функция заполняет матрицу случайно нулями и единицами.

```cpp
template <class T> void HML_RandomBinaryMatrix(T **VHML_ResultMatrix,int VHML_N,int VHML_M);
```

- Функция заполняет вектор (одномерный массив) случайно нулями и единицами.

```cpp
template <class T> void HML_RandomBinaryVector(T *VHML_ResultVector,int VHML_N);
```

- Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).

```cpp
template <class T> void HML_RandomIntMatrix(T **VHML_ResultMatrix, T n, T m, int VHML_N, int VHML_M);
```

- Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m). При этом элементы каждого столбца изменяются в своих пределах.

```cpp
template <class T> void HML_RandomIntMatrixInCols(T **VHML_ResultMatrix, T *n, T *m, int VHML_N, int VHML_M);
```

- Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m). При этом каждый элемент изменяется в своих пределах.

```cpp
template <class T> void HML_RandomIntMatrixInElements(T **VHML_ResultMatrix, T **n, T **m, int VHML_N, int VHML_M);
```

- Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m). При этом элементы каждой строки изменяются в своих пределах.

```cpp
template <class T> void HML_RandomIntMatrixInRows(T **VHML_ResultMatrix, T *n, T *m, int VHML_N, int VHML_M);
```

- Функция заполняет массив случайными целыми числами из определенного интервала [n,m).

```cpp
template <class T> void HML_RandomIntVector(T *VHML_ResultVector, T n, T m, int VHML_N);
```

- Функция заполняет массив случайными целыми  числами из определенного интервала [n_i,m_i). При этом для каждого элемента массива свой интервал изменения.

```cpp
template <class T> void HML_RandomIntVectorInElements(T *VHML_ResultVector, T *n, T *m, int VHML_N);
```

- Функция создает случайный массив строк-перестановок чисел от 1 до VHML_M.

```cpp
template <class T> void HML_RandomMatrixOfPermutation(T **VHML_ResultMatrix, int VHML_N, int VHML_M);
```

- Функция заполняет матрицу случайными вещественными числами из определенного интервала [Left;Right].

```cpp
void HML_RandomRealMatrix(double **VHML_ResultMatrix, double Left, double Right, int VHML_N, int VHML_M);
```

- Функция заполняет матрицу случайными вещественными числами из определенного интервала. При этом элементы каждого столбца изменяются в своих пределах.

```cpp
void HML_RandomRealMatrixInCols(double **VHML_ResultMatrix, double *Left, double *Right, int VHML_N, int VHML_M);
```

- Функция заполняет матрицу случайными вещественными числами из определенного интервала. При этом каждый элемент изменяется в своих пределах.

```cpp
void HML_RandomRealMatrixInElements(double **VHML_ResultMatrix, double **Left, double **Right, int VHML_N, int VHML_M);
```

- Функция заполняет матрицу случайными вещественными числами из определенного интервала. При этом элементы каждой строки изменяются в своих пределах.

```cpp
void HML_RandomRealMatrixInRows(double **VHML_ResultMatrix, double *Left, double *Right, int VHML_N, int VHML_M);
```

- Функция заполняет массив случайными вещественными числами из определенного интервала [Left;Right].

```cpp
void HML_RandomRealVector(double *VHML_ResultVector, double Left, double Right, int VHML_N);
```

- Функция заполняет массив случайными вещественными числами из определенного интервала, где на каждую координату свои границы изменения.

```cpp
void HML_RandomRealVectorInElements(double *VHML_ResultVector, double *Left, double *Right, int VHML_N);
```

- Функция создает случайную строку-перестановку чисел от 1 до VHML_N (включительно).

```cpp
template <class T> void HML_RandomVectorOfPermutation(T *VHML_ResultVector, int VHML_N);
```

- Функция заполняет вектор случайными значениями вероятностей. Сумма всех элементов вектора равна 1.

```cpp
void HML_RandomVectorOfProbability(double *VHML_ResultVector, int VHML_N);
```

Случайные числа
----------------

- Случайное число по нормальному закону распределения.

```cpp
double HML_RandomNormal(double Mean, double StdDev);
```

- Случайное вещественное число в интервале [a;b] по равномерному закону распределения.

```cpp
double HML_RandomUniform(double a, double b);
```

- Случайное целое число в интервале [n,m) по равномерному закону распределения.

```cpp
int HML_RandomUniformInt(int n, int m);
```

- Случайное целое число в интервале [n,m] по равномерному закону распределения.

```cpp
int HML_RandomUniformIntIncluding(int n, int m);
```

Сортировка
----------------

- Функция сортирует массив в порядке убывания методом <<Сортировка пузырьком>>.

```cpp
template <class T> void HML_BubbleDescendingSort(T *VHML_ResultVector, int VHML_N);
```

- Функция сортирует массив в порядке возрастания методом <<Сортировка пузырьком>>.

```cpp
template <class T> void HML_BubbleSort(T *VHML_ResultVector, int VHML_N);
```

- Функция сортирует матрицу по какому-то столбцу под номером в порядке возрастания методом <<Сортировка пузырьком>>. При этом все остальные столбцы являются как бы сопряженным с данным столбцом. То есть элементы в этом столбце сортируются, а все строки остаются прежними.

```cpp
template <class T> void HML_BubbleSortColWithOtherConjugateColsInMatrix(T **VHML_ResultMatrix,int Col, int VHML_N, int VHML_M);
```

- Функция сортирует каждый столбец матрицы в отдельности.

```cpp
template <class T> void HML_BubbleSortEveryColInMatrix(T **VHML_ResultMatrix,int VHML_N, int VHML_M);
```

- Функция сортирует каждую строку матрицы в отдельности.

```cpp
template <class T> void HML_BubbleSortEveryRowInMatrix(T **VHML_ResultMatrix,int VHML_N, int VHML_M);
```

- Функция сортирует массив в порядке возрастания методом <<Сортировка пузырьком>> в группах данного массива. Имеется массив. Он делится на группы элементов по m элементов. Первые m элементов принадлежат первой группе, следующие m элементов --- следующей и т.д. (Разумеется, в последней группе может и не оказаться m элементов). Потом в каждой группе элементы сортируются по возрастанию.

```cpp
template <class T> void HML_BubbleSortInGroups(T *VHML_ResultVector, int VHML_N, int m);
```

- Функция сортирует матрицу по какой-то строке под номером в порядке возрастания методом <<Сортировка пузырьком>>. При этом все остальные строки являются как бы сопряжеными с данной строкой. То есть элементы в этой строке сортируются, а все столбцы остаются прежними.

```cpp
template <class T> void HML_BubbleSortRowWithOtherConjugateRowsInMatrix(T **VHML_ResultMatrix,int Row, int VHML_N, int VHML_M);
```

- Функция сортирует массив вместе с сопряженный массивом в порядке возрастания методом <<Сортировка пузырьком>>. Пары элементов первого массива и сопряженного остаются без изменения.

```cpp
template <class T, class T2> void HML_BubbleSortWithConjugateVector(T *VHML_ResultVector, T2 *VHML_ResultVector2, int VHML_N);
```

- Функция сортирует массив вместе с двумя сопряженными массивами в порядке возрастания методом <<Сортировка пузырьком>>. Пары элементов первого массива и сопряженного остаются без изменения.

```cpp
template <class T, class T2, class T3> void HML_BubbleSortWithTwoConjugateVectors(T *VHML_ResultVector, T2 *VHML_ResultVector2, T3 *VHML_ResultVector3, int VHML_N);
```

Статистика и теория вероятности
----------------

- Плотность распределения вероятности нормированного и центрированного нормального распределения.

```cpp
double HML_DensityOfDistributionOfNormalizedCenteredNormalDistribution(double x);
```

- Функция распределения нормального распределения.

```cpp
double HML_DistributionFunctionOfNormalDistribution(double x, double mu, double sigma, double Epsilon);
```

- Функция распределения нормированного и центрированного нормального распределения.

```cpp
double HML_DistributionFunctionOfNormalizedCenteredNormalDistribution(double x, double Epsilon);
```

- Функция возвращает левую границу интервала критический значений статистики W для критерия Вилкоксена по табличным данным.

```cpp
double HML_LeftBorderOfWilcoxonWFromTable(int m, int n, double Q);
```

- Функция вычисляет среднее арифметическое массива.

```cpp
template <class T> T HML_Mean(T *x, int VHML_N);
```

- Функция вычисляет среднее арифметическое массива с фильтром, то есть при подсчете не учитываются значения ниже LowerFilter и выше UpperFilter.

```cpp
template <class T> T HML_MeanOfFilter(T *x, int VHML_N, T UpperFilter, T LowerFilter);
```

- Функция вычисляет среднее арифметическое массива с нижним фильтром, то есть при подсчете не учитываются значения ниже LowerFilter.

```cpp
template <class T> T HML_MeanOfLowerFilter(T *x, int VHML_N, T LowerFilter);
```

- Функция вычисляет среднее арифметическое массива с верхним фильтром, то есть при подсчете не учитываются значения выше UpperFilter.

```cpp
template <class T> T HML_MeanOfUpperFilter(T *x, int VHML_N, T UpperFilter);
```

- Функция вычисляет медиану выборки.

```cpp
template <class T> T HML_Median(T *x, int VHML_N);
```

- Функция возвращает правую границу интервала критический значений статистики W для критерия Вилкоксена по табличным данным.

```cpp
double HML_RightBorderOfWilcoxonWFromTable(int m, int n, double Q);
```

- Функция вычисляет выборочную ковариацию выборки (несмещенная, исправленная).

```cpp
template <class T> T HML_SampleCovariance(T *x, T *y, int VHML_N);
```

- Функция переводит среднеквадратичное уклонение в значение дисперсии случайной величины.

```cpp
double HML_StdDevToVariance(double StdDev);
```

- Функция вычисляет неисправленная выборочную дисперсию выборки..

```cpp
template <class T> T HML_UncorrectedVariance(T *x, int VHML_N);
```

- Функция вычисляет выборочную дисперсию выборки (несмещенная, исправленная).

```cpp
template <class T> T HML_Variance(T *x, int VHML_N);
```

- Функция переводит значение дисперсии случайной величины в среднеквадратичное уклонение.

```cpp
double HML_VarianceToStdDev(double Variance);
```

- Функция проверяет однородность выборок по критерию Вилкосена W.

```cpp
int HML_WilcoxonW(double *a, double *b, int VHML_N1, int VHML_N2, double Q);
int HML_WilcoxonW(double *a, double *b, int VHML_N1, int VHML_N2, double Q, double *Lr, double *Rr, double *Wr);
```

Тестовые функции для оптимизации
----------------

- Функция многих переменных: Ackley. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Ackley(double *x, int VHML_N);
```

- Функция двух переменных: аддитивная потенциальная функция. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_AdditivePotential(double x, double y);
```

- Функция двух переменных: функция Bosom. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Bosom(double x, double y);
```

- Функция двух переменных: функция Egg Holder. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_EggHolder(double x, double y);
```

- Функция многих переменных: функция Gaussian quartic. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_GaussianQuartic(double *x, int VHML_N);
```

- Функция многих переменных: функция Гриванка. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Griewangk(double *x, int VHML_N);
```

- Функция двух переменных: функция Химмельблау. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Himmelblau(double x, double y);
```

- Функция многих переменных: Гипер-эллипсоид. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_HyperEllipsoid(double *x, int VHML_N);
```

- Функция двух переменных: перевернутая функция Розенброка. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_InvertedRosenbrock(double x, double y);
```

- Функция двух переменных: функция Катникова. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Katnikov(double x, double y);
```

- Функция одной переменных: функция Multiextremal. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Multiextremal(double x);
```

- Функция одной переменных: функция Multiextremal2. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Multiextremal2(double x);
```

- Функция двух переменных: функция Multiextremal3. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Multiextremal3(double x, double y);
```

- Функция двух переменных: функция Multiextremal4. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Multiextremal4(double x, double y);
```

- Функция двух переменных: мультипликативная потенциальная функция. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_MultiplicativePotential(double x, double y);
```

- Функция многих переменных: Эллиптический параболоид. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_ParaboloidOfRevolution(double *x, int VHML_N);
```

- Функция двух переменных: функция Rana. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Rana(double x, double y);
```

- Функция многих переменных: функция Растригина. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Rastrigin(double *x, int VHML_N);
```

- Функция многих переменных: функция Растригина новгородская. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_RastriginNovgorod(double *x, int VHML_N);
```

- Функция двух переменных: функция Растригина с изменением коэффициентов. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_RastriginWithChange(double x, double y);
```

- Функция двух переменных: функция Растригина овражная с поворотом осей. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_RastriginWithTurning(double x, double y);
```

- Функция двух переменных: функция ReverseGriewank. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_ReverseGriewank(double x, double y);
```

- Функция многих переменных: функция Розенброка. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Rosenbrock(double *x, int VHML_N);
```

- Функция многих переменных: Развернутый гипер-эллипсоид. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_RotatedHyperEllipsoid(double *x, int VHML_N);
```

- Функция многих переменных: функция Швефеля. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Schwefel(double *x, int VHML_N);
```

- Функция двух переменных: функция <<Лисьи норы>> Шекеля. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_ShekelsFoxholes(double x, double y);
```

- Функция двух переменных: функция Сомбреро. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Sombrero(double x, double y);
```

- Функция многих переменных: Функция Step (модифицированная версия De Jong 3). Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_StepFunction(double *x, int VHML_N);
```

- Сумма всех элементов бинарного вектора. Тестовая функция бинарной оптимизации.

```cpp
double HML_TestFunction_SumVector(int *x, int VHML_N);
```

- Функция одной переменных: волна. Тестовая функция вещественной оптимизации.

```cpp
double HML_TestFunction_Wave(double x);
```

Тригонометрические функции
----------------

- Функция возвращает косинус угла в радианах.

```cpp
double HML_Cos(double x);
```

- Функция возвращает косинус угла в градусах.

```cpp
double HML_CosDeg(double x);
```

- Функция возвращает косеканс угла в радианах.

```cpp
double HML_Cosec(double x);
```

- Функция возвращает косеканс угла в градусах.

```cpp
double HML_CosecDeg(double x);
```

- Функция возвращает котангенс угла в радианах.

```cpp
double HML_Cotan(double x);
```

- Функция возвращает котангенс угла в градусах.

```cpp
double HML_CotanDeg(double x);
```

- Функция возвращает секанс угла в радианах.

```cpp
double HML_Sec(double x);
```

- Функция возвращает секанс угла в градусах.

```cpp
double HML_SecDeg(double x);
```

- Функция возвращает синус угла в радианах.

```cpp
double HML_Sin(double x);
```

- Функция возвращает синус угла в градусах.

```cpp
double HML_SinDeg(double x);
```

- Функция возвращает тангенс угла в радианах.

```cpp
double HML_Tan(double x);
```

- Функция возвращает тангенс угла в градусах.

```cpp
double HML_TanDeg(double x);
```

Уравнения
----------------

- Функция решает квадратное уравнение вида: a\cdot x^2+b\cdot x+c=0. Ответ представляет собой два действительных числа.

```cpp
int HML_QuadraticEquation(double a, double b, double c, double *x1, double *x2);
```

- Функция решает квадратное уравнение вида: a\cdot x^2+b\cdot x+c=0. Ответ представляет собой два действительных числа. Отличается от HML_QuadraticEquation только тем, что возвращается количество решений, а не его наличие.

```cpp
int HML_QuadraticEquationCount(double a, double b, double c, double *x1, double *x2);
```

Физика
----------------

- Функция вычисляет ускорение по второму закону Ньютона.

```cpp
double HML_NewtonSecondLawAcceleration(double F, double m);
```

- Функция вычисляет силу по второму закону Ньютона.

```cpp
double HML_NewtonSecondLawForce(double a, double m);
```

Цвет
----------------

- Функция увеличивает яркость цвета через прибавление к каждому каналу числа p. Выдает значение канала B.

```cpp
int HML_AddColorB(int R, int G, int B, double p);
```

- Функция увеличивает яркость цвета через прибавление к каждому каналу числа p. Выдает значение канала G.

```cpp
int HML_AddColorG(int R, int G, int B, double p);
```

- Функция увеличивает яркость цвета через прибавление к каждому каналу числа p. Выдает значение канала R.

```cpp
int HML_AddColorR(int R, int G, int B, double p);
```

- Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала B.

```cpp
int HML_AlphaBlendingColorToColorB(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала G.

```cpp
int HML_AlphaBlendingColorToColorG(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала R.

```cpp
int HML_AlphaBlendingColorToColorR(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала B.

```cpp
int HML_ColorFromGradientB(double position, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала G.

```cpp
int HML_ColorFromGradientG(double position, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала R.

```cpp
int HML_ColorFromGradientR(double position, int R1, int G1, int B1, int R2, int G2, int B2);
```

- Функция уменьшает яркость цвета через деление каждого канала на число p. Выдает значение канала B.

```cpp
int HML_DivideColorB(int R, int G, int B, double p);
```

- Функция уменьшает яркость цвета через деление каждого канала на число p. Выдает значение канала G.

```cpp
int HML_DivideColorG(int R, int G, int B, double p);
```

- Функция уменьшает яркость цвета через деление каждого канала на число p. Выдает значение канала R.

```cpp
int HML_DivideColorR(int R, int G, int B, double p);
```

- Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала B.

```cpp
int HML_GiveRainbowColorB(double position);
```

- Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала G.

```cpp
int HML_GiveRainbowColorG(double position);
```

- Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала R.

```cpp
int HML_GiveRainbowColorR(double position);
```

- Функция переводит цвет в серый цвет. Выдает значение канала B.

```cpp
int HML_GreyscaleB(int R, int G, int B);
```

- Функция переводит цвет в серый цвет. Выдает значение канала G.

```cpp
int HML_GreyscaleG(int R, int G, int B);
```

- Функция переводит цвет в серый цвет. Выдает значение канала R.

```cpp
int HML_GreyscaleR(int R, int G, int B);
```

- Функция увеличивает яркость цвета через умножение каждого канала числа на p. Выдает значение канала B.

```cpp
int HML_MultiplyColorB(int R, int G, int B, double p);
```

- Функция увеличивает яркость цвета через умножение каждого канала числа на p. Выдает значение канала G.

```cpp
int HML_MultiplyColorG(int R, int G, int B, double p);
```

- Функция увеличивает яркость цвета через умножение каждого канала числа на p. Выдает значение канала R.

```cpp
int HML_MultiplyColorR(int R, int G, int B, double p);
```

- Функция инвертирует цвет. Выдает значение канала B.

```cpp
int HML_NegativeColorB(int R, int G, int B);
```

- Функция инвертирует цвет. Выдает значение канала G.

```cpp
int HML_NegativeColorG(int R, int G, int B);
```

- Функция инвертирует цвет. Выдает значение канала R.

```cpp
int HML_NegativeColorR(int R, int G, int B);
```

- Функция уменьшает яркость цвета через отнимание от каждого канала числа p. Выдает значение канала B.

```cpp
int HML_SubtractColorB(int R, int G, int B, double p);
```

- Функция уменьшает яркость цвета через отнимание от каждого канала числа p. Выдает значение канала G.

```cpp
int HML_SubtractColorG(int R, int G, int B, double p);
```

- Функция уменьшает яркость цвета через отнимание от каждого канала числа p. Выдает значение канала R.

```cpp
int HML_SubtractColorR(int R, int G, int B, double p);
```

