#ifndef HARRIXMATHLIBRARY_H
#define HARRIXMATHLIBRARY_H
#include <stdlib.h>
#include <time.h>
#include <math.h>

// КОНСТАНТЫ
const double HML_TAU=0.61803398874989484820;
const double HML_E=2.71828182845904523536;
const double HML_LOG2E=1.44269504088896340736;
const double HML_LOG10E=0.434294481903251827651;
const double HML_LN2=0.693147180559945309417;
const double HML_LN10=2.30258509299404568402;
const double HML_PI=3.14159265358979323846;
const double HML_PI_2=1.57079632679489661923;
const double HML_PI_4=0.785398163397448309616;
const double HML_1_PI=0.318309886183790671538;
const double HML_2_PI=0.636619772367581343076;
const double HML_1_SQRTPI=0.564189583547756286948;
const double HML_2_SQRTPI=1.12837916709551257390;
const double HML_SQRT2=1.41421356237309504880;
const double HML_SQRT_2=0.707106781186547524401;
const double HML_INFINITY=1.7E308;//Машинная бесконечность
const double HML_MINFINITY=-1.7E308;//Минус машинная бесконечность
const double HML_MEANINGOFLIFE=42;//Смысл жизни
const double HML_G=9.80665;//Ускорение свободного падения
const double HML_GM=9.8156;//Ускорение свободного падения в Москве

//ДЛЯ ГЕНЕРАТОРОВ СЛУЧАЙНЫХ ЧИСЕЛ
enum TypeOfRandomNumberGenerator { StandardRandomNumberGenerator, MersenneTwisterRandomNumberGenerator };//тип генератора случайных чисел: стандартный или MersenneTwister:
void HML_SeedRandom(void);//Инициализатор генератора случайных чисел
double HML_RandomNumber(void);//Генерирует вещественное случайное число из интервала (0;1)
void HML_SetRandomNumberGenerator(TypeOfRandomNumberGenerator T);//Переназначить генератор случайных чисел на другой

//ПЕРЕМЕННЫЕ ПЕРЕЧИСЛЯЕМОГО ТИПА

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Вектора (Одномерные массивы)
template <class T> void HML_AcceptanceLimits(T *VHML_ResultVector, T *Left, T *Right, int VHML_N);
template <class T> void HML_AcceptanceLimits(T *VHML_ResultVector, T Left, T Right, int VHML_N);
template <class T> void HML_AcceptanceLimitsLeft(T *VHML_ResultVector, T *Left, int VHML_N);
template <class T> void HML_AcceptanceLimitsLeft(T *VHML_ResultVector, T Left, int VHML_N);
template <class T> void HML_AcceptanceLimitsRight(T *VHML_ResultVector, T *Right, int VHML_N);
template <class T> void HML_AcceptanceLimitsRight(T *VHML_ResultVector, T Right, int VHML_N);
template <class T> void HML_ChangeOrderInVector(T *VHML_Vector, T *VHML_ResultVector, int *Order, int VHML_N);
template <class T> void HML_ChangeOrderInVector(T *VHML_Vector, int *Order, int VHML_N);
template <class T> int HML_CheckElementInVector(T *x, int VHML_N, T a);
template <class T> int HML_CompareMeanOfVectors(T *a, T *b, int VHML_N);
template <class T> int HML_CompareMeanOfVectors(T *a, T *b, int VHML_N1, int VHML_N2);
void HML_DependentNoiseInVector(double *VHML_ResultVector, double percent, int VHML_N);
template <class T> bool HML_EqualityOfVectors(T *a, T *b, int VHML_N);
double HML_EuclidNorma(double *a,int VHML_N);
template <class T> void HML_FibonacciNumbersVector(T *VHML_ResultVector, int VHML_N);
template <class T> void HML_FillVector(T *VHML_ResultVector, int VHML_N, T x);
template <class T> T HML_MaximumOfVector(T *VHML_Vector, int VHML_N);
template <class T> T HML_MinimumOfVector(T *VHML_Vector, int VHML_N);
template <class T> void HML_MixingVector(T *VHML_ResultVector, double P, int VHML_N);
template <class T, class T2> void HML_MixingVectorWithConjugateVector(T *VHML_ResultVector, T2 *VHML_ResultVector2, double P, int VHML_N);
void HML_NoiseInVector(double *VHML_ResultVector, double percent, int VHML_N);
template <class T> int HML_NumberOfDifferentValuesInVector(T *a, int VHML_N);
template <class T> int HML_NumberOfMaximumOfVector(T *a, int VHML_N);
template <class T> int HML_NumberOfMinimumOfVector(T *a, int VHML_N);
template <class T> int HML_NumberOfNegativeValues(T *a, int VHML_N);
template <class T> int HML_NumberOfPositiveValues(T *a, int VHML_N);
template <class T> int HML_NumberOfZeroValues(T *a, int VHML_N);
template <class T> void HML_OrdinalVector(T *VHML_ResultVector, int VHML_N);
template <class T> void HML_OrdinalVectorZero(T *VHML_ResultVector, int VHML_N);
template <class T> T HML_ProductOfElementsOfVector(T *VHML_Vector,int VHML_N);
template <class T> void HML_ReverseVector(T *VHML_ResultVector, int VHML_N);
template <class T> int HML_SearchElementInVector (T *X, T x, int VHML_N);
template <class T> int HML_SearchFirstNotZero(T *x, int VHML_N);
template <class T> int HML_SearchFirstZero(T *x, int VHML_N);
int HML_SeparateVectorLimitOnProductElements(int *VHML_Vector, int *Order, int Limit, int VHML_N);
int HML_SeparateVectorLimitOnProductElementsTwo(int *VHML_Vector, int *Order, int Limit, int VHML_N);
template <class T> void HML_ShiftLeftVector(T *VHML_Vector, int VHML_N);
template <class T> void HML_ShiftRightVector(T *VHML_Vector, int VHML_N);
template <class T> T HML_SumSquareVector(T *VHML_Vector,int VHML_N);
template <class T> T HML_SumVector(T *VHML_Vector,int VHML_N);
template <class T> void HML_VectorMinusVector(T *a, T *b, T *VHML_ResultVector, int VHML_N);
template <class T> void HML_VectorMinusVector(T *VHML_ResultVector, T *b, int VHML_N);
template <class T> void HML_VectorMultiplyNumber(T *VHML_ResultVector, int VHML_N, T Number);
template <class T> void HML_VectorPlusVector(T *a, T *b, T *VHML_ResultVector, int VHML_N);
template <class T> void HML_VectorPlusVector(T *VHML_ResultVector, T *b, int VHML_N);
template <class T> void HML_VectorToVector(T *VHML_Vector, T *VHML_ResultVector, int VHML_N);
template <class T> void HML_ZeroVector(T *VHML_ResultVector,int VHML_N);

//Генетические алгоритмы
void HML_ArithmeticalCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N);
void HML_BLXCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double alpha, int VHML_N);
double HML_BinaryFitnessFunction(int*x, int VHML_N);
void HML_ExtendedLineForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N);
void HML_FlatCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
void HML_GeometricalCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N);
void HML_LinearCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
void HML_MakeVectorOfProbabilityForProportionalSelectionV2(double *Fitness, double *VHML_ResultVector, int VHML_N);
void HML_MakeVectorOfProbabilityForRanklSelection(double *Rank, double *VHML_ResultVector, int VHML_N);
void HML_MakeVectorOfRankForRankSelection(double *Fitness, double *VHML_ResultVector, int VHML_N);
void HML_MakeVectorOfRankZeroForRankSelection(double *Fitness, double *VHML_ResultVector, int VHML_N);
template <class T> void HML_MutationBinaryMatrix(T **VHML_ResultMatrix, double ProbabilityOfMutation, int VHML_N,int VHML_M);
template <class T> void HML_MutationBinaryVector(T *VHML_ResultVector, double ProbabilityOfMutation, int VHML_N);
void HML_NormalizationVectorAll(double *x,int VHML_N);
void HML_NormalizationVectorMaxMin(double *VHML_ResultVector,int VHML_N);
void HML_NormalizationVectorOne(double *VHML_ResultVector,int VHML_N);
double HML_ProbabilityOfTournamentSelection(double *Fitness, double *VHML_ResultVector_Probability, int T, int VHML_N);
int HML_ProportionalSelection(double *Fitness, int VHML_N);
int HML_ProportionalSelectionV2(double *VectorOfProbability, int VHML_N);
int HML_ProportionalSelectionV3(double *Fitness, int VHML_N);
int HML_RankSelection(double *VectorOfProbability, int VHML_N);
int HML_SelectItemOnProbability(double *P, int VHML_N);
template <class T> void HML_SinglepointCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
void HML_SinglepointCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
template <class T> void HML_SinglepointCrossoverWithCopying(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
int HML_StandartBinaryGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
int HML_StandartGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
int HML_StandartGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
int HML_StandartRealGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
int HML_TournamentSelection(double *Fitness, int SizeTournament, int VHML_N);
int HML_TournamentSelection(double *Fitness, int SizeTournament, int *Taken, int VHML_N);
int HML_TournamentSelectionWithReturn(double *Fitness, int SizeTournament, int VHML_N);
template <class T> void HML_TwopointCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
void HML_TwopointCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);
template <class T> void HML_TwopointCrossoverWithCopying(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
template <class T> void HML_UniformCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N);
void HML_UniformCrossoverForReal(double*Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N);

//Геометрия
template <class T> int HML_BoolCrossingTwoSegment(T b1,T c1,T b2,T c2);
double HML_LineGeneralForm(double x, double A, double B, double C, int *solutionis);
double HML_LineGeneralForm(double x, double A, double B, double C);
double HML_LineSlopeInterceptForm(double x, double k, double b);
double HML_LineTwoPoint(double x, double x1, double y1, double x2, double y2, int *solutionis);
double HML_LineTwoPoint(double x, double x1, double y1, double x2, double y2);
double HML_Parabola(double x, double a, double b, double c);

//Гиперболические функции
double HML_Cosech(double x);
double HML_Cosh(double x);
double HML_Cotanh(double x);
double HML_Sech(double x);
double HML_Sinh(double x);
double HML_Tanh(double x);

//Дифференцирование
double HML_CenterDerivative(double x, double h, double (*Function)(double));
double HML_LeftDerivative(double x, double h, double (*Function)(double));
double HML_RightDerivative(double x, double h, double (*Function)(double));

//Интегрирование
double HML_IntegralOfRectangle(double a, double b, double Epsilon,double (*Function)(double));
double HML_IntegralOfSimpson(double a, double b, double Epsilon,double (*Function)(double));
double HML_IntegralOfTrapezium(double a, double b, double Epsilon,double (*Function)(double));

//Кодирование и декодирование
void HML_BinaryGrayVectorToRealVector(int *x, int n, double *VHML_ResultVector, double *Left, double *Right, int *Lengthi, int VHML_N);
void HML_BinaryGrayVectorToRealVector(int *x, double *VHML_ResultVector,int *TempBinaryVector, double *Left, double *Right, int *Lengthi, int VHML_N);
template <class T> T HML_BinaryToDecimal(T *a, int VHML_N);
template <class T> T HML_BinaryToDecimalFromPart(T *a, int Begin, int n);
void HML_BinaryVectorToRealVector(int *x, double *VHML_ResultVector, double *Left, double *Right, int *Lengthi, int VHML_N);
template <class T> void HML_GrayCodeToBinary(T *a,int *VHML_ResultVector, int VHML_N);
template <class T> void HML_GrayCodeToBinaryFromPart(T *a, T *VHML_ResultVector, int Begin, int n);

//Комбинаторика
template <class T> T HML_KCombinations(T k, T n);

//Математические функции
template <class T> T HML_Abs(T x);
template <class T> T HML_AcceptanceLimitsNumber(T Number, T Left, T Right);
template <class T> T HML_AcceptanceLimitsNumberLeft(T Number, T Left);
template <class T> T HML_AcceptanceLimitsNumberRight(T Number, T Right);
template <class T> bool HML_AlmostEqual(T x, T y);
template <class T> bool HML_AlmostEqual(T x, T y, double epsilon);
template <class T> bool HML_AlmostZero(T x);
template <class T> bool HML_AlmostZero(T x, double epsilon);
double HML_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything();
double HML_ArithmeticalProgression(double a1,double d,int n);
double HML_ExpMSxD2(double x);
template <class T> T HML_Factorial(T x);
template <class T> T HML_FibonacciNumber(T n);
double HML_GeometricSeries(double u1,double q,int n);
int HML_GreatestCommonDivisorEuclid(int A,int B);
template <class T> T HML_HeavisideFunction(T x);
int HML_HowManyPowersOfTwo(int x);
double HML_InverseNormalizationNumberAll(double x);
int HML_LeastCommonMultipleEuclid(int A,int B);
template <class T> T HML_Max(T a, T b);
double HML_MeaningOfLife();
template <class T> T HML_Min(T a, T b);
void HML_MixedMultiLogicVectorOfFullSearch(int *VHML_Vector, int I, int *HowMuchInElements, int VHML_N);
double HML_NormalizationNumberAll(double x);
template <class T> void HML_NumberInterchange(T *a, T *b);
int HML_Parity(int a);
template <class T> T HML_PowerOf(T x, int n);
double HML_ProbabilityDensityFunctionOfInverseGaussianDistribution (double x, double mu, double lambda);
template <class T> int HML_Sign(T a);
template <class T> int HML_SignNull(T a);
double HML_SumGeometricSeries(double u1,double q,int n);
double HML_SumOfArithmeticalProgression(double a1,double d,int n);
int HML_SumOfDigits(int a);

