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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DS=QDir::separator();//какой разделитель используется в пути между папками
    Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
    HQt_BeginHtml(Path);
    ui->webView->setUrl(QUrl::fromLocalFile(Path+"index.html"));// и в webViewотображаем index.html (его вообще не трогаем)

    MHL_SeedRandom();//Инициализация датчика случайных чисел

    model = new QStandardItemModel(this);
    model->setObjectName(QString::fromUtf8("model"));

    QStandardItem *item;//элемент списка

    //добавление новых элементов

    //Сюда нужно добавить код

    item = new QStandardItem(QString("TMHL_FillVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MaximumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MinimumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SumVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SumSquareVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_ZeroVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_VectorToVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DegToRad"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RadToDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BitNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomUniform"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomNormal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomUniformInt"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealMatrixInCols"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealMatrixInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealMatrixInRows"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealVectorInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomVectorOfProbability"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cos"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CosDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cosec"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CosecDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cotan"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CotanDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Sec"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SecDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Sin"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SinDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Tan"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TanDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_OrdinalVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_OrdinalVectorZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SearchFirstNotZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SearchFirstZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_VectorMinusVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_VectorPlusVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_VectorMultiplyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cosech"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cosh"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cotanh"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Sech"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Sinh"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Tanh"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfMaximumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfMinimumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfNegativeValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfPositiveValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfZeroValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_FibonacciNumbersVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_EqualityOfVectors"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_CheckElementInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Max"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Min"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Abs"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberInterchange"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Sign"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SignNull"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SumOfDigits"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_ZeroMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SumMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MaximumOfMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MinimumOfMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_FillMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixMinusMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixPlusMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixMultiplyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixT"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixMultiplyMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixMultiplyMatrixT"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixTMultiplyMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomIntMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomIntMatrixInCols"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomIntMatrixInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomIntMatrixInRows"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomIntVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomIntVectorInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomBinaryMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomBinaryVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BernulliVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomArrangingObjectsIntoBaskets"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_ColInterchange"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_ColToMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_DeleteColInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_DeleteRowInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixToCol"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixToMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MatrixToRow"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RowInterchange"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RowToMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfDifferentValuesInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_IdentityMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MixingVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_ReverseVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfDifferentValuesInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_PowerOf"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Parity"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ArithmeticalProgression"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_GeometricSeries"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_GreatestCommonDivisorEuclid"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_LeastCommonMultipleEuclid"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_HowManyPowersOfTwo"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SumGeometricSeries"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SumOfArithmeticalProgression"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_FibonacciNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BoolCrossingTwoSegment"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_AcceptanceLimits"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_NoiseInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_EuclidNorma"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MixingVectorWithConjugateVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MixingRowsInOrder"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Chebychev"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_CityBlock"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Euclid"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RightDerivative"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CenterDerivative"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_LeftDerivative"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_IntegralOfTrapezium"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_IntegralOfSimpson"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_IntegralOfRectangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_HeavisideFunction"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ExpMSxD2"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_NormalizationNumberAll"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_InverseNormalizationNumberAll"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BinaryMonteCarloAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleDescendingSort"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleSort"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleSortInGroups"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleSortWithConjugateVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleSortWithTwoConjugateVectors"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DensityOfDistributionOfNormalizedCenteredNormalDistribution"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DistributionFunctionOfNormalizedCenteredNormalDistribution"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_StdDevToVariance"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_VarianceToStdDev"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Mean"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Median"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SampleCovariance"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Variance"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SinglepointCrossover"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_TwopointCrossover"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_UniformCrossover"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BinaryToDecimalFromPart"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BinaryToDecimal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BinaryVectorToRealVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_GrayCodeToBinaryFromPart"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_GrayCodeToBinary"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BinaryGrayVectorToRealVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomVectorOfPermutation"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_RandomMatrixOfPermutation"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MutationBinaryMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TournamentSelectionWithReturn"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TournamentSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_MakeVectorOfRankForRankSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_NormalizationVectorOne"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_NormalizationVectorMaxMin"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_NormalizationVectorAll"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_MakeVectorOfProbabilityForProportionalSelectionV2"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SelectItemOnProbability"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ProportionalSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ProportionalSelectionV2"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ProportionalSelectionV3"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RankSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_StandartBinaryGeneticAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_StandartRealGeneticAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_StandartGeneticAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Ackley"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_ParaboloidOfRevolution"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Rastrigin"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Rosenbrock"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_SumVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Factorial"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_KCombinations"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ProbabilityOfTournamentSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_MakeVectorOfProbabilityForRanklSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_MakeVectorOfRankZeroForRankSelection"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomUniformIntIncluding"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleSortRowWithOtherConjugateRowsInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleSortEveryRowInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleSortColWithOtherConjugateColsInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_BubbleSortEveryColInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_QuadraticEquation"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BellShapedKernelExp"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BellShapedKernelParabola"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BellShapedKernelRectangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BellShapedKernelTriangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DerivativeOfBellShapedKernelExp"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DerivativeOfBellShapedKernelParabola"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DerivativeOfBellShapedKernelRectangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DerivativeOfBellShapedKernelTriangle"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TrapeziformFuzzyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Binary"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_ProductOfElementsOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_MixedMultiLogicVectorOfFullSearch"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Real"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SearchElementInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_EqualityOfMatrixes"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DependentNoiseInVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_Minkovski"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RealMonteCarloAlgorithm"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DichotomyOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_FibonacciOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_GoldenSectionOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_QuadraticFitOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RealMonteCarloOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_UniformSearchOptimization"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_UniformSearchOptimizationN"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_CheckForIdenticalRowsInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_CheckForIdenticalColsInMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_LeftBorderOfWilcoxonWFromTable"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RightBorderOfWilcoxonWFromTable"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ProbabilityDensityFunctionOfInverseGaussianDistribution"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DistributionFunctionOfNormalDistribution"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_WilcoxonW"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_CompareMeanOfVectors"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_LineGeneralForm"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_LineSlopeInterceptForm"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_LineTwoPoint"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Parabola"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BinaryGeneticAlgorithmWDPOfNOfGPS"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RealGeneticAlgorithmWDPOfNOfGPS"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BinaryGeneticAlgorithmWDTS"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RealGeneticAlgorithmWDTS"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SinglepointCrossoverWithCopying"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_TwopointCrossoverWithCopying"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BinaryGeneticAlgorithmWCC"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RealGeneticAlgorithmWCC"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_AdditivePotential"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_MultiplicativePotential"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BinaryGeneticAlgorithmTournamentSelectionWithReturn"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RealGeneticAlgorithmTournamentSelectionWithReturn"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_ReverseGriewank"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_HyperEllipsoid"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_RotatedHyperEllipsoid"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Wave"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Multiextremal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Multiextremal2"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Sombrero"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Himmelblau"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Katnikov"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Multiextremal3"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Multiextremal4"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_StepFunction"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Rana"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_ShekelsFoxholes"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_EggHolder"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_RastriginWithChange"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_RastriginWithTurning"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Schwefel"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Griewangk"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_InvertedGriewangk"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_InvertedRosenbrock"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_GaussianQuartic"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_RastriginNovgorod"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_AlmostZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_QuadraticEquationCount"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_AlmostEqual"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_UncorrectedVariance"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_MeaningOfLife"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SinglepointCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TwopointCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_UniformCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MeanOfUpperFilter"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MeanOfLowerFilter"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MeanOfFilter"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ArithmeticalCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TestFunction_Bosom"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_FlatCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_GeometricalCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BLXCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_LinearCrossoverForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_ExtendedLineForReal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BinaryGeneticAlgorithmTwiceGenerations"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RealGeneticAlgorithmTwiceGenerations"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SeparateVectorLimitOnProductElements"));
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
double Func(int *x,int VMHL_N)
{
    //Сумма всех элементов массива
    return TMHL_SumVector(x,VMHL_N);
}
//---------------------------------------------------------------------------
double Func2(double *x,int VMHL_N)
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
void MainWindow::MHL_ShowText (QString TitleX)
{
    /*
    Функция выводит число строку в textEdit.
    Входные параметры:
     TitleX - непосредственно строка сама.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=HQt_ShowText (TitleX);// из HarrixQtLibrary.h
    Html=VMHL_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------
template <class T> void MainWindow::MHL_ShowNumber (T VMHL_X, QString TitleX, QString NameX)
{
    /*
    Функция выводит число VMHL_X в textEdit.
    Входные параметры:
     VMHL_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowNumber (VMHL_X, TitleX, NameX);// из HarrixQtLibrary.h
    Html=VMHL_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------
template <class T> QString MainWindow::MHL_NumberToText (T VMHL_X)
{
    /*
    Функция выводит число VMHL_X в строку.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_NumberToText (VMHL_X);
    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VMHL_Vector в textEdit
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowVector (VMHL_Vector,VMHL_N, TitleVector, NameVector);// из HarrixQtLibrary.h
    Html=VMHL_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VMHL_Vector в textEdit в траснпонированном виде
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowVectorT (VMHL_Vector,VMHL_N, TitleVector, NameVector);// из HarrixQtLibrary.h
    Html=VMHL_Result;
    HQt_AddHtml(Html);
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowMatrix (T **VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция выводит матрицу VMHL_Matrix в textEdit
    Входные параметры:
     VMHL_Matrix - указатель на указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowMatrix (VMHL_Matrix, VMHL_N ,VMHL_M, TitleMatrix, NameMatrix);// из HarrixQtLibrary.h
    Html=VMHL_Result;
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
    if (NameFunction=="TMHL_FillVector")
    {
        int VMHL_N=10;//Размер массива
        int *a;
        a=new int[VMHL_N];

        int x=5;//заполнитель

        //Вызов функции
        TMHL_FillVector(a,VMHL_N,x);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
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

    if (NameFunction=="TMHL_MaximumOfVector")
    {
        int VMHL_N=10;//Размер массива
        double max;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        max=TMHL_MaximumOfVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
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

        MHL_ShowNumber (max,"Максимальное значение в векторе", "max");
        //Максимальное значение в векторе:
        //max=0.937286

        delete [] a;
    }

    if (NameFunction=="TMHL_MinimumOfVector")
    {
        int VMHL_N=10;//Размер массива
        double min;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        min=TMHL_MinimumOfVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
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

        MHL_ShowNumber (min,"Минимальное значение в векторе", "min");
        //Максимальное значение в векторе:
        //max=0.0112305

        delete [] a;
    }

    if (NameFunction=="TMHL_SumVector")
    {
        int VMHL_N=10;//Размер массива
        double sum;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        sum=TMHL_SumVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
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

        MHL_ShowNumber (sum,"Сумма элементов массива", "sum");
        //Сумма элементов массива:
        //sum=4.68765

        delete [] a;
    }

    if (NameFunction=="TMHL_SumSquareVector")
    {
        int VMHL_N=10;//Размер массива
        double sum;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=i;//Заполняем значениями

        //Вызов функции
        sum=TMHL_SumSquareVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
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

        MHL_ShowNumber (sum,"Сумма квадратов элементов массива", "sum");
        //Сумма квадратов элементов массива:
        //sum=285

        delete [] a;
    }

    if (NameFunction=="TMHL_ZeroVector")
    {
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];

        //Вызов функции
        TMHL_ZeroVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Зануленный вектор", "a");
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

    if (NameFunction=="TMHL_VectorToVector")
    {
        int VMHL_N=10;//Размер массива

        double *a;
        a=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomNumber();//Заполняем случайными значениями

        double *b;
        b=new double[VMHL_N];

        //Вызов функции
        TMHL_VectorToVector(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Первоначальный вектор", "a");
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

        MHL_ShowVector (b,VMHL_N,"Вектор, в который скопировали первый", "b");
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

    if (NameFunction=="MHL_DegToRad")
    {
        double Rad;
        double Deg=90;//Угол в градусах

        //Вызов функции
        Rad=MHL_DegToRad(Deg);

        //Используем полученный результат
        MHL_ShowNumber(Rad,"Угол "+MHL_NumberToText(Deg)+" градусов","равен в радианах");
        //Угол 90 градусов:
        //равен в радианах=1.5708
    }

    if (NameFunction=="MHL_RadToDeg")
    {
        double Deg;
        double Rad=MHL_PI;//Угол в радианах

        //Вызов функции
        Deg=MHL_RadToDeg(Rad);

        //Используем полученный результат
        MHL_ShowNumber(Deg,"Угол "+MHL_NumberToText(Rad)+" радиан","равен в градусах");
        //Угол 3.14159 радиан:
        //равен в градусах=180
    }

    if (NameFunction=="MHL_BitNumber")
    {
        int x;
        double P=0.8;//Угол в радианах

        //Вызов функции
        x=MHL_BitNumber(P);

        //Используем полученный результат
        MHL_ShowNumber(x,"Из 0 и 1 с вероятностью "+MHL_NumberToText(P),"выбрано");

        //Вызов функции
        x=MHL_BitNumber();

        //Используем полученный результат
        MHL_ShowNumber(x,"Из 0 и 1 с вероятностью 0.5","выбрано");
    }

    if (NameFunction=="MHL_RandomUniform")
    {
        double x;

        //Вызов функции
        x=MHL_RandomUniform(10,100);

        //Используем полученный результат
        MHL_ShowNumber(x,"Случайное число из интервала [10;100]","x");
        //Случайное число из интервала [10;100]:
        //x=68.4308
    }

    if (NameFunction=="MHL_RandomRealMatrix")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];

        double Left=-3;//левая граница интервала;
        double Right=3;//правая граница интервала;

        //Вызов функции
        MHL_RandomRealMatrix(a,Left,Right,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //1.97571	0.862793	-0.357422
        //-2.62701	-0.202515	-2.79932
        //1.38794	1.35535	-2.29449

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="MHL_RandomNormal")
    {
        double x;
        double Mean=10;//математическое ожидание
        double StdDev=3;//среднеквадратичное отклонение

        //Вызов функции
        x=MHL_RandomNormal(Mean,StdDev);

        //Используем полученный результат
        MHL_ShowNumber(x,"Случайное число по нормальному закону (Mean="+MHL_NumberToText(Mean)+", StdDev="+MHL_NumberToText(StdDev)+")","x");
        //Случайное число по нормальному закону (Mean=10, StdDev=3):
        //x=10.9968
    }

    if (NameFunction=="MHL_RandomUniformInt")
    {
        double x;
        int s0=0,s1=0,s2=0,s3=0;

        //Вызов функции
        for (int i=0;i<1000;i++)
        {
            x=MHL_RandomUniformInt(0,3);
            if (x==0) s0++;
            if (x==1) s1++;
            if (x==2) s2++;
            if (x==3) s3++;
        }

        //Используем полученный результат
        MHL_ShowNumber(x,"Случайное целое число из интервала [0;3)","x");
        MHL_ShowNumber(s0,"Число выпадений 0","s0");
        MHL_ShowNumber(s1,"Число выпадений 1","s0");
        MHL_ShowNumber(s2,"Число выпадений 2","s0");
        MHL_ShowNumber(s3,"Число выпадений 3","s0");
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

    if (NameFunction=="MHL_RandomRealMatrixInCols")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];
        double *Left;
        Left=new double[VMHL_M];
        double *Right;
        Right=new double[VMHL_M];

        Left[0]=-5;//левая границы интервала изменения 1 столбца
        Right[0]=-4; //правая граница интервала изменения 1 столбца

        Left[1]=0;//левая границы интервала изменения 2 столбца
        Right[1]=3; //правая граница интервала изменения 2 столбца

        Left[2]=100;//левая границы интервала изменения 3 столбца
        Right[2]=200; //правая граница интервала изменения 3 столбца

        //Вызов функции
        MHL_RandomRealMatrixInCols(a,Left,Right,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //-4.20267	2.20367	148.468
        //-4.42432	2.09418	138.654
        //-4.07089	1.95831	140.198

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="MHL_RandomRealMatrixInElements")
    {
        int i,j;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];
        double **Left;
        Left=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Left[i]=new double[VMHL_M];
        double **Right;
        Right=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Right[i]=new double[VMHL_M];

        //Возьмем для примера границы интервала равными около номера ячейки в матрице
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
            {
                Left[i][j]=i*VMHL_N+j-0.1;
                Right[i][j]=Left[i][j]+0.2;
            }

        //Вызов функции
        MHL_RandomRealMatrixInElements(a,Left,Right,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (Left,VMHL_N,VMHL_M,"Матрица левых границ", "Left");
        // Матрица левых границ:
        //Left =
        //-0.1	0.9	1.9
        //2.9	3.9	4.9
        //5.9	6.9	7.9

        MHL_ShowMatrix (Right,VMHL_N,VMHL_M,"Матрица правых границ", "Right");
        // Матрица правых границ:
        //Right =
        //0.1	1.1	2.1
        //3.1	4.1	5.1
        //6.1	7.1	8.1

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //0.0829529	1.04504	1.9892
        //2.90126	3.92388	4.90221
        //5.96102	6.90623	8.09661

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_N;i++) delete [] Left[i];
        delete [] Left;
        for (i=0;i<VMHL_N;i++) delete [] Right[i];
        delete [] Right;
    }

    if (NameFunction=="MHL_RandomRealMatrixInRows")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];
        double *Left;
        Left=new double[VMHL_N];
        double *Right;
        Right=new double[VMHL_N];

        Left[0]=-5;//левая границы интервала изменения 1 строки
        Right[0]=-4; //правая граница интервала изменения 1 строки

        Left[1]=0;//левая границы интервала изменения 2 строки
        Right[1]=3; //правая граница интервала изменения 2 строки

        Left[2]=100;//левая границы интервала изменения 3 строки
        Right[2]=200; //правая граница интервала изменения 3 строки

        //Вызов функции
        MHL_RandomRealMatrixInRows(a,Left,Right,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //-4.98376	-4.64868	-4.38959
        //1.14386	2.70071	2.76151
        //141.309	192.12	100.122

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="MHL_RandomRealVector")
    {
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];

        double Left=-3;
        double Right=3;

        //Вызов функции
        MHL_RandomRealVector(a,Left,Right,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Массив", "a");
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

    if (NameFunction=="MHL_RandomRealVectorInElements")
    {
        int VMHL_N=2;//Размер массива
        double *a;
        a=new double[VMHL_N];

        double *Left;
        Left=new double[VMHL_N];
        Left[0]=-3;//Левая граница изменения первого элемента массива
        Left[1]=5;//Левая граница изменения второго элемента массива

        double *Right;
        Right=new double[VMHL_N];
        Right[0]=3;//Правая граница изменения первого элемента массива
        Right[1]=10;//Правая граница изменения второго элемента массива

        //Вызов функции
        MHL_RandomRealVectorInElements(a,Left,Right,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Left,VMHL_N,"Массив левых границ", "Left");
        // Массив левых границ:
        //Left =
        //-3
        //5

        MHL_ShowVector (Right,VMHL_N,"Массив правых границ", "Right");
        // Массив правых границ:
        //Right =
        //3
        //10

        MHL_ShowVector (a,VMHL_N,"Случайных массив", "a");
        // Случайных массив:
        //a =
        //1.32111
        //6.5625

        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="MHL_RandomVectorOfProbability")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];

        //Заполним вектор случайными значениями вероятностей
        //Вызов функции
        MHL_RandomVectorOfProbability(a, VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор вероятностей выбора", "a");
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

        MHL_ShowNumber (TMHL_SumVector(a,VMHL_N),"Его сумма", "Sum");
        // Его сумма:
        //Sum=1
    }

    if (NameFunction=="MHL_Cos")
    {
        double y;
        double Angle=MHL_PI;//Угол в радинах

        //Вызов функции
        y=MHL_Cos(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Косинус угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Косинус угла 3.14159 радианов:
        //равен=-1
    }

    if (NameFunction=="MHL_CosDeg")
    {
        double y;
        double Angle=180;//Угол в градусах

        //Вызов функции
        y=MHL_CosDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Косинус угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Косинус угла 180 градусов:
        //равен=-1
    }

    if (NameFunction=="MHL_Cosec")
    {
        double y;
        double Angle=MHL_PI/4.;//Угол в радинах

        //Вызов функции
        y=MHL_Cosec(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Косеканс угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Косеканс угла 0.785398 радианов:
        //равен=1.41421
    }

    if (NameFunction=="MHL_CosecDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=MHL_CosecDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Косеканс угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Косеканс угла 45 градусов:
        //равен=1.41421
    }

    if (NameFunction=="MHL_Cotan")
    {
        double y;
        double Angle=MHL_PI/4.;//Угол в радинах

        //Вызов функции
        y=MHL_Cotan(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Котангенс угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Котангенс угла 0.785398 радианов:
        //равен=1
    }

    if (NameFunction=="MHL_CotanDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=MHL_CotanDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Котангенс угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Котангенс угла 45 градусов:
        //равен=1
    }

    if (NameFunction=="MHL_Sec")
    {
        double y;
        double Angle=MHL_PI/4.;//Угол в радинах

        //Вызов функции
        y=MHL_Sec(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Секанс угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Секанс угла 0.785398 радианов:
        //равен=1.41421
    }

    if (NameFunction=="MHL_SecDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=MHL_SecDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Секанс угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Секанс угла 45 градусов:
        //равен=1.41421
    }

    if (NameFunction=="MHL_Sin")
    {
        double y;
        double Angle=MHL_PI/2.;//Угол в радинах

        //Вызов функции
        y=MHL_Sin(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Синус угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Синус угла 1.5708 радианов:
        //равен=1
    }

    if (NameFunction=="MHL_SinDeg")
    {
        double y;
        double Angle=90;//Угол в градусах

        //Вызов функции
        y=MHL_SinDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Синус угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Синус угла 90 градусов:
        //равен=1
    }

    if (NameFunction=="MHL_Tan")
    {
        double y;
        double Angle=MHL_PI/4.;//Угол в радинах

        //Вызов функции
        y=MHL_Tan(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Тангенс угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Тангенс угла 0.785398 радианов:
        //равен=1
    }

    if (NameFunction=="MHL_TanDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=MHL_TanDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Тангенс угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Тангенс угла 45 градусов:
        //равен=1
    }

    if (NameFunction=="TMHL_OrdinalVector")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];

        //Вызов функции
        TMHL_OrdinalVector(a,VMHL_N);
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
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");

        delete [] a;
    }

    if (NameFunction=="TMHL_OrdinalVectorZero")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];

        //Вызов функции
        TMHL_OrdinalVectorZero(a,VMHL_N);
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
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");

        delete [] a;
    }

    if (NameFunction=="TMHL_SearchFirstNotZero")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,2);

        //Вызов функции
        int Number=TMHL_SearchFirstNotZero(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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

        MHL_ShowNumber (Number,"Номер первого ненулевого элемента", "Number");
        //Номер первого ненулевого элемента:
        //Number=3

        delete [] a;
    }

    if (NameFunction=="TMHL_SearchFirstZero")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,2);

        //Вызов функции
        int Number=TMHL_SearchFirstZero(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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

        MHL_ShowNumber (Number,"Номер первого нулевого элемента", "Number");
        //Номер первого нулевого элемента:
        //Number=3

        delete [] a;
    }

    if (NameFunction=="TMHL_VectorMinusVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        int *b;
        b=new int[VMHL_N];
        int *c;
        c=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,10);
        for (i=0;i<VMHL_N;i++)
            b[i]=MHL_RandomUniformInt(0,10);

        //Вызов функции
        TMHL_VectorMinusVector(a,b,c,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //0	7	0	0	8	5	0	4	8	2

        MHL_ShowVectorT (b,VMHL_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //6	1	3	1	2	7	2	6	1	4

        MHL_ShowVectorT (c,VMHL_N,"Их разница", "c");
        //Их разница:
        //c =
        //-6	6	-3	-1	6	-2	-2	-2	7	-2

        delete [] a;
        delete [] b;
        delete [] c;

        //Для  переопределенной функции
        VMHL_N=10;//Размер массива (число строк)
        a=new int[VMHL_N];
        b=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,10);
        for (i=0;i<VMHL_N;i++)
            b[i]=MHL_RandomUniformInt(0,10);

        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //6	9	3	0	2	9	4	2	3	7

        //Вызов функции
        TMHL_VectorMinusVector(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (b,VMHL_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //5	6	3	8	5	0	7	6	4	4

        MHL_ShowVectorT (a,VMHL_N,"Из первого вычли второй", "a");
        //Из первого вычли второй:
        //a =
        //1	3	0	-8	-3	9	-3	-4	-1	3

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_VectorPlusVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        int *b;
        b=new int[VMHL_N];
        int *c;
        c=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,10);
        for (i=0;i<VMHL_N;i++)
            b[i]=MHL_RandomUniformInt(0,10);

        //Вызов функции
        TMHL_VectorPlusVector(a,b,c,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //2	7	9	2	3	3	3	2	8	8


        MHL_ShowVectorT (b,VMHL_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //3	7	2	9	5	3	2	7	2	7

        MHL_ShowVectorT (c,VMHL_N,"Их сумма", "c");
        //Их сумма:
        //c =
        //5	14	11	11	8	6	5	9	10	15

        delete [] a;
        delete [] b;
        delete [] c;

        //Для  переопределенной функции
        VMHL_N=10;//Размер массива (число строк)
        a=new int[VMHL_N];
        b=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,10);
        for (i=0;i<VMHL_N;i++)
            b[i]=MHL_RandomUniformInt(0,10);

        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //0	6	7	4	9	3	9	8	5	6

        //Вызов функции
        TMHL_VectorPlusVector(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (b,VMHL_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //1	7	0	5	4	0	9	5	7	7

        MHL_ShowVectorT (a,VMHL_N,"К первому прибавили второй", "a");
        //К первому прибавили второй:
        //a =
        //1	13	7	9	13	3	18	13	12	13

        delete [] a;
        delete [] b;

    }

    if (NameFunction=="TMHL_VectorMultiplyNumber")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,10);

        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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

        double Number=MHL_RandomUniform(0,10);

        //Вызов функции
        TMHL_VectorMultiplyNumber(a,VMHL_N,Number);

        //Используем полученный результат
        MHL_ShowNumber (Number,"Случайный множитель", "Number");
        //Случайный множитель:
        //Number=3.57941

        MHL_ShowVector (a,VMHL_N,"Умножили на число Number", "a");
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

    if (NameFunction=="MHL_Cosech")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Cosech(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический косеканс от x="+MHL_NumberToText(x),"равен");
        //Гиперболический косеканс от x=0.571289:
        //равен=1.65872
    }

    if (NameFunction=="MHL_Cosh")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Cosh(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический косинус от x="+MHL_NumberToText(x),"равен");
        //Гиперболический косинус от x=4.04968:
        //равен=28.6983
    }

    if (NameFunction=="MHL_Cotanh")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Cotanh(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический котангенс от x="+MHL_NumberToText(x),"равен");
        //Гиперболический котангенс от x=1.92505:
        //равен=1.04348
    }

    if (NameFunction=="MHL_Sech")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Sech(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический секанс от x="+MHL_NumberToText(x),"равен");
        //Гиперболический секанс от x=0.679932:
        //равен=0.806323
    }

    if (NameFunction=="MHL_Sinh")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Sinh(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический синус от x="+MHL_NumberToText(x),"равен");
        //Гиперболический синус от x=0.166321:
        //равен=0.167089
    }

    if (NameFunction=="MHL_Tanh")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Tanh(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический тангенс от x="+MHL_NumberToText(x),"равен");
        //Гиперболический тангенс от x=4.27643:
        //равен=0.999614
    }

    if (NameFunction=="TMHL_NumberOfMaximumOfVector")
    {
        int i;
        int VMHL_N=10;//Размер массива
        double *Vector=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++) Vector[i]=MHL_RandomNumber();

        //Вызов функции
        double Number=TMHL_NumberOfMaximumOfVector(Vector,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (Vector,VMHL_N,"Случайный массив", "Vector");
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

        MHL_ShowNumber(Number,"Номер максимального элемента","Number");//Например, выводим результат
        // Номер максимального элемента:
        //Number=8
        delete [] Vector;
    }

    if (NameFunction=="TMHL_NumberOfMinimumOfVector")
    {
        int i;
        int VMHL_N=10;//Размер массива
        double *Vector=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++) Vector[i]=MHL_RandomNumber();

        //Вызов функции
        double Number=TMHL_NumberOfMinimumOfVector(Vector,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (Vector,VMHL_N,"Случайный массив", "Vector");
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

        MHL_ShowNumber(Number,"Номер минимального элемента","Number");//Например, выводим результат
        //Номер минимального элемента:
        //Number=7
        delete [] Vector;
    }

    if (NameFunction=="TMHL_NumberOfNegativeValues")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(-20,20);

        //Вызов функции
        int NumberOfNegative=TMHL_NumberOfNegativeValues(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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

        MHL_ShowNumber (NumberOfNegative,"Число отрицательных значений в векторе", "NumberOfNegative");
        //Число отрицательных значений в векторе:
        //NumberOfNegative=5

        delete [] a;
    }

    if (NameFunction=="TMHL_NumberOfPositiveValues")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(-20,20);

        //Вызов функции
        int NumberOfNegative=TMHL_NumberOfPositiveValues(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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

        MHL_ShowNumber (NumberOfNegative,"Число положительных значений в векторе", "NumberOfNegative");
        //Число положительных значений в векторе:
        //NumberOfNegative=6

        delete [] a;
    }

    if (NameFunction=="TMHL_NumberOfZeroValues")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(-2,2);

        //Вызов функции
        int NumberOfNegative=TMHL_NumberOfZeroValues(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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

        MHL_ShowNumber (NumberOfNegative,"Число нулевых значений в векторе", "NumberOfNegative");
        //Число нулевых значений в векторе:
        //NumberOfNegative=4

        delete [] a;
    }

    if (NameFunction=="TMHL_FibonacciNumbersVector")
    {
        int VMHL_N=MHL_RandomUniformInt(5,15);//Размер массива
        double *x;
        x=new double[VMHL_N];

        //Вызов функции
        TMHL_FibonacciNumbersVector(x,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Вектор, заполненый числами Фибоначи", "x");
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

    if (NameFunction=="TMHL_EqualityOfVectors")
    {
        int VMHL_N=5;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        int *b;
        b=new int[VMHL_N];

        int x=MHL_RandomUniformInt(0,2);//заполнитель для вектора a
        int y=MHL_RandomUniformInt(0,2);//заполнитель для вектора b
        TMHL_FillVector (a, VMHL_N, x);
        TMHL_FillVector (b, VMHL_N, y);


        //Вызов функции
        int Q=TMHL_EqualityOfVectors(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");
        //Вектор:
        //a =
        //1
        //1
        //1
        //1
        //1

        MHL_ShowVector (b,VMHL_N,"Вектор", "b");
        //Вектор:
        //b =
        //0
        //0
        //0
        //0
        //0

        MHL_ShowNumber (Q,"Равны ли вектора", "Q");
        // Равны ли вектора:
        //Q=0


        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_CheckElementInVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,5);
        int k=MHL_RandomUniformInt(0,5);//искомое число

        //Вызов функции
        int Search=TMHL_CheckElementInVector(a,VMHL_N,k);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");
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

        MHL_ShowNumber (k,"Искомое число", "k");
        //Искомое число:
        //k=3

        MHL_ShowNumber (Search,"находится в векторе a под номером", "Search");
        //находится в векторе a под номером:
        //Search=7
        delete [] a;
    }

    if (NameFunction=="TMHL_Max")
    {
        int a=MHL_RandomUniformInt(10,100);
        int b=MHL_RandomUniformInt(10,100);

        //Вызов функции
        int Max=TMHL_Max(a,b);

        //Используем полученный результат
        MHL_ShowNumber(Max,"Максимальное среди "+MHL_NumberToText(a)+" и "+MHL_NumberToText(b),"равно");
        //Максимальное среди 73 и 44:
        //равно=73
    }

    if (NameFunction=="TMHL_Min")
    {
        int a=MHL_RandomUniformInt(10,100);
        int b=MHL_RandomUniformInt(10,100);

        //Вызов функции
        int Max=TMHL_Min(a,b);

        //Используем полученный результат
        MHL_ShowNumber(Max,"Минимальное среди "+MHL_NumberToText(a)+" и "+MHL_NumberToText(b),"равно");
        //Минимальное среди 79 и 18:
        //равно=18
    }

    if (NameFunction=="TMHL_Abs")
    {
        double x;
        double absx;

        x=MHL_RandomUniform(-10,10);

        //Вызов функции
        absx=TMHL_Abs(x);

        //Используем полученный результат
        MHL_ShowNumber (x,"Число", "x");
        // Число:
        //x=-6.29578

        MHL_ShowNumber (absx,"Модуль", "absx");
        // Модуль:
        //absx=6.29578
    }

    if (NameFunction=="TMHL_NumberInterchange")
    {
        double a=MHL_RandomUniform(-10,10);
        double b=MHL_RandomUniform(-10,10);

        MHL_ShowNumber(a,"Было","a");
        //Было:
        //a=-3.18237
        MHL_ShowNumber(b,"Было","b");
        //Было:
        //b=5.36194

        //Вызов функции
        TMHL_NumberInterchange(&a,&b);

        //Используем полученный результат
        MHL_ShowNumber(a,"Стало","a");
        //Стало:
        //a=5.36194
        MHL_ShowNumber(b,"Стало","b");
        //Стало:
        //b=-3.18237
    }

    if (NameFunction=="TMHL_Sign")
    {
        int a=MHL_RandomUniformInt(-5,5);

        //Вызов функции
        int Result=TMHL_Sign(a);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Знак числа "+MHL_NumberToText(a),"равен");
        //Знак числа -3:
        //равен=-1
    }

    if (NameFunction=="TMHL_SignNull")
    {
        int a=MHL_RandomUniformInt(-5,5);

        //Вызов функции
        int Result=TMHL_SignNull(a);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Знак числа "+MHL_NumberToText(a),"равен");
        //Знак числа 0:
        //равен=1
    }

    if (NameFunction=="MHL_SumOfDigits")
    {
        int a=MHL_RandomUniformInt(100,30000);

        //Вызов функции
        int SumOfDigits=MHL_SumOfDigits(a);

        //Используем полученный результат
        MHL_ShowNumber (SumOfDigits,"Сумма цифр числа a="+MHL_NumberToText(a), "равна");
        //Сумма цифр числа a=2069:
        //равна=17
    }

    if (NameFunction=="TMHL_SumMatrix")
    {
        int i,j;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                a[i][j]=MHL_RandomUniformInt(10,100);

        //Вызов функции
        int SumMatrix=TMHL_SumMatrix(a,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
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

        MHL_ShowNumber (SumMatrix,"Её сумма", "SumVector");
        //Её сумма:
        //SumVector=1639

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_ZeroMatrix")
    {
        int i;
        int VMHL_N=MHL_RandomUniformInt(4,10);//Размер массива (число строк)
        int VMHL_M=MHL_RandomUniformInt(4,10);//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        //Вызов функции
        TMHL_ZeroMatrix(a,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Зануленая матрица", "a");
        //Зануленая матрица:
        //a =
        //0	0	0	0	0	0	0	0
        //0	0	0	0	0	0	0	0
        //0	0	0	0	0	0	0	0
        //0	0	0	0	0	0	0	0

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_MaximumOfMatrix")
    {
        int i,j;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **Matrix;
        Matrix=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new double[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                Matrix[i][j]=MHL_RandomUniformInt(10,100);

        //Вызов функции
        double Maximum=TMHL_MaximumOfMatrix(Matrix,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Случайная матрица", "Matrix");
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

        MHL_ShowNumber(Maximum,"Максимальный элемент","Maximum");
        //Максимальный элемент:
        //Maximum=96

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="TMHL_MinimumOfMatrix")
    {
        int i,j;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **Matrix;
        Matrix=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new double[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                Matrix[i][j]=MHL_RandomUniformInt(10,100);

        //Вызов функции
        double Minimum=TMHL_MinimumOfMatrix(Matrix,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Случайная матрица", "Matrix");
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

        MHL_ShowNumber(Minimum,"Минимальный элемент","Minimum");
        //Минимальный элемент:
        //Minimum=13

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="TMHL_FillMatrix")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        int x=MHL_RandomUniformInt(0,10);//заполнитель

        //Вызов функции
        TMHL_FillMatrix(a,VMHL_N,VMHL_M,x);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Заполненная матрица", "a");
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

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_MatrixMinusMatrix")
    {
        int i,j;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int **b;
        b=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) b[i]=new int[VMHL_M];
        int **c;
        c=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) c[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
            {
                a[i][j]=MHL_RandomUniformInt(10,20);
                b[i][j]=MHL_RandomUniformInt(10,20);
            }

        //Вызов функции
        TMHL_MatrixMinusMatrix(a,b,c,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Матрица", "a");
        //Матрица:
        //a =
        //18	19	17
        //14	12	11
        //10	16	19
        //12	18	16
        //12	16	11

        MHL_ShowMatrix (b,VMHL_N,VMHL_M,"Матрица", "b");
        //Матрица:
        //b =
        //11	19	18
        //12	10	13
        //11	14	10
        //11	17	15
        //12	16	10

        MHL_ShowMatrix (c,VMHL_N,VMHL_M,"Их разница", "c");
        //Их разница:
        //c =
        //7	0	-1
        //2	2	-2
        //-1	2	9
        //1	1	1
        //0	0	1

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_N;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VMHL_N;i++) delete [] c[i];
        delete [] c;

        //Для переопределенной функции
        VMHL_N=5;//Размер массива (число строк)
        VMHL_M=3;//Размер массива (число столбцов)
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        b=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) b[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
            {
                a[i][j]=MHL_RandomUniformInt(10,20);
                b[i][j]=MHL_RandomUniformInt(10,20);
            }

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Матрица", "a");
        //Матрица:
        //a =
        //11	18	11
        //19	14	15
        //14	13	14
        //19	13	12
        //19	15	10

        //Вызов функции
        TMHL_MatrixMinusMatrix(a,b,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (b,VMHL_N,VMHL_M,"Матрица", "b");
        //Матрица:
        //b =
        //12	13	18
        //14	12	14
        //12	14	19
        //18	16	16
        //16	17	19

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Теперь матрица a", "a");
        //Теперь матрица a:
        //a =
        //-1	5	-7
        //5	2	1
        //2	-1	-5
        //1	-3	-4
        //3	-2	-9

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_N;i++) delete [] b[i];
        delete [] b;
    }

    if (NameFunction=="TMHL_MatrixPlusMatrix")
    {
        int i,j;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int **b;
        b=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) b[i]=new int[VMHL_M];
        int **c;
        c=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) c[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
            {
                a[i][j]=MHL_RandomUniformInt(10,20);
                b[i][j]=MHL_RandomUniformInt(10,20);
            }

        //Вызов функции
        TMHL_MatrixPlusMatrix(a,b,c,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Матрица", "a");
        //Матрица:
        //a =
        //18	15	15
        //15	11	17
        //19	14	10
        //17	18	18
        //19	15	16

        MHL_ShowMatrix (b,VMHL_N,VMHL_M,"Матрица", "b");
        //Матрица:
        //b =
        //17	15	15
        //16	18	10
        //17	12	15
        //12	16	13
        //15	14	10

        MHL_ShowMatrix (c,VMHL_N,VMHL_M,"Их сумма", "c");
        //Их сумма:
        //c =
        //35	30	30
        //31	29	27
        //36	26	25
        //29	34	31
        //34	29	26

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_N;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VMHL_N;i++) delete [] c[i];
        delete [] c;

        //Для переопределенной функции
        VMHL_N=5;//Размер массива (число строк)
        VMHL_M=3;//Размер массива (число столбцов)
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        b=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) b[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
            {
                a[i][j]=MHL_RandomUniformInt(10,20);
                b[i][j]=MHL_RandomUniformInt(10,20);
            }

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Матрица", "a");
        //Матрица:
        //a =
        //18	12	12
        //19	17	12
        //19	17	17
        //11	10	17
        //11	19	10

        //Вызов функции
        TMHL_MatrixPlusMatrix(a,b,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (b,VMHL_N,VMHL_M,"Матрица", "b");
        //Матрица:
        //b =
        //10	10	16
        //10	18	18
        //15	13	17
        //13	11	14
        //16	13	11

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Теперь матрица a", "a");
        //Теперь матрица a:
        //a =
        //28	22	28
        //29	35	30
        //34	30	34
        //24	21	31
        //27	32	21

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_N;i++) delete [] b[i];
        delete [] b;
    }

    if (NameFunction=="TMHL_MatrixMultiplyNumber")
    {
        int i,j;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=5;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                Matrix[i][j]=MHL_RandomUniformInt(10,100);

        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Случайная матрица", "Matrix");
        //Случайная матрица:
        //Matrix =
        //77	34	14	83	30
        //31	15	87	68	20
        //52	11	49	92	95
        //77	29	96	50	90
        //10	47	40	49	20

        int Number=MHL_RandomUniformInt(-10,10);

        //Вызов функции
        TMHL_MatrixMultiplyNumber(Matrix,VMHL_N,VMHL_M,Number);

        //Используем полученный результат
        MHL_ShowNumber (Number,"Число, на которое умножается матрица","Number");
        //Число, на которое умножается матрица:
        //Number=4
        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Матрица умноженное на число", "Matrix");
        //Матрица умноженное на число:
        //Matrix =
        //308	136	56	332	120
        //124	60	348	272	80
        //208	44	196	368	380
        //308	116	384	200	360
        //40	188	160	196	80

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="TMHL_MatrixT")
    {
        int i,j;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new int[VMHL_M];
        int **MatrixT;
        MatrixT=new int*[VMHL_M];
        for (i=0;i<VMHL_M;i++) MatrixT[i]=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                Matrix[i][j]=MHL_RandomUniformInt(10,100);

        //Вызов функции
        TMHL_MatrixT(Matrix,MatrixT,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Матрица", "Matrix");
        //Матрица:
        //Matrix =
        //26	64	62
        //70	49	43
        //50	41	50
        //76	75	81
        //26	72	24

        MHL_ShowMatrix (MatrixT,VMHL_M,VMHL_N,"Транспонированная матрица", "MatrixT");
        // Транспонированная матрица:
        //MatrixT =
        //26	70	50	76	26
        //64	49	41	75	72
        //62	43	50	81	24

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
        for (i=0;i<VMHL_M;i++) delete [] MatrixT[i];
        delete [] MatrixT;
    }

    if (NameFunction=="TMHL_MatrixMultiplyMatrix")
    {
        int i;
        int VMHL_N=3;
        int VMHL_M=5;
        int VMHL_S=4;
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int **b;
        b=new int*[VMHL_M];
        for (i=0;i<VMHL_M;i++) b[i]=new int[VMHL_S];
        int **c;
        c=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) c[i]=new int[VMHL_S];
        TMHL_RandomIntMatrix(a,0,10,VMHL_N,VMHL_M);
        TMHL_RandomIntMatrix(b,0,10,VMHL_M,VMHL_S);

        //Вызов функции
        TMHL_MatrixMultiplyMatrix (a, b, c, VMHL_N, VMHL_M, VMHL_S);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //3	0	4	4	5
        //9	4	3	4	4
        //8	0	1	9	8

        MHL_ShowMatrix (b,VMHL_M,VMHL_S,"Случайная матрица", "b");
        // Случайная матрица:
        //b =
        //6	6	6	3
        //4	2	1	2
        //6	9	6	3
        //1	1	8	2
        //6	8	0	9

        MHL_ShowMatrix (c,VMHL_N,VMHL_S,"Произведение", "c");
        // Произведение:
        //c =
        //76	98	74	74
        //116	125	108	88
        //111	130	126	117

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_M;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VMHL_N;i++) delete [] c[i];
        delete [] c;
    }

    if (NameFunction=="TMHL_MatrixMultiplyMatrixT")
    {
        int i;
        int VMHL_N=3;
        int VMHL_M=5;
        int VMHL_S=4;
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int **b;
        b=new int*[VMHL_S];
        for (i=0;i<VMHL_S;i++) b[i]=new int[VMHL_M];
        int **c;
        c=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) c[i]=new int[VMHL_S];
        TMHL_RandomIntMatrix(a,0,10,VMHL_N,VMHL_M);
        TMHL_RandomIntMatrix(b,0,10,VMHL_S,VMHL_M);

        //Вызов функции
        TMHL_MatrixMultiplyMatrixT (a, b, c, VMHL_N, VMHL_M, VMHL_S);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //9	8	5	2	1
        //1	9	3	4	8
        //9	9	3	0	3

        MHL_ShowMatrix (b,VMHL_S,VMHL_M,"Случайная матрица", "b");
        // Случайная матрица:
        //b =
        //3	7	3	0	8
        //9	8	0	6	9
        //0	2	5	6	5
        //8	7	9	2	3

        MHL_ShowMatrix (c,VMHL_N,VMHL_S,"Произведение", "c");
        // Произведение:
        //c =
        //106	166	58	180
        //139	177	97	130
        //123	180	48	171

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_S;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VMHL_N;i++) delete [] c[i];
        delete [] c;
    }

    if (NameFunction=="TMHL_MatrixTMultiplyMatrix")
    {
        int i;
        int VMHL_N=3;
        int VMHL_M=5;
        int VMHL_S=4;
        int **a;
        a=new int*[VMHL_M];
        for (i=0;i<VMHL_M;i++) a[i]=new int[VMHL_N];
        int **b;
        b=new int*[VMHL_M];
        for (i=0;i<VMHL_M;i++) b[i]=new int[VMHL_S];
        int **c;
        c=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) c[i]=new int[VMHL_S];
        TMHL_RandomIntMatrix(a,0,10,VMHL_M,VMHL_N);
        TMHL_RandomIntMatrix(b,0,10,VMHL_M,VMHL_S);

        //Вызов функции
        TMHL_MatrixTMultiplyMatrix (a, b, c, VMHL_N, VMHL_M, VMHL_S);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_M,VMHL_N,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //6	0	1
        //6	5	9
        //7	2	0
        //3	1	5
        //3	8	8

        MHL_ShowMatrix (b,VMHL_M,VMHL_S,"Случайная матрица", "b");
        // Случайная матрица:
        //b =
        //6	7	1	0
        //7	6	0	0
        //5	6	0	0
        //9	7	9	3
        //5	7	0	1

        MHL_ShowMatrix (c,VMHL_N,VMHL_S,"Произведение", "c");
        // Произведение:
        //c =
        //155	162	33	12
        //94	105	9	11
        //154	152	46	23

        for (i=0;i<VMHL_M;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_M;i++) delete [] b[i];
        delete [] b;
        for (i=0;i<VMHL_N;i++) delete [] c[i];
        delete [] c;
    }

    if (NameFunction=="TMHL_RandomIntMatrix")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        int n=-3;//левая граница интервала;
        int m=3;//правая граница интервала;

        //Вызов функции
        TMHL_RandomIntMatrix(a,n,m,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //-1	-1	2
        //2	0	1
        //-3	2	-1ss

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_RandomIntMatrixInCols")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int *n;
        n=new int[VMHL_M];
        int *m;
        m=new int[VMHL_M];

        n[0]=-50;//левая границы интервала изменения 1 столбца
        m[0]=-40; //правая граница интервала изменения 1 столбца

        n[1]=0;//левая границы интервала изменения 2 столбца
        m[1]=3; //правая граница интервала изменения 2 столбца

        n[2]=100;//левая границы интервала изменения 3 столбца
        m[2]=200; //правая граница интервала изменения 3 столбца

        //Вызов функции
        TMHL_RandomIntMatrixInCols(a,n,m,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //-47	2	142
        //-47	1	139
        //-44	0	199

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] n;
        delete [] m;
    }

    if (NameFunction=="TMHL_RandomIntMatrixInElements")
    {
        int i,j;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int **n;
        n=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) n[i]=new int[VMHL_M];
        int **m;
        m=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) m[i]=new int[VMHL_M];

        //Заполним границы изменения каждого элемента
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
            {
                n[i][j]=i*VMHL_N+j-10;
                m[i][j]=n[i][j]+20;
            }

        //Вызов функции
        TMHL_RandomIntMatrixInElements(a,n,m,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (n,VMHL_N,VMHL_M,"Матрица левых границ", "n");
        //Матрица левых границ:
        //n =
        //-10	-9	-8
        //-7	-6	-5
        //-4	-3	-2

        MHL_ShowMatrix (m,VMHL_N,VMHL_M,"Матрица правых границ", "m");
        // Матрица правых границ:
        //m =
        //10	11	12
        //13	14	15
        //16	17	18

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //-4	6	-8
        //-1	1	1
        //-3	16	4

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_N;i++) delete [] n[i];
        delete [] n;
        for (i=0;i<VMHL_N;i++) delete [] m[i];
        delete [] m;
    }

    if (NameFunction=="TMHL_RandomIntMatrixInRows")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int *n;
        n=new int[VMHL_N];
        int *m;
        m=new int[VMHL_N];

        n[0]=-50;//левая границы интервала изменения 1 строки
        m[0]=-40; //правая граница интервала изменения 1 строки

        n[1]=0;//левая границы интервала изменения 2 строки
        m[1]=3; //правая граница интервала изменения 2 строки

        n[2]=100;//левая границы интервала изменения 3 строки
        m[2]=200; //правая граница интервала изменения 3 строки

        //Вызов функции
        TMHL_RandomIntMatrixInRows(a,n,m,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        // -42	-42	-45
        //2	2	0
        //113	102	109

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] n;
        delete [] m;
    }

    if (NameFunction=="TMHL_RandomIntVector")
    {
        int VMHL_N=10;//Размер массива
        int *a;
        a=new int[VMHL_N];

        int n=3;
        int m=50;

        //Вызов функции
        TMHL_RandomIntVector(a,n,m,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (a,VMHL_N,"Массив", "a");
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

    if (NameFunction=="TMHL_RandomIntVectorInElements")
    {
        int VMHL_N=2;//Размер массива
        int *a;
        a=new int[VMHL_N];

        int *n;
        n=new int[VMHL_N];
        n[0]=3;//Левая граница изменения первого элемента массива
        n[1]=-90;//Левая граница изменения второго элемента массива

        int *m;
        m=new int[VMHL_N];
        m[0]=40;//Правая граница изменения первого элемента массива
        m[1]=-10;//Правая граница изменения второго элемента массива

        //Вызов функции
        TMHL_RandomIntVectorInElements(a,n,m,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (n,VMHL_N,"Массив левых границ", "n");
        //Массив левых границ:
        //n =
        //3
        //-90

        MHL_ShowVector (m,VMHL_N,"Массив правых границ", "m");
        // Массив правых границ:
        //m =
        //40
        //-10

        MHL_ShowVector (a,VMHL_N,"Случайных массив", "a");
        // Случайных массив:
        //a =
        //31
        //-52

        delete [] a;
        delete [] n;
        delete [] m;
    }

    if (NameFunction=="TMHL_RandomBinaryMatrix")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        //Вызов функции
        TMHL_RandomBinaryMatrix(a,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная бинарная матрица", "a");
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

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_RandomBinaryVector")
    {
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];

        //Вызов функции
        TMHL_RandomBinaryVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный бинарный вектор", "a");
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

    if (NameFunction=="TMHL_BernulliVector")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];

        //Вызов функции
        TMHL_BernulliVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор Бернулли", "a");
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

    if (NameFunction=="TMHL_RandomArrangingObjectsIntoBaskets")
    {
        int VMHL_N=10;//Размер массива
        int *a;
        a=new int[VMHL_N];

        int N=MHL_RandomUniformInt(0,10);// Размер турнира

        //Вызов функции
        TMHL_RandomArrangingObjectsIntoBaskets(a,N,VMHL_N);

        //Используем полученный результат
        MHL_ShowNumber (N,"Число предметов", "N");
        // Число предметов:
        // N=5
        MHL_ShowVectorT (a,VMHL_N,"Случаное расположение по 10 корзинам", "a");
        // Случаное расположение по 10 корзинам:
        //a =
        //0	1	0	0	0	1	1	0	1	1

        delete [] a;
    }

    if (NameFunction=="TMHL_ColInterchange")
    {
        int i,j;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=5;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                Matrix[i][j]=MHL_RandomUniformInt(10,100);

        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Случайная матрица", "Matrix");
        // Случайная матрица:
        //Matrix =
        //46	37	90	95	83
        //92	58	48	61	16
        //31	92	37	64	56
        //20	54	84	90	75
        //86	79	20	40	69

        // номера перставляемых столбцов
        int k=MHL_RandomUniformInt(0,5);
        int l=MHL_RandomUniformInt(0,5);

        //Вызов функции
        TMHL_ColInterchange(Matrix,VMHL_N,k,l);

        //Используем полученный результат
        MHL_ShowNumber (k,"Номер первого столбца","k");
        // Номер первого столбца:
        //k=4
        MHL_ShowNumber (l,"Номер второго столбца","l");
        // Номер второго столбца:
        //l=0
        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Матрица с персетавленными столбцами", "Matrix");
        // Матрица с персетавленными столбцами:
        //Matrix =
        //83	37	90	95	46
        //16	58	48	61	92
        //56	92	37	64	31
        //75	54	84	90	20
        //69	79	20	40	86

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="TMHL_ColToMatrix")
    {
        int i,j;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int *b;
        b=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                a[i][j]=MHL_RandomUniformInt(10,100);
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
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

        for (j=0;j<VMHL_N;j++)
            b[j]=MHL_RandomUniformInt(10,100);

        int k=1;//Номер столбца, в который мы копируем

        //Вызов функции
        TMHL_ColToMatrix(a,b,VMHL_N,k);

        //Используем полученный результат
        MHL_ShowNumber(k,"Номер столбца, в который мы копируем ","k");
        //Номер столбца, в который мы копируем :
        //k=1
        MHL_ShowVector (b,VMHL_N,"Вектор","b");
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

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Матрица с изменившимся столбцом", "a");
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

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_DeleteRowInMatrix")
    {
        int i,j;
        int VMHL_N=6;//Размер массива (число строк)
        int VMHL_M=4;//Размер массива (число столбцов)
        double **Matrix;
        Matrix=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new double[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                Matrix[i][j]=MHL_RandomUniformInt(10,100);

        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Случайная матрица", "Matrix");
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
        TMHL_DeleteRowInMatrix(Matrix,k,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Матрица с удаленной строкой", "Matrix");
        // Матрица с удаленной строкой:
        //Matrix =
        //70	57	44	95
        //26	21	60	63
        //10	10	43	92
        //66	20	51	65
        //32	52	63	78
        //0	0	0	0

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="TMHL_DeleteColInMatrix")
    {
        int i,j;
        int VMHL_N=6;//Размер массива (число строк)
        int VMHL_M=4;//Размер массива (число столбцов)
        double **Matrix;
        Matrix=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new double[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                Matrix[i][j]=MHL_RandomUniformInt(10,100);

        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Случайная матрица", "Matrix");
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
        TMHL_DeleteColInMatrix(Matrix,k,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Матрица с удаленным столбцом", "Matrix");
        // Матрица с удаленным столбцом:
        //Matrix =
        //39	52	31	0
        //49	49	65	0
        //68	15	86	0
        //91	73	32	0
        //52	31	78	0
        //22	20	94	0

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="TMHL_MatrixToCol")
    {
        int i,j;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int *b;
        b=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                a[i][j]=MHL_RandomUniformInt(10,100);

        int k=1;//Номер копируемого столбца

        //Вызов функции
        TMHL_MatrixToCol(a,b,VMHL_N,k);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
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

        MHL_ShowNumber(k,"Номер копируемого столбца ","k");
        //Номер копируемого столбца :
        //k=1
        MHL_ShowVector (b,VMHL_N,"Вектор, в который скопировали столбец","b");
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

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_MatrixToMatrix")
    {
        int i,j;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];
        double **b;
        b=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) b[i]=new double[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                a[i][j]=MHL_RandomUniformInt(10,100);

        //Вызов функции
        TMHL_MatrixToMatrix(a,b,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
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

        MHL_ShowMatrix (b,VMHL_N,VMHL_M,"Теперь b равна a", "b");
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

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_N;i++) delete [] b[i];
        delete [] b;
    }

    if (NameFunction=="TMHL_MatrixToRow")
    {
        int i,j;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int *b;
        b=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                a[i][j]=MHL_RandomUniformInt(10,100);

        int k=1;//Номер копируемой строки

        //Вызов функции
        TMHL_MatrixToRow(a,b,k,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
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

        MHL_ShowNumber(k,"Номер копируемой строки ","k");
        //Номер копируемой строки :
        //k=1
        MHL_ShowVector (b,VMHL_M,"Вектор, в который скопировали строку","b");
        //Вектор, в который скопировали строку:
        //b =
        //69
        //75
        //13

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_RowInterchange")
    {
        int i,j;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=5;//Размер массива (число столбцов)
        int **Matrix;
        Matrix=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                Matrix[i][j]=MHL_RandomUniformInt(10,100);

        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Случайная матрица", "Matrix");
        //Случайная матрица:
        //Matrix =
        //64	41	93	98	45
        //19	55	31	38	44
        //38	78	39	44	86
        //28	54	39	14	72
        //31	99	64	49	63

        // номера перставляемых строк
        int k=MHL_RandomUniformInt(0,5);
        int l=MHL_RandomUniformInt(0,5);

        //Вызов функции
        TMHL_RowInterchange(Matrix,VMHL_M,k,l);

        //Используем полученный результат
        MHL_ShowNumber (k,"Номер первой строки","k");
        //Номер первой строки:
        //k=4
        MHL_ShowNumber (l,"Номер второй строки","l");
        //Номер второй строки:
        //l=3
        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_M,"Матрица с персетавленными строками", "Matrix");
        //Матрица с персетавленными строками:
        //Matrix =
        //64	41	93	98	45
        //19	55	31	38	44
        //38	78	39	44	86
        //31	99	64	49	63
        //28	54	39	14	72

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="TMHL_RowToMatrix")
    {
        int i,j;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        int *b;
        b=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                a[i][j]=MHL_RandomUniformInt(10,100);
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
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

        for (j=0;j<VMHL_M;j++)
            b[j]=MHL_RandomUniformInt(10,100);

        int k=1;//Номер строки, в которую мы копируем

        //Вызов функции
        TMHL_RowToMatrix(a,b,k,VMHL_M);

        //Используем полученный результат
        MHL_ShowNumber(k,"Номер строки, в которую мы копируем ","k");
        //Номер строки, в которую мы копируем :
        //k=1
        MHL_ShowVector (b,VMHL_M,"Вектор","b");
        //Вектор:
        //b =
        //92
        //89
        //11

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Матрица с изменившейся строкой", "a");
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

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_NumberOfDifferentValuesInMatrix")
    {
        int i,j;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                a[i][j]=MHL_RandomUniformInt(0,50);

        //Вызов функции
        int NumberOfDifferent=TMHL_NumberOfDifferentValuesInMatrix(a,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //7	3	27
        //31	30	10
        //37	34	49
        //45	26	12
        //26	28	0

        MHL_ShowNumber (NumberOfDifferent,"Число различных значений в матрице", "NumberOfDifferent");
        //Число различных значений в матрице:
        //NumberOfDifferent=14
        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_IdentityMatrix")
    {
        int i;
        int VMHL_N=5;//Размер массива (число строк и столбцов)
        int **Matrix;
        Matrix=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Matrix[i]=new int[VMHL_N];

        //Вызов функции
        TMHL_IdentityMatrix(Matrix,VMHL_N);

        //Используем полученный результат
        MHL_ShowMatrix (Matrix,VMHL_N,VMHL_N,"Единичная матрица", "Matrix");
        //Единичная матрица:
        //Matrix =
        //1	0	0	0	0
        //0	1	0	0	0
        //0	0	1	0	0
        //0	0	0	1	0
        //0	0	0	0	1

        for (i=0;i<VMHL_N;i++) delete [] Matrix[i];
        delete [] Matrix;
    }

    if (NameFunction=="TMHL_MixingVector")
    {
        int VMHL_N=10;//Размер массива
        int *x;
        x=new int[VMHL_N];
        //Заполним массив номерами от 1
        TMHL_OrdinalVector(x,VMHL_N);
        MHL_ShowVector (x,VMHL_N,"Вектор", "x");
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
        TMHL_MixingVector(x,P,VMHL_N);//Перемешаем массив

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Перемешанный вектор", "x");
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

    if (NameFunction=="TMHL_ReverseVector")
    {
        int i;
        int VMHL_N=MHL_RandomUniformInt(2,10);//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(10,100);

        MHL_ShowVector (a,VMHL_N,"Вектор равен", "a");
        //Вектор равен:
        //a =
        //83
        //57
        //55
        //52
        //70
        //73

        //Вызов функции
        TMHL_ReverseVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Теперь вектор равен", "a");
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

    if (NameFunction=="TMHL_NumberOfDifferentValuesInVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,5);

        //Вызов функции
        int NumberOfDifferent=TMHL_NumberOfDifferentValuesInVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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

        MHL_ShowNumber (NumberOfDifferent,"Число различных значений в векторе", "NumberOfDifferent");
        //Число различных значений в векторе:
        //NumberOfDifferent=4
        delete [] a;
    }

    if (NameFunction=="TMHL_PowerOf")
    {
        double a=MHL_RandomUniform(-5,5);
        int Degree=MHL_RandomUniformInt(0,20);

        double Result=TMHL_PowerOf(a,Degree);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Число "+MHL_NumberToText(a)+" в степени "+MHL_NumberToText(Degree),"равно");
        //Число 3.9624 в степени 4:
        //равно=246.51
    }

    if (NameFunction=="MHL_Parity")
    {
        int a=MHL_RandomUniformInt(-50,50);

        double Result=MHL_Parity(a);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Четность числа "+MHL_NumberToText(a),"равна");
        //Четность числа 2:
        //равна=1
    }

    if (NameFunction=="MHL_ArithmeticalProgression")
    {
        double a1=MHL_RandomUniformInt(1,10);
        double d=MHL_RandomUniformInt(1,10);
        int n=MHL_RandomUniformInt(1,10);

        double an=MHL_ArithmeticalProgression(a1,d,n);

        //Используем полученный результат
        MHL_ShowNumber(a1,"Первый член последовательности","a1");
        //Первый член последовательности:
        //a1=6
        MHL_ShowNumber(d,"Шаг арифметической прогрессии","d");
        //Шаг арифметической прогрессии:
        //d=9
        MHL_ShowNumber(n,"Номер последнего члена","n");
        //Номер последнего члена:
        //n=4
        MHL_ShowNumber(an,"n-ый член последовательности","an");
        //n-ый член последовательности:
        //an=33
    }

    if (NameFunction=="MHL_GeometricSeries")
    {
        double u1=MHL_RandomUniformInt(1,10);
        double q=MHL_RandomUniformInt(1,10);
        int n=MHL_RandomUniformInt(1,10);

        double qn=MHL_GeometricSeries(u1,q,n);

        //Используем полученный результат
        MHL_ShowNumber(u1,"Первый член последовательности","u1");
        //Первый член последовательности:
        //u1=4
        MHL_ShowNumber(q,"Шаг арифметической прогрессии","q");
        //Шаг арифметической прогрессии:
        //q=4
        MHL_ShowNumber(n,"Номер последнего члена","n");
        //Номер последнего члена:
        //n=6
        MHL_ShowNumber(qn,"n-ый член последовательности","qn");
        //n-ый член последовательности:
        //qn=4096
    }

    if (NameFunction=="MHL_GreatestCommonDivisorEuclid")
    {
        int A=MHL_RandomUniformInt(1,100);
        int B=MHL_RandomUniformInt(1,100);

        double Result=MHL_GreatestCommonDivisorEuclid(A,B);

        //Используем полученный результат
        MHL_ShowNumber(A,"Число","A");
        //Число:
        //A=96
        MHL_ShowNumber(B,"Число","B");
        //Число:
        //B=18
        MHL_ShowNumber(Result,"НОД","");
        //НОД:
        //=6
    }

    if (NameFunction=="MHL_LeastCommonMultipleEuclid")
    {
        int A=MHL_RandomUniformInt(1,100);
        int B=MHL_RandomUniformInt(1,100);

        double Result=MHL_LeastCommonMultipleEuclid(A,B);

        //Используем полученный результат
        MHL_ShowNumber(A,"Число","A");
        //Число:
        //A=68
        MHL_ShowNumber(B,"Число","B");
        //Число:
        //B=67
        MHL_ShowNumber(Result,"НОК","");
        //НОК:
        //=4556
    }

    if (NameFunction=="MHL_HowManyPowersOfTwo")
    {
        int x=MHL_RandomUniformInt(0,1000);
        int Degree;

        //Вызываем функцию
        Degree=MHL_HowManyPowersOfTwo(x);

        //Используем полученный результат
        MHL_ShowNumber(x,"Число","x");
        //Число:
        //x=480
        MHL_ShowNumber(Degree,"Его покрывает 2 в степени","Degree");
        //Его покрывает 2 в степени:
        //Degree=9
        MHL_ShowNumber(TMHL_PowerOf(2,Degree),"То есть","2^"+MHL_NumberToText(Degree));
        //То есть:
        //2^9=512
    }

    if (NameFunction=="MHL_SumGeometricSeries")
    {
        double u1=MHL_RandomUniformInt(1,5);
        double q=MHL_RandomUniformInt(1,5);
        int n=MHL_RandomUniformInt(1,5);

        double Sum=MHL_SumGeometricSeries(u1,q,n);

        //Используем полученный результат
        MHL_ShowNumber(u1,"Первый член последовательности","u1");
        //Первый член последовательности:
        //u1=4
        MHL_ShowNumber(q,"Шаг арифметической прогрессии","q");
        //Шаг арифметической прогрессии:
        //q=4
        MHL_ShowNumber(n,"Номер последнего члена","n");
        //Номер последнего члена:
        //n=3
        MHL_ShowNumber(Sum,"Сумма первых n членов","Sum");
        //Сумма первых n членов:
        //Sum=84
    }

    if (NameFunction=="MHL_SumOfArithmeticalProgression")
    {
        double a1=MHL_RandomUniformInt(1,10);
        double d=MHL_RandomUniformInt(1,10);
        int n=MHL_RandomUniformInt(1,10);

        double Sum=MHL_SumOfArithmeticalProgression(a1,d,n);

        //Используем полученный результат
        MHL_ShowNumber(a1,"Первый член последовательности","a1");
        //Первый член последовательности:
        //a1=9
        MHL_ShowNumber(d,"Шаг арифметической прогрессии","d");
        //Шаг арифметической прогрессии:
        //d=6
        MHL_ShowNumber(n,"Номер последнего члена","n");
        //Номер последнего члена:
        //n=9
        MHL_ShowNumber(Sum,"Сумма первых n членов","Sum");
        //Сумма первых n членов:
        //Sum=297
    }

    if (NameFunction=="TMHL_FibonacciNumber")
    {
        int n;
        int F;
        n=MHL_RandomUniformInt(3,20);

        //Вызов функции
        F=TMHL_FibonacciNumber(n);

        //Используем полученный результат

        MHL_ShowNumber (n,"Номер числа", "n");
        // Номер числа:
        // n=14
        MHL_ShowNumber (F,"Число Фибоначчи, заданного номера", "F");
        // Число Фибоначчи, заданного номера:
        // F=377
    }

    if (NameFunction=="TMHL_BoolCrossingTwoSegment")
    {
        double b1,c1,b2,c2;
        int Result;
        //Зададим случайные координаты отрезков
        b1=MHL_RandomUniform(-3,5);
        c1=MHL_RandomUniform(-3,5);
        b2=MHL_RandomUniform(-3,5);
        c2=MHL_RandomUniform(-3,5);

        //Вызов функции
        Result=TMHL_BoolCrossingTwoSegment(b1,c1,b2,c2);

        //Используем полученный результат
        MHL_ShowNumber (b1,"Левый конец первого отрезка", "b1");
        //Левый конец первого отрезка:
        //b1=0.773193
        MHL_ShowNumber (c1,"Правый конец первого отрезка", "c1");
        //Правый конец первого отрезка:
        //c1=3.22803
        MHL_ShowNumber (b2,"Левый конец второго отрезка", "b2");
        //Левый конец второго отрезка:
        //b2=4.99121
        MHL_ShowNumber (c2,"Правый конец второго отрезка", "c2");
        //Правый конец второго отрезка:
        //c2=1.43921
        MHL_ShowNumber (Result,"Пересекаются ли отрезки", "Result");
        //Пересекаются ли отрезки:
        //Result=1
    }

    if (NameFunction=="TMHL_AcceptanceLimits")
    {
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];
        double *Left;
        Left=new double[VMHL_N];
        double *Right;
        Right=new double[VMHL_N];
        TMHL_FillVector(Left,VMHL_N,-1.);//Левая граница
        TMHL_FillVector(Right,VMHL_N,1.);//Правая граница

        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomUniform(-1.1,1.1);
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");
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
        TMHL_AcceptanceLimits(a,Left,Right,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (Left,VMHL_N,"Левые границы", "Left");
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

        MHL_ShowVector (Right,VMHL_N,"Правые границы", "Right");
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

        MHL_ShowVector (a,VMHL_N,"Отредактированный вектор", "a");
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

    if (NameFunction=="MHL_NoiseInVector")
    {
        int VMHL_N=10;//Размер массива
        double *x;
        x=new double[VMHL_N];
        //Заполним массив номерами от 1
        TMHL_OrdinalVector(x,VMHL_N);
        MHL_ShowVector (x,VMHL_N,"Вектор", "x");
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

        double percent=double(MHL_RandomUniformInt(0,100));//Процент помехи

        //Вызов функции
        MHL_NoiseInVector(x,percent,VMHL_N);

        //Используем полученный результат

        MHL_ShowNumber (percent,"Процент помехи", "percent");
        //Процент помехи:
        //percent=89
        MHL_ShowVector (x,VMHL_N,"Вектор с помехой", "x");
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

    if (NameFunction=="MHL_EuclidNorma")
    {
        int VMHL_N=5;//Размер массива
        double *x;
        x=new double[VMHL_N];
        //Заполним случайными числами
        MHL_RandomRealVector (x,0,10,VMHL_N);

        //Вызов функции
        double a=MHL_EuclidNorma(x,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Вектор", "x");
        // Вектор:
        //x =
        //2.22504
        //5.2655
        //5.00092
        //5.7428
        //9.11682

        MHL_ShowNumber (a,"Значение евклидовой нормы вектора", "a");
        // Значение евклидовой нормы вектора:
        // a=13.1826

        delete [] x;
    }

    if (NameFunction=="TMHL_MixingVectorWithConjugateVector")
    {
        int VMHL_N=10;//Размер массива
        int *x;
        x=new int[VMHL_N];
        int *y;
        y=new int[VMHL_N];
        //Заполним массив номерами от 1
        TMHL_OrdinalVector(x,VMHL_N);
        //А сопряженный заполним номерами с нуля
        TMHL_OrdinalVectorZero(y,VMHL_N);
        MHL_ShowVectorT (x,VMHL_N,"Вектор", "x");
        //Вектор:
        //x =
        //1	2	3	4	5	6	7	8	9	10

        MHL_ShowVectorT (y,VMHL_N,"Вектор", "y");
        //Вектор:
        //y =
        //0	1	2	3	4	5	6	7	8	9

        double P=0.4;//Вероятность перемешивания

        //Вызов функции
        TMHL_MixingVectorWithConjugateVector(x,y,P,VMHL_N);//Перемешаем массив

        //Используем полученный результат
        MHL_ShowVectorT (x,VMHL_N,"Перемешанный вектор", "x");
        // Перемешанный вектор:
        //x =
        //9	1	4	8	10	5	7	3	6	2

        MHL_ShowVectorT (y,VMHL_N,"Сопряженный перемешанный вектор", "y");
        //Сопряженный перемешанный вектор:
        //y =
        //8	0	3	7	9	4	6	2	5	1

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="TMHL_MixingRowsInOrder")
    {
        int i;
        int VMHL_N=7;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)

        int *b;
        b=new int[VMHL_N];

        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        //Заполним случайными числами
        TMHL_RandomIntMatrix(a,10,100,VMHL_N,VMHL_M);
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
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
        TMHL_OrdinalVectorZero(b,VMHL_N);
        //Перемешаем
        TMHL_MixingVector(b,0.5,VMHL_N);

        //Вызов функции
        TMHL_MixingRowsInOrder(a,b,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowVector (b,VMHL_N,"Номера нового порядка", "b");
        //Номера нового порядка:
        //b =
        //5
        //0
        //1
        //4
        //6
        //2
        //3

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица с новым порядком строк", "a");
        //Случайная матрица с новым порядком строк:
        //a =
        //92	73	27
        //10	72	80
        //15	75	94
        //56	96	39
        //87	62	12
        //49	65	82
        //82	11	75

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_Chebychev")
    {
        int VMHL_N=5;//Размер массива
        double *x;
        x=new double[VMHL_N];
        double *y;
        y=new double[VMHL_N];
        //Заполним случайными числами
        MHL_RandomRealVector (x,0,10,VMHL_N);
        MHL_RandomRealVector (y,0,10,VMHL_N);

        //Вызов функции
        double metric=TMHL_Chebychev(x,y,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Первый массив", "x");
        //Первый массив:
        //x =
        //7.9245
        //7.28699
        //6.24054
        //1.12152
        //7.65442

        MHL_ShowVector (y,VMHL_N,"Второй массив", "y");
        //Второй массив:
        //y =
        //0.324097
        //3.12164
        //4.47266
        //9.70062
        //5.64117

        MHL_ShowNumber (metric,"Значение метрики расстояние Чебышева", "metric");
        //Значение метрики расстояние Чебышева:
        //metric=8.5791

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="TMHL_CityBlock")
    {
        int i;
        int VMHL_N=5;//Размер массива
        int *x;
        x=new int[VMHL_N];
        int *y;
        y=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
        {
            x[i]=MHL_RandomUniformInt(0,5);
            y[i]=MHL_RandomUniformInt(0,5);
        }

        //Вызов функции
        int metric=TMHL_CityBlock(x,y,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Первый массив", "x");
        //Первый массив:
        //x =
        //4
        //1
        //3
        //3
        //0

        MHL_ShowVector (y,VMHL_N,"Второй массив", "y");
        //Второй массив:
        //y =
        //3
        //4
        //1
        //4
        //1

        MHL_ShowNumber (metric,"Значение метрики манхэттенское расстояние", "metric");
        // Значение метрики манхэттенское расстояние:
        //metric=8

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="TMHL_Euclid")
    {
        int VMHL_N=5;//Размер массива
        double *x;
        x=new double[VMHL_N];
        double *y;
        y=new double[VMHL_N];
        //Заполним случайными числами
        MHL_RandomRealVector (x,0,10,VMHL_N);
        MHL_RandomRealVector (y,0,10,VMHL_N);

        //Вызов функции
        double metric=TMHL_Euclid(x,y,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Первый массив", "x");
        //Первый массив:
        //x =
        //3.15491
        //4.04266
        //2.63519
        //9.94141
        //3.2193

        MHL_ShowVector (y,VMHL_N,"Второй массив", "y");
        //Второй массив:
        //y =
        //9.4516
        //2.59064
        //2.56348
        //4.78271
        //5.78705

        MHL_ShowNumber (metric,"Значение метрики евклидово расстояние", "metric");
        //Значение метрики евклидово расстояние:
        //metric=8.65837

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="MHL_CenterDerivative")
    {
        double x;
        double h;
        double dfdx;
        //Зададим случайные координаты отрезков
        x=MHL_RandomUniform(-3,5);
        h=0.01;//малое приращение x

        //Вызов функции
        dfdx=MHL_CenterDerivative(x,h,Func3);

        //Используем полученный результат
        MHL_ShowNumber (x,"Точка, в которой считается производная", "x");
        //Точка, в которой считается производная:
        //x=0.843262
        MHL_ShowNumber (h,"Малое приращение x", "h");
        // Малое приращение x:
        //h=0.01
        MHL_ShowNumber (dfdx,"Значение производной в точке", "dfdx");
        // Значение производной в точке:
        //dfdx=1.68652
    }

    if (NameFunction=="MHL_LeftDerivative")
    {
        double x;
        double h;
        double dfdx;
        //Зададим случайные координаты отрезков
        x=MHL_RandomUniform(-3,5);
        h=0.01;//малое приращение x

        //Вызов функции
        dfdx=MHL_LeftDerivative(x,h,Func3);

        //Используем полученный результат
        MHL_ShowNumber (x,"Точка, в которой считается производная", "x");
        // Точка, в которой считается производная:
        //x=1.87964
        MHL_ShowNumber (h,"Малое приращение x", "h");
        // Малое приращение x:
        //h=0.01
        MHL_ShowNumber (dfdx,"Значение производной в точке", "dfdx");
        // Значение производной в точке:
        //dfdx=3.74928
    }

    if (NameFunction=="MHL_RightDerivative")
    {
        double x;
        double h;
        double dfdx;
        //Зададим случайные координаты отрезков
        x=MHL_RandomUniform(-3,5);
        h=0.01;//малое приращение x

        //Вызов функции
        dfdx=MHL_RightDerivative(x,h,Func3);

        //Используем полученный результат
        MHL_ShowNumber (x,"Точка, в которой считается производная", "x");
        // Точка, в которой считается производная:
        //x=-1.69409
        MHL_ShowNumber (h,"Малое приращение x", "h");
        // Малое приращение x:
        //h=0.01
        MHL_ShowNumber (dfdx,"Значение производной в точке", "dfdx");
        // Значение производной в точке:
        //dfdx=-3.37818
    }

    if (NameFunction=="MHL_IntegralOfTrapezium")
    {
        double a=-2;
        double b=2;
        double Epsilon=0.01;
        double S;

        //Вызов функции
        S=MHL_IntegralOfTrapezium(a,b,Epsilon,Func3);

        //Используем полученный результат
        MHL_ShowNumber (a,"Левая граница интегрирования", "a");
        //Левая граница интегрирования:
        //a=-2
        MHL_ShowNumber (b,"Правая граница интегрирования", "b");
        //Правая граница интегрирования:
        //b=2
        MHL_ShowNumber (S,"Интеграл", "S");
        //Интеграл:
        //S=5.33594
    }

    if (NameFunction=="MHL_IntegralOfSimpson")
    {
        double a=-2;
        double b=2;
        double Epsilon=0.01;
        double S;

        //Вызов функции
        S=MHL_IntegralOfSimpson(a,b,Epsilon,Func3);

        //Используем полученный результат
        MHL_ShowNumber (a,"Левая граница интегрирования", "a");
        // Левая граница интегрирования:
        //a=-2
        MHL_ShowNumber (b,"Правая граница интегрирования", "b");
        // Правая граница интегрирования:
        //b=2
        MHL_ShowNumber (S,"Интеграл", "S");
        // Интеграл:
        //S=5.33333
    }

    if (NameFunction=="MHL_IntegralOfRectangle")
    {
        double a=-2;
        double b=2;
        double Epsilon=0.01;
        double S;

        //Вызов функции
        S=MHL_IntegralOfRectangle(a,b,Epsilon,Func3);

        //Используем полученный результат
        MHL_ShowNumber (a,"Левая граница интегрирования", "a");
        //Левая граница интегрирования:
        //a=-2
        MHL_ShowNumber (b,"Правая граница интегрирования", "b");
        //Правая граница интегрирования:
        //b=2
        MHL_ShowNumber (S,"Интеграл", "S");
        // Интеграл:
        //S=5.32812
    }

    if (NameFunction=="TMHL_HeavisideFunction")
    {
        double x=MHL_RandomUniform(-50,50);

        double F=TMHL_HeavisideFunction(x);

        //Используем полученный результат
        MHL_ShowNumber(F,"Функция Хэвисайда при a = "+MHL_NumberToText(x),"равна");
        //Функция Хэвисайда при a = -49.7559:
        //равна=0
    }

    if (NameFunction=="MHL_ExpMSxD2")
    {
        double t;
        double f;
        t=MHL_RandomUniform(0,3);

        //Вызов функции
        f=MHL_ExpMSxD2(t);

        //Используем полученный результат

        MHL_ShowNumber (t,"Параметр", "t");
        //Параметр:
        //t=2.06177
        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.11938
    }

    if (NameFunction=="MHL_NormalizationNumberAll")
    {
        double x;
        double y;
        y=MHL_RandomUniform(-100,100);

        //Вызов функции
        x=MHL_NormalizationNumberAll(y);

        //Используем полученный результат
        MHL_ShowNumber (y,"Число", "y");
        //Число:
        //y=-10.4004
        MHL_ShowNumber (x,"Нормированное число", "x");
        //Нормированное число:
        //x=0.0438581
    }

    if (NameFunction=="MHL_InverseNormalizationNumberAll")
    {
        double x;
        double y;
        x=MHL_RandomNumber();

        //Вызов функции
        y=MHL_InverseNormalizationNumberAll(x);

        //Используем полученный результат
        MHL_ShowNumber (x,"Нормированное число", "x");
        // Нормированное число:
        //x=0.0491333
        MHL_ShowNumber (y,"Перенормированное число", "y");
        // Перенормированное число:
        //y=-9.1764
    }

    if (NameFunction=="MHL_BinaryMonteCarloAlgorithm")
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
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_BinaryMonteCarloAlgorithm (ParametersOfBinaryMonteCarloAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        //Как прошел запуск:
        //VMHL_Success=1

        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,LengthBinarString,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	0	1	1	1	1	1	0	1	1	1	1	1	1	1	0	0	1	0	0	1	1	1	1	1	0	1	1	0	1	1	0	1	1	1	1	0	0	1	1	1	1	0	1	1	1	0	1	1	1

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=37
        }
        delete [] ParametersOfBinaryMonteCarloAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="TMHL_BubbleDescendingSort")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomNumber();

        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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
        TMHL_BubbleDescendingSort(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Отсортированный вектор", "a");
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

    if (NameFunction=="TMHL_BubbleSort")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomNumber();

        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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
        TMHL_BubbleSort(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Отсортированный вектор", "a");
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

    if (NameFunction=="TMHL_BubbleSortInGroups")
    {
        int i;
        int VMHL_N=9;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(10,50);

        // Например
        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //20	42	39	19	27	33	35	44	32

        int m=3;

        //Вызов функции
        TMHL_BubbleSortInGroups(a,VMHL_N,m);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Отсортированный вектор по три элемента", "a");
        //Отсортированный вектор по три элемента:
        //a =
        //20	39	42	19	27	33	32	35	44

        delete [] a;
    }

    if (NameFunction=="TMHL_BubbleSortWithConjugateVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        int *b;
        b=new int[VMHL_N];
        for (i=0;i<VMHL_N;i++)
        {
            a[i]=MHL_RandomUniformInt(10,50);
            b[i]=MHL_RandomUniformInt(10,50);
        }

        // Например
        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        // Случайный вектор:
        //a =
        //31	32	13	26	40	40	47	26	10	18

        MHL_ShowVectorT (b,VMHL_N,"Сопряженный вектор", "b");
        //Сопряженный вектор:
        //b =
        //31	20	44	32	21	36	46	30	31	15

        //Вызов функции
        TMHL_BubbleSortWithConjugateVector(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Отсортированный вектор", "a");
        // Отсортированный вектор:
        //a =
        //10	13	18	26	26	31	32	40	40	47

        MHL_ShowVectorT (b,VMHL_N,"Сопряженный вектор", "b");
        // Сопряженный вектор:
        //b =
        //31	44	15	32	30	31	20	21	36	46

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_BubbleSortWithTwoConjugateVectors")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        int *b;
        b=new int[VMHL_N];
        int *c;
        c=new int[VMHL_N];
        for (i=0;i<VMHL_N;i++)
        {
            a[i]=MHL_RandomUniformInt(10,50);
            b[i]=MHL_RandomUniformInt(10,50);
            c[i]=MHL_RandomUniformInt(10,50);
        }

        // Например
        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //45	27	11	18	24	25	16	19	34	43

        MHL_ShowVectorT (b,VMHL_N,"Сопряженный вектор", "b");
        //Сопряженный вектор:
        //b =
        //33	32	24	33	32	49	33	43	25	47

        MHL_ShowVectorT (c,VMHL_N,"Сопряженный вектор", "c");
        //Сопряженный вектор:
        //c =
        //15	24	27	43	17	47	25	11	13	26

        //Вызов функции
        TMHL_BubbleSortWithTwoConjugateVectors(a,b,c,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Отсортированный вектор", "a");
        //Отсортированный вектор:
        //a =
        //11	16	18	19	24	25	27	34	43	45

        MHL_ShowVectorT (b,VMHL_N,"Сопряженный вектор", "b");
        // Сопряженный вектор:
        //b =
        //24	33	33	43	32	49	32	25	47	33

        MHL_ShowVectorT (c,VMHL_N,"Второй сопряженный вектор", "c");
        //Второй сопряженный вектор:
        //c =
        //27	25	43	11	17	47	24	13	26	15

        delete [] a;
        delete [] b;
        delete [] c;
    }

    if (NameFunction=="MHL_DensityOfDistributionOfNormalizedCenteredNormalDistribution")
    {
        double t;
        double f;
        t=MHL_RandomUniform(0,3);

        //Вызов функции
        f=MHL_DensityOfDistributionOfNormalizedCenteredNormalDistribution(t);

        //Используем полученный результат

        MHL_ShowNumber (t,"Параметр", "t");
        // Параметр:
        //t=1.42401
        MHL_ShowNumber (f,"Значение функции", "f");
        // Значение функции:
        //f=0.144736
    }

    if (NameFunction=="MHL_StdDevToVariance")
    {
        double Variance;
        double StdDev=6;

        //Вызов функции
        Variance=MHL_StdDevToVariance(StdDev);

        //Используем результат
        MHL_ShowNumber(Variance,"Дисперсия при среднеквадратичном уклонении, равным "+MHL_NumberToText(StdDev),"равна");
        //Дисперсия при среднеквадратичном уклонении, равным 6:
        //равна=2.44949
    }

    if (NameFunction=="MHL_VarianceToStdDev")
    {
        double StdDev;
        double Variance=6;

        //Вызов функции
        StdDev=MHL_VarianceToStdDev(Variance);

        //Используем полученный результат
        MHL_ShowNumber(StdDev,"Среднеквадратичное уклонение при дисперсии, равной "+MHL_NumberToText(Variance),"равно");
        //Среднеквадратичное уклонение при дисперсии, равной 6:
        //равно=36
    }

    if (NameFunction=="TMHL_Mean")
    {
        int i;
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniform(0,10);

        //Вызов функции
        double Mean=TMHL_Mean(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Массив", "a");
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

        MHL_ShowNumber (Mean,"Среднее арифметическое массива", "Mean");
        //Среднее арифметическое массива:
        //Mean=4.37216

        delete [] a;
    }

    if (NameFunction=="TMHL_Median")
    {
        int i;
        int VMHL_N=MHL_RandomUniformInt(3,10);//Размер массива
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniform(0,10);

        //Вызов функции
        double Median=TMHL_Median(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Массив", "a");
        //Массив:
        //a =
        //8.77167
        //5.89142
        //6.45966
        //3.94775

        MHL_ShowNumber (Median,"Медиана", "Median");
        // Медиана:
        //Median=6.17554

        delete [] a;
    }

    if (NameFunction=="TMHL_SampleCovariance")
    {
        int VMHL_N=10;//Размер массива
        double *x;
        x=new double[VMHL_N];
        double *y;
        y=new double[VMHL_N];
        //Заполним случайными числами
        MHL_RandomRealVector (x,0,10,VMHL_N);
        MHL_RandomRealVector (y,0,10,VMHL_N);

        //Вызов функции
        double SampleCovariance=TMHL_SampleCovariance(x,y,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Первый массив", "x");
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

        MHL_ShowVector (y,VMHL_N,"Второй массив", "y");
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

        MHL_ShowNumber (SampleCovariance,"Значение выборочной ковариации", "SampleCovariance");
        // Значение выборочной ковариации:
        //SampleCovariance=-0.955199

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="TMHL_Variance")
    {
        int VMHL_N=10;//Размер массива
        double *x;
        x=new double[VMHL_N];
        //Заполним случайными числами
        MHL_RandomRealVector (x,0,10,VMHL_N);

        //Вызов функции
        double Variance=TMHL_Variance(x,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Массив", "x");
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

        MHL_ShowNumber (Variance,"Значение выборочной дисперсии", "Variance");
        //Значение выборочной дисперсии:
        //Variance=10.1197

        delete [] x;
    }

    if (NameFunction=="TMHL_SinglepointCrossover")
    {
        int VMHL_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VMHL_N];
        int *Parent2;
        Parent2=new int[VMHL_N];
        int *Child;
        Child=new int[VMHL_N];
        TMHL_RandomBinaryVector(Parent1,VMHL_N);
        TMHL_RandomBinaryVector(Parent2,VMHL_N);

        //Получим потомка Child
        TMHL_SinglepointCrossover(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0	1	1	0	0	1	0	1	1	1

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	0	0	1	0	1	0	0	0	0

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0	1	1	0	0	1	0	1	1	1

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="TMHL_TwopointCrossover")
    {
        int VMHL_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VMHL_N];
        int *Parent2;
        Parent2=new int[VMHL_N];
        int *Child;
        Child=new int[VMHL_N];
        TMHL_RandomBinaryVector(Parent1,VMHL_N);
        TMHL_RandomBinaryVector(Parent2,VMHL_N);

        //Получим потомка Child
        TMHL_TwopointCrossover(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //1	1	0	0	1	1	0	0	0	0

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	1	1	0	0	1	0	0	1	0

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0	1	1	0	0	1	0	0	1	0

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="TMHL_UniformCrossover")
    {
        int VMHL_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VMHL_N];
        int *Parent2;
        Parent2=new int[VMHL_N];
        int *Child;
        Child=new int[VMHL_N];
        TMHL_RandomBinaryVector(Parent1,VMHL_N);
        TMHL_RandomBinaryVector(Parent2,VMHL_N);

        //Получим потомка Child
        TMHL_UniformCrossover(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //1	1	0	1	1	1	1	1	1	0

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	0	0	0	1	0	1	1	0	0

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //1	1	0	0	1	0	1	1	1	0

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="TMHL_BinaryToDecimalFromPart")
    {
        int VMHL_N=8;//Размер массива
        int *a;
        a=new int[VMHL_N];
        TMHL_RandomBinaryVector(a,VMHL_N);

        int Begin=2;

        //Вызов функции
        int x=TMHL_BinaryToDecimalFromPart(a,Begin,5);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Бинарная строка", "a");
        //Бинарная строка:
        //a =
        //0	0	1	0	1	0	0	0

        MHL_ShowNumber (Begin,"Двоичное число состоит из 5 символов начиная с", "номера");
        //Двоичное число состоит из 5 символов начиная с:
        //номера=2

        MHL_ShowNumber (x,"Было закодировано", "x");
        //Было закодировано:
        //x=20

        delete [] a;
    }

    if (NameFunction=="TMHL_BinaryToDecimal")
    {
        int VMHL_N=8;//Размер массива
        int *a;
        a=new int[VMHL_N];
        TMHL_RandomBinaryVector(a,VMHL_N);

        //Вызов функции
        int x=TMHL_BinaryToDecimal(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Двоичное число", "a");
        //Двоичное число:
        //a =
        //0	1	1	1	1	0	1	0

        MHL_ShowNumber (x,"Было закодировано", "x");
        //Было закодировано:
        //x=122

        delete [] a;
    }

    if (NameFunction=="MHL_BinaryVectorToRealVector")
    {
        int n=10;//Размер массива
        int *BinaryVector;
        BinaryVector=new int[n];
        //Заполним случайно
        TMHL_RandomBinaryVector(BinaryVector,n);

        int VMHL_N=2;//Пусть был закодирован двумерный вектор
        double *RealVector;//Вещественный вектор
        RealVector=new double[VMHL_N];
        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[VMHL_N];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[VMHL_N];
        int *Lengthi;//массив значений, сколько на каждую координату отводится бит в бинраной строке;
        Lengthi=new int[VMHL_N];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        TMHL_FillVector(Left,VMHL_N,0.);//Пусть будет интервал [0;1]
        TMHL_FillVector(Right,VMHL_N,1.);
        TMHL_FillVector(Lengthi,VMHL_N,5);//По сумме элементов вектор должен равен n (длине бинарной строки)

        //Вызов функции
        MHL_BinaryVectorToRealVector(BinaryVector,RealVector,Left,Right,Lengthi,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (BinaryVector,n,"Бинарная строка", "BinaryVector");
        //Бинарная строка:
        //BinaryVector =
        //0	1	0	1	1	1	0	1	0	1

        MHL_ShowVectorT (RealVector,VMHL_N,"Был закодирован вектор", "RealVector");
        //Был закодирован вектор:
        //RealVector =
        //0.34375	0.65625

        delete [] BinaryVector;
        delete [] RealVector;
        delete [] Left;
        delete [] Right;
        delete [] Lengthi;
    }

    if (NameFunction=="TMHL_GrayCodeToBinaryFromPart")
    {
        int VMHL_N=8;//Размер массива
        int *VectorWithGrayCode;
        VectorWithGrayCode=new int[VMHL_N];
        //Заполним случайно нулями и единицами
        TMHL_RandomBinaryVector(VectorWithGrayCode,VMHL_N);

        int *VectorWithBinaryCode;
        VectorWithBinaryCode=new int[VMHL_N];
        TMHL_FillVector(VectorWithBinaryCode,VMHL_N,-1);

        int Begin=2;

        //Вызов функции
        TMHL_GrayCodeToBinaryFromPart(VectorWithGrayCode,VectorWithBinaryCode,Begin,5);

        //Используем полученный результат
        MHL_ShowVectorT (VectorWithGrayCode,VMHL_N,"Строка, содержащая код Грея", "a");
        //Строка, содержащая код Грея:
        //a =
        //1	0	0	1	1	1	0	0

        MHL_ShowNumber (Begin,"Двоичное число состоит из 5 символов начиная с", "номера");
        //Двоичное число состоит из 5 символов начиная с:
        //номера=2

        MHL_ShowVectorT (VectorWithBinaryCode,VMHL_N,"Строка, содержащая бинарный код, полученый из кода Грея", "a");
        //Строка, содержащая бинарный код, полученый из кода Грея:
        //a =
        //-1	-1	0	1	0	1	1	-1

        delete [] VectorWithGrayCode;
        delete [] VectorWithBinaryCode;
    }

    if (NameFunction=="TMHL_GrayCodeToBinary")
    {
        int VMHL_N=5;//Размер массива
        int *GrayCode;
        GrayCode=new int[VMHL_N];
        //Получим случайный Грей код
        TMHL_RandomBinaryVector(GrayCode,VMHL_N);

        int *BinaryCode;
        BinaryCode=new int[VMHL_N];

        //Вызов функции
        TMHL_GrayCodeToBinary(GrayCode,BinaryCode,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (GrayCode,VMHL_N,"Грей код", "a");
        //Грей код:
        //a =
        //1	1	0	1	1

        MHL_ShowVectorT (BinaryCode,VMHL_N,"Бинарный код, полученый из кода Грея", "a");
        //Бинарный код, полученый из кода Грея:
        //a =
        //1	0	0	1	0

        delete [] GrayCode;
        delete [] BinaryCode;
    }

    if (NameFunction=="MHL_BinaryGrayVectorToRealVector")
    {
        int n=10;//Размер массива
        int *BinaryGrayVector;
        BinaryGrayVector=new int[n];
        //Заполним случайно
        TMHL_RandomBinaryVector(BinaryGrayVector,n);

        int VMHL_N=2;//Пусть был закодирован двумерный вектор
        double *RealVector;//Вещественный вектор
        RealVector=new double[VMHL_N];
        double *Left;//массив левых границ изменения каждой вещественной координаты
        Left=new double[VMHL_N];
        double *Right;//массив правых границ изменения каждой вещественной координаты
        Right=new double[VMHL_N];
        int *Lengthi;//массив значений, сколько на каждую координату отводится бит в бинраной строке;
        Lengthi=new int[VMHL_N];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        TMHL_FillVector(Left,VMHL_N,0.);//Пусть будет интервал [0;1]
        TMHL_FillVector(Right,VMHL_N,1.);
        TMHL_FillVector(Lengthi,VMHL_N,5);//По сумме элементов вектор должен равен n (длине бинарной строки)

        //Вызов функции
        MHL_BinaryGrayVectorToRealVector(BinaryGrayVector,n,RealVector,Left,Right,Lengthi,VMHL_N);

        //Используем полученный результат

        MHL_ShowVectorT (BinaryGrayVector,n,"Бинарная строка Грея кода", "BinaryVector");
        //Бинарная строка Грея кода:
        //BinaryVector =
        //1	0	1	0	1	0	0	0	1	0

        MHL_ShowVectorT (RealVector,VMHL_N,"Был закодирован вектор", "RealVector");
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
        TMHL_RandomBinaryVector(BinaryGrayVector,n);

        VMHL_N=2;//Пусть был закодирован двумерный вектор
        RealVector=new double[VMHL_N];
        Left=new double[VMHL_N];
        Right=new double[VMHL_N];
        Lengthi=new int[VMHL_N];

        int *TempBinaryVector;
        TempBinaryVector=new int[n];

        //Заполним массивы
        //Причем по каждой коодинтате одинаковые значения выставим
        TMHL_FillVector(Left,VMHL_N,0.);//Пусть будет интервал [0;1]
        TMHL_FillVector(Right,VMHL_N,1.);
        TMHL_FillVector(Lengthi,VMHL_N,5);//По сумме элементов вектор должен равен n (длине бинарной строки)

        //Вызов функции
        MHL_BinaryGrayVectorToRealVector(BinaryGrayVector,RealVector,TempBinaryVector,Left,Right,Lengthi,VMHL_N);

        //Используем полученный результат

        MHL_ShowVectorT (BinaryGrayVector,n,"Бинарная строка Грея кода", "BinaryVector");
        // Бинарная строка Грея кода:
        //BinaryVector =
        //0	0	1	0	0	1	1	1	0	1

        MHL_ShowVectorT (RealVector,VMHL_N,"Был закодирован вектор", "RealVector");
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

    if (NameFunction=="TMHL_RandomVectorOfPermutation")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];

        //Вызов функции
        TMHL_RandomVectorOfPermutation(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Строка-перестановка", "a");
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

    if (NameFunction=="TMHL_RandomMatrixOfPermutation")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=5;//Размер массива (число строк)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        //Вызов функции
        TMHL_RandomMatrixOfPermutation(a,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Матрица строк-перестановок", "a");
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

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_MutationBinaryMatrix")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        TMHL_RandomBinaryMatrix(a,VMHL_N,VMHL_M);//Случайная бинарная матрица
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная бинарная матрица", "a");
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
        TMHL_MutationBinaryMatrix(a,ProbabilityOfMutation,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Мутированная бинарная матрица", "a");
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

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="MHL_TournamentSelectionWithReturn")
    {
        int i;
        int VMHL_N=7;//Размер массива
        double *Fitness;
        Fitness=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            Fitness[i]=MHL_RandomNumber();

        int SizeTournament=3;// Размер турнира

        //Вызов функции
        int Number=MHL_TournamentSelectionWithReturn(Fitness,SizeTournament,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Fitness,VMHL_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.883148
        //0.370209
        //0.0719604
        //0.311371
        //0.558594
        //0.42215
        //0.011322

        MHL_ShowNumber (Number,"Номер выбранного индивида", "Number");
        //Номер выбранного индивида:
        //Number=4

        delete [] Fitness;
    }

    if (NameFunction=="MHL_TournamentSelection")
    {
        int i;
        int VMHL_N=7;//Размер массива
        double *Fitness;
        Fitness=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            Fitness[i]=MHL_RandomNumber();

        int SizeTournament=3;// Размер турнира

        //Вызов функции
        int Number=MHL_TournamentSelection(Fitness,SizeTournament,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Fitness,VMHL_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.858643
        //0.460541
        //0.469696
        //0.454315
        //0.594543
        //0.000457764
        //0.476135


        MHL_ShowNumber (SizeTournament,"Размер турнираа", "SizeTournament");
        // Размер турнираа:
        //SizeTournament=3

        MHL_ShowNumber (Number,"Номер выбранного индивида", "Number");
        //Номер выбранного индивида:
        //Number=6

        delete [] Fitness;

        //Для переопределенной функции
        VMHL_N=7;//Размер массива
        Fitness=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            Fitness[i]=MHL_RandomNumber();

        int *Taken;//Информация о том, в турнире или нет индивид (Служебный массив)
        Taken=new int[VMHL_N];

        SizeTournament=3;// Размер турнира

        //Вызов функции
        Number=MHL_TournamentSelection(Fitness,SizeTournament,Taken,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Fitness,VMHL_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.598633
        //0.396423
        //0.756683
        //0.123505
        //0.0546875
        //0.542511
        //0.605499

        MHL_ShowNumber (SizeTournament,"Размер турнира", "SizeTournament");
        //Размер турнира:
        //SizeTournament=3

        MHL_ShowNumber (Number,"Номер выбранного индивида", "Number");
        //Номер выбранного индивида:
        //Number=2

        delete [] Fitness;
        delete [] Taken;
    }

    if (NameFunction=="MHL_MakeVectorOfRankForRankSelection")
    {
        int i;
        int VMHL_N=7;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            Fitness[i]=MHL_RandomUniformInt(1,10)/10.;

        double *Rank;
        Rank=new double[VMHL_N];

        //Вызов функции
        MHL_MakeVectorOfRankForRankSelection(Fitness,Rank,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Fitness,VMHL_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.3
        //0.5
        //0.7
        //0.5
        //0.8
        //0.1
        //0.6

        MHL_ShowVector (Rank,VMHL_N,"Массив рангов", "Rank");
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

    if (NameFunction=="MHL_NormalizationVectorOne")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(-100,100);

        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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
        MHL_NormalizationVectorOne(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Нормализованный вектор", "a");
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

        MHL_ShowNumber (TMHL_SumVector(a,VMHL_N),"Его сумма", "Sum");
        //Его сумма:
        //Sum=1

        delete [] a;
    }

    if (NameFunction=="MHL_NormalizationVectorMaxMin")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(-100,100);

        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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
        MHL_NormalizationVectorMaxMin(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Нормализованный вектор", "a");
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

    if (NameFunction=="MHL_NormalizationVectorAll")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        MHL_RandomRealVector(a,-100,100,VMHL_N);

        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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
        MHL_NormalizationVectorAll(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Нормализованный вектор", "a");
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

    if (NameFunction=="MHL_MakeVectorOfProbabilityForProportionalSelectionV2")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VMHL_N];
        //Заполним вектор случайными значениями пригодностей индивидов
        //на практике, конечно, пригодности вычисляются, например, в
        //процессе работы ГА
        for (i=0;i<VMHL_N;i++) Fitness[i]=MHL_RandomNumber();

        //Для работы этого варианта пропорциональной селекции нужен
        //массив вероятностей выбора индивидов для порпоциональной селекции;
        double *VectorProbability;
        VectorProbability=new double[VMHL_N];

        //Вызов функции
        MHL_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorProbability,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (Fitness,VMHL_N,"Вектор пригодностей индивидов", "a");
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

        MHL_ShowVector (VectorProbability,VMHL_N,"Вектор вероятностей выбора индивидов", "VectorProbability");
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

        MHL_ShowNumber (TMHL_SumVector(VectorProbability,VMHL_N),"Его сумма", "Sum");
        //Его сумма:
        //Sum=1

        delete [] Fitness;
        delete [] VectorProbability;
    }

    if (NameFunction=="MHL_SelectItemOnProbability")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        //Заполним вектор случайными значениями вероятностей
        MHL_RandomVectorOfProbability(a, VMHL_N);

        //Вызов функции
        int Number=MHL_SelectItemOnProbability(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор вероятностей выбора", "a");
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

        MHL_ShowNumber (Number,"Номер выбранного элемента", "Number");
        // Номер выбранного элемента:
        //Number=6

        delete [] a;
    }

    if (NameFunction=="MHL_ProportionalSelection")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VMHL_N];
        //Заполним вектор случайными значениями пригодностей индивидов
        //на практике, конечно, пригодности вычисляются, например, в
        //процессе работы ГА
        for (i=0;i<VMHL_N;i++) Fitness[i]=MHL_RandomNumber();

        //Вызов функции
        int Number=MHL_ProportionalSelection(Fitness,VMHL_N);

        //Используем полученный результат

        //Например:
        MHL_ShowVector (Fitness,VMHL_N,"Вектор пригодностей индивидов", "a");
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

        MHL_ShowNumber (Number,"Номер выбранного индивида", "Number");
        //Номер выбранного индивида:
        //Number=5

        delete [] Fitness;
    }

    if (NameFunction=="MHL_ProportionalSelectionV2")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VMHL_N];
        //Заполним вектор случайными значениями пригодностей индивидов
        //на практике, конечно, пригодности вычисляются, например, в
        //процессе работы ГА
        for (i=0;i<VMHL_N;i++) Fitness[i]=MHL_RandomNumber();

        //Для работы этого варианта пропорциональной селекции нужен
        //массив вероятностей выбора индивидов для порпоциональной селекции;
        double *VectorProbability;
        VectorProbability=new double[VMHL_N];
        //Сформируем этот массив
        MHL_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorProbability,VMHL_N);

        //Вызов функции
        int Number=MHL_ProportionalSelectionV2(VectorProbability,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (Fitness,VMHL_N,"Вектор пригодностей индивидов", "a");
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

        MHL_ShowVector (VectorProbability,VMHL_N,"Вектор вероятностей выбора индивидов", "VectorProbability");
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

        MHL_ShowNumber (TMHL_SumVector(VectorProbability,VMHL_N),"Его сумма", "Sum");
        // Его сумма:
        //Sum=1

        MHL_ShowNumber (Number,"Номер выбранного индивида", "Number");

        // Номер выбранного индивида:
        //Number=6

        delete [] Fitness;
        delete [] VectorProbability;
    }

    if (NameFunction=="MHL_ProportionalSelectionV3")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VMHL_N];
        //Заполним вектор случайными значениями пригодностей индивидов
        //на практике, конечно, пригодности вычисляются, например, в
        //процессе работы ГА
        for (i=0;i<VMHL_N;i++) Fitness[i]=MHL_RandomNumber();

        //Вызов функции
        int Number=MHL_ProportionalSelectionV3(Fitness,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (Fitness,VMHL_N,"Вектор пригодностей индивидов", "a");
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

        MHL_ShowNumber (Number,"Номер выбранного индивида", "Number");
        // Номер выбранного индивида:
        //Number=0

        delete [] Fitness;
    }

    if (NameFunction=="MHL_RankSelection")
    {
        int i;
        int VMHL_N=7;//Размер массива
        double *Fitness;
        Fitness=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            Fitness[i]=MHL_RandomUniformInt(1,10)/10.;

        double *Rank;
        Rank=new double[VMHL_N];

        double *VectorProbability;
        VectorProbability=new double[VMHL_N];

        //Сформируем вектор рангов
        MHL_MakeVectorOfRankForRankSelection(Fitness,Rank,VMHL_N);
        //Из вектора рангов получим вектор вероятностей выбора
        MHL_MakeVectorOfProbabilityForProportionalSelectionV2(Rank,VectorProbability,VMHL_N);

        //Вызов функции
        int Number=MHL_RankSelection(VectorProbability,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Fitness,VMHL_N,"Массив пригодностей", "Fitness");
        // Массив пригодностей:
        //Fitness =
        //0.2
        //0.2
        //0.6
        //0.8
        //0.4
        //0.3
        //0.2

        MHL_ShowVector (Rank,VMHL_N,"Массив рангов", "Rank");
        // Массив рангов:
        //Rank =
        //2
        //2
        //6
        //7
        //5
        //4
        //2

        MHL_ShowVector (VectorProbability,VMHL_N,"Массив вероятностей выбора", "VectorProbability");
        //Массив вероятностей выбора:
        //VectorProbability =
        //0
        //0
        //0.285714
        //0.357143
        //0.214286
        //0.142857
        //0

        MHL_ShowNumber (Number,"Номер выбранного индивида", "Number");
        // Номер выбранного индивида:
        //Number=3

        delete [] Fitness;
        delete [] Rank;
        delete [] VectorProbability;
    }

    if (NameFunction=="MHL_StandartBinaryGeneticAlgorithm")
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
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_StandartBinaryGeneticAlgorithm (ParametersOfStandartBinaryGeneticAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        //Как прошел запуск:
        //VMHL_Success=1

        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=50
        }

        delete [] ParametersOfStandartBinaryGeneticAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="MHL_StandartRealGeneticAlgorithm")
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
        TMHL_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        TMHL_FillVector(Right,ChromosomeLength,5.);
        TMHL_FillVector(NumberOfParts,ChromosomeLength,TMHL_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_StandartRealGeneticAlgorithm (ParametersOfStandartRealGeneticAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //
            MHL_ShowNumber(ValueOfFitnessFunction,"Значение целевой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction =
        }

        delete [] ParametersOfStandartRealGeneticAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="MHL_StandartGeneticAlgorithm")
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
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_StandartGeneticAlgorithm (ParametersOfStandartBinaryGeneticAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        //Как прошел запуск:
        //VMHL_Success=1

        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
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
            TMHL_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
            TMHL_FillVector(Right,ChromosomeLength,5.);
            TMHL_FillVector(NumberOfParts,ChromosomeLength,TMHL_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

            double *Decision;//вещественное решение
            Decision=new double[ChromosomeLength];
            double ValueOfFitnessFunction;//значение целевой функции в точке Decision
            int VMHL_Success=0;//Успешен ли будет запуск cГА

            //Запуск алгоритма
            VMHL_Success=MHL_StandartGeneticAlgorithm (ParametersOfStandartRealGeneticAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

            //Используем полученный результат
            MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
            if (VMHL_Success==1)
            {
                MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
                //Найденное решение:
                //Decision =
                MHL_ShowNumber(ValueOfFitnessFunction,"Значение целевой функции","ValueOfFitnessFunction");
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

    if (NameFunction=="MHL_TestFunction_Ackley")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-5,5);
        f=MHL_TestFunction_Ackley(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //4.51813
        //-4.19861

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=13.645

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_ParaboloidOfRevolution")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-2,2);
        f=MHL_TestFunction_ParaboloidOfRevolution(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        // Входной вектор:
        //x =
        //0.0842285
        //-1.04395

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=1.09692

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_Rastrigin")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-5,5);
        f=MHL_TestFunction_Rastrigin(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        // Входной вектор:
        //x =
        //2.62268
        //3.52692

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=56.3483

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_Rosenbrock")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-2,2);
        f=MHL_TestFunction_Rosenbrock(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        // Входной вектор:
        //x =
        //-1.28491
        //0.342896


        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=176.334

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_SumVector")
    {
        int VMHL_N=10;//Размер массива (число строк)
        int *x;
        x=new int[VMHL_N];
        //Получим случайный бинарный вектор
        TMHL_RandomBinaryVector(x,VMHL_N);

        //Вызов функции
        double f=MHL_TestFunction_SumVector(x,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Вектор", "x");
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

        MHL_ShowNumber (f,"Значение функции в точке", "f");
        //Значение функции в точке:
        //f=5

        delete [] x;
    }

    if (NameFunction=="TMHL_Factorial")
    {
        int a=MHL_RandomUniformInt(0,10);

        double Result=TMHL_Factorial(a);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Факториал числа "+MHL_NumberToText(a),"a!");
        //Факториал числа 3:
        //a!=6
    }

    if (NameFunction=="TMHL_KCombinations")
    {
        int n=10;
        int k=MHL_RandomUniformInt(0,10);

        int C=TMHL_KCombinations(k,n);

        //Используем полученный результат
        MHL_ShowNumber(C,"Число сочетаний по "+MHL_NumberToText(k)+" элементов из " +MHL_NumberToText(n),"C");
        //Число сочетаний по 8 элементов из 10:
        //C=45

    }

    if (NameFunction=="MHL_ProbabilityOfTournamentSelection")
    {
        int i;
        int VMHL_N=10;//размер популяции
        double *f=new double[VMHL_N];//массив значений целевой функции
        double *p=new double[VMHL_N];//массив значений веротяностей выбора индивидов
        int T=3; // размер турнира

        for (i=0;i<VMHL_N;i++) f[i]=MHL_RandomUniformInt(0,11)/10.;//заполним случайными значениями целевой функции

        MHL_ShowVector (f,VMHL_N,"Вектор значений целевой функции", "f");
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
        double sum = MHL_ProbabilityOfTournamentSelection(f,p,T,VMHL_N);

        //Используем результат
        MHL_ShowVector (p,VMHL_N,"Вектор значений вероятностей выбора", "p");
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

        MHL_ShowNumber(sum,"Сумма вектора значений вероятностей выбора","sum");
        //Сумма вектора значений вероятностей выбора:
        //sum=1

        delete[] f;
        delete[] p;
    }

    if (NameFunction=="MHL_MakeVectorOfProbabilityForRanklSelection")
    {
        int i;
        int VMHL_N=7;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            Fitness[i]=MHL_RandomUniformInt(1,10)/10.;

        double *Rank;
        Rank=new double[VMHL_N];

        double *VectorProbability;
        VectorProbability=new double[VMHL_N];

        //Получаем массив рангов
        MHL_MakeVectorOfRankForRankSelection(Fitness,Rank,VMHL_N);

        //Вызов функции
        MHL_MakeVectorOfProbabilityForRanklSelection(Rank,VectorProbability,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Fitness,VMHL_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.5
        //0.7
        //0.3
        //0.9
        //0.8
        //0.7
        //0.9

        MHL_ShowVector (Rank,VMHL_N,"Массив рангов", "Rank");
        //Массив рангов:
        //Rank =
        //2
        //3.5
        //1
        //6.5
        //5
        //3.5
        //6.5

        MHL_ShowVector (VectorProbability,VMHL_N,"Вектор вероятностей выбора", "VectorProbability");
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

    if (NameFunction=="MHL_MakeVectorOfRankZeroForRankSelection")
    {
        int i;
        int VMHL_N=7;//Размер массива (число строк)
        double *Fitness;
        Fitness=new double[VMHL_N];
        for (i=0;i<VMHL_N;i++)
            Fitness[i]=MHL_RandomUniformInt(1,10)/10.;

        double *Rank;
        Rank=new double[VMHL_N];

        //Вызов функции
        MHL_MakeVectorOfRankZeroForRankSelection(Fitness,Rank,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Fitness,VMHL_N,"Массив пригодностей", "Fitness");
        //Массив пригодностей:
        //Fitness =
        //0.3
        //0.8
        //0.2
        //0.9
        //0.1
        //0.9
        //0.4

        MHL_ShowVector (Rank,VMHL_N,"Массив рангов", "Rank");
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

    if (NameFunction=="MHL_RandomUniformIntIncluding")
    {
        double x;
        int s0=0,s1=0,s2=0,s3=0;

        //Вызов функции
        for (int i=0;i<1000;i++)
        {
            x=MHL_RandomUniformIntIncluding(0,3);
            if (x==0) s0++;
            if (x==1) s1++;
            if (x==2) s2++;
            if (x==3) s3++;
        }

        //Используем полученный результат
        MHL_ShowNumber(x,"Случайное целое число из интервала [0;3]","x");
        MHL_ShowNumber(s0,"Число выпадений 0","s0");
        MHL_ShowNumber(s1,"Число выпадений 1","s0");
        MHL_ShowNumber(s2,"Число выпадений 2","s0");
        MHL_ShowNumber(s3,"Число выпадений 3","s0");
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

    if (NameFunction=="TMHL_BubbleSortRowWithOtherConjugateRowsInMatrix")
    {
        int i;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        TMHL_RandomIntMatrix(a,0,5,VMHL_N,VMHL_M);

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //0	0	1	2	3
        //1	2	1	4	1
        //3	1	2	0	1
        //3	4	1	0	0
        //4	4	1	0	2

        int Row=2;//Будем сортировать строку под номером 2

        //Вызов функции

        TMHL_BubbleSortRowWithOtherConjugateRowsInMatrix(a, Row, VMHL_N, VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица отсортированная по строке с номером "+MHL_NumberToText(Row), "a");
        //Случайная матрица отсортированная по строке с номером 2:
        //a =
        //2	0	3	1	0
        //4	2	1	1	1
        //0	1	1	2	3
        //0	4	0	1	3
        //0	4	2	1	4

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_BubbleSortEveryRowInMatrix")
    {
        int i;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=6;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        TMHL_RandomIntMatrix(a,0,5,VMHL_N,VMHL_M);

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //Случайная матрица:
        //a =
        //3	1	2	1	1	2
        //0	1	4	0	2	1
        //4	4	4	3	2	1
        //1	3	0	3	4	0
        //2	3	1	1	2	3


        //Вызов функции
        TMHL_BubbleSortEveryRowInMatrix(a, VMHL_N, VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица, где каждая строка отсортировна независимо", "a");
        //Случайная матрица, где каждая отсортировна независимо:
        //a =
        //1	1	1	2	2	3
        //0	0	1	1	2	4
        //1	2	3	4	4	4
        //0	0	1	3	3	4
        //1	1	2	2	3	3

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_BubbleSortColWithOtherConjugateColsInMatrix")
    {
        int i;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        TMHL_RandomIntMatrix(a,0,5,VMHL_N,VMHL_M);

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //4	0	1
        //4	0	4
        //2	2	0
        //2	3	1
        //1	3	1

        int Col=0;//Будем сортировать столбец под номером 2

        //Вызов функции

        TMHL_BubbleSortColWithOtherConjugateColsInMatrix(a, Col, VMHL_N, VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица отсортированная по столбцу с номером "+MHL_NumberToText(Col), "a");
        //Случайная матрица отсортированная по столбцу с номером 0:
        //a =
        //1	3	1
        //2	2	0
        //2	3	1
        //4	0	1
        //4	0	4

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_BubbleSortEveryColInMatrix")
    {
        int i;
        int VMHL_N=5;//Размер массива (число строк)
        int VMHL_M=6;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        TMHL_RandomIntMatrix(a,0,5,VMHL_N,VMHL_M);

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //4	1	4	3	0	4
        //2	1	1	1	0	3
        //0	4	2	2	0	3
        //1	2	2	2	4	0
        //3	0	2	4	1	4

        //Вызов функции
        TMHL_BubbleSortEveryColInMatrix(a, VMHL_N, VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица, где каждый столбец отсортирован независимо", "a");
        //Случайная матрица, где каждый столбец отсортирован независимо:
        //a =
        //0	0	1	1	0	0
        //1	1	2	2	0	3
        //2	1	2	2	0	3
        //3	2	2	3	1	4
        //4	4	4	4	4	4

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="MHL_QuadraticEquation")
    {
        double a=MHL_RandomUniformInt(1,10);
        double b=MHL_RandomUniformInt(1,10);
        double c=MHL_RandomUniformInt(1,10);
        double x1;
        double x2;

        int Result=MHL_QuadraticEquation(a,b,c,&x1,&x2);;

        //Используем полученный результат
        MHL_ShowText("Квадратное уравнение: "+MHL_NumberToText(a)+"x^2+"+MHL_NumberToText(b)+"x+"+MHL_NumberToText(c)+"=0");
        //Квадратное уравнение: 1x^2+8x+5:
        MHL_ShowNumber(Result,"Найдено ли решение","Result");
        //Найдено ли решение:
        //Result=1
        if (Result==1)
        {
            MHL_ShowNumber(x1,"Первый корень квадратного уравнения","x1");
            //Первый корень квадратного уравнения:
            //x1=-0.683375
            MHL_ShowNumber(x2,"Первый корень квадратного уравнения","x2");
            //Первый корень квадратного уравнения:
            //x2=-7.31662
        }
    }

    if (NameFunction=="MHL_BellShapedKernelExp")
    {
        double z=MHL_RandomUniform(-5,5);

        //Вызов функции
        double f=MHL_BellShapedKernelExp(z);

        //Используем полученный результат
        MHL_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.721436
        MHL_ShowNumber(f,"Значение колоколообразного экспоненциального ядра","f");
        //Значение колоколообразного экспоненциального ядра:
        //f=0.302588
    }

    if (NameFunction=="MHL_BellShapedKernelParabola")
    {
        double z=MHL_RandomUniform(-5,5);

        //Вызов функции
        double f=MHL_BellShapedKernelParabola(z);

        //Используем полученный результат
        MHL_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.33905
        MHL_ShowNumber(f,"Значение колоколообразного параболического ядра","f");
        //Значение колоколообразного параболического ядра:
        //f=0.327298
    }

    if (NameFunction=="MHL_BellShapedKernelRectangle")
    {
        double z=MHL_RandomUniform(-5,5);

        //Вызов функции
        double f=MHL_BellShapedKernelRectangle(z);

        //Используем полученный результат
        MHL_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.669556
        MHL_ShowNumber(f,"Значение колоколообразного прямоугольного ядра","f");
        //Значение колоколообразного прямоугольного ядра:
        //f=0.5
    }

    if (NameFunction=="MHL_BellShapedKernelTriangle")
    {
        double z=MHL_RandomUniform(-5,5);

        //Вызов функции
        double f=MHL_BellShapedKernelTriangle(z);

        //Используем полученный результат
        MHL_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.362854
        MHL_ShowNumber(f,"Значение колоколообразного треугольного ядра","f");
        //Значение колоколообразного треугольного ядра:
        //f=0.637146
    }

    if (NameFunction=="MHL_DerivativeOfBellShapedKernelExp")
    {
        double z=MHL_RandomUniform(-4,4);

        //Вызов функции
        double f=MHL_DerivativeOfBellShapedKernelExp(z);

        //Используем полученный результат
        MHL_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=-1.93701
        MHL_ShowNumber(f,"Значение производной колоколообразного экспоненциального ядра","f");
        //Значение производной колоколообразного экспоненциального ядра:
        //f=0.192278
    }

    if (NameFunction=="MHL_DerivativeOfBellShapedKernelParabola")
    {
        double z=MHL_RandomUniform(-4,4);

        //Вызов функции
        double f=MHL_DerivativeOfBellShapedKernelParabola(z);

        //Используем полученный результат
        MHL_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=1.28394
        MHL_ShowNumber(f,"Значение производной колоколообразного параболического ядра","f");
        //Значение производной колоколообразного параболического ядра:
        //f=-0.172047
    }

    if (NameFunction=="MHL_DerivativeOfBellShapedKernelRectangle")
    {
        double z=MHL_RandomUniform(-4,4);

        //Вызов функции
        double f=MHL_DerivativeOfBellShapedKernelRectangle(z);

        //Используем полученный результат
        MHL_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=3.146
        MHL_ShowNumber(f,"Значение производной колоколообразного прямоугольного ядра","f");
        //Значение производной колоколообразного прямоугольного ядра:
        //f=0
    }

    if (NameFunction=="MHL_DerivativeOfBellShapedKernelTriangle")
    {
        double z=MHL_RandomUniform(-4,4);

        //Вызов функции
        double f=MHL_DerivativeOfBellShapedKernelTriangle(z);

        //Используем полученный результат
        MHL_ShowNumber(z,"Значение параметра","z");
        //Значение параметра:
        //z=0.365479
        MHL_ShowNumber(f,"Значение производной колоколообразного треугольного ядра","f");
        //Значение производной колоколообразного треугольного ядра:
        //f=-1
    }

    if (NameFunction=="MHL_TrapeziformFuzzyNumber")
    {
        double a=MHL_RandomUniform(-4,4);
        double b=a+MHL_RandomUniform(0,2);
        double c=b+MHL_RandomUniform(0,2);
        double d=c+MHL_RandomUniform(0,2);

        double x=MHL_RandomUniform(a-1,d+1);

        //Вызов функции
        double f=MHL_TrapeziformFuzzyNumber (x,a,b,c,d);

        //Используем полученный результат
        MHL_ShowNumber(x,"Значение параметра","x");
        //Значение параметра:
        //x=-0.932339
        MHL_ShowNumber(a,"Значение первого параметра трапецевидного нечеткого числа","a");
        //Значение первого параметра трапецевидного нечеткого числа:
        //a=-1.71997
        MHL_ShowNumber(b,"Значение второго параметра трапецевидного нечеткого числа","b");
        //Значение второго параметра трапецевидного нечеткого числа:
        //b=-0.446045
        MHL_ShowNumber(c,"Значение третьего параметра трапецевидного нечеткого числа","c");
        //Значение третьего параметра трапецевидного нечеткого числа:
        //c=-0.0568848
        MHL_ShowNumber(d,"Значение последнего параметра трапецевидного нечеткого числа","d");
        //Значение последнего параметра трапецевидного нечеткого числа:
        //d=0.253784
        MHL_ShowNumber(f,"Значение функция принадлежности трапециевидного нечеткого числа","f");
        //Значение функция принадлежности трапециевидного нечеткого числа:
        //f=0.618271
    }

    if (NameFunction=="TMHL_ProductOfElementsOfVector")
    {
        int VMHL_N=5;//Размер массива
        double p;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomUniformIntIncluding(1,4);//Заполняем случайными значениями

        //Вызов функции
        p=TMHL_ProductOfElementsOfVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //4
        //3
        //1
        //3
        //2

        MHL_ShowNumber (p,"Произведение элементов массива", "p");
        //Произведение элементов массива:
        //p=72

        delete [] a;
    }

    if (NameFunction=="MHL_MixedMultiLogicVectorOfFullSearch")
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

        int P=TMHL_ProductOfElementsOfVector(x,N);

        MHL_ShowVector(x,N,"Сколько каждого параметра в штуках","x");
        //Сколько каждого параметра в штуках:
        //x =
        //3
        //2
        //3

        for (i=0;i<P;i++)
        {
            MHL_ShowNumber(i,"<hr>Номер итерации", "i");
            //Номер итерации:
            //i=0

            //Вызов функции
            MHL_MixedMultiLogicVectorOfFullSearch(y,i,x,N);

            MHL_ShowVectorT(y,N,"Необходимый вектор","y");
            //Необходимый вектор:
            //y =
            //0	0	0
        }

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="TMHL_SearchElementInVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniformInt(0,4);

        int x=2;

        //Вызов функции
        int Number=TMHL_SearchElementInVector(a,x,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
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

        MHL_ShowNumber (x,"Искомое число", "x");
        //Искомое число:
        //x=2

        MHL_ShowNumber (Number,"Номер первого элемента, равного искомому", "Number");
        //Номер первого элемента, равного искомому:
        //Number=5

        delete [] a;
    }

    if (NameFunction=="TMHL_EqualityOfMatrixes")
    {
        int i,j;
        int VMHL_N=2;//Размер массива (число строк)
        int VMHL_M=2;//Размер массива (число столбцов)

        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                a[i][j]=MHL_RandomUniformInt(0,2);

        int **b;
        b=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) b[i]=new int[VMHL_M];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            for (j=0;j<VMHL_M;j++)
                b[i][j]=MHL_RandomUniformInt(0,2);

        //Вызов функции
        bool Equality=TMHL_EqualityOfMatrixes(a,b,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //1	1
        //0	1

        MHL_ShowMatrix (b,VMHL_N,VMHL_M,"Случайная матрица", "b");
        //Случайная матрица:
        //b =
        //1	1
        //0	1

        MHL_ShowNumber (Equality,"Равны ли матрицы", "Equality");
        //Равны ли матрицы:
        //Equality=1

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;

        for (i=0;i<VMHL_N;i++) delete [] b[i];
        delete [] b;
    }

    if (NameFunction=="MHL_DependentNoiseInVector")
    {
        int VMHL_N=10;//Размер массива
        double *x;
        x=new double[VMHL_N];
        //Заполним массив номерами от 1
        TMHL_OrdinalVector(x,VMHL_N);
        MHL_ShowVector (x,VMHL_N,"Вектор", "x");
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

        double percent=double(MHL_RandomUniformInt(0,100));//Процент помехи

        //Вызов функции
        MHL_DependentNoiseInVector(x,percent,VMHL_N);

        //Используем полученный результат

        MHL_ShowNumber (percent,"Процент помехи", "percent");
        //Процент помехи:
        //percent=6
        MHL_ShowVector (x,VMHL_N,"Вектор с зависимой помехой", "x");
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

    if (NameFunction=="TMHL_Minkovski")
    {
        int VMHL_N=5;//Размер массива
        double *x;
        x=new double[VMHL_N];
        double *y;
        y=new double[VMHL_N];
        //Заполним случайными числами
        MHL_RandomRealVector (x,0,10,VMHL_N);
        MHL_RandomRealVector (y,0,10,VMHL_N);

        int r=3;

        //Вызов функции
        double metric=TMHL_Minkovski(x,y,r,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Первый массив", "x");
        //Первый массив:
        //x =
        //8.2312
        //2.74628
        //9.36371
        //7.31995
        //0.139465

        MHL_ShowVector (y,VMHL_N,"Второй массив", "y");
        //Второй массив:
        //y =
        //6.2793
        //5.07324
        //9.01978
        //5.29297
        //9.84436

        MHL_ShowNumber (metric,"Значение метрики Минковского", "metric");
        //Значение метрики Минковского:
        //metric=9.8044

        delete [] x;
        delete [] y;
    }

    if (NameFunction=="MHL_RealMonteCarloAlgorithm")
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
        TMHL_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        TMHL_FillVector(Right,ChromosomeLength,5.);

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_RealMonteCarloAlgorithm (ParametersOfAlgorithm,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1.91864	1.93604
            MHL_ShowNumber(ValueOfFitnessFunction,"Значение целtвой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction=-0.0107109
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="MHL_DichotomyOptimization")
    {
        double Left=-5;
        double Right=5;
        double Interval=0.01;
        double Epsilon=0.001;
        double x,f;

        //Вызов функции
        MHL_DichotomyOptimization (Left, Right, Func4, Interval, Epsilon, &x, &f);

        //Используем полученный результат
        MHL_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=0.998335

        MHL_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=2.77073e-06
    }

    if (NameFunction=="MHL_FibonacciOptimization")
    {
        double Left=-5;
        double Right=5;
        int Count=30;
        double x,f;

        //Вызов функции
        MHL_FibonacciOptimization (Left, Right, Func4, Count, &x, &f);

        //Используем полученный результат
        MHL_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1

        MHL_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=3.7817e-12
    }

    if (NameFunction=="MHL_GoldenSectionOptimization")
    {
        double Left=-5;
        double Right=5;
        double Interval=0.001;
        double x,f;

        //Вызов функции
        MHL_GoldenSectionOptimization (Left, Right, Func4, Interval, &x, &f);

        //Используем полученный результат
        MHL_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=0.999934

        MHL_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=4.37013e-09
    }

    if (NameFunction=="MHL_QuadraticFitOptimization")
    {
        double Left=-5;
        double Right=5;
        double Epsilon=0.001;
        double Epsilon2=0.001;
        double x,f;

        //Вызов функции
        MHL_QuadraticFitOptimization (Left, Right, Func4, Epsilon,Epsilon2, &x, &f);

        //Используем полученный результат
        MHL_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1

        MHL_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=0
    }

    if (NameFunction=="MHL_RealMonteCarloOptimization")
    {
        double Left=-5;
        double Right=5;
        int Count=30;
        double x,f;

        //Вызов функции
        MHL_RealMonteCarloOptimization (Left, Right, Func4, Count, &x, &f);

        //Используем полученный результат
        MHL_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1.11359

        MHL_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=0.0129019
    }

    if (NameFunction=="MHL_UniformSearchOptimization")
    {
        double Left=-5;
        double Right=5;
        double Interval=0.001;
        double x,f;

        //Вызов функции
        MHL_UniformSearchOptimization (Left, Right, Func4, Interval, &x, &f);

        //Используем полученный результат
        MHL_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1

        MHL_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=2.3863e-29
    }

    if (NameFunction=="MHL_UniformSearchOptimizationN")
    {
        double Left=-5;
        double Right=5;
        int Count=30;
        double x,f;

        //Вызов функции
        MHL_UniformSearchOptimizationN (Left, Right, Func4, Count, &x, &f);

        //Используем полученный результат
        MHL_ShowNumber(x,"Найденное решение","x");
        //Найденное решение:
        //x=1

        MHL_ShowNumber(f,"Значение целевой функции в найденном решении","f");
        //Значение целевой функции в найденном решении:
        //f=0
    }

    if (NameFunction=="TMHL_CheckForIdenticalRowsInMatrix")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int VMHL_M=2;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        TMHL_RandomIntMatrix(a,0,5,VMHL_N,VMHL_M);//заполним матрицу

        //Вызов функции
        bool b=TMHL_CheckForIdenticalRowsInMatrix(a,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Заполненная матрица", "a");
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

        MHL_ShowNumber(b,"Есть ли одинаковые строки", "b");
        //Есть ли одинаковые строки:
        //b=1

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="TMHL_CheckForIdenticalColsInMatrix")
    {
        int i;
        int VMHL_N=2;//Размер массива (число строк)
        int VMHL_M=10;//Размер массива (число столбцов)
        int **a;
        a=new int*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new int[VMHL_M];

        TMHL_RandomIntMatrix(a,0,5,VMHL_N,VMHL_M);//заполним матрицу

        //Вызов функции
        bool b=TMHL_CheckForIdenticalColsInMatrix(a,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Заполненная матрица", "a");
        //Заполненная матрица:
        //a =
        //4	4	0	1	0	1	0	0	2	1
        //1	4	4	3	3	4	4	3	0	1

        MHL_ShowNumber(b,"Есть ли одинаковые столбцы", "b");
        //Есть ли одинаковые столбцы::
        //b=1

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="MHL_LeftBorderOfWilcoxonWFromTable")
    {
        int m=20;
        MHL_ShowNumber(m,"Объем меньшей выборки","m");

        int n=21;
        MHL_ShowNumber(n,"Объем большей выборки","n");

        double Q=0.05;
        MHL_ShowNumber(Q,"Уровень значисмости","Q");

        //Вызов функции
        double Left=MHL_LeftBorderOfWilcoxonWFromTable(m,n,Q);

        //Использование результата
        MHL_ShowNumber(Left,"Левая граница интервала критический значений сатистики W для критерия Вилкоксена","Left");
        //Левая граница интервала критический значений сатистики W для критерия Вилкоксена:
        //Left=356
    }

    if (NameFunction=="MHL_RightBorderOfWilcoxonWFromTable")
    {
        int m=20;
        MHL_ShowNumber(m,"Объем меньшей выборки","m");

        int n=21;
        MHL_ShowNumber(n,"Объем большей выборки","n");

        double Q=0.05;
        MHL_ShowNumber(Q,"Уровень значисмости","Q");

        //Вызов функции
        double Right=MHL_RightBorderOfWilcoxonWFromTable(m,n,Q);

        //Использование результата
        MHL_ShowNumber(Right,"Правая граница интервала критический значений сатистики W для критерия Вилкоксена","Right");
        //Правая граница интервала критический значений сатистики W для критерия Вилкоксена:
        //Right=484
    }

    if (NameFunction=="MHL_ProbabilityDensityFunctionOfInverseGaussianDistribution")
    {
        double x;
        double mu=1;
        double lambda=1;
        double f;
        x=MHL_RandomUniform(0,3);
        //x=0.975;

        //Вызов функции
        f=MHL_ProbabilityDensityFunctionOfInverseGaussianDistribution(x,mu,lambda);

        //Используем полученный результат
        MHL_ShowNumber (x,"Входная переменная", "x");
        //Входная переменная:
        //x=1.10063
        MHL_ShowNumber (mu,"Параметр mu", "mu");
        //Параметр mu:
        //mu=1
        MHL_ShowNumber (lambda,"Параметр lambda", "lambda");
        //Параметр lambda:
        //lambda=1
        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.343916
    }

    if (NameFunction=="MHL_DistributionFunctionOfNormalizedCenteredNormalDistribution")
    {
        double t;
        double f;
        t=MHL_RandomUniform(0,3);

        //Вызов функции
        f=MHL_DistributionFunctionOfNormalizedCenteredNormalDistribution(t,0.001);

        //Используем полученный результат

        MHL_ShowNumber (t,"Параметр", "t");
        //Параметр:
        //t=1.36576
        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.914011
    }

    if (NameFunction=="MHL_DistributionFunctionOfNormalDistribution")
    {
        double x;
        double f;
        x=MHL_RandomUniform(0,3);
        double mu=3;
        double sigma=1;

        //Вызов функции
        f=MHL_DistributionFunctionOfNormalizedCenteredNormalDistribution(x,0.001);

        //Используем полученный результат
        MHL_ShowNumber (x,"Входная переменная", "x");
        //Входная переменная:
        //x=0.527979
        MHL_ShowNumber (mu,"Параметр mu", "mu");
        //Параметр mu:
        //mu=3
        MHL_ShowNumber (sigma,"Параметр sigma", "sigma");
        //Параметр sigma:
        //sigma=1
        MHL_ShowNumber (f,"Значение функции распределения нормального распределения", "f");
        //Значение функции распределения нормального распределения:
        //f=0.701244
    }

    if (NameFunction=="MHL_WilcoxonW")
    {
        int VMHL_Result;

        int VMHL_N1=10;
        int VMHL_N2=10;

        double *a = new double[VMHL_N1];
        double *b = new double[VMHL_N2];
        TMHL_RandomIntVector(a,0.,10.,VMHL_N1);
        TMHL_RandomIntVector(b,0.,10.,VMHL_N2);
        MHL_ShowVectorT(a,VMHL_N1,"Первая выборка","a");
        //Первая выборка:
        //a =
        //6	0	6	1	4	9	6	2	4	8

        MHL_ShowVectorT(b,VMHL_N2,"Вторая выборка","b");
        //Вторая выборка:
        //b =
        //8	1	1	6	0	3	1	1	2	3

        double Q=0.002;
        //Q=0.2;
        MHL_ShowNumber(Q,"Уровень значимости","Q");
        //Уровень значимости:
        //Q=0.002
        //Вызов функции
        VMHL_Result = MHL_WilcoxonW(a, b, VMHL_N1, VMHL_N2, Q);

        //Используем результат
        MHL_ShowNumber(VMHL_Result,"Итог проверка двух выборок ритерием Вилкосена W","VMHL_Result");
        //Итог проверка двух выборок ритерием Вилкосена W:
        //VMHL_Result=1

        delete [] a;
        delete [] b;
    }
    
    if (NameFunction=="TMHL_CompareMeanOfVectors")
    {
        int VMHL_Result;

        int VMHL_N1=10;
        int VMHL_N2=10;

        double *a = new double[VMHL_N1];
        double *b = new double[VMHL_N2];
        TMHL_RandomIntVector(a,0.,100.,VMHL_N1);
        TMHL_RandomIntVector(b,0.,20.,VMHL_N2);
        MHL_ShowVectorT(a,VMHL_N1,"Первая выборка","a");
        //Первая выборка:
        //a =
        //15	91	38	78	68	80	68	83	37	97

        MHL_ShowVectorT(b,VMHL_N2,"Вторая выборка","b");
        //Вторая выборка:
        //b =
        //7	10	0	18	11	4	18	3	12	13

        //Вызов функции
        VMHL_Result = TMHL_CompareMeanOfVectors(a, b, VMHL_N1, VMHL_N2);

        //Используем результат
        MHL_ShowNumber(VMHL_Result,"У какой выборки больше среднеарифметическое","VMHL_Result");
        //У какой выборки больше среднеарифметическое:
        //VMHL_Result=1

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="MHL_LineGeneralForm")
    {
        double A=MHL_RandomUniformInt(1,10);
        double B=MHL_RandomUniformInt(1,10);
        double C=MHL_RandomUniformInt(1,10);

        double x=5;

        int solutionis;

        //Вызов функции
        double y=MHL_LineGeneralForm(x,A,B,C,&solutionis);

        //Используем полученный результат
        MHL_ShowText("Уравнение прямой: "+MHL_NumberToText(A)+"*x+"+MHL_NumberToText(B)+"*y+"+MHL_NumberToText(C)+"=0");
        //Уравнение прямой: 7*x+1*y+7=0.
        MHL_ShowNumber(solutionis,"Найдено ли решение","solutionis");
        //Найдено ли решение:
        //solutionis=1
        if (solutionis!=0)
        {
            MHL_ShowNumber(y,"Значение функции прямой в точке x=5","y");
            //Значение функции прямой в точке x=5:
            //y=-42
        }
    }

    if (NameFunction=="MHL_LineSlopeInterceptForm")
    {
        double k=MHL_RandomUniformInt(1,10);
        double b=MHL_RandomUniformInt(1,10);

        double x=5;

        //Вызов функции
        double y=MHL_LineSlopeInterceptForm(x,k,b);

        //Используем полученный результат
        MHL_ShowText("Уравнение прямой: y="+MHL_NumberToText(k)+"*x+"+MHL_NumberToText(b));
        //Уравнение прямой: y=4*x+1.
        MHL_ShowNumber(y,"Значение функции прямой в точке x=5","y");
        //Значение функции прямой в точке x=5:
        //y=21
    }

    if (NameFunction=="MHL_LineTwoPoint")
    {
        double x1=MHL_RandomUniformInt(1,10);
        double y1=MHL_RandomUniformInt(1,10);
        double x2=MHL_RandomUniformInt(1,10);
        double y2=MHL_RandomUniformInt(1,10);

        double x=5;

        int solutionis;

        //Вызов функции
        double y=MHL_LineTwoPoint(x,x1,y1,x2,y2,&solutionis);

        //Используем полученный результат
        MHL_ShowText("Первая точка: ("+MHL_NumberToText(x1)+"; "+MHL_NumberToText(y1)+")");
        //Первая точка: (6; 3).
        MHL_ShowText("Вторая точка: ("+MHL_NumberToText(x2)+"; "+MHL_NumberToText(y2)+")");
        //Вторая точка: (3; 3).
        MHL_ShowNumber(solutionis,"Найдено ли решение","solutionis");
        //Найдено ли решение:
        //solutionis=1
        if (solutionis!=0)
        {
            MHL_ShowNumber(y,"Значение прямо, проходящей через две указанные точки, в точке x=5","y");
            //Значение прямо, проходящей через две указанные точки, в точке x=5:
            //y=32
        }
    }

    if (NameFunction=="MHL_Parabola")
    {
        double a=MHL_RandomUniformInt(1,10);
        double b=MHL_RandomUniformInt(1,10);
        double c=MHL_RandomUniformInt(1,10);

        double x=5;

        //Вызов функции
        double y=MHL_Parabola(x,a,b,c);

        //Используем полученный результат
        MHL_ShowText("Уравнение параболы: y="+MHL_NumberToText(a)+"*x^2+"+MHL_NumberToText(b)+"*x+"+MHL_NumberToText(c));
        //Уравнение параболы: y=4*x^2+5*x+3.
        MHL_ShowNumber(y,"Значение функции параболы в точке x=5","y");
        //Значение функции параболы в точке x=5:
        //y=128
    }

    if (NameFunction=="MHL_BinaryGeneticAlgorithmWDPOfNOfGPS")
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
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_BinaryGeneticAlgorithmWDPOfNOfGPS (ParametersOfAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        //Как прошел запуск:
        //VMHL_Success=1

        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            //Значение функции пригодности:
            //ValueOfFitnessFunction=47
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="MHL_RealGeneticAlgorithmWDPOfNOfGPS")
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
        TMHL_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        TMHL_FillVector(Right,ChromosomeLength,5.);
        TMHL_FillVector(NumberOfParts,ChromosomeLength,TMHL_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_RealGeneticAlgorithmWDPOfNOfGPS (ParametersOfAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //2.00226	1.98883

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение целовой функции","ValueOfFitnessFunction");
            //Значение целовой функции:
            //ValueOfFitnessFunction=-0.000129856
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="MHL_RealGeneticAlgorithmWDTS")
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
        TMHL_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        TMHL_FillVector(Right,ChromosomeLength,5.);
        TMHL_FillVector(NumberOfParts,ChromosomeLength,TMHL_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_RealGeneticAlgorithmWDTS (ParametersOfAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //2.00226	2.00134

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение целовой функции","ValueOfFitnessFunction");
            //Значение целовой функции:
            //ValueOfFitnessFunction=-6.90296e-06
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="MHL_BinaryGeneticAlgorithmWDTS")
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
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_BinaryGeneticAlgorithmWDTS (ParametersOfAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        //Как прошел запуск:
        //VMHL_Success=1

        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1


            MHL_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            //Значение функции пригодности:
            //ValueOfFitnessFunction=49
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="TMHL_SinglepointCrossoverWithCopying")
    {
        int VMHL_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VMHL_N];
        int *Parent2;
        Parent2=new int[VMHL_N];
        int *Child;
        Child=new int[VMHL_N];
        TMHL_RandomBinaryVector(Parent1,VMHL_N);
        TMHL_RandomBinaryVector(Parent2,VMHL_N);

        //Получим потомка Child
        TMHL_SinglepointCrossoverWithCopying(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0	1	1	0	0	1	0	1	1	1

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	0	0	1	0	1	0	0	0	0

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0	1	1	0	0	1	0	1	1	1

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="TMHL_TwopointCrossoverWithCopying")
    {
        int VMHL_N=10; //Размер массива (число строк)
        int *Parent1;
        Parent1=new int[VMHL_N];
        int *Parent2;
        Parent2=new int[VMHL_N];
        int *Child;
        Child=new int[VMHL_N];
        TMHL_RandomBinaryVector(Parent1,VMHL_N);
        TMHL_RandomBinaryVector(Parent2,VMHL_N);

        //Получим потомка Child
        TMHL_TwopointCrossoverWithCopying(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //1	1	0	0	1	1	0	0	0	0

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0	1	1	0	0	1	0	0	1	0

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0	1	1	0	0	1	0	0	1	0

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_BinaryGeneticAlgorithmWCC")
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
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_BinaryGeneticAlgorithmWCC (Parameters,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        //Как прошел запуск:
        //VMHL_Success=1

        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=50
        }

        delete [] Parameters;
        delete [] Decision;
    }

    if (NameFunction=="MHL_RealGeneticAlgorithmWCC")
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
        TMHL_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        TMHL_FillVector(Right,ChromosomeLength,5.);
        TMHL_FillVector(NumberOfParts,ChromosomeLength,TMHL_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_RealGeneticAlgorithmWCC (Parameters,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //2.0105	2.00195
            MHL_ShowNumber(ValueOfFitnessFunction,"Значение целевой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction=-0.000114024
        }

        delete [] Parameters;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="MHL_TestFunction_AdditivePotential")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-5,5);
        y=MHL_RandomUniform(-5,5);

        //Вызываем функцию
        f=MHL_TestFunction_AdditivePotential(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-2.87701

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-0.443955

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-0.64441
    }

    if (NameFunction=="MHL_TestFunction_MultiplicativePotential")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-5,5);
        y=MHL_RandomUniform(-5,5);

        //Вызываем функцию
        f=MHL_TestFunction_MultiplicativePotential(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=0.520743

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-4.96242

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-0.113219
    }

    if (NameFunction=="MHL_BinaryGeneticAlgorithmTournamentSelectionWithReturn")
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
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_BinaryGeneticAlgorithmTournamentSelectionWithReturn (ParametersOfAlgorithm,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        //Как прошел запуск:
        //VMHL_Success=1

        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            //Значение функции пригодности:
            //ValueOfFitnessFunction=47
        }
        delete [] ParametersOfAlgorithm;
        delete [] Decision;
    }

    if (NameFunction=="MHL_RealGeneticAlgorithmTournamentSelectionWithReturn")
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
        TMHL_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        TMHL_FillVector(Right,ChromosomeLength,5.);
        TMHL_FillVector(NumberOfParts,ChromosomeLength,TMHL_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_RealGeneticAlgorithmTournamentSelectionWithReturn (ParametersOfAlgorithm,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //2.00226	1.98883

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение целовой функции","ValueOfFitnessFunction");
            //Значение целевой функции:
            //ValueOfFitnessFunction=-0.000129856
        }

        delete [] ParametersOfAlgorithm;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

    if (NameFunction=="MHL_TestFunction_ReverseGriewank")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-10,10);
        y=MHL_RandomUniform(-10,10);

        //Вызываем функцию
        f=MHL_TestFunction_ReverseGriewank(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=9.39884

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-8.80345

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.26129
    }

    if (NameFunction=="MHL_TestFunction_HyperEllipsoid")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-5,5);
        f=MHL_TestFunction_HyperEllipsoid(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //1.39903
        //1.96538

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=17.4082

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_RotatedHyperEllipsoid")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-5,5);
        f=MHL_TestFunction_RotatedHyperEllipsoid(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //-0.933898
        //-1.2216

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=5.51833

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_Wave")
    {
        double x;
        double f;
        x=MHL_RandomUniform(-2,2);

        //Вызываем функцию
        f=MHL_TestFunction_Wave(x);

        MHL_ShowNumber (x,"Вещественная переменная", "x");
        //Вещественная переменная:
        //x=0.802021

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.515755
    }

    if (NameFunction=="MHL_TestFunction_Multiextremal")
    {
        double x;
        double f;
        x=MHL_RandomUniform(-2,2);
        //x=0.954451617;

        //Вызываем функцию
        f=MHL_TestFunction_Multiextremal(x);

        MHL_ShowNumber (x,"Вещественная переменная", "x");
        //Вещественная переменная:
        //x=1.112

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=5.46058
    }

    if (NameFunction=="MHL_TestFunction_Multiextremal2")
    {
        double x;
        double f;
        x=MHL_RandomUniform(-2,2);
        x=-0.993263;

        //Вызываем функцию
        f=MHL_TestFunction_Multiextremal2(x);

        MHL_ShowNumber (x,"Вещественная переменная", "x");
        //Вещественная переменная:
        //x=-0.00666742

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=1.0641
    }

    if (NameFunction=="MHL_TestFunction_Sombrero")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-20,20);
        y=MHL_RandomUniform(-20,20);

        //Вызываем функцию
        f=MHL_TestFunction_Sombrero(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-3.26381

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-0.836133

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.938425
    }

    if (NameFunction=="MHL_TestFunction_Himmelblau")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-5,5);
        y=MHL_RandomUniform(-5,5);

        //Вызываем функцию
        f=MHL_TestFunction_Himmelblau(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=1.8744

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=0.39062

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=75.0844
    }

    if (NameFunction=="MHL_TestFunction_Katnikov")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-5,5);
        y=MHL_RandomUniform(-5,5);

        //Вызываем функцию
        f=MHL_TestFunction_Katnikov(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-1.44256

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-3.16906

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=11.5793
    }

    if (NameFunction=="MHL_TestFunction_Multiextremal3")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-5,5);
        y=MHL_RandomUniform(-5,5);

        //Вызываем функцию
        f=MHL_TestFunction_Multiextremal3(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=2.68873

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=0.520861

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=10.8962
    }

    if (NameFunction=="MHL_TestFunction_Multiextremal4")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(0,4);
        y=MHL_RandomUniform(0,4);

        //Вызываем функцию
        f=MHL_TestFunction_Multiextremal4(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=2.6604

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=2.56989

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=8.82495
    }

    if (NameFunction=="MHL_TestFunction_StepFunction")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-5,5);
        f=MHL_TestFunction_StepFunction(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        //Входной вектор:
        //Входной вектор:
        //x =
        //-0.413264
        //-0.141813

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-0.444923

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_Rana")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-512,512);
        y=MHL_RandomUniform(-512,512);

        //Вызываем функцию
        f=MHL_TestFunction_Rana(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-169.488

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-458.027

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=145.161
    }

    if (NameFunction=="MHL_TestFunction_ShekelsFoxholes")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-50,50);
        y=MHL_RandomUniform(-50,50);

        //Вызываем функцию
        f=MHL_TestFunction_ShekelsFoxholes(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-1.42869

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=-6.40351

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=496.009
    }

    if (NameFunction=="MHL_TestFunction_EggHolder")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-512,512);
        y=MHL_RandomUniform(-512,512);

        //Вызываем функцию
        f=MHL_TestFunction_EggHolder(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=367.682

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=464.74

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-287.643
    }

    if (NameFunction=="MHL_TestFunction_RastriginWithChange")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-16,16);
        y=MHL_RandomUniform(-16,16);

        //Вызываем функцию
        f=MHL_TestFunction_RastriginWithChange(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=12.4601

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=5.36642

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=31.4576
    }

    if (NameFunction=="MHL_TestFunction_RastriginWithTurning")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-16,16);
        y=MHL_RandomUniform(-16,16);

        //Вызываем функцию
        f=MHL_TestFunction_RastriginWithTurning(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=-7.1266

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=11.4531

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=10.3461
    }

    if (NameFunction=="MHL_TestFunction_Schwefel")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-500,500);


        //Вызов функции
        f=MHL_TestFunction_Schwefel(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //169.715
        //410.499

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=357.17

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_Griewangk")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-16,16);

        //Вызов функции
        f=MHL_TestFunction_Griewangk(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //7.82863
        //12.7969

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=1.07984

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_InvertedRosenbrock")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-5,5);
        y=MHL_RandomUniform(-5,5);

        //Вызываем функцию
        f=MHL_TestFunction_InvertedRosenbrock(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=4.95843

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=4.1078

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=-0.0375447
    }

    if (NameFunction=="MHL_TestFunction_GaussianQuartic")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-2,2);

        //Вызов функции
        f=MHL_TestFunction_GaussianQuartic(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //1.82905
        //-1.81438

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=33.8315

        delete[] x;
    }

    if (NameFunction=="MHL_TestFunction_RastriginNovgorod")
    {
        double *x;
        double f;
        int VMHL_N=2;
        x=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) x[i]=MHL_RandomUniform(-2,2);

        //Вызов функции
        f=MHL_TestFunction_RastriginNovgorod(x,VMHL_N);

        MHL_ShowVector (x,VMHL_N,"Входной вектор", "x");
        //Входной вектор:
        //x =
        //-1.15942
        //1.19803

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=3.42316

        delete[] x;
    }

    if (NameFunction=="TMHL_AlmostZero")
    {
        double y=0.000000001;
        bool Zero;

        //Вызов функции
        Zero=TMHL_AlmostZero(y);

        //Используем полученный результат
        MHL_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=1e-09
        MHL_ShowNumber(Zero,"Является ли почти нулем?","Zero");
        //Является ли почти нулем?:
        //Zero=1

        y=0.01;

        //Вызов функции
        Zero=TMHL_AlmostZero(y);

        //Используем полученный результат
        MHL_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=0.01
        MHL_ShowNumber(Zero,"Является ли почти нулем?","Zero");
        //Является ли почти нулем?:
        //Zero=0

        y=0;

        //Вызов функции
        Zero=TMHL_AlmostZero(y);

        //Используем полученный результат
        MHL_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=0
        MHL_ShowNumber(Zero,"Является ли почти нулем?","Zero");
        //Является ли почти нулем?:
        //Zero=1

        y=1;

        //Вызов функции
        Zero=TMHL_AlmostZero(y);

        //Используем полученный результат
        MHL_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=1
        MHL_ShowNumber(Zero,"Является ли почти нулем?","Zero");
        //Является ли почти нулем?:
        //Zero=0
    }

    if (NameFunction=="MHL_QuadraticEquationCount")
    {
        double a=MHL_RandomUniformInt(1,10);
        double b=MHL_RandomUniformInt(1,10);
        double c=MHL_RandomUniformInt(1,10);
        double x1;
        double x2;

        int Result=MHL_QuadraticEquationCount(a,b,c,&x1,&x2);

        //Используем полученный результат
        MHL_ShowText("Квадратное уравнение: "+MHL_NumberToText(a)+"x^2+"+MHL_NumberToText(b)+"x+"+MHL_NumberToText(c)+"=0");
        //Квадратное уравнение: 1x^2+4x+4=0.
        MHL_ShowNumber(Result,"Сколько решений найдено","Result");
        //Сколько решений найдено:
        //Result=1
        if (Result>=1)
        {
            MHL_ShowNumber(x1,"Первый корень квадратного уравнения","x1");
            //Первый корень квадратного уравнения:
            //x1=-2
            MHL_ShowNumber(x2,"Второй корень квадратного уравнения","x2");
            //Второй корень квадратного уравнения:
            //x2=-2
        }
    }

    if (NameFunction=="TMHL_AlmostEqual")
    {
        double x=0;
        double y=0.000000001;
        bool Equal;

        //Вызов функции
        Equal=TMHL_AlmostEqual(x,y);

        //Используем полученный результат
        MHL_ShowNumber(x,"Проверяемое число","x");
        //Проверяемое число:
        //x=0
        MHL_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //y=1e-09
        MHL_ShowNumber(Equal,"Являются ли почти равными?","Equal");
        //Являются ли почти равными?:
        //Equal=1

        x=1;
        y=2;
        //Вызов функции
        Equal=TMHL_AlmostEqual(x,y);
        //Используем полученный результат
        MHL_ShowNumber(x,"Проверяемое число","x");
        //Проверяемое число:
        //x=1
        MHL_ShowNumber(y,"Проверяемое число","y");
        //Проверяемое число:
        //x=1
        MHL_ShowNumber(Equal,"Являются ли почти равными?","Equal");
        //Являются ли почти равными?:
        //Equal=0
    }

    if (NameFunction=="TMHL_UncorrectedVariance")
    {
        int VMHL_N=10;//Размер массива
        double *x;
        x=new double[VMHL_N];
        //Заполним случайными числами
        MHL_RandomRealVector (x,0,10,VMHL_N);

        //Вызов функции
        double UncorrectedVariance=TMHL_UncorrectedVariance(x,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Массив", "x");
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

        MHL_ShowNumber (UncorrectedVariance,"Значение выборочной неисправленной дисперсии", "UncorrectedVariance");
        //Значение выборочной неисправленной дисперсии:
        //UncorrectedVariance=9.25051

        delete [] x;
    }

    if (NameFunction=="MHL_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything")
    {
        double Result=MHL_AnswerToTheUltimateQuestionOfLifeTheUniverseAndEverything();

        //Используем полученный результат
        MHL_ShowNumber(Result,"Ответ на главный вопрос жизни, вселенной и всего такого","Ответ");
        //Ответ на главный вопрос жизни, вселенной и всего такого:
        //Ответ=42
    }

    if (NameFunction=="MHL_MeaningOfLife")
    {
        double Result=MHL_MeaningOfLife();

        //Используем полученный результат
        MHL_ShowNumber(Result,"Смысл жизни","Ответ");
        //Смысл жизни:
        //Ответ=42
    }

    if (NameFunction=="MHL_SinglepointCrossoverForReal")
    {
        int VMHL_N=10; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_SinglepointCrossoverForReal(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.92261	0.684314	0.891158	0.312732	0.640667	0.406768	0.228042	0.180759	0.394544	0.88495

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.856881	0.134294	0.985216	0.254506	0.456079	0.330734	0.78648	0.257115	0.609472	0.868141

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.92261	0.684314	0.891158	0.312732	0.456079	0.330734	0.78648	0.257115	0.609472	0.868141

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_TwopointCrossoverForReal")
    {
        int VMHL_N=10; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_TwopointCrossoverForReal(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.301053	0.64133	0.815178	0.727049	0.426111	0.119812	0.720018	0.484514	0.948253	0.489644

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.566543	0.972537	0.575658	0.887848	0.937234	0.772248	0.982688	0.931731	0.480371	0.562743

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.301053	0.64133	0.815178	0.887848	0.937234	0.772248	0.982688	0.484514	0.948253	0.489644

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_UniformCrossoverForReal")
    {
        int VMHL_N=10; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_UniformCrossoverForReal(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.872271	0.400017	0.382867	0.0215583	0.195993	0.0210766	0.546082	0.540188	0.448846	0.22661

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.972843	0.656896	0.892507	0.438632	0.1083	0.982196	0.376142	0.285289	0.411732	0.681029

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Полученный потомок:
        //Child =
        //0.972843	0.400017	0.382867	0.0215583	0.195993	0.0210766	0.546082	0.285289	0.448846	0.22661

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="TMHL_MeanOfUpperFilter")
    {
        int i;
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniform(0,10);

        double UpperFilter=9;

        double Mean=TMHL_Mean(a,VMHL_N);

        //Вызов функции
        double MeanOfUpperFilter=TMHL_MeanOfUpperFilter(a,VMHL_N,UpperFilter);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Массив", "a");
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

        MHL_ShowNumber (UpperFilter,"Значение верхнего фильтра", "UpperFilter");
        //Значение верхнего фильтра:
        //UpperFilter=9

        MHL_ShowNumber (Mean,"Среднее арифметическое массива", "Mean");
        //Среднее арифметическое массива:
        ///Mean=6.11094

        MHL_ShowNumber (MeanOfUpperFilter,"Среднее арифметическое массива с верхним фильтром", "MeanOfUpperFilter");
        //Среднее арифметическое массива с верхним фильтром:
        //MeanOfUpperFilter=4.69698

        delete [] a;
    }

    if (NameFunction=="TMHL_MeanOfLowerFilter")
    {
        int i;
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniform(0,10);

        double LowerFilter=1;

        double Mean=TMHL_Mean(a,VMHL_N);

        //Вызов функции
        double MeanOfLowerFilter=TMHL_MeanOfLowerFilter(a,VMHL_N,LowerFilter);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Массив", "a");
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

        MHL_ShowNumber (LowerFilter,"Значение нижнего фильтра", "LowerFilter");
        //Значение нижнего фильтра:
        //LowerFilter=1

        MHL_ShowNumber (Mean,"Среднее арифметическое массива", "Mean");
        //Среднее арифметическое массива:
        //Mean=5.57397

        MHL_ShowNumber (MeanOfLowerFilter,"Среднее арифметическое массива с нижним фильтром", "MeanOfLowerFilter");
        //Среднее арифметическое массива с нижним фильтром:
        //MeanOfLowerFilter=6.18932

        delete [] a;
    }

    if (NameFunction=="TMHL_MeanOfFilter")
    {
        int i;
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
            a[i]=MHL_RandomUniform(0,10);

        double LowerFilter=1;

        double UpperFilter=9;

        double Mean=TMHL_Mean(a,VMHL_N);

        //Вызов функции
        double MeanOfFilter=TMHL_MeanOfFilter(a,VMHL_N, UpperFilter, LowerFilter);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Массив", "a");
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

        MHL_ShowNumber (LowerFilter,"Значение нижнего фильтра", "LowerFilter");
        //Значение нижнего фильтра:
        //LowerFilter=1

        MHL_ShowNumber (UpperFilter,"Значение верхнего фильтра", "UpperFilter");
        //Значение верхнего фильтра:
        //UpperFilter=9

        MHL_ShowNumber (Mean,"Среднее арифметическое массива", "Mean");
        //Среднее арифметическое массива:
        //Mean=4.53549

        MHL_ShowNumber (MeanOfFilter,"Среднее арифметическое массива с фильтром", "MeanOfFilter");
        //Среднее арифметическое массива с фильтром:
        //MeanOfFilter=5.07057

        delete [] a;
    }

    if (NameFunction=="MHL_ArithmeticalCrossoverForReal")
    {
        int VMHL_N=10; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_ArithmeticalCrossoverForReal(Parent1,Parent2,Child,0.5,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.332926	0.899553	0.469617	0.89417	0.510588	0.261183	0.0920975	0.599565	0.663209	0.544152
        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.084834	0.633822	0.814498	0.211601	0.753767	0.815395	0.82197	0.817619	0.543505	0.754058

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.20888	0.766688	0.642057	0.552885	0.632177	0.538289	0.457034	0.708592	0.603357	0.649105

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_TestFunction_Bosom")
    {
        double x;
        double y;
        double f;
        x=MHL_RandomUniform(-12,12);
        y=MHL_RandomUniform(-12,12);

        //Вызываем функцию
        f=MHL_TestFunction_Bosom(x,y);

        MHL_ShowNumber (x,"Первая вещественная переменная", "x");
        //Первая вещественная переменная:
        //x=6.33755

        MHL_ShowNumber (y,"Вторая вещественная переменная", "y");
        //Вторая вещественная переменная:
        //y=10.0335

        MHL_ShowNumber (f,"Значение функции", "f");
        //Значение функции:
        //f=0.173283
    }

    if (NameFunction=="MHL_FlatCrossoverForReal")
    {
        int VMHL_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_FlatCrossoverForReal(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.53608	0.642251	0.592985	0.496914	0.869165

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.865619	0.479102	0.872257	0.270094	0.567692


        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.86188	0.559004	0.60677	0.367834	0.737273

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_GeometricalCrossoverForReal")
    {
        int VMHL_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_GeometricalCrossoverForReal(Parent1,Parent2,Child,0.5,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.237303	0.742526	0.401953	0.794393	0.450861

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.0427865	0.784436	0.736516	0.875728	0.871102

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.100764	0.763194	0.5441	0.83407	0.626694

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_BLXCrossoverForReal")
    {
        int VMHL_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_BLXCrossoverForReal(Parent1,Parent2,Child,0.5,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.00492424	0.904672	0.495609	0.277354	0.157748

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.0642395	0.216884	0.270904	0.602833	0.0286132

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.0163621	0.797608	0.169474	0.73645	0.114127

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_LinearCrossoverForReal")
    {
        int VMHL_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_LinearCrossoverForReal(Parent1,Parent2,Child,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.677296	0.808882	0.182892	0.776259	0.82249

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.91462	0.788695	0.563462	0.214182	0.603119

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.558634	0.818976	-0.00739218	1.0573	0.932176

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_ExtendedLineForReal")
    {
        int VMHL_N=5; //Размер массива (число строк)
        double *Parent1;
        Parent1=new double[VMHL_N];
        double *Parent2;
        Parent2=new double[VMHL_N];
        double *Child;
        Child=new double[VMHL_N];
        MHL_RandomRealVector(Parent1,0,1,VMHL_N);
        MHL_RandomRealVector(Parent2,0,1,VMHL_N);

        //Получим потомка Child
        MHL_ExtendedLineForReal(Parent1,Parent2,Child,0.5,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (Parent1,VMHL_N,"Первый родитель", "Parent1");
        //Первый родитель:
        //Parent1 =
        //0.0407698	0.221488	0.912053	0.845252	0.219005

        MHL_ShowVectorT (Parent2,VMHL_N,"Второй родитель", "Parent2");
        //Второй родитель:
        //Parent2 =
        //0.388894	0.841718	0.741151	0.390797	0.0401433

        MHL_ShowVectorT (Child,VMHL_N,"Полученный потомок", "Child");
        //Полученный потомок:
        //Child =
        //0.214832	0.531603	0.826602	0.618024	0.129574

        delete [] Parent2;
        delete [] Parent1;
        delete [] Child;
    }

    if (NameFunction=="MHL_SeparateVectorLimitOnProductElements")
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

        ElementsInPart = MHL_SeparateVectorLimitOnProductElements(Vector, Order, Limit, N);

        MHL_ShowVectorT(Vector,N,"Массив","Vector");
        //Массив:
        //Vector =
        //2	3	4	2	3	4	2	4

        MHL_ShowVectorT(Order,N,"Порядок элементов в новых двух группах","Order");
        //Порядок элементов в новых двух группах:
        //Order =
        //0	3	6	1	4	2	5	7

        MHL_ShowNumber(ElementsInPart,"Количество элементов в первой группе","ElementsInPart");
        //Количество элементов в первой группе:
        //ElementsInPart=3

        delete [] Vector;
        delete [] Order;
    }

    if (NameFunction=="MHL_BinaryGeneticAlgorithmTwiceGenerations")
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
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_BinaryGeneticAlgorithmTwiceGenerations (Parameters,Func, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        //Как прошел запуск:
        //VMHL_Success=1

        if (VMHL_Success==1)
        {
            MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
            //Найденное решение:
            //Decision =
            //1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

            MHL_ShowNumber(ValueOfFitnessFunction,"Значение функции пригодности","ValueOfFitnessFunction");
            // Значение функции пригодности:
            //ValueOfFitnessFunction=50
        }

        delete [] Parameters;
        delete [] Decision;
    }

    if (NameFunction=="MHL_RealGeneticAlgorithmTwiceGenerations")
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
        TMHL_FillVector(Left,ChromosomeLength,-5.);//Пусть будет интервал [-3;3]
        TMHL_FillVector(Right,ChromosomeLength,5.);
        TMHL_FillVector(NumberOfParts,ChromosomeLength,TMHL_PowerOf(2,15)-1);//Делим на 32768-1 частей каждую вещественную координату

        double *Decision;//вещественное решение
        Decision=new double[ChromosomeLength];
        double ValueOfFitnessFunction;//значение целевой функции в точке Decision
        int VMHL_Success=0;//Успешен ли будет запуск cГА

        //Запуск алгоритма
        VMHL_Success=MHL_RealGeneticAlgorithmTwiceGenerations (Parameters,NumberOfParts,Left,Right,Func2, Decision, &ValueOfFitnessFunction);

        //Используем полученный результат
        MHL_ShowNumber(VMHL_Success,"Как прошел запуск","VMHL_Success");
        if (VMHL_Success==1)
         {
         MHL_ShowVectorT(Decision,ChromosomeLength,"Найденное решение","Decision");
         //Найденное решение:
         //Decision =
         //1.99951	1.99646
         MHL_ShowNumber(ValueOfFitnessFunction,"Значение целевой функции","ValueOfFitnessFunction");
         //Значение целевой функции:
         //ValueOfFitnessFunction=-1.27703e-05
         }

        delete [] Parameters;
        delete [] Decision;
        delete [] Left;
        delete [] Right;
        delete [] NumberOfParts;
    }

}
//---------------------------------------------------------------------------

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    QRegExp regExp(QString("*%1*").arg(arg1), Qt::CaseInsensitive,
                   QRegExp::Wildcard);
    proxyModelView->setFilterRegExp(regExp);
}
