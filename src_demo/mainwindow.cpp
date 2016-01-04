#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "HarrixMathLibrary.h"
#include "HarrixQtLibraryForQWebView.h"
#include "HarrixQtLibrary.h"

using namespace MyNamespace;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DS=QDir::separator();//какой разделитель используется в пути между папками
    Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
    HQt_BeginHtml(Path);
    ui->webView->setUrl(QUrl::fromLocalFile(Path+"index.html"));// и в webViewотображаем index.html (его вообще не трогаем)

    HML_SeedRandom();//Инициализация датчика случайных чисел

    model = new QStandardItemModel(this);
    model->setObjectName(QString::fromUtf8("model"));

    QStandardItem *item;//элемент списка

    //добавление новых элементов

    //Сюда нужно добавить код

    item = new QStandardItem(QString("HML_FillVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MaximumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MinimumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SumVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SumSquareVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ZeroVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_VectorToVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DegToRad"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RadToDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BitNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomRealMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomUniform"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomNormal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomUniformInt"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomRealMatrixInCols"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomRealMatrixInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomRealMatrixInRows"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomRealVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomRealVectorInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomVectorOfProbability"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Cos"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CosDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Cosec"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CosecDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Cotan"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CotanDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Sec"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SecDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Sin"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SinDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Tan"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TanDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_OrdinalVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_OrdinalVectorZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SearchFirstNotZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SearchFirstZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_VectorMinusVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_VectorPlusVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_VectorMultiplyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Cosech"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Cosh"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Cotanh"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Sech"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Sinh"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Tanh"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberOfMaximumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberOfMinimumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberOfNegativeValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberOfPositiveValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberOfZeroValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_FibonacciNumbersVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_EqualityOfVectors"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CheckElementInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Max"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Min"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Abs"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberInterchange"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Sign"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SignNull"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SumOfDigits"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ZeroMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SumMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MaximumOfMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MinimumOfMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_FillMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixMinusMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixPlusMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixMultiplyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixT"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixMultiplyMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixMultiplyMatrixT"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixTMultiplyMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomIntMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomIntMatrixInCols"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomIntMatrixInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomIntMatrixInRows"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomIntVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomIntVectorInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomBinaryMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomBinaryVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BernulliVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomArrangingObjectsIntoBaskets"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ColInterchange"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ColToMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DeleteColInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DeleteRowInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixToCol"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixToMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MatrixToRow"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RowInterchange"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RowToMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberOfDifferentValuesInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_IdentityMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MixingVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ReverseVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NumberOfDifferentValuesInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_PowerOf"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Parity"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ArithmeticalProgression"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GeometricSeries"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GreatestCommonDivisorEuclid"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_LeastCommonMultipleEuclid"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_HowManyPowersOfTwo"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SumGeometricSeries"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SumOfArithmeticalProgression"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_FibonacciNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BoolCrossingTwoSegment"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AcceptanceLimits"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NoiseInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_EuclidNorma"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MixingVectorWithConjugateVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MixingRowsInOrder"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Chebychev"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CityBlock"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Euclid"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RightDerivative"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CenterDerivative"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_LeftDerivative"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_IntegralOfTrapezium"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_IntegralOfSimpson"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_IntegralOfRectangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_HeavisideFunction"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ExpMSxD2"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NormalizationNumberAll"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_InverseNormalizationNumberAll"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryMonteCarloAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleDescendingSort"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleSort"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleSortInGroups"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleSortWithConjugateVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleSortWithTwoConjugateVectors"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DensityOfDistributionOfNormalizedCenteredNormalDistribution"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DistributionFunctionOfNormalizedCenteredNormalDistribution"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_StdDevToVariance"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_VarianceToStdDev"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Mean"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Median"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SampleCovariance"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Variance"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SinglepointCrossover"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TwopointCrossover"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_UniformCrossover"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryToDecimalFromPart"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryToDecimal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryVectorToRealVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GrayCodeToBinaryFromPart"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GrayCodeToBinary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryGrayVectorToRealVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomVectorOfPermutation"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomMatrixOfPermutation"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MutationBinaryMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TournamentSelectionWithReturn"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TournamentSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MakeVectorOfRankForRankSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NormalizationVectorOne"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NormalizationVectorMaxMin"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NormalizationVectorAll"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MakeVectorOfProbabilityForProportionalSelectionV2"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SelectItemOnProbability"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ProportionalSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ProportionalSelectionV2"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ProportionalSelectionV3"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RankSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_StandartBinaryGeneticAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_StandartRealGeneticAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_StandartGeneticAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Ackley"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_ParaboloidOfRevolution"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Rastrigin"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Rosenbrock"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_SumVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Factorial"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_KCombinations"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ProbabilityOfTournamentSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MakeVectorOfProbabilityForRanklSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MakeVectorOfRankZeroForRankSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RandomUniformIntIncluding"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleSortRowWithOtherConjugateRowsInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleSortEveryRowInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleSortColWithOtherConjugateColsInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BubbleSortEveryColInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_QuadraticEquation"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BellShapedKernelExp"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BellShapedKernelParabola"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BellShapedKernelRectangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BellShapedKernelTriangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DerivativeOfBellShapedKernelExp"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DerivativeOfBellShapedKernelParabola"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DerivativeOfBellShapedKernelRectangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DerivativeOfBellShapedKernelTriangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TrapeziformFuzzyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ProductOfElementsOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MixedMultiLogicVectorOfFullSearch"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SearchElementInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_EqualityOfMatrixes"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DependentNoiseInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Minkovski"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RealMonteCarloAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DichotomyOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_FibonacciOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GoldenSectionOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_QuadraticFitOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RealMonteCarloOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_UniformSearchOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_UniformSearchOptimizationN"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CheckForIdenticalRowsInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CheckForIdenticalColsInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_LeftBorderOfWilcoxonWFromTable"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RightBorderOfWilcoxonWFromTable"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ProbabilityDensityFunctionOfInverseGaussianDistribution"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DistributionFunctionOfNormalDistribution"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_WilcoxonW"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CompareMeanOfVectors"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_LineGeneralForm"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_LineSlopeInterceptForm"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_LineTwoPoint"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Parabola"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryGeneticAlgorithmWDPOfNOfGPS"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RealGeneticAlgorithmWDPOfNOfGPS"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryGeneticAlgorithmWDTS"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RealGeneticAlgorithmWDTS"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SinglepointCrossoverWithCopying"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TwopointCrossoverWithCopying"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryGeneticAlgorithmWCC"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RealGeneticAlgorithmWCC"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_AdditivePotential"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_MultiplicativePotential"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryGeneticAlgorithmTournamentSelectionWithReturn"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RealGeneticAlgorithmTournamentSelectionWithReturn"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_ReverseGriewank"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_HyperEllipsoid"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_RotatedHyperEllipsoid"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Wave"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Multiextremal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Multiextremal2"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Sombrero"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Himmelblau"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Katnikov"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Multiextremal3"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Multiextremal4"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_StepFunction"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Rana"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_ShekelsFoxholes"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_EggHolder"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_RastriginWithChange"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_RastriginWithTurning"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Schwefel"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Griewangk"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_InvertedGriewangk"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_InvertedRosenbrock"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_GaussianQuartic"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_RastriginNovgorod"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AlmostZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_QuadraticEquationCount"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AlmostEqual"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_UncorrectedVariance"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MeaningOfLife"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SinglepointCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TwopointCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_UniformCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MeanOfUpperFilter"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MeanOfLowerFilter"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MeanOfFilter"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ArithmeticalCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TestFunction_Bosom"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_FlatCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GeometricalCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BLXCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_LinearCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ExtendedLineForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_BinaryGeneticAlgorithmTwiceGenerations"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RealGeneticAlgorithmTwiceGenerations"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SeparateVectorLimitOnProductElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ChangeOrderInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SeparateVectorLimitOnProductElementsTwo"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ShiftLeftVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ShiftRightVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_PendulumOfMaxwell"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_CentroidOfTrapeziformFuzzyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MaxiMinTrapeziformFuzzyNumbers"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NonparametricEstimatorOfRegression"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AcceptanceLimitsNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AlphaBlendingColorToColorR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AlphaBlendingColorToColorG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AlphaBlendingColorToColorB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ColorFromGradientR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ColorFromGradientG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ColorFromGradientB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GiveRainbowColorR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GiveRainbowColorG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GiveRainbowColorB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MutationBinaryVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_TrapeziformTruncatedFuzzyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NewtonSecondLawForce"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NewtonSecondLawAcceleration"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AcceptanceLimitsLeft"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AcceptanceLimitsRight"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AcceptanceLimitsNumberLeft"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AcceptanceLimitsNumberRight"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NonparametricEstimatorOfDerivative"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NonparametricEstimatorOfDerivative2"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NonparametricEstimatorOfDerivative4"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NonparametricEstimatorOfDerivative5"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MakingVectorForNonparametricEstimatorOfDerivative3"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NonparametricEstimatorOfDerivative3"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NonparametricEstimatorOfDerivative6"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MakingVectorForNonparametricEstimatorOfDerivative6"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NegativeColorR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NegativeColorG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_NegativeColorB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GreyscaleR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GreyscaleG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_GreyscaleB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DivideColorR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DivideColorG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_DivideColorB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SubtractColorR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SubtractColorG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_SubtractColorB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MultiplyColorG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MultiplyColorB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_MultiplyColorR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AddColorR"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AddColorG"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_AddColorB"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_Swap"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_LogFactorial"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_RowInMatrixMultiplyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("HML_ColInMatrixMultiplyNumber"));
    model->appendRow(item);


    model->sort(0);

    //соединение модели списка с конкретным списком

    proxyModelView = new QSortFilterProxyModel(this);
    proxyModelView->setSourceModel(model);
    proxyModelView->setObjectName(QString::fromUtf8("proxyModelView"));

    ui->listView->setModel(proxyModelView);

    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//---------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//---------------------------------------------------------------------------
void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    QRegExp regExp(QString("*%1*").arg(arg1), Qt::CaseInsensitive,
                   QRegExp::Wildcard);
    proxyModelView->setFilterRegExp(regExp);
}
//---------------------------------------------------------------------------

double Func(int *x,int VHML_N)
{
    //Сумма всех элементов массива
    return HML_SumVector(x,VHML_N);
}
//---------------------------------------------------------------------------
double Func2(double *x,int VHML_N)
{
    //Сумма всех элементов массива
    return -((x[0]-2)*(x[0]-2)+(x[1]-2)*(x[1]-2));
    //return (exp(-x[0]*x[0])+0.01*cos(200*x[0]));
    //return (1.-0.5*cos(1.5*(10.*x[0]-0.3))*cos(31.4*x[0])+0.5*cos(sqrt(5.)*10.*x[0])*cos(35.*x[0]));

    //double X=x[0];
    //double Y=x[1];

    //double S,Z1,Z2;
    //Z1=-(1./((X-1.)*(X-1.)+0.2))-(1./(2.*(X-2.)*(X-2.)+0.15))-(1./(3.*(X-3.)*(X-3.)+0.3));
    //Z2=-(1./((Y-1.)*(Y-1.)+0.2))-(1./(2.*(Y-2.)*(Y-2.)+0.15))-(1./(3.*(Y-3.)*(Y-3.)+0.3));
    //S=-Z1*Z2;
    //return -S;
}
//---------------------------------------------------------------------------
double Func3(double x)
{
    return x*x;
}
//---------------------------------------------------------------------------
double Func4(double x)
{
    return (x-1)*(x-1);
}
//---------------------------------------------------------------------------
void MainWindow::HML_ShowText (QString TitleX)
{
    /*
    Функция выводит число строку в textEdit.
    Входные параметры:
     TitleX - непосредственно строка сама.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=HQt_ShowText (TitleX);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------
template <class T> void MainWindow::HML_ShowNumber (T VHML_X, QString TitleX, QString NameX)
{
    /*
    Функция выводит число VHML_X в textEdit.
    Входные параметры:
     VHML_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=THQt_ShowNumber (VHML_X, TitleX, NameX);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------
template <class T> QString MainWindow::HML_NumberToText (T VHML_X)
{
    /*
    Функция выводит число VHML_X в строку.
    Входные параметры:
     VHML_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VHML_Result;
    VHML_Result=THQt_NumberToText (VHML_X);
    return VHML_Result;
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::HML_ShowVector (T *VHML_Vector, int VHML_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VHML_Vector в textEdit
    Входные параметры:
     VHML_Vector - указатель на выводимый вектор;
     VHML_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=THQt_ShowVector (VHML_Vector,VHML_N, TitleVector, NameVector);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::HML_ShowVectorT (T *VHML_Vector, int VHML_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VHML_Vector в textEdit в траснпонированном виде
    Входные параметры:
     VHML_Vector - указатель на выводимый вектор;
     VHML_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=THQt_ShowVectorT (VHML_Vector,VHML_N, TitleVector, NameVector);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::HML_ShowMatrix (T **VHML_Matrix, int VHML_N, int VHML_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция выводит матрицу VHML_Matrix в textEdit
    Входные параметры:
     VHML_Matrix - указатель на указатель на выводимую матрицу;
     VHML_N - количество строк в матрице;
     VHML_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VHML_Result;
    VHML_Result=THQt_ShowMatrix (VHML_Matrix, VHML_N ,VHML_M, TitleMatrix, NameMatrix);// из HarrixQtLibrary.h
    Html=VHML_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    HQt_BeginHtml (Path);

    QString NameFunction;//Какая функция вызывается

    //выдергиваем текст
    NameFunction=index.data(Qt::DisplayRole).toString();

    //Сюда нужно добавить код

    //используем результат
    if (NameFunction=="HML_FillVector")
    {
        int VHML_N=10;//Размер массива
        int *a;
        a=new int[VHML_N];

        int x=5;//заполнитель

        //Вызов функции
        HML_FillVector(a,VHML_N,x);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        // a[0] = 5
        // a[1] = 5
        // a[2] = 5
        // a[3] = 5
        // a[4] = 5
        // a[5] = 5
        // a[6] = 5
        // a[7] = 5
        // a[8] = 5
        // a[9] = 5
        delete [] a;
    }

    if (NameFunction=="HML_MaximumOfVector")
    {
        int VHML_N=10;//Размер массива
        double max;
        double *a;
        a=new double[VHML_N];

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        max=HML_MaximumOfVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //0.0988159
        //0.61557
        //0.674866
        //0.937286
        //0.521759
        //0.074585
        //0.733337
        //0.5979
        //0.604309
        //0.917114

        HML_ShowNumber (max,"Максимальное значение в векторе", "max");
        //Максимальное значение в векторе:
        //max=0.937286

        delete [] a;
    }

    if (NameFunction=="HML_MinimumOfVector")
    {
        int VHML_N=10;//Размер массива
        double min;
        double *a;
        a=new double[VHML_N];

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        min=HML_MinimumOfVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //0.777496
        //0.446411
        //0.14621
        //0.938232
        //0.354156
        //0.831604
        //0.420349
        //0.50061
        //0.491394
        //0.0112305

        HML_ShowNumber (min,"Минимальное значение в векторе", "min");
        //Максимальное значение в векторе:
        //max=0.0112305

        delete [] a;
    }

    if (NameFunction=="HML_SumVector")
    {
        int VHML_N=10;//Размер массива
        double sum;
        double *a;
        a=new double[VHML_N];

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        sum=HML_SumVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //0.886475
        //0.998413
        //0.242859
        //0.221405
        //0.292175
        //0.134247
        //0.723846
        //0.271393
        //0.188904
        //0.727936

        HML_ShowNumber (sum,"Сумма элементов массива", "sum");
        //Сумма элементов массива:
        //sum=4.68765

        delete [] a;
    }

    if (NameFunction=="HML_SumSquareVector")
    {
        int VHML_N=10;//Размер массива
        double sum;
        double *a;
        a=new double[VHML_N];

        for (int i=0;i<VHML_N;i++) a[i]=i;//Заполняем значениями

        //Вызов функции
        sum=HML_SumSquareVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //0
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9

        HML_ShowNumber (sum,"Сумма квадратов элементов массива", "sum");
        //Сумма квадратов элементов массива:
        //sum=285

        delete [] a;
    }

    if (NameFunction=="HML_ZeroVector")
    {
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];

        //Вызов функции
        HML_ZeroVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Зануленный вектор", "a");
        //Зануленный вектор:
        //a =
        //0
        //0
        //0
        //0
        //0
        //0
        //0
        //0
        //0
        //0

        delete [] a;
    }

    if (NameFunction=="HML_VectorToVector")
    {
        int VHML_N=10;//Размер массива

        double *a;
        a=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomNumber();//Заполняем случайными значениями

        double *b;
        b=new double[VHML_N];

        //Вызов функции
        HML_VectorToVector(a,b,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Первоначальный вектор", "a");
        //Первоначальный вектор:
        //a =
        //0.874634
        //0.28656
        //0.676056
        //0.861755
        //0.0521851
        //0.308319
        //0.348267
        //0.431671
        //0.186462
        //0.562805

        HML_ShowVector (b,VHML_N,"Вектор, в который скопировали первый", "b");
        //Вектор, в который скопировали первый:
        //b =
        //0.874634
        //0.28656
        //0.676056
        //0.861755
        //0.0521851
        //0.308319
        //0.348267
        //0.431671
        //0.186462
        //0.562805

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_DegToRad")
    {
        double Rad;
        double Deg=90;//Угол в градусах

        //Вызов функции
        Rad=HML_DegToRad(Deg);

        //Используем полученный результат
        HML_ShowNumber(Rad,"Угол "+HML_NumberToText(Deg)+" градусов","равен в радианах");
        //Угол 90 градусов:
        //равен в радианах=1.5708
    }

    if (NameFunction=="HML_RadToDeg")
    {
        double Deg;
        double Rad=HML_PI;//Угол в радианах

        //Вызов функции
        Deg=HML_RadToDeg(Rad);

        //Используем полученный результат
        HML_ShowNumber(Deg,"Угол "+HML_NumberToText(Rad)+" радиан","равен в градусах");
        //Угол 3.14159 радиан:
        //равен в градусах=180
    }

    if (NameFunction=="HML_BitNumber")
    {
        int x;
        double P=0.8;//Угол в радианах

        //Вызов функции
        x=HML_BitNumber(P);

        //Используем полученный результат
        HML_ShowNumber(x,"Из 0 и 1 с вероятностью "+HML_NumberToText(P),"выбрано");

        //Вызов функции
        x=HML_BitNumber();

        //Используем полученный результат
        HML_ShowNumber(x,"Из 0 и 1 с вероятностью 0.5","выбрано");
    }

    if (NameFunction=="HML_RandomUniform")
    {
        double x;

        //Вызов функции
        x=HML_RandomUniform(10,100);

        //Используем полученный результат
        HML_ShowNumber(x,"Случайное число из интервала [10;100]","x");
        //Случайное число из интервала [10;100]:
        //x=68.4308
    }

    if (NameFunction=="HML_RandomRealMatrix")
    {
        int i;
        int VHML_N=3;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new double[VHML_M];

        double Left=-3;//левая граница интервала;
        double Right=3;//правая граница интервала;

        //Вызов функции
        HML_RandomRealMatrix(a,Left,Right,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //1.97571	0.862793	-0.357422
        //-2.62701	-0.202515	-2.79932
        //1.38794	1.35535	-2.29449

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_RandomNormal")
    {
        double x;
        double Mean=10;//математическое ожидание
        double StdDev=3;//среднеквадратичное отклонение

        //Вызов функции
        x=HML_RandomNormal(Mean,StdDev);

        //Используем полученный результат
        HML_ShowNumber(x,"Случайное число по нормальному закону (Mean="+HML_NumberToText(Mean)+", StdDev="+HML_NumberToText(StdDev)+")","x");
        //Случайное число по нормальному закону (Mean=10, StdDev=3):
        //x=10.9968
    }

    if (NameFunction=="HML_RandomUniformInt")
    {
        double x;
        int s0=0,s1=0,s2=0,s3=0;

        //Вызов функции
        for (int i=0;i<1000;i++)
        {
            x=HML_RandomUniformInt(0,3);
            if (x==0) s0++;
            if (x==1) s1++;
            if (x==2) s2++;
            if (x==3) s3++;
        }

        //Используем полученный результат
        HML_ShowNumber(x,"Случайное целое число из интервала [0;3)","x");
        HML_ShowNumber(s0,"Число выпадений 0","s0");
        HML_ShowNumber(s1,"Число выпадений 1","s0");
        HML_ShowNumber(s2,"Число выпадений 2","s0");
        HML_ShowNumber(s3,"Число выпадений 3","s0");
        //Случайное целое число из интервала [0;3):
        //x=1
        //Число выпадений 0:
        //s0=324
        //Число выпадений 1:
        //s0=374
        //Число выпадений 2:
        //s0=302
        //Число выпадений 3:
        //s0=0
    }

    if (NameFunction=="HML_RandomRealMatrixInCols")
    {
        int i;
        int VHML_N=3;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new double[VHML_M];
        double *Left;
        Left=new double[VHML_M];
        double *Right;
        Right=new double[VHML_M];

        Left[0]=-5;//левая границы интервала изменения 1 столбца
        Right[0]=-4; //правая граница интервала изменения 1 столбца

        Left[1]=0;//левая границы интервала изменения 2 столбца
        Right[1]=3; //правая граница интервала изменения 2 столбца

        Left[2]=100;//левая границы интервала изменения 3 столбца
        Right[2]=200; //правая граница интервала изменения 3 столбца

        //Вызов функции
        HML_RandomRealMatrixInCols(a,Left,Right,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //-4.20267	2.20367	148.468
        //-4.42432	2.09418	138.654
        //-4.07089	1.95831	140.198

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="HML_RandomRealMatrixInElements")
    {
        int i,j;
        int VHML_N=3;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new double[VHML_M];
        double **Left;
        Left=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) Left[i]=new double[VHML_M];
        double **Right;
        Right=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) Right[i]=new double[VHML_M];

        //Возьмем для примера границы интервала равными около номера ячейки в матрице
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
            {
                Left[i][j]=i*VHML_N+j-0.1;
                Right[i][j]=Left[i][j]+0.2;
            }

        //Вызов функции
        HML_RandomRealMatrixInElements(a,Left,Right,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowMatrix (Left,VHML_N,VHML_M,"Матрица левых границ", "Left");
        // Матрица левых границ:
        //Left =
        //-0.1	0.9	1.9
        //2.9	3.9	4.9
        //5.9	6.9	7.9

        HML_ShowMatrix (Right,VHML_N,VHML_M,"Матрица правых границ", "Right");
        // Матрица правых границ:
        //Right =
        //0.1	1.1	2.1
        //3.1	4.1	5.1
        //6.1	7.1	8.1

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //0.0829529	1.04504	1.9892
        //2.90126	3.92388	4.90221
        //5.96102	6.90623	8.09661

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_N;i++) delete [] Left[i];
        delete [] Left;
        for (i=0;i<VHML_N;i++) delete [] Right[i];
        delete [] Right;
    }

    if (NameFunction=="HML_RandomRealMatrixInRows")
    {
        int i;
        int VHML_N=3;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new double[VHML_M];
        double *Left;
        Left=new double[VHML_N];
        double *Right;
        Right=new double[VHML_N];

        Left[0]=-5;//левая границы интервала изменения 1 строки
        Right[0]=-4; //правая граница интервала изменения 1 строки

        Left[1]=0;//левая границы интервала изменения 2 строки
        Right[1]=3; //правая граница интервала изменения 2 строки

        Left[2]=100;//левая границы интервала изменения 3 строки
        Right[2]=200; //правая граница интервала изменения 3 строки

        //Вызов функции
        HML_RandomRealMatrixInRows(a,Left,Right,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //-4.98376	-4.64868	-4.38959
        //1.14386	2.70071	2.76151
        //141.309	192.12	100.122

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="HML_RandomRealVector")
    {
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];

        double Left=-3;
        double Right=3;

        //Вызов функции
        HML_RandomRealVector(a,Left,Right,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Массив", "a");
        //a =
        //1.73822
        //-0.406311
        //-2.7572
        //-0.351013
        //0.367493
        //1.40991
        //0.662476
        //-1.15576
        //-1.75781
        //-2.06927

        delete [] a;
    }

    if (NameFunction=="HML_RandomRealVectorInElements")
    {
        int VHML_N=2;//Размер массива
        double *a;
        a=new double[VHML_N];

        double *Left;
        Left=new double[VHML_N];
        Left[0]=-3;//Левая граница изменения первого элемента массива
        Left[1]=5;//Левая граница изменения второго элемента массива

        double *Right;
        Right=new double[VHML_N];
        Right[0]=3;//Правая граница изменения первого элемента массива
        Right[1]=10;//Правая граница изменения второго элемента массива

        //Вызов функции
        HML_RandomRealVectorInElements(a,Left,Right,VHML_N);

        //Используем полученный результат

        HML_ShowVector (Left,VHML_N,"Массив левых границ", "Left");
        // Массив левых границ:
        //Left =
        //-3
        //5

        HML_ShowVector (Right,VHML_N,"Массив правых границ", "Right");
        // Массив правых границ:
        //Right =
        //3
        //10

        HML_ShowVector (a,VHML_N,"Случайных массив", "a");
        // Случайных массив:
        //a =
        //1.32111
        //6.5625

        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="HML_RandomVectorOfProbability")
    {
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];

        //Заполним вектор случайными значениями вероятностей
        //Вызов функции
        HML_RandomVectorOfProbability(a, VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Вектор вероятностей выбора", "a");
        // Вектор вероятностей выбора:
        //a =
        //0.0662721
        //0.0681826
        //0.083972
        //0.0554142
        //0.18878
        //0.160006
        //0.0698625
        //0.0652843
        //0.127822
        //0.114404

        HML_ShowNumber (HML_SumVector(a,VHML_N),"Его сумма", "Sum");
        // Его сумма:
        //Sum=1
    }

    if (NameFunction=="HML_Cos")
    {
        double y;
        double Angle=HML_PI;//Угол в радинах

        //Вызов функции
        y=HML_Cos(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Косинус угла "+HML_NumberToText(Angle)+" радианов","равен");
        //Косинус угла 3.14159 радианов:
        //равен=-1
    }

    if (NameFunction=="HML_CosDeg")
    {
        double y;
        double Angle=180;//Угол в градусах

        //Вызов функции
        y=HML_CosDeg(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Косинус угла "+HML_NumberToText(Angle)+" градусов","равен");
        //Косинус угла 180 градусов:
        //равен=-1
    }

    if (NameFunction=="HML_Cosec")
    {
        double y;
        double Angle=HML_PI/4.;//Угол в радинах

        //Вызов функции
        y=HML_Cosec(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Косеканс угла "+HML_NumberToText(Angle)+" радианов","равен");
        //Косеканс угла 0.785398 радианов:
        //равен=1.41421
    }

    if (NameFunction=="HML_CosecDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=HML_CosecDeg(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Косеканс угла "+HML_NumberToText(Angle)+" градусов","равен");
        //Косеканс угла 45 градусов:
        //равен=1.41421
    }

    if (NameFunction=="HML_Cotan")
    {
        double y;
        double Angle=HML_PI/4.;//Угол в радинах

        //Вызов функции
        y=HML_Cotan(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Котангенс угла "+HML_NumberToText(Angle)+" радианов","равен");
        //Котангенс угла 0.785398 радианов:
        //равен=1
    }

    if (NameFunction=="HML_CotanDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=HML_CotanDeg(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Котангенс угла "+HML_NumberToText(Angle)+" градусов","равен");
        //Котангенс угла 45 градусов:
        //равен=1
    }

    if (NameFunction=="HML_Sec")
    {
        double y;
        double Angle=HML_PI/4.;//Угол в радинах

        //Вызов функции
        y=HML_Sec(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Секанс угла "+HML_NumberToText(Angle)+" радианов","равен");
        //Секанс угла 0.785398 радианов:
        //равен=1.41421
    }

    if (NameFunction=="HML_SecDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=HML_SecDeg(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Секанс угла "+HML_NumberToText(Angle)+" градусов","равен");
        //Секанс угла 45 градусов:
        //равен=1.41421
    }

    if (NameFunction=="HML_Sin")
    {
        double y;
        double Angle=HML_PI/2.;//Угол в радинах

        //Вызов функции
        y=HML_Sin(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Синус угла "+HML_NumberToText(Angle)+" радианов","равен");
        //Синус угла 1.5708 радианов:
        //равен=1
    }

    if (NameFunction=="HML_SinDeg")
    {
        double y;
        double Angle=90;//Угол в градусах

        //Вызов функции
        y=HML_SinDeg(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Синус угла "+HML_NumberToText(Angle)+" градусов","равен");
        //Синус угла 90 градусов:
        //равен=1
    }

    if (NameFunction=="HML_Tan")
    {
        double y;
        double Angle=HML_PI/4.;//Угол в радинах

        //Вызов функции
        y=HML_Tan(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Тангенс угла "+HML_NumberToText(Angle)+" радианов","равен");
        //Тангенс угла 0.785398 радианов:
        //равен=1
    }

    if (NameFunction=="HML_TanDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=HML_TanDeg(Angle);

        //Используем полученный результат
        HML_ShowNumber(y,"Тангенс угла "+HML_NumberToText(Angle)+" градусов","равен");
        //Тангенс угла 45 градусов:
        //равен=1
    }

    if (NameFunction=="HML_OrdinalVector")
    {
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];

        //Вызов функции
        HML_OrdinalVector(a,VHML_N);
        //Вектор:
        //a =
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9
        //10

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Вектор", "a");

        delete [] a;
    }

    if (NameFunction=="HML_OrdinalVectorZero")
    {
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];

        //Вызов функции
        HML_OrdinalVectorZero(a,VHML_N);
        //Вектор:
        //a =
        //0
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Вектор", "a");

        delete [] a;
    }

    if (NameFunction=="HML_SearchFirstNotZero")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,2);

        //Вызов функции
        int Number=HML_SearchFirstNotZero(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //0
        //0
        //0
        //1
        //0
        //0
        //0
        //1
        //1
        //0

        HML_ShowNumber (Number,"Номер первого ненулевого элемента", "Number");
        //Номер первого ненулевого элемента:
        //Number=3

        delete [] a;
    }

    if (NameFunction=="HML_SearchFirstZero")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,2);

        //Вызов функции
        int Number=HML_SearchFirstZero(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //1
        //1
        //1
        //0
        //0
        //1
        //0
        //0
        //0
        //1

        HML_ShowNumber (Number,"Номер первого нулевого элемента", "Number");
        //Номер первого нулевого элемента:
        //Number=3

        delete [] a;
    }

    if (NameFunction=="HML_VectorMinusVector")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        int *b;
        b=new int[VHML_N];
        int *c;
        c=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,10);
        for (i=0;i<VHML_N;i++)
            b[i]=HML_RandomUniformInt(0,10);

        //Вызов функции
        HML_VectorMinusVector(a,b,c,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //0	7	0	0	8	5	0	4	8	2

        HML_ShowVectorT (b,VHML_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //6	1	3	1	2	7	2	6	1	4

        HML_ShowVectorT (c,VHML_N,"Их разница", "c");
        //Их разница:
        //c =
        //-6	6	-3	-1	6	-2	-2	-2	7	-2

        delete [] a;
        delete [] b;
        delete [] c;

        //Для  переопределенной функции
        VHML_N=10;//Размер массива (число строк)
        a=new int[VHML_N];
        b=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,10);
        for (i=0;i<VHML_N;i++)
            b[i]=HML_RandomUniformInt(0,10);

        HML_ShowVectorT (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //6	9	3	0	2	9	4	2	3	7

        //Вызов функции
        HML_VectorMinusVector(a,b,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (b,VHML_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //5	6	3	8	5	0	7	6	4	4

        HML_ShowVectorT (a,VHML_N,"Из первого вычли второй", "a");
        //Из первого вычли второй:
        //a =
        //1	3	0	-8	-3	9	-3	-4	-1	3

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_VectorPlusVector")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        int *b;
        b=new int[VHML_N];
        int *c;
        c=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,10);
        for (i=0;i<VHML_N;i++)
            b[i]=HML_RandomUniformInt(0,10);

        //Вызов функции
        HML_VectorPlusVector(a,b,c,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //2	7	9	2	3	3	3	2	8	8


        HML_ShowVectorT (b,VHML_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //3	7	2	9	5	3	2	7	2	7

        HML_ShowVectorT (c,VHML_N,"Их сумма", "c");
        //Их сумма:
        //c =
        //5	14	11	11	8	6	5	9	10	15

        delete [] a;
        delete [] b;
        delete [] c;

        //Для  переопределенной функции
        VHML_N=10;//Размер массива (число строк)
        a=new int[VHML_N];
        b=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,10);
        for (i=0;i<VHML_N;i++)
            b[i]=HML_RandomUniformInt(0,10);

        HML_ShowVectorT (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //0	6	7	4	9	3	9	8	5	6

        //Вызов функции
        HML_VectorPlusVector(a,b,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (b,VHML_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //1	7	0	5	4	0	9	5	7	7

        HML_ShowVectorT (a,VHML_N,"К первому прибавили второй", "a");
        //К первому прибавили второй:
        //a =
        //1	13	7	9	13	3	18	13	12	13

        delete [] a;
        delete [] b;

    }

    if (NameFunction=="HML_VectorMultiplyNumber")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,10);

        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //4
        //6
        //3
        //5
        //4
        //7
        //8
        //2
        //1
        //0

        double Number=HML_RandomUniform(0,10);

        //Вызов функции
        HML_VectorMultiplyNumber(a,VHML_N,Number);

        //Используем полученный результат
        HML_ShowNumber (Number,"Случайный множитель", "Number");
        //Случайный множитель:
        //Number=3.57941

        HML_ShowVector (a,VHML_N,"Умножили на число Number", "a");
        //Умножили на число Number:
        //a =
        //14.3176
        //21.4764
        //10.7382
        //17.897
        //14.3176
        //25.0558
        //28.6353
        //7.15881
        //3.57941
        //0

        delete [] a;
    }

    if (NameFunction=="HML_Cosech")
    {
        double x=HML_RandomUniform(0,10);

        //Вызов функции
        double Result=HML_Cosech(x);

        //Используем полученный результат
        HML_ShowNumber(Result,"Гиперболический косеканс от x="+HML_NumberToText(x),"равен");
        //Гиперболический косеканс от x=0.571289:
        //равен=1.65872
    }

    if (NameFunction=="HML_Cosh")
    {
        double x=HML_RandomUniform(0,10);

        //Вызов функции
        double Result=HML_Cosh(x);

        //Используем полученный результат
        HML_ShowNumber(Result,"Гиперболический косинус от x="+HML_NumberToText(x),"равен");
        //Гиперболический косинус от x=4.04968:
        //равен=28.6983
    }

    if (NameFunction=="HML_Cotanh")
    {
        double x=HML_RandomUniform(0,10);

        //Вызов функции
        double Result=HML_Cotanh(x);

        //Используем полученный результат
        HML_ShowNumber(Result,"Гиперболический котангенс от x="+HML_NumberToText(x),"равен");
        //Гиперболический котангенс от x=1.92505:
        //равен=1.04348
    }

    if (NameFunction=="HML_Sech")
    {
        double x=HML_RandomUniform(0,10);

        //Вызов функции
        double Result=HML_Sech(x);

        //Используем полученный результат
        HML_ShowNumber(Result,"Гиперболический секанс от x="+HML_NumberToText(x),"равен");
        //Гиперболический секанс от x=0.679932:
        //равен=0.806323
    }

    if (NameFunction=="HML_Sinh")
    {
        double x=HML_RandomUniform(0,10);

        //Вызов функции
        double Result=HML_Sinh(x);

        //Используем полученный результат
        HML_ShowNumber(Result,"Гиперболический синус от x="+HML_NumberToText(x),"равен");
        //Гиперболический синус от x=0.166321:
        //равен=0.167089
    }

    if (NameFunction=="HML_Tanh")
    {
        double x=HML_RandomUniform(0,10);

        //Вызов функции
        double Result=HML_Tanh(x);

        //Используем полученный результат
        HML_ShowNumber(Result,"Гиперболический тангенс от x="+HML_NumberToText(x),"равен");
        //Гиперболический тангенс от x=4.27643:
        //равен=0.999614
    }

    if (NameFunction=="HML_NumberOfMaximumOfVector")
    {
        int i;
        int VHML_N=10;//Размер массива
        double *Vector=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++) Vector[i]=HML_RandomNumber();

        //Вызов функции
        double Number=HML_NumberOfMaximumOfVector(Vector,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Vector,VHML_N,"Случайный массив", "Vector");
        //Случайный массив:
        //Vector =
        //0.9245
        //0.221466
        //0.301544
        //0.643951
        //0.881958
        //0.832764
        //0.104462
        //0.0611267
        //0.943604
        //0.335205

        HML_ShowNumber(Number,"Номер максимального элемента","Number");//Например, выводим результат
        // Номер максимального элемента:
        //Number=8
        delete [] Vector;
    }

    if (NameFunction=="HML_NumberOfMinimumOfVector")
    {
        int i;
        int VHML_N=10;//Размер массива
        double *Vector=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++) Vector[i]=HML_RandomNumber();

        //Вызов функции
        double Number=HML_NumberOfMinimumOfVector(Vector,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Vector,VHML_N,"Случайный массив", "Vector");
        //Случайный массив:
        //Vector =
        //0.958344
        //0.0968323
        //0.689697
        //0.102264
        //0.142242
        //0.135925
        //0.473816
        //0.0245056
        //0.616333
        //0.798065

        HML_ShowNumber(Number,"Номер минимального элемента","Number");//Например, выводим результат
        //Номер минимального элемента:
        //Number=7
        delete [] Vector;
    }

    if (NameFunction=="HML_NumberOfNegativeValues")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(-20,20);

        //Вызов функции
        int NumberOfNegative=HML_NumberOfNegativeValues(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //12
        //19
        //-11
        //-20
        //13
        //4
        //-6
        //-1
        //1
        //-8

        HML_ShowNumber (NumberOfNegative,"Число отрицательных значений в векторе", "NumberOfNegative");
        //Число отрицательных значений в векторе:
        //NumberOfNegative=5

        delete [] a;
    }

    if (NameFunction=="HML_NumberOfPositiveValues")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(-20,20);

        //Вызов функции
        int NumberOfNegative=HML_NumberOfPositiveValues(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //6
        //14
        //14
        //13
        //-19
        //-18
        //11
        //-18
        //-20
        //5

        HML_ShowNumber (NumberOfNegative,"Число положительных значений в векторе", "NumberOfNegative");
        //Число положительных значений в векторе:
        //NumberOfNegative=6

        delete [] a;
    }

    if (NameFunction=="HML_NumberOfZeroValues")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(-2,2);

        //Вызов функции
        int NumberOfNegative=HML_NumberOfZeroValues(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //1
        //1
        //0
        //0
        //0
        //-1
        //1
        //1
        //0
        //1

        HML_ShowNumber (NumberOfNegative,"Число нулевых значений в векторе", "NumberOfNegative");
        //Число нулевых значений в векторе:
        //NumberOfNegative=4

        delete [] a;
    }

    if (NameFunction=="HML_FibonacciNumbersVector")
    {
        int VHML_N=HML_RandomUniformInt(5,15);//Размер массива
        double *x;
        x=new double[VHML_N];

        //Вызов функции
        HML_FibonacciNumbersVector(x,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Вектор, заполненый числами Фибоначи", "x");
        //Вектор, заполненый числами Фибоначи:
        //x =
        //1
        //1
        //2
        //3
        //5
        //8
        //13
        //21
        //34
        //55
        //89
        //144

        delete [] x;
    }

    if (NameFunction=="HML_EqualityOfVectors")
    {
        int VHML_N=5;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        int *b;
        b=new int[VHML_N];

        int x=HML_RandomUniformInt(0,2);//заполнитель для вектора a
        int y=HML_RandomUniformInt(0,2);//заполнитель для вектора b
        HML_FillVector (a, VHML_N, x);
        HML_FillVector (b, VHML_N, y);


        //Вызов функции
        int Q=HML_EqualityOfVectors(a,b,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Вектор", "a");
        //Вектор:
        //a =
        //1
        //1
        //1
        //1
        //1

        HML_ShowVector (b,VHML_N,"Вектор", "b");
        //Вектор:
        //b =
        //0
        //0
        //0
        //0
        //0

        HML_ShowNumber (Q,"Равны ли вектора", "Q");
        // Равны ли вектора:
        //Q=0


        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_CheckElementInVector")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,5);
        int k=HML_RandomUniformInt(0,5);//искомое число

        //Вызов функции
        int Search=HML_CheckElementInVector(a,VHML_N,k);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Вектор", "a");
        //Вектор:
        //a =
        //2
        //1
        //2
        //1
        //0
        //1
        //0
        //3
        //0
        //0

        HML_ShowNumber (k,"Искомое число", "k");
        //Искомое число:
        //k=3

        HML_ShowNumber (Search,"находится в векторе a под номером", "Search");
        //находится в векторе a под номером:
        //Search=7
        delete [] a;
    }

    if (NameFunction=="HML_Max")
    {
        int a=HML_RandomUniformInt(10,100);
        int b=HML_RandomUniformInt(10,100);
        int c=HML_RandomUniformInt(10,100);

        //Вызов функции
        int Max=HML_Max(a,b,c);

        //Используем полученный результат
        HML_ShowNumber(Max,"Максимальное среди "+HML_NumberToText(a)+" и "+HML_NumberToText(b)+" и "+HML_NumberToText(c),"равно");
        //Максимальное среди 73 и 44:
        //равно=73
    }

    if (NameFunction=="HML_Min")
    {
        int a=HML_RandomUniformInt(10,100);
        int b=HML_RandomUniformInt(10,100);

        //Вызов функции
        int Max=HML_Min(a,b);

        //Используем полученный результат
        HML_ShowNumber(Max,"Минимальное среди "+HML_NumberToText(a)+" и "+HML_NumberToText(b),"равно");
        //Минимальное среди 79 и 18:
        //равно=18
    }

    if (NameFunction=="HML_Abs")
    {
        double x;
        double absx;

        x=HML_RandomUniform(-10,10);

        //Вызов функции
        absx=HML_Abs(x);

        //Используем полученный результат
        HML_ShowNumber (x,"Число", "x");
        // Число:
        //x=-6.29578

        HML_ShowNumber (absx,"Модуль", "absx");
        // Модуль:
        //absx=6.29578
    }

    if (NameFunction=="HML_NumberInterchange")
    {
        double a=HML_RandomUniform(-10,10);
        double b=HML_RandomUniform(-10,10);

        HML_ShowNumber(a,"Было","a");
        //Было:
        //a=-3.18237
        HML_ShowNumber(b,"Было","b");
        //Было:
        //b=5.36194

        //Вызов функции
        HML_NumberInterchange(a,b);

        //Используем полученный результат
        HML_ShowNumber(a,"Стало","a");
        //Стало:
        //a=5.36194
        HML_ShowNumber(b,"Стало","b");
        //Стало:
        //b=-3.18237
    }

    if (NameFunction=="HML_Swap")
    {
        double a=HML_RandomUniform(-10,10);
        double b=HML_RandomUniform(-10,10);

        HML_ShowNumber(a,"Было","a");
        //Было:
        //a=-3.18237
        HML_ShowNumber(b,"Было","b");
        //Было:
        //b=5.36194

        //Вызов функции
        HML_Swap(a,b);

        //Используем полученный результат
        HML_ShowNumber(a,"Стало","a");
        //Стало:
        //a=5.36194
        HML_ShowNumber(b,"Стало","b");
        //Стало:
        //b=-3.18237
    }

    if (NameFunction=="HML_Sign")
    {
        int a=HML_RandomUniformInt(-5,5);

        //Вызов функции
        int Result=HML_Sign(a);

        //Используем полученный результат
        HML_ShowNumber(Result,"Знак числа "+HML_NumberToText(a),"равен");
        //Знак числа -3:
        //равен=-1
    }

    if (NameFunction=="HML_SignNull")
    {
        int a=HML_RandomUniformInt(-5,5);

        //Вызов функции
        int Result=HML_SignNull(a);

        //Используем полученный результат
        HML_ShowNumber(Result,"Знак числа "+HML_NumberToText(a),"равен");
        //Знак числа 0:
        //равен=1
    }

    if (NameFunction=="HML_SumOfDigits")
    {
        int a=HML_RandomUniformInt(100,30000);

        //Вызов функции
        int SumOfDigits=HML_SumOfDigits(a);

        //Используем полученный результат
        HML_ShowNumber (SumOfDigits,"Сумма цифр числа a="+HML_NumberToText(a), "равна");
        //Сумма цифр числа a=2069:
        //равна=17
    }

    if (NameFunction=="HML_SumMatrix")
    {
        int i,j;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                a[i][j]=HML_RandomUniformInt(10,100);

        //Вызов функции
        int SumMatrix=HML_SumMatrix(a,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //93	11	72
        //58	74	66
        //39	16	46
        //87	23	76
        //85	60	13
        //34	43	63
        //11	99	20
        //77	93	70
        //68	32	65
        //36	74	35

        HML_ShowNumber (SumMatrix,"Её сумма", "SumVector");
        //Её сумма:
        //SumVector=1639

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_ZeroMatrix")
    {
        int i;
        int VHML_N=HML_RandomUniformInt(4,10);//Размер массива (число строк)
        int VHML_M=HML_RandomUniformInt(4,10);//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        //Вызов функции
        HML_ZeroMatrix(a,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Зануленая матрица", "a");
        //Зануленая матрица:
        //a =
        //0	0	0	0	0	0	0	0
        //0	0	0	0	0	0	0	0
        //0	0	0	0	0	0	0	0
        //0	0	0	0	0	0	0	0

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_MaximumOfMatrix")
    {
        int i,j;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        double **Matrix;
        Matrix=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new double[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                Matrix[i][j]=HML_RandomUniformInt(10,100);

        //Вызов функции
        double Maximum=HML_MaximumOfMatrix(Matrix,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        //Случайная матрица:
        //Matrix =
        //25	42	79
        //99	34	34
        //16	80	41
        //12	95	78
        //67	27	14
        //29	20	93
        //57	66	17
        //52	38	42
        //31	96	27
        //39	77	50

        HML_ShowNumber(Maximum,"Максимальный элемент","Maximum");
        //Максимальный элемент:
        //Maximum=96

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_MinimumOfMatrix")
    {
        int i,j;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        double **Matrix;
        Matrix=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new double[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                Matrix[i][j]=HML_RandomUniformInt(10,100);

        //Вызов функции
        double Minimum=HML_MinimumOfMatrix(Matrix,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        //Случайная матрица:
        //Matrix =
        //29	64	95
        //55	25	36
        //73	31	62
        //54	19	22
        //29	78	48
        //24	40	46
        //82	13	90
        //66	23	14
        //44	45	56
        //73	92	16

        HML_ShowNumber(Minimum,"Минимальный элемент","Minimum");
        //Минимальный элемент:
        //Minimum=13

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_FillMatrix")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        int x=HML_RandomUniformInt(0,10);//заполнитель

        //Вызов функции
        HML_FillMatrix(a,VHML_N,VHML_M,x);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Заполненная матрица", "a");
        //Заполненная матрица:
        //a =
        //3	3	3
        //3	3	3
        //3	3	3
        //3	3	3
        //3	3	3
        //3	3	3
        //3	3	3
        //3	3	3
        //3	3	3
        //3	3	3

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_MatrixMinusMatrix")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int **b;
        b=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) b[i]=new int[VHML_M];
        int **c;
        c=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) c[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
            {
                a[i][j]=HML_RandomUniformInt(10,20);
                b[i][j]=HML_RandomUniformInt(10,20);
            }

        //Вызов функции
        HML_MatrixMinusMatrix(a,b,c,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Матрица", "a");
        //Матрица:
        //a =
        //18	19	17
        //14	12	11
        //10	16	19
        //12	18	16
        //12	16	11

        HML_ShowMatrix (b,VHML_N,VHML_M,"Матрица", "b");
        //Матрица:
        //b =
        //11	19	18
        //12	10	13
        //11	14	10
        //11	17	15
        //12	16	10

        HML_ShowMatrix (c,VHML_N,VHML_M,"Их разница", "c");
        //Их разница:
        //c =
        //7	0	-1
        //2	2	-2
        //-1	2	9
        //1	1	1
        //0	0	1

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_N;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VHML_N;i++) delete [] c[i];
        delete [] c;

        //Для переопределенной функции
        VHML_N=5;//Размер массива (число строк)
        VHML_M=3;//Размер массива (число столбцов)
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        b=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) b[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
            {
                a[i][j]=HML_RandomUniformInt(10,20);
                b[i][j]=HML_RandomUniformInt(10,20);
            }

        HML_ShowMatrix (a,VHML_N,VHML_M,"Матрица", "a");
        //Матрица:
        //a =
        //11	18	11
        //19	14	15
        //14	13	14
        //19	13	12
        //19	15	10

        //Вызов функции
        HML_MatrixMinusMatrix(a,b,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (b,VHML_N,VHML_M,"Матрица", "b");
        //Матрица:
        //b =
        //12	13	18
        //14	12	14
        //12	14	19
        //18	16	16
        //16	17	19

        HML_ShowMatrix (a,VHML_N,VHML_M,"Теперь матрица a", "a");
        //Теперь матрица a:
        //a =
        //-1	5	-7
        //5	2	1
        //2	-1	-5
        //1	-3	-4
        //3	-2	-9

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_N;i++) delete [] b[i];
        delete [] b;
    }

    if (NameFunction=="HML_MatrixPlusMatrix")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int **b;
        b=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) b[i]=new int[VHML_M];
        int **c;
        c=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) c[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
            {
                a[i][j]=HML_RandomUniformInt(10,20);
                b[i][j]=HML_RandomUniformInt(10,20);
            }

        //Вызов функции
        HML_MatrixPlusMatrix(a,b,c,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Матрица", "a");
        //Матрица:
        //a =
        //18	15	15
        //15	11	17
        //19	14	10
        //17	18	18
        //19	15	16

        HML_ShowMatrix (b,VHML_N,VHML_M,"Матрица", "b");
        //Матрица:
        //b =
        //17	15	15
        //16	18	10
        //17	12	15
        //12	16	13
        //15	14	10

        HML_ShowMatrix (c,VHML_N,VHML_M,"Их сумма", "c");
        //Их сумма:
        //c =
        //35	30	30
        //31	29	27
        //36	26	25
        //29	34	31
        //34	29	26

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_N;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VHML_N;i++) delete [] c[i];
        delete [] c;

        //Для переопределенной функции
        VHML_N=5;//Размер массива (число строк)
        VHML_M=3;//Размер массива (число столбцов)
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        b=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) b[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
            {
                a[i][j]=HML_RandomUniformInt(10,20);
                b[i][j]=HML_RandomUniformInt(10,20);
            }

        HML_ShowMatrix (a,VHML_N,VHML_M,"Матрица", "a");
        //Матрица:
        //a =
        //18	12	12
        //19	17	12
        //19	17	17
        //11	10	17
        //11	19	10

        //Вызов функции
        HML_MatrixPlusMatrix(a,b,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (b,VHML_N,VHML_M,"Матрица", "b");
        //Матрица:
        //b =
        //10	10	16
        //10	18	18
        //15	13	17
        //13	11	14
        //16	13	11

        HML_ShowMatrix (a,VHML_N,VHML_M,"Теперь матрица a", "a");
        //Теперь матрица a:
        //a =
        //28	22	28
        //29	35	30
        //34	30	34
        //24	21	31
        //27	32	21

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_N;i++) delete [] b[i];
        delete [] b;
    }

    if (NameFunction=="HML_MatrixMultiplyNumber")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=5;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                Matrix[i][j]=HML_RandomUniformInt(10,100);

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        //Случайная матрица:
        //Matrix =
        //77	34	14	83	30
        //31	15	87	68	20
        //52	11	49	92	95
        //77	29	96	50	90
        //10	47	40	49	20

        int Number=HML_RandomUniformInt(-10,10);

        //Вызов функции
        HML_MatrixMultiplyNumber(Matrix,VHML_N,VHML_M,Number);

        //Используем полученный результат
        HML_ShowNumber (Number,"Число, на которое умножается матрица","Number");
        //Число, на которое умножается матрица:
        //Number=4
        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Матрица умноженное на число", "Matrix");
        //Матрица умноженное на число:
        //Matrix =
        //308	136	56	332	120
        //124	60	348	272	80
        //208	44	196	368	380
        //308	116	384	200	360
        //40	188	160	196	80

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_MatrixT")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new int[VHML_M];
        int **MatrixT;
        MatrixT=new int*[VHML_M];
        for (i=0;i<VHML_M;i++) MatrixT[i]=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                Matrix[i][j]=HML_RandomUniformInt(10,100);

        //Вызов функции
        HML_MatrixT(Matrix,MatrixT,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Матрица", "Matrix");
        //Матрица:
        //Matrix =
        //26	64	62
        //70	49	43
        //50	41	50
        //76	75	81
        //26	72	24

        HML_ShowMatrix (MatrixT,VHML_M,VHML_N,"Транспонированная матрица", "MatrixT");
        // Транспонированная матрица:
        //MatrixT =
        //26	70	50	76	26
        //64	49	41	75	72
        //62	43	50	81	24

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
        for (i=0;i<VHML_M;i++) delete [] MatrixT[i];
        delete [] MatrixT;
    }

    if (NameFunction=="HML_MatrixMultiplyMatrix")
    {
        int i;
        int VHML_N=3;
        int VHML_M=5;
        int VHML_S=4;
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int **b;
        b=new int*[VHML_M];
        for (i=0;i<VHML_M;i++) b[i]=new int[VHML_S];
        int **c;
        c=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) c[i]=new int[VHML_S];
        HML_RandomIntMatrix(a,0,10,VHML_N,VHML_M);
        HML_RandomIntMatrix(b,0,10,VHML_M,VHML_S);

        //Вызов функции
        HML_MatrixMultiplyMatrix (a, b, c, VHML_N, VHML_M, VHML_S);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //3	0	4	4	5
        //9	4	3	4	4
        //8	0	1	9	8

        HML_ShowMatrix (b,VHML_M,VHML_S,"Случайная матрица", "b");
        // Случайная матрица:
        //b =
        //6	6	6	3
        //4	2	1	2
        //6	9	6	3
        //1	1	8	2
        //6	8	0	9

        HML_ShowMatrix (c,VHML_N,VHML_S,"Произведение", "c");
        // Произведение:
        //c =
        //76	98	74	74
        //116	125	108	88
        //111	130	126	117

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_M;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VHML_N;i++) delete [] c[i];
        delete [] c;
    }

    if (NameFunction=="HML_MatrixMultiplyMatrixT")
    {
        int i;
        int VHML_N=3;
        int VHML_M=5;
        int VHML_S=4;
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int **b;
        b=new int*[VHML_S];
        for (i=0;i<VHML_S;i++) b[i]=new int[VHML_M];
        int **c;
        c=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) c[i]=new int[VHML_S];
        HML_RandomIntMatrix(a,0,10,VHML_N,VHML_M);
        HML_RandomIntMatrix(b,0,10,VHML_S,VHML_M);

        //Вызов функции
        HML_MatrixMultiplyMatrixT (a, b, c, VHML_N, VHML_M, VHML_S);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //9	8	5	2	1
        //1	9	3	4	8
        //9	9	3	0	3

        HML_ShowMatrix (b,VHML_S,VHML_M,"Случайная матрица", "b");
        // Случайная матрица:
        //b =
        //3	7	3	0	8
        //9	8	0	6	9
        //0	2	5	6	5
        //8	7	9	2	3

        HML_ShowMatrix (c,VHML_N,VHML_S,"Произведение", "c");
        // Произведение:
        //c =
        //106	166	58	180
        //139	177	97	130
        //123	180	48	171

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_S;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VHML_N;i++) delete [] c[i];
        delete [] c;
    }

    if (NameFunction=="HML_MatrixTMultiplyMatrix")
    {
        int i;
        int VHML_N=3;
        int VHML_M=5;
        int VHML_S=4;
        int **a;
        a=new int*[VHML_M];
        for (i=0;i<VHML_M;i++) a[i]=new int[VHML_N];
        int **b;
        b=new int*[VHML_M];
        for (i=0;i<VHML_M;i++) b[i]=new int[VHML_S];
        int **c;
        c=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) c[i]=new int[VHML_S];
        HML_RandomIntMatrix(a,0,10,VHML_M,VHML_N);
        HML_RandomIntMatrix(b,0,10,VHML_M,VHML_S);

        //Вызов функции
        HML_MatrixTMultiplyMatrix (a, b, c, VHML_N, VHML_M, VHML_S);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_M,VHML_N,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //6	0	1
        //6	5	9
        //7	2	0
        //3	1	5
        //3	8	8

        HML_ShowMatrix (b,VHML_M,VHML_S,"Случайная матрица", "b");
        // Случайная матрица:
        //b =
        //6	7	1	0
        //7	6	0	0
        //5	6	0	0
        //9	7	9	3
        //5	7	0	1

        HML_ShowMatrix (c,VHML_N,VHML_S,"Произведение", "c");
        // Произведение:
        //c =
        //155	162	33	12
        //94	105	9	11
        //154	152	46	23

        for (i=0;i<VHML_M;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_M;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VHML_N;i++) delete [] c[i];
        delete [] c;
    }

    if (NameFunction=="HML_RandomIntMatrix")
    {
        int i;
        int VHML_N=3;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        int n=-3;//левая граница интервала;
        int m=3;//правая граница интервала;

        //Вызов функции
        HML_RandomIntMatrix(a,n,m,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //-1	-1	2
        //2	0	1
        //-3	2	-1ss

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_RandomIntMatrixInCols")
    {
        int i;
        int VHML_N=3;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int *n;
        n=new int[VHML_M];
        int *m;
        m=new int[VHML_M];

        n[0]=-50;//левая границы интервала изменения 1 столбца
        m[0]=-40; //правая граница интервала изменения 1 столбца

        n[1]=0;//левая границы интервала изменения 2 столбца
        m[1]=3; //правая граница интервала изменения 2 столбца

        n[2]=100;//левая границы интервала изменения 3 столбца
        m[2]=200; //правая граница интервала изменения 3 столбца

        //Вызов функции
        HML_RandomIntMatrixInCols(a,n,m,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //-47	2	142
        //-47	1	139
        //-44	0	199

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] n;
        delete [] m;
    }

    if (NameFunction=="HML_RandomIntMatrixInElements")
    {
        int i,j;
        int VHML_N=3;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int **n;
        n=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) n[i]=new int[VHML_M];
        int **m;
        m=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) m[i]=new int[VHML_M];

        //Заполним границы изменения каждого элемента
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
            {
                n[i][j]=i*VHML_N+j-10;
                m[i][j]=n[i][j]+20;
            }

        //Вызов функции
        HML_RandomIntMatrixInElements(a,n,m,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowMatrix (n,VHML_N,VHML_M,"Матрица левых границ", "n");
        //Матрица левых границ:
        //n =
        //-10	-9	-8
        //-7	-6	-5
        //-4	-3	-2

        HML_ShowMatrix (m,VHML_N,VHML_M,"Матрица правых границ", "m");
        // Матрица правых границ:
        //m =
        //10	11	12
        //13	14	15
        //16	17	18

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //-4	6	-8
        //-1	1	1
        //-3	16	4

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_N;i++) delete [] n[i];
        delete [] n;
        for (i=0;i<VHML_N;i++) delete [] m[i];
        delete [] m;
    }

    if (NameFunction=="HML_RandomIntMatrixInRows")
    {
        int i;
        int VHML_N=3;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int *n;
        n=new int[VHML_N];
        int *m;
        m=new int[VHML_N];

        n[0]=-50;//левая границы интервала изменения 1 строки
        m[0]=-40; //правая граница интервала изменения 1 строки

        n[1]=0;//левая границы интервала изменения 2 строки
        m[1]=3; //правая граница интервала изменения 2 строки

        n[2]=100;//левая границы интервала изменения 3 строки
        m[2]=200; //правая граница интервала изменения 3 строки

        //Вызов функции
        HML_RandomIntMatrixInRows(a,n,m,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        // -42	-42	-45
        //2	2	0
        //113	102	109

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] n;
        delete [] m;
    }

    if (NameFunction=="HML_RandomIntVector")
    {
        int VHML_N=10;//Размер массива
        int *a;
        a=new int[VHML_N];

        int n=3;
        int m=50;

        //Вызов функции
        HML_RandomIntVector(a,n,m,VHML_N);

        //Используем полученный результат

        HML_ShowVector (a,VHML_N,"Массив", "a");
        //Массив:
        //a =
        //6
        //23
        //40
        //19
        //39
        //37
        //48
        //46
        //31
        //42

        delete [] a;
    }

    if (NameFunction=="HML_RandomIntVectorInElements")
    {
        int VHML_N=2;//Размер массива
        int *a;
        a=new int[VHML_N];

        int *n;
        n=new int[VHML_N];
        n[0]=3;//Левая граница изменения первого элемента массива
        n[1]=-90;//Левая граница изменения второго элемента массива

        int *m;
        m=new int[VHML_N];
        m[0]=40;//Правая граница изменения первого элемента массива
        m[1]=-10;//Правая граница изменения второго элемента массива

        //Вызов функции
        HML_RandomIntVectorInElements(a,n,m,VHML_N);

        //Используем полученный результат

        HML_ShowVector (n,VHML_N,"Массив левых границ", "n");
        //Массив левых границ:
        //n =
        //3
        //-90

        HML_ShowVector (m,VHML_N,"Массив правых границ", "m");
        // Массив правых границ:
        //m =
        //40
        //-10

        HML_ShowVector (a,VHML_N,"Случайных массив", "a");
        // Случайных массив:
        //a =
        //31
        //-52

        delete [] a;
        delete [] n;
        delete [] m;
    }

    if (NameFunction=="HML_RandomBinaryMatrix")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        //Вызов функции
        HML_RandomBinaryMatrix(a,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная бинарная матрица", "a");
        //Случайная бинарная матрица:
        //a =
        //1	0	1
        //0	0	0
        //1	1	1
        //1	0	0
        //1	1	0
        //1	1	0
        //0	1	1
        //0	0	1
        //1	0	0
        //1	1	0

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_RandomBinaryVector")
    {
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];

        //Вызов функции
        HML_RandomBinaryVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный бинарный вектор", "a");
        //Случайный бинарный вектор:
        //a =
        //1
        //1
        //0
        //0
        //0
        //0
        //1
        //1
        //0
        //0

        delete [] a;
    }

    if (NameFunction=="HML_BernulliVector")
    {
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];

        //Вызов функции
        HML_BernulliVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный вектор Бернулли", "a");
        //Случайный вектор Бернулли:
        //a =
        //1
        //-1
        //1
        //1
        //-1
        //1
        //-1
        //-1
        //1
        //1
    }

    if (NameFunction=="HML_RandomArrangingObjectsIntoBaskets")
    {
        int VHML_N=10;//Размер массива
        int *a;
        a=new int[VHML_N];

        int N=HML_RandomUniformInt(0,10);// Размер турнира

        //Вызов функции
        HML_RandomArrangingObjectsIntoBaskets(a,N,VHML_N);

        //Используем полученный результат
        HML_ShowNumber (N,"Число предметов", "N");
        // Число предметов:
        // N=5
        HML_ShowVectorT (a,VHML_N,"Случаное расположение по 10 корзинам", "a");
        // Случаное расположение по 10 корзинам:
        //a =
        //0	1	0	0	0	1	1	0	1	1

        delete [] a;
    }

    if (NameFunction=="HML_ColInterchange")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=5;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                Matrix[i][j]=HML_RandomUniformInt(10,100);

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        // Случайная матрица:
        //Matrix =
        //46	37	90	95	83
        //92	58	48	61	16
        //31	92	37	64	56
        //20	54	84	90	75
        //86	79	20	40	69

        // номера перставляемых столбцов
        int k=HML_RandomUniformInt(0,5);
        int l=HML_RandomUniformInt(0,5);

        //Вызов функции
        HML_ColInterchange(Matrix,VHML_N,k,l);

        //Используем полученный результат
        HML_ShowNumber (k,"Номер первого столбца","k");
        // Номер первого столбца:
        //k=4
        HML_ShowNumber (l,"Номер второго столбца","l");
        // Номер второго столбца:
        //l=0
        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Матрица с персетавленными столбцами", "Matrix");
        // Матрица с персетавленными столбцами:
        //Matrix =
        //83	37	90	95	46
        //16	58	48	61	92
        //56	92	37	64	31
        //75	54	84	90	20
        //69	79	20	40	86

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_ColToMatrix")
    {
        int i,j;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int *b;
        b=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                a[i][j]=HML_RandomUniformInt(10,100);
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //13	99	23
        //69	44	44
        //64	70	72
        //14	85	92
        //11	40	12
        //95	85	81
        //82	50	13
        //63	82	58
        //56	68	89
        //51	89	78

        for (j=0;j<VHML_N;j++)
            b[j]=HML_RandomUniformInt(10,100);

        int k=1;//Номер столбца, в который мы копируем

        //Вызов функции
        HML_ColToMatrix(a,b,VHML_N,k);

        //Используем полученный результат
        HML_ShowNumber(k,"Номер столбца, в который мы копируем ","k");
        //Номер столбца, в который мы копируем :
        //k=1
        HML_ShowVector (b,VHML_N,"Вектор","b");
        //Вектор:
        //b =
        //35
        //92
        //90
        //41
        //17
        //24
        //11
        //13
        //23
        //14

        HML_ShowMatrix (a,VHML_N,VHML_M,"Матрица с изменившимся столбцом", "a");
        //Матрица с изменившимся столбцом:
        //a =
        //13	35	23
        //69	92	44
        //64	90	72
        //14	41	92
        //11	17	12
        //95	24	81
        //82	11	13
        //63	13	58
        //56	23	89
        //51	14	78

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_DeleteRowInMatrix")
    {
        int i,j;
        int VHML_N=6;//Размер массива (число строк)
        int VHML_M=4;//Размер массива (число столбцов)
        double **Matrix;
        Matrix=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new double[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                Matrix[i][j]=HML_RandomUniformInt(10,100);

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        // Случайная матрица:
        //Matrix =
        //70	57	44	95
        //26	21	60	63
        //61	55	27	95
        //10	10	43	92
        //66	20	51	65
        //32	52	63	78

        int k=2;//Удалим вторую строку

        //Вызов функции
        HML_DeleteRowInMatrix(Matrix,k,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Матрица с удаленной строкой", "Matrix");
        // Матрица с удаленной строкой:
        //Matrix =
        //70	57	44	95
        //26	21	60	63
        //10	10	43	92
        //66	20	51	65
        //32	52	63	78
        //0	0	0	0

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_DeleteColInMatrix")
    {
        int i,j;
        int VHML_N=6;//Размер массива (число строк)
        int VHML_M=4;//Размер массива (число столбцов)
        double **Matrix;
        Matrix=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new double[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                Matrix[i][j]=HML_RandomUniformInt(10,100);

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        // Случайная матрица:
        //Matrix =
        //39	52	14	31
        //49	49	59	65
        //68	15	12	86
        //91	73	36	32
        //52	31	24	78
        //22	20	33	94

        int k=2;//Удалим второй столбец

        //Вызов функции
        HML_DeleteColInMatrix(Matrix,k,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Матрица с удаленным столбцом", "Matrix");
        // Матрица с удаленным столбцом:
        //Matrix =
        //39	52	31	0
        //49	49	65	0
        //68	15	86	0
        //91	73	32	0
        //52	31	78	0
        //22	20	94	0

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_MatrixToCol")
    {
        int i,j;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int *b;
        b=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                a[i][j]=HML_RandomUniformInt(10,100);

        int k=1;//Номер копируемого столбца

        //Вызов функции
        HML_MatrixToCol(a,b,VHML_N,k);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //98	39	35
        //18	30	95
        //68	81	59
        //43	20	23
        //94	40	14
        //17	36	84
        //98	13	69
        //11	94	63
        //62	80	22
        //27	17	58

        HML_ShowNumber(k,"Номер копируемого столбца ","k");
        //Номер копируемого столбца :
        //k=1
        HML_ShowVector (b,VHML_N,"Вектор, в который скопировали столбец","b");
        //Вектор, в который скопировали столбец:
        //b =
        //39
        //30
        //81
        //20
        //40
        //36
        //13
        //94
        //80
        //17

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_MatrixToMatrix")
    {
        int i,j;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new double[VHML_M];
        double **b;
        b=new double*[VHML_N];
        for (i=0;i<VHML_N;i++) b[i]=new double[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                a[i][j]=HML_RandomUniformInt(10,100);

        //Вызов функции
        HML_MatrixToMatrix(a,b,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //82	55	19
        //38	82	91
        //68	67	50
        //82	62	63
        //24	41	69
        //16	47	29
        //18	92	63
        //11	29	30
        //71	49	64
        //11	95	38

        HML_ShowMatrix (b,VHML_N,VHML_M,"Теперь b равна a", "b");
        //Теперь b равна a:
        //b =
        //82	55	19
        //38	82	91
        //68	67	50
        //82	62	63
        //24	41	69
        //16	47	29
        //18	92	63
        //11	29	30
        //71	49	64
        //11	95	38

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VHML_N;i++) delete [] b[i];
        delete [] b;
    }

    if (NameFunction=="HML_MatrixToRow")
    {
        int i,j;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int *b;
        b=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                a[i][j]=HML_RandomUniformInt(10,100);

        int k=1;//Номер копируемой строки

        //Вызов функции
        HML_MatrixToRow(a,b,k,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //31	57	29
        //69	75	13
        //85	14	75
        //78	91	11
        //83	23	94
        //79	48	31
        //43	18	70
        //80	18	15
        //38	95	78
        //16	90	69

        HML_ShowNumber(k,"Номер копируемой строки ","k");
        //Номер копируемой строки :
        //k=1
        HML_ShowVector (b,VHML_M,"Вектор, в который скопировали строку","b");
        //Вектор, в который скопировали строку:
        //b =
        //69
        //75
        //13

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_RowInterchange")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=5;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                Matrix[i][j]=HML_RandomUniformInt(10,100);

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        //Случайная матрица:
        //Matrix =
        //64	41	93	98	45
        //19	55	31	38	44
        //38	78	39	44	86
        //28	54	39	14	72
        //31	99	64	49	63

        // номера перставляемых строк
        int k=HML_RandomUniformInt(0,5);
        int l=HML_RandomUniformInt(0,5);

        //Вызов функции
        HML_RowInterchange(Matrix,VHML_M,k,l);

        //Используем полученный результат
        HML_ShowNumber (k,"Номер первой строки","k");
        //Номер первой строки:
        //k=4
        HML_ShowNumber (l,"Номер второй строки","l");
        //Номер второй строки:
        //l=3
        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Матрица с персетавленными строками", "Matrix");
        //Матрица с персетавленными строками:
        //Matrix =
        //64	41	93	98	45
        //19	55	31	38	44
        //38	78	39	44	86
        //31	99	64	49	63
        //28	54	39	14	72

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_RowToMatrix")
    {
        int i,j;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        int *b;
        b=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                a[i][j]=HML_RandomUniformInt(10,100);
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //53	15	56
        //47	85	84
        //82	56	58
        //24	34	53
        //42	34	20
        //76	46	24
        //93	17	17
        //73	31	26
        //29	63	20
        //84	83	98

        for (j=0;j<VHML_M;j++)
            b[j]=HML_RandomUniformInt(10,100);

        int k=1;//Номер строки, в которую мы копируем

        //Вызов функции
        HML_RowToMatrix(a,b,k,VHML_M);

        //Используем полученный результат
        HML_ShowNumber(k,"Номер строки, в которую мы копируем ","k");
        //Номер строки, в которую мы копируем :
        //k=1
        HML_ShowVector (b,VHML_M,"Вектор","b");
        //Вектор:
        //b =
        //92
        //89
        //11

        HML_ShowMatrix (a,VHML_N,VHML_M,"Матрица с изменившейся строкой", "a");
        //Матрица с изменившейся строкой:
        //a =
        //53	15	56
        //92	89	11
        //82	56	58
        //24	34	53
        //42	34	20
        //76	46	24
        //93	17	17
        //73	31	26
        //29	63	20
        //84	83	98

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_NumberOfDifferentValuesInMatrix")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                a[i][j]=HML_RandomUniformInt(0,50);

        //Вызов функции
        int NumberOfDifferent=HML_NumberOfDifferentValuesInMatrix(a,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //7	3	27
        //31	30	10
        //37	34	49
        //45	26	12
        //26	28	0

        HML_ShowNumber (NumberOfDifferent,"Число различных значений в матрице", "NumberOfDifferent");
        //Число различных значений в матрице:
        //NumberOfDifferent=14
        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_IdentityMatrix")
    {
        int i;
        int VHML_N=5;//Размер массива (число строк и столбцов)
        int **Matrix;
        Matrix=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new int[VHML_N];

        //Вызов функции
        HML_IdentityMatrix(Matrix,VHML_N);

        //Используем полученный результат
        HML_ShowMatrix (Matrix,VHML_N,VHML_N,"Единичная матрица", "Matrix");
        //Единичная матрица:
        //Matrix =
        //1	0	0	0	0
        //0	1	0	0	0
        //0	0	1	0	0
        //0	0	0	1	0
        //0	0	0	0	1

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_MixingVector")
    {
        int VHML_N=10;//Размер массива
        int *x;
        x=new int[VHML_N];
        //Заполним массив номерами от 1
        HML_OrdinalVector(x,VHML_N);
        HML_ShowVector (x,VHML_N,"Вектор", "x");
        //Вектор:
        //x =
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9
        //10

        double P=0.4;//Вероятность перемешивания

        //Вызов функции
        HML_MixingVector(x,P,VHML_N);//Перемешаем массив

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Перемешанный вектор", "x");
        //Перемешанный вектор:
        //x =
        //4
        //2
        //1
        //3
        //5
        //6
        //7
        //8
        //9
        //10

        delete [] x;
    }

    if (NameFunction=="HML_ReverseVector")
    {
        int i;
        int VHML_N=HML_RandomUniformInt(2,10);//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(10,100);

        HML_ShowVector (a,VHML_N,"Вектор равен", "a");
        //Вектор равен:
        //a =
        //83
        //57
        //55
        //52
        //70
        //73

        //Вызов функции
        HML_ReverseVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Теперь вектор равен", "a");
        //Теперь вектор равен:
        //a =
        //73
        //70
        //52
        //55
        //57
        //83

        delete [] a;
    }

    if (NameFunction=="HML_NumberOfDifferentValuesInVector")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,5);

        //Вызов функции
        int NumberOfDifferent=HML_NumberOfDifferentValuesInVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //2
        //1
        //1
        //4
        //0
        //2
        //1
        //1
        //2
        //2

        HML_ShowNumber (NumberOfDifferent,"Число различных значений в векторе", "NumberOfDifferent");
        //Число различных значений в векторе:
        //NumberOfDifferent=4
        delete [] a;
    }

    if (NameFunction=="HML_PowerOf")
    {
        double a=HML_RandomUniform(-5,5);
        int Degree=HML_RandomUniformInt(0,20);

        double Result=HML_PowerOf(a,Degree);

        //Используем полученный результат
        HML_ShowNumber(Result,"Число "+HML_NumberToText(a)+" в степени "+HML_NumberToText(Degree),"равно");
        //Число 3.9624 в степени 4:
        //равно=246.51
    }

    if (NameFunction=="HML_Parity")
    {
        int a=HML_RandomUniformInt(-50,50);

        double Result=HML_Parity(a);

        //Используем полученный результат
        HML_ShowNumber(Result,"Четность числа "+HML_NumberToText(a),"равна");
        //Четность числа 2:
        //равна=1
    }

    if (NameFunction=="HML_ArithmeticalProgression")
    {
        double a1=HML_RandomUniformInt(1,10);
        double d=HML_RandomUniformInt(1,10);
        int n=HML_RandomUniformInt(1,10);

        double an=HML_ArithmeticalProgression(a1,d,n);

        //Используем полученный результат
        HML_ShowNumber(a1,"Первый член последовательности","a1");
        //Первый член последовательности:
        //a1=6
        HML_ShowNumber(d,"Шаг арифметической прогрессии","d");
        //Шаг арифметической прогрессии:
        //d=9
        HML_ShowNumber(n,"Номер последнего члена","n");
        //Номер последнего члена:
        //n=4
        HML_ShowNumber(an,"n-ый член последовательности","an");
        //n-ый член последовательности:
        //an=33
    }

    if (NameFunction=="HML_GeometricSeries")
    {
        double u1=HML_RandomUniformInt(1,10);
        double q=HML_RandomUniformInt(1,10);
        int n=HML_RandomUniformInt(1,10);

        double qn=HML_GeometricSeries(u1,q,n);

        //Используем полученный результат
        HML_ShowNumber(u1,"Первый член последовательности","u1");
        //Первый член последовательности:
        //u1=4
        HML_ShowNumber(q,"Шаг арифметической прогрессии","q");
        //Шаг арифметической прогрессии:
        //q=4
        HML_ShowNumber(n,"Номер последнего члена","n");
        //Номер последнего члена:
        //n=6
        HML_ShowNumber(qn,"n-ый член последовательности","qn");
        //n-ый член последовательности:
        //qn=4096
    }

    if (NameFunction=="HML_GreatestCommonDivisorEuclid")
    {
        int A=HML_RandomUniformInt(1,100);
        int B=HML_RandomUniformInt(1,100);

        double Result=HML_GreatestCommonDivisorEuclid(A,B);

        //Используем полученный результат
        HML_ShowNumber(A,"Число","A");
        //Число:
        //A=96
        HML_ShowNumber(B,"Число","B");
        //Число:
        //B=18
        HML_ShowNumber(Result,"НОД","");
        //НОД:
        //=6
    }

    if (NameFunction=="HML_LeastCommonMultipleEuclid")
    {
        int A=HML_RandomUniformInt(1,100);
        int B=HML_RandomUniformInt(1,100);

        double Result=HML_LeastCommonMultipleEuclid(A,B);

        //Используем полученный результат
        HML_ShowNumber(A,"Число","A");
        //Число:
        //A=68
        HML_ShowNumber(B,"Число","B");
        //Число:
        //B=67
        HML_ShowNumber(Result,"НОК","");
        //НОК:
        //=4556
    }

    if (NameFunction=="HML_HowManyPowersOfTwo")
    {
        int x=HML_RandomUniformInt(0,1000);
        int Degree;

        //Вызываем функцию
        Degree=HML_HowManyPowersOfTwo(x);

        //Используем полученный результат
        HML_ShowNumber(x,"Число","x");
        //Число:
        //x=480
        HML_ShowNumber(Degree,"Его покрывает 2 в степени","Degree");
        //Его покрывает 2 в степени:
        //Degree=9
        HML_ShowNumber(HML_PowerOf(2,Degree),"То есть","2^"+HML_NumberToText(Degree));
        //То есть:
        //2^9=512
    }

    if (NameFunction=="HML_SumGeometricSeries")
    {
        double u1=HML_RandomUniformInt(1,5);
        double q=HML_RandomUniformInt(1,5);
        int n=HML_RandomUniformInt(1,5);

        double Sum=HML_SumGeometricSeries(u1,q,n);

        //Используем полученный результат
        HML_ShowNumber(u1,"Первый член последовательности","u1");
        //Первый член последовательности:
        //u1=4
        HML_ShowNumber(q,"Шаг арифметической прогрессии","q");
        //Шаг арифметической прогрессии:
        //q=4
        HML_ShowNumber(n,"Номер последнего члена","n");
        //Номер последнего члена:
        //n=3
        HML_ShowNumber(Sum,"Сумма первых n членов","Sum");
        //Сумма первых n членов:
        //Sum=84
    }

    if (NameFunction=="HML_SumOfArithmeticalProgression")
    {
        double a1=HML_RandomUniformInt(1,10);
        double d=HML_RandomUniformInt(1,10);
        int n=HML_RandomUniformInt(1,10);

        double Sum=HML_SumOfArithmeticalProgression(a1,d,n);

        //Используем полученный результат
        HML_ShowNumber(a1,"Первый член последовательности","a1");
        //Первый член последовательности:
        //a1=9
        HML_ShowNumber(d,"Шаг арифметической прогрессии","d");
        //Шаг арифметической прогрессии:
        //d=6
        HML_ShowNumber(n,"Номер последнего члена","n");
        //Номер последнего члена:
        //n=9
        HML_ShowNumber(Sum,"Сумма первых n членов","Sum");
        //Сумма первых n членов:
        //Sum=297
    }

    if (NameFunction=="HML_FibonacciNumber")
    {
        int n;
        int F;
        n=HML_RandomUniformInt(3,20);

        //Вызов функции
        F=HML_FibonacciNumber(n);

        //Используем полученный результат

        HML_ShowNumber (n,"Номер числа", "n");
        // Номер числа:
        // n=14
        HML_ShowNumber (F,"Число Фибоначчи, заданного номера", "F");
        // Число Фибоначчи, заданного номера:
        // F=377
    }

    if (NameFunction=="HML_BoolCrossingTwoSegment")
    {
        double b1,c1,b2,c2;
        int Result;
        //Зададим случайные координаты отрезков
        b1=HML_RandomUniform(-3,5);
        c1=HML_RandomUniform(-3,5);
        b2=HML_RandomUniform(-3,5);
        c2=HML_RandomUniform(-3,5);

        //Вызов функции
        Result=HML_BoolCrossingTwoSegment(b1,c1,b2,c2);

        //Используем полученный результат
        HML_ShowNumber (b1,"Левый конец первого отрезка", "b1");
        //Левый конец первого отрезка:
        //b1=0.773193
        HML_ShowNumber (c1,"Правый конец первого отрезка", "c1");
        //Правый конец первого отрезка:
        //c1=3.22803
        HML_ShowNumber (b2,"Левый конец второго отрезка", "b2");
        //Левый конец второго отрезка:
        //b2=4.99121
        HML_ShowNumber (c2,"Правый конец второго отрезка", "c2");
        //Правый конец второго отрезка:
        //c2=1.43921
        HML_ShowNumber (Result,"Пересекаются ли отрезки", "Result");
        //Пересекаются ли отрезки:
        //Result=1
    }

    if (NameFunction=="HML_AcceptanceLimits")
    {
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];
        double *Left;
        Left=new double[VHML_N];
        double *Right;
        Right=new double[VHML_N];
        HML_FillVector(Left,VHML_N,-1.);//Левая граница
        HML_FillVector(Right,VHML_N,1.);//Правая граница

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomUniform(-1.1,1.1);
        HML_ShowVector (a,VHML_N,"Вектор", "a");
        //Вектор:
        //a =
        //-0.199268
        //-1.07664
        //-0.395917
        //0.170935
        //-0.720935
        //-1.07878
        //1.01608
        //-0.594714
        //-1.09678
        //0.2513

        //Вызов функции
        HML_AcceptanceLimits(a,Left,Right,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Left,VHML_N,"Левые границы", "Left");
        //Левые границы:
        //Left =
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1

        HML_ShowVector (Right,VHML_N,"Правые границы", "Right");
        // Правые границы:
        //Right =
        //1
        //1
        //1
        //1
        //1
        //1
        //1
        //1
        //1
        //1

        HML_ShowVector (a,VHML_N,"Отредактированный вектор", "a");
        //Отредактированный вектор:
        //a =
        //-0.199268
        //-1
        //-0.395917
        //0.170935
        //-0.720935
        //-1
        //1
        //-0.594714
        //-1
        //0.2513

        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="HML_NoiseInVector")
    {
        int VHML_N=10;//Размер массива
        double *x;
        x=new double[VHML_N];
        //Заполним массив номерами от 1
        HML_OrdinalVector(x,VHML_N);
        HML_ShowVector (x,VHML_N,"Вектор", "x");
        //Вектор:
        //x =
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9
        //10

        double percent=double(HML_RandomUniformInt(0,100));//Процент помехи

        //Вызов функции
        HML_NoiseInVector(x,percent,VHML_N);

        //Используем полученный результат

        HML_ShowNumber (percent,"Процент помехи", "percent");
        //Процент помехи:
        //percent=89
        HML_ShowVector (x,VHML_N,"Вектор с помехой", "x");
        //Вектор с помехой:
        //x =
        //-1.95828
        //2.17942
        //1.76139
        //4.45956
        //3.82128
        //8.0003
        //6.80982
        //5.94739
        //9.03153
        //8.59053

        delete [] x;
    }

    if (NameFunction=="HML_EuclidNorma")
    {
        int VHML_N=5;//Размер массива
        double *x;
        x=new double[VHML_N];
        //Заполним случайными числами
        HML_RandomRealVector (x,0,10,VHML_N);

        //Вызов функции
        double a=HML_EuclidNorma(x,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Вектор", "x");
        // Вектор:
        //x =
        //2.22504
        //5.2655
        //5.00092
        //5.7428
        //9.11682

        HML_ShowNumber (a,"Значение евклидовой нормы вектора", "a");
        // Значение евклидовой нормы вектора:
        // a=13.1826

        delete [] x;
    }

    if (NameFunction=="HML_MixingVectorWithConjugateVector")
    {
        int VHML_N=10;//Размер массива
        int *x;
        x=new int[VHML_N];
        int *y;
        y=new int[VHML_N];
        //Заполним массив номерами от 1
        HML_OrdinalVector(x,VHML_N);
        //А сопряженный заполним номерами с нуля
        HML_OrdinalVectorZero(y,VHML_N);
        HML_ShowVectorT (x,VHML_N,"Вектор", "x");
        //Вектор:
        //x =
        //1	2	3	4	5	6	7	8	9	10

        HML_ShowVectorT (y,VHML_N,"Вектор", "y");
        //Вектор:
        //y =
        //0	1	2	3	4	5	6	7	8	9

        double P=0.4;//Вероятность перемешивания

        //Вызов функции
        HML_MixingVectorWithConjugateVector(x,y,P,VHML_N);//Перемешаем массив

        //Используем полученный результат
        HML_ShowVectorT (x,VHML_N,"Перемешанный вектор", "x");
        // Перемешанный вектор:
        //x =
        //9	1	4	8	10	5	7	3	6	2

        HML_ShowVectorT (y,VHML_N,"Сопряженный перемешанный вектор", "y");
        //Сопряженный перемешанный вектор:
        //y =
        //8	0	3	7	9	4	6	2	5	1

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="HML_MixingRowsInOrder")
    {
        int i;
        int VHML_N=7;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)

        int *b;
        b=new int[VHML_N];

        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        //Заполним случайными числами
        HML_RandomIntMatrix(a,10,100,VHML_N,VHML_M);
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //49	65	82
        //92	73	27
        //10	72	80
        //87	62	12
        //82	11	75
        //15	75	94
        //56	96	39

        //Первончальный порядок
        HML_OrdinalVectorZero(b,VHML_N);
        //Перемешаем
        HML_MixingVector(b,0.5,VHML_N);

        //Вызов функции
        HML_MixingRowsInOrder(a,b,VHML_N,VHML_M);

        //Используем полученный результат

        HML_ShowVector (b,VHML_N,"Номера нового порядка", "b");
        //Номера нового порядка:
        //b =
        //5
        //0
        //1
        //4
        //6
        //2
        //3

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица с новым порядком строк", "a");
        //Случайная матрица с новым порядком строк:
        //a =
        //92	73	27
        //10	72	80
        //15	75	94
        //56	96	39
        //87	62	12
        //49	65	82
        //82	11	75

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_Chebychev")
    {
        int VHML_N=5;//Размер массива
        double *x;
        x=new double[VHML_N];
        double *y;
        y=new double[VHML_N];
        //Заполним случайными числами
        HML_RandomRealVector (x,0,10,VHML_N);
        HML_RandomRealVector (y,0,10,VHML_N);

        //Вызов функции
        double metric=HML_Chebychev(x,y,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Первый массив", "x");
        //Первый массив:
        //x =
        //7.9245
        //7.28699
        //6.24054
        //1.12152
        //7.65442

        HML_ShowVector (y,VHML_N,"Второй массив", "y");
        //Второй массив:
        //y =
        //0.324097
        //3.12164
        //4.47266
        //9.70062
        //5.64117

        HML_ShowNumber (metric,"Значение метрики расстояние Чебышева", "metric");
        //Значение метрики расстояние Чебышева:
        //metric=8.5791

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="HML_CityBlock")
    {
        int i;
        int VHML_N=5;//Размер массива
        int *x;
        x=new int[VHML_N];
        int *y;
        y=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
        {
            x[i]=HML_RandomUniformInt(0,5);
            y[i]=HML_RandomUniformInt(0,5);
        }

        //Вызов функции
        int metric=HML_CityBlock(x,y,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Первый массив", "x");
        //Первый массив:
        //x =
        //4
        //1
        //3
        //3
        //0

        HML_ShowVector (y,VHML_N,"Второй массив", "y");
        //Второй массив:
        //y =
        //3
        //4
        //1
        //4
        //1

        HML_ShowNumber (metric,"Значение метрики манхэттенское расстояние", "metric");
        // Значение метрики манхэттенское расстояние:
        //metric=8

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="HML_Euclid")
    {
        int VHML_N=5;//Размер массива
        double *x;
        x=new double[VHML_N];
        double *y;
        y=new double[VHML_N];
        //Заполним случайными числами
        HML_RandomRealVector (x,0,10,VHML_N);
        HML_RandomRealVector (y,0,10,VHML_N);

        //Вызов функции
        double metric=HML_Euclid(x,y,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Первый массив", "x");
        //Первый массив:
        //x =
        //3.15491
        //4.04266
        //2.63519
        //9.94141
        //3.2193

        HML_ShowVector (y,VHML_N,"Второй массив", "y");
        //Второй массив:
        //y =
        //9.4516
        //2.59064
        //2.56348
        //4.78271
        //5.78705

        HML_ShowNumber (metric,"Значение метрики евклидово расстояние", "metric");
        //Значение метрики евклидово расстояние:
        //metric=8.65837

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="HML_CenterDerivative")
    {
        double x;
        double h;
        double dfdx;
        //Зададим случайные координаты отрезков
        x=HML_RandomUniform(-3,5);
        h=0.01;//малое приращение x

        //Вызов функции
        dfdx=HML_CenterDerivative(x,h,Func3);

        //Используем полученный результат
        HML_ShowNumber (x,"Точка, в которой считается производная", "x");
        //Точка, в которой считается производная:
        //x=0.843262
        HML_ShowNumber (h,"Малое приращение x", "h");
        // Малое приращение x:
        //h=0.01
        HML_ShowNumber (dfdx,"Значение производной в точке", "dfdx");
        // Значение производной в точке:
        //dfdx=1.68652
    }

    if (NameFunction=="HML_LeftDerivative")
    {
        double x;
        double h;
        double dfdx;
        //Зададим случайные координаты отрезков
        x=HML_RandomUniform(-3,5);
        h=0.01;//малое приращение x

        //Вызов функции
        dfdx=HML_LeftDerivative(x,h,Func3);

        //Используем полученный результат
        HML_ShowNumber (x,"Точка, в которой считается производная", "x");
        // Точка, в которой считается производная:
        //x=1.87964
        HML_ShowNumber (h,"Малое приращение x", "h");
        // Малое приращение x:
        //h=0.01
        HML_ShowNumber (dfdx,"Значение производной в точке", "dfdx");
        // Значение производной в точке:
        //dfdx=3.74928
    }

    if (NameFunction=="HML_RightDerivative")
    {
        double x;
        double h;
        double dfdx;
        //Зададим случайные координаты отрезков
        x=HML_RandomUniform(-3,5);
        h=0.01;//малое приращение x

        //Вызов функции
        dfdx=HML_RightDerivative(x,h,Func3);

        //Используем полученный результат
        HML_ShowNumber (x,"Точка, в которой считается производная", "x");
        // Точка, в которой считается производная:
        //x=-1.69409
        HML_ShowNumber (h,"Малое приращение x", "h");
        // Малое приращение x:
        //h=0.01
        HML_ShowNumber (dfdx,"Значение производной в точке", "dfdx");
        // Значение производной в точке:
        //dfdx=-3.37818
    }

    if (NameFunction=="HML_IntegralOfTrapezium")
    {
        double a=-2;
        double b=2;
        double Epsilon=0.01;
        double S;

        //Вызов функции
        S=HML_IntegralOfTrapezium(a,b,Epsilon,Func3);

        //Используем полученный результат
        HML_ShowNumber (a,"Левая граница интегрирования", "a");
        //Левая граница интегрирования:
        //a=-2
        HML_ShowNumber (b,"Правая граница интегрирования", "b");
        //Правая граница интегрирования:
        //b=2
        HML_ShowNumber (S,"Интеграл", "S");
        //Интеграл:
        //S=5.33594
    }

    if (NameFunction=="HML_IntegralOfSimpson")
    {
        double a=-2;
        double b=2;
        double Epsilon=0.01;
        double S;

        //Вызов функции
        S=HML_IntegralOfSimpson(a,b,Epsilon,Func3);

        //Используем полученный результат
        HML_ShowNumber (a,"Левая граница интегрирования", "a");
        // Левая граница интегрирования:
        //a=-2
        HML_ShowNumber (b,"Правая граница интегрирования", "b");
        // Правая граница интегрирования:
        //b=2
        HML_ShowNumber (S,"Интеграл", "S");
        // Интеграл:
        //S=5.33333
    }

    if (NameFunction=="HML_IntegralOfRectangle")
    {
        double a=-2;
        double b=2;
        double Epsilon=0.01;
        double S;

        //Вызов функции
        S=HML_IntegralOfRectangle(a,b,Epsilon,Func3);

        //Используем полученный результат
        HML_ShowNumber (a,"Левая граница интегрирования", "a");
        //Левая граница интегрирования:
        //a=-2
        HML_ShowNumber (b,"Правая граница интегрирования", "b");
        //Правая граница интегрирования:
        //b=2
        HML_ShowNumber (S,"Интеграл", "S");
        // Интеграл:
        //S=5.32812
    }

    if (NameFunction=="HML_HeavisideFunction")
    {
        double x=HML_RandomUniform(-50,50);

        double F=HML_HeavisideFunction(x);

        //Используем полученный результат
        HML_ShowNumber(F,"Функция Хэвисайда при a = "+HML_NumberToText(x),"равна");
        //Функция Хэвисайда при a = -49.7559:
        //равна=0
    }

    if (NameFunction=="HML_ExpMSxD2")
    {
        double t;
        double f;
        t=HML_RandomUniform(0,3);

        //Вызов функции
        f=HML_ExpMSxD2(t);

        //Используем полученный результат

        HML_ShowNumber (t,"Параметр", "t");
        //Параметр:
        //t=2.06177
        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.11938
    }

    if (NameFunction=="HML_NormalizationNumberAll")
    {
        double x;
        double y;
        y=HML_RandomUniform(-100,100);

        //Вызов функции
        x=HML_NormalizationNumberAll(y);

        //Используем полученный результат
        HML_ShowNumber (y,"Число", "y");
        //Число:
        //y=-10.4004
        HML_ShowNumber (x,"Нормированное число", "x");
        //Нормированное число:
        //x=0.0438581
    }

    if (NameFunction=="HML_InverseNormalizationNumberAll")
    {
        double x;
        double y;
        x=HML_RandomNumber();

        //Вызов функции
        y=HML_InverseNormalizationNumberAll(x);

        //Используем полученный результат
        HML_ShowNumber (x,"Нормированное число", "x");
        // Нормированное число:
        //x=0.0491333
        HML_ShowNumber (y,"Перенормированное число", "y");
        // Перенормированное число:
        //y=-9.1764
    }

    if (NameFunction=="HML_BinaryMonteCarloAlgorithm")
    {
        int LengthBinarString=50;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений функции пригодности

        int *ParametersOfBinaryMonteCarloAlgorithm;
        ParametersOfBinaryMonteCarloAlgorithm=new int[2];
        ParametersOfBinaryMonteCarloAlgorithm[0]=LengthBinarString;//Длина хромосомы
        ParametersOfBinaryMonteCarloAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции

        int *Decision;//бинарное решение
        Decision=new int[LengthBinarString];
        double ValueOfFitnessFunction;//значение функции пригодности в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_BinaryMonteCarloAlgorithm (ParametersOfBinaryMonteCarloAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        //Как прошел запуск:
        //VHML_Success=1

        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,LengthBinarString,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	0	1	1	1	1	1	0	1	1	1	1	1	1	1	0	0	1	0	0	1	1	1	1	1	0	1	1	0	1	1	0	1	1	1	1	0	0	1	1	1	1	0	1	1	1	0	1	1	1

            HML_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=37
        }
        delete [] ParametersOfBinaryMonteCarloAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="HML_BubbleDescendingSort")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomNumber();

        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        // Например
        // Случайный вектор:
        //Случайный вектор:
        //a =
        //0.233978
        //0.29541
        //0.142914
        //0.719482
        //0.489319
        //0.610382
        //0.667908
        //0.596069
        //0.92099
        //0.88327

        //Вызов функции
        HML_BubbleDescendingSort(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Отсортированный вектор", "a");
        //Отсортированный вектор:
        //a =
        //0.92099
        //0.88327
        //0.719482
        //0.667908
        //0.610382
        //0.596069
        //0.489319
        //0.29541
        //0.233978
        //0.142914

        delete [] a;
    }

    if (NameFunction=="HML_BubbleSort")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomNumber();

        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        // Например
        //Случайный вектор:
        //a =
        //0.889862
        //0.575836
        //0.741882
        //0.0479736
        //0.788879
        //0.873413
        //0.343933
        //0.32196
        //0.0332031
        //0.0214844

        //Вызов функции
        HML_BubbleSort(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Отсортированный вектор", "a");
        // Отсортированный вектор:
        //a =
        //0.0214844
        //0.0332031
        //0.0479736
        //0.32196
        //0.343933
        //0.575836
        //0.741882
        //0.788879
        //0.873413
        //0.889862

        delete [] a;
    }

    if (NameFunction=="HML_BubbleSortInGroups")
    {
        int i;
        int VHML_N=9;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(10,50);

        // Например
        HML_ShowVectorT (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //20	42	39	19	27	33	35	44	32

        int m=3;

        //Вызов функции
        HML_BubbleSortInGroups(a,VHML_N,m);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Отсортированный вектор по три элемента", "a");
        //Отсортированный вектор по три элемента:
        //a =
        //20	39	42	19	27	33	32	35	44

        delete [] a;
    }

    if (NameFunction=="HML_BubbleSortWithConjugateVector")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        int *b;
        b=new int[VHML_N];
        for (i=0;i<VHML_N;i++)
        {
            a[i]=HML_RandomUniformInt(10,50);
            b[i]=HML_RandomUniformInt(10,50);
        }

        // Например
        HML_ShowVectorT (a,VHML_N,"Случайный вектор", "a");
        // Случайный вектор:
        //a =
        //31	32	13	26	40	40	47	26	10	18

        HML_ShowVectorT (b,VHML_N,"Сопряженный вектор", "b");
        //Сопряженный вектор:
        //b =
        //31	20	44	32	21	36	46	30	31	15

        //Вызов функции
        HML_BubbleSortWithConjugateVector(a,b,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Отсортированный вектор", "a");
        // Отсортированный вектор:
        //a =
        //10	13	18	26	26	31	32	40	40	47

        HML_ShowVectorT (b,VHML_N,"Сопряженный вектор", "b");
        // Сопряженный вектор:
        //b =
        //31	44	15	32	30	31	20	21	36	46

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_BubbleSortWithTwoConjugateVectors")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        int *b;
        b=new int[VHML_N];
        int *c;
        c=new int[VHML_N];
        for (i=0;i<VHML_N;i++)
        {
            a[i]=HML_RandomUniformInt(10,50);
            b[i]=HML_RandomUniformInt(10,50);
            c[i]=HML_RandomUniformInt(10,50);
        }

        // Например
        HML_ShowVectorT (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //45	27	11	18	24	25	16	19	34	43

        HML_ShowVectorT (b,VHML_N,"Сопряженный вектор", "b");
        //Сопряженный вектор:
        //b =
        //33	32	24	33	32	49	33	43	25	47

        HML_ShowVectorT (c,VHML_N,"Сопряженный вектор", "c");
        //Сопряженный вектор:
        //c =
        //15	24	27	43	17	47	25	11	13	26

        //Вызов функции
        HML_BubbleSortWithTwoConjugateVectors(a,b,c,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Отсортированный вектор", "a");
        //Отсортированный вектор:
        //a =
        //11	16	18	19	24	25	27	34	43	45

        HML_ShowVectorT (b,VHML_N,"Сопряженный вектор", "b");
        // Сопряженный вектор:
        //b =
        //24	33	33	43	32	49	32	25	47	33

        HML_ShowVectorT (c,VHML_N,"Второй сопряженный вектор", "c");
        //Второй сопряженный вектор:
        //c =
        //27	25	43	11	17	47	24	13	26	15

        delete [] a;
        delete [] b;
        delete [] c;
    }

    if (NameFunction=="HML_DensityOfDistributionOfNormalizedCenteredNormalDistribution")
    {
        double t;
        double f;
        t=HML_RandomUniform(0,3);

        //Вызов функции
        f=HML_DensityOfDistributionOfNormalizedCenteredNormalDistribution(t);

        //Используем полученный результат

        HML_ShowNumber (t,"Параметр", "t");
        // Параметр:
        //t=1.42401
        HML_ShowNumber (f,"Значение функции", "f");
        // Значение функции:
        //f=0.144736
    }

    if (NameFunction=="HML_StdDevToVariance")
    {
        double Variance;
        double StdDev=6;

        //Вызов функции
        Variance=HML_StdDevToVariance(StdDev);

        //Используем результат
        HML_ShowNumber(Variance,"Дисперсия при среднеквадратичном уклонении, равным "+HML_NumberToText(StdDev),"равна");
        //Дисперсия при среднеквадратичном уклонении, равным 6:
        //равна=2.44949
    }

    if (NameFunction=="HML_VarianceToStdDev")
    {
        double StdDev;
        double Variance=6;

        //Вызов функции
        StdDev=HML_VarianceToStdDev(Variance);

        //Используем полученный результат
        HML_ShowNumber(StdDev,"Среднеквадратичное уклонение при дисперсии, равной "+HML_NumberToText(Variance),"равно");
        //Среднеквадратичное уклонение при дисперсии, равной 6:
        //равно=36
    }

    if (NameFunction=="HML_Mean")
    {
        int i;
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniform(0,10);

        //Вызов функции
        double Mean=HML_Mean(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Массив", "a");
        // Массив:
        //a =
        //4.65149
        //4.00574
        //1.41113
        //1.55457
        //2.75055
        //3.16559
        //8.26508
        //3.86902
        //9.5401
        //4.50836

        HML_ShowNumber (Mean,"Среднее арифметическое массива", "Mean");
        //Среднее арифметическое массива:
        //Mean=4.37216

        delete [] a;
    }

    if (NameFunction=="HML_Median")
    {
        int i;
        int VHML_N=HML_RandomUniformInt(3,10);//Размер массива
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniform(0,10);

        //Вызов функции
        double Median=HML_Median(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Массив", "a");
        //Массив:
        //a =
        //8.77167
        //5.89142
        //6.45966
        //3.94775

        HML_ShowNumber (Median,"Медиана", "Median");
        // Медиана:
        //Median=6.17554

        delete [] a;
    }

    if (NameFunction=="HML_SampleCovariance")
    {
        int VHML_N=10;//Размер массива
        double *x;
        x=new double[VHML_N];
        double *y;
        y=new double[VHML_N];
        //Заполним случайными числами
        HML_RandomRealVector (x,0,10,VHML_N);
        HML_RandomRealVector (y,0,10,VHML_N);

        //Вызов функции
        double SampleCovariance=HML_SampleCovariance(x,y,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Первый массив", "x");
        // Первый массив:
        //x =
        //3.06915
        //9.92218
        //2.5592
        //9.19586
        //8.23486
        //1.49231
        //3.93158
        //4.97345
        //6.78223
        //1.50909

        HML_ShowVector (y,VHML_N,"Второй массив", "y");
        // Второй массив:
        //y =
        //7.00226
        //6.10626
        //3.22845
        //0.000305176
        //5.9494
        //2.27203
        //6.9046
        //8.87909
        //0.3125
        //4.01459

        HML_ShowNumber (SampleCovariance,"Значение выборочной ковариации", "SampleCovariance");
        // Значение выборочной ковариации:
        //SampleCovariance=-0.955199

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="HML_Variance")
    {
        int VHML_N=10;//Размер массива
        double *x;
        x=new double[VHML_N];
        //Заполним случайными числами
        HML_RandomRealVector (x,0,10,VHML_N);

        //Вызов функции
        double Variance=HML_Variance(x,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Массив", "x");
        //Массив:
        //x =
        //4.61365
        //6.74438
        //0.18219
        //9.68933
        //8.77136
        //2.5177
        //1.89178
        //6.16455
        //8.45978
        //4.33228

        HML_ShowNumber (Variance,"Значение выборочной дисперсии", "Variance");
        //Значение выборочной дисперсии:
        //Variance=10.1197

        delete [] x;
    }

    if (NameFunction=="HML_SinglepointCrossover")
    {
        int VHML_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VHML_N];
        int *Parent2;
        Parent2=new int[VHML_N];
        int *Child;
        Child=new int[VHML_N];
        HML_RandomBinaryVector(Parent1,VHML_N);
        HML_RandomBinaryVector(Parent2,VHML_N);

        //Получим потомка Child
        HML_SinglepointCrossover(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0	1	1	0	0	1	0	1	1	1

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	0	0	1	0	1	0	0	0	0

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0	1	1	0	0	1	0	1	1	1

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_TwopointCrossover")
    {
        int VHML_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VHML_N];
        int *Parent2;
        Parent2=new int[VHML_N];
        int *Child;
        Child=new int[VHML_N];
        HML_RandomBinaryVector(Parent1,VHML_N);
        HML_RandomBinaryVector(Parent2,VHML_N);

        //Получим потомка Child
        HML_TwopointCrossover(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //1	1	0	0	1	1	0	0	0	0

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	1	1	0	0	1	0	0	1	0

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0	1	1	0	0	1	0	0	1	0

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_UniformCrossover")
    {
        int VHML_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VHML_N];
        int *Parent2;
        Parent2=new int[VHML_N];
        int *Child;
        Child=new int[VHML_N];
        HML_RandomBinaryVector(Parent1,VHML_N);
        HML_RandomBinaryVector(Parent2,VHML_N);

        //Получим потомка Child
        HML_UniformCrossover(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //1	1	0	1	1	1	1	1	1	0

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	0	0	0	1	0	1	1	0	0

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //1	1	0	0	1	0	1	1	1	0

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_BinaryToDecimalFromPart")
    {
        int VHML_N=8;//Размер массива
        int *a;
        a=new int[VHML_N];
        HML_RandomBinaryVector(a,VHML_N);

        int Begin=2;

        //Вызов функции
        int x=HML_BinaryToDecimalFromPart(a,Begin,5);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Бинарная строка", "a");
        //Бинарная строка:
        //a =
        //0	0	1	0	1	0	0	0

        HML_ShowNumber (Begin,"Двоичное число состоит из 5 символов начиная с", "номера");
        //Двоичное число состоит из 5 символов начиная с:
        //номера=2

        HML_ShowNumber (x,"Было закодировано", "x");
        //Было закодировано:
        //x=20

        delete [] a;
    }

    if (NameFunction=="HML_BinaryToDecimal")
    {
        int VHML_N=8;//Размер массива
        int *a;
        a=new int[VHML_N];
        HML_RandomBinaryVector(a,VHML_N);

        //Вызов функции
        int x=HML_BinaryToDecimal(a,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Двоичное число", "a");
        //Двоичное число:
        //a =
        //0	1	1	1	1	0	1	0

        HML_ShowNumber (x,"Было закодировано", "x");
        //Было закодировано:
        //x=122

        delete [] a;
    }

    if (NameFunction=="HML_BinaryVectorToRealVector")
    {
        int n=10;//Размер массива
        int *BinaryVector;
        BinaryVector=new int[n];
        //Заполним случайно
        HML_RandomBinaryVector(BinaryVector,n);

        int VHML_N=2;//Пусть был закодирован двумерный вектор
        double *RealVector;//Вещественный вектор
        RealVector=new double[VHML_N];
        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[VHML_N];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[VHML_N];
        int *Lengthi;//массив значений, сколько на каждую координату отводится бит в бинраной строке;
        Lengthi=new int[VHML_N];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        HML_FillVector(Left,VHML_N,0.);//Пусть будет интервал [0;1]
        HML_FillVector(Right,VHML_N,1.);
        HML_FillVector(Lengthi,VHML_N,5);//По сумме элементов вектор должен равен n (длине бинарной строки)

        //Вызов функции
        HML_BinaryVectorToRealVector(BinaryVector,RealVector,Left,Right,Lengthi,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (BinaryVector,n,"Бинарная строка", "BinaryVector");
        //Бинарная строка:
        //BinaryVector =
        //0	1	0	1	1	1	0	1	0	1

        HML_ShowVectorT (RealVector,VHML_N,"Был закодирован вектор", "RealVector");
        //Был закодирован вектор:
        //RealVector =
        //0.34375	0.65625

        delete [] BinaryVector;
        delete [] RealVector;
        delete [] Left;
        delete [] Right;
        delete [] Lengthi;
    }

    if (NameFunction=="HML_GrayCodeToBinaryFromPart")
    {
        int VHML_N=8;//Размер массива
        int *VectorWithGrayCode;
        VectorWithGrayCode=new int[VHML_N];
        //Заполним случайно нулями и единицами
        HML_RandomBinaryVector(VectorWithGrayCode,VHML_N);

        int *VectorWithBinaryCode;
        VectorWithBinaryCode=new int[VHML_N];
        HML_FillVector(VectorWithBinaryCode,VHML_N,-1);

        int Begin=2;

        //Вызов функции
        HML_GrayCodeToBinaryFromPart(VectorWithGrayCode,VectorWithBinaryCode,Begin,5);

        //Используем полученный результат
        HML_ShowVectorT (VectorWithGrayCode,VHML_N,"Строка, содержащая код Грея", "a");
        //Строка, содержащая код Грея:
        //a =
        //1	0	0	1	1	1	0	0

        HML_ShowNumber (Begin,"Двоичное число состоит из 5 символов начиная с", "номера");
        //Двоичное число состоит из 5 символов начиная с:
        //номера=2

        HML_ShowVectorT (VectorWithBinaryCode,VHML_N,"Строка, содержащая бинарный код, полученый из кода Грея", "a");
        //Строка, содержащая бинарный код, полученый из кода Грея:
        //a =
        //-1	-1	0	1	0	1	1	-1

        delete [] VectorWithGrayCode;
        delete [] VectorWithBinaryCode;
    }

    if (NameFunction=="HML_GrayCodeToBinary")
    {
        int VHML_N=5;//Размер массива
        int *GrayCode;
        GrayCode=new int[VHML_N];
        //Получим случайный Грей код
        HML_RandomBinaryVector(GrayCode,VHML_N);

        int *BinaryCode;
        BinaryCode=new int[VHML_N];

        //Вызов функции
        HML_GrayCodeToBinary(GrayCode,BinaryCode,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (GrayCode,VHML_N,"Грей код", "a");
        //Грей код:
        //a =
        //1	1	0	1	1

        HML_ShowVectorT (BinaryCode,VHML_N,"Бинарный код, полученый из кода Грея", "a");
        //Бинарный код, полученый из кода Грея:
        //a =
        //1	0	0	1	0

        delete [] GrayCode;
        delete [] BinaryCode;
    }

    if (NameFunction=="HML_BinaryGrayVectorToRealVector")
    {
        int n=10;//Размер массива
        int *BinaryGrayVector;
        BinaryGrayVector=new int[n];
        //Заполним случайно
        HML_RandomBinaryVector(BinaryGrayVector,n);

        int VHML_N=2;//Пусть был закодирован двумерный вектор
        double *RealVector;//Вещественный вектор
        RealVector=new double[VHML_N];
        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[VHML_N];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[VHML_N];
        int *Lengthi;//массив значений, сколько на каждую координату отводится бит в бинраной строке;
        Lengthi=new int[VHML_N];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        HML_FillVector(Left,VHML_N,0.);//Пусть будет интервал [0;1]
        HML_FillVector(Right,VHML_N,1.);
        HML_FillVector(Lengthi,VHML_N,5);//По сумме элементов вектор должен равен n (длине бинарной строки)

        //Вызов функции
        HML_BinaryGrayVectorToRealVector(BinaryGrayVector,n,RealVector,Left,Right,Lengthi,VHML_N);

        //Используем полученный результат

        HML_ShowVectorT (BinaryGrayVector,n,"Бинарная строка Грея кода", "BinaryVector");
        //Бинарная строка Грея кода:
        //BinaryVector =
        //1	0	1	0	1	0	0	0	1	0

        HML_ShowVectorT (RealVector,VHML_N,"Был закодирован вектор", "RealVector");
        //Был закодирован вектор:
        //RealVector =
        //0.78125	0.09375

        delete [] BinaryGrayVector;
        delete [] RealVector;
        delete [] Left;
        delete [] Right;
        delete [] Lengthi;

        //Для перегруженной функции
        n=10;//Размер массива
        BinaryGrayVector=new int[n];
        //Заполним случайно
        HML_RandomBinaryVector(BinaryGrayVector,n);

        VHML_N=2;//Пусть был закодирован двумерный вектор
        RealVector=new double[VHML_N];
        Left=new double[VHML_N];
        Right=new double[VHML_N];
        Lengthi=new int[VHML_N];

        int *TempBinaryVector;
        TempBinaryVector=new int[n];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        HML_FillVector(Left,VHML_N,0.);//Пусть будет интервал [0;1]
        HML_FillVector(Right,VHML_N,1.);
        HML_FillVector(Lengthi,VHML_N,5);//По сумме элементов вектор должен равен n (длине бинарной строки)

        //Вызов функции
        HML_BinaryGrayVectorToRealVector(BinaryGrayVector,RealVector,TempBinaryVector,Left,Right,Lengthi,VHML_N);

        //Используем полученный результат

        HML_ShowVectorT (BinaryGrayVector,n,"Бинарная строка Грея кода", "BinaryVector");
        // Бинарная строка Грея кода:
        //BinaryVector =
        //0	0	1	0	0	1	1	1	0	1

        HML_ShowVectorT (RealVector,VHML_N,"Был закодирован вектор", "RealVector");
        //Был закодирован вектор:
        //RealVector =
        //0.21875	0.6875

        delete [] BinaryGrayVector;
        delete [] RealVector;
        delete [] Left;
        delete [] Right;
        delete [] Lengthi;
        delete [] TempBinaryVector;
    }

    if (NameFunction=="HML_RandomVectorOfPermutation")
    {
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];

        //Вызов функции
        HML_RandomVectorOfPermutation(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Строка-перестановка", "a");
        //Строка-перестановка:
        //a =
        //1
        //4
        //8
        //7
        //9
        //10
        //5
        //3
        //2
        //6

        delete [] a;
    }

    if (NameFunction=="HML_RandomMatrixOfPermutation")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=5;//Размер массива (число строк)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        //Вызов функции
        HML_RandomMatrixOfPermutation(a,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Матрица строк-перестановок", "a");
        //Матрица строк-перестановок:
        //a =
        //3	2	1	4	5
        //4	1	3	2	5
        //5	2	3	4	1
        //5	3	4	2	1
        //5	4	2	1	3
        //1	4	3	5	2
        //5	4	1	3	2
        //1	4	2	5	3
        //3	1	2	4	5
        //5	3	4	2	1

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_MutationBinaryMatrix")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        HML_RandomBinaryMatrix(a,VHML_N,VHML_M);//Случайная бинарная матрица
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная бинарная матрица", "a");
        // Случайная бинарная матрица:
        //a =
        //1	0	1
        //0	0	0
        //0	1	1
        //1	0	1
        //1	0	1
        //1	0	1
        //0	0	1
        //1	1	0
        //1	0	1
        //1	1	0

        double ProbabilityOfMutation=0.1;//Вероятность мутации

        //Вызов функции
        HML_MutationBinaryMatrix(a,ProbabilityOfMutation,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Мутированная бинарная матрица", "a");
        //Мутированная бинарная матрица:
        //a =
        //1	1	1
        //1	0	0
        //0	1	1
        //1	0	1
        //1	0	1
        //1	0	1
        //0	0	1
        //1	1	0
        //1	0	1
        //1	1	1

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_TournamentSelectionWithReturn")
    {
        int i;
        int VHML_N=7;//Размер массива
        double *Fitness;
        Fitness=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            Fitness[i]=HML_RandomNumber();

        int SizeTournament=3;// Размер турнира

        //Вызов функции
        int Number=HML_TournamentSelectionWithReturn(Fitness,SizeTournament,VHML_N);

        //Используем полученный результат

        HML_ShowVector (Fitness,VHML_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.883148
        //0.370209
        //0.0719604
        //0.311371
        //0.558594
        //0.42215
        //0.011322

        HML_ShowNumber (Number,"Номер выбранного индивида", "Number");
        //Номер выбранного индивида:
        //Number=4

        delete [] Fitness;
    }

    if (NameFunction=="HML_TournamentSelection")
    {
        int i;
        int VHML_N=7;//Размер массива
        double *Fitness;
        Fitness=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            Fitness[i]=HML_RandomNumber();

        int SizeTournament=3;// Размер турнира

        //Вызов функции
        int Number=HML_TournamentSelection(Fitness,SizeTournament,VHML_N);

        //Используем полученный результат

        HML_ShowVector (Fitness,VHML_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.858643
        //0.460541
        //0.469696
        //0.454315
        //0.594543
        //0.000457764
        //0.476135


        HML_ShowNumber (SizeTournament,"Размер турнираа", "SizeTournament");
        // Размер турнираа:
        //SizeTournament=3

        HML_ShowNumber (Number,"Номер выбранного индивида", "Number");
        //Номер выбранного индивида:
        //Number=6

        delete [] Fitness;

        //Для переопределенной функции
        VHML_N=7;//Размер массива
        Fitness=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            Fitness[i]=HML_RandomNumber();

        int *Taken;//Информация о том, в турнире или нет индивид (Служебный массив)
        Taken=new int[VHML_N];

        SizeTournament=3;// Размер турнира

        //Вызов функции
        Number=HML_TournamentSelection(Fitness,SizeTournament,Taken,VHML_N);

        //Используем полученный результат

        HML_ShowVector (Fitness,VHML_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.598633
        //0.396423
        //0.756683
        //0.123505
        //0.0546875
        //0.542511
        //0.605499

        HML_ShowNumber (SizeTournament,"Размер турнира", "SizeTournament");
        //Размер турнира:
        //SizeTournament=3

        HML_ShowNumber (Number,"Номер выбранного индивида", "Number");
        //Номер выбранного индивида:
        //Number=2

        delete [] Fitness;
        delete [] Taken;
    }

    if (NameFunction=="HML_MakeVectorOfRankForRankSelection")
    {
        int i;
        int VHML_N=7;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            Fitness[i]=HML_RandomUniformInt(1,10)/10.;

        double *Rank;
        Rank=new double[VHML_N];

        //Вызов функции
        HML_MakeVectorOfRankForRankSelection(Fitness,Rank,VHML_N);

        //Используем полученный результат

        HML_ShowVector (Fitness,VHML_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.3
        //0.5
        //0.7
        //0.5
        //0.8
        //0.1
        //0.6

        HML_ShowVector (Rank,VHML_N,"Массив рангов", "Rank");
        //Массив рангов:
        //Rank =
        //2
        //3.5
        //6
        //3.5
        //7
        //1
        //5

        delete [] Fitness;
        delete [] Rank;
    }

    if (NameFunction=="HML_NormalizationVectorOne")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(-100,100);

        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //-76
        //-100
        //-2
        //97
        //99
        //49
        //87
        //-49
        //-13
        //7

        //Вызов функции
        HML_NormalizationVectorOne(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Нормализованный вектор", "a");
        //Нормализованный вектор:
        //a =
        //0.021838
        //0
        //0.089172
        //0.179254
        //0.181074
        //0.135578
        //0.170155
        //0.0464058
        //0.0791629
        //0.0973612

        HML_ShowNumber (HML_SumVector(a,VHML_N),"Его сумма", "Sum");
        //Его сумма:
        //Sum=1

        delete [] a;
    }

    if (NameFunction=="HML_NormalizationVectorMaxMin")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(-100,100);

        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //38
        //-35
        //-59
        //-15
        //-98
        //24
        //83
        //-16
        //73
        //45

        //Вызов функции
        HML_NormalizationVectorMaxMin(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Нормализованный вектор", "a");
        //Нормализованный вектор:
        //a =
        //0.751381
        //0.348066
        //0.21547
        //0.458564
        //0
        //0.674033
        //1
        //0.453039
        //0.944751
        //0.790055

        delete [] a;
    }

    if (NameFunction=="HML_NormalizationVectorAll")
    {
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        HML_RandomRealVector(a,-100,100,VHML_N);

        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //-41.1987
        //81.2317
        //-64.386
        //58.4839
        //78.5706
        //11.8958
        //52.179
        //47.5952
        //-98.4924
        //-47.6013

        //Вызов функции
        HML_NormalizationVectorAll(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Нормализованный вектор", "a");
        // Нормализованный вектор:
        //a =
        //0.0118487
        //0.99392
        //0.0076469
        //0.991594
        //0.993716
        //0.961228
        //0.990598
        //0.989711
        //0.00502551
        //0.0102878

        delete [] a;
    }

    if (NameFunction=="HML_MakeVectorOfProbabilityForProportionalSelectionV2")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VHML_N];
        //Заполним вектор случайными значениями пригодностей индивидов
        //на практике, конечно, пригодности вычисляются, например, в
        //процессе работы ГА
        for (i=0;i<VHML_N;i++) Fitness[i]=HML_RandomNumber();

        //Для работы этого варианта пропорциональной селекции нужен
        //массив вероятностей выбора индивидов для порпоциональной селекции;
        double *VectorProbability;
        VectorProbability=new double[VHML_N];

        //Вызов функции
        HML_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorProbability,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Fitness,VHML_N,"Вектор пригодностей индивидов", "a");
        //Вектор пригодностей индивидов:
        //a =
        //0.902191
        //0.804932
        //0.0402527
        //0.344849
        //0.375427
        //0.0223999
        //0.650024
        //0.207642
        //0.275391
        //0.164215

        HML_ShowVector (VectorProbability,VHML_N,"Вектор вероятностей выбора индивидов", "VectorProbability");
        // Вектор вероятностей выбора индивидов:
        //VectorProbability =
        //0.246902
        //0.219607
        //0.00501015
        //0.090491
        //0.0990725
        //0
        //0.176135
        //0.0519856
        //0.0709985
        //0.0397986

        HML_ShowNumber (HML_SumVector(VectorProbability,VHML_N),"Его сумма", "Sum");
        //Его сумма:
        //Sum=1

        delete [] Fitness;
        delete [] VectorProbability;
    }

    if (NameFunction=="HML_SelectItemOnProbability")
    {
        int VHML_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VHML_N];
        //Заполним вектор случайными значениями вероятностей
        HML_RandomVectorOfProbability(a, VHML_N);

        //Вызов функции
        int Number=HML_SelectItemOnProbability(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Вектор вероятностей выбора", "a");
        // Вектор вероятностей выбора:
        //Вектор вероятностей выбора:
        //a =
        //0.0701006
        //0.190423
        //0.0231631
        //0.160255
        //0.0983935
        //0.038739
        //0.166252
        //0.105259
        //0.0621408
        //0.0852747

        HML_ShowNumber (Number,"Номер выбранного элемента", "Number");
        // Номер выбранного элемента:
        //Number=6

        delete [] a;
    }

    if (NameFunction=="HML_ProportionalSelection")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VHML_N];
        //Заполним вектор случайными значениями пригодностей индивидов
        //на практике, конечно, пригодности вычисляются, например, в
        //процессе работы ГА
        for (i=0;i<VHML_N;i++) Fitness[i]=HML_RandomNumber();

        //Вызов функции
        int Number=HML_ProportionalSelection(Fitness,VHML_N);

        //Используем полученный результат

        //Например:
        HML_ShowVector (Fitness,VHML_N,"Вектор пригодностей индивидов", "a");
        // Вектор пригодностей индивидов:
        //a =
        //0.368073
        //0.474609
        //0.297089
        //0.373474
        //0.102203
        //0.774292
        //0.487335
        //0.747742
        //0.505646
        //0.901184

        HML_ShowNumber (Number,"Номер выбранного индивида", "Number");
        //Номер выбранного индивида:
        //Number=5

        delete [] Fitness;
    }

    if (NameFunction=="HML_ProportionalSelectionV2")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VHML_N];
        //Заполним вектор случайными значениями пригодностей индивидов
        //на практике, конечно, пригодности вычисляются, например, в
        //процессе работы ГА
        for (i=0;i<VHML_N;i++) Fitness[i]=HML_RandomNumber();

        //Для работы этого варианта пропорциональной селекции нужен
        //массив вероятностей выбора индивидов для порпоциональной селекции;
        double *VectorProbability;
        VectorProbability=new double[VHML_N];
        //Сформируем этот массив
        HML_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorProbability,VHML_N);

        //Вызов функции
        int Number=HML_ProportionalSelectionV2(VectorProbability,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Fitness,VHML_N,"Вектор пригодностей индивидов", "a");
        // Вектор пригодностей индивидов:
        //a =
        //0.681061
        //0.629517
        //0.697021
        //0.140045
        //0.221649
        //0.203461
        //0.702576
        //0.998077
        //0.853607
        //0.19928

        HML_ShowVector (VectorProbability,VHML_N,"Вектор вероятностей выбора индивидов", "VectorProbability");
        // Вектор вероятностей выбора индивидов:
        //VectorProbability =
        //0.137809
        //0.124679
        //0.141874
        //0
        //0.0207864
        //0.0161534
        //0.143289
        //0.21856
        //0.18176
        //0.0150884

        HML_ShowNumber (HML_SumVector(VectorProbability,VHML_N),"Его сумма", "Sum");
        // Его сумма:
        //Sum=1

        HML_ShowNumber (Number,"Номер выбранного индивида", "Number");

        // Номер выбранного индивида:
        //Number=6

        delete [] Fitness;
        delete [] VectorProbability;
    }

    if (NameFunction=="HML_ProportionalSelectionV3")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VHML_N];
        //Заполним вектор случайными значениями пригодностей индивидов
        //на практике, конечно, пригодности вычисляются, например, в
        //процессе работы ГА
        for (i=0;i<VHML_N;i++) Fitness[i]=HML_RandomNumber();

        //Вызов функции
        int Number=HML_ProportionalSelectionV3(Fitness,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Fitness,VHML_N,"Вектор пригодностей индивидов", "a");
        // Вектор пригодностей индивидов:
        //a =
        //0.774231
        //0.15918
        //0.671448
        //0.0546265
        //0.881012
        //0.766541
        //0.638275
        //0.0705261
        //0.234528
        //0.0510559

        HML_ShowNumber (Number,"Номер выбранного индивида", "Number");
        // Номер выбранного индивида:
        //Number=0

        delete [] Fitness;
    }

    if (NameFunction=="HML_RankSelection")
    {
        int i;
        int VHML_N=7;//Размер массива
        double *Fitness;
        Fitness=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            Fitness[i]=HML_RandomUniformInt(1,10)/10.;

        double *Rank;
        Rank=new double[VHML_N];

        double *VectorProbability;
        VectorProbability=new double[VHML_N];

        //Сформируем вектор рангов
        HML_MakeVectorOfRankForRankSelection(Fitness,Rank,VHML_N);
        //Из вектора рангов получим вектор вероятностей выбора
        HML_MakeVectorOfProbabilityForProportionalSelectionV2(Rank,VectorProbability,VHML_N);

        //Вызов функции
        int Number=HML_RankSelection(VectorProbability,VHML_N);

        //Используем полученный результат

        HML_ShowVector (Fitness,VHML_N,"Массив пригодностей", "Fitness");
        // Массив пригодностей:
        //Fitness =
        //0.2
        //0.2
        //0.6
        //0.8
        //0.4
        //0.3
        //0.2

        HML_ShowVector (Rank,VHML_N,"Массив рангов", "Rank");
        // Массив рангов:
        //Rank =
        //2
        //2
        //6
        //7
        //5
        //4
        //2

        HML_ShowVector (VectorProbability,VHML_N,"Массив вероятностей выбора", "VectorProbability");
        //Массив вероятностей выбора:
        //VectorProbability =
        //0
        //0
        //0.285714
        //0.357143
        //0.214286
        //0.142857
        //0

        HML_ShowNumber (Number,"Номер выбранного индивида", "Number");
        // Номер выбранного индивида:
        //Number=3

        delete [] Fitness;
        delete [] Rank;
        delete [] VectorProbability;
    }

    if (NameFunction=="HML_StandartBinaryGeneticAlgorithm")
    {
        int ChromosomeLength=50;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        int *ParametersOfStandartBinaryGeneticAlgorithm;
        ParametersOfStandartBinaryGeneticAlgorithm=new int[6];
        ParametersOfStandartBinaryGeneticAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfStandartBinaryGeneticAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfStandartBinaryGeneticAlgorithm[2]=TypeOfSel;//Тип селекции
        ParametersOfStandartBinaryGeneticAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfStandartBinaryGeneticAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfStandartBinaryGeneticAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения

        int *Decision;//бинарное решение
        Decision=new int[ChromosomeLength];
        double ValueOfFitnessFunction;//значение функции пригодности в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_StandartBinaryGeneticAlgorithm (ParametersOfStandartBinaryGeneticAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        //Как прошел запуск:
        //VHML_Success=1

        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

            HML_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=50
        }

        delete [] ParametersOfStandartBinaryGeneticAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="HML_StandartRealGeneticAlgorithm")
    {
        int ChromosomeLength=2;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        int *ParametersOfStandartRealGeneticAlgorithm;
        ParametersOfStandartRealGeneticAlgorithm=new int[7];
        ParametersOfStandartRealGeneticAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfStandartRealGeneticAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfStandartRealGeneticAlgorithm[2]=TypeOfSel;//Тип селекции
        ParametersOfStandartRealGeneticAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfStandartRealGeneticAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfStandartRealGeneticAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения
        ParametersOfStandartRealGeneticAlgorithm[6]=0;//Тип формирования нового поколения

        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[ChromosomeLength];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[ChromosomeLength];
        int *NumberOfParts;//на сколько делить каждую координату
        NumberOfParts=new int[ChromosomeLength];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        HML_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        HML_FillVector(Right,ChromosomeLength,5.);
        HML_FillVector(NumberOfParts,ChromosomeLength,HML_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_StandartRealGeneticAlgorithm (ParametersOfStandartRealGeneticAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //
            HML_ShowNumber(ValueOfFitnessFunction,"Значение целевой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction =
        }

        delete [] ParametersOfStandartRealGeneticAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="HML_StandartGeneticAlgorithm")
    {
        int ChromosomeLength=50;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        int *ParametersOfStandartBinaryGeneticAlgorithm;
        ParametersOfStandartBinaryGeneticAlgorithm=new int[6];
        ParametersOfStandartBinaryGeneticAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfStandartBinaryGeneticAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfStandartBinaryGeneticAlgorithm[2]=TypeOfSel;//Тип селекции
        ParametersOfStandartBinaryGeneticAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfStandartBinaryGeneticAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfStandartBinaryGeneticAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения

        int *Decision;//бинарное решение
        Decision=new int[ChromosomeLength];
        double ValueOfFitnessFunction;//значение функции пригодности в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_StandartGeneticAlgorithm (ParametersOfStandartBinaryGeneticAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        //Как прошел запуск:
        //VHML_Success=1

        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

            HML_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=50
        }

        delete [] ParametersOfStandartBinaryGeneticAlgorithm;
        delete [] Decision;

        //Для переопределенной функции
        {//чтобы не удалять объявления переменных, заключим в скобки
            int ChromosomeLength=2;//Длина хромосомы
            int CountOfFitness=50*50;//Число вычислений целевой функции
            int TypeOfSel=1;//Тип селекции
            int TypeOfCros=0;//Тип скрещивания
            int TypeOfMutation=1;//Тип мутации
            int TypeOfForm=0;//Тип формирования нового поколения

            int *ParametersOfStandartRealGeneticAlgorithm;
            ParametersOfStandartRealGeneticAlgorithm=new int[7];
            ParametersOfStandartRealGeneticAlgorithm[0]=ChromosomeLength;//Длина хромосомы
            ParametersOfStandartRealGeneticAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
            ParametersOfStandartRealGeneticAlgorithm[2]=TypeOfSel;//Тип селекции
            ParametersOfStandartRealGeneticAlgorithm[3]=TypeOfCros;//Тип скрещивания
            ParametersOfStandartRealGeneticAlgorithm[4]=TypeOfMutation;//Тип мутации
            ParametersOfStandartRealGeneticAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения
            ParametersOfStandartRealGeneticAlgorithm[6]=0;//Тип формирования нового поколения

            double *Left;//массив левых границ изменения каждой вещественной координаты
            Left=new double[ChromosomeLength];
            double *Right;//массив правых границ изменения каждой вещественной координаты
            Right=new double[ChromosomeLength];
            int *NumberOfParts;//на сколько делить каждую координату
            NumberOfParts=new int[ChromosomeLength];

            //Заполним массивы
            //Причем по каждой коодинтате одинаковые значения выставим
            HML_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
            HML_FillVector(Right,ChromosomeLength,5.);
            HML_FillVector(NumberOfParts,ChromosomeLength,HML_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

            double *Decision;//вещественное решение
            Decision=new double[ChromosomeLength];
            double ValueOfFitnessFunction;//значение целевой функции в точке Decision
            int VHML_Success=0;//Успешен ли будет запуск cГА

            //Запуск алгоритма
            VHML_Success=HML_StandartGeneticAlgorithm (ParametersOfStandartRealGeneticAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

            //Используем полученный результат
            HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
            if (VHML_Success==1)
            {
                HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
                //Найденное решение:
                //Decision =
                HML_ShowNumber(ValueOfFitnessFunction,"Значение целевой функции","ValueOfFitnessFunction");
                //Значение целевой функции:
                //ValueOfFitnessFunction =
            }

            delete [] ParametersOfStandartRealGeneticAlgorithm;
            delete [] Decision;
            delete [] Left;
            delete [] Right;
            delete [] NumberOfParts;
        }//чтобы не удалять объявления переменных, заключим в скобки
    }

    if (NameFunction=="HML_TestFunction_Ackley")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-5,5);
        f=HML_TestFunction_Ackley(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //4.51813
        //-4.19861

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=13.645

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_ParaboloidOfRevolution")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-2,2);
        f=HML_TestFunction_ParaboloidOfRevolution(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        // Входной вектор:
        //x =
        //0.0842285
        //-1.04395

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=1.09692

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_Rastrigin")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-5,5);
        f=HML_TestFunction_Rastrigin(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        // Входной вектор:
        //x =
        //2.62268
        //3.52692

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=56.3483

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_Rosenbrock")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-2,2);
        f=HML_TestFunction_Rosenbrock(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        // Входной вектор:
        //x =
        //-1.28491
        //0.342896


        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=176.334

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_SumVector")
    {
        int VHML_N=10;//Размер массива (число строк)
        int *x;
        x=new int[VHML_N];
        //Получим случайный бинарный вектор
        HML_RandomBinaryVector(x,VHML_N);

        //Вызов функции
        double f=HML_TestFunction_SumVector(x,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Вектор", "x");
        //Вектор:
        //x =
        //0
        //0
        //1
        //0
        //0
        //1
        //1
        //1
        //0
        //1

        HML_ShowNumber (f,"Значение функции в точке", "f");
        //Значение функции в точке:
        //f=5

        delete [] x;
    }

    if (NameFunction=="HML_Factorial")
    {
        int a=HML_RandomUniformInt(0,10);

        double Result=HML_Factorial(a);

        //Используем полученный результат
        HML_ShowNumber(Result,"Факториал числа "+HML_NumberToText(a),"a!");
        //Факториал числа 3:
        //a!=6
    }

    if (NameFunction=="HML_KCombinations")
    {
        int n=10;
        int k=HML_RandomUniformInt(0,10);

        int C=HML_KCombinations(k,n);

        //Используем полученный результат
        HML_ShowNumber(C,"Число сочетаний по "+HML_NumberToText(k)+" элементов из " +HML_NumberToText(n),"C");
        //Число сочетаний по 8 элементов из 10:
        //C=45

    }

    if (NameFunction=="HML_ProbabilityOfTournamentSelection")
    {
        int i;
        int VHML_N=10;//размер популяции
        double *f=new double[VHML_N];//массив значений целевой функции
        double *p=new double[VHML_N];//массив значений веротяностей выбора индивидов
        int T=3; // размер турнира

        for (i=0;i<VHML_N;i++) f[i]=HML_RandomUniformInt(0,11)/10.;//заполним случайными значениями целевой функции

        HML_ShowVector (f,VHML_N,"Вектор значений целевой функции", "f");
        //Вектор значений целевой функции:
        //f =
        //0.9
        //0.4
        //0.4
        //0.5
        //1
        //0.8
        //0.5
        //0.8
        //0.8
        //0.4

        //Вызов функции
        double sum = HML_ProbabilityOfTournamentSelection(f,p,T,VHML_N);

        //Используем результат
        HML_ShowVector (p,VHML_N,"Вектор значений вероятностей выбора", "p");
        //Вектор значений вероятностей выбора:
        //p =
        //0.233333
        //0.00277778
        //0.00277778
        //0.0375
        //0.3
        //0.127778
        //0.0375
        //0.127778
        //0.127778
        //0.00277778

        HML_ShowNumber(sum,"Сумма вектора значений вероятностей выбора","sum");
        //Сумма вектора значений вероятностей выбора:
        //sum=1

        delete[] f;
        delete[] p;
    }

    if (NameFunction=="HML_MakeVectorOfProbabilityForRanklSelection")
    {
        int i;
        int VHML_N=7;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            Fitness[i]=HML_RandomUniformInt(1,10)/10.;

        double *Rank;
        Rank=new double[VHML_N];

        double *VectorProbability;
        VectorProbability=new double[VHML_N];

        //Получаем массив рангов
        HML_MakeVectorOfRankForRankSelection(Fitness,Rank,VHML_N);

        //Вызов функции
        HML_MakeVectorOfProbabilityForRanklSelection(Rank,VectorProbability,VHML_N);

        //Используем полученный результат

        HML_ShowVector (Fitness,VHML_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.5
        //0.7
        //0.3
        //0.9
        //0.8
        //0.7
        //0.9

        HML_ShowVector (Rank,VHML_N,"Массив рангов", "Rank");
        //Массив рангов:
        //Rank =
        //2
        //3.5
        //1
        //6.5
        //5
        //3.5
        //6.5

        HML_ShowVector (VectorProbability,VHML_N,"Вектор вероятностей выбора", "VectorProbability");
        //Вектор вероятностей выбора:
        //VectorProbability =
        //0.0714286
        //0.125
        //0.0357143
        //0.232143
        //0.178571
        //0.125
        //0.232143

        delete [] Fitness;
        delete [] Rank;
        delete [] VectorProbability;
    }

    if (NameFunction=="HML_MakeVectorOfRankZeroForRankSelection")
    {
        int i;
        int VHML_N=7;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VHML_N];
        for (i=0;i<VHML_N;i++)
            Fitness[i]=HML_RandomUniformInt(1,10)/10.;

        double *Rank;
        Rank=new double[VHML_N];

        //Вызов функции
        HML_MakeVectorOfRankZeroForRankSelection(Fitness,Rank,VHML_N);

        //Используем полученный результат

        HML_ShowVector (Fitness,VHML_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.3
        //0.8
        //0.2
        //0.9
        //0.1
        //0.9
        //0.4

        HML_ShowVector (Rank,VHML_N,"Массив рангов", "Rank");
        //Массив рангов:
        //Rank =
        //2
        //4
        //1
        //5.5
        //0
        //5.5
        //3

        delete [] Fitness;
        delete [] Rank;
    }

    if (NameFunction=="HML_RandomUniformIntIncluding")
    {
        double x;
        int s0=0,s1=0,s2=0,s3=0;

        //Вызов функции
        for (int i=0;i<1000;i++)
        {
            x=HML_RandomUniformIntIncluding(0,3);
            if (x==0) s0++;
            if (x==1) s1++;
            if (x==2) s2++;
            if (x==3) s3++;
        }

        //Используем полученный результат
        HML_ShowNumber(x,"Случайное целое число из интервала [0;3]","x");
        HML_ShowNumber(s0,"Число выпадений 0","s0");
        HML_ShowNumber(s1,"Число выпадений 1","s0");
        HML_ShowNumber(s2,"Число выпадений 2","s0");
        HML_ShowNumber(s3,"Число выпадений 3","s0");
        //Случайное целое число из интервала [0;3):
        //x=1
        //Число выпадений 0:
        //s0=324
        //Число выпадений 1:
        //s0=374
        //Число выпадений 2:
        //s0=302
        //Число выпадений 3:
        //s0=0

    }

    if (NameFunction=="HML_BubbleSortRowWithOtherConjugateRowsInMatrix")
    {
        int i;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        HML_RandomIntMatrix(a,0,5,VHML_N,VHML_M);

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //0	0	1	2	3
        //1	2	1	4	1
        //3	1	2	0	1
        //3	4	1	0	0
        //4	4	1	0	2

        int Row=2;//Будем сортировать строку под номером 2

        //Вызов функции

        HML_BubbleSortRowWithOtherConjugateRowsInMatrix(a, Row, VHML_N, VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица отсортированная по строке с номером "+HML_NumberToText(Row), "a");
        //Случайная матрица отсортированная по строке с номером 2:
        //a =
        //2	0	3	1	0
        //4	2	1	1	1
        //0	1	1	2	3
        //0	4	0	1	3
        //0	4	2	1	4

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_BubbleSortEveryRowInMatrix")
    {
        int i;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=6;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        HML_RandomIntMatrix(a,0,5,VHML_N,VHML_M);

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //Случайная матрица:
        //a =
        //3	1	2	1	1	2
        //0	1	4	0	2	1
        //4	4	4	3	2	1
        //1	3	0	3	4	0
        //2	3	1	1	2	3


        //Вызов функции
        HML_BubbleSortEveryRowInMatrix(a, VHML_N, VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица, где каждая строка отсортировна независимо", "a");
        //Случайная матрица, где каждая отсортировна независимо:
        //a =
        //1	1	1	2	2	3
        //0	0	1	1	2	4
        //1	2	3	4	4	4
        //0	0	1	3	3	4
        //1	1	2	2	3	3

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_BubbleSortColWithOtherConjugateColsInMatrix")
    {
        int i;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        HML_RandomIntMatrix(a,0,5,VHML_N,VHML_M);

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //4	0	1
        //4	0	4
        //2	2	0
        //2	3	1
        //1	3	1

        int Col=0;//Будем сортировать столбец под номером 2

        //Вызов функции

        HML_BubbleSortColWithOtherConjugateColsInMatrix(a, Col, VHML_N, VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица отсортированная по столбцу с номером "+HML_NumberToText(Col), "a");
        //Случайная матрица отсортированная по столбцу с номером 0:
        //a =
        //1	3	1
        //2	2	0
        //2	3	1
        //4	0	1
        //4	0	4

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_BubbleSortEveryColInMatrix")
    {
        int i;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=6;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        HML_RandomIntMatrix(a,0,5,VHML_N,VHML_M);

        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //4	1	4	3	0	4
        //2	1	1	1	0	3
        //0	4	2	2	0	3
        //1	2	2	2	4	0
        //3	0	2	4	1	4

        //Вызов функции
        HML_BubbleSortEveryColInMatrix(a, VHML_N, VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица, где каждый столбец отсортирован независимо", "a");
        //Случайная матрица, где каждый столбец отсортирован независимо:
        //a =
        //0	0	1	1	0	0
        //1	1	2	2	0	3
        //2	1	2	2	0	3
        //3	2	2	3	1	4
        //4	4	4	4	4	4

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_QuadraticEquation")
    {
        double a=HML_RandomUniformInt(1,10);
        double b=HML_RandomUniformInt(1,10);
        double c=HML_RandomUniformInt(1,10);
        double x1;
        double x2;

        int Result=HML_QuadraticEquation(a,b,c,&x1,&x2);;

        //Используем полученный результат
        HML_ShowText("Квадратное уравнение: "+HML_NumberToText(a)+"x^2+"+HML_NumberToText(b)+"x+"+HML_NumberToText(c)+"=0");
        //Квадратное уравнение: 1x^2+8x+5:
        HML_ShowNumber(Result,"Найдено ли решение","Result");
        //Найдено ли решение:
        //Result=1
        if (Result==1)
        {
            HML_ShowNumber(x1,"Первый корень квадратного уравнения","x1");
            //Первый корень квадратного уравнения:
            //x1=-0.683375
            HML_ShowNumber(x2,"Первый корень квадратного уравнения","x2");
            //Первый корень квадратного уравнения:
            //x2=-7.31662
        }
    }

    if (NameFunction=="HML_BellShapedKernelExp")
    {
        double z=HML_RandomUniform(-5,5);

        //Вызов функции
        double f=HML_BellShapedKernelExp(z);

        //Используем полученный результат
        HML_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.721436
        HML_ShowNumber(f,"Значение колоколообразного экспоненциального ядра","f");
        //Значение колоколообразного экспоненциального ядра:
        //f=0.302588
    }

    if (NameFunction=="HML_BellShapedKernelParabola")
    {
        double z=HML_RandomUniform(-5,5);

        //Вызов функции
        double f=HML_BellShapedKernelParabola(z);

        //Используем полученный результат
        HML_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.33905
        HML_ShowNumber(f,"Значение колоколообразного параболического ядра","f");
        //Значение колоколообразного параболического ядра:
        //f=0.327298
    }

    if (NameFunction=="HML_BellShapedKernelRectangle")
    {
        double z=HML_RandomUniform(-5,5);

        //Вызов функции
        double f=HML_BellShapedKernelRectangle(z);

        //Используем полученный результат
        HML_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.669556
        HML_ShowNumber(f,"Значение колоколообразного прямоугольного ядра","f");
        //Значение колоколообразного прямоугольного ядра:
        //f=0.5
    }

    if (NameFunction=="HML_BellShapedKernelTriangle")
    {
        double z=HML_RandomUniform(-5,5);

        //Вызов функции
        double f=HML_BellShapedKernelTriangle(z);

        //Используем полученный результат
        HML_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.362854
        HML_ShowNumber(f,"Значение колоколообразного треугольного ядра","f");
        //Значение колоколообразного треугольного ядра:
        //f=0.637146
    }

    if (NameFunction=="HML_DerivativeOfBellShapedKernelExp")
    {
        double z=HML_RandomUniform(-4,4);

        //Вызов функции
        double f=HML_DerivativeOfBellShapedKernelExp(z);

        //Используем полученный результат
        HML_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=-1.93701
        HML_ShowNumber(f,"Значение производной колоколообразного экспоненциального ядра","f");
        //Значение производной колоколообразного экспоненциального ядра:
        //f=0.192278
    }

    if (NameFunction=="HML_DerivativeOfBellShapedKernelParabola")
    {
        double z=HML_RandomUniform(-4,4);

        //Вызов функции
        double f=HML_DerivativeOfBellShapedKernelParabola(z);

        //Используем полученный результат
        HML_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=1.28394
        HML_ShowNumber(f,"Значение производной колоколообразного параболического ядра","f");
        //Значение производной колоколообразного параболического ядра:
        //f=-0.172047
    }

    if (NameFunction=="HML_DerivativeOfBellShapedKernelRectangle")
    {
        double z=HML_RandomUniform(-4,4);

        //Вызов функции
        double f=HML_DerivativeOfBellShapedKernelRectangle(z);

        //Используем полученный результат
        HML_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=3.146
        HML_ShowNumber(f,"Значение производной колоколообразного прямоугольного ядра","f");
        //Значение производной колоколообразного прямоугольного ядра:
        //f=0
    }

    if (NameFunction=="HML_DerivativeOfBellShapedKernelTriangle")
    {
        double z=HML_RandomUniform(-4,4);

        //Вызов функции
        double f=HML_DerivativeOfBellShapedKernelTriangle(z);

        //Используем полученный результат
        HML_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.365479
        HML_ShowNumber(f,"Значение производной колоколообразного треугольного ядра","f");
        //Значение производной колоколообразного треугольного ядра:
        //f=-1
    }

    if (NameFunction=="HML_TrapeziformFuzzyNumber")
    {
        double a=HML_RandomUniform(-4,4);
        double b=a+HML_RandomUniform(0,2);
        double c=b+HML_RandomUniform(0,2);
        double d=c+HML_RandomUniform(0,2);

        double x=HML_RandomUniform(a-1,d+1);

        //Вызов функции
        double f=HML_TrapeziformFuzzyNumber (x,a,b,c,d);

        //Используем полученный результат
        HML_ShowNumber(x,"Значение параметра","x");
        //Значение параметра:
        //x=-0.932339
        HML_ShowNumber(a,"Значение первого параметра трапецевидного нечеткого числа","a");
        //Значение первого параметра трапецевидного нечеткого числа:
        //a=-1.71997
        HML_ShowNumber(b,"Значение второго параметра трапецевидного нечеткого числа","b");
        //Значение второго параметра трапецевидного нечеткого числа:
        //b=-0.446045
        HML_ShowNumber(c,"Значение третьего параметра трапецевидного нечеткого числа","c");
        //Значение третьего параметра трапецевидного нечеткого числа:
        //c=-0.0568848
        HML_ShowNumber(d,"Значение последнего параметра трапецевидного нечеткого числа","d");
        //Значение последнего параметра трапецевидного нечеткого числа:
        //d=0.253784
        HML_ShowNumber(f,"Значение функция принадлежности трапециевидного нечеткого числа","f");
        //Значение функция принадлежности трапециевидного нечеткого числа:
        //f=0.618271
    }

    if (NameFunction=="HML_ProductOfElementsOfVector")
    {
        int VHML_N=5;//Размер массива
        double p;
        double *a;
        a=new double[VHML_N];

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomUniformIntIncluding(1,4);//Заполняем случайными значениями

        //Вызов функции
        p=HML_ProductOfElementsOfVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //4
        //3
        //1
        //3
        //2

        HML_ShowNumber (p,"Произведение элементов массива", "p");
        //Произведение элементов массива:
        //p=72

        delete [] a;
    }

    if (NameFunction=="HML_MixedMultiLogicVectorOfFullSearch")
    {
        int i;
        int N=3;
        int *x;
        x=new int[N];
        int *y;
        y=new int[N];

        x[0]=3;
        x[1]=2;
        x[2]=3;

        int P=HML_ProductOfElementsOfVector(x,N);

        HML_ShowVector(x,N,"Сколько каждого параметра в штуках","x");
        //Сколько каждого параметра в штуках:
        //x =
        //3
        //2
        //3

        for (i=0;i<P;i++)
        {
            HML_ShowNumber(i,"<hr>Номер итерации", "i");
            //Номер итерации:
            //i=0

            //Вызов функции
            HML_MixedMultiLogicVectorOfFullSearch(y,i,x,N);

            HML_ShowVectorT(y,N,"Необходимый вектор","y");
            //Необходимый вектор:
            //y =
            //0	0	0
        }

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="HML_SearchElementInVector")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniformInt(0,4);

        int x=2;

        //Вызов функции
        int Number=HML_SearchElementInVector(a,x,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //3
        //3
        //0
        //1
        //0
        //2
        //2
        //1
        //3
        //1

        HML_ShowNumber (x,"Искомое число", "x");
        //Искомое число:
        //x=2

        HML_ShowNumber (Number,"Номер первого элемента, равного искомому", "Number");
        //Номер первого элемента, равного искомому:
        //Number=5

        delete [] a;
    }

    if (NameFunction=="HML_EqualityOfMatrixes")
    {
        int i,j;
        int VHML_N=2;//Размер массива (число строк)
        int VHML_M=2;//Размер массива (число столбцов)

        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                a[i][j]=HML_RandomUniformInt(0,2);

        int **b;
        b=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) b[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            for (j=0;j<VHML_M;j++)
                b[i][j]=HML_RandomUniformInt(0,2);

        //Вызов функции
        bool Equality=HML_EqualityOfMatrixes(a,b,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //1	1
        //0	1

        HML_ShowMatrix (b,VHML_N,VHML_M,"Случайная матрица", "b");
        //Случайная матрица:
        //b =
        //1	1
        //0	1

        HML_ShowNumber (Equality,"Равны ли матрицы", "Equality");
        //Равны ли матрицы:
        //Equality=1

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;

        for (i=0;i<VHML_N;i++) delete [] b[i];
        delete [] b;
    }

    if (NameFunction=="HML_DependentNoiseInVector")
    {
        int VHML_N=10;//Размер массива
        double *x;
        x=new double[VHML_N];
        //Заполним массив номерами от 1
        HML_OrdinalVector(x,VHML_N);
        HML_ShowVector (x,VHML_N,"Вектор", "x");
        //Вектор:
        //x =
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9
        //10

        double percent=double(HML_RandomUniformInt(0,100));//Процент помехи

        //Вызов функции
        HML_DependentNoiseInVector(x,percent,VHML_N);

        //Используем полученный результат

        HML_ShowNumber (percent,"Процент помехи", "percent");
        //Процент помехи:
        //percent=6
        HML_ShowVector (x,VHML_N,"Вектор с зависимой помехой", "x");
        //Вектор с помехой:
        //Вектор с помехой:
        //x =
        //0.865099
        //2.50058
        //2.43314
        //4.38595
        //3.98511
        //5.36837
        //8.42834
        //7.18024
        //9.33134
        //10.5783

        delete [] x;
    }

    if (NameFunction=="HML_Minkovski")
    {
        int VHML_N=5;//Размер массива
        double *x;
        x=new double[VHML_N];
        double *y;
        y=new double[VHML_N];
        //Заполним случайными числами
        HML_RandomRealVector (x,0,10,VHML_N);
        HML_RandomRealVector (y,0,10,VHML_N);

        int r=3;

        //Вызов функции
        double metric=HML_Minkovski(x,y,r,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Первый массив", "x");
        //Первый массив:
        //x =
        //8.2312
        //2.74628
        //9.36371
        //7.31995
        //0.139465

        HML_ShowVector (y,VHML_N,"Второй массив", "y");
        //Второй массив:
        //y =
        //6.2793
        //5.07324
        //9.01978
        //5.29297
        //9.84436

        HML_ShowNumber (metric,"Значение метрики Минковского", "metric");
        //Значение метрики Минковского:
        //metric=9.8044

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="HML_RealMonteCarloAlgorithm")
    {
        int ChromosomeLength=2;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции

        int *ParametersOfAlgorithm;
        ParametersOfAlgorithm=new int[2];
        ParametersOfAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции

        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[ChromosomeLength];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[ChromosomeLength];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        HML_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        HML_FillVector(Right,ChromosomeLength,5.);

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_RealMonteCarloAlgorithm (ParametersOfAlgorithm,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1.91864	1.93604
            HML_ShowNumber(ValueOfFitnessFunction,"Значение целtвой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction=-0.0107109
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="HML_DichotomyOptimization")
    {
        double Left=-5;
        double Right=5;
        double Interval=0.01;
        double Epsilon=0.001;
        double x,f;

        //Вызов функции
        HML_DichotomyOptimization (Left, Right, Func4, Interval, Epsilon, &x, &f);

        //Используем полученный результат
        HML_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=0.998335

        HML_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=2.77073e-06
    }

    if (NameFunction=="HML_FibonacciOptimization")
    {
        double Left=-5;
        double Right=5;
        int Count=30;
        double x,f;

        //Вызов функции
        HML_FibonacciOptimization (Left, Right, Func4, Count, &x, &f);

        //Используем полученный результат
        HML_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1

        HML_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=3.7817e-12
    }

    if (NameFunction=="HML_GoldenSectionOptimization")
    {
        double Left=-5;
        double Right=5;
        double Interval=0.001;
        double x,f;

        //Вызов функции
        HML_GoldenSectionOptimization (Left, Right, Func4, Interval, &x, &f);

        //Используем полученный результат
        HML_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=0.999934

        HML_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=4.37013e-09
    }

    if (NameFunction=="HML_QuadraticFitOptimization")
    {
        double Left=-5;
        double Right=5;
        double Epsilon=0.001;
        double Epsilon2=0.001;
        double x,f;

        //Вызов функции
        HML_QuadraticFitOptimization (Left, Right, Func4, Epsilon,Epsilon2, &x, &f);

        //Используем полученный результат
        HML_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1

        HML_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=0
    }

    if (NameFunction=="HML_RealMonteCarloOptimization")
    {
        double Left=-5;
        double Right=5;
        int Count=30;
        double x,f;

        //Вызов функции
        HML_RealMonteCarloOptimization (Left, Right, Func4, Count, &x, &f);

        //Используем полученный результат
        HML_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1.11359

        HML_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=0.0129019
    }

    if (NameFunction=="HML_UniformSearchOptimization")
    {
        double Left=-5;
        double Right=5;
        double Interval=0.001;
        double x,f;

        //Вызов функции
        HML_UniformSearchOptimization (Left, Right, Func4, Interval, &x, &f);

        //Используем полученный результат
        HML_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1

        HML_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=2.3863e-29
    }

    if (NameFunction=="HML_UniformSearchOptimizationN")
    {
        double Left=-5;
        double Right=5;
        int Count=30;
        double x,f;

        //Вызов функции
        HML_UniformSearchOptimizationN (Left, Right, Func4, Count, &x, &f);

        //Используем полученный результат
        HML_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1

        HML_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=0
    }

    if (NameFunction=="HML_CheckForIdenticalRowsInMatrix")
    {
        int i;
        int VHML_N=10;//Размер массива (число строк)
        int VHML_M=2;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        HML_RandomIntMatrix(a,0,5,VHML_N,VHML_M);//заполним матрицу

        //Вызов функции
        bool b=HML_CheckForIdenticalRowsInMatrix(a,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Заполненная матрица", "a");
        //Заполненная матрица:
        //a =
        //3	3
        //0	0
        //3	0
        //0	3
        //3	1
        //3	2
        //3	2
        //2	1
        //0	3
        //4	2

        HML_ShowNumber(b,"Есть ли одинаковые строки", "b");
        //Есть ли одинаковые строки:
        //b=1

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_CheckForIdenticalColsInMatrix")
    {
        int i;
        int VHML_N=2;//Размер массива (число строк)
        int VHML_M=10;//Размер массива (число столбцов)
        int **a;
        a=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) a[i]=new int[VHML_M];

        HML_RandomIntMatrix(a,0,5,VHML_N,VHML_M);//заполним матрицу

        //Вызов функции
        bool b=HML_CheckForIdenticalColsInMatrix(a,VHML_N,VHML_M);

        //Используем полученный результат
        HML_ShowMatrix (a,VHML_N,VHML_M,"Заполненная матрица", "a");
        //Заполненная матрица:
        //a =
        //4	4	0	1	0	1	0	0	2	1
        //1	4	4	3	3	4	4	3	0	1

        HML_ShowNumber(b,"Есть ли одинаковые столбцы", "b");
        //Есть ли одинаковые столбцы::
        //b=1

        for (i=0;i<VHML_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="HML_LeftBorderOfWilcoxonWFromTable")
    {
        int m=20;
        HML_ShowNumber(m,"Объем меньшей выборки","m");

        int n=21;
        HML_ShowNumber(n,"Объем большей выборки","n");

        double Q=0.05;
        HML_ShowNumber(Q,"Уровень значисмости","Q");

        //Вызов функции
        double Left=HML_LeftBorderOfWilcoxonWFromTable(m,n,Q);

        //Использование результата
        HML_ShowNumber(Left,"Левая граница интервала критический значений сатистики W для критерия Вилкоксена","Left");
        //Левая граница интервала критический значений сатистики W для критерия Вилкоксена:
        //Left=356
    }

    if (NameFunction=="HML_RightBorderOfWilcoxonWFromTable")
    {
        int m=20;
        HML_ShowNumber(m,"Объем меньшей выборки","m");

        int n=21;
        HML_ShowNumber(n,"Объем большей выборки","n");

        double Q=0.05;
        HML_ShowNumber(Q,"Уровень значисмости","Q");

        //Вызов функции
        double Right=HML_RightBorderOfWilcoxonWFromTable(m,n,Q);

        //Использование результата
        HML_ShowNumber(Right,"Правая граница интервала критический значений сатистики W для критерия Вилкоксена","Right");
        //Правая граница интервала критический значений сатистики W для критерия Вилкоксена:
        //Right=484
    }

    if (NameFunction=="HML_ProbabilityDensityFunctionOfInverseGaussianDistribution")
    {
        double x;
        double mu=1;
        double lambda=1;
        double f;
        x=HML_RandomUniform(0,3);
        //x=0.975;

        //Вызов функции
        f=HML_ProbabilityDensityFunctionOfInverseGaussianDistribution(x,mu,lambda);

        //Используем полученный результат
        HML_ShowNumber (x,"Входная переменная", "x");
        //Входная переменная:
        //x=1.10063
        HML_ShowNumber (mu,"Параметр mu", "mu");
        //Параметр mu:
        //mu=1
        HML_ShowNumber (lambda,"Параметр lambda", "lambda");
        //Параметр lambda:
        //lambda=1
        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.343916
    }

    if (NameFunction=="HML_DistributionFunctionOfNormalizedCenteredNormalDistribution")
    {
        double t;
        double f;
        t=HML_RandomUniform(0,3);

        //Вызов функции
        f=HML_DistributionFunctionOfNormalizedCenteredNormalDistribution(t,0.001);

        //Используем полученный результат

        HML_ShowNumber (t,"Параметр", "t");
        //Параметр:
        //t=1.36576
        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.914011
    }

    if (NameFunction=="HML_DistributionFunctionOfNormalDistribution")
    {
        double x;
        double f;
        x=HML_RandomUniform(0,3);
        double mu=3;
        double sigma=1;

        //Вызов функции
        f=HML_DistributionFunctionOfNormalizedCenteredNormalDistribution(x,0.001);

        //Используем полученный результат
        HML_ShowNumber (x,"Входная переменная", "x");
        //Входная переменная:
        //x=0.527979
        HML_ShowNumber (mu,"Параметр mu", "mu");
        //Параметр mu:
        //mu=3
        HML_ShowNumber (sigma,"Параметр sigma", "sigma");
        //Параметр sigma:
        //sigma=1
        HML_ShowNumber (f,"Значение функции распределения нормального распределения", "f");
        //Значение функции распределения нормального распределения:
        //f=0.701244
    }

    if (NameFunction=="HML_WilcoxonW")
    {
        int VHML_Result;

        int VHML_N1=10;
        int VHML_N2=10;

        double *a = new double[VHML_N1];
        double *b = new double[VHML_N2];
        HML_RandomIntVector(a,0.,10.,VHML_N1);
        HML_RandomIntVector(b,0.,10.,VHML_N2);
        HML_ShowVectorT(a,VHML_N1,"Первая выборка","a");
        //Первая выборка:
        //a =
        //6	0	6	1	4	9	6	2	4	8

        HML_ShowVectorT(b,VHML_N2,"Вторая выборка","b");
        //Вторая выборка:
        //b =
        //8	1	1	6	0	3	1	1	2	3

        double Q=0.002;
        //Q=0.2;
        HML_ShowNumber(Q,"Уровень значимости","Q");
        //Уровень значимости:
        //Q=0.002
        //Вызов функции
        VHML_Result = HML_WilcoxonW(a, b, VHML_N1, VHML_N2, Q);

        //Используем результат
        HML_ShowNumber(VHML_Result,"Итог проверка двух выборок ритерием Вилкосена W","VHML_Result");
        //Итог проверка двух выборок ритерием Вилкосена W:
        //VHML_Result=1

        delete [] a;
        delete [] b;
    }
    
    if (NameFunction=="HML_CompareMeanOfVectors")
    {
        int VHML_Result;

        int VHML_N1=10;
        int VHML_N2=10;

        double *a = new double[VHML_N1];
        double *b = new double[VHML_N2];
        HML_RandomIntVector(a,0.,100.,VHML_N1);
        HML_RandomIntVector(b,0.,20.,VHML_N2);
        HML_ShowVectorT(a,VHML_N1,"Первая выборка","a");
        //Первая выборка:
        //a =
        //15	91	38	78	68	80	68	83	37	97

        HML_ShowVectorT(b,VHML_N2,"Вторая выборка","b");
        //Вторая выборка:
        //b =
        //7	10	0	18	11	4	18	3	12	13

        //Вызов функции
        VHML_Result = HML_CompareMeanOfVectors(a, b, VHML_N1, VHML_N2);

        //Используем результат
        HML_ShowNumber(VHML_Result,"У какой выборки больше среднеарифметическое","VHML_Result");
        //У какой выборки больше среднеарифметическое:
        //VHML_Result=1

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="HML_LineGeneralForm")
    {
        double A=HML_RandomUniformInt(1,10);
        double B=HML_RandomUniformInt(1,10);
        double C=HML_RandomUniformInt(1,10);

        double x=5;

        int solutionis;

        //Вызов функции
        double y=HML_LineGeneralForm(x,A,B,C,&solutionis);

        //Используем полученный результат
        HML_ShowText("Уравнение прямой: "+HML_NumberToText(A)+"*x+"+HML_NumberToText(B)+"*y+"+HML_NumberToText(C)+"=0");
        //Уравнение прямой: 7*x+1*y+7=0.
        HML_ShowNumber(solutionis,"Найдено ли решение","solutionis");
        //Найдено ли решение:
        //solutionis=1
        if (solutionis!=0)
        {
            HML_ShowNumber(y,"Значение функции прямой в точке x=5","y");
            //Значение функции прямой в точке x=5:
            //y=-42
        }
    }

    if (NameFunction=="HML_LineSlopeInterceptForm")
    {
        double k=HML_RandomUniformInt(1,10);
        double b=HML_RandomUniformInt(1,10);

        double x=5;

        //Вызов функции
        double y=HML_LineSlopeInterceptForm(x,k,b);

        //Используем полученный результат
        HML_ShowText("Уравнение прямой: y="+HML_NumberToText(k)+"*x+"+HML_NumberToText(b));
        //Уравнение прямой: y=4*x+1.
        HML_ShowNumber(y,"Значение функции прямой в точке x=5","y");
        //Значение функции прямой в точке x=5:
        //y=21
    }

    if (NameFunction=="HML_LineTwoPoint")
    {
        double x1=HML_RandomUniformInt(1,10);
        double y1=HML_RandomUniformInt(1,10);
        double x2=HML_RandomUniformInt(1,10);
        double y2=HML_RandomUniformInt(1,10);

        double x=5;

        int solutionis;

        //Вызов функции
        double y=HML_LineTwoPoint(x,x1,y1,x2,y2,&solutionis);

        //Используем полученный результат
        HML_ShowText("Первая точка: ("+HML_NumberToText(x1)+"; "+HML_NumberToText(y1)+")");
        //Первая точка: (6; 3).
        HML_ShowText("Вторая точка: ("+HML_NumberToText(x2)+"; "+HML_NumberToText(y2)+")");
        //Вторая точка: (3; 3).
        HML_ShowNumber(solutionis,"Найдено ли решение","solutionis");
        //Найдено ли решение:
        //solutionis=1
        if (solutionis!=0)
        {
            HML_ShowNumber(y,"Значение прямо, проходящей через две указанные точки, в точке x=5","y");
            //Значение прямо, проходящей через две указанные точки, в точке x=5:
            //y=32
        }
    }

    if (NameFunction=="HML_Parabola")
    {
        double a=HML_RandomUniformInt(1,10);
        double b=HML_RandomUniformInt(1,10);
        double c=HML_RandomUniformInt(1,10);

        double x=5;

        //Вызов функции
        double y=HML_Parabola(x,a,b,c);

        //Используем полученный результат
        HML_ShowText("Уравнение параболы: y="+HML_NumberToText(a)+"*x^2+"+HML_NumberToText(b)+"*x+"+HML_NumberToText(c));
        //Уравнение параболы: y=4*x^2+5*x+3.
        HML_ShowNumber(y,"Значение функции параболы в точке x=5","y");
        //Значение функции параболы в точке x=5:
        //y=128
    }

    if (NameFunction=="HML_BinaryGeneticAlgorithmWDPOfNOfGPS")
    {
        int ChromosomeLength=50;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения
        double Proportion=0.4;//"Доля" числа поколений от числа вычислений целевой функции

        double *ParametersOfAlgorithm;
        ParametersOfAlgorithm=new double[7];
        ParametersOfAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfAlgorithm[2]=TypeOfSel;//Тип селекции
        ParametersOfAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения
        ParametersOfAlgorithm[6]=Proportion;//"Доля" числа поколений от числа вычислений целевой функции

        int *Decision;//бинарное решение
        Decision=new int[ChromosomeLength];
        double ValueOfFitnessFunction;//значение функции пригодности в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_BinaryGeneticAlgorithmWDPOfNOfGPS (ParametersOfAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        //Как прошел запуск:
        //VHML_Success=1

        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1

            HML_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            //Значение функции пригодности:
            //ValueOfFitnessFunction=47
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="HML_RealGeneticAlgorithmWDPOfNOfGPS")
    {
        int ChromosomeLength=2;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения
        double Proportion=0.4;//"Доля" числа поколений от числа вычислений целевой функции

        double *ParametersOfAlgorithm;
        ParametersOfAlgorithm=new double[8];
        ParametersOfAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfAlgorithm[2]=TypeOfSel;//Тип селекции
        ParametersOfAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения
        ParametersOfAlgorithm[6]=0;//Тип преобразование задачи вещественной оптимизации в задачу бинарной оптимизации
        ParametersOfAlgorithm[7]=Proportion;//"Доля" числа поколений от числа вычислений целевой функции

        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[ChromosomeLength];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[ChromosomeLength];
        int *NumberOfParts;//на сколько делить каждую координату
        NumberOfParts=new int[ChromosomeLength];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        HML_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        HML_FillVector(Right,ChromosomeLength,5.);
        HML_FillVector(NumberOfParts,ChromosomeLength,HML_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_RealGeneticAlgorithmWDPOfNOfGPS (ParametersOfAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //2.00226	1.98883

            HML_ShowNumber(ValueOfFitnessFunction,"Значение целовой функции","ValueOfFitnessFunction");
            //Значение целовой функции:
            //ValueOfFitnessFunction=-0.000129856
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="HML_RealGeneticAlgorithmWDTS")
    {
        int ChromosomeLength=2;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int SizeOfTournament=2;//Размер турнира в турнирной селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        double *ParametersOfAlgorithm;
        ParametersOfAlgorithm=new double[7];
        ParametersOfAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfAlgorithm[2]=SizeOfTournament;//Размер турнира в турнирной селекции
        ParametersOfAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения
        ParametersOfAlgorithm[6]=0;//Тип преобразование задачи вещественной оптимизации в задачу бинарной оптимизации

        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[ChromosomeLength];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[ChromosomeLength];
        int *NumberOfParts;//на сколько делить каждую координату
        NumberOfParts=new int[ChromosomeLength];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        HML_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        HML_FillVector(Right,ChromosomeLength,5.);
        HML_FillVector(NumberOfParts,ChromosomeLength,HML_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_RealGeneticAlgorithmWDTS (ParametersOfAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //2.00226	2.00134

            HML_ShowNumber(ValueOfFitnessFunction,"Значение целовой функции","ValueOfFitnessFunction");
            //Значение целовой функции:
            //ValueOfFitnessFunction=-6.90296e-06
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="HML_BinaryGeneticAlgorithmWDTS")
    {
        int ChromosomeLength=50;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int SizeOfTournament=2;//Размер турнира в турнирной селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        double *ParametersOfAlgorithm;
        ParametersOfAlgorithm=new double[6];
        ParametersOfAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfAlgorithm[2]=SizeOfTournament;//Размер турнира в турнирной селекции
        ParametersOfAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения

        int *Decision;//бинарное решение
        Decision=new int[ChromosomeLength];
        double ValueOfFitnessFunction;//значение функции пригодности в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_BinaryGeneticAlgorithmWDTS (ParametersOfAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        //Как прошел запуск:
        //VHML_Success=1

        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1


            HML_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            //Значение функции пригодности:
            //ValueOfFitnessFunction=49
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="HML_SinglepointCrossoverWithCopying")
    {
        int VHML_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VHML_N];
        int *Parent2;
        Parent2=new int[VHML_N];
        int *Child;
        Child=new int[VHML_N];
        HML_RandomBinaryVector(Parent1,VHML_N);
        HML_RandomBinaryVector(Parent2,VHML_N);

        //Получим потомка Child
        HML_SinglepointCrossoverWithCopying(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0	1	1	0	0	1	0	1	1	1

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	0	0	1	0	1	0	0	0	0

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0	1	1	0	0	1	0	1	1	1

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_TwopointCrossoverWithCopying")
    {
        int VHML_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VHML_N];
        int *Parent2;
        Parent2=new int[VHML_N];
        int *Child;
        Child=new int[VHML_N];
        HML_RandomBinaryVector(Parent1,VHML_N);
        HML_RandomBinaryVector(Parent2,VHML_N);

        //Получим потомка Child
        HML_TwopointCrossoverWithCopying(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //1	1	0	0	1	1	0	0	0	0

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	1	1	0	0	1	0	0	1	0

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0	1	1	0	0	1	0	0	1	0

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_BinaryGeneticAlgorithmWCC")
    {
        int ChromosomeLength=50;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        int *Parameters;
        Parameters=new int[6];
        Parameters[0]=ChromosomeLength;//Длина хромосомы
        Parameters[1]=CountOfFitness;//Число вычислений целевой функции
        Parameters[2]=TypeOfSel;//Тип селекции
        Parameters[3]=TypeOfCros;//Тип скрещивания
        Parameters[4]=TypeOfMutation;//Тип мутации
        Parameters[5]=TypeOfForm;//Тип формирования нового поколения

        int *Decision;//бинарное решение
        Decision=new int[ChromosomeLength];
        double ValueOfFitnessFunction;//значение функции пригодности в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_BinaryGeneticAlgorithmWCC (Parameters,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        //Как прошел запуск:
        //VHML_Success=1

        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

            HML_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=50
        }

        delete [] Parameters;
        delete [] Decision;
    }

    if (NameFunction=="HML_RealGeneticAlgorithmWCC")
    {
        int ChromosomeLength=2;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        int *Parameters;
        Parameters=new int[7];
        Parameters[0]=ChromosomeLength;//Длина хромосомы
        Parameters[1]=CountOfFitness;//Число вычислений целевой функции
        Parameters[2]=TypeOfSel;//Тип селекции
        Parameters[3]=TypeOfCros;//Тип скрещивания
        Parameters[4]=TypeOfMutation;//Тип мутации
        Parameters[5]=TypeOfForm;//Тип формирования нового поколения
        Parameters[6]=0;//Тип преобразование задачи вещественной оптимизации в задачу бинарной оптимизации

        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[ChromosomeLength];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[ChromosomeLength];
        int *NumberOfParts;//на сколько делить каждую координату
        NumberOfParts=new int[ChromosomeLength];

        //Заполним массивы
        //Причем по каждой координате одинаковые значения выставим
        HML_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        HML_FillVector(Right,ChromosomeLength,5.);
        HML_FillVector(NumberOfParts,ChromosomeLength,HML_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_RealGeneticAlgorithmWCC (Parameters,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //2.0105	2.00195
            HML_ShowNumber(ValueOfFitnessFunction,"Значение целевой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction=-0.000114024
        }

        delete [] Parameters;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="HML_TestFunction_AdditivePotential")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-5,5);
        y=HML_RandomUniform(-5,5);

        //Вызываем функцию
        f=HML_TestFunction_AdditivePotential(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-2.87701

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-0.443955

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-0.64441
    }

    if (NameFunction=="HML_TestFunction_MultiplicativePotential")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-5,5);
        y=HML_RandomUniform(-5,5);

        //Вызываем функцию
        f=HML_TestFunction_MultiplicativePotential(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=0.520743

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-4.96242

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-0.113219
    }

    if (NameFunction=="HML_BinaryGeneticAlgorithmTournamentSelectionWithReturn")
    {
        int ChromosomeLength=50;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int SizeOfTournament=2;//Размер турнира в турнирной селекции с возвращением
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        double *ParametersOfAlgorithm;
        ParametersOfAlgorithm=new double[6];
        ParametersOfAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfAlgorithm[2]=SizeOfTournament;//Размер турнира в турнирной селекции с возвращением
        ParametersOfAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения

        int *Decision;//бинарное решение
        Decision=new int[ChromosomeLength];
        double ValueOfFitnessFunction;//значение функции пригодности в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_BinaryGeneticAlgorithmTournamentSelectionWithReturn (ParametersOfAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        //Как прошел запуск:
        //VHML_Success=1

        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1

            HML_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            //Значение функции пригодности:
            //ValueOfFitnessFunction=47
        }
        delete [] ParametersOfAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="HML_RealGeneticAlgorithmTournamentSelectionWithReturn")
    {
        int ChromosomeLength=2;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int SizeOfTournament=2;//Размер турнира в турнирной селекции с возвращением
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        double *ParametersOfAlgorithm;
        ParametersOfAlgorithm=new double[7];
        ParametersOfAlgorithm[0]=ChromosomeLength;//Длина хромосомы
        ParametersOfAlgorithm[1]=CountOfFitness;//Число вычислений целевой функции
        ParametersOfAlgorithm[2]=SizeOfTournament;//Размер турнира в турнирной селекции с возвращением
        ParametersOfAlgorithm[3]=TypeOfCros;//Тип скрещивания
        ParametersOfAlgorithm[4]=TypeOfMutation;//Тип мутации
        ParametersOfAlgorithm[5]=TypeOfForm;//Тип формирования нового поколения
        ParametersOfAlgorithm[6]=0;//Тип преобразование задачи вещественной оптимизации в задачу бинарной оптимизации

        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[ChromosomeLength];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[ChromosomeLength];
        int *NumberOfParts;//на сколько делить каждую координату
        NumberOfParts=new int[ChromosomeLength];

        //Заполним массивы
        //Причем по каждой координате одинаковые значения выставим
        HML_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        HML_FillVector(Right,ChromosomeLength,5.);
        HML_FillVector(NumberOfParts,ChromosomeLength,HML_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_RealGeneticAlgorithmTournamentSelectionWithReturn (ParametersOfAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //2.00226	1.98883

            HML_ShowNumber(ValueOfFitnessFunction,"Значение целовой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction=-0.000129856
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="HML_TestFunction_ReverseGriewank")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-10,10);
        y=HML_RandomUniform(-10,10);

        //Вызываем функцию
        f=HML_TestFunction_ReverseGriewank(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=9.39884

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-8.80345

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.26129
    }

    if (NameFunction=="HML_TestFunction_HyperEllipsoid")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-5,5);
        f=HML_TestFunction_HyperEllipsoid(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //1.39903
        //1.96538

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=17.4082

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_RotatedHyperEllipsoid")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-5,5);
        f=HML_TestFunction_RotatedHyperEllipsoid(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //-0.933898
        //-1.2216

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=5.51833

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_Wave")
    {
        double x;
        double f;
        x=HML_RandomUniform(-2,2);

        //Вызываем функцию
        f=HML_TestFunction_Wave(x);

        HML_ShowNumber (x,"Вещественная переменная", "x");
        //Вещественная переменная:
        //x=0.802021

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.515755
    }

    if (NameFunction=="HML_TestFunction_Multiextremal")
    {
        double x;
        double f;
        x=HML_RandomUniform(-2,2);
        //x=0.954451617;

        //Вызываем функцию
        f=HML_TestFunction_Multiextremal(x);

        HML_ShowNumber (x,"Вещественная переменная", "x");
        //Вещественная переменная:
        //x=1.112

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=5.46058
    }

    if (NameFunction=="HML_TestFunction_Multiextremal2")
    {
        double x;
        double f;
        x=HML_RandomUniform(-2,2);
        x=-0.993263;

        //Вызываем функцию
        f=HML_TestFunction_Multiextremal2(x);

        HML_ShowNumber (x,"Вещественная переменная", "x");
        //Вещественная переменная:
        //x=-0.00666742

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=1.0641
    }

    if (NameFunction=="HML_TestFunction_Sombrero")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-20,20);
        y=HML_RandomUniform(-20,20);

        //Вызываем функцию
        f=HML_TestFunction_Sombrero(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-3.26381

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-0.836133

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.938425
    }

    if (NameFunction=="HML_TestFunction_Himmelblau")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-5,5);
        y=HML_RandomUniform(-5,5);

        //Вызываем функцию
        f=HML_TestFunction_Himmelblau(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=1.8744

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=0.39062

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=75.0844
    }

    if (NameFunction=="HML_TestFunction_Katnikov")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-5,5);
        y=HML_RandomUniform(-5,5);

        //Вызываем функцию
        f=HML_TestFunction_Katnikov(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-1.44256

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-3.16906

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=11.5793
    }

    if (NameFunction=="HML_TestFunction_Multiextremal3")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-5,5);
        y=HML_RandomUniform(-5,5);

        //Вызываем функцию
        f=HML_TestFunction_Multiextremal3(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=2.68873

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=0.520861

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=10.8962
    }

    if (NameFunction=="HML_TestFunction_Multiextremal4")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(0,4);
        y=HML_RandomUniform(0,4);

        //Вызываем функцию
        f=HML_TestFunction_Multiextremal4(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=2.6604

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=2.56989

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=8.82495
    }

    if (NameFunction=="HML_TestFunction_StepFunction")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-5,5);
        f=HML_TestFunction_StepFunction(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        //Входной вектор:
        //Входной вектор:
        //x =
        //-0.413264
        //-0.141813

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-0.444923

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_Rana")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-512,512);
        y=HML_RandomUniform(-512,512);

        //Вызываем функцию
        f=HML_TestFunction_Rana(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-169.488

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-458.027

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=145.161
    }

    if (NameFunction=="HML_TestFunction_ShekelsFoxholes")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-50,50);
        y=HML_RandomUniform(-50,50);

        //Вызываем функцию
        f=HML_TestFunction_ShekelsFoxholes(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-1.42869

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-6.40351

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=496.009
    }

    if (NameFunction=="HML_TestFunction_EggHolder")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-512,512);
        y=HML_RandomUniform(-512,512);

        //Вызываем функцию
        f=HML_TestFunction_EggHolder(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=367.682

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=464.74

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-287.643
    }

    if (NameFunction=="HML_TestFunction_RastriginWithChange")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-16,16);
        y=HML_RandomUniform(-16,16);

        //Вызываем функцию
        f=HML_TestFunction_RastriginWithChange(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=12.4601

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=5.36642

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=31.4576
    }

    if (NameFunction=="HML_TestFunction_RastriginWithTurning")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-16,16);
        y=HML_RandomUniform(-16,16);

        //Вызываем функцию
        f=HML_TestFunction_RastriginWithTurning(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-7.1266

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=11.4531

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=10.3461
    }

    if (NameFunction=="HML_TestFunction_Schwefel")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-500,500);


        //Вызов функции
        f=HML_TestFunction_Schwefel(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //169.715
        //410.499

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=357.17

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_Griewangk")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-16,16);

        //Вызов функции
        f=HML_TestFunction_Griewangk(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //7.82863
        //12.7969

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=1.07984

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_InvertedRosenbrock")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-5,5);
        y=HML_RandomUniform(-5,5);

        //Вызываем функцию
        f=HML_TestFunction_InvertedRosenbrock(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=4.95843

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=4.1078

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-0.0375447
    }

    if (NameFunction=="HML_TestFunction_GaussianQuartic")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-2,2);

        //Вызов функции
        f=HML_TestFunction_GaussianQuartic(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //1.82905
        //-1.81438

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=33.8315

        delete[] x;
    }

    if (NameFunction=="HML_TestFunction_RastriginNovgorod")
    {
        double *x;
        double f;
        int VHML_N=2;
        x=new double[VHML_N];
        for (int i=0;i<VHML_N;i++) x[i]=HML_RandomUniform(-2,2);

        //Вызов функции
        f=HML_TestFunction_RastriginNovgorod(x,VHML_N);

        HML_ShowVector (x,VHML_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //-1.15942
        //1.19803

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=3.42316

        delete[] x;
    }

    if (NameFunction=="HML_AlmostZero")
    {
        double y=0.000000001;
        bool Zero;

        //Вызов функции
        Zero=HML_AlmostZero(y);

        //Используем полученный результат
        HML_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=1e-09
        HML_ShowNumber(Zero,"Является ли почти нулем?","Zero");
        //Является ли почти нулем?:
        //Zero=1

        y=0.01;

        //Вызов функции
        Zero=HML_AlmostZero(y);

        //Используем полученный результат
        HML_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=0.01
        HML_ShowNumber(Zero,"Является ли почти нулем?","Zero");
        //Является ли почти нулем?:
        //Zero=0

        y=0;

        //Вызов функции
        Zero=HML_AlmostZero(y);

        //Используем полученный результат
        HML_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=0
        HML_ShowNumber(Zero,"Является ли почти нулем?","Zero");
        //Является ли почти нулем?:
        //Zero=1

        y=1;

        //Вызов функции
        Zero=HML_AlmostZero(y);

        //Используем полученный результат
        HML_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=1
        HML_ShowNumber(Zero,"Является ли почти нулем?","Zero");
        //Является ли почти нулем?:
        //Zero=0
    }

    if (NameFunction=="HML_QuadraticEquationCount")
    {
        double a=HML_RandomUniformInt(1,10);
        double b=HML_RandomUniformInt(1,10);
        double c=HML_RandomUniformInt(1,10);
        double x1;
        double x2;

        int Result=HML_QuadraticEquationCount(a,b,c,&x1,&x2);

        //Используем полученный результат
        HML_ShowText("Квадратное уравнение: "+HML_NumberToText(a)+"x^2+"+HML_NumberToText(b)+"x+"+HML_NumberToText(c)+"=0");
        //Квадратное уравнение: 1x^2+4x+4=0.
        HML_ShowNumber(Result,"Сколько решений найдено","Result");
        //Сколько решений найдено:
        //Result=1
        if (Result>=1)
        {
            HML_ShowNumber(x1,"Первый корень квадратного уравнения","x1");
            //Первый корень квадратного уравнения:
            //x1=-2
            HML_ShowNumber(x2,"Второй корень квадратного уравнения","x2");
            //Второй корень квадратного уравнения:
            //x2=-2
        }
    }

    if (NameFunction=="HML_AlmostEqual")
    {
        double x=0;
        double y=0.000000001;
        bool Equal;

        //Вызов функции
        Equal=HML_AlmostEqual(x,y);

        //Используем полученный результат
        HML_ShowNumber(x,"Проверяемое число","x");
        //Проверяемое число:
        //x=0
        HML_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=1e-09
        HML_ShowNumber(Equal,"Являются ли почти равными?","Equal");
        //Являются ли почти равными?:
        //Equal=1

        x=1;
        y=2;
        //Вызов функции
        Equal=HML_AlmostEqual(x,y);
        //Используем полученный результат
        HML_ShowNumber(x,"Проверяемое число","x");
        //Проверяемое число:
        //x=1
        HML_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //x=1
        HML_ShowNumber(Equal,"Являются ли почти равными?","Equal");
        //Являются ли почти равными?:
        //Equal=0
    }

    if (NameFunction=="HML_UncorrectedVariance")
    {
        int VHML_N=10;//Размер массива
        double *x;
        x=new double[VHML_N];
        //Заполним случайными числами
        HML_RandomRealVector (x,0,10,VHML_N);

        //Вызов функции
        double UncorrectedVariance=HML_UncorrectedVariance(x,VHML_N);

        //Используем полученный результат
        HML_ShowVector (x,VHML_N,"Массив", "x");
        //Массив:
        //x =
        //7.85789
        //3.68858
        //1.29782
        //7.19989
        //7.21336
        //0.717554
        //5.07097
        //0.514343
        //9.4794
        //5.8723

        HML_ShowNumber (UncorrectedVariance,"Значение выборочной неисправленной дисперсии", "UncorrectedVariance");
        //Значение выборочной неисправленной дисперсии:
        //UncorrectedVariance=9.25051

        delete [] x;
    }

    if (NameFunction=="HML_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything")
    {
        double Result=HML_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything();

        //Используем полученный результат
        HML_ShowNumber(Result,"Ответ на главный вопрос жизни, вселенной и всего такого","Ответ");
        //Ответ на главный вопрос жизни, вселенной и всего такого:
        //Ответ=42
    }

    if (NameFunction=="HML_MeaningOfLife")
    {
        double Result=HML_MeaningOfLife();

        //Используем полученный результат
        HML_ShowNumber(Result,"Смысл жизни","Ответ");
        //Смысл жизни:
        //Ответ=42
    }

    if (NameFunction=="HML_SinglepointCrossoverForReal")
    {
        int VHML_N=10; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_SinglepointCrossoverForReal(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.92261	0.684314	0.891158	0.312732	0.640667	0.406768	0.228042	0.180759	0.394544	0.88495

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.856881	0.134294	0.985216	0.254506	0.456079	0.330734	0.78648	0.257115	0.609472	0.868141

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.92261	0.684314	0.891158	0.312732	0.456079	0.330734	0.78648	0.257115	0.609472	0.868141

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_TwopointCrossoverForReal")
    {
        int VHML_N=10; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_TwopointCrossoverForReal(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.301053	0.64133	0.815178	0.727049	0.426111	0.119812	0.720018	0.484514	0.948253	0.489644

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.566543	0.972537	0.575658	0.887848	0.937234	0.772248	0.982688	0.931731	0.480371	0.562743

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.301053	0.64133	0.815178	0.887848	0.937234	0.772248	0.982688	0.484514	0.948253	0.489644

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_UniformCrossoverForReal")
    {
        int VHML_N=10; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_UniformCrossoverForReal(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.872271	0.400017	0.382867	0.0215583	0.195993	0.0210766	0.546082	0.540188	0.448846	0.22661

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.972843	0.656896	0.892507	0.438632	0.1083	0.982196	0.376142	0.285289	0.411732	0.681029

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Полученный потомок:
        //Child =
        //0.972843	0.400017	0.382867	0.0215583	0.195993	0.0210766	0.546082	0.285289	0.448846	0.22661

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_MeanOfUpperFilter")
    {
        int i;
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniform(0,10);

        double UpperFilter=9;

        double Mean=HML_Mean(a,VHML_N);

        //Вызов функции
        double MeanOfUpperFilter=HML_MeanOfUpperFilter(a,VHML_N,UpperFilter);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Массив", "a");
        //Массив:
        //a =
        //4.51301
        //9.00999
        //5.42346
        //4.33216
        //8.50985
        //9.90472
        //6.28173
        //2.48286
        //9.3158
        //1.33581

        HML_ShowNumber (UpperFilter,"Значение верхнего фильтра", "UpperFilter");
        //Значение верхнего фильтра:
        //UpperFilter=9

        HML_ShowNumber (Mean,"Среднее арифметическое массива", "Mean");
        //Среднее арифметическое массива:
        ///Mean=6.11094

        HML_ShowNumber (MeanOfUpperFilter,"Среднее арифметическое массива с верхним фильтром", "MeanOfUpperFilter");
        //Среднее арифметическое массива с верхним фильтром:
        //MeanOfUpperFilter=4.69698

        delete [] a;
    }

    if (NameFunction=="HML_MeanOfLowerFilter")
    {
        int i;
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniform(0,10);

        double LowerFilter=1;

        double Mean=HML_Mean(a,VHML_N);

        //Вызов функции
        double MeanOfLowerFilter=HML_MeanOfLowerFilter(a,VHML_N,LowerFilter);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Массив", "a");
        //Массив:
        //a =
        //8.20861
        //5.52348
        //4.90245
        //3.24057
        //5.12062
        //8.07709
        //4.60095
        //0.0358931
        //9.51881
        //6.51128

        HML_ShowNumber (LowerFilter,"Значение нижнего фильтра", "LowerFilter");
        //Значение нижнего фильтра:
        //LowerFilter=1

        HML_ShowNumber (Mean,"Среднее арифметическое массива", "Mean");
        //Среднее арифметическое массива:
        //Mean=5.57397

        HML_ShowNumber (MeanOfLowerFilter,"Среднее арифметическое массива с нижним фильтром", "MeanOfLowerFilter");
        //Среднее арифметическое массива с нижним фильтром:
        //MeanOfLowerFilter=6.18932

        delete [] a;
    }

    if (NameFunction=="HML_MeanOfFilter")
    {
        int i;
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
            a[i]=HML_RandomUniform(0,10);

        double LowerFilter=1;

        double UpperFilter=9;

        double Mean=HML_Mean(a,VHML_N);

        //Вызов функции
        double MeanOfFilter=HML_MeanOfFilter(a,VHML_N, UpperFilter, LowerFilter);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Массив", "a");
        //Массив:
        //a =
        //0.0249536
        //5.65315
        //4.50364
        //9.83102
        //8.18634
        //6.15052
        //0.00491235
        //2.80304
        //4.85183
        //3.34549

        HML_ShowNumber (LowerFilter,"Значение нижнего фильтра", "LowerFilter");
        //Значение нижнего фильтра:
        //LowerFilter=1

        HML_ShowNumber (UpperFilter,"Значение верхнего фильтра", "UpperFilter");
        //Значение верхнего фильтра:
        //UpperFilter=9

        HML_ShowNumber (Mean,"Среднее арифметическое массива", "Mean");
        //Среднее арифметическое массива:
        //Mean=4.53549

        HML_ShowNumber (MeanOfFilter,"Среднее арифметическое массива с фильтром", "MeanOfFilter");
        //Среднее арифметическое массива с фильтром:
        //MeanOfFilter=5.07057

        delete [] a;
    }

    if (NameFunction=="HML_ArithmeticalCrossoverForReal")
    {
        int VHML_N=10; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_ArithmeticalCrossoverForReal(Parent1,Parent2,Child,0.5,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.332926	0.899553	0.469617	0.89417	0.510588	0.261183	0.0920975	0.599565	0.663209	0.544152
        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.084834	0.633822	0.814498	0.211601	0.753767	0.815395	0.82197	0.817619	0.543505	0.754058

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.20888	0.766688	0.642057	0.552885	0.632177	0.538289	0.457034	0.708592	0.603357	0.649105

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_TestFunction_Bosom")
    {
        double x;
        double y;
        double f;
        x=HML_RandomUniform(-12,12);
        y=HML_RandomUniform(-12,12);

        //Вызываем функцию
        f=HML_TestFunction_Bosom(x,y);

        HML_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=6.33755

        HML_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=10.0335

        HML_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.173283
    }

    if (NameFunction=="HML_FlatCrossoverForReal")
    {
        int VHML_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_FlatCrossoverForReal(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.53608	0.642251	0.592985	0.496914	0.869165

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.865619	0.479102	0.872257	0.270094	0.567692


        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.86188	0.559004	0.60677	0.367834	0.737273

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_GeometricalCrossoverForReal")
    {
        int VHML_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_GeometricalCrossoverForReal(Parent1,Parent2,Child,0.5,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.237303	0.742526	0.401953	0.794393	0.450861

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.0427865	0.784436	0.736516	0.875728	0.871102

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.100764	0.763194	0.5441	0.83407	0.626694

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_BLXCrossoverForReal")
    {
        int VHML_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_BLXCrossoverForReal(Parent1,Parent2,Child,0.5,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.00492424	0.904672	0.495609	0.277354	0.157748

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.0642395	0.216884	0.270904	0.602833	0.0286132

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.0163621	0.797608	0.169474	0.73645	0.114127

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_LinearCrossoverForReal")
    {
        int VHML_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_LinearCrossoverForReal(Parent1,Parent2,Child,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.677296	0.808882	0.182892	0.776259	0.82249

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.91462	0.788695	0.563462	0.214182	0.603119

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.558634	0.818976	-0.00739218	1.0573	0.932176

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_ExtendedLineForReal")
    {
        int VHML_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VHML_N];
        double *Parent2;
        Parent2=new double[VHML_N];
        double *Child;
        Child=new double[VHML_N];
        HML_RandomRealVector(Parent1,0,1,VHML_N);
        HML_RandomRealVector(Parent2,0,1,VHML_N);

        //Получим потомка Child
        HML_ExtendedLineForReal(Parent1,Parent2,Child,0.5,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (Parent1,VHML_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.0407698	0.221488	0.912053	0.845252	0.219005

        HML_ShowVectorT (Parent2,VHML_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.388894	0.841718	0.741151	0.390797	0.0401433

        HML_ShowVectorT (Child,VHML_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.214832	0.531603	0.826602	0.618024	0.129574

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="HML_SeparateVectorLimitOnProductElements")
    {
        int *Vector;
        int N=8;
        Vector = new int [N];
        Vector[0]=2;
        Vector[1]=3;
        Vector[2]=4;
        Vector[3]=2;
        Vector[4]=3;
        Vector[5]=4;
        Vector[6]=2;
        Vector[7]=4;

        int *Order;
        Order = new int [N];

        int Limit=16;

        int ElementsInPart;

        ElementsInPart = HML_SeparateVectorLimitOnProductElements(Vector, Order, Limit, N);

        HML_ShowVectorT(Vector,N,"Массив","Vector");
        //Массив:
        //Vector =
        //2	3	4	2	3	4	2	4

        HML_ShowVectorT(Order,N,"Порядок элементов в новых двух группах","Order");
        //Порядок элементов в новых двух группах:
        //Order =
        //0	3	6	1	4	2	5	7

        HML_ShowNumber(ElementsInPart,"Количество элементов в первой группе","ElementsInPart");
        //Количество элементов в первой группе:
        //ElementsInPart=3

        delete [] Vector;
        delete [] Order;
    }

    if (NameFunction=="HML_BinaryGeneticAlgorithmTwiceGenerations")
    {
        int ChromosomeLength=200;//Длина хромосомы
        int CountOfFitness=40*40;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        int *Parameters;
        Parameters=new int[6];
        Parameters[0]=ChromosomeLength;//Длина хромосомы
        Parameters[1]=CountOfFitness;//Число вычислений целевой функции
        Parameters[2]=TypeOfSel;//Тип селекции
        Parameters[3]=TypeOfCros;//Тип скрещивания
        Parameters[4]=TypeOfMutation;//Тип мутации
        Parameters[5]=TypeOfForm;//Тип формирования нового поколения

        int *Decision;//бинарное решение
        Decision=new int[ChromosomeLength];
        double ValueOfFitnessFunction;//значение функции пригодности в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_BinaryGeneticAlgorithmTwiceGenerations (Parameters,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        //Как прошел запуск:
        //VHML_Success=1

        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

            HML_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=50
        }

        delete [] Parameters;
        delete [] Decision;
    }

    if (NameFunction=="HML_RealGeneticAlgorithmTwiceGenerations")
    {
        int ChromosomeLength=2;//Длина хромосомы
        int CountOfFitness=50*50;//Число вычислений целевой функции
        int TypeOfSel=1;//Тип селекции
        int TypeOfCros=0;//Тип скрещивания
        int TypeOfMutation=1;//Тип мутации
        int TypeOfForm=0;//Тип формирования нового поколения

        int *Parameters;
        Parameters=new int[7];
        Parameters[0]=ChromosomeLength;//Длина хромосомы
        Parameters[1]=CountOfFitness;//Число вычислений целевой функции
        Parameters[2]=TypeOfSel;//Тип селекции
        Parameters[3]=TypeOfCros;//Тип скрещивания
        Parameters[4]=TypeOfMutation;//Тип мутации
        Parameters[5]=TypeOfForm;//Тип формирования нового поколения
        Parameters[6]=0;//Тип преобразование задачи вещественной оптимизации в задачу бинарной оптимизации

        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[ChromosomeLength];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[ChromosomeLength];
        int *NumberOfParts;//на сколько делить каждую координату
        NumberOfParts=new int[ChromosomeLength];

        //Заполним массивы
        //Причем по каждой координате одинаковые значения выставим
        HML_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        HML_FillVector(Right,ChromosomeLength,5.);
        HML_FillVector(NumberOfParts,ChromosomeLength,HML_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VHML_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VHML_Success=HML_RealGeneticAlgorithmTwiceGenerations (Parameters,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        HML_ShowNumber(VHML_Success,"Как прошел запуск","VHML_Success");
        if (VHML_Success==1)
        {
            HML_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1.99951	1.99646
            HML_ShowNumber(ValueOfFitnessFunction,"Значение целевой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction=-1.27703e-05
        }

        delete [] Parameters;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="HML_ChangeOrderInVector")
    {
        int VHML_N=5;//Размер массива
        int *a;
        a=new int[VHML_N];

        a[0]=2;
        a[1]=3;
        a[2]=1;
        a[3]=8;
        a[4]=2;

        int *Order;
        Order=new int[VHML_N];
        Order[0]=4;
        Order[1]=3;
        Order[2]=1;
        Order[3]=2;
        Order[4]=0;

        HML_ShowVector (a,VHML_N,"Вектор", "a");
        //Вектор:
        //a =
        //2
        //3
        //1
        //8
        //2

        //Вызов функции
        HML_ChangeOrderInVector(a,Order,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Order,VHML_N,"Порядок элементов, к которому нужно привести массив", "Order");
        //Порядок элементов, к которому нужно привести массив:
        //Order =
        //4
        //3
        //1
        //2
        //0

        HML_ShowVector (a,VHML_N,"Переставленный вектор", "a");
        //Переставленный вектор:
        //a =
        //2
        //8
        //3
        //1
        //2

        delete [] a;
        delete [] Order;
    }

    if (NameFunction=="HML_SeparateVectorLimitOnProductElementsTwo")
    {
        int *Vector;
        int N=8;
        Vector = new int [N];
        Vector[0]=2;
        Vector[1]=3;
        Vector[2]=4;
        Vector[3]=2;
        Vector[4]=3;
        Vector[5]=4;
        Vector[6]=2;
        Vector[7]=4;

        int *Order;
        Order = new int [N];

        int Limit=16;

        int ElementsInPart;

        ElementsInPart = HML_SeparateVectorLimitOnProductElementsTwo(Vector, Order, Limit, N);

        HML_ShowVectorT(Vector,N,"Массив","Vector");
        //Массив:
        //Vector =
        //2	3	4	2	3	4	2	4

        HML_ShowVectorT(Order,N,"Порядок элементов в новых двух группах","Order");
        //Порядок элементов в новых двух группах:
        //Order =
        //7	5	2	4	1	6	3	0

        HML_ShowNumber(ElementsInPart,"Количество элементов в первой группе","ElementsInPart");
        //Количество элементов в первой группе:
        //ElementsInPart=2

        delete [] Vector;
        delete [] Order;
    }

    if (NameFunction=="HML_ShiftLeftVector")
    {
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomUniformInt(0,6);//Заполняем случайными значениями

        HML_ShowVector (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //2
        //5
        //3
        //4
        //4
        //1
        //0
        //2
        //0
        //3

        //Вызов функции
        HML_ShiftLeftVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVector (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //5
        //3
        //4
        //4
        //1
        //0
        //2
        //0
        //3
        //2

        delete [] a;
    }

    if (NameFunction=="HML_ShiftRightVector")
    {
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomUniformInt(0,6);//Заполняем случайными значениями

        HML_ShowVectorT (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //4	3	4	2	2	2	0	0	4	5

        //Вызов функции
        HML_ShiftRightVector(a,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //5	4	3	4	2	2	2	0	0	4

        delete [] a;
    }

    if (NameFunction=="HML_PendulumOfMaxwell")
    {
        int i;
        double Data[13];
        double m,maxis,R,r,dt,t,x0,v0,l,k,e;
        double Input1,Input2;
        m=0.5;
        maxis=0.01;
        R=0.03;
        r=0.002;
        dt=0.01;
        t=20;
        x0=0.03;
        v0=0;
        l=0.5;
        k=0.1;
        e=0.000001;

        Data[0]=x0;
        Data[1]=v0;
        Data[2]=0;
        Data[5]=m;
        Data[6]=maxis;
        Data[7]=R;
        Data[8]=r;
        Data[9]=l;
        Data[10]=k;
        Data[11]=dt;
        Data[12]=e;

        //Массивы для сохранения значений. Они не обзяательны
        double *Position = new double [int(t/dt)];
        double *TimePosition = new double [int(t/dt)];

        for (i=0;i<int(t/dt);i++)
        {
            Input1=Data[0];//считываем, чтобы в случае использовать для управления
            Input2=Data[1];
            Data[2]=0;//управления нет

            Position[i]=Input1;
            TimePosition[i]=dt*i;

            if (HML_PendulumOfMaxwell(Data)==0) break;
        }

        QString Html=THQt_ShowChartOfLine (TimePosition,Position, int(t/dt), "Положение маятника от времени", "t", "x", "Координаты положения маятника",true,false,false,true,true);
        HQt_AddHtml(Html);

        delete [] Position;
        delete [] TimePosition;
    }

    if (NameFunction=="HML_CentroidOfTrapeziformFuzzyNumber")
    {
        double a=HML_RandomUniform(-4,4);
        double b=a+HML_RandomUniform(0,2);
        double c=b+HML_RandomUniform(0,2);
        double d=c+HML_RandomUniform(0,2);

        //Вызов функции
        double f=HML_CentroidOfTrapeziformFuzzyNumber (a,b,c,d);

        //Используем полученный результат
        HML_ShowNumber(a,"Значение первого параметра трапецевидного нечеткого числа","a");
        //Значение первого параметра трапецевидного нечеткого числа:
        //a=3.59917
        HML_ShowNumber(b,"Значение второго параметра трапецевидного нечеткого числа","b");
        //Значение второго параметра трапецевидного нечеткого числа:
        //b=5.46629
        HML_ShowNumber(c,"Значение третьего параметра трапецевидного нечеткого числа","c");
        //Значение третьего параметра трапецевидного нечеткого числа:
        //c=6.24352
        HML_ShowNumber(d,"Значение последнего параметра трапецевидного нечеткого числа","d");
        //Значение последнего параметра трапецевидного нечеткого числа:
        //d=6.45975
        HML_ShowNumber(f,"Центр тяжести трапециевидного числа","f");
        //Центр тяжести трапециевидного числа:
        //f=5.36339
    }

    if (NameFunction=="HML_MaxiMinTrapeziformFuzzyNumbers")
    {
        double *Data=new double[8];
        Data[0]=HML_RandomUniform(-4,4);
        Data[1]=Data[0]+HML_RandomUniform(0,2);
        Data[2]=Data[1]+HML_RandomUniform(0,2);
        Data[3]=Data[2]+HML_RandomUniform(0,2);
        Data[4]=HML_RandomUniform(-4,4);
        Data[5]=Data[4]+HML_RandomUniform(0,2);
        Data[6]=Data[5]+HML_RandomUniform(0,2);
        Data[7]=Data[6]+HML_RandomUniform(0,2);

        //Вызов функции
        double f=HML_MaxiMinTrapeziformFuzzyNumbers (Data);

        //Используем полученный результат
        HML_ShowVector(Data,8, "Два нечетких трапецевидных числа","Data");
        //Два нечетких трапецевидных числа:
        //Data =
        //0.989053
        //1.13038
        //1.8941
        //2.04333
        //-2.00039
        //-0.915334
        //0.343752
        //1.68268

        HML_ShowNumber(f,"Максимальное значение функции принадлежности объединенного нечеткого числа","f");
        //Максимальное значение функции принадлежности объединенного нечеткого числа:
        //f=0.468587
        delete [] Data;
    }

    if (NameFunction=="HML_NonparametricEstimatorOfRegression")
    {
        int N=500;
        double *X=new double [N];
        double *Y=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }
        //HML_NoiseInVector(Y,5,N);//добавим помеху

        double x=HML_RandomUniform(0,6);//Для этого числа будем считать оценку регрессию

        double C=0.1;//коэффициент размытости

        //Применим функцию
        bool b;
        double y=HML_NonparametricEstimatorOfRegression(x,X,Y,N,C,3,&b);

        HML_ShowNumber(x,"Входной парметр","x");
        //Входной парметр:
        //x=5.7237
        HML_ShowNumber(y,"Непараметрическая оценка регрессии","y");
        //Непараметрическая оценка регрессии:
        //y=-0.537582
        HML_ShowNumber(sin(x),"Действительное значение функции в точке","y*");
        //Действительное значение функции в точке:
        //y*=-0.530754

        delete [] X;
        delete [] Y;
    }

    if (NameFunction=="HML_AcceptanceLimitsNumber")
    {
        int a    = HML_RandomUniformInt(-50,50);
        int Left = -40;
        int Right= 30;

        int Result=HML_AcceptanceLimitsNumber(a,Left,Right);

        //Используем полученный результат
        HML_ShowNumber(a,"Первоначальное число","a");
        //Первоначальное число:
        //a=49
        HML_ShowNumber(Left,"Левая граница","Left");
        //Левая граница:
        //Left=-40
        HML_ShowNumber(Right,"Правая граница","Right");
        //Правая граница:
        //Right=30
        HML_ShowNumber(Result,"Число в рамках","Result");
        //Число в рамках:
        //Result=30
    }

    if (NameFunction=="HML_AlphaBlendingColorToColorR")
    {
        double alpha = 0.1;
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;
        int R2 = 85;
        int G2 = 1;
        int B2 = 89;

        int R=HML_AlphaBlendingColorToColorR(alpha, R1, G1, B1, R2, G2, B2);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75
        HML_ShowNumber(R2,"Канал R второго цвета","R2");
        //Канал R второго цвета:
        //R2=85
        HML_ShowNumber(G2,"Канал G второго цвета","G2");
        //Канал G второго цвета:
        //G2=1
        HML_ShowNumber(B2,"Канал B второго цвета","B2");
        //Канал B второго цвета:
        //B2=89

        HML_ShowNumber(alpha,"Степень прозрачности первого цвета","alpha");
        //Степень прозрачности первого цвета:
        //alpha=0.1

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=31
    }

    if (NameFunction=="HML_AlphaBlendingColorToColorG")
    {
        double alpha = 0.1;
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;
        int R2 = 85;
        int G2 = 1;
        int B2 = 89;

        int G=HML_AlphaBlendingColorToColorG(alpha, R1, G1, B1, R2, G2, B2);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75
        HML_ShowNumber(R2,"Канал R второго цвета","R2");
        //Канал R второго цвета:
        //R2=85
        HML_ShowNumber(G2,"Канал G второго цвета","G2");
        //Канал G второго цвета:
        //G2=1
        HML_ShowNumber(B2,"Канал B второго цвета","B2");
        //Канал B второго цвета:
        //B2=89

        HML_ShowNumber(alpha,"Степень прозрачности первого цвета","alpha");
        //Степень прозрачности первого цвета:
        //alpha=0.1

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=115
    }

    if (NameFunction=="HML_AlphaBlendingColorToColorB")
    {
        double alpha = 0.1;
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;
        int R2 = 85;
        int G2 = 1;
        int B2 = 89;

        int B=HML_AlphaBlendingColorToColorB(alpha, R1, G1, B1, R2, G2, B2);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75
        HML_ShowNumber(R2,"Канал R второго цвета","R2");
        //Канал R второго цвета:
        //R2=85
        HML_ShowNumber(G2,"Канал G второго цвета","G2");
        //Канал G второго цвета:
        //G2=1
        HML_ShowNumber(B2,"Канал B второго цвета","B2");
        //Канал B второго цвета:
        //B2=89

        HML_ShowNumber(alpha,"Степень прозрачности первого цвета","alpha");
        //Степень прозрачности первого цвета:
        //alpha=0.1

        HML_ShowNumber(B,"Канал B итогового цвета","B");
        //Канал R итогового цвета:
        //R=31
    }

    if (NameFunction=="HML_ColorFromGradientR")
    {
        double position = 0.1;
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;
        int R2 = 85;
        int G2 = 1;
        int B2 = 89;

        int R=HML_ColorFromGradientR(position, R1, G1, B1, R2, G2, B2);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75
        HML_ShowNumber(R2,"Канал R второго цвета","R2");
        //Канал R второго цвета:
        //R2=85
        HML_ShowNumber(G2,"Канал G второго цвета","G2");
        //Канал G второго цвета:
        //G2=1
        HML_ShowNumber(B2,"Канал B второго цвета","B2");
        //Канал B второго цвета:
        //B2=89

        HML_ShowNumber(position,"Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента","position");
        //Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента:
        //position=0.1

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=31
    }

    if (NameFunction=="HML_ColorFromGradientG")
    {
        double position = 0.1;
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;
        int R2 = 85;
        int G2 = 1;
        int B2 = 89;

        int G=HML_ColorFromGradientG(position, R1, G1, B1, R2, G2, B2);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75
        HML_ShowNumber(R2,"Канал R второго цвета","R2");
        //Канал R второго цвета:
        //R2=85
        HML_ShowNumber(G2,"Канал G второго цвета","G2");
        //Канал G второго цвета:
        //G2=1
        HML_ShowNumber(B2,"Канал B второго цвета","B2");
        //Канал B второго цвета:
        //B2=89

        HML_ShowNumber(position,"Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента","position");
        //Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента:
        //position=0.1

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=115
    }

    if (NameFunction=="HML_ColorFromGradientB")
    {
        double position = 0.1;
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;
        int R2 = 85;
        int G2 = 1;
        int B2 = 89;

        int B=HML_ColorFromGradientB(position, R1, G1, B1, R2, G2, B2);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75
        HML_ShowNumber(R2,"Канал R второго цвета","R2");
        //Канал R второго цвета:
        //R2=85
        HML_ShowNumber(G2,"Канал G второго цвета","G2");
        //Канал G второго цвета:
        //G2=1
        HML_ShowNumber(B2,"Канал B второго цвета","B2");
        //Канал B второго цвета:
        //B2=89

        HML_ShowNumber(position,"Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента","position");
        //Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента:
        //position=0.1

        HML_ShowNumber(B,"Канал B итогового цвета","B");
        //Канал B итогового цвета:
        //B=76
    }

    if (NameFunction=="HML_GiveRainbowColorR")
    {
        double position = 0.6;

        int R=HML_GiveRainbowColorR(position);

        HML_ShowNumber(position,"Позиция из интервала [0;1], которая говорит какой цвет выдать из радуги","position");
        //Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента:
        //position=0.1

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=0
    }

    if (NameFunction=="HML_GiveRainbowColorG")
    {
        double position = 0.6;

        int G=HML_GiveRainbowColorG(position);

        HML_ShowNumber(position,"Позиция из интервала [0;1], которая говорит какой цвет выдать из радуги","position");
        //Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента:
        //position=0.1

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=103
    }

    if (NameFunction=="HML_GiveRainbowColorB")
    {
        double position = 0.6;

        int B=HML_GiveRainbowColorB(position);

        HML_ShowNumber(position,"Позиция из интервала [0;1], которая говорит какой цвет выдать из радуги","position");
        //Позиция из интервала [0;1], которая говорит какой цвет выдать из градиента:
        //position=0.1

        HML_ShowNumber(B,"Канал B итогового цвета","B");
        //Канал B итогового цвета:
        //B=255
    }

    if (NameFunction=="HML_MutationBinaryVector")
    {
        int VHML_N=10;//Размер массива
        int *a;
        a=new int[VHML_N];
        HML_RandomBinaryVector(a,VHML_N);//Случайный бинарный вектор
        HML_ShowVectorT (a,VHML_N,"Случайный бинарный вектор", "a");
        //Случайный бинарный вектор:
        //a =
        //0	1	1	1	1	0	0	0	1	1

        double ProbabilityOfMutation=0.1;//Вероятность мутации

        //Вызов функции
        HML_MutationBinaryVector(a,ProbabilityOfMutation,VHML_N);

        //Используем полученный результат
        HML_ShowVectorT (a,VHML_N,"Мутированный бинарный вектор", "a");
        //Мутированный бинарный вектор:
        //a =
        //0	1	0	1	1	0	0	0	0	1

        delete [] a;
    }

    if (NameFunction=="HML_TrapeziformTruncatedFuzzyNumber")
    {
        double a=HML_RandomUniform(-4,4);
        double b=a+HML_RandomUniform(0,2);
        double c=b+HML_RandomUniform(0,2);
        double d=c+HML_RandomUniform(0,2);

        double x=HML_RandomUniform(a-1,d+1);

        double m=0.5;

        //Вызов функции
        double f=HML_TrapeziformTruncatedFuzzyNumber (x,a,b,c,d,m);

        //Используем полученный результат
        HML_ShowNumber(x,"Значение параметра","x");
        //Значение параметра:
        //x=-1.63713
        HML_ShowNumber(a,"Значение первого параметра трапецевидного нечеткого числа","a");
        //Значение первого параметра трапецевидного нечеткого числа:
        //a=-2.75211
        HML_ShowNumber(b,"Значение второго параметра трапецевидного нечеткого числа","b");
        //Значение второго параметра трапецевидного нечеткого числа:
        //b=-2.49458
        HML_ShowNumber(c,"Значение третьего параметра трапецевидного нечеткого числа","c");
        //Значение третьего параметра трапецевидного нечеткого числа:
        //c=-1.6546
        HML_ShowNumber(d,"Значение последнего параметра трапецевидного нечеткого числа","d");
        //Значение последнего параметра трапецевидного нечеткого числа:
        //d=-0.0519362
        HML_ShowNumber(m,"Усечение проводим по границе","m");
        //Усечение проводим по границе:
        //m=0.5
        HML_ShowNumber(f,"Значение функция принадлежности усеченного трапециевидного нечеткого числа","f");
        //Значение функция принадлежности усеченного трапециевидного нечеткого числа:
        //f=0.5
    }

    if (NameFunction=="HML_NewtonSecondLawForce")
    {
        double a=2.2;
        double m=3;

        double F=HML_NewtonSecondLawForce(a,m);

        //Используем полученный результат
        HML_ShowNumber(a,"Ускорение тела","a");
        //Ускорение тела:
        //a=2.2
        HML_ShowNumber(m,"Масса тела","m");
        //Масса тела:
        //m=3
        HML_ShowNumber(F,"Сила приложенная к телу","F");
        //Сила приложенная к телу:
        //F=6.6
    }

    if (NameFunction=="HML_NewtonSecondLawAcceleration")
    {
        double F=7;
        double m=3;

        double a=HML_NewtonSecondLawAcceleration(F,m);

        //Используем полученный результат
        HML_ShowNumber(a,"Ускорение тела","a");
        //Ускорение тела:
        //a=2.33333
        HML_ShowNumber(m,"Масса тела","m");
        //Масса тела:
        //m=3
        HML_ShowNumber(F,"Сила приложенная к телу","F");
        //Сила приложенная к телу:
        //F=7
    }

    if (NameFunction=="HML_AcceptanceLimitsLeft")
    {
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];
        double *Left;
        Left=new double[VHML_N];
        HML_FillVector(Left,VHML_N,-1.);//Левая граница

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomUniform(-1.1,1.1);
        HML_ShowVector (a,VHML_N,"Вектор", "a");
        //Вектор:
        //a =
        //-0.883149
        //-1.04337
        //0.413145
        //0.109003
        //-0.177475
        //0.648155
        //0.219876
        //-0.827451
        //-1.07879
        //0.739566

        //Вызов функции
        HML_AcceptanceLimitsLeft(a,Left,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Left,VHML_N,"Левые границы", "Left");
        //Левые границы:
        //Left =
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1
        //-1

        HML_ShowVector (a,VHML_N,"Отредактированный вектор", "a");
        //Отредактированный вектор:
        //a =
        //-0.883149
        //-1
        //0.413145
        //0.109003
        //-0.177475
        //0.648155
        //0.219876
        //-0.827451
        //-1
        //0.739566

        delete [] a;
        delete [] Left;
    }

    if (NameFunction=="HML_AcceptanceLimitsRight")
    {
        int VHML_N=10;//Размер массива
        double *a;
        a=new double[VHML_N];
        double *Right;
        Right=new double[VHML_N];
        HML_FillVector(Right,VHML_N,1.);//Левая граница

        for (int i=0;i<VHML_N;i++) a[i]=HML_RandomUniform(-1.1,1.1);
        HML_ShowVector (a,VHML_N,"Вектор", "a");
        //Вектор:
        //a =
        //-0.292555
        //1.08624
        //0.491535
        //0.911258
        //-0.367329
        //1.09461
        //-1.0691
        //0.767508
        //0.492846
        //-0.893972

        //Вызов функции
        HML_AcceptanceLimitsRight(a,Right,VHML_N);

        //Используем полученный результат
        HML_ShowVector (Right,VHML_N,"Правые границы", "Right");
        //Левые границы:
        //Right =
        //1
        //1
        //1
        //1
        //1
        //1
        //1
        //1
        //1
        //1

        HML_ShowVector (a,VHML_N,"Отредактированный вектор", "a");
        //Отредактированный вектор:
        //a =
        //-0.292555
        //1
        //0.491535
        //0.911258
        //-0.367329
        //1
        //-1.0691
        //0.767508
        //0.492846
        //-0.893972

        delete [] a;
        delete [] Right;
    }

    if (NameFunction=="HML_AcceptanceLimitsNumberLeft")
    {
        int a    = HML_RandomUniformInt(-50,50);
        int Left = -40;

        int Result=HML_AcceptanceLimitsNumberLeft(a,Left);

        //Используем полученный результат
        HML_ShowNumber(a,"Первоначальное число","a");
        //Первоначальное число:
        //a=49
        HML_ShowNumber(Left,"Левая граница","Left");
        //Левая граница:
        //Left=-40
        HML_ShowNumber(Result,"Число в рамках","Result");
        //Число в рамках:
        //Result=30
    }

    if (NameFunction=="HML_AcceptanceLimitsNumberRight")
    {
        int a    = HML_RandomUniformInt(-50,50);
        int Right= 30;

        int Result=HML_AcceptanceLimitsNumberRight(a,Right);

        //Используем полученный результат
        HML_ShowNumber(a,"Первоначальное число","a");
        //Первоначальное число:
        //a=49
        HML_ShowNumber(Right,"Правая граница","Right");
        //Правая граница:
        //Right=30
        HML_ShowNumber(Result,"Число в рамках","Result");
        //Число в рамках:
        //Result=30
    }

    if (NameFunction=="HML_NonparametricEstimatorOfDerivative")
    {
        int N=100;
        double *X=new double [N];
        double *Y=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }
        //HML_NoiseInVector(Y,5,N);//добавим помеху

        double x=HML_RandomUniform(0,6);//Для этого числа будем считать оценку регрессию

        double C=0.5;//коэффициент размытости

        //Применим функцию
        bool b;
        double y=HML_NonparametricEstimatorOfDerivative(x,X,Y,N,C,3,&b);

        HML_ShowNumber(x,"Входной парметр","x");
        //Входной парметр:
        //x=1.48351
        HML_ShowNumber(y,"Непараметрическая оценка производной","y");
        //Непараметрическая оценка производной:
        //y=0.0281603
        HML_ShowNumber(cos(x),"Действительное значение производной функции в точке","y*");
        //Действительное значение производной функции в точке:
        //y*=0.0871789

        delete [] X;
        delete [] Y;
    }

    if (NameFunction=="HML_NonparametricEstimatorOfDerivative2")
    {
        int N=100;
        double *X=new double [N];
        double *Y=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }
        //HML_NoiseInVector(Y,5,N);//добавим помеху

        double x=HML_RandomUniform(0,6);//Для этого числа будем считать оценку регрессию

        double C=0.3;//коэффициент размытости

        //Применим функцию
        bool b;
        double y=HML_NonparametricEstimatorOfDerivative4(x,X,Y,N,C,3,&b);

        HML_ShowNumber(x,"Входной парметр","x");
        //Входной парметр:
        //x=3.6964
        HML_ShowNumber(y,"Непараметрическая оценка производной","y");
        //Непараметрическая оценка производной:
        //y=-0.76092
        HML_ShowNumber(cos(x),"Действительное значение производной функции в точке","y*");
        //Действительное значение производной функции в точке:
        //y*=-0.850004

        delete [] X;
        delete [] Y;
    }

    if (NameFunction=="HML_NonparametricEstimatorOfDerivative4")
    {
        int N=100;
        double *X=new double [N];
        double *Y=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }
        //HML_NoiseInVector(Y,5,N);//добавим помеху

        double x=HML_RandomUniform(0,6);//Для этого числа будем считать оценку регрессию

        double C=0.5;//коэффициент размытости

        //Применим функцию
        bool b;
        double y=HML_NonparametricEstimatorOfDerivative4(x,X,Y,N,C,3,&b);

        HML_ShowNumber(x,"Входной парметр","x");
        //Входной парметр:
        //x=5.53702
        HML_ShowNumber(y,"Непараметрическая оценка производной","y");
        //Непараметрическая оценка производной:
        //y=0.761896
        HML_ShowNumber(cos(x),"Действительное значение производной функции в точке","y*");
        //Действительное значение производной функции в точке:
        //y*=0.734294

        delete [] X;
        delete [] Y;
    }

    if (NameFunction=="HML_NonparametricEstimatorOfDerivative5")
    {
        int N=100;
        double *X=new double [N];
        double *Y=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }
        //HML_NoiseInVector(Y,5,N);//добавим помеху

        double x=HML_RandomUniform(0,6);//Для этого числа будем считать оценку регрессию

        double C=0.5;//коэффициент размытости

        //Применим функцию
        bool b;
        double y=HML_NonparametricEstimatorOfDerivative5(x,X,Y,N,C,3,&b);

        HML_ShowNumber(x,"Входной парметр","x");
        //Входной парметр:
        //x=3.09027
        HML_ShowNumber(y,"Непараметрическая оценка производной","y");
        //Непараметрическая оценка производной:
        //y=-0.975845
        HML_ShowNumber(cos(x),"Действительное значение производной функции в точке","y*");
        //Действительное значение производной функции в точке:
        //y*=-0.998683

        delete [] X;
        delete [] Y;
    }

    if (NameFunction=="HML_MakingVectorForNonparametricEstimatorOfDerivative3")
    {
        int N=20;
        double *X=new double [N];
        double *Y=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }

        double *dY = new double [N];

        double C=0.6;//коэффициент размытости

        //Применим функцию
        HML_MakingVectorForNonparametricEstimatorOfDerivative3(dY,X,Y,N,C,3);

        HML_ShowVector(dY, N, "Полученный вектор", "dY");
        //Полученный вектор:
        //dY =
        //0.433703
        //0.135073
        //0.423069
        //-0.144353
        //0.132919
        //-0.280884
        //0.173751
        //-1.02639
        //0.0222925
        //0.0887054
        //-0.315277
        //-0.561402
        //0.00702664
        //0.0441916
        //0.168806
        //0.174562
        //-0.228904
        //-0.0751131
        //0.136842
        //-0.0710526

        delete [] X;
        delete [] Y;
        delete [] dY;
    }

    if (NameFunction=="HML_NonparametricEstimatorOfDerivative3")
    {
        int N=100;
        double *X=new double [N];
        double *Y=new double [N];
        double *dY=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }
        //HML_NoiseInVector(Y,5,N);//добавим помеху

        double x=HML_RandomUniform(0,6);//Для этого числа будем считать оценку регрессию

        double C=0.3;//коэффициент размытости

        HML_MakingVectorForNonparametricEstimatorOfDerivative3(dY,X,Y,N,C,3);

        //Применим функцию
        bool b;
        double y=HML_NonparametricEstimatorOfDerivative3(x,X,dY,N,C,3,&b);

        HML_ShowNumber(x,"Входной парметр","x");
        //Входной парметр:
        //x=4.00877
        HML_ShowNumber(y,"Непараметрическая оценка производной","y");
        //Непараметрическая оценка производной:
        //y=-0.532728
        HML_ShowNumber(cos(x),"Действительное значение производной функции в точке","y*");
        //Действительное значение производной функции в точке:
        //y*=-0.646979

        delete [] X;
        delete [] Y;
        delete [] dY;
    }

    if (NameFunction=="HML_MakingVectorForNonparametricEstimatorOfDerivative6")
    {
        int N=20;
        double *X=new double [N];
        double *Y=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }

        double *dY = new double [N];

        double C=0.6;//коэффициент размытости

        //Применим функцию
        HML_MakingVectorForNonparametricEstimatorOfDerivative6(dY,X,Y,N,C,3);

        HML_ShowVector(dY, N, "Полученный вектор", "dY");
        //Полученный вектор:
        //dY =
        //-0.515422
        //-0.481574
        //-0.443075
        //-0.360637
        //-0.506483
        //-0.0248741
        //0.898217
        //-0.518947
        //-0.517786
        //0.84482
        //-0.511115
        //0.751889
        //0.0241403
        //-0.408982
        //-0.234821
        //0.458671
        //0.0267333
        //-0.400295
        //-0.184401
        //0.577117

        delete [] X;
        delete [] Y;
        delete [] dY;
    }

    if (NameFunction=="HML_NonparametricEstimatorOfDerivative6")
    {
        int N=100;
        double *X=new double [N];
        double *Y=new double [N];
        double *dY=new double [N];
        for (int i=0;i<N;i++)
        {
            X[i] = HML_RandomUniform(0,6);
            Y[i] = sin(X[i]);
        }
        //HML_NoiseInVector(Y,5,N);//добавим помеху

        double x=HML_RandomUniform(0,6);//Для этого числа будем считать оценку регрессию

        double C=0.3;//коэффициент размытости

        HML_MakingVectorForNonparametricEstimatorOfDerivative6(dY,X,Y,N,C,3);

        //Применим функцию
        bool b;
        double y=HML_NonparametricEstimatorOfDerivative6(x,X,dY,N,C,3,&b);

        HML_ShowNumber(x,"Входной парметр","x");
        //Входной парметр:
        //x=5.29326
        HML_ShowNumber(y,"Непараметрическая оценка производной","y");
        //Непараметрическая оценка производной:
        //y=0.732548
        HML_ShowNumber(cos(x),"Действительное значение производной функции в точке","y*");
        //Действительное значение производной функции в точке:
        //y*=0.548749

        delete [] X;
        delete [] Y;
        delete [] dY;
    }

    if (NameFunction=="HML_NegativeColorR")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        int R=HML_NegativeColorR(R1, G1, B1);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=230
    }

    if (NameFunction=="HML_NegativeColorG")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        int G=HML_NegativeColorG(R1, G1, B1);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=127
    }

    if (NameFunction=="HML_NegativeColorB")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        int B=HML_NegativeColorB(R1, G1, B1);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(B,"Канал B итогового цвета","B");
        //Канал R итогового цвета:
        //R=230
    }

    if (NameFunction=="HML_GreyscaleR")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        int R=HML_GreyscaleR(R1, G1, B1);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=76
    }

    if (NameFunction=="HML_GreyscaleG")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        int G=HML_GreyscaleG(R1, G1, B1);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=76
    }

    if (NameFunction=="HML_GreyscaleB")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        int B=HML_GreyscaleB(R1, G1, B1);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(B,"Канал B итогового цвета","B");
        //Канал B итогового цвета:
        //B=76
    }

    if (NameFunction=="HML_DivideColorR")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=2;

        int R=HML_DivideColorR(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=12
    }

    if (NameFunction=="HML_DivideColorG")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=2;

        int G=HML_DivideColorG(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=64
    }

    if (NameFunction=="HML_DivideColorB")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=2;

        int B=HML_DivideColorB(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(B,"Канал R итогового цвета","B");
        //Канал B итогового цвета:
        //B=37
    }

    if (NameFunction=="HML_SubtractColorR")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=50;

        int R=HML_SubtractColorR(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=0
    }

    if (NameFunction=="HML_SubtractColorG")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=50;

        int G=HML_SubtractColorG(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=78
    }

    if (NameFunction=="HML_SubtractColorB")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=50;

        int B=HML_SubtractColorB(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(B,"Канал B итогового цвета","B");
        //Канал B итогового цвета:
        //B=25
    }

    if (NameFunction=="HML_MultiplyColorB")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=2;

        int B=HML_MultiplyColorB(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(B,"Канал B итогового цвета","B");
        //Канал B итогового цвета:
        //B=150
    }

    if (NameFunction=="HML_MultiplyColorG")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=2;

        int G=HML_MultiplyColorG(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=255
    }

    if (NameFunction=="HML_MultiplyColorR")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=2;

        int R=HML_MultiplyColorR(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=50
    }

    if (NameFunction=="HML_AddColorR")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=50;

        int R=HML_AddColorR(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(R,"Канал R итогового цвета","R");
        //Канал R итогового цвета:
        //R=75
    }

    if (NameFunction=="HML_AddColorG")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=50;

        int G=HML_AddColorG(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(G,"Канал G итогового цвета","G");
        //Канал G итогового цвета:
        //G=178
    }

    if (NameFunction=="HML_AddColorB")
    {
        int R1 = 25;
        int G1 = 128;
        int B1 = 75;

        double p=50;

        int B=HML_AddColorB(R1, G1, B1, p);

        //Используем полученный результат
        HML_ShowNumber(R1,"Канал R первого цвета","R1");
        //Канал R первого цвета:
        //R1=25
        HML_ShowNumber(G1,"Канал G первого цвета","G1");
        //Канал G первого цвета:
        //G1=128
        HML_ShowNumber(B1,"Канал B первого цвета","B1");
        //Канал B первого цвета:
        //B1=75

        HML_ShowNumber(B,"Канал B итогового цвета","B");
        //Канал B итогового цвета:
        //B=125
    }

    if (NameFunction=="HML_LogFactorial")
    {
        double a=HML_RandomUniformInt(0,100);

        double Result=HML_LogFactorial(a);

        //Используем полученный результат
        HML_ShowNumber(Result,"Логарифм факториала числа "+HML_NumberToText(a),"log(a!)");
        //Логарифм факториала числа 51:
        //log(a!)=152.41
    }

    if (NameFunction=="HML_RowInMatrixMultiplyNumber")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=5;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
         for (j=0;j<VHML_M;j++)
          Matrix[i][j]=HML_RandomUniformInt(10,100);

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        //Случайная матрица:
        //Matrix =
        //51	85	33	78	38
        //32	18	87	88	85
        //98	22	79	44	76
        //10	86	53	99	43
        //10	78	14	29	35

        int Number=HML_RandomUniformInt(-10,10);

        //Вызов функции
        HML_RowInMatrixMultiplyNumber(Matrix,2,VHML_M,Number);

        //Используем полученный результат
        HML_ShowNumber (Number,"Число, на которое умножается третья строка","Number");
        //Число, на которое умножается матрица:
        //Number=2
        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Матрица, где третья строка умноженнилась на число", "Matrix");
        //Матрица, где третья строка умноженнилась на число:
        //Matrix =
        //51	85	33	78	38
        //32	18	87	88	85
        //196	44	158	88	152
        //10	86	53	99	43
        //10	78	14	29	35

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="HML_ColInMatrixMultiplyNumber")
    {
        int i,j;
        int VHML_N=5;//Размер массива (число строк)
        int VHML_M=5;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VHML_N];
        for (i=0;i<VHML_N;i++) Matrix[i]=new int[VHML_M];
        //Заполним случайными числами
        for (i=0;i<VHML_N;i++)
         for (j=0;j<VHML_M;j++)
          Matrix[i][j]=HML_RandomUniformInt(10,100);

        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Случайная матрица", "Matrix");
        //Случайная матрица:
        //Matrix =
        //92	42	98	88	70
        //62	68	66	47	45
        //49	47	39	36	18
        //49	96	55	66	20
        //30	66	96	10	55
        int Number=HML_RandomUniformInt(-10,10);

        //Вызов функции
        HML_ColInMatrixMultiplyNumber(Matrix,2,VHML_M,Number);

        //Используем полученный результат
        HML_ShowNumber (Number,"Число, на которое умножается третий столбец","Number");
        //Число, на которое умножается матрица:
        //Number=2
        HML_ShowMatrix (Matrix,VHML_N,VHML_M,"Матрица, где третий столбец умножается на число", "Matrix");
        //Матрица, где третий столбец умножается на число:
        //Matrix =
        //92	42	490	88	70
        //62	68	330	47	45
        //49	47	195	36	18
        //49	96	275	66	20
        //30	66	480	10	55

        for (i=0;i<VHML_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

}
//---------------------------------------------------------------------------
