#ifndef HARRIXQTLIBRARY_H
#define HARRIXQTLIBRARY_H

#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QTextCodec>
#include <QTextEdit>
#include <QDateTime>
#include <QApplication>
#include <typeinfo>
#include <QXmlStreamReader>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Обработка данных, считанных их файла
int HQt_CountOfColsFromQStringList(QStringList QStringListFromFile);
int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile);
int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile, int k);
int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile, int *VHQt_ResultVector);
void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QDate *VHQt_VectorResult);
void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QString *VHQt_VectorResult);
template <class T> void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, T *VHQt_VectorResult);
template <class T> void THQt_ReadMatrixFromQStringList(QStringList QStringListFromFile, T **VHQt_MatrixResult);
template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VHQt_VectorResult1, T *VHQt_VectorResult2);
template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VHQt_VectorResult1, QDate *VHQt_VectorResult2);
template <class T> void THQt_ReadVectorFromQStringList(QStringList QStringListFromFile, T *VHQt_VectorResult);

//Получение строк-выводов по данным
QString HQt_BoolToWord(QString Bool);
QString HQt_BoolToWord(QString Bool, QString No, QString Yes);
QString HQt_BoolToWord(bool Bool);
QString HQt_BoolToWord(bool Bool, QString No, QString Yes);
QString HQt_BoolToWord(int Bool);
QString HQt_BoolToWord(int Bool, QString No, QString Yes);
QString HQt_RandomRussianLetter();
QString HQt_RandomString(int Length);
QString HQt_TryingReduceString(QString text, int MaxSize);
QString HQt_TryingReduceString(QString text);
QString HQt_UniqueName ();
QString HQt_UniqueName (QString BeginString);
QString HQt_UniqueNameOnlyNumbers ();
QString HQt_WriteTime(int t);
QString HQt_WriteTime(qint64 t);

//Работа с алфавитом и переносами
QStringList HQt_BreakdownOfTextWithWordWrap(QString S, int length);
bool HQt_CheckIntolerablePunctuation(QString x);
bool HQt_CheckLetterFromWord(QString x);
bool HQt_CheckRus(QString S);
QStringList HQt_CutToWords(QString S);
QStringList HQt_CutToWordsWithWordWrap(QString S);
int HQt_GetTypeCharEng(QString x);
int HQt_GetTypeCharRus(QString x);
QString HQt_RussianLetter(int i);

//Работа с датами
int HQt_DaysBetweenDates(QDate BeginDate, QDate EndDate);
int HQt_DaysBetweenDates(QString BeginDate, QString EndDate);

//Работа с файлами и папками
bool HQt_CopyFile(QString filename, QString dir);
bool HQt_CopyFile(QString filename, QString dir, bool overwrite);
bool HQt_CopyFile(QString filename, QString dir, bool overwrite, bool dirmake);
bool HQt_DirDelete(QString path);
bool HQt_DirExists(QString path);
void HQt_DirMake(QString path);
bool HQt_FileExists(QString filename);
QString HQt_GetExpFromFilename(QString filename);
QString HQt_GetFilenameFromFullFilename(QString filename);
QString HQt_GetNameFromFilename(QString filename);
QString HQt_ListDirsInDir(QString path);
QStringList HQt_ListDirsInDirQStringList(QString path);
QString HQt_ListFilesInDir(QString path);
QStringList HQt_ListFilesInDirQStringList(QString path);
QString HQt_ReadFile(QString filename);
QStringList HQt_ReadFileToQStringList(QString filename);
bool HQt_RenameFile(QString filename, QString newfilename);
void HQt_SaveFile(QString line, QString filename);

//Работа с цветом
QString THQt_AlphaBlendingColorToColor(double alpha, QString FirstRGB, QString SecondRGB);
QString THQt_ColorFromGradient(double position, QString FirstRGB, QString SecondRGB);
QString THQt_GiveRainbowColorRGB(double position);
void THQt_RGBStringToThreeNumbers(QString RGB, int *R, int *G, int *B);
QString THQt_ThreeNumbersToRGBString(int R, int G, int B);