//Матрицы
template <class T> bool HML_CheckForIdenticalColsInMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M);
template <class T> bool HML_CheckForIdenticalRowsInMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M);
template <class T> void HML_ColInterchange(T **VHML_ResultMatrix, int VHML_N, int k, int l);
template <class T> void HML_ColToMatrix(T **VHML_ResultMatrix, T *b, int VHML_N, int k);
template <class T> void HML_DeleteColInMatrix(T **VHML_ResultMatrix, int k, int VHML_N, int VHML_M);
template <class T> void HML_DeleteRowInMatrix(T **VHML_ResultMatrix, int k, int VHML_N, int VHML_M);
template <class T> bool HML_EqualityOfMatrixes (T **a, T **b,int VHML_N,int VHML_M);
template <class T> void HML_FillMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M, T x);
template <class T> void HML_IdentityMatrix(T **VHML_ResultMatrix,int VHML_N);
template <class T> void HML_MatrixMinusMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M);
template <class T> void HML_MatrixMinusMatrix(T **VHML_ResultMatrix, T **b, int VHML_N, int VHML_M);
template <class T> void HML_MatrixMultiplyMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S);
template <class T> void HML_MatrixMultiplyMatrixT(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S);
template <class T> void HML_MatrixMultiplyNumber(T **VHML_ResultMatrix, int VHML_N, int VHML_M, T Number);
template <class T> void HML_MatrixPlusMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M);
template <class T> void HML_MatrixPlusMatrix(T **VHML_ResultMatrix, T **b, int VHML_N, int VHML_M);
template <class T> void HML_MatrixT(T **a, T **VHML_ResultMatrix, int VHML_N, int VHML_M);
template <class T> void HML_MatrixTMultiplyMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S);
template <class T> void HML_MatrixToCol(T **a, T *VHML_ResultVector, int VHML_N, int k);
template <class T> void HML_MatrixToMatrix(T **a, T **VHML_ResultMatrix, int VHML_N, int VHML_M);
template <class T> void HML_MatrixToRow(T **a, T *VHML_ResultVector, int k, int VHML_M);
template <class T> T HML_MaximumOfMatrix(T **a, int VHML_N, int VHML_M);
template <class T> T HML_MinimumOfMatrix(T **a, int VHML_N, int VHML_M);
template <class T> void HML_MixingRowsInOrder(T **VHML_ResultMatrix, int *b, int VHML_N, int VHML_M);
template <class T> int HML_NumberOfDifferentValuesInMatrix(T **a, int VHML_N, int VHML_M);
template <class T> void HML_MatrixToRow(T **a, T *VHML_ResultVector, int k, int VHML_M);
template <class T> void HML_RowToMatrix(T **VHML_ResultMatrix, T *b, int k, int VHML_M);
template <class T> T HML_SumMatrix(T **a,int VHML_N,int VHML_M);
template <class T> void HML_ZeroMatrix(T **VHML_ResultMatrix,int VHML_N,int VHML_M);

//Метрика
template <class T> T HML_Chebychev(T *x, T *y, int VHML_N);
template <class T> T HML_CityBlock(T *x, T *y, int VHML_N);
template <class T> T HML_Euclid(T *x, T *y, int VHML_N);
template <class T> T HML_Minkovski(T *x, T *y, int r, int VHML_N);

//Модели
int HML_PendulumOfMaxwell(double *Data);

