#ifndef HARRIXMATHLIBRARY_H
#define HARRIXMATHLIBRARY_H
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

//ДЛЯ ГЕНЕРАТОРОВ СЛУЧАЙНЫХ ЧИСЕЛ
enum TypeOfRandomNumberGenerator { StandardRandomNumberGenerator, MersenneTwisterRandomNumberGenerator };//тип генератора случайных чисел: стандартный или MersenneTwister:
void MHL_SeedRandom(void);//Инициализатор генератора случайных чисел
double MHL_RandomNumber(void);//Генерирует вещественное случайное число из интервала (0;1)
void MHL_SetRandomNumberGenerator(TypeOfRandomNumberGenerator T);//Переназначить генератор случайных чисел на другой

//ПЕРЕМЕННЫЕ ПЕРЕЧИСЛЯЕМОГО ТИПА
enum TypeOfTestFunction { TestFunction_Ackley, TestFunction_ParaboloidOfRevolution, TestFunction_Rastrigin, TestFunction_Rosenbrock, TestFunction_SumVector, TestFunction_AdditivePotential, TestFunction_MultiplicativePotential, TestFunction_ReverseGriewank, TestFunction_HyperEllipsoid, TestFunction_RotatedHyperEllipsoid, TestFunction_Wave, TestFunction_Multiextremal, TestFunction_Multiextremal2, TestFunction_Sombrero, TestFunction_Himmelblau, TestFunction_Katnikov, TestFunction_Multiextremal3, TestFunction_Multiextremal4, TestFunction_StepFunction, TestFunction_Rana };

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Вектора (Одномерные массивы)
void MHL_DependentNoiseInVector(double *VMHL_ResultVector, double percent, int VMHL_N);
double MHL_EuclidNorma(double *a,int VMHL_N);
void MHL_NoiseInVector(double *VMHL_ResultVector, double percent, int VMHL_N);
template <class T> void TMHL_AcceptanceLimits(T *VMHL_ResultVector, T *Left, T *Right, int VMHL_N);
template <class T> int TMHL_CheckElementInVector(T *x, int VMHL_N, T a);
template <class T> int TMHL_CompareMeanOfVectors(T *a, T *b, int VMHL_N);
template <class T> int TMHL_CompareMeanOfVectors(T *a, T *b, int VMHL_N1, int VMHL_N2);
template <class T> bool TMHL_EqualityOfVectors(T *a, T *b, int VMHL_N);
template <class T> void TMHL_FibonacciNumbersVector(T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_FillVector(T *VMHL_ResultVector, int VMHL_N, T x);
template <class T> T TMHL_MaximumOfVector(T *VMHL_Vector, int VMHL_N);
template <class T> T TMHL_MinimumOfVector(T *VMHL_Vector, int VMHL_N);
template <class T> void TMHL_MixingVector(T *VMHL_ResultVector, double P, int VMHL_N);
template <class T, class T2> void TMHL_MixingVectorWithConjugateVector(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, double P, int VMHL_N);
template <class T> int TMHL_NumberOfDifferentValuesInVector(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfMaximumOfVector(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfMinimumOfVector(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfNegativeValues(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfPositiveValues(T *a, int VMHL_N);
template <class T> int TMHL_NumberOfZeroValues(T *a, int VMHL_N);
template <class T> void TMHL_OrdinalVector(T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_OrdinalVectorZero(T *VMHL_ResultVector, int VMHL_N);
template <class T> T TMHL_ProductOfElementsOfVector(T *VMHL_Vector,int VMHL_N);
template <class T> void TMHL_ReverseVector(T *VMHL_ResultVector, int VMHL_N);
template <class T> int TMHL_SearchElementInVector (T *X, T x, int VMHL_N);
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

//Генетические алгоритмы
double MHL_BinaryFitnessFunction(int*x, int VMHL_N);
void MHL_MakeVectorOfProbabilityForProportionalSelectionV2(double *Fitness, double *VMHL_ResultVector, int VMHL_N);
void MHL_MakeVectorOfProbabilityForRanklSelection(double *Rank, double *VMHL_ResultVector, int VMHL_N);
void MHL_MakeVectorOfRankForRankSelection(double *Fitness, double *VMHL_ResultVector, int VMHL_N);
void MHL_MakeVectorOfRankZeroForRankSelection(double *Fitness, double *VMHL_ResultVector, int VMHL_N);
void MHL_NormalizationVectorAll(double *x,int VMHL_N);
void MHL_NormalizationVectorMaxMin(double *VMHL_ResultVector,int VMHL_N);
void MHL_NormalizationVectorOne(double *VMHL_ResultVector,int VMHL_N);
double MHL_ProbabilityOfTournamentSelection(double *Fitness, double *VMHL_ResultVector_Probability, int T, int VMHL_N);
int MHL_ProportionalSelection(double *Fitness, int VMHL_N);
int MHL_ProportionalSelectionV2(double *VectorOfProbability, int VMHL_N);
int MHL_ProportionalSelectionV3(double *Fitness, int VMHL_N);
int MHL_RankSelection(double *VectorOfProbability, int VMHL_N);
int MHL_SelectItemOnProbability(double *P, int VMHL_N);
int MHL_StandartBinaryGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
int MHL_StandartGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
int MHL_StandartGeneticAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
int MHL_StandartRealGeneticAlgorithm(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
int MHL_TournamentSelection(double *Fitness, int SizeTournament, int VMHL_N);
int MHL_TournamentSelection(double *Fitness, int SizeTournament, int *Taken, int VMHL_N);
int MHL_TournamentSelectionWithReturn(double *Fitness, int SizeTournament, int VMHL_N);
template <class T> void TMHL_MutationBinaryMatrix(T **VMHL_ResultMatrix, double ProbabilityOfMutation, int VMHL_N,int VMHL_M);
template <class T> void TMHL_SinglepointCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_SinglepointCrossoverWithCopying(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_TwopointCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_TwopointCrossoverWithCopying(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_UniformCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N);

//Геометрия
double MHL_LineGeneralForm(double x, double A, double B, double C, int *solutionis);
double MHL_LineGeneralForm(double x, double A, double B, double C);
double MHL_LineSlopeInterceptForm(double x, double k, double b);
double MHL_LineTwoPoint(double x, double x1, double y1, double x2, double y2, int *solutionis);
double MHL_LineTwoPoint(double x, double x1, double y1, double x2, double y2);
double MHL_Parabola(double x, double a, double b, double c);
template <class T> int TMHL_BoolCrossingTwoSegment(T b1,T c1,T b2,T c2);

//Гиперболические функции
double MHL_Cosech(double x);
double MHL_Cosh(double x);
double MHL_Cotanh(double x);
double MHL_Sech(double x);
double MHL_Sinh(double x);
double MHL_Tanh(double x);

//Дифференцирование
double MHL_CenterDerivative(double x, double h, double (*Function)(double));
double MHL_LeftDerivative(double x, double h, double (*Function)(double));
double MHL_RightDerivative(double x, double h, double (*Function)(double));

//Для тестовых функций
int MHL_ClassOfTestFunction(TypeOfTestFunction Type);
int MHL_CountOfFitnessOfTestFunction_Binary(int Dimension);
int MHL_CountOfFitnessOfTestFunction_Binary(int Dimension, TypeOfTestFunction Type);
int MHL_CountOfFitnessOfTestFunction_Real(int Dimension);
int MHL_CountOfFitnessOfTestFunction_Real(int Dimension, TypeOfTestFunction Type);
void MHL_DefineTestFunction(TypeOfTestFunction Type);
int MHL_DimensionTestFunction_Binary(int i);
int MHL_DimensionTestFunction_Binary(int i, TypeOfTestFunction Type);
int MHL_DimensionTestFunction_Real(int i);
int MHL_DimensionTestFunction_Real(int i, TypeOfTestFunction Type);
double MHL_ErrorExOfTestFunction_Binary(int *x, int VMHL_N);
double MHL_ErrorExOfTestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorExOfTestFunction_Real(double *x, int VMHL_N);
double MHL_ErrorExOfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VMHL_N);
double MHL_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorEyOfTestFunction_Real(double FitnessOfx, int VMHL_N);
double MHL_ErrorEyOfTestFunction_Real(double FitnessOfx, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorROfTestFunction_Binary(int *x, int VMHL_N);
double MHL_ErrorROfTestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N);
double MHL_ErrorROfTestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_FitnessOfOptimumOfTestFunction_Binary(int VMHL_N);
double MHL_FitnessOfOptimumOfTestFunction_Binary(int VMHL_N, TypeOfTestFunction Type);
double MHL_FitnessOfOptimumOfTestFunction_Real(double VMHL_N);
double MHL_FitnessOfOptimumOfTestFunction_Real(double VMHL_N, TypeOfTestFunction Type);
int MHL_GetCountOfFitness();
int MHL_GetCountOfSubProblems_Binary();
int MHL_GetCountOfSubProblems_Binary(TypeOfTestFunction Type);
int MHL_GetCountOfSubProblems_Real();
int MHL_GetCountOfSubProblems_Real(TypeOfTestFunction Type);
void MHL_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right,int VMHL_N);
void MHL_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right, int VMHL_N, TypeOfTestFunction Type);
double MHL_MaximumOrMinimumOfTestFunction_Binary();
double MHL_MaximumOrMinimumOfTestFunction_Binary(TypeOfTestFunction Type);
double MHL_MaximumOrMinimumOfTestFunction_Real();
double MHL_MaximumOrMinimumOfTestFunction_Real(TypeOfTestFunction Type);
double MHL_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VMHL_N);
double MHL_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VMHL_N, TypeOfTestFunction Type);
double MHL_OptimumOfTestFunction_Binary(int *Optimum, int VMHL_N);
double MHL_OptimumOfTestFunction_Binary(int *Optimum, int VMHL_N, TypeOfTestFunction Type);
double MHL_OptimumOfTestFunction_Real(double *Optimum, int VMHL_N);
double MHL_OptimumOfTestFunction_Real(double *Optimum, int VMHL_N, TypeOfTestFunction Type);
double MHL_PrecisionOfCalculationsOfTestFunction_Real();
double MHL_PrecisionOfCalculationsOfTestFunction_Real(TypeOfTestFunction Type);
void MHL_SetToZeroCountOfFitness();
double MHL_TestFunction_Binary(int *x, int VMHL_N);
double MHL_TestFunction_Binary(int *x, int VMHL_N, TypeOfTestFunction Type);
double MHL_TestFunction_Real(double *x, int VMHL_N);
double MHL_TestFunction_Real(double *x, int VMHL_N, TypeOfTestFunction Type);

//Интегрирование
double MHL_IntegralOfRectangle(double a, double b, double Epsilon,double (*Function)(double));
double MHL_IntegralOfSimpson(double a, double b, double Epsilon,double (*Function)(double));
double MHL_IntegralOfTrapezium(double a, double b, double Epsilon,double (*Function)(double));

//Кодирование и декодирование
void MHL_BinaryGrayVectorToRealVector(int *x, int n, double *VMHL_ResultVector, double *Left, double *Right, int *Lengthi, int VMHL_N);
void MHL_BinaryGrayVectorToRealVector(int *x, double *VMHL_ResultVector,int *TempBinaryVector, double *Left, double *Right, int *Lengthi, int VMHL_N);
void MHL_BinaryVectorToRealVector(int *x, double *VMHL_ResultVector, double *Left, double *Right, int *Lengthi, int VMHL_N);
template <class T> T TMHL_BinaryToDecimal(T *a, int VMHL_N);
template <class T> T TMHL_BinaryToDecimalFromPart(T *a, int Begin, int n);
template <class T> void TMHL_GrayCodeToBinary(T *a,int *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_GrayCodeToBinaryFromPart(T *a, T *VMHL_ResultVector, int Begin, int n);

//Комбинаторика
template <class T> T TMHL_KCombinations(T k, T n);

//Математические функции
double MHL_ArithmeticalProgression(double a1,double d,int n);
double MHL_ExpMSxD2(double x);
double MHL_GeometricSeries(double u1,double q,int n);
int MHL_GreatestCommonDivisorEuclid(int A,int B);
int MHL_HowManyPowersOfTwo(int x);
double MHL_InverseNormalizationNumberAll(double x);
int MHL_LeastCommonMultipleEuclid(int A,int B);
void MHL_MixedMultiLogicVectorOfFullSearch(int *VMHL_Vector, int I, int *HowMuchInElements, int VMHL_N);
double MHL_NormalizationNumberAll(double x);
int MHL_Parity(int a);
double MHL_ProbabilityDensityFunctionOfInverseGaussianDistribution (double x, double mu, double lambda);
double MHL_SumGeometricSeries(double u1,double q,int n);
double MHL_SumOfArithmeticalProgression(double a1,double d,int n);
int MHL_SumOfDigits(int a);
template <class T> T TMHL_Abs(T x);
template <class T> T TMHL_Factorial(T x);
template <class T> T TMHL_FibonacciNumber(T n);
template <class T> T TMHL_HeavisideFunction(T x);
template <class T> T TMHL_Max(T a, T b);
template <class T> T TMHL_Min(T a, T b);
template <class T> void TMHL_NumberInterchange(T *a, T *b);
template <class T> T TMHL_PowerOf(T x, int n);
template <class T> int TMHL_Sign(T a);
template <class T> int TMHL_SignNull(T a);

//Матрицы
template <class T> bool TMHL_CheckForIdenticalColsInMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> bool TMHL_CheckForIdenticalRowsInMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> void TMHL_ColInterchange(T **VMHL_ResultMatrix, int VMHL_N, int k, int l);
template <class T> void TMHL_ColToMatrix(T **VMHL_ResultMatrix, T *b, int VMHL_N, int k);
template <class T> void TMHL_DeleteColInMatrix(T **VMHL_ResultMatrix, int k, int VMHL_N, int VMHL_M);
template <class T> void TMHL_DeleteRowInMatrix(T **VMHL_ResultMatrix, int k, int VMHL_N, int VMHL_M);
template <class T> bool TMHL_EqualityOfMatrixes (T **a, T **b,int VMHL_N,int VMHL_M);
template <class T> void TMHL_FillMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, T x);
template <class T> void TMHL_IdentityMatrix(T **VMHL_ResultMatrix,int VMHL_N);
template <class T> void TMHL_MatrixMinusMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixMinusMatrix(T **VMHL_ResultMatrix, T **b, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixMultiplyMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S);
template <class T> void TMHL_MatrixMultiplyMatrixT(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S);
template <class T> void TMHL_MatrixMultiplyNumber(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, T Number);
template <class T> void TMHL_MatrixPlusMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixPlusMatrix(T **VMHL_ResultMatrix, T **b, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixT(T **a, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixTMultiplyMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S);
template <class T> void TMHL_MatrixToCol(T **a, T *VMHL_ResultVector, int VMHL_N, int k);
template <class T> void TMHL_MatrixToMatrix(T **a, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixToRow(T **a, T *VMHL_ResultVector, int k, int VMHL_M);
template <class T> T TMHL_MaximumOfMatrix(T **a, int VMHL_N, int VMHL_M);
template <class T> T TMHL_MinimumOfMatrix(T **a, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MixingRowsInOrder(T **VMHL_ResultMatrix, int *b, int VMHL_N, int VMHL_M);
template <class T> int TMHL_NumberOfDifferentValuesInMatrix(T **a, int VMHL_N, int VMHL_M);
template <class T> void TMHL_MatrixToRow(T **a, T *VMHL_ResultVector, int k, int VMHL_M);
template <class T> void TMHL_RowToMatrix(T **VMHL_ResultMatrix, T *b, int k, int VMHL_M);
template <class T> T TMHL_SumMatrix(T **a,int VMHL_N,int VMHL_M);
template <class T> void TMHL_ZeroMatrix(T **VMHL_ResultMatrix,int VMHL_N,int VMHL_M);

//Метрика
template <class T> T TMHL_Chebychev(T *x, T *y, int VMHL_N);
template <class T> T TMHL_CityBlock(T *x, T *y, int VMHL_N);
template <class T> T TMHL_Euclid(T *x, T *y, int VMHL_N);
template <class T> T TMHL_Minkovski(T *x, T *y, int r, int VMHL_N);

//Непараметрика
double MHL_BellShapedKernelExp(double z);
double MHL_BellShapedKernelParabola(double z);
double MHL_BellShapedKernelRectangle(double z);
double MHL_BellShapedKernelTriangle(double z);
double MHL_DerivativeOfBellShapedKernelExp(double z);
double MHL_DerivativeOfBellShapedKernelParabola(double z);
double MHL_DerivativeOfBellShapedKernelRectangle(double z);
double MHL_DerivativeOfBellShapedKernelTriangle(double z);

//Нечеткие системы
double MHL_TrapeziformFuzzyNumber(double x,double a,double b,double c,double d);

//Оптимизация
int MHL_BinaryMonteCarloAlgorithm(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
void MHL_DichotomyOptimization (double Left, double Right, double (*Function)(double), double Interval, double Epsilon, double *VMHL_Result_X,double *VMHL_Result_Y);
void MHL_FibonacciOptimization (double Left, double Right, double (*Function)(double), int Count, double *VMHL_Result_X,double *VMHL_Result_Y);
void MHL_GoldenSectionOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VMHL_Result_X,double *VMHL_Result_Y);
void MHL_QuadraticFitOptimization (double Left, double Right, double (*Function)(double), double Epsilon, double Epsilon2, double *VMHL_Result_X,double *VMHL_Result_Y);
int MHL_RealMonteCarloAlgorithm(int *Parameters, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
void MHL_RealMonteCarloOptimization (double Left, double Right, double (*Function)(double), int Count, double *VMHL_Result_X,double *VMHL_Result_Y);
void MHL_UniformSearchOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VMHL_Result_X,double *VMHL_Result_Y);
void MHL_UniformSearchOptimizationN (double Left, double Right, double (*Function)(double), int Count, double *VMHL_Result_X,double *VMHL_Result_Y);

//Оптимизация - свалка алгоритмов
int MHL_BinaryGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
int MHL_BinaryGeneticAlgorithmWCC(int *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
int MHL_BinaryGeneticAlgorithmWDPOfNOfGPS(double *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
int MHL_BinaryGeneticAlgorithmWDTS(double *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result);
int MHL_RealGeneticAlgorithmTournamentSelectionWithReturn(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
int MHL_RealGeneticAlgorithmWCC(int *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
int MHL_RealGeneticAlgorithmWDPOfNOfGPS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);
int MHL_RealGeneticAlgorithmWDTS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result);

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
template <class T> void TMHL_BernulliVector(T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_RandomArrangingObjectsIntoBaskets(T *VMHL_ResultVector, int N, int VMHL_N);
template <class T> void TMHL_RandomBinaryMatrix(T **VMHL_ResultMatrix,int VMHL_N,int VMHL_M);
template <class T> void TMHL_RandomBinaryVector(T *VMHL_ResultVector,int VMHL_N);
template <class T> void TMHL_RandomIntMatrix(T **VMHL_ResultMatrix, T n, T m, int VMHL_N, int VMHL_M);
template <class T> void TMHL_RandomIntMatrixInCols(T **VMHL_ResultMatrix, T *n, T *m, int VMHL_N, int VMHL_M);
template <class T> void TMHL_RandomIntMatrixInElements(T **VMHL_ResultMatrix, T **n, T **m, int VMHL_N, int VMHL_M);
template <class T> void TMHL_RandomIntMatrixInRows(T **VMHL_ResultMatrix, T *n, T *m, int VMHL_N, int VMHL_M);
template <class T> void TMHL_RandomIntVector(T *VMHL_ResultVector, T n, T m, int VMHL_N);
template <class T> void TMHL_RandomIntVectorInElements(T *VMHL_ResultVector, T *n, T *m, int VMHL_N);
template <class T> void TMHL_RandomMatrixOfPermutation(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M);
template <class T> void TMHL_RandomVectorOfPermutation(T *VMHL_ResultVector, int VMHL_N);

//Случайные числа
double MHL_RandomNormal(double Mean, double StdDev);
double MHL_RandomUniform(double a, double b);
int MHL_RandomUniformInt(int n, int m);
int MHL_RandomUniformIntIncluding(int n, int m);

//Сортировка
template <class T> void TMHL_BubbleDescendingSort(T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_BubbleSort(T *VMHL_ResultVector, int VMHL_N);
template <class T> void TMHL_BubbleSortColWithOtherConjugateColsInMatrix(T **VMHL_ResultMatrix,int Col, int VMHL_N, int VMHL_M);
template <class T> void TMHL_BubbleSortEveryColInMatrix(T **VMHL_ResultMatrix,int VMHL_N, int VMHL_M);
template <class T> void TMHL_BubbleSortEveryRowInMatrix(T **VMHL_ResultMatrix,int VMHL_N, int VMHL_M);
template <class T> void TMHL_BubbleSortInGroups(T *VMHL_ResultVector, int VMHL_N, int m);
template <class T> void TMHL_BubbleSortRowWithOtherConjugateRowsInMatrix(T **VMHL_ResultMatrix,int Row, int VMHL_N, int VMHL_M);
template <class T, class T2> void TMHL_BubbleSortWithConjugateVector(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, int VMHL_N);
template <class T, class T2, class T3> void TMHL_BubbleSortWithTwoConjugateVectors(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, T3 *VMHL_ResultVector3, int VMHL_N);

//Статистика и теория вероятности
double MHL_DensityOfDistributionOfNormalizedCenteredNormalDistribution(double x);
double MHL_DistributionFunctionOfNormalDistribution(double x, double mu, double sigma, double Epsilon);
double MHL_DistributionFunctionOfNormalizedCenteredNormalDistribution(double x, double Epsilon);
double MHL_LeftBorderOfWilcoxonWFromTable(int m, int n, double Q);
double MHL_RightBorderOfWilcoxonWFromTable(int m, int n, double Q);
double MHL_StdDevToVariance(double StdDev);
double MHL_VarianceToStdDev(double Variance);
int MHL_WilcoxonW(double *a, double *b, int VMHL_N1, int VMHL_N2, double Q);
template <class T> T TMHL_Mean(T *x, int VMHL_N);
template <class T> T TMHL_Median(T *x, int VMHL_N);
template <class T> T TMHL_SampleCovariance(T *x, T *y, int VMHL_N);
template <class T> T TMHL_Variance(T *x, int VMHL_N);

//Тестовые функции для оптимизации
double MHL_TestFunction_Ackley(double *x, int VMHL_N);
double MHL_TestFunction_AdditivePotential(double x, double y);
double MHL_TestFunction_Himmelblau(double x, double y);
double MHL_TestFunction_HyperEllipsoid(double *x, int VMHL_N);
double MHL_TestFunction_Katnikov(double x, double y);
double MHL_TestFunction_Multiextremal(double x);
double MHL_TestFunction_Multiextremal2(double x);
double MHL_TestFunction_Multiextremal3(double x, double y);
double MHL_TestFunction_Multiextremal4(double x, double y);
double MHL_TestFunction_MultiplicativePotential(double x, double y);
double MHL_TestFunction_ParaboloidOfRevolution(double *x, int VMHL_N);
double MHL_TestFunction_Rana(double x, double y);
double MHL_TestFunction_Rastrigin(double *x, int VMHL_N);
double MHL_TestFunction_ReverseGriewank(double x, double y);
double MHL_TestFunction_Rosenbrock(double *x, int VMHL_N);
double MHL_TestFunction_RotatedHyperEllipsoid(double *x, int VMHL_N);
double MHL_TestFunction_Sombrero(double x, double y);
double MHL_TestFunction_StepFunction(double *x, int VMHL_N);
double MHL_TestFunction_SumVector(int *x, int VMHL_N);
double MHL_TestFunction_Wave(double x);

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

//Уравнения
int MHL_QuadraticEquation(double a, double b, double c, double *x1, double *x2);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Вектора (Одномерные массивы)
//*****************************************************************
template <class T> void TMHL_AcceptanceLimits(T *VMHL_ResultVector, T *Left, T *Right, int VMHL_N)
{
/*
Функция вмещает вектор VMHL_ResultVector в прямоугольную многомерной области,
определяемой левыми границами и правыми границами. Если какая-то координата
вектора выходит за границу, то значение этой координаты принимает граничное значение.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - вектор левых границ;
 Right - вектор правых границ;
 VMHL_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 {
 if (VMHL_ResultVector[i]<Left[i]) VMHL_ResultVector[i]=Left[i];//принятие граничного левого условия
 if (VMHL_ResultVector[i]>Right[i]) VMHL_ResultVector[i]=Right[i];//принятие граничного правого условия
 }
}
//---------------------------------------------------------------------------
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
template <class T> int TMHL_CompareMeanOfVectors(T *a, T *b, int VMHL_N)
{
    /*
Функция проверяет, какой вектор по среднему арифметическому больше.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_N - размер векторов.
Возвращаемое значение:
 0 - вектора совпадают или совпадает среднее арифметическое;
 1 - первый вектор имеет большее значение арифметического среднего;
 2 - второй вектор имеет большее значение арифметического среднего.
Примечание:
 Данную функцию удобно использовать вкупе с функцией MHL_WilcoxonW.
*/
    int VMHL_Result=0;
    for (int i=0;i<VMHL_N;i++)
        if (a[i]!=b[i]) VMHL_Result=-1;

    if (VMHL_Result==-1)
    {
        double Ma=TMHL_SumVector(a,VMHL_N)/double(VMHL_N);
        double Mb=TMHL_SumVector(b,VMHL_N)/double(VMHL_N);

        if (Ma>Mb)
            VMHL_Result=1;
        else
            VMHL_Result=2;
		if (Ma==Mb) VMHL_Result=0;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_CompareMeanOfVectors(T *a, T *b, int VMHL_N1, int VMHL_N2)
{
    /*
Функция проверяет, какой вектор по среднему арифметическому больше.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_N1 - размер вектора a;
 VMHL_N2 - размер вектора b.
Возвращаемое значение:
 0 - вектора совпадают или совпадает среднее арифметическое;
 1 - первый вектор имеет большее значение арифметического среднего;
 2 - второй вектор имеет большее значение арифметического среднего.
Примечание:
 Данную функцию удобно использовать вкупе с функцией MHL_WilcoxonW.
*/
    int VMHL_Result=0;
    if (VMHL_N1==VMHL_N2)
        for (int i=0;i<VMHL_N1;i++)
            if (a[i]!=b[i]) VMHL_Result=-1;
            else
                VMHL_Result=-1;

    if (VMHL_Result==-1)
    {
        double Ma=TMHL_SumVector(a,VMHL_N1)/double(VMHL_N1);
        double Mb=TMHL_SumVector(b,VMHL_N2)/double(VMHL_N2);

        if (Ma>Mb)
            VMHL_Result=1;
        else
            VMHL_Result=2;
		if (Ma==Mb) VMHL_Result=0;
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
bool VMHL_Result=true;
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
template <class T> void TMHL_MixingVector(T *VMHL_ResultVector, double P, int VMHL_N)
{
/*
Функция перемешивает массив. Поочередно рассматриваются номера элементов массивов.
С некоторой вероятностью рассматриваемый элемент массива меняется местами со
случайным элементом массива.
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 P - вероятность того, что элемент массива под рассматриваемым номером поменяется
 местами с каким-нибудь другим элементов (не включая самого себя);
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VMHL_N;i++)
 {
 if (MHL_RandomNumber()<=P)
  {
  j=MHL_RandomUniformInt(0,VMHL_N-1);
  if (j>=i) j++;
  TMHL_NumberInterchange (&VMHL_ResultVector[i],&VMHL_ResultVector[j]); //меняем местами элементы массива
  }
 }
}
//---------------------------------------------------------------------------
template <class T, class T2> void TMHL_MixingVectorWithConjugateVector(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, double P, int VMHL_N)
{
/*
Функция перемешивает массив вместе со сопряженным массивом. Поочередно
рассматриваются номера элементов массивов. С некоторой вероятностью
рассматриваемый элемент массива меняется местами со случайным элементом массива.
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_ResultVector2 - указатель на сопряженный массив;
 P - вероятность того, что элемент массива под рассматриваемым номером поменяется
 местами с каким-нибудь другим элементов (не включая самого себя);
 VMHL_N - количество элементов в массивах.
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VMHL_N;i++)
 {
 if (MHL_RandomNumber()<P)
  {
  j=MHL_RandomUniformInt(0,VMHL_N-1);
  if (j>=i) j++;
  TMHL_NumberInterchange (&VMHL_ResultVector[i],&VMHL_ResultVector[j]);//меняем местами элементы массива
  TMHL_NumberInterchange (&VMHL_ResultVector2[i],&VMHL_ResultVector2[j]);//меняем местами элементы сопряженного массива
  }
 }
}
//---------------------------------------------------------------------------
template <class T> int TMHL_NumberOfDifferentValuesInVector(T *a, int VMHL_N)
{
/*
Функция подсчитывает число различных значений в векторе (одномерном массиве).
Входные параметры:
 a - указатель на вектор;
 VMHL_N - размер массива a.
Возвращаемое значение:
 Число различных значений в векторе.
Примечание:
 Алгоритм очень топорный и медленный.
*/
T *b;
b=new T[VMHL_N];
int VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 if (TMHL_CheckElementInVector(b,VMHL_Result,a[i])==-1)
  {
  b[VMHL_Result]=a[i];
  VMHL_Result++;
  }
delete [] b;
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
template <class T> T TMHL_ProductOfElementsOfVector(T *VMHL_Vector,int VMHL_N)
{
/*
Функция вычисляет произведение элементов вектора.
Входные параметры:
 VMHL_Vector - указатель на исходный массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Произведение элементов массива.
*/
T VMHL_Result=1;
for (int i=0;i<VMHL_N;i++)
    VMHL_Result*=VMHL_Vector[i];

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_ReverseVector(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция меняет порядок элементов в массиве на обратный. Преобразуется подаваемый массив.
Входные параметры:
 VMHL_ResultVector - указатель на преобразуемый массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N/2;i++)
 TMHL_NumberInterchange(&(VMHL_ResultVector[i]),&(VMHL_ResultVector[VMHL_N-i-1]));
}
//---------------------------------------------------------------------------
template <class T> int TMHL_SearchElementInVector (T *X, T x, int VMHL_N)
/*
Функция находит номер первого элемента в массиве, равного данному.
Входные параметры:
 X - исходный массив;
 x - данный элемент;
 VMHL_N - размер массива.
Возвращаемое значение:
 Номер элемента.
Примечание:
 Если такого элемента нет, то возвращает -1.
*/
{
int i=0;

while (i<VMHL_N)
	{
	if (X[i]==x) return (i);//нашли элемент
	i++;
	}
	
return -1;//не нашли
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
//Генетические алгоритмы
//*****************************************************************
template <class T> void TMHL_MutationBinaryMatrix(T **VMHL_ResultMatrix, double ProbabilityOfMutation, int VMHL_N,int VMHL_M)
{
/*
Мутация для бинарной матрицы. Оператор генетического алгоритма.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 ProbabilityOfMutation - вероятность мутации;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
if (ProbabilityOfMutation>1) ProbabilityOfMutation=1;
if (ProbabilityOfMutation<0) ProbabilityOfMutation=0;

for(int i=0;i<VMHL_N;i++)
 for(int j=0;j<VMHL_M;j++)
 if (MHL_RandomNumber()<ProbabilityOfMutation)
  {
  //Инвертируем ген
  if (VMHL_ResultMatrix[i][j]==0) VMHL_ResultMatrix[i][j]=1; else VMHL_ResultMatrix[i][j]=0;
  }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_SinglepointCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N)
{
/*
Одноточечное скрещивание. Оператор генетического алгоритма.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
int i;
int k=MHL_RandomUniformInt(0,2);//0 или 1
int point=MHL_RandomUniformInt(1,VMHL_N);//точка разрыва хромосомы
if (k==0)//какой потомок "выживет": первый вариант или второй
 {
 for (i=0;i<point;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
else
 {
 for (i=0;i<point;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_SinglepointCrossoverWithCopying(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N)
{
/*
Одноточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного одноточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
int i;
int k=MHL_RandomUniformInt(0,2);//0 или 1
int point=MHL_RandomUniformInt(0,VMHL_N+1);//точка разрыва хромосомы
if (k==0)//какой потомок "выживет": первый вариант или второй
 {
 for (i=0;i<point;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
else
 {
 for (i=0;i<point;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_TwopointCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N)
{
/*
Двухточечное скрещивание. Оператор генетического алгоритма.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
int i;
int k=MHL_RandomUniformInt(0,2);//0 или 1
//проводим скрещивание
int point1=MHL_RandomUniformInt(1,VMHL_N);//1 точка разрыва хромосомы
int point2=MHL_RandomUniformInt(1,VMHL_N);//2 точка разрыва хромосомы
//1-ая точка разрыва должна следовать за 2-ой. Поэтому, если это не так,
//то переставляем точки местами функцией TMHL_NumberInterchangeInt
if (point2<point1) TMHL_NumberInterchange(&point1,&point2);
if (k==0)//какой потомок "выживет": первый вариант или второй (зависит от порядка следования родителей)
 {
 for (i=0;i<point1;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point1;i<point2;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point2;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
else
 {
 for (i=0;i<point1;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point1;i<point2;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point2;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_TwopointCrossoverWithCopying(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N)
{
/*
Двухточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного двухточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
int i;
int k=MHL_RandomUniformInt(0,2);//0 или 1
//проводим скрещивание
int point1=MHL_RandomUniformInt(0,VMHL_N+1);//1 точка разрыва хромосомы
int point2=MHL_RandomUniformInt(0,VMHL_N+1);//2 точка разрыва хромосомы
//1-ая точка разрыва должна следовать за 2-ой. Поэтому, если это не так,
//то переставляем точки местами функцией TMHL_NumberInterchangeInt
if (point2<point1) TMHL_NumberInterchange(&point1,&point2);
if (k==0)//какой потомок "выживет": первый вариант или второй (зависит от порядка следования родителей)
 {
 for (i=0;i<point1;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point1;i<point2;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point2;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
else
 {
 for (i=0;i<point1;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point1;i<point2;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point2;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_UniformCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N)
{
/*
Равномерное скрещивание. Оператор генетического алгоритма.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
int i;
int k;
//проводим скрещивание
for (i=0;i<VMHL_N;i++)
 {
 //копируем гены из родителей по порядку с равной вероятностью
 k=MHL_RandomUniformInt(0,2);
 if (k==0) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 if (k==1) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
//---------------------------------------------------------------------------
//*****************************************************************
//Геометрия
//*****************************************************************
template <class T> int TMHL_BoolCrossingTwoSegment(T b1,T c1,T b2,T c2)
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
if (B1>C1) TMHL_NumberInterchange (&B1,&C1);
if (B2>C2) TMHL_NumberInterchange (&B2,&C2);
if (B1>C2)
 {
 TMHL_NumberInterchange (&B1,&B2);
 TMHL_NumberInterchange (&C1,&C2);
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
//Для тестовых функций
//*****************************************************************
//*****************************************************************
//Интегрирование
//*****************************************************************
//*****************************************************************
//Кодирование и декодирование
//*****************************************************************
template <class T> T TMHL_BinaryToDecimal(T *a, int VMHL_N)
{
/*
Функция декодирует двоичное число в десятичное целое неотрицательное.
Входные параметры:
 a - двоичное число;
 VMHL_N - длина двоичного числа.
Возвращаемое значение:
 Число в десятичной системе исчисления.
*/
T VMHL_Result;
VMHL_Result=TMHL_BinaryToDecimalFromPart(a,0,VMHL_N);
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_BinaryToDecimalFromPart(T *a, int Begin, int n)
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
T VMHL_Result=0;
try
 {
 int i=0;
 while (i<=n-1)
  {
  VMHL_Result+=+a[i+Begin]*TMHL_PowerOf(2,n-i-1);
  i++;
  }
 }
catch (...)
 {
 return -1;//Возможно произошло переполнение. Вообщем, ошибка.
 }
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_GrayCodeToBinary(T *a,int *VMHL_ResultVector, int VMHL_N)
{
/*
Функция переводит бинарный код Грея в бинарный код.
Входные параметры:
 a - код Грея (массив заполнен 0 и 1);
 VMHL_N - длина массива a.
Возвращаемое значение:
 Отсутствует.
*/
TMHL_GrayCodeToBinaryFromPart(a,VMHL_ResultVector,0,VMHL_N);
}
//---------------------------------------------------------------------------
template <class T> void TMHL_GrayCodeToBinaryFromPart(T *a, T *VMHL_ResultVector, int Begin, int n)
{
/*
Функция переводит бинарный код Грея в бинарный код.
При этом бинарный код Грея берется как часть некой строки a, заполненной 0 и 1.
Входные параметры:
 a - строка, заполненная 0 и 1;
 VMHL_ResultVector - сюда записывается вектор бинарного числа. Причем запись происходит в те же элементы по номерам, что брались из вектора a, то есть в номера элементов от Begin до Begin+n. Остальные элементы в VMHL_ResultVector не трогаются.
 Begin - номер элемента массива a как начало числа в виде кода Грея (начиная с нуля);
 n - длина числа в виде кода Грея (это не длина вектора a).
Возвращаемое значение:
 Отсутствует.
*/
for (int j=0;j<n;j++)
 {
 if (j==0)
  VMHL_ResultVector[j+Begin]=a[j+Begin];//Первый бит остается прежним
 else
  {
  if (VMHL_ResultVector[j+Begin-1]==0)
   VMHL_ResultVector[j+Begin]=a[j+Begin];//оставляем без изменения
  else
   VMHL_ResultVector[j+Begin]=1-a[j+Begin];//инвертируем
  }
 }
}
//---------------------------------------------------------------------------
//*****************************************************************
//Комбинаторика
//*****************************************************************
template <class T> T TMHL_KCombinations(T k, T n)
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
    if (k>n)  TMHL_NumberInterchange(&n,&k);//n должен быть больше m

    return TMHL_KCombinations(k, n - 1) + TMHL_KCombinations(k - 1, n - 1);
}
//---------------------------------------------------------------------------
//*****************************************************************
//Математические функции
//*****************************************************************
template <class T> T TMHL_Abs(T x)
{
/*
Функция возвращает модуль числа.
Входные параметры:
 x - число.
Возвращаемое значение:
 Модуль числа.
*/
T VMHL_Result;
T MinusOne=-1;
if (x>=0) VMHL_Result=x;
else VMHL_Result=x*MinusOne;
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_Factorial(T x)
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
template <class T> T TMHL_FibonacciNumber(T n)
{
/*
Функция вычисляет число Фибоначчи, заданного номера.
Входные параметры:
 n - номер числа Фибоначчи.
Возвращаемое значение:
 Число Фибоначчи, заданного номера.
*/
T F1,F2,VMHL_Result;

if (n==0) return 0;

if (n>=1)//иницилизация
 {
 VMHL_Result=1;
 F1=1;
 }

if (n>=2) F2=1;

if (n>2)
 {
 for (int i=2;i<n;i++)
  {
  VMHL_Result=F1+F2;//итерационное складывание
  F1=F2;
  F2=VMHL_Result;
  }
 }

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_HeavisideFunction(T x)
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
template <class T> T TMHL_Max(T a, T b)
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
template <class T> T TMHL_Min(T a, T b)
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
template <class T> void TMHL_NumberInterchange(T *a, T *b)
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
template <class T> T TMHL_PowerOf(T x, int n)
{
/*
Функция возводит произвольное число в целую степень.
Входные параметры:
 x - основание степени;
 n - показатель степени.
Возвращаемое значение:
 Cтепень числа.
*/
T VMHL_Result=1;
if (n>0)
 for (int i=0;i<n;i++) VMHL_Result*=x;
if (n<0)
 for (int i=0;i<n;i++) VMHL_Result/=x;
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_Sign(T a)
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
template <class T> int TMHL_SignNull(T a)
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
template <class T> bool TMHL_CheckForIdenticalColsInMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
    /*
Функция проверяет наличие одинаковых столбцов в матрице.
Входные параметры:
 VMHL_ResultMatrix - указатель на массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов);
Возвращаемое значение:
 true - если есть одинаковые столбцы;
 false - если таких столбцы нет.
*/
    bool VMHL_Result=false;
    bool b;
    for (int i=0;i<VMHL_M;i++)
        for (int ii=0;ii<VMHL_M;ii++)
        {
            if (ii!=i)
            {
            b=true;
            for (int j=0;j<VMHL_N;j++)
            {
                if (VMHL_ResultMatrix[j][i]!=VMHL_ResultMatrix[j][ii]) b=false;
            }
            if (b) VMHL_Result=true;
            }
        }
    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> bool TMHL_CheckForIdenticalRowsInMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
    /*
Функция проверяет наличие одинаковых строк в матрице.
Входные параметры:
 VMHL_ResultMatrix - указатель на массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов);
Возвращаемое значение:
 true - если есть одинаковые строки;
 false - если таких строк нет.
*/
    bool VMHL_Result=false;
    bool b;
    for (int i=0;i<VMHL_N;i++)
        for (int ii=0;ii<VMHL_N;ii++)
        {
            if (ii!=i)
            {
            b=true;
            for (int j=0;j<VMHL_M;j++)
            {
                if (VMHL_ResultMatrix[i][j]!=VMHL_ResultMatrix[ii][j]) b=false;
            }
            if (b) VMHL_Result=true;
            }
        }
    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_ColInterchange(T **VMHL_ResultMatrix, int VMHL_N, int k, int l)
{
/*
Функция переставляет столбцы матрицы.
Входные параметры:
 VMHL_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VMHL_N - размер массива (число строки);
 k,l - номера переставляемых столбцов (нумерация с нуля).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 TMHL_NumberInterchange (&(VMHL_ResultMatrix[i][k]),&(VMHL_ResultMatrix[i][l]));
}
//---------------------------------------------------------------------------
template <class T> void TMHL_ColToMatrix(T **VMHL_ResultMatrix, T *b, int VMHL_N, int k)
{
/*
Функция копирует в матрицу (двумерный массив) из вектора столбец.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 b - указатель на вектор;
 VMHL_N - количество строк в матрице и одновременно размер массива b;
 k - номер столбца, в который будет происходить копирование (начиная с 0).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) VMHL_ResultMatrix[i][k]=b[i];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_DeleteColInMatrix(T **VMHL_ResultMatrix, int k, int VMHL_N, int VMHL_M)
{
/*
Функция удаляет k столбец из матрицы (начиная с нуля). Все правостоящие столбцы
сдвигаются влево  на единицу. Последний столбец зануляется.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 k - номер удаляемого столбца;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VMHL_N;i++)
 for (j=k;j<VMHL_M-1;j++)
  VMHL_ResultMatrix[i][j]=VMHL_ResultMatrix[i][j+1];
for (i=0;i<VMHL_N;i++)
 VMHL_ResultMatrix[i][VMHL_M-1]=0;//зануляем
}
//---------------------------------------------------------------------------
template <class T> void TMHL_DeleteRowInMatrix(T **VMHL_ResultMatrix, int k, int VMHL_N, int VMHL_M)
{
/*
Функция удаляет k строку из матрицы (начиная с нуля). Все нижестоящие строки поднимаются на единицу.
Последняя строка зануляется.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 k - номер удаляемой строки;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=k;i<VMHL_N-1;i++)
 for (j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=VMHL_ResultMatrix[i+1][j];
for (j=0;j<VMHL_M;j++)
 VMHL_ResultMatrix[VMHL_N-1][j]=0;//зануляем
}
//---------------------------------------------------------------------------
template <class T> bool TMHL_EqualityOfMatrixes (T **a, T **b,int VMHL_N,int VMHL_M)
{
/*
Функция проверяет равенство матриц.
Входные параметры:
 a - указатель на первую матрицу;
 b - указатель на вторую матрицу;
 VMHL_N - размер массива a (число строк);
 VMHL_M - размер массива a (число столбцов).
Возвращаемое значение:
 true - матрицы совпадают;
 false - матрицы не совпадают.
*/
bool VMHL_Result=true;

for (int i=0;i<VMHL_N;i++)
    for (int j=0;j<VMHL_M;j++)
        if (a[i][j]!=b[i][j])
            VMHL_Result=false;

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_FillMatrix(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, T x)
{
/*
Функция заполняет матрицу значениями, равных x.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов);
 x - число, которым заполняется вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=x;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_IdentityMatrix(T **VMHL_ResultMatrix,int VMHL_N)
{
/*
Функция формирует единичную квадратную матрицу.
Входные параметры:
 VMHL_ResultMatrix - исходная матрица (в ней и сохраняется результат);
 VMHL_N - размер матрицы (число строк и столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_N;j++)
  {
  if (i==j)
   VMHL_ResultMatrix[i][j]=1;
  else
   VMHL_ResultMatrix[i][j]=0;
  }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixMinusMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция вычитает две матрицы.
Входные параметры:
 a - первая матрица;
 b - вторая матрица;
 VMHL_ResultMatrix - разница матриц;
 VMHL_N - размер матриц (число строк);
 VMHL_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=a[i][j]-b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixMinusMatrix(T **VMHL_ResultMatrix, T **b, int VMHL_N, int VMHL_M)
{
/*
Функция вычитает два матрицы и результат записывает в первую матрицу.
Входные параметры:
 VMHL_ResultMatrix - первая матрица (в ней и сохраняется разница);
 b - вторая матрица;
 VMHL_N - размер матриц (число строк);
 VMHL_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]-=b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixMultiplyMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S)
{
/*
Функция перемножает матрицы.
Входные параметры:
 a - первый сомножитель, VMHL_N x VMHL_M;
 b - второй сомножитель, VMHL_M x VMHL_S;
 VMHL_ResultMatrix - произведение матриц (сюда записывается результат), VMHL_N x VMHL_S;
 VMHL_N - число строк в матрице a;
 VMHL_M - число столбцов в матрице a и строк в матрице b;
 VMHL_S - число столбцов в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VMHL_N;i++)
 for (k=0;k<VMHL_S;k++)
  {
  w=0;
  for (j=0;j<VMHL_M;j++) w+=a[i][j]*b[j][k];
  VMHL_ResultMatrix[i][k]=w;
  }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixMultiplyMatrixT(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S)
{
/*
Функция умножает матрицу на транспонированную матрицу.
Входные параметры:
 a - первый сомножитель, VMHL_N x VMHL_M;
 b - второй сомножитель (матрица, которую мы транспонируем), VMHL_S x VMHL_M;
 VMHL_ResultMatrix - произведение матриц (сюда записывается результат), VMHL_N x VMHL_S;
 VMHL_N - число строк в матрице a;
 VMHL_M - число столбцов в матрице a и столбцов в матрице b;
 VMHL_S - число строк в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VMHL_N;i++)
 for (k=0;k<VMHL_S;k++)
  {
  w=0;
  for (j=0;j<VMHL_M;j++) w=w+a[i][j]*b[k][j];
  VMHL_ResultMatrix[i][k]=w;
  }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixMultiplyNumber(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, T Number)
{
/*
Функция умножает матрицу на число.
Входные параметры:
 VMHL_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VMHL_N - размер матрицы (число строк);
 VMHL_M - размер матрицы (число столбцов);
 Number - число, на которое умножается матрица.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]*=Number;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixPlusMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция суммирует две матрицы.
Входные параметры:
 a - первая матрица;
 b - вторая матрица;
 VMHL_ResultMatrix - сумма матриц;
 VMHL_N - размер матриц (число строк);
 VMHL_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=a[i][j]+b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixPlusMatrix(T **VMHL_ResultMatrix, T **b, int VMHL_N, int VMHL_M)
{
/*
Функция суммирует два матрицы и результат записывает в первую матрицу.
Входные параметры:
 VMHL_ResultMatrix - первая матрица (в ней и сохраняется сумма);
 b - вторая матрица;
 VMHL_N - размер матриц (число строк);
 VMHL_M - размер матриц (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]+=b[i][j];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixT(T **a, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция транспонирует матрицу.
Входные параметры:
 a - исходная матрица, (VMHL_N x VMHL_M);
 VMHL_ResultMatrix - транспонированная матрица, (VMHL_M x VMHL_N);
 VMHL_N - размер матрицы (число строк) в матрице a;
 VMHL_M - размер матрицы (число столбцов) в матрице a.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[j][i]=a[i][j];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixTMultiplyMatrix(T **a, T **b, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M, int VMHL_S)
{
/*
Функция умножает транспонированную матрицу на матрицу.
Входные параметры:
 a - первый сомножитель (матрица, которую мы транспонируем), VMHL_M x VMHL_N;
 b - второй сомножитель, VMHL_M x VMHL_S;
 VMHL_ResultMatrix - произведение матриц (сюда записывается результат), VMHL_N x VMHL_S;
 VMHL_N - число столбцов в матрице a;
 VMHL_M - число строк в матрице a и строк в матрице b;
 VMHL_S - число столбцов в матрице b.
Возвращаемое значение:
 Отсутствует.
*/
T w;
int i,j,k;
for (i=0;i<VMHL_N;i++)
 for (k=0;k<VMHL_S;k++)
  {
  w=0;
  for (j=0;j<VMHL_M;j++) w=w+a[j][i]*b[j][k];
  VMHL_ResultMatrix[i][k]=w;
  }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixToCol(T **a, T *VMHL_ResultVector, int VMHL_N, int k)
{
/*
Функция копирует из матрицы (двумерного массива) в вектор столбец.
Входные параметры:
 a - указатель на матрицу;
 VMHL_ResultVector - указатель на вектор;
 VMHL_N - количество строк в матрице и одновременно размер массива b;
 k - номер копируемого столбца (начиная с 0).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=a[i][k];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixToMatrix(T **a, T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция копирует содержимое матрицы (двумерного массива) a в массив VMHL_ResultMatrix.
Входные параметры:
 a - указатель на исходный массив;
 VMHL_ResultMatrix - указатель на массив в который производится запись;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=a[i][j];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MatrixToRow(T **a, T *VMHL_ResultVector, int k, int VMHL_M)
{
/*
Функция копирует из матрицы (двумерного массива) в вектор строку.
Входные параметры:
 a - указатель на матрицу;
 VMHL_ResultVector - указатель на вектор;
 k - номер копируемой строки (начиная с 0);
 VMHL_M - количество столбцов в матрице и одновременно размер массива VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_M;i++) VMHL_ResultVector[i]=a[k][i];
}
//---------------------------------------------------------------------------
template <class T> T TMHL_MaximumOfMatrix(T **a, int VMHL_N, int VMHL_M)
{
/*
Функция ищет максимальный элемент в матрице (двумерном массиве).
Входные параметры:
 a - указатель на матрицу;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Максимальный элемент.
*/
T VMHL_Result;
VMHL_Result=a[0][0];
for (int i=1;i<VMHL_N;i++)
 for (int j=1;j<VMHL_M;j++)
  if (a[i][j]>VMHL_Result) VMHL_Result=a[i][j];
  
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_MinimumOfMatrix(T **a, int VMHL_N, int VMHL_M)
{
/*
Функция ищет минимальный элемент в матрице (двумерном массиве).
Входные параметры:
 a - указатель на матрицу;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Минимальный элемент.
*/
T VMHL_Result;
VMHL_Result=a[0][0];
for (int i=1;i<VMHL_N;i++)
 for (int j=1;j<VMHL_M;j++)
  if (a[i][j]<VMHL_Result) VMHL_Result=a[i][j];
  
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_MixingRowsInOrder(T **VMHL_ResultMatrix, int *b, int VMHL_N, int VMHL_M)
{
/*
Функция меняет строки матрицы в порядке, указанным в массиве b.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, в которой меняем порядок строк;
 b - вектор, в котором записаны номера, под которыми должны стать строки в матрице (от 0 до VMHL_N-1);
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
T **c;//Временный массив
c=new T*[VMHL_N];
for (i=0;i<VMHL_N;i++) c[i]=new T[VMHL_M];

//Записываем в массив c в новом порядке
for (i=0;i<VMHL_N;i++)
 for (j=0;j<VMHL_M;j++)
  c[b[i]][j]=VMHL_ResultMatrix[i][j];

//Заменяем основной массив промежуточным
TMHL_MatrixToMatrix(c,VMHL_ResultMatrix,VMHL_N,VMHL_M);

for (i=0;i<VMHL_N;i++) delete[] c[i];
delete[] c;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_NumberOfDifferentValuesInMatrix(T **a, int VMHL_N, int VMHL_M)
{
/*
Функция подсчитывает число различных значений в матрице.
Входные параметры:
 a - указатель на матрица;
 VMHL_N - размер массива a (строки);
 VMHL_M - размер массива a (столбцы).
Возвращаемое значение:
 Число различных значений в матрице.
Примечание:
 Алгоритм очень топорный и медленный.
*/
T *b;
b=new T[VMHL_N*VMHL_M];
int VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  if (TMHL_CheckElementInVector(b,VMHL_Result,a[i][j])==-1)
   {
   b[VMHL_Result]=a[i][j];
   VMHL_Result++;
   }
delete [] b;
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RowInterchange(T **VMHL_ResultMatrix, int VMHL_M, int k, int l)
{
/*
Функция переставляет строки матрицы.
Входные параметры:
 VMHL_ResultMatrix - указатель на исходную матрицу (в ней и сохраняется результат);
 VMHL_M - размер массива (число столбцов);
 k,l - номера переставляемых строк (нумерация с нуля).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_M;i++)
 TMHL_NumberInterchange (&(VMHL_ResultMatrix[k][i]),&(VMHL_ResultMatrix[l][i]));
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RowToMatrix(T **VMHL_ResultMatrix, T *b, int k, int VMHL_M)
{
/*
Функция копирует в матрицу (двумерный массив) из вектора строку.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 b - указатель на вектор;
 k - номер строки, в которую будет происходить копирование (начиная с 0);
 VMHL_M - количество столбцов в матрице и одновременно размер массива b.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_M;i++) VMHL_ResultMatrix[k][i]=b[i];
}
//---------------------------------------------------------------------------
template <class T> T TMHL_SumMatrix(T **a,int VMHL_N,int VMHL_M)
{
/*
Функция вычисляет сумму элементов матрицы.
Входные параметры:
 a - указатель на исходный массив;
 VMHL_N - размер массива a (число строк);
 VMHL_M - размер массива a (число столбцов).
Возвращаемое значение:
 Сумма элементов матрицы.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_Result+=a[i][j];
  
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> void TMHL_ZeroMatrix(T **VMHL_ResultMatrix,int VMHL_N,int VMHL_M)
{
/*
Функция зануляет матрицу.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=0;//зануляем
}
//---------------------------------------------------------------------------
//*****************************************************************
//Метрика
//*****************************************************************
template <class T> T TMHL_Chebychev(T *x, T *y, int VMHL_N)
{
/*
Функция вычисляет расстояние Чебышева.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Значение метрики расстояние Чебышева.
*/
T VMHL_Result=0;
T Temp;
for (int i=0;i<VMHL_N;i++)
 {
 Temp=TMHL_Abs(x[i]-y[i]);
 if (Temp>VMHL_Result) VMHL_Result=Temp;
}
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_CityBlock(T *x, T *y, int VMHL_N)
{
/*
Функция вычисляет манхэттенское расстояние между двумя массивами.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Значение метрики манхэттенское расстояние.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 VMHL_Result+=TMHL_Abs(x[i]-y[i]);
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_Euclid(T *x, T *y, int VMHL_N)
{
/*
Функция вычисляет евклидово расстояние.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Значение метрики евклидово расстояние.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 VMHL_Result+=(x[i]-y[i])*(x[i]-y[i]);
VMHL_Result=sqrt(VMHL_Result);
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_Minkovski(T *x, T *y, int r, int VMHL_N)
{
/*
Функция вычисляет метрику Минковского.
Входные параметры:
 x - указатель на первый вектор;
 y - указатель на второй вектор;
 r - порядок метрики;
 VMHL_N - размер массивов.
Возвращаемое значение:
 Значение метрики Минковского.
*/
T VMHL_Result=0;
for (int i=0;i<VMHL_N;i++)
 {
 VMHL_Result+=pow(fabs(x[i]-y[i]),r);
}
VMHL_Result=pow(VMHL_Result,1./double(r));

return VMHL_Result;
}
//---------------------------------------------------------------------------
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
template <class T> void TMHL_BernulliVector(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция формирует случайный вектор Бернулли.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VMHL_N;i++)
 {
 if (MHL_RandomNumber()<0.5)
  VMHL_ResultVector[i]=-1.;
 else
  VMHL_ResultVector[i]=1.;
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomArrangingObjectsIntoBaskets(T *VMHL_ResultVector, int N, int VMHL_N)
{
/*
Функция предлагает случайный способ расставить N объектов в VMHL_N корзин при условии, что
в каждой корзине может располагаться только один предмет.
Входные параметры:
 VMHL_ResultVector - массив, в который записывается результат;
 N - число предметов;
 VMHL_N - размер массива (и число корзин).
Возвращаемое значение:
 Отсутствует.
Примечание:
 В VMHL_ResultVector 0 удет означать отсутствие предмета, 1 - наличие.
*/
if (N<0) N=0;// должен быть хотя бы один предмет
if (N>VMHL_N) N=VMHL_N;

int j;//Счетчик
int p;//Текущее число свободнных участников
int r;//случайное число для определения победителя
int g=0;//Номер выбранного участника

TMHL_ZeroVector(VMHL_ResultVector,VMHL_N);// Пока никого

if (N>0)
 {//Если есть хотя бы один предмет
 r=MHL_RandomUniformInt(0,VMHL_N);
 VMHL_ResultVector[r]=1;//отметили первую корзину

 for (int i=1;i<N;i++)
  {//выбор еще одной корзины
  r=MHL_RandomUniformInt(0,VMHL_N-i);//на один меньше можно выбрать, чем в предыдущий раз
  p=0;//Текущее число свободных корзин
  j=0;//Счетчик

  while (p!=r+1)
   {
   //Ищем нашу корзину
   if (VMHL_ResultVector[j]==0)
    {
    //Нашли свободную корзину. Возможно это наша.
    p++;
    g=j;
    }
   j++;
   }

  //Теперь g - номер нашей корзины
  VMHL_ResultVector[g]=1;//Поместим предмет
  }//выбор еще одной корзины
 }//Если есть хотя бы один предмет
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomBinaryMatrix(T **VMHL_ResultMatrix,int VMHL_N,int VMHL_M)
{
/*
Функция заполняет матрицу случайно нулями и единицами.
Входные параметры:
 VMHL_ResultMatrix - указатель на преобразуемый массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк);
 VMHL_M - размер массива VMHL_ResultMatrix (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VMHL_N;i++)
 for(int j=0;j<VMHL_M;j++)
  {
  if (MHL_RandomNumber()<0.5)
   VMHL_ResultMatrix[i][j]=0;
  else
   VMHL_ResultMatrix[i][j]=1;
  }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomBinaryVector(T *VMHL_ResultVector,int VMHL_N)
{
/*
Функция заполняет вектор (одномерный массив) случайно нулями и единицами.
Входные параметры:
 VMHL_ResultVector - указатель на преобразуемый массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк).
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VMHL_N;i++)
 {
 if (MHL_RandomNumber()<0.5)
  VMHL_ResultVector[i]=0;
 else
  VMHL_ResultVector[i]=1;
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomIntMatrix(T **VMHL_ResultMatrix, T n, T m, int VMHL_N, int VMHL_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 n - левая граница интервала;
 m - правая граница интервала;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=MHL_RandomUniformInt(n,m);
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomIntMatrixInCols(T **VMHL_ResultMatrix, T *n, T *m, int VMHL_N, int VMHL_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
При этом элементы каждого столбца изменяются в своих пределах.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 n - левые границы интервала изменения элементов столбцов (размер VMHL_M);
 m - правые границы интервала изменения элементов столбцов (размер VMHL_M);
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=MHL_RandomUniformInt(n[j],m[j]);
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomIntMatrixInElements(T **VMHL_ResultMatrix, T **n, T **m, int VMHL_N, int VMHL_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
При этом каждый элемент изменяется в своих пределах.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 n - левые границы интервала изменения каждого элемента (размер VMHL_N x VMHL_M);
 m - правые границы интервала изменения каждого элемента (размер VMHL_N x VMHL_M);
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=MHL_RandomUniformInt(n[i][j],m[i][j]);
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomIntMatrixInRows(T **VMHL_ResultMatrix, T *n, T *m, int VMHL_N, int VMHL_M)
{
/*
Функция заполняет матрицу случайными целыми числами из определенного интервала [n;m).
При этом элементы каждой строки изменяются в своих пределах.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 n - левые границы интервала изменения элементов строки (размер VMHL_N);
 m - правые границы интервала изменения элементов строки (размер VMHL_N);
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 for (int j=0;j<VMHL_M;j++)
  VMHL_ResultMatrix[i][j]=MHL_RandomUniformInt(n[i],m[i]);
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomIntVector(T *VMHL_ResultVector, T n, T m, int VMHL_N)
{
/*
Функция заполняет массив случайными целыми числами из определенного интервала [n,m).
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 n - левая граница интервала;
 m - правая граница интервала;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 VMHL_ResultVector[i]=MHL_RandomUniformInt(int(n),int(m));
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomIntVectorInElements(T *VMHL_ResultVector, T *n, T *m, int VMHL_N)
{
/*
Функция заполняет массив случайными целыми  числами из определенного интервала [n_i,m_i). При этом для каждого элемента массива свой интервал изменения.
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 n - указатель на массив левых границ интервала;
 m - указатель на массив правых границ интервала;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 VMHL_ResultVector[i]=MHL_RandomUniform(int(n[i]),int(m[i]));
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomMatrixOfPermutation(T **VMHL_ResultMatrix, int VMHL_N, int VMHL_M)
{
/*
Функция создает случайный массив строк-перестановок чисел от 1 до VMHL_M.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу;
 VMHL_N - размер массива (число строк);
 VMHL_M - размер массива (число столбцов).
Возвращаемое значение:
 Отсутствует.
*/
T MOne=-1;
int i, j, b1, b2, randomall;
TMHL_FillMatrix (VMHL_ResultMatrix,VMHL_N,VMHL_M,MOne);
for (j=0;j<VMHL_N;j++)
 {
 for (i=0;i<VMHL_M;i++)
  {//начало заполнения цифрами
  randomall=MHL_RandomUniformInt(0,VMHL_M-i)+1;
  b1=0;
  b2=0;
  while (b1<randomall)
   {
   if (VMHL_ResultMatrix[j][b2]==-1) b1=b1+1;
   b2=b2+1;
   }
  VMHL_ResultMatrix[j][b2-1]=i+1;
  }//конец заполнения цифрами
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_RandomVectorOfPermutation(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция создает случайную строку-перестановку чисел от 1 до VMHL_N (включительно).
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T MOne=-1;
int i, b1, b2, randomall;
TMHL_FillVector (VMHL_ResultVector,VMHL_N,MOne);
for (i=0;i<VMHL_N;i++)
 {//начало заполнения цифрами
 randomall=MHL_RandomUniformInt(0,VMHL_N-i)+1;
 b1=0;
 b2=0;
 while (b1<randomall)
  {
  if (VMHL_ResultVector[b2]==-1) b1=b1+1;
  b2=b2+1;
  }
 VMHL_ResultVector[b2-1]=i+1;
 }//конец заполнения цифрами
}
//---------------------------------------------------------------------------
//*****************************************************************
//Случайные числа
//*****************************************************************
//*****************************************************************
//Сортировка
//*****************************************************************
template <class T> void TMHL_BubbleDescendingSort(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция сортирует массив в порядке убывания методом "Сортировка пузырьком".
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_N - количество элементов в массиве.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VMHL_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VMHL_ResultVector[j]<VMHL_ResultVector[j+1])
   TMHL_NumberInterchange(&(VMHL_ResultVector[j]),&(VMHL_ResultVector[j+1]));
}
//---------------------------------------------------------------------------
template <class T> void TMHL_BubbleSort(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция сортирует массив в порядке возрастания методом "Сортировка пузырьком".
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_N - количество элементов в массиве.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VMHL_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VMHL_ResultVector[j]>VMHL_ResultVector[j+1])
   TMHL_NumberInterchange(&(VMHL_ResultVector[j]),&(VMHL_ResultVector[j+1]));
}
//---------------------------------------------------------------------------
template <class T> void TMHL_BubbleSortColWithOtherConjugateColsInMatrix(T **VMHL_ResultMatrix,int Col, int VMHL_N, int VMHL_M)
{
/*
Функция сортирует матрицу по какому-то столбцу под номером в порядке возрастания методом "Сортировка пузырьком".
При этом все остальные столбцы являются как бы сопряженным с данным столбцом. То есть элементы в этом столбце сортируются,
а все строки остаются прежними.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, которую будем сортировать;
 Col - номер сортируемого столбца в матрице;
 VMHL_N - количество строк в матрице;
 VMHL_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for(i=VMHL_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(VMHL_ResultMatrix[j][Col]>VMHL_ResultMatrix[j+1][Col])
            {
                for (k=0;k<VMHL_M;k++)
                    TMHL_NumberInterchange(&(VMHL_ResultMatrix[j][k]),&(VMHL_ResultMatrix[j+1][k]));
            }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_BubbleSortEveryColInMatrix(T **VMHL_ResultMatrix,int VMHL_N, int VMHL_M)
{
/*
Функция сортирует каждый столбец матрицы в отдельности.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, которую будем сортировать;
 VMHL_N - количество строк в матрице;
 VMHL_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for (k=0;k<VMHL_M;k++)
    {
        for(i=VMHL_N-1;i>0;i--)
            for(j=0;j<i;j++)
                if(VMHL_ResultMatrix[j][k]>VMHL_ResultMatrix[j+1][k])
                {
                    TMHL_NumberInterchange(&(VMHL_ResultMatrix[j][k]),&(VMHL_ResultMatrix[j+1][k]));
                }
    }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_BubbleSortEveryRowInMatrix(T **VMHL_ResultMatrix,int VMHL_N, int VMHL_M)
{
/*
Функция сортирует каждую строку матрицы в отдельности.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, которую будем сортировать;
 VMHL_N - количество строк в матрице;
 VMHL_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for (k=0;k<VMHL_N;k++)
    {
        for(i=VMHL_M-1;i>0;i--)
            for(j=0;j<i;j++)
                if(VMHL_ResultMatrix[k][j]>VMHL_ResultMatrix[k][j+1])
                {
                    TMHL_NumberInterchange(&(VMHL_ResultMatrix[k][j]),&(VMHL_ResultMatrix[k][j+1]));
                }
    }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_BubbleSortInGroups(T *VMHL_ResultVector, int VMHL_N, int m)
{
/*
Функция сортирует массив в порядке возрастания методом "Сортировка пузырьком" в группах данного массива.
Имеется массив. Он делится на группы элементов по m элементов. Первые m
элементов принадлежат первой группе, следующие m элементов - следующей и т.д.
(Разумеется, в последней группе может и не оказаться m элементов).
Потом в каждой группе элементы сортируются по возрастанию.
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_N - количество элементов в массиве;
 m - количество элементов в группе.
*/
int i,j,k,N,M;
N=int(VMHL_N/m);//число групп
for (k=0;k<N;k++)
 {
 for(i=m-1;i>0;i--)
  for(j=0;j<i;j++)
   if(VMHL_ResultVector[k*m+j]>VMHL_ResultVector[k*m+j+1])
    TMHL_NumberInterchange(&(VMHL_ResultVector[k*m+j]),&(VMHL_ResultVector[k*m+j+1]));
 }
M=VMHL_N%m;
if (M!=0)//если есть последняя неполная группа
 {
 for(i=M-1;i>0;i--)
  for(j=0;j<i;j++)
   if(VMHL_ResultVector[N*m+j]>VMHL_ResultVector[N*m+j+1])
    TMHL_NumberInterchange(&(VMHL_ResultVector[N*m+j]),&(VMHL_ResultVector[N*m+j+1]));
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_BubbleSortRowWithOtherConjugateRowsInMatrix(T **VMHL_ResultMatrix,int Row, int VMHL_N, int VMHL_M)
{
/*
Функция сортирует матрицу по какой-то строке под номером в порядке возрастания методом "Сортировка пузырьком".
При этом все остальные строки являются как бы сопряжеными с данной строкой. То есть элементы в этой строке сортируются,
а все столбцы остаются прежними.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, которую будем сортировать;
 Row - номер сортируемой строки в матрице;
 VMHL_N - количество строк в матрице;
 VMHL_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for(i=VMHL_M-1;i>0;i--)
        for(j=0;j<i;j++)
            if(VMHL_ResultMatrix[Row][j]>VMHL_ResultMatrix[Row][j+1])
            {
                for (k=0;k<VMHL_N;k++)
                    TMHL_NumberInterchange(&(VMHL_ResultMatrix[k][j]),&(VMHL_ResultMatrix[k][j+1]));
            }
}
//---------------------------------------------------------------------------
template <class T, class T2> void TMHL_BubbleSortWithConjugateVector(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, int VMHL_N)
{
/*
Функция сортирует массив вместе с сопряженный массивом в порядке возрастания методом "Сортировка пузырьком".
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_ResultVector2 - указатель на сопряженный массив;
 VMHL_N - количество элементов в массиве.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VMHL_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VMHL_ResultVector[j]>VMHL_ResultVector[j+1])
   {
   TMHL_NumberInterchange(&(VMHL_ResultVector[j]),&(VMHL_ResultVector[j+1]));
   TMHL_NumberInterchange(&(VMHL_ResultVector2[j]),&(VMHL_ResultVector2[j+1]));
   }
}
//---------------------------------------------------------------------------
template <class T, class T2, class T3> void TMHL_BubbleSortWithTwoConjugateVectors(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, T3 *VMHL_ResultVector3, int VMHL_N)
{
/*
Функция сортирует массив вместе с двумя сопряженными массивами в порядке возрастания методом "Сортировка пузырьком".
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_ResultVector2 - указатель на сопряженный массив;
 VMHL_ResultVector3 - указатель на второй сопряженный массив;
 VMHL_N - количество элементов в массивах.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VMHL_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VMHL_ResultVector[j]>VMHL_ResultVector[j+1])
   {
   TMHL_NumberInterchange(&(VMHL_ResultVector[j]),&(VMHL_ResultVector[j+1]));
   TMHL_NumberInterchange(&(VMHL_ResultVector2[j]),&(VMHL_ResultVector2[j+1]));
   TMHL_NumberInterchange(&(VMHL_ResultVector3[j]),&(VMHL_ResultVector3[j+1]));
   }
}
//---------------------------------------------------------------------------
//*****************************************************************
//Статистика и теория вероятности
//*****************************************************************
template <class T> T TMHL_Mean(T *x, int VMHL_N)
{
/*
Функция вычисляет среднее арифметическое массива.
Входные параметры:
 x - массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Среднее арифметическое массива.
Примечание:
 Если будете считать для массива *int, то ответ будет некорректным, так как ответ возвратиться тоже в виде int.
*/
return TMHL_SumVector(x,VMHL_N)/double(VMHL_N);
}
//---------------------------------------------------------------------------
template <class T> T TMHL_Median(T *x, int VMHL_N)
{
/*
Функция вычисляет медиану выборки.
Входные параметры:
 x - указатель на исходную выборку;
 VMHL_N - размер массива.
Возвращаемое значение:
 Медиана массива.
*/
T VMHL_Result;
T *SortVector;
T Two=2;
SortVector=new T[VMHL_N];//Нам нужно отсортировать массив, но не трогая этот
TMHL_VectorToVector(x,SortVector,VMHL_N);

TMHL_BubbleSort(SortVector,VMHL_N);//отсортируем массив

if (MHL_Parity(VMHL_N)==0)//Если число элементов нечетно
 VMHL_Result=SortVector[VMHL_N/2];
else//Если число элементов четно
 VMHL_Result=(SortVector[VMHL_N/2-1]+SortVector[VMHL_N/2])/Two;
delete [] SortVector;

return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_SampleCovariance(T *x, T *y, int VMHL_N)
{
/*
Функция вычисляет выборочную ковариацию выборки (несмещенная, исправленная).
Входные параметры:
 x - указатель на первую сравниваемую выборки;
 y - указатель на вторую сравниваемую выборки;
 VMHL_N - размер массивов.
Выходной параметр:
 Значение выборочной ковариации.
*/
T xn,yn;
T VMHL_Result=0;

//Найдем среднее арифметические двух выборок
xn=TMHL_Mean(x,VMHL_N);
yn=TMHL_Mean(x,VMHL_N);

for(int i=0;i<VMHL_N;i++)
 VMHL_Result+=(x[i]-xn)*(y[i]-yn);

VMHL_Result/=VMHL_N-1;
return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> T TMHL_Variance(T *x, int VMHL_N)
{
/*
Функция вычисляет выборочную дисперсию выборки (несмещенная, исправленная).
Входные параметры:
 x - указатель на исходную выборку;
 VMHL_N - размер массива.
Возвращаемое значение:
 Выборочная дисперсия выборки.
*/
return TMHL_SampleCovariance(x,x,VMHL_N);
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

#endif // HARRIXMATHLIBRARY_H