//Работа со строками и списками строк
QStringList HQt_AddUniqueQStringInQStringList (QStringList StringList, QString String);
bool HQt_IsNumeric(QString x);
int HQt_MaxCountOfQStringList(QStringList x);
bool HQt_NaturalCompareTwoQStrings(const QString& s1,const QString& s2);
QStringList HQt_NaturalSortingQStringList (QStringList StringList);
QString HQt_QStringListToQString(QStringList lines);
double HQt_QStringToNumber (QString x);
double HQt_QStringToNumber (QString x, bool checkcomma);
QStringList HQt_QStringToQStringList(QString line);
int HQt_SearchQStringInQStringList (QStringList StringList, QString String);
QString HQt_StringForLaTeX (QString String);
QString HQt_StringFromLaTeX (QString String);
QString HQt_StringToLabelForLaTeX (QString String);
QString HQt_TextAfterEqualSign (QString String);
QString HQt_TextBeforeEqualSign (QString String);
template <class T> void THQt_VectorToQStringList(T *x, int N);

//Служебные функции
void HQt_Delay(int MSecs);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Обработка данных, считанных их файла
//*****************************************************************
template <class T> void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, T *VHQt_VectorResult)
{
    /*
    Функция считывает данные какого-то k столбца из QStringList в виде матрицы.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     k - номер столбца, начиная с нуля, который считываем;
     VHQt_VectorResult - сюда будем записывать результат считывания столбца из матрицы.
    Возвращаемое значение:
     Количество элементов в столбце. Как только встречает вместо числа символ "-", то функция считает, что вектор закончился.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VHQt_VectorResult.
1	2	6
52	3	96
6.4	7	4
    Второй пример содержимого VHQt_VectorResult.
1	2	6	5
52	3	96	5
-	-	4   2
    Пример использования:
///////////////////////////////////
QString DS=QDir::separator();
QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

QStringList List = HQt_ReadFileToQStringList(path+"5.txt");
int N;
N=HQt_CountOfRowsFromQStringList(List,k);

double *X;
X=new double[N];

int k=2;//номер столбца

THQt_ReadColFromQStringList(List, k, X);

delete [] X;
///////////////////////////////////
    */
    int i,j;
    int N;
    N = HQt_CountOfRowsFromQStringList(QStringListFromFile,k);
    QString A,X;

    for (i=0;i<N;i++)
    {
        A=QStringListFromFile.at(i);
        A=A.trimmed();
        for (j=0;j<k;j++)
        {
            A=A.mid(A.indexOf("\t")+1);
            A=A.trimmed();
        }
        X=A.mid(0,A.indexOf("\t"));
        X=X.trimmed();
        VHQt_VectorResult[i]=X.toDouble();
    }
}
//---------------------------------------------------------------------------

template <class T> void THQt_ReadMatrixFromQStringList(QStringList QStringListFromFile, T **VHQt_MatrixResult)
{
    /*
    Функция считывает данные из QStringList в матрицу.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     VHQt_MatrixResult - сюда будем записывать результат считывания матрицы.
    Возвращаемое значение:
     Отсутствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VHQt_VectorResult.
1	2	6
52	3	96
6.4	7	4
    Второй пример содержимого VHQt_VectorResult.
1	2	6	5
52	3	96	5
-	-	4   2
    Пример использования:
///////////////////////////////////

QString DS=QDir::separator();
QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке
QStringList List = HQt_ReadFileToQStringList(path+"5.txt");

int N,M;
M=HQt_CountOfColsFromQStringList(List);
N=HQt_CountOfRowsFromQStringList(List);

double **X;
X=new double*[N];
for (int i=0;i<N;i++) X[i]=new double[M];

THQt_ReadMatrixFromQStringList(List, X);

for (int i=0;i<N;i++) delete [] X[i];
delete [] X;
///////////////////////////////////
    */
    int i,j;
    int N,M;
    M=HQt_CountOfColsFromQStringList(QStringListFromFile);
    N=HQt_CountOfRowsFromQStringList(QStringListFromFile);
    QString A,X;

    for (i=0;i<N;i++)
        for (j=0;j<M;j++)
            VHQt_MatrixResult[i][j]=0;

    for (i=0;i<N;i++)
    {
        A=QStringListFromFile.at(i);
        A=A.trimmed();
        for (j=0;j<M;j++)
        {
            X=A.mid(0,A.indexOf("\t"));
            A=A.mid(A.indexOf("\t")+1);
            A=A.trimmed();
            VHQt_MatrixResult[i][j]=X.toDouble();
        }
    }
}
//---------------------------------------------------------------------------