//Непараметрика
double HML_BellShapedKernelExp(double z);
double HML_BellShapedKernelParabola(double z);
double HML_BellShapedKernelRectangle(double z);
double HML_BellShapedKernelTriangle(double z);
double HML_DerivativeOfBellShapedKernelExp(double z);
double HML_DerivativeOfBellShapedKernelParabola(double z);
double HML_DerivativeOfBellShapedKernelRectangle(double z);
double HML_DerivativeOfBellShapedKernelTriangle(double z);
void HML_MakingVectorForNonparametricEstimatorOfDerivative3(double *VHML_ResultVector, double *X, double *Y, int VHML_N, double C, int V);
void HML_MakingVectorForNonparametricEstimatorOfDerivative6(double *VHML_ResultVector, double *X, double *Y, int VHML_N, double C, int V);
double HML_NonparametricEstimatorOfDerivative(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative(double x, double *X, double *Y, int VHML_N, double C, int V);
double HML_NonparametricEstimatorOfDerivative2(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative2(double x, double *X, double *Y, int VHML_N, double C, int V);
double HML_NonparametricEstimatorOfDerivative3(double x, double *X, double *dY, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative3(double x, double *X, double *dY, int VHML_N, double C, int V);
double HML_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative4(double x, double *X, double *Y, int VHML_N, double C, int V);
double HML_NonparametricEstimatorOfDerivative5(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative5(double x, double *X, double *Y, int VHML_N, double C, int V);
double HML_NonparametricEstimatorOfDerivative6(double x, double *X, double *dY, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfDerivative6(double x, double *X, double *dY, int VHML_N, double C, int V);
double HML_NonparametricEstimatorOfRegression(double x, double *X, double *Y, int VHML_N, double C, int V, bool *b);
double HML_NonparametricEstimatorOfRegression(double x, double *X, double *Y, int VHML_N, double C, int V);

//Нечеткие системы
double HML_CentroidOfTrapeziformFuzzyNumber(double a,double b,double c,double d);
double HML_MaxiMinTrapeziformFuzzyNumbers (double *Data);
double HML_TrapeziformFuzzyNumber(double x,double a,double b,double c,double d);
double HML_TrapeziformTruncatedFuzzyNumber(double x, double a, double b, double c, double d, double m);

//Оптимизация
int HML_BinaryMonteCarloAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
void HML_DichotomyOptimization (double Left, double Right, double (*Function)(double), double Interval, double Epsilon, double *VHML_Result_X,double *VHML_Result_Y);
void HML_FibonacciOptimization (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y);
void HML_GoldenSectionOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VHML_Result_X,double *VHML_Result_Y);
void HML_QuadraticFitOptimization (double Left, double Right, double (*Function)(double), double Epsilon, double Epsilon2, double *VHML_Result_X,double *VHML_Result_Y);
int HML_RealMonteCarloAlgorithm(int *Parameters, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
void HML_RealMonteCarloOptimization (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y);
void HML_UniformSearchOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VHML_Result_X,double *VHML_Result_Y);
void HML_UniformSearchOptimizationN (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y);

//Оптимизация - свалка алгоритмов
int HML_BinaryGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
int HML_BinaryGeneticAlgorithmTwiceGenerations(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
int HML_BinaryGeneticAlgorithmWCC(int *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
int HML_BinaryGeneticAlgorithmWDPOfNOfGPS(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
int HML_BinaryGeneticAlgorithmWDTS(double *Parameters, double (*FitnessFunction)(int*,int), int *VHML_ResultVector, double *VHML_Result);
int HML_RealGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
int HML_RealGeneticAlgorithmTwiceGenerations(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
int HML_RealGeneticAlgorithmWCC(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
int HML_RealGeneticAlgorithmWDPOfNOfGPS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);
int HML_RealGeneticAlgorithmWDTS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VHML_ResultVector, double *VHML_Result);

//Перевод единиц измерений
double HML_DegToRad(double VHML_X);
double HML_RadToDeg(double VHML_X);

//Случайные объекты
template <class T> void HML_BernulliVector(T *VHML_ResultVector, int VHML_N);
int HML_BitNumber(double P);
int HML_BitNumber();
template <class T> void HML_RandomArrangingObjectsIntoBaskets(T *VHML_ResultVector, int N, int VHML_N);
template <class T> void HML_RandomBinaryMatrix(T **VHML_ResultMatrix,int VHML_N,int VHML_M);
template <class T> void HML_RandomBinaryVector(T *VHML_ResultVector,int VHML_N);
template <class T> void HML_RandomIntMatrix(T **VHML_ResultMatrix, T n, T m, int VHML_N, int VHML_M);
template <class T> void HML_RandomIntMatrixInCols(T **VHML_ResultMatrix, T *n, T *m, int VHML_N, int VHML_M);
template <class T> void HML_RandomIntMatrixInElements(T **VHML_ResultMatrix, T **n, T **m, int VHML_N, int VHML_M);
template <class T> void HML_RandomIntMatrixInRows(T **VHML_ResultMatrix, T *n, T *m, int VHML_N, int VHML_M);
template <class T> void HML_RandomIntVector(T *VHML_ResultVector, T n, T m, int VHML_N);
template <class T> void HML_RandomIntVectorInElements(T *VHML_ResultVector, T *n, T *m, int VHML_N);
template <class T> void HML_RandomMatrixOfPermutation(T **VHML_ResultMatrix, int VHML_N, int VHML_M);
void HML_RandomRealMatrix(double **VHML_ResultMatrix, double Left, double Right, int VHML_N, int VHML_M);
void HML_RandomRealMatrixInCols(double **VHML_ResultMatrix, double *Left, double *Right, int VHML_N, int VHML_M);
void HML_RandomRealMatrixInElements(double **VHML_ResultMatrix, double **Left, double **Right, int VHML_N, int VHML_M);
void HML_RandomRealMatrixInRows(double **VHML_ResultMatrix, double *Left, double *Right, int VHML_N, int VHML_M);
void HML_RandomRealVector(double *VHML_ResultVector, double Left, double Right, int VHML_N);
void HML_RandomRealVectorInElements(double *VHML_ResultVector, double *Left, double *Right, int VHML_N);
template <class T> void HML_RandomVectorOfPermutation(T *VHML_ResultVector, int VHML_N);
void HML_RandomVectorOfProbability(double *VHML_ResultVector, int VHML_N);

//Случайные числа
double HML_RandomNormal(double Mean, double StdDev);
double HML_RandomUniform(double a, double b);
int HML_RandomUniformInt(int n, int m);
int HML_RandomUniformIntIncluding(int n, int m);

//Сортировка
template <class T> void HML_BubbleDescendingSort(T *VHML_ResultVector, int VHML_N);
template <class T> void HML_BubbleSort(T *VHML_ResultVector, int VHML_N);
template <class T> void HML_BubbleSortColWithOtherConjugateColsInMatrix(T **VHML_ResultMatrix,int Col, int VHML_N, int VHML_M);
template <class T> void HML_BubbleSortEveryColInMatrix(T **VHML_ResultMatrix,int VHML_N, int VHML_M);
template <class T> void HML_BubbleSortEveryRowInMatrix(T **VHML_ResultMatrix,int VHML_N, int VHML_M);
template <class T> void HML_BubbleSortInGroups(T *VHML_ResultVector, int VHML_N, int m);
template <class T> void HML_BubbleSortRowWithOtherConjugateRowsInMatrix(T **VHML_ResultMatrix,int Row, int VHML_N, int VHML_M);
template <class T, class T2> void HML_BubbleSortWithConjugateVector(T *VHML_ResultVector, T2 *VHML_ResultVector2, int VHML_N);
template <class T, class T2, class T3> void HML_BubbleSortWithTwoConjugateVectors(T *VHML_ResultVector, T2 *VHML_ResultVector2, T3 *VHML_ResultVector3, int VHML_N);

//Статистика и теория вероятности
double HML_DensityOfDistributionOfNormalizedCenteredNormalDistribution(double x);
double HML_DistributionFunctionOfNormalDistribution(double x, double mu, double sigma, double Epsilon);
double HML_DistributionFunctionOfNormalizedCenteredNormalDistribution(double x, double Epsilon);
double HML_LeftBorderOfWilcoxonWFromTable(int m, int n, double Q);
template <class T> T HML_Mean(T *x, int VHML_N);
template <class T> T HML_MeanOfFilter(T *x, int VHML_N, T UpperFilter, T LowerFilter);
template <class T> T HML_MeanOfLowerFilter(T *x, int VHML_N, T LowerFilter);
template <class T> T HML_MeanOfUpperFilter(T *x, int VHML_N, T UpperFilter);
template <class T> T HML_Median(T *x, int VHML_N);
double HML_RightBorderOfWilcoxonWFromTable(int m, int n, double Q);
template <class T> T HML_SampleCovariance(T *x, T *y, int VHML_N);
double HML_StdDevToVariance(double StdDev);
template <class T> T HML_UncorrectedVariance(T *x, int VHML_N);
template <class T> T HML_Variance(T *x, int VHML_N);
double HML_VarianceToStdDev(double Variance);
int HML_WilcoxonW(double *a, double *b, int VHML_N1, int VHML_N2, double Q);
int HML_WilcoxonW(double *a, double *b, int VHML_N1, int VHML_N2, double Q, double *Lr, double *Rr, double *Wr);

//Тестовые функции для оптимизации
double HML_TestFunction_Ackley(double *x, int VHML_N);
double HML_TestFunction_AdditivePotential(double x, double y);
double HML_TestFunction_Bosom(double x, double y);
double HML_TestFunction_EggHolder(double x, double y);
double HML_TestFunction_GaussianQuartic(double *x, int VHML_N);
double HML_TestFunction_Griewangk(double *x, int VHML_N);
double HML_TestFunction_Himmelblau(double x, double y);
double HML_TestFunction_HyperEllipsoid(double *x, int VHML_N);
double HML_TestFunction_InvertedRosenbrock(double x, double y);
double HML_TestFunction_Katnikov(double x, double y);
double HML_TestFunction_Multiextremal(double x);
double HML_TestFunction_Multiextremal2(double x);
double HML_TestFunction_Multiextremal3(double x, double y);
double HML_TestFunction_Multiextremal4(double x, double y);
double HML_TestFunction_MultiplicativePotential(double x, double y);
double HML_TestFunction_ParaboloidOfRevolution(double *x, int VHML_N);
double HML_TestFunction_Rana(double x, double y);
double HML_TestFunction_Rastrigin(double *x, int VHML_N);
double HML_TestFunction_RastriginNovgorod(double *x, int VHML_N);
double HML_TestFunction_RastriginWithChange(double x, double y);
double HML_TestFunction_RastriginWithTurning(double x, double y);
double HML_TestFunction_ReverseGriewank(double x, double y);
double HML_TestFunction_Rosenbrock(double *x, int VHML_N);
double HML_TestFunction_RotatedHyperEllipsoid(double *x, int VHML_N);
double HML_TestFunction_Schwefel(double *x, int VHML_N);
double HML_TestFunction_ShekelsFoxholes(double x, double y);
double HML_TestFunction_Sombrero(double x, double y);
double HML_TestFunction_StepFunction(double *x, int VHML_N);
double HML_TestFunction_SumVector(int *x, int VHML_N);
double HML_TestFunction_Wave(double x);

//Тригонометрические функции
double HML_Cos(double x);
double HML_CosDeg(double x);
double HML_Cosec(double x);
double HML_CosecDeg(double x);
double HML_Cotan(double x);
double HML_CotanDeg(double x);
double HML_Sec(double x);
double HML_SecDeg(double x);
double HML_Sin(double x);
double HML_SinDeg(double x);
double HML_Tan(double x);
double HML_TanDeg(double x);

//Уравнения
int HML_QuadraticEquation(double a, double b, double c, double *x1, double *x2);
int HML_QuadraticEquationCount(double a, double b, double c, double *x1, double *x2);

//Физика
double HML_NewtonSecondLawAcceleration(double F, double m);
double HML_NewtonSecondLawForce(double a, double m);

//Цвет
int HML_AddColorB(int R, int G, int B, double p);
int HML_AddColorG(int R, int G, int B, double p);
int HML_AddColorR(int R, int G, int B, double p);
int HML_AlphaBlendingColorToColorB(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
int HML_AlphaBlendingColorToColorG(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
int HML_AlphaBlendingColorToColorR(double alpha, int R1, int G1, int B1, int R2, int G2, int B2);
int HML_ColorFromGradientB(double position, int R1, int G1, int B1, int R2, int G2, int B2);
int HML_ColorFromGradientG(double position, int R1, int G1, int B1, int R2, int G2, int B2);
int HML_ColorFromGradientR(double position, int R1, int G1, int B1, int R2, int G2, int B2);
int HML_DivideColorB(int R, int G, int B, double p);
int HML_DivideColorG(int R, int G, int B, double p);
int HML_DivideColorR(int R, int G, int B, double p);
int HML_GiveRainbowColorB(double position);
int HML_GiveRainbowColorG(double position);
int HML_GiveRainbowColorR(double position);
int HML_GreyscaleB(int R, int G, int B);
int HML_GreyscaleG(int R, int G, int B);
int HML_GreyscaleR(int R, int G, int B);
int HML_MultiplyColorB(int R, int G, int B, double p);
int HML_MultiplyColorG(int R, int G, int B, double p);
int HML_MultiplyColorR(int R, int G, int B, double p);
int HML_NegativeColorB(int R, int G, int B);
int HML_NegativeColorG(int R, int G, int B);
int HML_NegativeColorR(int R, int G, int B);
int HML_SubtractColorB(int R, int G, int B, double p);
int HML_SubtractColorG(int R, int G, int B, double p);
int HML_SubtractColorR(int R, int G, int B, double p);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Вектора (Одномерные массивы)
//*****************************************************************
template <class T> void HML_AcceptanceLimits(T *VHML_ResultVector, T *Left, T *Right, int VHML_N)
{
/*
Функция вмещает вектор VHML_ResultVector в прямоугольную многомерной области,
определяемой левыми границами и правыми границами. Если какая-то координата
вектора выходит за границу, то значение этой координаты принимает граничное значение.
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - вектор левых границ;
 Right - вектор правых границ;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 {
 if (VHML_ResultVector[i]<Left[i]) VHML_ResultVector[i]=Left[i];//принятие граничного левого условия
 if (VHML_ResultVector[i]>Right[i]) VHML_ResultVector[i]=Right[i];//принятие граничного правого условия
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_AcceptanceLimits(T *VHML_ResultVector, T Left, T Right, int VHML_N)
{
/*
Функция вмещает вектор VHML_ResultVector в прямоугольную многомерной области,
определяемой левыми границами и правыми границами. Если какая-то координата
вектора выходит за границу, то значение этой координаты принимает граничное значение.
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - левая граница;
 Right - правая граница;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 {
 if (VHML_ResultVector[i]<Left) VHML_ResultVector[i]=Left;//принятие граничного левого условия
 if (VHML_ResultVector[i]>Right) VHML_ResultVector[i]=Right;//принятие граничного правого условия
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_AcceptanceLimitsLeft(T *VHML_ResultVector, T *Left, int VHML_N)
{
/*
Если значения вектора VHML_ResultVector[i] слева выходят за Left[i], то она ограничивается Left[i].
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - вектор левых границ;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VHML_N;i++)
    {
        if (VHML_ResultVector[i]<Left[i]) VHML_ResultVector[i]=Left[i];//принятие граничного левого условия
    }
}
//---------------------------------------------------------------------------
template <class T> void HML_AcceptanceLimitsLeft(T *VHML_ResultVector, T Left, int VHML_N)
{
/*
Если значения вектора VHML_ResultVector[i] слева выходят за Left, то она ограничивается Left.
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - левая граница;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VHML_N;i++)
    {
        if (VHML_ResultVector[i]<Left) VHML_ResultVector[i]=Left;//принятие граничного левого условия
    }
}
//---------------------------------------------------------------------------
template <class T> void HML_AcceptanceLimitsRight(T *VHML_ResultVector, T *Right, int VHML_N)
{
/*
Если значения вектора VHML_ResultVector[i] справа выходят за Right[i], то она ограничивается Right[i].
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Right - вектор правых границ;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VHML_N;i++)
    {
        if (VHML_ResultVector[i]>Right[i]) VHML_ResultVector[i]=Right[i];//принятие граничного правого условия
    }
}
//---------------------------------------------------------------------------
template <class T> void HML_AcceptanceLimitsRight(T *VHML_ResultVector, T Right, int VHML_N)
{
/*
Если значения вектора VHML_ResultVector[i] справа выходят за Right, то она ограничивается Right.
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Right - правая граница;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VHML_N;i++)
    {
        if (VHML_ResultVector[i]>Right) VHML_ResultVector[i]=Right;//принятие граничного правого условия
    }
}
//---------------------------------------------------------------------------
template <class T> void HML_ChangeOrderInVector(T *VHML_Vector, T *VHML_ResultVector, int *Order, int VHML_N)
{
/*
Функция меняет порядок элементов в массиве VHML_Vector и сохраняет в другой VHML_ResultVector согласно массиву
Order, в котором записан новый порядок элементов.
Входные параметры:
 VHML_Vector - указатель на массив;
 VHML_ResultVector - указатель на массив, куда сохраняем данные;
 Order - указатель на массив, в котором хранится порядок элементов;
 VHML_N - количество элементов в массиве.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=VHML_Vector[Order[i]];
}
//---------------------------------------------------------------------------
template <class T> void HML_ChangeOrderInVector(T *VHML_Vector, int *Order, int VHML_N)
{
/*
Функция меняет порядок элементов в массиве VHML_Vector согласно массиву
Order, в котором записан новый порядок элементов.
Входные параметры:
 VHML_Vector - указатель на массив;
 Order - указатель на массив, в котором хранится порядок элементов;
 VHML_N - количество элементов в массиве.
Возвращаемое значение:
 Отсутствует.
*/
T *TempVector;
TempVector = new T [VHML_N];
HML_VectorToVector(VHML_Vector,TempVector,VHML_N);
for (int i=0;i<VHML_N;i++)
    VHML_Vector[i]=TempVector[Order[i]];
delete [] TempVector;
}
//---------------------------------------------------------------------------
template <class T> int HML_CheckElementInVector(T *x, int VHML_N, T a)
{
/*
Функция проверяет наличие элемента а в векторе x.
Входные параметры:
 x - указатель на вектор;
 VHML_N - размер массива;
 a - проверяемый элемент.
Возвращаемое значение:
 Номер (начиная с нуля) первого элемента, равного искомому. Если такого элемента нет, то возвращается -1.
*/
int VHML_Result=-1;
int i=0;
while ((i<VHML_N)&&(VHML_Result==-1))
 {
 if (x[i]==a) VHML_Result=i;//нашли
 i++;
 }
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_CompareMeanOfVectors(T *a, T *b, int VHML_N)
{
    /*
Функция проверяет, какой вектор по среднему арифметическому больше.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_N - размер векторов.
Возвращаемое значение:
 0 - вектора совпадают или совпадает среднее арифметическое;
 1 - первый вектор имеет большее значение арифметического среднего;
 2 - второй вектор имеет большее значение арифметического среднего.
Примечание:
 Данную функцию удобно использовать вкупе с функцией HML_WilcoxonW.
*/
    int VHML_Result=0;
    for (int i=0;i<VHML_N;i++)
        if (a[i]!=b[i]) VHML_Result=-1;

    if (VHML_Result==-1)
    {
        double Ma=HML_SumVector(a,VHML_N)/double(VHML_N);
        double Mb=HML_SumVector(b,VHML_N)/double(VHML_N);

        if (Ma>Mb)
            VHML_Result=1;
        else
            VHML_Result=2;
		if (Ma==Mb) VHML_Result=0;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_CompareMeanOfVectors(T *a, T *b, int VHML_N1, int VHML_N2)
{
    /*
Функция проверяет, какой вектор по среднему арифметическому больше.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_N1 - размер вектора a;
 VHML_N2 - размер вектора b.
Возвращаемое значение:
 0 - вектора совпадают или совпадает среднее арифметическое;
 1 - первый вектор имеет большее значение арифметического среднего;
 2 - второй вектор имеет большее значение арифметического среднего.
Примечание:
 Данную функцию удобно использовать вкупе с функцией HML_WilcoxonW.
*/
    int VHML_Result=0;
    if (VHML_N1==VHML_N2)
        for (int i=0;i<VHML_N1;i++)
            if (a[i]!=b[i]) VHML_Result=-1;
            else
                VHML_Result=-1;

    if (VHML_Result==-1)
    {
        double Ma=HML_SumVector(a,VHML_N1)/double(VHML_N1);
        double Mb=HML_SumVector(b,VHML_N2)/double(VHML_N2);

        if (Ma>Mb)
            VHML_Result=1;
        else
            VHML_Result=2;
		if (Ma==Mb) VHML_Result=0;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> bool HML_EqualityOfVectors(T *a, T *b, int VHML_N)
{
/*
Функция проверяет равенство векторов.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_N - размер векторов.
Возвращаемое значение:
 true - вектора совпадают;
 false - вектора не совпадают.
*/
bool VHML_Result=true;
for (int i=0;i<VHML_N;i++)
 if (a[i]!=b[i]) VHML_Result=false;

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_FibonacciNumbersVector(T *VHML_ResultVector, int VHML_N)
{
/*
Функция заполняет массив числами Фибоначчи.
Входные параметры:
 VHML_ResultVector - указатель на массив, в который записывается результат;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
if (VHML_N>=1) VHML_ResultVector[0]=1;
if (VHML_N>=2) VHML_ResultVector[1]=1;
if (VHML_N>2)
 {
 for (int i=2;i<VHML_N;i++)
  VHML_ResultVector[i]=VHML_ResultVector[i-1]+VHML_ResultVector[i-2];
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_FillVector(T *VHML_ResultVector, int VHML_N, T x)
{
/*
Функция заполняет вектор значениями, равных x.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый массив;
 VHML_N - количество элементов в массиве;
 x - число, которым заполняется вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=x;
}
//---------------------------------------------------------------------------
template <class T> T HML_MaximumOfVector(T *VHML_Vector, int VHML_N)
{
/*
Функция ищет максимальный элемент в векторе (одномерном массиве).
Входные параметры:
 VHML_Vector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Максимальный элемент.
*/
T VHML_Result;
VHML_Result=VHML_Vector[0];
for (int i=1;i<VHML_N;i++)
    if (VHML_Vector[i]>VHML_Result)
        VHML_Result=VHML_Vector[i];

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_MinimumOfVector(T *VHML_Vector, int VHML_N)
{
/*
Функция ищет минимальный элемент в векторе (одномерном массиве).
Входные параметры:
 VHML_Vector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Минимальный элемент.
*/
T VHML_Result;
VHML_Result=VHML_Vector[0];
for (int i=1;i<VHML_N;i++)
    if (VHML_Vector[i]<VHML_Result)
        VHML_Result=VHML_Vector[i];

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_MixingVector(T *VHML_ResultVector, double P, int VHML_N)
{
/*
Функция перемешивает массив. Поочередно рассматриваются номера элементов массивов.
С некоторой вероятностью рассматриваемый элемент массива меняется местами со
случайным элементом массива.
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 P - вероятность того, что элемент массива под рассматриваемым номером поменяется
 местами с каким-нибудь другим элементов (не включая самого себя);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VHML_N;i++)
 {
 if (HML_RandomNumber()<=P)
  {
  j=HML_RandomUniformInt(0,VHML_N-1);
  if (j>=i) j++;
  HML_NumberInterchange (&VHML_ResultVector[i],&VHML_ResultVector[j]); //меняем местами элементы массива
  }
 }
}
//---------------------------------------------------------------------------
template <class T, class T2> void HML_MixingVectorWithConjugateVector(T *VHML_ResultVector, T2 *VHML_ResultVector2, double P, int VHML_N)
{
/*
Функция перемешивает массив вместе со сопряженным массивом. Поочередно
рассматриваются номера элементов массивов. С некоторой вероятностью
рассматриваемый элемент массива меняется местами со случайным элементом массива.
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_ResultVector2 - указатель на сопряженный массив;
 P - вероятность того, что элемент массива под рассматриваемым номером поменяется
 местами с каким-нибудь другим элементов (не включая самого себя);
 VHML_N - количество элементов в массивах.
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VHML_N;i++)
 {
 if (HML_RandomNumber()<P)
  {
  j=HML_RandomUniformInt(0,VHML_N-1);
  if (j>=i) j++;
  HML_NumberInterchange (&VHML_ResultVector[i],&VHML_ResultVector[j]);//меняем местами элементы массива
  HML_NumberInterchange (&VHML_ResultVector2[i],&VHML_ResultVector2[j]);//меняем местами элементы сопряженного массива
  }
 }
}
//---------------------------------------------------------------------------
template <class T> int HML_NumberOfDifferentValuesInVector(T *a, int VHML_N)
{
/*
Функция подсчитывает число различных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор;
 VHML_N - размер массива a.
Возвращаемое значение:
 Число различных значений в векторе.
Примечание:
 Алгоритм очень топорный и медленный.
*/
T *b;
b=new T[VHML_N];
int VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 if (HML_CheckElementInVector(b,VHML_Result,a[i])==-1)
  {
  b[VHML_Result]=a[i];
  VHML_Result++;
  }
delete [] b;
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_NumberOfMaximumOfVector(T *a, int VHML_N)
{
/*
Функция ищет номер максимального элемента в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Номер максимального элемента.
*/
T Max;
Max=a[0];
int VHML_Result=0;
for (int i=1;i<VHML_N;i++)
 if (a[i]>Max)
  {
  Max=a[i];
  VHML_Result=i;
  }
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_NumberOfMinimumOfVector(T *a, int VHML_N)
{
/*
Функция ищет номер минимального элемента в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Номер минимального элемента.
*/
T Min;
Min=a[0];
int VHML_Result=0;
for (int i=1;i<VHML_N;i++)
 if (a[i]<Min)
  {
  Min=a[i];
  VHML_Result=i;
  }
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_NumberOfNegativeValues(T *a, int VHML_N)
{
/*
Функция подсчитывает число отрицательных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на исходный массив;
 VHML_N - количество элементов в массиве.
Выходной параметр:
 Число отрицательных значений в массиве.
*/
int VHML_Result=0;
for (int i=0;i<VHML_N;i++)
	if (a[i]<0)
		VHML_Result++;
		
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_NumberOfPositiveValues(T *a, int VHML_N)
{
/*
Функция подсчитывает число положительных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на исходный массив;
 VHML_N - количество элементов в массиве.
Выходной параметр:
 Число положительных значений в массиве.
*/
int VHML_Result=0;
for (int i=0;i<VHML_N;i++)
    if (a[i]>0)
        VHML_Result++;

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_NumberOfZeroValues(T *a, int VHML_N)
{
/*
Функция подсчитывает число нулевых значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на исходный массив;
 VHML_N - количество элементов в массиве.
Выходной параметр:
 Число нулевых значений в массиве.
*/
int VHML_Result=0;
for (int i=0;i<VHML_N;i++)
    if (a[i]==0)
        VHML_Result++;

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_OrdinalVector(T *VHML_ResultVector, int VHML_N)
{
/*
Функция заполняет вектор значениями, равные номеру элемента, начиная с единицы.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив), который и заполняется;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=i+1;
}
//---------------------------------------------------------------------------
template <class T> void HML_OrdinalVectorZero(T *VHML_ResultVector, int VHML_N)
{
/*
Функция заполняет вектор значениями, равные номеру элемента, начиная с нуля.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив), который и заполняется;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) 
    VHML_ResultVector[i]=i;
}
//---------------------------------------------------------------------------
template <class T> T HML_ProductOfElementsOfVector(T *VHML_Vector,int VHML_N)
{
/*
Функция вычисляет произведение элементов вектора.
Входные параметры:
 VHML_Vector - указатель на исходный массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Произведение элементов массива.
*/
T VHML_Result=1;
for (int i=0;i<VHML_N;i++)
    VHML_Result*=VHML_Vector[i];

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_ReverseVector(T *VHML_ResultVector, int VHML_N)
{
/*
Функция меняет порядок элементов в массиве на обратный. Преобразуется подаваемый массив.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N/2;i++)
 HML_NumberInterchange(&(VHML_ResultVector[i]),&(VHML_ResultVector[VHML_N-i-1]));
}
//---------------------------------------------------------------------------
template <class T> int HML_SearchElementInVector (T *X, T x, int VHML_N)
/*
Функция находит номер первого элемента в массиве, равного данному.
Входные параметры:
 X - исходный массив;
 x - данный элемент;
 VHML_N - размер массива.
Возвращаемое значение:
 Номер элемента.
Примечание:
 Если такого элемента нет, то возвращает -1.
*/
{
int i=0;

while (i<VHML_N)
	{
	if (X[i]==x) return (i);//нашли элемент
	i++;
	}
	
return -1;//не нашли
}
//---------------------------------------------------------------------------
template <class T> int HML_SearchFirstNotZero(T *x, int VHML_N)
{
/*
Функция возвращает номер первого ненулевого элемента массива.
Входные параметры:
 x - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Номер первого ненулевого элемента массива (начиная с нуля). Если такого элемента нет, то возвращается -1.
*/
int VHML_Result=-1;
int i=0;
while ((i<VHML_N)&&(VHML_Result==-1))
 {
 if (x[i]!=0)
  VHML_Result=i;//нашли
 i++;
 }
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_SearchFirstZero(T *x, int VHML_N)
{
/*
Функция возвращает номер первого нулевого элемента массива.
Входные параметры:
 x - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Номер первого нулевого элемента массива (начиная с нуля). Если такого элемента нет, то возвращается -1.
*/
int VHML_Result=-1;
int i=0;
while ((i<VHML_N)&&(VHML_Result==-1))
 {
 if (x[i]==0)
  VHML_Result=i;//нашли
 i++;
 }
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_ShiftLeftVector(T *VHML_Vector, int VHML_N)
{
/*
Функция сдвигает циклически в векторе (одномерном массиве) все элементы влево на один элемент.
Входные параметры:
 VHML_Vector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T Temp;
Temp=VHML_Vector[0];

for (int i=0;i<VHML_N-1;i++)
    VHML_Vector[i] = VHML_Vector[i+1];

VHML_Vector[VHML_N-1] = Temp;
}
//---------------------------------------------------------------------------
template <class T> void HML_ShiftRightVector(T *VHML_Vector, int VHML_N)
{
/*
Функция сдвигает циклически в векторе (одномерном массиве) все элементы вправо на один элемент.
Входные параметры:
 VHML_Vector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T Temp;
Temp=VHML_Vector[VHML_N-1];

for (int i=VHML_N-1;i>0;i--)
    VHML_Vector[i] = VHML_Vector[i-1];

VHML_Vector[0] = Temp;
}
//---------------------------------------------------------------------------
template <class T> T HML_SumSquareVector(T *VHML_Vector,int VHML_N)
{
/*
Функция вычисляет сумму квадратов элементов вектора.
Входные параметры:
 VHML_Vector - указатель на исходный массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Сумма элементов массива.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
    VHML_Result+=VHML_Vector[i]*VHML_Vector[i];

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_SumVector(T *VHML_Vector,int VHML_N)
{
/*
Функция вычисляет сумму элементов вектора.
Входные параметры:
 VHML_Vector - указатель на исходный массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Сумма элементов массива.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
    VHML_Result+=VHML_Vector[i];

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_VectorMinusVector(T *a, T *b, T *VHML_ResultVector, int VHML_N)
{
/*
Функция вычитает поэлементно из одного массива другой и записывает результат в третий массив.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_ResultVector - вектор разности;
 VHML_N - размер векторов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=a[i]-b[i];
}
//---------------------------------------------------------------------------
template <class T> void HML_VectorMinusVector(T *VHML_ResultVector, T *b, int VHML_N)
{
/*
Функция вычитает поэлементно из одного массива другой и записывает результат в первый массив.
Входные параметры:
 VHML_ResultVector - первый вектор, из которого вычитают второй вектор;
 b - вторый вектор;
 VHML_N - размер векторов.
Возвращаемое значение:
 Отсутствует
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]-=b[i];
}
//---------------------------------------------------------------------------
template <class T> void HML_VectorMultiplyNumber(T *VHML_ResultVector, int VHML_N, T Number)
{
/*
Функция умножает вектор на число.
Входные параметры:
 VHML_ResultVector - вектор (в нем и сохраняется результат);
 VHML_N - размер вектора;
 Number - число, на которое умножается вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) 
   VHML_ResultVector[i]*=Number;
}
//---------------------------------------------------------------------------
template <class T> void HML_VectorPlusVector(T *a, T *b, T *VHML_ResultVector, int VHML_N)
{
/*
Функция складывает поэлементно из одного массива другой и записывает результат в третий массив.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_ResultVector - вектор разности;
 VHML_N - размер векторов.
Возвращаемое значение:
 Отсутствует
*/
for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=a[i]+b[i];
}
//---------------------------------------------------------------------------
template <class T> void HML_VectorPlusVector(T *VHML_ResultVector, T *b, int VHML_N)
{
/*
Функция складывает поэлементно из одного массива другой и записывает результат в первый массив.
Входные параметры:
 VHML_ResultVector - первый вектор, к которому прибавляют второй вектор;
 b - вторый вектор;
 VHML_N - размер векторов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]+=b[i];
}
//---------------------------------------------------------------------------
template <class T> void HML_VectorToVector(T *VHML_Vector, T *VHML_ResultVector, int VHML_N)
{
/*
Функция копирует содержимое вектора (одномерного массива) VHML_Vector в массив VHML_ResultVector.
Входные параметры:
 VHML_Vector - указатель на исходный массив;
 VHML_ResultVector - указатель на массив в который производится запись;
 VHML_N - размер массивов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=VHML_Vector[i];
}
//---------------------------------------------------------------------------
template <class T> void HML_ZeroVector(T *VHML_ResultVector,int VHML_N)
{
/*
Функция зануляет массив.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=0;
}
//---------------------------------------------------------------------------
//*****************************************************************
//Генетические алгоритмы
//*****************************************************************
template <class T> void HML_MutationBinaryMatrix(T **VHML_ResultMatrix, double ProbabilityOfMutation, int VHML_N,int VHML_M)
{
/*
Мутация для бинарной матрицы. Оператор генетического алгоритма.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 ProbabilityOfMutation - вероятность мутации;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
if (ProbabilityOfMutation>1) ProbabilityOfMutation=1;
if (ProbabilityOfMutation<0) ProbabilityOfMutation=0;

for(int i=0;i<VHML_N;i++)
 for(int j=0;j<VHML_M;j++)
 if (HML_RandomNumber()<ProbabilityOfMutation)
  {
  //Инвертируем ген
  if (VHML_ResultMatrix[i][j]==0) VHML_ResultMatrix[i][j]=1; else VHML_ResultMatrix[i][j]=0;
  }
}
//---------------------------------------------------------------------------
template <class T> void HML_MutationBinaryVector(T *VHML_ResultVector, double ProbabilityOfMutation, int VHML_N)
{
/*
Мутация для бинарного вектора. Оператор генетического алгоритма.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый вектор;
 ProbabilityOfMutation - вероятность мутации;
 VHML_N - размер массива VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
    ProbabilityOfMutation = HML_AcceptanceLimitsNumber(ProbabilityOfMutation,0.,1.);

    for(int i=0;i<VHML_N;i++)
        if (HML_RandomNumber()<ProbabilityOfMutation)
        {
            //Инвертируем ген
            if (VHML_ResultVector[i]==0) VHML_ResultVector[i]=1; else VHML_ResultVector[i]=0;
        }
}
//---------------------------------------------------------------------------
template <class T> void HML_SinglepointCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N)
{
/*
Одноточечное скрещивание. Оператор генетического алгоритма.
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
int k=HML_RandomUniformInt(0,2);//0 или 1
int point=HML_RandomUniformInt(1,VHML_N);//точка разрыва хромосомы
if (k==0)//какой потомок "выживет": первый вариант или второй
 {
 for (i=0;i<point;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point;i<VHML_N;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
else
 {
 for (i=0;i<point;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point;i<VHML_N;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_SinglepointCrossoverWithCopying(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N)
{
/*
Одноточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного одноточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.
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
int k=HML_RandomUniformInt(0,2);//0 или 1
int point=HML_RandomUniformInt(0,VHML_N+1);//точка разрыва хромосомы
if (k==0)//какой потомок "выживет": первый вариант или второй
 {
 for (i=0;i<point;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point;i<VHML_N;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
else
 {
 for (i=0;i<point;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point;i<VHML_N;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_TwopointCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N)
{
/*
Двухточечное скрещивание. Оператор генетического алгоритма.
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
int k=HML_RandomUniformInt(0,2);//0 или 1
//проводим скрещивание
int point1=HML_RandomUniformInt(1,VHML_N);//1 точка разрыва хромосомы
int point2=HML_RandomUniformInt(1,VHML_N);//2 точка разрыва хромосомы
//1-ая точка разрыва должна следовать за 2-ой. Поэтому, если это не так,
//то переставляем точки местами функцией HML_NumberInterchangeInt
if (point2<point1) HML_NumberInterchange(&point1,&point2);
if (k==0)//какой потомок "выживет": первый вариант или второй (зависит от порядка следования родителей)
 {
 for (i=0;i<point1;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point1;i<point2;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point2;i<VHML_N;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
else
 {
 for (i=0;i<point1;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point1;i<point2;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point2;i<VHML_N;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_TwopointCrossoverWithCopying(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N)
{
/*
Двухточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного двухточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.
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
int k=HML_RandomUniformInt(0,2);//0 или 1
//проводим скрещивание
int point1=HML_RandomUniformInt(0,VHML_N+1);//1 точка разрыва хромосомы
int point2=HML_RandomUniformInt(0,VHML_N+1);//2 точка разрыва хромосомы
//1-ая точка разрыва должна следовать за 2-ой. Поэтому, если это не так,
//то переставляем точки местами функцией HML_NumberInterchangeInt
if (point2<point1) HML_NumberInterchange(&point1,&point2);
if (k==0)//какой потомок "выживет": первый вариант или второй (зависит от порядка следования родителей)
 {
 for (i=0;i<point1;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point1;i<point2;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point2;i<VHML_N;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
else
 {
 for (i=0;i<point1;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point1;i<point2;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point2;i<VHML_N;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_UniformCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N)
{
/*
Равномерное скрещивание. Оператор генетического алгоритма.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
int i;
int k;
//проводим скрещивание
for (i=0;i<VHML_N;i++)
 {
 //копируем гены из родителей по порядку с равной вероятностью
 k=HML_RandomUniformInt(0,2);
 if (k==0) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 if (k==1) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
//---------------------------------------------------------------------------
//*****************************************************************
//Геометрия
//*****************************************************************
template <class T> int HML_BoolCrossingTwoSegment(T b1,T c1,T b2,T c2)
{
/*
Функция определяет наличие пересечения двух отрезков на линии. Координаты отрезков могут быть перепутаны по порядку в каждом отрезке.
Входные параметры:
 b1 - левый конец первого отрезка;
 c1 - правый конец первого отрезка;
 b2 - левый конец второго отрезка;
 с2 - правый конец второго отрезка.
Возвращаемое значение:
 1 - отрезки пересекаются;
 0 - отрезки не пересекаются.
*/
//Запишем во временные переменные
T B1=b1,B2=b2,C1=c1,C2=c2;
if (B1>C1) HML_NumberInterchange (&B1,&C1);
if (B2>C2) HML_NumberInterchange (&B2,&C2);
if (B1>C2)
 {
 HML_NumberInterchange (&B1,&B2);
 HML_NumberInterchange (&C1,&C2);
 }
if (C1<B2)
 return 0;
else
 return 1;
}
//---------------------------------------------------------------------------
//*****************************************************************
//Гиперболические функции
//*****************************************************************
//*****************************************************************
//Дифференцирование
//*****************************************************************
//*****************************************************************
//Интегрирование
//*****************************************************************
//*****************************************************************
//Кодирование и декодирование
//*****************************************************************
template <class T> T HML_BinaryToDecimal(T *a, int VHML_N)
{
/*
Функция декодирует двоичное число в десятичное целое неотрицательное.
Входные параметры:
 a - двоичное число;
 VHML_N - длина двоичного числа.
Возвращаемое значение:
 Число в десятичной системе исчисления.
*/
T VHML_Result;
VHML_Result=HML_BinaryToDecimalFromPart(a,0,VHML_N);
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_BinaryToDecimalFromPart(T *a, int Begin, int n)
{
/*
Функция декодирует двоичное число в десятичное целое неотрицательное.
При этом двоичное число длины  берется как часть некой бинарной строки a.
Входные параметры:
 a - бинарная строка;
 Begin - номер элемента массива a как начало двоичного числа (начиная с нуля);
 n - длина двоичного числа (это не длина вектора a).
Возвращаемое значение:
 Число в десятичной системе исчисления.
*/
T VHML_Result=0;
try
 {
 int i=0;
 while (i<=n-1)
  {
  VHML_Result+=+a[i+Begin]*HML_PowerOf(2,n-i-1);
  i++;
  }
 }
catch (...)
 {
 return -1;//Возможно произошло переполнение. Вообщем, ошибка.
 }
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_GrayCodeToBinary(T *a,int *VHML_ResultVector, int VHML_N)
{
/*
Функция переводит бинарный код Грея в бинарный код.
Входные параметры:
 a - код Грея (массив заполнен 0 и 1);
 VHML_N - длина массива a.
Возвращаемое значение:
 Отсутствует.
*/
HML_GrayCodeToBinaryFromPart(a,VHML_ResultVector,0,VHML_N);
}
//---------------------------------------------------------------------------
template <class T> void HML_GrayCodeToBinaryFromPart(T *a, T *VHML_ResultVector, int Begin, int n)
{
/*
Функция переводит бинарный код Грея в бинарный код.
При этом бинарный код Грея берется как часть некой строки a, заполненной 0 и 1.
Входные параметры:
 a - строка, заполненная 0 и 1;
 VHML_ResultVector - сюда записывается вектор бинарного числа. Причем запись происходит в те же элементы по номерам, что брались из вектора a, то есть в номера элементов от Begin до Begin+n. Остальные элементы в VHML_ResultVector не трогаются.
 Begin - номер элемента массива a как начало числа в виде кода Грея (начиная с нуля);
 n - длина числа в виде кода Грея (это не длина вектора a).
Возвращаемое значение:
 Отсутствует.
*/
for (int j=0;j<n;j++)
 {
 if (j==0)
  VHML_ResultVector[j+Begin]=a[j+Begin];//Первый бит остается прежним
 else
  {
  if (VHML_ResultVector[j+Begin-1]==0)
   VHML_ResultVector[j+Begin]=a[j+Begin];//оставляем без изменения
  else
   VHML_ResultVector[j+Begin]=1-a[j+Begin];//инвертируем
  }
 }
}
//---------------------------------------------------------------------------
//*****************************************************************
//Комбинаторика
//*****************************************************************
template <class T> T HML_KCombinations(T k, T n)
{
/*
Функция возвращает число сочетаний из n по m (без возвращения).
Выходные параметры:
 k - по сколько элементов надо брать в группу;
 n - общее число элементов.
Возвращаемое значение:
 Число сочетаний из n по k.
*/
    if ((k == 0) || (n == k)) return 1;
    if (k>n)  HML_NumberInterchange(&n,&k);//n должен быть больше m

    return HML_KCombinations(k, n - 1) + HML_KCombinations(k - 1, n - 1);
}
//---------------------------------------------------------------------------
//*****************************************************************
//Математические функции
//*****************************************************************
template <class T> T HML_Abs(T x)
{
/*
Функция возвращает модуль числа.
Входные параметры:
 x - число.
Возвращаемое значение:
 Модуль числа.
*/
T VHML_Result;
T MinusOne=-1;

if (x>=0) 
	VHML_Result=x;
else 
	VHML_Result=x*MinusOne;
	
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_AcceptanceLimitsNumber(T Number, T Left, T Right)
{
/*
Функция проверяет не выходит ли число за заданные рамки [Left, Right]. Если выходит, то
принимает граничные значения.
Входные параметры:
 Number - проверяемое число;
 Left - левая граница;
 Right - правая граница.
Возвращаемое значение:
 Число в рамках.
*/
    T VHML_Result = Number;

    if (Number<Left) VHML_Result=Left;//принятие граничного левого условия
    if (Number>Right) VHML_Result=Right;//принятие граничного правого условия

    return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_AcceptanceLimitsNumberLeft(T Number, T Left)
{
/*
Функция проверяет не выходит ли число за левую рамку Left. Если выходит, то
принимает граничное значения.
Входные параметры:
 Number - проверяемое число;
 Left - левая граница.
Возвращаемое значение:
 Число в рамках.
*/
    T VHML_Result = Number;

    if (Number<Left) VHML_Result=Left;//принятие граничного левого условия

    return VHML_Result;
}

//---------------------------------------------------------------------------
template <class T> T HML_AcceptanceLimitsNumberRight(T Number, T Right)
{
/*
Функция проверяет не выходит ли число за правую рамку Right. Если выходит, то
принимает граничное значения.
Входные параметры:
 Number - проверяемое число;
 Right - правая граница.
Возвращаемое значение:
 Число в рамках.
*/
    T VHML_Result = Number;

    if (Number>Right) VHML_Result=Right;//принятие граничного правого условия

    return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> bool HML_AlmostEqual(T x, T y)
{
/*
Функция показывает, являются ли числа почти равными. Используйте с осторожностью.
Входные параметры:
 x - значение первого числа;
 y - значение второго числа.
Возвращаемое значение:
 true - являются почти равны (по модулю разница меньше или равна 0.00000001);
 false - не являются почти раными.
*/
    if (fabs(double (x-y))>0.00000001) return false;

    return true;
}
//---------------------------------------------------------------------------
template <class T> bool HML_AlmostEqual(T x, T y, double epsilon)
{
/*
Функция показывает, являются ли числа почти равными. Используйте с осторожностью.
Входные параметры:
 x - значение первого числа;
 y - значение второго числа;
 epsilon - маленькое число, относительно которого производится сравнение, например, 0.00000001.
Возвращаемое значение:
 true - являются почти равны (по модулю разница меньше или равна 0.00000001);
 false - не являются почти раными.
*/
    if (fabs(double (x-y))>epsilon) return false;

    return true;
}
//---------------------------------------------------------------------------
template <class T> bool HML_AlmostZero(T x)
{
/*
Функция показывает, является ли число почти нулем. Используется для сравнения с нулем для вещественных чисел.
Используйте с осторожностью.
Входные параметры:
 x - значение проверяемого числа.
Возвращаемое значение:
 true - является почти нулем (по модулю меньше или равно 0.00000001);
 false - не является почти нулем.
*/
    if (fabs(double (x))>0.00000001) return false;

    return true;
}
//---------------------------------------------------------------------------
template <class T> bool HML_AlmostZero(T x, double epsilon)
{
/*
Функция показывает, является ли число почти нулем. Используется для сравнения с нулем для вещественных чисел.
Используйте с осторожностью.
Входные параметры:
 x - значение проверяемого числа;
 epsilon - маленькое число, относительно которого производится сравнение, например, 0.00000001.
Возвращаемое значение:
 true - является почти нулем (по модулю меньше или равно epsilon);
 false - не является почти нулем.
*/
    if (fabs(double (x))>epsilon) return false;

    return true;
}
//---------------------------------------------------------------------------
template <class T> T HML_Factorial(T x)
{
/*
Функция вычисляет факториал числа.
Входные параметры:
 x - число.
Возвращаемое значение:
 Факториал числа.
*/
    if (x<1) x=1;
    T S=1;
    for (int i=0; i<x; i++)
        S*=i+1;

    return S;
}
//---------------------------------------------------------------------------
template <class T> T HML_FibonacciNumber(T n)
{
/*
Функция вычисляет число Фибоначчи, заданного номера.
Входные параметры:
 n - номер числа Фибоначчи.
Возвращаемое значение:
 Число Фибоначчи, заданного номера.
*/
T F1,F2,VHML_Result;

if (n==0) return 0;

if (n>=1)//иницилизация
 {
 VHML_Result=1;
 F1=1;
 }

if (n>=2) F2=1;

if (n>2)
 {
 for (int i=2;i<n;i++)
  {
  VHML_Result=F1+F2;//итерационное складывание
  F1=F2;
  F2=VHML_Result;
  }
 }

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_HeavisideFunction(T x)
{
/*
Функция Хевисайда (функция одной переменной).
Входные параметры:
 x - переменная.
Возвращаемое значение:
 Значение функции Хевисайда.
*/
if (x<0)
 return 0;
else
 return 1;
}
//---------------------------------------------------------------------------
template <class T> T HML_Max(T a, T b)
{
/*
Функция возвращает максимальный элемент из двух.
Входные параметры:
 a - первый элемент;
 b - первый элемент.
Возвращаемое значение:
 Максимальный элемент.
*/
if (a>b)
 return a;
else
 return b;
}
//---------------------------------------------------------------------------
template <class T> T HML_Min(T a, T b)
{
/*
Функция возвращает минимальный элемент из двух.
Входные параметры:
 a - первый элемент;
 b - первый элемент.
Возвращаемое значение:
 Минимальный элемент.
*/
if (a<b)
 return a;
else
 return b;
}
//---------------------------------------------------------------------------
template <class T> void HML_NumberInterchange(T *a, T *b)
{
/*
Функция меняет местами значения двух чисел.
Входные параметры:
 a - первое число;
 b - второе число.
Возвращаемое значение:
 Отсутствует.
*/
T x;
x=*b;
*b=*a;
*a=x;
}
//---------------------------------------------------------------------------
template <class T> T HML_PowerOf(T x, int n)
{
/*
Функция возводит произвольное число в целую степень.
Входные параметры:
 x - основание степени;
 n - показатель степени.
Возвращаемое значение:
 Cтепень числа.
*/
T VHML_Result=1;
if (n>0)
 for (int i=0;i<n;i++) VHML_Result*=x;
if (n<0)
 for (int i=0;i<n;i++) VHML_Result/=x;
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_Sign(T a)
{
/*
Функция вычисляет знака числа.
Входные параметры:
 a - исходное число.
Возвращаемое значение:
 0 - если a==0;
 1 - если число положительное;
 -1 - если число отрицательное.
*/
if (a==0) return 0;
if (a>0)
 return 1;
else
 return -1;
}
//---------------------------------------------------------------------------
template <class T> int HML_SignNull(T a)
{
/*
Функция вычисляет знака числа.
Входные параметры:
 a - исходное число.
Возвращаемое значение:
 1 - если число неотрицательное;
 -1 - если число отрицательное.
*/
if (a>=0)
 return 1;
else
 return -1;
}
//---------------------------------------------------------------------------
//*****************************************************************
//Матрицы
//*****************************************************************
template <class T> bool HML_CheckForIdenticalColsInMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
    /*
Функция проверяет наличие одинаковых столбцов в матрице.
Входные параметры:
 VHML_ResultMatrix - указатель на массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов);
Возвращаемое значение:
 true - если есть одинаковые столбцы;
 false - если таких столбцы нет.
*/
    bool VHML_Result=false;
    bool b;
    for (int i=0;i<VHML_M;i++)
        for (int ii=0;ii<VHML_M;ii++)
        {
            if (ii!=i)
            {
            b=true;
            for (int j=0;j<VHML_N;j++)
            {
                if (VHML_ResultMatrix[j][i]!=VHML_ResultMatrix[j][ii]) b=false;
            }
            if (b) VHML_Result=true;
            }
        }
    return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> bool HML_CheckForIdenticalRowsInMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
    /*
Функция проверяет наличие одинаковых строк в матрице.
Входные параметры:
 VHML_ResultMatrix - указатель на массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов);
Возвращаемое значение:
 true - если есть одинаковые строки;
 false - если таких строк нет.
*/
    bool VHML_Result=false;
    bool b;
    for (int i=0;i<VHML_N;i++)
        for (int ii=0;ii<VHML_N;ii++)
        {
            if (ii!=i)
            {
            b=true;
            for (int j=0;j<VHML_M;j++)
            {
                if (VHML_ResultMatrix[i][j]!=VHML_ResultMatrix[ii][j]) b=false;
            }
            if (b) VHML_Result=true;
            }
        }
    return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_ColInterchange(T **VHML_ResultMatrix, int VHML_N, int k, int l)
{
/*
Функция переставляет столбцы матрицы.
Входные параметры:
 VHML_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VHML_N - размер массива (число строки);
 k,l - номера переставляемых столбцов (нумерация с нуля).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 HML_NumberInterchange (&(VHML_ResultMatrix[i][k]),&(VHML_ResultMatrix[i][l]));
}
//---------------------------------------------------------------------------
template <class T> void HML_ColToMatrix(T **VHML_ResultMatrix, T *b, int VHML_N, int k)
{
/*
Функция копирует в матрицу (двумерный массив) из вектора столбец.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 b - указатель на вектор;
 VHML_N - количество строк в матрице и одновременно размер массива b;
 k - номер столбца, в который будет происходить копирование (начиная с 0).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) VHML_ResultMatrix[i][k]=b[i];
}
//---------------------------------------------------------------------------
template <class T> void HML_DeleteColInMatrix(T **VHML_ResultMatrix, int k, int VHML_N, int VHML_M)
{
/*
Функция удаляет k столбец из матрицы (начиная с нуля). Все правостоящие столбцы
сдвигаются влево  на единицу. Последний столбец зануляется.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 k - номер удаляемого столбца;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VHML_N;i++)
 for (j=k;j<VHML_M-1;j++)
  VHML_ResultMatrix[i][j]=VHML_ResultMatrix[i][j+1];
for (i=0;i<VHML_N;i++)
 VHML_ResultMatrix[i][VHML_M-1]=0;//зануляем
}
//---------------------------------------------------------------------------
template <class T> void HML_DeleteRowInMatrix(T **VHML_ResultMatrix, int k, int VHML_N, int VHML_M)
{
/*
Функция удаляет k строку из матрицы (начиная с нуля). Все нижестоящие строки поднимаются на единицу.
Последняя строка зануляется.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 k - номер удаляемой строки;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=k;i<VHML_N-1;i++)
 for (j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=VHML_ResultMatrix[i+1][j];
for (j=0;j<VHML_M;j++)
 VHML_ResultMatrix[VHML_N-1][j]=0;//зануляем
}
//---------------------------------------------------------------------------
template <class T> bool HML_EqualityOfMatrixes (T **a, T **b,int VHML_N,int VHML_M)
{
/*
Функция проверяет равенство матриц.
Входные параметры:
 a - указатель на первую матрицу;
 b - указатель на вторую матрицу;
 VHML_N - размер массива a (число строк);
 VHML_M - размер массива a (число столбцов).
Возвращаемое значение:
 true - матрицы совпадают;
 false - матрицы не совпадают.
*/
bool VHML_Result=true;

for (int i=0;i<VHML_N;i++)
    for (int j=0;j<VHML_M;j++)
        if (a[i][j]!=b[i][j])
            VHML_Result=false;

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_FillMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M, T x)
{
/*
Функция заполняет матрицу значениями, равных x.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов);
 x - число, которым заполняется вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=x;
}
//---------------------------------------------------------------------------
template <class T> void HML_IdentityMatrix(T **VHML_ResultMatrix,int VHML_N)
{
/*
Функция формирует единичную квадратную матрицу.
Входные параметры:
 VHML_ResultMatrix - исходная матрица (в ней и сохраняется результат);
 VHML_N - размер матрицы (число строк и столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_N;j++)
  {
  if (i==j)
   VHML_ResultMatrix[i][j]=1;
  else
   VHML_ResultMatrix[i][j]=0;
  }
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixMinusMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция вычитает две матрицы.
Входные параметры:
 a - первая матрица;
 b - вторая матрица;
 VHML_ResultMatrix - разница матриц;
 VHML_N - размер матриц (число строк);
 VHML_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=a[i][j]-b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixMinusMatrix(T **VHML_ResultMatrix, T **b, int VHML_N, int VHML_M)
{
/*
Функция вычитает два матрицы и результат записывает в первую матрицу.
Входные параметры:
 VHML_ResultMatrix - первая матрица (в ней и сохраняется разница);
 b - вторая матрица;
 VHML_N - размер матриц (число строк);
 VHML_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]-=b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixMultiplyMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S)
{
/*
Функция перемножает матрицы.
Входные параметры:
 a - первый сомножитель, VHML_N x VHML_M;
 b - второй сомножитель, VHML_M x VHML_S;
 VHML_ResultMatrix - произведение матриц (сюда записывается результат), VHML_N x VHML_S;
 VHML_N - число строк в матрице a;
 VHML_M - число столбцов в матрице a и строк в матрице b;
 VHML_S - число столбцов в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VHML_N;i++)
 for (k=0;k<VHML_S;k++)
  {
  w=0;
  for (j=0;j<VHML_M;j++) w+=a[i][j]*b[j][k];
  VHML_ResultMatrix[i][k]=w;
  }
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixMultiplyMatrixT(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S)
{
/*
Функция умножает матрицу на транспонированную матрицу.
Входные параметры:
 a - первый сомножитель, VHML_N x VHML_M;
 b - второй сомножитель (матрица, которую мы транспонируем), VHML_S x VHML_M;
 VHML_ResultMatrix - произведение матриц (сюда записывается результат), VHML_N x VHML_S;
 VHML_N - число строк в матрице a;
 VHML_M - число столбцов в матрице a и столбцов в матрице b;
 VHML_S - число строк в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VHML_N;i++)
 for (k=0;k<VHML_S;k++)
  {
  w=0;
  for (j=0;j<VHML_M;j++) w=w+a[i][j]*b[k][j];
  VHML_ResultMatrix[i][k]=w;
  }
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixMultiplyNumber(T **VHML_ResultMatrix, int VHML_N, int VHML_M, T Number)
{
/*
Функция умножает матрицу на число.
Входные параметры:
 VHML_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VHML_N - размер матрицы (число строк);
 VHML_M - размер матрицы (число столбцов);
 Number - число, на которое умножается матрица.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]*=Number;
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixPlusMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция суммирует две матрицы.
Входные параметры:
 a - первая матрица;
 b - вторая матрица;
 VHML_ResultMatrix - сумма матриц;
 VHML_N - размер матриц (число строк);
 VHML_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=a[i][j]+b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixPlusMatrix(T **VHML_ResultMatrix, T **b, int VHML_N, int VHML_M)
{
/*
Функция суммирует два матрицы и результат записывает в первую матрицу.
Входные параметры:
 VHML_ResultMatrix - первая матрица (в ней и сохраняется сумма);
 b - вторая матрица;
 VHML_N - размер матриц (число строк);
 VHML_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]+=b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixT(T **a, T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция транспонирует матрицу.
Входные параметры:
 a - исходная матрица, (VHML_N x VHML_M);
 VHML_ResultMatrix - транспонированная матрица, (VHML_M x VHML_N);
 VHML_N - размер матрицы (число строк) в матрице a;
 VHML_M - размер матрицы (число столбцов) в матрице a.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[j][i]=a[i][j];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixTMultiplyMatrix(T **a, T **b, T **VHML_ResultMatrix, int VHML_N, int VHML_M, int VHML_S)
{
/*
Функция умножает транспонированную матрицу на матрицу.
Входные параметры:
 a - первый сомножитель (матрица, которую мы транспонируем), VHML_M x VHML_N;
 b - второй сомножитель, VHML_M x VHML_S;
 VHML_ResultMatrix - произведение матриц (сюда записывается результат), VHML_N x VHML_S;
 VHML_N - число столбцов в матрице a;
 VHML_M - число строк в матрице a и строк в матрице b;
 VHML_S - число столбцов в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VHML_N;i++)
 for (k=0;k<VHML_S;k++)
  {
  w=0;
  for (j=0;j<VHML_M;j++) w=w+a[j][i]*b[j][k];
  VHML_ResultMatrix[i][k]=w;
  }
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixToCol(T **a, T *VHML_ResultVector, int VHML_N, int k)
{
/*
Функция копирует из матрицы (двумерного массива) в вектор столбец.
Входные параметры:
 a - указатель на матрицу;
 VHML_ResultVector - указатель на вектор;
 VHML_N - количество строк в матрице и одновременно размер массива b;
 k - номер копируемого столбца (начиная с 0).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=a[i][k];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixToMatrix(T **a, T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция копирует содержимое матрицы (двумерного массива) a в массив VHML_ResultMatrix.
Входные параметры:
 a - указатель на исходный массив;
 VHML_ResultMatrix - указатель на массив в который производится запись;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=a[i][j];
}
//---------------------------------------------------------------------------
template <class T> void HML_MatrixToRow(T **a, T *VHML_ResultVector, int k, int VHML_M)
{
/*
Функция копирует из матрицы (двумерного массива) в вектор строку.
Входные параметры:
 a - указатель на матрицу;
 VHML_ResultVector - указатель на вектор;
 k - номер копируемой строки (начиная с 0);
 VHML_M - количество столбцов в матрице и одновременно размер массива VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_M;i++) VHML_ResultVector[i]=a[k][i];
}
//---------------------------------------------------------------------------
template <class T> T HML_MaximumOfMatrix(T **a, int VHML_N, int VHML_M)
{
/*
Функция ищет максимальный элемент в матрице (двумерном массиве).
Входные параметры:
 a - указатель на матрицу;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Максимальный элемент.
*/
T VHML_Result;
VHML_Result=a[0][0];
for (int i=1;i<VHML_N;i++)
 for (int j=1;j<VHML_M;j++)
  if (a[i][j]>VHML_Result) VHML_Result=a[i][j];
  
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_MinimumOfMatrix(T **a, int VHML_N, int VHML_M)
{
/*
Функция ищет минимальный элемент в матрице (двумерном массиве).
Входные параметры:
 a - указатель на матрицу;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Минимальный элемент.
*/
T VHML_Result;
VHML_Result=a[0][0];
for (int i=1;i<VHML_N;i++)
 for (int j=1;j<VHML_M;j++)
  if (a[i][j]<VHML_Result) VHML_Result=a[i][j];
  
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_MixingRowsInOrder(T **VHML_ResultMatrix, int *b, int VHML_N, int VHML_M)
{
/*
Функция меняет строки матрицы в порядке, указанным в массиве b.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, в которой меняем порядок строк;
 b - вектор, в котором записаны номера, под которыми должны стать строки в матрице (от 0 до VHML_N-1);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
T **c;//Временный массив
c=new T*[VHML_N];
for (i=0;i<VHML_N;i++) c[i]=new T[VHML_M];

//Записываем в массив c в новом порядке
for (i=0;i<VHML_N;i++)
 for (j=0;j<VHML_M;j++)
  c[b[i]][j]=VHML_ResultMatrix[i][j];

//Заменяем основной массив промежуточным
HML_MatrixToMatrix(c,VHML_ResultMatrix,VHML_N,VHML_M);

for (i=0;i<VHML_N;i++) delete[] c[i];
delete[] c;
}
//---------------------------------------------------------------------------
template <class T> int HML_NumberOfDifferentValuesInMatrix(T **a, int VHML_N, int VHML_M)
{
/*
Функция подсчитывает число различных значений в матрице.
Входные параметры:
 a - указатель на матрица;
 VHML_N - размер массива a (строки);
 VHML_M - размер массива a (столбцы).
Возвращаемое значение:
 Число различных значений в матрице.
Примечание:
 Алгоритм очень топорный и медленный.
*/
T *b;
b=new T[VHML_N*VHML_M];
int VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  if (HML_CheckElementInVector(b,VHML_Result,a[i][j])==-1)
   {
   b[VHML_Result]=a[i][j];
   VHML_Result++;
   }
delete [] b;
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_RowInterchange(T **VHML_ResultMatrix, int VHML_M, int k, int l)
{
/*
Функция переставляет строки матрицы.
Входные параметры:
 VHML_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VHML_M - размер массива (число столбцов);
 k,l - номера переставляемых строк (нумерация с нуля).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_M;i++)
 HML_NumberInterchange (&(VHML_ResultMatrix[k][i]),&(VHML_ResultMatrix[l][i]));
}
//---------------------------------------------------------------------------
template <class T> void HML_RowToMatrix(T **VHML_ResultMatrix, T *b, int k, int VHML_M)
{
/*
Функция копирует в матрицу (двумерный массив) из вектора строку.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 b - указатель на вектор;
 k - номер строки, в которую будет происходить копирование (начиная с 0);
 VHML_M - количество столбцов в матрице и одновременно размер массива b.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_M;i++) VHML_ResultMatrix[k][i]=b[i];
}
//---------------------------------------------------------------------------
template <class T> T HML_SumMatrix(T **a,int VHML_N,int VHML_M)
{
/*
Функция вычисляет сумму элементов матрицы.
Входные параметры:
 a - указатель на исходный массив;
 VHML_N - размер массива a (число строк);
 VHML_M - размер массива a (число столбцов).
Возвращаемое значение:
 Сумма элементов матрицы.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_Result+=a[i][j];
  
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> void HML_ZeroMatrix(T **VHML_ResultMatrix,int VHML_N,int VHML_M)
{
/*
Функция зануляет матрицу.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=0;//зануляем
}
//---------------------------------------------------------------------------
//*****************************************************************
//Метрика
//*****************************************************************
template <class T> T HML_Chebychev(T *x, T *y, int VHML_N)
{
/*
Функция вычисляет расстояние Чебышева.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VHML_N - размер массивов.
Возвращаемое значение:
 Значение метрики расстояние Чебышева.
*/
T VHML_Result=0;
T Temp;
for (int i=0;i<VHML_N;i++)
 {
 Temp=HML_Abs(x[i]-y[i]);
 if (Temp>VHML_Result) VHML_Result=Temp;
}
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_CityBlock(T *x, T *y, int VHML_N)
{
/*
Функция вычисляет манхэттенское расстояние между двумя массивами.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VHML_N - размер массивов.
Возвращаемое значение:
 Значение метрики манхэттенское расстояние.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 VHML_Result+=HML_Abs(x[i]-y[i]);
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_Euclid(T *x, T *y, int VHML_N)
{
/*
Функция вычисляет евклидово расстояние.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VHML_N - размер массивов.
Возвращаемое значение:
 Значение метрики евклидово расстояние.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 VHML_Result+=(x[i]-y[i])*(x[i]-y[i]);
VHML_Result=sqrt(VHML_Result);
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_Minkovski(T *x, T *y, int r, int VHML_N)
{
/*
Функция вычисляет метрику Минковского.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 r - порядок метрики;
 VHML_N - размер массивов.
Возвращаемое значение:
 Значение метрики Минковского.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
 {
 VHML_Result+=pow(fabs(x[i]-y[i]),r);
}
VHML_Result=pow(VHML_Result,1./double(r));

return VHML_Result;
}
//---------------------------------------------------------------------------
//*****************************************************************
//Модели
//*****************************************************************
//*****************************************************************
//Непараметрика
//*****************************************************************
//*****************************************************************
//Нечеткие системы
//*****************************************************************
//*****************************************************************
//Оптимизация
//*****************************************************************
//*****************************************************************
//Оптимизация - свалка алгоритмов
//*****************************************************************
//*****************************************************************
//Перевод единиц измерений
//*****************************************************************
//*****************************************************************
//Случайные объекты
//*****************************************************************
template <class T> void HML_BernulliVector(T *VHML_ResultVector, int VHML_N)
{
/*
Функция формирует случайный вектор Бернулли.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VHML_N;i++)
 {
 if (HML_RandomNumber()<0.5)
  VHML_ResultVector[i]=-1.;
 else
  VHML_ResultVector[i]=1.;
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomArrangingObjectsIntoBaskets(T *VHML_ResultVector, int N, int VHML_N)
{
/*
Функция предлагает случайный способ расставить N объектов в VHML_N корзин при условии, что
в каждой корзине может располагаться только один предмет.
Входные параметры:
 VHML_ResultVector - массив, в который записывается результат;
 N - число предметов;
 VHML_N - размер массива (и число корзин).
Возвращаемое значение:
 Отсутствует.
Примечание:
 В VHML_ResultVector 0 удет означать отсутствие предмета, 1 - наличие.
*/
if (N<0) N=0;// должен быть хотя бы один предмет
if (N>VHML_N) N=VHML_N;

int j;//Счетчик
int p;//Текущее число свободнных участников
int r;//случайное число для определения победителя
int g=0;//Номер выбранного участника

HML_ZeroVector(VHML_ResultVector,VHML_N);// Пока никого

if (N>0)
 {//Если есть хотя бы один предмет
 r=HML_RandomUniformInt(0,VHML_N);
 VHML_ResultVector[r]=1;//отметили первую корзину

 for (int i=1;i<N;i++)
  {//выбор еще одной корзины
  r=HML_RandomUniformInt(0,VHML_N-i);//на один меньше можно выбрать, чем в предыдущий раз
  p=0;//Текущее число свободных корзин
  j=0;//Счетчик

  while (p!=r+1)
   {
   //Ищем нашу корзину
   if (VHML_ResultVector[j]==0)
    {
    //Нашли свободную корзину. Возможно это наша.
    p++;
    g=j;
    }
   j++;
   }

  //Теперь g - номер нашей корзины
  VHML_ResultVector[g]=1;//Поместим предмет
  }//выбор еще одной корзины
 }//Если есть хотя бы один предмет
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomBinaryMatrix(T **VHML_ResultMatrix,int VHML_N,int VHML_M)
{
/*
Функция заполняет матрицу случайно нулями и единицами.
Входные параметры:
 VHML_ResultMatrix - указатель на преобразуемый массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VHML_N;i++)
 for(int j=0;j<VHML_M;j++)
  {
  if (HML_RandomNumber()<0.5)
   VHML_ResultMatrix[i][j]=0;
  else
   VHML_ResultMatrix[i][j]=1;
  }
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomBinaryVector(T *VHML_ResultVector,int VHML_N)
{
/*
Функция заполняет вектор (одномерный массив) случайно нулями и единицами.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VHML_N;i++)
 {
 if (HML_RandomNumber()<0.5)
  VHML_ResultVector[i]=0;
 else
  VHML_ResultVector[i]=1;
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomIntMatrix(T **VHML_ResultMatrix, T n, T m, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 n - левая граница интервала;
 m - правая граница интервала;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniformInt(n,m);
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomIntMatrixInCols(T **VHML_ResultMatrix, T *n, T *m, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
При этом элементы каждого столбца изменяются в своих пределах.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 n - левые границы интервала изменения элементов столбцов (размер VHML_M);
 m - правые границы интервала изменения элементов столбцов (размер VHML_M);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniformInt(n[j],m[j]);
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomIntMatrixInElements(T **VHML_ResultMatrix, T **n, T **m, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
При этом каждый элемент изменяется в своих пределах.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 n - левые границы интервала изменения каждого элемента (размер VHML_N x VHML_M);
 m - правые границы интервала изменения каждого элемента (размер VHML_N x VHML_M);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniformInt(n[i][j],m[i][j]);
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomIntMatrixInRows(T **VHML_ResultMatrix, T *n, T *m, int VHML_N, int VHML_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
При этом элементы каждой строки изменяются в своих пределах.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 n - левые границы интервала изменения элементов строки (размер VHML_N);
 m - правые границы интервала изменения элементов строки (размер VHML_N);
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 for (int j=0;j<VHML_M;j++)
  VHML_ResultMatrix[i][j]=HML_RandomUniformInt(n[i],m[i]);
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomIntVector(T *VHML_ResultVector, T n, T m, int VHML_N)
{
/*
Функция заполняет массив случайными целыми числами из определенного интервала [n,m).
Входные параметры:
 VHML_ResultVector - указатель на массив;
 n - левая граница интервала;
 m - правая граница интервала;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomUniformInt(int(n),int(m));
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomIntVectorInElements(T *VHML_ResultVector, T *n, T *m, int VHML_N)
{
/*
Функция заполняет массив случайными целыми  числами из определенного интервала [n_i,m_i). При этом для каждого элемента массива свой интервал изменения.
Входные параметры:
 VHML_ResultVector - указатель на массив;
 n - указатель на массив левых границ интервала;
 m - указатель на массив правых границ интервала;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomUniform(int(n[i]),int(m[i]));
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomMatrixOfPermutation(T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
/*
Функция создает случайный массив строк-перестановок чисел от 1 до VHML_M.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу;
 VHML_N - размер массива (число строк);
 VHML_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
T MOne=-1;
int i, j, b1, b2, randomall;
HML_FillMatrix (VHML_ResultMatrix,VHML_N,VHML_M,MOne);
for (j=0;j<VHML_N;j++)
 {
 for (i=0;i<VHML_M;i++)
  {//начало заполнения цифрами
  randomall=HML_RandomUniformInt(0,VHML_M-i)+1;
  b1=0;
  b2=0;
  while (b1<randomall)
   {
   if (VHML_ResultMatrix[j][b2]==-1) b1=b1+1;
   b2=b2+1;
   }
  VHML_ResultMatrix[j][b2-1]=i+1;
  }//конец заполнения цифрами
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_RandomVectorOfPermutation(T *VHML_ResultVector, int VHML_N)
{
/*
Функция создает случайную строку-перестановку чисел от 1 до VHML_N (включительно).
Входные параметры:
 VHML_ResultVector - указатель на массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T MOne=-1;
int i, b1, b2, randomall;
HML_FillVector (VHML_ResultVector,VHML_N,MOne);
for (i=0;i<VHML_N;i++)
 {//начало заполнения цифрами
 randomall=HML_RandomUniformInt(0,VHML_N-i)+1;
 b1=0;
 b2=0;
 while (b1<randomall)
  {
  if (VHML_ResultVector[b2]==-1) b1=b1+1;
  b2=b2+1;
  }
 VHML_ResultVector[b2-1]=i+1;
 }//конец заполнения цифрами
}
//---------------------------------------------------------------------------
//*****************************************************************
//Случайные числа
//*****************************************************************
//*****************************************************************
//Сортировка
//*****************************************************************
template <class T> void HML_BubbleDescendingSort(T *VHML_ResultVector, int VHML_N)
{
/*
Функция сортирует массив в порядке убывания методом "Сортировка пузырьком".
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_N - количество элементов в массиве.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VHML_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VHML_ResultVector[j]<VHML_ResultVector[j+1])
   HML_NumberInterchange(&(VHML_ResultVector[j]),&(VHML_ResultVector[j+1]));
}
//---------------------------------------------------------------------------
template <class T> void HML_BubbleSort(T *VHML_ResultVector, int VHML_N)
{
/*
Функция сортирует массив в порядке возрастания методом "Сортировка пузырьком".
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_N - количество элементов в массиве.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VHML_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VHML_ResultVector[j]>VHML_ResultVector[j+1])
   HML_NumberInterchange(&(VHML_ResultVector[j]),&(VHML_ResultVector[j+1]));
}
//---------------------------------------------------------------------------
template <class T> void HML_BubbleSortColWithOtherConjugateColsInMatrix(T **VHML_ResultMatrix,int Col, int VHML_N, int VHML_M)
{
/*
Функция сортирует матрицу по какому-то столбцу под номером в порядке возрастания методом "Сортировка пузырьком".
При этом все остальные столбцы являются как бы сопряженным с данным столбцом. То есть элементы в этом столбце сортируются,
а все строки остаются прежними.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, которую будем сортировать;
 Col - номер сортируемого столбца в матрице;
 VHML_N - количество строк в матрице;
 VHML_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for(i=VHML_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(VHML_ResultMatrix[j][Col]>VHML_ResultMatrix[j+1][Col])
            {
                for (k=0;k<VHML_M;k++)
                    HML_NumberInterchange(&(VHML_ResultMatrix[j][k]),&(VHML_ResultMatrix[j+1][k]));
            }
}
//---------------------------------------------------------------------------
template <class T> void HML_BubbleSortEveryColInMatrix(T **VHML_ResultMatrix,int VHML_N, int VHML_M)
{
/*
Функция сортирует каждый столбец матрицы в отдельности.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, которую будем сортировать;
 VHML_N - количество строк в матрице;
 VHML_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for (k=0;k<VHML_M;k++)
    {
        for(i=VHML_N-1;i>0;i--)
            for(j=0;j<i;j++)
                if(VHML_ResultMatrix[j][k]>VHML_ResultMatrix[j+1][k])
                {
                    HML_NumberInterchange(&(VHML_ResultMatrix[j][k]),&(VHML_ResultMatrix[j+1][k]));
                }
    }
}
//---------------------------------------------------------------------------
template <class T> void HML_BubbleSortEveryRowInMatrix(T **VHML_ResultMatrix,int VHML_N, int VHML_M)
{
/*
Функция сортирует каждую строку матрицы в отдельности.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, которую будем сортировать;
 VHML_N - количество строк в матрице;
 VHML_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for (k=0;k<VHML_N;k++)
    {
        for(i=VHML_M-1;i>0;i--)
            for(j=0;j<i;j++)
                if(VHML_ResultMatrix[k][j]>VHML_ResultMatrix[k][j+1])
                {
                    HML_NumberInterchange(&(VHML_ResultMatrix[k][j]),&(VHML_ResultMatrix[k][j+1]));
                }
    }
}
//---------------------------------------------------------------------------
template <class T> void HML_BubbleSortInGroups(T *VHML_ResultVector, int VHML_N, int m)
{
/*
Функция сортирует массив в порядке возрастания методом "Сортировка пузырьком" в группах данного массива.
Имеется массив. Он делится на группы элементов по m элементов. Первые m
элементов принадлежат первой группе, следующие m элементов - следующей и т.д.
(Разумеется, в последней группе может и не оказаться m элементов).
Потом в каждой группе элементы сортируются по возрастанию.
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_N - количество элементов в массиве;
 m - количество элементов в группе.
*/
int i,j,k,N,M;
N=int(VHML_N/m);//число групп
for (k=0;k<N;k++)
 {
 for(i=m-1;i>0;i--)
  for(j=0;j<i;j++)
   if(VHML_ResultVector[k*m+j]>VHML_ResultVector[k*m+j+1])
    HML_NumberInterchange(&(VHML_ResultVector[k*m+j]),&(VHML_ResultVector[k*m+j+1]));
 }
M=VHML_N%m;
if (M!=0)//если есть последняя неполная группа
 {
 for(i=M-1;i>0;i--)
  for(j=0;j<i;j++)
   if(VHML_ResultVector[N*m+j]>VHML_ResultVector[N*m+j+1])
    HML_NumberInterchange(&(VHML_ResultVector[N*m+j]),&(VHML_ResultVector[N*m+j+1]));
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_BubbleSortRowWithOtherConjugateRowsInMatrix(T **VHML_ResultMatrix,int Row, int VHML_N, int VHML_M)
{
/*
Функция сортирует матрицу по какой-то строке под номером в порядке возрастания методом "Сортировка пузырьком".
При этом все остальные строки являются как бы сопряжеными с данной строкой. То есть элементы в этой строке сортируются,
а все столбцы остаются прежними.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, которую будем сортировать;
 Row - номер сортируемой строки в матрице;
 VHML_N - количество строк в матрице;
 VHML_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for(i=VHML_M-1;i>0;i--)
        for(j=0;j<i;j++)
            if(VHML_ResultMatrix[Row][j]>VHML_ResultMatrix[Row][j+1])
            {
                for (k=0;k<VHML_N;k++)
                    HML_NumberInterchange(&(VHML_ResultMatrix[k][j]),&(VHML_ResultMatrix[k][j+1]));
            }
}
//---------------------------------------------------------------------------
template <class T, class T2> void HML_BubbleSortWithConjugateVector(T *VHML_ResultVector, T2 *VHML_ResultVector2, int VHML_N)
{
/*
Функция сортирует массив вместе с сопряженный массивом в порядке возрастания методом "Сортировка пузырьком".
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_ResultVector2 - указатель на сопряженный массив;
 VHML_N - количество элементов в массиве.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VHML_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VHML_ResultVector[j]>VHML_ResultVector[j+1])
   {
   HML_NumberInterchange(&(VHML_ResultVector[j]),&(VHML_ResultVector[j+1]));
   HML_NumberInterchange(&(VHML_ResultVector2[j]),&(VHML_ResultVector2[j+1]));
   }
}
//---------------------------------------------------------------------------
template <class T, class T2, class T3> void HML_BubbleSortWithTwoConjugateVectors(T *VHML_ResultVector, T2 *VHML_ResultVector2, T3 *VHML_ResultVector3, int VHML_N)
{
/*
Функция сортирует массив вместе с двумя сопряженными массивами в порядке возрастания методом "Сортировка пузырьком".
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_ResultVector2 - указатель на сопряженный массив;
 VHML_ResultVector3 - указатель на второй сопряженный массив;
 VHML_N - количество элементов в массивах.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VHML_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VHML_ResultVector[j]>VHML_ResultVector[j+1])
   {
   HML_NumberInterchange(&(VHML_ResultVector[j]),&(VHML_ResultVector[j+1]));
   HML_NumberInterchange(&(VHML_ResultVector2[j]),&(VHML_ResultVector2[j+1]));
   HML_NumberInterchange(&(VHML_ResultVector3[j]),&(VHML_ResultVector3[j+1]));
   }
}
//---------------------------------------------------------------------------
//*****************************************************************
//Статистика и теория вероятности
//*****************************************************************
template <class T> T HML_Mean(T *x, int VHML_N)
{
/*
Функция вычисляет среднее арифметическое массива.
Входные параметры:
 x - массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Среднее арифметическое массива.
Примечание:
 Если будете считать для массива *int, то ответ будет некорректным, так как ответ возвратиться тоже в виде int.
*/
return HML_SumVector(x,VHML_N)/double(VHML_N);
}
//---------------------------------------------------------------------------
template <class T> T HML_MeanOfFilter(T *x, int VHML_N, T UpperFilter, T LowerFilter)
{
/*
Функция вычисляет среднее арифметическое массива с фильтром, то есть при подсчете не учитываются значения ниже LowerFilter и выше UpperFilter.
Входные параметры:
 x - массив;
 VHML_N - размер массива;
 UpperFilter - верхняя граница значений, ниже которых значения не участвуют в подсчете;
 LowerFilter - нижняя граница значений, ниже которых значения не участвуют в подсчете.
Возвращаемое значение:
 Среднее арифметическое массива с фильтром.
Примечание:
 Если будете считать для массива *int, то ответ будет некорректным, так как ответ возвратиться тоже в виде int.
*/
    T N=0;
    T Sum=0;
    for (int i=0;i<VHML_N;i++)
    {
        if ((x[i]>=LowerFilter)&&(x[i]<=UpperFilter))
        {
            N++;
            Sum += x[i];
        }
    }

return Sum/N;
}
//---------------------------------------------------------------------------
template <class T> T HML_MeanOfLowerFilter(T *x, int VHML_N, T LowerFilter)
{
/*
Функция вычисляет среднее арифметическое массива с нижним фильтром, то есть при подсчете не учитываются значения ниже LowerFilter.
Входные параметры:
 x - массив;
 VHML_N - размер массива;
 LowerFilter - нижняя граница значений, ниже которых значения не участвуют в подсчете.
Возвращаемое значение:
 Среднее арифметическое массива с нижним фильтром.
Примечание:
 Если будете считать для массива *int, то ответ будет некорректным, так как ответ возвратиться тоже в виде int.
*/
    T N=0;
    T Sum=0;
    for (int i=0;i<VHML_N;i++)
    {
        if (x[i]>=LowerFilter)
        {
            N++;
            Sum += x[i];
        }
    }

return Sum/N;
}
//---------------------------------------------------------------------------
template <class T> T HML_MeanOfUpperFilter(T *x, int VHML_N, T UpperFilter)
{
/*
Функция вычисляет среднее арифметическое массива с верхним фильтром, то есть при подсчете не учитываются значения выше UpperFilter.
Входные параметры:
 x - массив;
 VHML_N - размер массива;
 UpperFilter - верхняя граница значений, выше которых значения не участвуют в подсчете.
Возвращаемое значение:
 Среднее арифметическое массива с верхним фильтром.
Примечание:
 Если будете считать для массива *int, то ответ будет некорректным, так как ответ возвратиться тоже в виде int.
*/
    T N=0;
    T Sum=0;
    for (int i=0;i<VHML_N;i++)
    {
        if (x[i]<=UpperFilter)
        {
            N++;
            Sum += x[i];
        }
    }

return Sum/N;
}
//---------------------------------------------------------------------------
template <class T> T HML_Median(T *x, int VHML_N)
{
/*
Функция вычисляет медиану выборки.
Входные параметры:
 x - указатель на исходную выборку;
 VHML_N - размер массива.
Возвращаемое значение:
 Медиана массива.
*/
T VHML_Result;
T *SortVector;
T Two=2;
SortVector=new T[VHML_N];//Нам нужно отсортировать массив, но не трогая этот
HML_VectorToVector(x,SortVector,VHML_N);

HML_BubbleSort(SortVector,VHML_N);//отсортируем массив

if (HML_Parity(VHML_N)==0)//Если число элементов нечетно
 VHML_Result=SortVector[VHML_N/2];
else//Если число элементов четно
 VHML_Result=(SortVector[VHML_N/2-1]+SortVector[VHML_N/2])/Two;
delete [] SortVector;

return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_SampleCovariance(T *x, T *y, int VHML_N)
{
/*
Функция вычисляет выборочную ковариацию выборки (несмещенная, исправленная).
Входные параметры:
 x - указатель на первую сравниваемую выборки;
 y - указатель на вторую сравниваемую выборки;
 VHML_N - размер массивов.
Выходной параметр:
 Значение выборочной ковариации.
*/
T xn,yn;
T VHML_Result=0;

//Найдем среднее арифметические двух выборок
xn=HML_Mean(x,VHML_N);
yn=HML_Mean(x,VHML_N);

for(int i=0;i<VHML_N;i++)
 VHML_Result+=(x[i]-xn)*(y[i]-yn);

VHML_Result/=VHML_N-1;
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_UncorrectedVariance(T *x, int VHML_N)
{
/*
Функция вычисляет неисправленная выборочную дисперсию выборки.
Входные параметры:
 x - указатель на исходную выборку;
 VHML_N - размер массива.
Возвращаемое значение:
 Выборочная неисправленная дисперсия выборки.
*/
T xn;
T VHML_Result=0;

//Найдем среднее арифметические выборки
xn=HML_Mean(x,VHML_N);

for(int i=0;i<VHML_N;i++)
 VHML_Result+=(x[i]-xn)*(x[i]-xn);

VHML_Result/=VHML_N;
return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> T HML_Variance(T *x, int VHML_N)
{
/*
Функция вычисляет выборочную дисперсию выборки (несмещенная, исправленная).
Входные параметры:
 x - указатель на исходную выборку;
 VHML_N - размер массива.
Возвращаемое значение:
 Выборочная дисперсия выборки.
*/
return HML_SampleCovariance(x,x,VHML_N);
}
//---------------------------------------------------------------------------
//*****************************************************************
//Тестовые функции для оптимизации
//*****************************************************************
//*****************************************************************
//Тригонометрические функции
//*****************************************************************
//*****************************************************************
//Уравнения
//*****************************************************************
//*****************************************************************
//Физика
//*****************************************************************
//*****************************************************************
//Цвет
//*****************************************************************

#endif // HARRIXMATHLIBRARY_H