template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VHQt_VectorResult1, T *VHQt_VectorResult2)
{
    /*
    Функция считывает данные из QStringList в два вектора.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     VHQt_VectorResult1 - сюда будем записывать результат первого вектора;
     VHQt_VectorResult2 - сюда будем записывать результат второго вектора.
    Возвращаемое значение:
     Отсутствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VHQt_VectorResult.
1	2
52	3
6.4	7
    Пример использования:
///////////////////////////////////

QString DS=QDir::separator();
QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке
int N;
double *x,*y;
QStringList List = HQt_ReadFileToQStringList(path+"2.txt");
N=HQt_CountOfRowsFromQStringList(List);
x=new double [N];
y=new double [N];

THQt_ReadTwoVectorFromQStringList(List,x,y);

delete [] y;
delete [] x;
///////////////////////////////////
    */
    int i;
    int N=QStringListFromFile.count();
    QString A,X1,X2;

    for (i=0;i<N;i++)
    {
        A=QStringListFromFile.at(i);
        A=A.trimmed();
        X1=A;
        X2=A;
        X1=X1.mid(0,X1.lastIndexOf("\t"));
        X2=X2.mid(X2.lastIndexOf("\t"));

        VHQt_VectorResult1[i]=X1.toDouble();
        VHQt_VectorResult2[i]=X2.toDouble();
    }
}
//---------------------------------------------------------------------------
template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VHQt_VectorResult1, QDate *VHQt_VectorResult2)
{
    /*
    Функция считывает данные из QStringList в два вектора (второй вектор - это даты).
    Входные параметры:
     VHQt_VectorResult1 - сюда будем записывать результат первого вектора;
     VHQt_VectorResult2 - сюда будем записывать результат второго вектора (даты).
    Возвращаемое значение:
     Отсутствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VHQt_VectorResult.
33	21.08.2012
32	24.07.2012
31	20.06.2012
    */
    int i;
    int N=QStringListFromFile.count();
    QString A,X1,X2;

    for (i=0;i<N;i++)
    {
        A=QStringListFromFile.at(i);
        A=A.trimmed();
        X1=A;
        X2=A;
        X1=X1.mid(0,X1.lastIndexOf("\t"));
        X2=X2.mid(X2.lastIndexOf("\t"));
        X2=X2.trimmed();

        VHQt_VectorResult1[i]=X1.toDouble();

        int p1=X2.lastIndexOf(".");
        int p2=X2.indexOf(".");

        QDate DBeginDate;
        if ((p1==2)&&(p2==5))
            DBeginDate=QDate::fromString(X2, "yyyy.MM.dd");
        else
            DBeginDate=QDate::fromString(X2, "dd.MM.yyyy");

        VHQt_VectorResult2[i]=DBeginDate;
    }
}
//---------------------------------------------------------------------------

template <class T> void THQt_ReadVectorFromQStringList(QStringList QStringListFromFile, T *VHQt_VectorResult)
{
    /*
    Функция считывает данные из QStringList в вектор.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     VHQt_VectorResult - сюда будем записывать результат.
    Возвращаемое значение:
     Отсутствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VHQt_VectorResult.
1
52
6.45
    Пример использования:
///////////////////////////////////

QString DS=QDir::separator();
QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке
int N;
double *y;
QStringList List = HQt_ReadFileToQStringList(path+"1.txt");
N=HQt_CountOfRowsFromQStringList(List);
y=new double [N];

THQt_ReadVectorFromQStringList(List,y);//считываем

delete [] y;
///////////////////////////////////
    */
    int i;
    int N=QStringListFromFile.count();
    QString A;

    for (i=0;i<N;i++)
    {
        A=QStringListFromFile.at(i);
        A=A.trimmed();
        VHQt_VectorResult[i]=A.toDouble();
    }
}
//---------------------------------------------------------------------------

//*****************************************************************
//Получение строк-выводов по данным
//*****************************************************************
//*****************************************************************
//Работа с алфавитом и переносами
//*****************************************************************
//*****************************************************************
//Работа с датами
//*****************************************************************
//*****************************************************************
//Работа с файлами и папками
//*****************************************************************
//*****************************************************************
//Работа с цветом
//*****************************************************************
//*****************************************************************
//Работа со строками и списками строк
//*****************************************************************
template <class T> void THQt_VectorToQStringList(T *x, int N)
{
    /*
    Функция переводит вектор чисел в QStringList.
    Входные параметры:
     x - переводимый массив.
     N - Количество элементов в массиве.
    Возвращаемое значение:
     Список строк.
*/
    QStringList Result;

    for (int i=0;i<N;i++)
        Result << QString::number(x[i]);

    return Result;
}
//---------------------------------------------------------------------------

//*****************************************************************
//Служебные функции
//*****************************************************************

#endif // HARRIXQTLIBRARY_H