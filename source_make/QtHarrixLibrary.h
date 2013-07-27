#ifndef QTHARRIXLIBRARY_H
#define QTHARRIXLIBRARY_H

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

const QString ColorOfNumber="#3d99c7";//цвет текста цифр, для вывода в HTML

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

QString HQt_ReadFile(QString filename);//Функция считывает текстовой файл в QString.
QStringList HQt_ReadFileToQStringList(QString filename);//Функция считывает текстовой файл в QStringList.
void HQt_SaveFile(QString line, QString filename);//Функция сохраняет QString в текстовой файл.
QString HQt_ListFilesInDir(QString path);//Функция считывает список файлов (включая скрытые) в директории в QString.
QStringList HQt_ListFilesInDirQStringList(QString path);//Функция считывает список файлов (включая скрытые) в директории в QStringList.
QString HQt_ListDirsInDir(QString path);//Функция считывает список директорий в директории в QString.
QStringList HQt_ListDirsInDirQStringList(QString path);//Функция считывает список директорий в директории в QStringList.
QString HQt_GetExpFromFilename(QString filename);//Функция получает расширение файла по его имени.
QStringList HQt_QStringToQStringList(QString line);//Функция переводит QString в QStringList.
QString HQt_QStringListToQString(QStringList lines);//Функция переводит QStringList в QString.
bool HQt_FileExists(QString filename);//Функция проверяет сущестование файла.
QString HQt_GetNameFromFilename(QString filename);//Функция получает имя файла без расширения по его имени.
bool HQt_CopyFile(QString filename, QString dir);//Функция копирует файл filename в папку dir.
bool HQt_CopyFile(QString filename, QString dir, bool overwrite);//Функция копирует файл filename в папку dir, с возможносью перезаписи.
QString HQt_GetFilenameFromFullFilename(QString filename);//Функция получает имя файла по полному пути.
QString HQt_WriteTime(int t);//Функция переводит миллисекунды в строку с описанием сколько это минут, секунд и др.
QString HQt_UniqueName ();//Функция возвращает уникальную строку, которую можно использовать как некий идентификатор.
QString HQt_UniqueName (QString BeginString);//Функция возвращает уникальную строку, которую можно использовать как некий идентификатор.
QString HQt_UniqueNameOnlyNumbers ();//Функция возвращает уникальную строку, которую можно использовать как некий идентификатор. В строке только цифры.
void HQt_Delay(int MSecs);//Функция делает задержку в MSecs миллисекунд.
QString HQt_RandomString(int Length);//Функция генерирует случайную строку из английских больших и малых букв.
int HQt_DaysBetweenDates(QDate BeginDate, QDate EndDate);//Функция определяет сколько дней между двумя датами.
int HQt_DaysBetweenDates(QString BeginDate, QString EndDate);//Функция определяет сколько дней между двумя датами.
QString THQt_ThreeNumbersToRGBString(int R, int G, int B);//Функция переводит три числа в строку RGB типа #25ffb5, как в Photoshop или HTML.
QString THQt_GiveRainbowColorRGB(double position);//Функция выдает код RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента.
void THQt_RGBStringToThreeNumbers(QString RGB, int *R, int *G, int *B);//Функция переводит строку RGB типа #25ffb5 в три числа от 0 до 255, которые кодируют  цвета.
QString THQt_ColorFromGradient(double position, QString FirstRGB, QString SecondRGB);//Функция выдает код RGB из градиента от одного цвета FirstRGB к другому цвету SecondRGB согласно позиции от 0 до 1.
QString THQt_AlphaBlendingColorToColor(double alpha, QString FirstRGB, QString SecondRGB);//Функция накладывает сверху на цвет другой цвет с определенной прозрачностью.
int HQt_CountOfColsFromQStringList(QStringList QStringListFromFile);//Функция подсчитывает сколько столбцов в текстовом файле, который скопировали в QStringListFromFile.
int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile);//Функция подсчитывает сколько строк в текстовом файле, который скопировали в QStringListFromFile.
int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile, int k);//Функция подсчитывает сколько строк в k столбце из текстового файла, который скопировали в QStringListFromFile.
int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile, int *VMHL_ResultVector);//Функция подсчитывает сколько строк в каждом столбце из текстового файла с матрицей, который скопировали в QStringListFromFile.
template <class T> void THQt_ReadVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult);//Функция считывает данные из QStringList в вектор.
template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult1, T *VMHL_VectorResult2);//Функция считывает данные из QStringList в два вектора.
template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult1, QDate *VMHL_VectorResult2);//Функция считывает данные из QStringList в два вектора (второй вектор - это даты).
template <class T> void THQt_ReadMatrixFromQStringList(QStringList QStringListFromFile, T **VMHL_MatrixResult);//Функция считывает данные из QStringList в матрицу.
template <class T> void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, T *VMHL_VectorResult);//Функция считывает данные какого-то k столбца из QStringList в виде матрицы.
void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QDate *VMHL_VectorResult);//Функция считывает данные какого-то k столбца с датами из QStringList в виде матрицы.
void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QString *VMHL_VectorResult);//Функция считывает данные какого-то k столбца с датами из QStringList в виде матрицы.
QString HQt_TextBeforeEqualSign (QString String);//Функция возвращает текст строки до первого знака =.
QString HQt_TextAfterEqualSign (QString String);//Функция возвращает текст строки после первого знака =.

//Для отображения HTML текста
QString HQt_BeginHtml (); //Функция возвращает строку с началом HTML файла, в который другими функциями добавляются иные данные.
QString HQt_EndHtml (); //Функция возвращает строку с концовкой HTML файла, в который другими функциями добавляются иные данные.
QString HQt_ShowText (QString TitleX);//Функция возвращает строку с выводом некоторой строки с HTML кодами. Для добавление в html файл.
QString HQt_ShowSimpleText (QString String);//Функция возвращает строку с выводом некоторой строки с HTML кодами без всякого излишевства. Для добавление в html файл.
QString HQt_ShowAlert (QString String);//Функция возвращает строку с выводом некоторого предупреждения. Для добавление в html файл.
template <class T> QString THQt_ShowNumber (T VMHL_X, QString TitleX, QString NameX);//Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами.
template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);//Функция возвращает строку с выводом некоторый вектора VMHL_Vector с HTML кодами.
template <class T> QString THQt_NumberToText (T VMHL_X);//Функция выводит число VMHL_X в строку.
template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);//Функция возвращает строку с выводом некоторый вектора VMHL_Vector в траснпонированном виде с HTML кодами.
template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);//Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами.
template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);//Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);//Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл. Отличается от основной функцией отсутствием параметра NameLine(название первого графика (для легенды)).
template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);// Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.
template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N);//Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Отличается отсуствием параметров NameLine1 и NameLine2. То есть нет легенды у графика.
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);//Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл. Отличается от основной функции отсутствием булевских переменных - все по умолчанию.
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N);//Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Отличается от основной функции отсутствием булевских переменных и названий графика, осей, линий - все по умолчанию.
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Отличается от основной функции отсутствием легенды, то есть параметров NameLine1, NameLine2.
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Отличается от основной функции отсутствием булевых параметров - все по умолчанию.
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами.Отличается от основной функции отсутствием булевых параметров и подписей - все по умолчанию.
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Первый столбец - это значения вектора X, одинакового для всех графиков. Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Первый столбец - это значения вектора X, одинакового для всех графиков. Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов. Отличается от основной библиотеки отсутствием легенды (нет параметра NewLine).
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Отличается от основной функции отсутствием булевых переменных - все по умолчанию.
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Отличается от основной функции отсутствием булевых переменных и названий осей, графиков - все по умолчанию.
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие значения Y. То есть графики друг от друга независимы. Количество графиков равно половине столбцов в матрице.
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Отличается от основной функции отсутствием легенды на графике.
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл. Отличается от основной функции отсутствием булевых переменных - все по умолчанию.
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M);//Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Отличается от основной функции отсутствием булевых переменных, названий осей, графиков - все по умолчанию.
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Для добавление в html файл.
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Отличается от основной функции отсутствием легенды, то есть параметров NameLine1, NameLine2.
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Отличается от основной функции отсутствием булевых параметров - все по умолчанию.
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2);//Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий. Отличается от основной функции отсутствием булевых параметров и подписей - все по умолчанию.
QString HQt_ReadHdataToHtmlChart (QString filename);//Функция возвращает строку с HTML кодом графика в результате считывания информации из *.hdata. Для добавление в html файл.


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

template <class T> void THQt_ReadVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult)
{
    /*
    Функция считывает данные из QStringList в вектор.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     VMHL_VectorResult - сюда будем записывать результат.
    Возвращаемое значение:
     Отсуствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VMHL_VectorResult.
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
        VMHL_VectorResult[i]=A.toDouble();
    }
}
//---------------------------------------------------------------------------

template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult1, T *VMHL_VectorResult2)
{
    /*
    Функция считывает данные из QStringList в два вектора.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     VMHL_VectorResult1 - сюда будем записывать результат первого вектора;
     VMHL_VectorResult2 - сюда будем записывать результат второго вектора.
    Возвращаемое значение:
     Отсуствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VMHL_VectorResult.
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

        VMHL_VectorResult1[i]=X1.toDouble();
        VMHL_VectorResult2[i]=X2.toDouble();
    }
}
//---------------------------------------------------------------------------

template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult1, QDate *VMHL_VectorResult2)
{
    /*
    Функция считывает данные из QStringList в два вектора (второй вектор - это даты).
    Входные параметры:
     VMHL_VectorResult1 - сюда будем записывать результат первого вектора;
     VMHL_VectorResult2 - сюда будем записывать результат второго вектора (даты).
    Возвращаемое значение:
     Отсуствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VMHL_VectorResult.
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

        VMHL_VectorResult1[i]=X1.toDouble();

        int p1=X2.lastIndexOf(".");
        int p2=X2.indexOf(".");

        QDate DBeginDate;
        if ((p1==2)&&(p2==5))
            DBeginDate=QDate::fromString(X2, "yyyy.MM.dd");
        else
            DBeginDate=QDate::fromString(X2, "dd.MM.yyyy");

        VMHL_VectorResult2[i]=DBeginDate;
    }
}
//---------------------------------------------------------------------------

template <class T> void THQt_ReadMatrixFromQStringList(QStringList QStringListFromFile, T **VMHL_MatrixResult)
{
    /*
    Функция считывает данные из QStringList в матрицу.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     VMHL_MatrixResult - сюда будем записывать результат считывания матрицы.
    Возвращаемое значение:
     Отсуствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VMHL_VectorResult.
1	2	6
52	3	96
6.4	7	4
    Второй пример содержимого VMHL_VectorResult.
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
            VMHL_MatrixResult[i][j]=0;

    for (i=0;i<N;i++)
    {
        A=QStringListFromFile.at(i);
        A=A.trimmed();
        for (j=0;j<M;j++)
        {
            X=A.mid(0,A.indexOf("\t"));
            A=A.mid(A.indexOf("\t")+1);
            A=A.trimmed();
            VMHL_MatrixResult[i][j]=X.toDouble();
        }
    }
}
//---------------------------------------------------------------------------

template <class T> void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, T *VMHL_VectorResult)
{
    /*
    Функция считывает данные какого-то k столбца из QStringList в виде матрицы.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     k - номер столбца, начиная с нуля, который считываем;
     VMHL_VectorResult - сюда будем записывать результат считывания столбца из матрицы.
    Возвращаемое значение:
     Количество элементов в столбце. Как только встречает вместо числа символ "-", то функция считает, что вектор закончился.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VMHL_VectorResult.
1	2	6
52	3	96
6.4	7	4
    Второй пример содержимого VMHL_VectorResult.
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
        VMHL_VectorResult[i]=X.toDouble();
    }
}
//---------------------------------------------------------------------------

//Функции для получения HTML кода для вывода в webView

template <class T> QString THQt_ShowNumber (T VMHL_X, QString TitleX, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result="<p><b>"+TitleX+":</b><br>";

    VMHL_Result+=NameX+"=<b><font color=\""+ColorOfNumber+"\">"+QString::number(VMHL_X)+"</font></b></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_NumberToText (T VMHL_X)
{
    /*
    Функция выводит число VMHL_X в строку.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VMHL_Result;
    VMHL_Result="<b><font color=\""+ColorOfNumber+"\">"+QString::number(VMHL_X)+"</font></b>";
    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VMHL_Result;
    VMHL_Result+="<style type='text/css'>.matrix td{text-align: center;line-height: 1.2em;padding: 0 1ex 0ex 1ex;}td.lbrak { width: 0.8ex;font-size: 50%;border: solid thin black;border-right: none;}td.rbrak { width: 0.8ex; font-size: 50%;border: solid thin black;border-left: none;}.matrixbrak td { line-height: 1.6; }</style>\n";

    VMHL_Result+="<p><b>"+TitleVector+":</b>";

    VMHL_Result+="<table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<font style=\"text-decoration:overline;\">";
    VMHL_Result+=NameVector;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table cellpadding=\"0\" cellspacing=\"0\" class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table cellpadding=\"0\" cellspacing=\"0\" class=\"matrix\">\n";

    for (int i=0;i<VMHL_N;i++)
    {
        VMHL_Result+="<tr>\n";
        VMHL_Result+="<td><b><font color=\""+ColorOfNumber+"\">"+QString::number(VMHL_Vector[i])+"</font></b></td>\n";

        VMHL_Result+="</tr>\n";
    }

    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";
    VMHL_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некотоого вектора VMHL_Vector в траснпонированном виде с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VMHL_Result;
    VMHL_Result+="<style type='text/css'>.matrix td{text-align: center;line-height: 1.2em;padding: 0 1ex 0ex 1ex;}td.lbrak { width: 0.8ex;font-size: 50%;border: solid thin black;border-right: none;}td.rbrak { width: 0.8ex; font-size: 50%;border: solid thin black;border-left: none;}.matrixbrak td { line-height: 1.6; }</style>\n";

    VMHL_Result+="<p><b>"+TitleVector+":</b>";

    VMHL_Result+="<table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<font style=\"text-decoration:overline;\">";
    VMHL_Result+=NameVector;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table cellpadding=\"0\" cellspacing=\"0\" class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table cellpadding=\"0\" cellspacing=\"0\" class=\"matrix\">\n";

    VMHL_Result+="<tr>\n";
    for (int i=0;i<VMHL_N;i++)
        VMHL_Result+="<td><b><font color=\""+ColorOfNumber+"\">"+QString::number(VMHL_Vector[i])+"</font></b></td>\n";
    VMHL_Result+="</tr>\n";

    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";
    VMHL_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";
    VMHL_Result+="<td style=\"text-align:left;vertical-align:top;margin:5px;\">ᵀ<br>&nbsp;</td>\n";

    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;

    VMHL_Result+="<style type='text/css'>.matrix td{text-align: center;line-height: 1.2em;padding: 0 1ex 0ex 1ex;}td.lbrak { width: 0.8ex;font-size: 50%;border: solid thin black;border-right: none;}td.rbrak { width: 0.8ex; font-size: 50%;border: solid thin black;border-left: none;}.matrixbrak td { line-height: 1.6; }</style>\n";

    VMHL_Result+="<p><b>"+TitleMatrix+":</b>";

    VMHL_Result+="<table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<font style=\"text-decoration:overline;\">";
    VMHL_Result+=NameMatrix;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table cellpadding=\"0\" cellspacing=\"0\" class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table cellpadding=\"0\" cellspacing=\"0\" class=\"matrix\">\n";

    for (int i=0;i<VMHL_N;i++)
    {
        VMHL_Result+="<tr>\n";
        for (int j=0;j<VMHL_M;j++)
            VMHL_Result+="<td><b><font color=\""+ColorOfNumber+"\">"+QString::number(VMHL_Matrix[i][j])+"</font></b></td>\n";

        VMHL_Result+="</tr>\n";
    }

    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";
    VMHL_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table>\n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="</tr>\n";
    VMHL_Result+="</table></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine=true, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - название первого графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синию.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y","линия",true,true,true,true,false);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString Color="#97bbcd";
    QString HighlightColor="#3c7693";
    QString CoordinateColor="#88969c";
    QString RedColor="#ff0000";
    QString HighlightRedColor="#8b0909";

    //посчитаем гарницы изменения параметров
    T MinX=VMHL_VectorX[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorX[i]<MinX)
            MinX=VMHL_VectorX[i];

    T MinY=VMHL_VectorY[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY[i]<MinY)
            MinY=VMHL_VectorY[i];

    T MaxX=VMHL_VectorX[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorX[i]>MaxX)
            MaxX=VMHL_VectorX[i];

    T MaxY=VMHL_VectorY[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY[i]>MaxY)
            MaxY=VMHL_VectorY[i];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;

    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;

    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VMHL_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VMHL_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    //QString UniqueName=HQt_UniqueNameOnlyNumbers();
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX="DataX"+UniqueName;
    QString NameDataY="DataY"+UniqueName;
    QString NameDataXArea="DataXArea"+UniqueName;
    QString NameDataYArea="DataYArea"+UniqueName;
    QString NameChart="Chart"+UniqueName;


    //рисуем область графика и оси
    VMHL_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VMHL_Result+="<script type=\"text/javascript\">\n";
    VMHL_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VMHL_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VMHL_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VMHL_VectorX=new T[VMHL_N];
    T *Temp_VMHL_VectorY=new T[VMHL_N];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorX[i]=VMHL_VectorX[i];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorY[i]=VMHL_VectorY[i];

    //отсортируем массивы
    for(i=VMHL_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_VectorX[j]>Temp_VMHL_VectorX[j+1])
            {
                T x;
                x=Temp_VMHL_VectorX[j+1];
                Temp_VMHL_VectorX[j+1]=Temp_VMHL_VectorX[j];
                Temp_VMHL_VectorX[j]=x;
                x=Temp_VMHL_VectorY[j+1];
                Temp_VMHL_VectorY[j+1]=Temp_VMHL_VectorY[j];
                Temp_VMHL_VectorY[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX;
    QString SDataY;
    for (i=0;i<VMHL_N-1;i++)
        SDataX+=QString::number(Temp_VMHL_VectorX[i])+", ";
    SDataX+=QString::number(Temp_VMHL_VectorX[VMHL_N-1]);
    for (i=0;i<VMHL_N-1;i++)
        SDataY+=QString::number(Temp_VMHL_VectorY[i])+", ";
    SDataY+=QString::number(Temp_VMHL_VectorY[VMHL_N-1]);

    //запишем массивы точек
    VMHL_Result+="var "+NameDataX+" = ["+SDataX+"];\n";
    VMHL_Result+="var "+NameDataY+" = ["+SDataY+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);
        SDataY=SBeginYAxis+", "+SDataY+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VMHL_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataYArea+" = ["+SDataY+"];\n";
        if (!RedLine)
            VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
        else
            VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea+"],{strokeColor:'"+RedColor+"',highlightStrokeColor:'"+RedColor+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+RedColor+"',highlightFillColor:'"+RedColor+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        VMHL_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line,point'});\n";
        if (!RedLine)
            VMHL_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        else
            VMHL_Result+=NameChart+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        if (!RedLine)
            VMHL_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        else
            VMHL_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";

        VMHL_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем график
        VMHL_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        if (!RedLine)
            VMHL_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        else
            VMHL_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        VMHL_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line'});\n";
        if (!RedLine)
            VMHL_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        else
            VMHL_Result+=NameChart+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VMHL_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VMHL_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataYLegend="DataYLegend"+UniqueNameLegend;
        QString NameChartLegend="ChartLegend"+UniqueNameLegend;
        QString NameTextLegend="TextLegend"+UniqueName;

        //рисуем область графика и оси
        VMHL_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:50px;\"></div>\n";
        VMHL_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="2";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VMHL_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        SDataX="1, 2";
        SDataY="1, 1";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY="1, 1, 1";
        }

        //запишем массивы точек
        VMHL_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataYLegend+" = ["+SDataY+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            VMHL_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line,point'});\n";
            if (!RedLine)
                VMHL_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            else
                VMHL_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VMHL_Result+="    {\n";
            if (!RedLine)
                VMHL_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            else
                VMHL_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
            VMHL_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            VMHL_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            if (!RedLine)
                VMHL_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            else
                VMHL_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
            VMHL_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            VMHL_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line'});\n";
            if (!RedLine)
                VMHL_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            else
                VMHL_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
        }

        //напишем текст
        VMHL_Result+=NameTextLegend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VMHL_Result+="</script>\n";
    }

    delete [] Temp_VMHL_VectorX;
    delete [] Temp_VMHL_VectorY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием параметра NameLine(название первого графика (для легенды)).
    То есть не будет легенды у графика.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синию.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y",true,true,true,true);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VMHL_VectorX,VMHL_VectorY,VMHL_N,TitleChart,NameVectorX, NameVectorY, "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - название первого графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y","линия");

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VMHL_VectorX,VMHL_VectorY,VMHL_N,TitleChart,NameVectorX, NameVectorY, NameLine, true, true, true, true, false);

}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY - указатель на вектор координат Y точек;
     VMHL_N - количество точек.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VMHL_VectorX,VMHL_VectorY,VMHL_N,"","x", "y", "", true, true, true, true, false);

}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,true);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString CoordinateColor="#88969c";

    QString Color="#97bbcd";
    QString HighlightColor="#3c7693";

    QString Color2="#cccccc";
    QString HighlightColor2="#7e7e7e";

    //посчитаем гарницы изменения параметров
    T MinX=VMHL_VectorX[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorX[i]<MinX)
            MinX=VMHL_VectorX[i];

    T MinY1=VMHL_VectorY1[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY1[i]<MinY1)
            MinY1=VMHL_VectorY1[i];

    T MinY2=VMHL_VectorY2[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY2[i]<MinY2)
            MinY2=VMHL_VectorY2[i];

    T MaxX=VMHL_VectorX[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorX[i]>MaxX)
            MaxX=VMHL_VectorX[i];

    T MaxY1=VMHL_VectorY1[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY1[i]>MaxY1)
            MaxY1=VMHL_VectorY1[i];

    T MaxY2=VMHL_VectorY2[0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_VectorY2[i]>MaxY2)
            MaxY2=VMHL_VectorY2[i];

    T MinY;
    T MaxY;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VMHL_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VMHL_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX="DataX"+UniqueName;
    QString NameDataY1="DataY1"+UniqueName;
    QString NameDataY2="DataY2"+UniqueName;
    QString NameDataXArea="DataXArea"+UniqueName;
    QString NameDataY1Area="DataY1Area"+UniqueName;
    QString NameDataY2Area="DataY2Area"+UniqueName;
    QString NameChart1="Chart1"+UniqueName;
    QString NameChart2="Chart2"+UniqueName;

    //рисуем область графика и оси
    VMHL_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VMHL_Result+="<script type=\"text/javascript\">\n";
    VMHL_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VMHL_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VMHL_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VMHL_VectorX=new T[VMHL_N];
    T *Temp_VMHL_VectorY1=new T[VMHL_N];
    T *Temp_VMHL_VectorY2=new T[VMHL_N];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorX[i]=VMHL_VectorX[i];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorY1[i]=VMHL_VectorY1[i];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_VectorY2[i]=VMHL_VectorY2[i];

    //отсортируем массивы
    for(i=VMHL_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_VectorX[j]>Temp_VMHL_VectorX[j+1])
            {
                T x;
                x=Temp_VMHL_VectorX[j+1];
                Temp_VMHL_VectorX[j+1]=Temp_VMHL_VectorX[j];
                Temp_VMHL_VectorX[j]=x;
                x=Temp_VMHL_VectorY1[j+1];
                Temp_VMHL_VectorY1[j+1]=Temp_VMHL_VectorY1[j];
                Temp_VMHL_VectorY1[j]=x;
                x=Temp_VMHL_VectorY2[j+1];
                Temp_VMHL_VectorY2[j+1]=Temp_VMHL_VectorY2[j];
                Temp_VMHL_VectorY2[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX;
    QString SDataY1;
    QString SDataY2;
    for (i=0;i<VMHL_N-1;i++)
        SDataX+=QString::number(Temp_VMHL_VectorX[i])+", ";
    SDataX+=QString::number(Temp_VMHL_VectorX[VMHL_N-1]);
    for (i=0;i<VMHL_N-1;i++)
        SDataY1+=QString::number(Temp_VMHL_VectorY1[i])+", ";
    SDataY1+=QString::number(Temp_VMHL_VectorY1[VMHL_N-1]);

    for (i=0;i<VMHL_N-1;i++)
        SDataY2+=QString::number(Temp_VMHL_VectorY2[i])+", ";
    SDataY2+=QString::number(Temp_VMHL_VectorY2[VMHL_N-1]);

    //запишем массивы точек
    VMHL_Result+="var "+NameDataX+" = ["+SDataX+"];\n";
    VMHL_Result+="var "+NameDataY1+" = ["+SDataY1+"];\n";
    VMHL_Result+="var "+NameDataY2+" = ["+SDataY2+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);
        SDataY1=SBeginYAxis+", "+SDataY1+", "+SBeginYAxis+", "+SBeginYAxis;
        SDataY2=SBeginYAxis+", "+SDataY2+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VMHL_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataY1Area+" = ["+SDataY1+"];\n";
        VMHL_Result+="var "+NameDataY2Area+" = ["+SDataY2+"];\n";
        VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataY2Area+"],{strokeColor:'"+Color2+"',highlightStrokeColor:'"+Color2+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color2+"',highlightFillColor:'"+Color2+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
        VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataY1Area+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";

        //Нарисуем график
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";

        //Нарисуем точки
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию 2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";

        //Нарисуем только линию
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VMHL_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VMHL_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine1.trimmed().isEmpty()))&& (!(NameLine2.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataY1Legend="DataY1Legend"+UniqueNameLegend;
        QString NameDataY2Legend="DataY2Legend"+UniqueNameLegend;
        QString NameChart1Legend="Chart1Legend"+UniqueNameLegend;
        QString NameChart2Legend="Chart2Legend"+UniqueNameLegend;
        QString NameText1Legend="Text1Legend"+UniqueName;
        QString NameText2Legend="Text2Legend"+UniqueName;


        //рисуем область графика и оси
        VMHL_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:100px;\"></div>\n";
        VMHL_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="3";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VMHL_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        SDataX="1, 2";
        SDataY1="2, 2";
        SDataY2="1, 1";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY1="2, 2, 2";
            SDataY2="1, 1, 1";
        }

        //запишем массивы точек
        VMHL_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataY1Legend+" = ["+SDataY1+"];\n";
        VMHL_Result+="var "+NameDataY2Legend+" = ["+SDataY2+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";

            //Нарисуем график2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";

            //Нарисуем точки2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";

            //Нарисуем только линию 2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        }

        //напишем текст
        VMHL_Result+=NameText1Legend+" = "+NameBoardLegend+".create('text',[2.2,2, \"- "+NameLine1+";\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        VMHL_Result+=NameText2Legend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine2+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VMHL_Result+="</script>\n";
    }

    delete [] Temp_VMHL_VectorX;
    delete [] Temp_VMHL_VectorY1;
    delete [] Temp_VMHL_VectorY2;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается отсуствием параметров NameLine1 и NameLine2. То есть нет легенды у графика.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y",true,true,true,true);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VMHL_VectorX,VMHL_VectorY1,VMHL_VectorY2, VMHL_N,TitleChart,NameVectorX, NameVectorY,"", "",ShowLine,ShowPoints,ShowArea, ShowSpecPoints);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевских переменных - все по умолчанию.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y","количество деревьев","количество домов");

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VMHL_VectorX,VMHL_VectorY1,VMHL_VectorY2, VMHL_N, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2,true,true,true,true);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VMHL_VectorX,T *VMHL_VectorY1,T *VMHL_VectorY2, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевских переменных и названий графика, осей, линий - все по умолчанию.
    Входные параметры:
     VMHL_VectorX - указатель на вектор координат X точек;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VMHL_VectorX,VMHL_VectorY1,VMHL_VectorY2, VMHL_N, "", "x", "y", "", "",true,true,true,true);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VMHL_VectorX1 - указатель на вектор координат X точек первой линии;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_N1 - количество точек первой линии;
     VMHL_VectorX2 - указатель на вектор координат X точек второй линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,true);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString CoordinateColor="#88969c";

    QString Color="#97bbcd";
    QString HighlightColor="#3c7693";

    QString Color2="#cccccc";
    QString HighlightColor2="#7e7e7e";

    //посчитаем гарницы изменения параметров
    T MinX1=VMHL_VectorX1[0];
    for (int i=1;i<VMHL_N1;i++)
        if (VMHL_VectorX1[i]<MinX1)
            MinX1=VMHL_VectorX1[i];

    T MinX2=VMHL_VectorX2[0];
    for (int i=1;i<VMHL_N2;i++)
        if (VMHL_VectorX2[i]<MinX2)
            MinX2=VMHL_VectorX2[i];

    T MinY1=VMHL_VectorY1[0];
    for (int i=1;i<VMHL_N1;i++)
        if (VMHL_VectorY1[i]<MinY1)
            MinY1=VMHL_VectorY1[i];

    T MinY2=VMHL_VectorY2[0];
    for (int i=1;i<VMHL_N2;i++)
        if (VMHL_VectorY2[i]<MinY2)
            MinY2=VMHL_VectorY2[i];

    T MaxX1=VMHL_VectorX1[0];
    for (int i=1;i<VMHL_N1;i++)
        if (VMHL_VectorX1[i]>MaxX1)
            MaxX1=VMHL_VectorX1[i];

    T MaxX2=VMHL_VectorX2[0];
    for (int i=1;i<VMHL_N2;i++)
        if (VMHL_VectorX2[i]>MaxX2)
            MaxX2=VMHL_VectorX2[i];

    T MaxY1=VMHL_VectorY1[0];
    for (int i=1;i<VMHL_N1;i++)
        if (VMHL_VectorY1[i]>MaxY1)
            MaxY1=VMHL_VectorY1[i];

    T MaxY2=VMHL_VectorY2[0];
    for (int i=1;i<VMHL_N2;i++)
        if (VMHL_VectorY2[i]>MaxY2)
            MaxY2=VMHL_VectorY2[i];

    T MinX;
    T MaxX;

    T MinY;
    T MaxY;

    if (MinX1<MinX2)
        MinX=MinX1;
    else
        MinX=MinX2;

    if (MaxX1>MaxX2)
        MaxX=MaxX1;
    else
        MaxX=MaxX2;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VMHL_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VMHL_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX1="DataX1"+UniqueName;
    QString NameDataX2="DataX2"+UniqueName;
    QString NameDataY1="DataY1"+UniqueName;
    QString NameDataY2="DataY2"+UniqueName;
    QString NameDataX1Area="DataX1Area"+UniqueName;
    QString NameDataX2Area="DataX2Area"+UniqueName;
    QString NameDataY1Area="DataY1Area"+UniqueName;
    QString NameDataY2Area="DataY2Area"+UniqueName;
    QString NameChart1="Chart1"+UniqueName;
    QString NameChart2="Chart2"+UniqueName;

    //рисуем область графика и оси
    VMHL_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VMHL_Result+="<script type=\"text/javascript\">\n";
    VMHL_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VMHL_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VMHL_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VMHL_VectorX1=new T[VMHL_N1];
    T *Temp_VMHL_VectorX2=new T[VMHL_N2];
    T *Temp_VMHL_VectorY1=new T[VMHL_N1];
    T *Temp_VMHL_VectorY2=new T[VMHL_N2];
    for (i=0;i<VMHL_N1;i++) Temp_VMHL_VectorX1[i]=VMHL_VectorX1[i];
    for (i=0;i<VMHL_N2;i++) Temp_VMHL_VectorX2[i]=VMHL_VectorX2[i];
    for (i=0;i<VMHL_N1;i++) Temp_VMHL_VectorY1[i]=VMHL_VectorY1[i];
    for (i=0;i<VMHL_N2;i++) Temp_VMHL_VectorY2[i]=VMHL_VectorY2[i];

    //отсортируем массивы
    for(i=VMHL_N1-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_VectorX1[j]>Temp_VMHL_VectorX1[j+1])
            {
                T x;
                x=Temp_VMHL_VectorX1[j+1];
                Temp_VMHL_VectorX1[j+1]=Temp_VMHL_VectorX1[j];
                Temp_VMHL_VectorX1[j]=x;
                x=Temp_VMHL_VectorY1[j+1];
                Temp_VMHL_VectorY1[j+1]=Temp_VMHL_VectorY1[j];
                Temp_VMHL_VectorY1[j]=x;
            }

    for(i=VMHL_N2-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_VectorX2[j]>Temp_VMHL_VectorX2[j+1])
            {
                T x;
                x=Temp_VMHL_VectorX2[j+1];
                Temp_VMHL_VectorX2[j+1]=Temp_VMHL_VectorX2[j];
                Temp_VMHL_VectorX2[j]=x;
                x=Temp_VMHL_VectorY2[j+1];
                Temp_VMHL_VectorY2[j+1]=Temp_VMHL_VectorY2[j];
                Temp_VMHL_VectorY2[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX1;
    QString SDataX2;
    QString SDataY1;
    QString SDataY2;

    for (i=0;i<VMHL_N1-1;i++)
        SDataX1+=QString::number(Temp_VMHL_VectorX1[i])+", ";
    SDataX1+=QString::number(Temp_VMHL_VectorX1[VMHL_N1-1]);

    for (i=0;i<VMHL_N2-1;i++)
        SDataX2+=QString::number(Temp_VMHL_VectorX2[i])+", ";
    SDataX2+=QString::number(Temp_VMHL_VectorX2[VMHL_N2-1]);

    for (i=0;i<VMHL_N1-1;i++)
        SDataY1+=QString::number(Temp_VMHL_VectorY1[i])+", ";
    SDataY1+=QString::number(Temp_VMHL_VectorY1[VMHL_N1-1]);

    for (i=0;i<VMHL_N2-1;i++)
        SDataY2+=QString::number(Temp_VMHL_VectorY2[i])+", ";
    SDataY2+=QString::number(Temp_VMHL_VectorY2[VMHL_N2-1]);

    //запишем массивы точек
    VMHL_Result+="var "+NameDataX1+" = ["+SDataX1+"];\n";
    VMHL_Result+="var "+NameDataX2+" = ["+SDataX2+"];\n";
    VMHL_Result+="var "+NameDataY1+" = ["+SDataY1+"];\n";
    VMHL_Result+="var "+NameDataY2+" = ["+SDataY2+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX1=QString::number(MinX1)+", "+SDataX1+", "+QString::number(MaxX1)+", "+QString::number(MinX1);
        SDataX2=QString::number(MinX2)+", "+SDataX2+", "+QString::number(MaxX2)+", "+QString::number(MinX2);
        SDataY1=SBeginYAxis+", "+SDataY1+", "+SBeginYAxis+", "+SBeginYAxis;
        SDataY2=SBeginYAxis+", "+SDataY2+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VMHL_Result+="var "+NameDataX1Area+" = ["+SDataX1+"];\n";
        VMHL_Result+="var "+NameDataX2Area+" = ["+SDataX2+"];\n";
        VMHL_Result+="var "+NameDataY1Area+" = ["+SDataY1+"];\n";
        VMHL_Result+="var "+NameDataY2Area+" = ["+SDataY2+"];\n";
        VMHL_Result+=NameBoard+".create('curve', ["+NameDataX2Area+","+NameDataY2Area+"],{strokeColor:'"+Color2+"',highlightStrokeColor:'"+Color2+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color2+"',highlightFillColor:'"+Color2+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
        VMHL_Result+=NameBoard+".create('curve', ["+NameDataX1Area+","+NameDataY1Area+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N2)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";

        //Нарисуем график
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX1+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N1)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N2)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";

        //Нарисуем точки
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX1+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N1)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию 2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";

        //Нарисуем только линию
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX1+","+NameDataY1+"], {chartStyle:'line'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VMHL_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VMHL_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine1.trimmed().isEmpty()))&& (!(NameLine2.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataY1Legend="DataY1Legend"+UniqueNameLegend;
        QString NameDataY2Legend="DataY2Legend"+UniqueNameLegend;
        QString NameChart1Legend="Chart1Legend"+UniqueNameLegend;
        QString NameChart2Legend="Chart2Legend"+UniqueNameLegend;
        QString NameText1Legend="Text1Legend"+UniqueName;
        QString NameText2Legend="Text2Legend"+UniqueName;


        //рисуем область графика и оси
        VMHL_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:100px;\"></div>\n";
        VMHL_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="3";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VMHL_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";
        SDataY1="2, 2";
        SDataY2="1, 1";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY1="2, 2, 2";
            SDataY2="1, 1, 1";
        }

        //запишем массивы точек
        VMHL_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataY1Legend+" = ["+SDataY1+"];\n";
        VMHL_Result+="var "+NameDataY2Legend+" = ["+SDataY2+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";

            //Нарисуем график2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";

            //Нарисуем точки2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";

            //Нарисуем только линию 2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        }

        //напишем текст
        VMHL_Result+=NameText1Legend+" = "+NameBoardLegend+".create('text',[2.2,2, \"- "+NameLine1+";\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        VMHL_Result+=NameText2Legend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine2+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VMHL_Result+="</script>\n";
    }

    delete [] Temp_VMHL_VectorX1;
    delete [] Temp_VMHL_VectorX2;
    delete [] Temp_VMHL_VectorY1;
    delete [] Temp_VMHL_VectorY2;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием легенды, то есть параметров NameLine1, NameLine2.
    Входные параметры:
     VMHL_VectorX1 - указатель на вектор координат X точек первой линии;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_N1 - количество точек первой линии;
     VMHL_VectorX2 - указатель на вектор координат X точек второй линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y",true,true,true,true);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfLine (VMHL_VectorX1,VMHL_VectorY1, VMHL_N1,VMHL_VectorX2,VMHL_VectorY2, VMHL_N2, TitleChart, NameVectorX, NameVectorY,"", "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых параметров - все по умолчанию.
    Входные параметры:
     VMHL_VectorX1 - указатель на вектор координат X точек первой линии;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_N1 - количество точек первой линии;
     VMHL_VectorX2 - указатель на вектор координат X точек второй линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y","количество деревьев","количество домов");

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfLine (VMHL_VectorX1,VMHL_VectorY1,VMHL_N1,VMHL_VectorX2,VMHL_VectorY2, VMHL_N2, TitleChart, NameVectorX, NameVectorY,NameLine1, NameLine2,true,true,true,true);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых параметров и подписей - все по умолчанию.
    Входные параметры:
     VMHL_VectorX1 - указатель на вектор координат X точек первой линии;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_N1 - количество точек первой линии;
     VMHL_VectorX2 - указатель на вектор координат X точек второй линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,N1,dataX2,dataY2,N2);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfLine (VMHL_VectorX1,VMHL_VectorY1,VMHL_N1,VMHL_VectorX2,VMHL_VectorY2, VMHL_N2, "", "x", "y","", "",true,true,true,true);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VMHL_MatrixXY - указатель на матрицу значений X и Н графиков;
     VMHL_N - количество точек;
     VMHL_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M-1 (так как первый столбец - это X значения);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    int M=2;
    double **data;
    data=new double*[N];
    for (int i=0;i<N;i++) X[i]=new double[M];
    data[0][0]=7;data[0][1]=6;
    data[1][0]=8;data[1][1]=4;
    data[2][0]=10;data[2][1]=7;
    data[3][0]=5;data[3][1]=12;
    data[4][0]=14;data[4][1]=4;
    data[5][0]=13;data[5][1]=8;

    QString *NameLine=new QString[M-1];
    NameLine[0]="Первая линия";

    Html += THQt_ShowChartsOfLineFromMatrix (data,N,M, "График", "x", "y",NameLine,true,true,true,true);

    for (int i=0;i<N;i++) delete [] data[i];
    delete [] data;
    delete [] NameLine;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString CoordinateColor="#88969c";
    QString HighlightCoordinateColor="#3c7693";

    QString *Color=new QString [VMHL_M-1];
    for (j=0;j<VMHL_M-1;j++) Color[j]="#97bbcd";

    QString *HighlightColor=new QString [VMHL_M-1];
    for (j=0;j<VMHL_M-1;j++) HighlightColor[j]="#3c7693";

    QString *ColorArea=new QString [VMHL_M-1];
    for (j=0;j<VMHL_M-1;j++) ColorArea[j]="#97bbcd";

    QString *OpacityArea=new QString [VMHL_M-1];
    for (j=0;j<VMHL_M-1;j++) OpacityArea[j]="0.5";

    QString *StrokeWidth=new QString [VMHL_M-1];
    for (j=0;j<VMHL_M-1;j++) StrokeWidth[j]="2";

    QString *StrokeWidthPoints=new QString [VMHL_M-1];
    for (j=0;j<VMHL_M-1;j++) StrokeWidthPoints[j]="2";

    QString *FaceOfLine=new QString [VMHL_M-1];
    for (j=0;j<VMHL_M-1;j++) FaceOfLine[j]="o";

    if (VMHL_M-1==2)//если два графика
    {
        Color[1]="#cccccc";
        HighlightColor[1]="#7e7e7e";
        ColorArea[1]="#cccccc";
    }
    if ((VMHL_M-1==3)&&(ShowArea))//если три графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";
        ColorArea[1]="#97bbcd";
        OpacityArea[1]="0.5";

        Color[2]="#cccccc";
        HighlightColor[2]="#7e7e7e";
        ColorArea[2]="#cccccc";
        OpacityArea[2]="0.5";
    }
    if ((VMHL_M-1==3)&&(!ShowArea))//если три графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e06c65";
        HighlightColor[2]="#9d2b24";
    }
    if ((VMHL_M-1==4)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#cccccc";
        HighlightColor[3]="#7e7e7e";
        ColorArea[3]="#cccccc";
        OpacityArea[3]="0.5";
    }
    if ((VMHL_M-1==4)&&(!ShowArea))//если 4 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";
    }
    if ((VMHL_M-1==5)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#cccccc";
        HighlightColor[4]="#7e7e7e";
        ColorArea[4]="#cccccc";
        OpacityArea[4]="0.5";
    }
    if ((VMHL_M-1==5)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";

        Color[4]="#9d50c8";
        HighlightColor[4]="#6a2b8d";
    }
    if ((VMHL_M-1==6)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#bec7cd";
        HighlightColor[4]="#5c7483";
        ColorArea[4]="#bec7cd";
        OpacityArea[4]="0.5";

        Color[5]="#cccccc";
        HighlightColor[5]="#7e7e7e";
        ColorArea[5]="#cccccc";
        OpacityArea[5]="0.5";
    }
    if ((VMHL_M-1==6)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#b5d24e";
        HighlightColor[2]="#8ca72c";

        Color[3]="#e7cc4c";
        HighlightColor[3]="#b49c28";

        Color[4]="#e06c65";
        HighlightColor[4]="#9d2b24";

        Color[5]="#9d50c8";
        HighlightColor[5]="#6a2b8d";
    }
    if ((VMHL_M-1==7)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#97bbcd";
        HighlightColor[3]="#3c7693";
        ColorArea[3]="#97bbcd";
        OpacityArea[3]="0.5";

        Color[4]="#adc2cd";
        HighlightColor[4]="#58839a";
        ColorArea[4]="#adc2cd";
        OpacityArea[4]="0.5";

        Color[5]="#bec7cd";
        HighlightColor[5]="#5c7483";
        ColorArea[5]="#bec7cd";
        OpacityArea[5]="0.5";

        Color[6]="#cccccc";
        HighlightColor[6]="#7e7e7e";
        ColorArea[6]="#cccccc";
        OpacityArea[6]="0.5";
    }
    if ((VMHL_M-1==7)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";
    }
    if ((VMHL_M-1==8)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#bec7cd";
        HighlightColor[6]="#5c7483";
        ColorArea[6]="#bec7cd";
        OpacityArea[6]="0.5";

        Color[7]="#cccccc";
        HighlightColor[7]="#7e7e7e";
        ColorArea[7]="#cccccc";
        OpacityArea[7]="0.5";
    }
    if ((VMHL_M-1==8)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";

        Color[7]="#c64f8f";
        HighlightColor[7]="#8d275e";
    }
    if ((VMHL_M-1==9)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#b6c5cd";
        HighlightColor[6]="#617580";
        ColorArea[6]="#b6c5cd";
        OpacityArea[6]="0.5";

        Color[7]="#bec7cd";
        HighlightColor[7]="#5c7483";
        ColorArea[7]="#bec7cd";
        OpacityArea[7]="0.5";

        Color[8]="#cccccc";
        HighlightColor[8]="#7e7e7e";
        ColorArea[8]="#cccccc";
        OpacityArea[8]="0.5";
    }
    if ((VMHL_M-1==9)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e9ac4c";
        HighlightColor[5]="#946b2c";

        Color[6]="#e06c65";
        HighlightColor[6]="#9d2b24";

        Color[7]="#9d50c8";
        HighlightColor[7]="#6a2b8d";

        Color[8]="#c64f8f";
        HighlightColor[8]="#8d275e";
    }
    if ((VMHL_M-1>9)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VMHL_M-1;j++)
        {
            position=j/double(VMHL_M-1);
            Color[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#537c90";
            HighlightColor[j]="#26576f";
            ColorArea[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#799bac";
            OpacityArea[j]="0.5";
        }
    }
    if ((VMHL_M-1>9)&&(!ShowArea))//если 4 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VMHL_M-1;j++)
        {
            position=j/double(VMHL_M-1);
            Color[j]=THQt_AlphaBlendingColorToColor(0.4,THQt_GiveRainbowColorRGB(position),"#ffffff");
            HighlightColor[j]="#26576f";
        }
    }
    //по точкам пройдемся
    if (VMHL_M-1>=3)
    {
        FaceOfLine[1]="[]";
        StrokeWidthPoints[1]="2";

        FaceOfLine[2]="<>";
        StrokeWidthPoints[2]="3";
    }
    if (VMHL_M-1>=4)
    {
        FaceOfLine[3]="x";
        StrokeWidthPoints[3]="3";
    }
    if (VMHL_M-1>=5)
    {
        FaceOfLine[4]="+";
        StrokeWidthPoints[4]="3";
    }
    if (VMHL_M-1>=6)
    {
        FaceOfLine[5]="^";
        StrokeWidthPoints[5]="3";
    }
    if (VMHL_M-1>=7)
    {
        FaceOfLine[6]="v";
        StrokeWidthPoints[6]="3";
    }
    if (VMHL_M-1>=8)
    {
        FaceOfLine[7]=">";
        StrokeWidthPoints[7]="3";
    }
    if (VMHL_M-1>=9)
    {
        FaceOfLine[8]="<";
        StrokeWidthPoints[8]="3";
    }
    //когда уменьшать толщину линии
    if (VMHL_M-1>5)
        for (j=0;j<VMHL_M-1;j++)
        {
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]=QString::number((StrokeWidthPoints[j].toInt())-1);
        }
    if (VMHL_M-1>9)//слишком много кривых
    {
        for (j=0;j<VMHL_M-1;j++)
        {
            FaceOfLine[j]="o";
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]="1";
        }
    }

    //посчитаем гарницы изменения параметров
    T MinX=VMHL_MatrixXY[0][0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_MatrixXY[i][0]<MinX)
            MinX=VMHL_MatrixXY[i][0];

    T MaxX=VMHL_MatrixXY[0][0];
    for (int i=1;i<VMHL_N;i++)
        if (VMHL_MatrixXY[i][0]>MaxX)
            MaxX=VMHL_MatrixXY[i][0];

    T MinY=VMHL_MatrixXY[0][1];
    for (j=0;j<VMHL_M-1;j++)
        for (int i=0;i<VMHL_N;i++)
            if (VMHL_MatrixXY[i][j+1]<MinY)
                MinY=VMHL_MatrixXY[i][j+1];

    T MaxY=VMHL_MatrixXY[0][1];
    for (j=0;j<VMHL_M-1;j++)
        for (int i=0;i<VMHL_N;i++)
            if (VMHL_MatrixXY[i][j+1]>MaxY)
                MaxY=VMHL_MatrixXY[i][j+1];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VMHL_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VMHL_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX="DataX"+UniqueName;
    QString NameDataXArea="DataX1Area"+UniqueName;

    QString *NameDataY=new QString[VMHL_M-1];
    QString *NameDataYArea=new QString[VMHL_M-1];
    QString *NameChart=new QString[VMHL_M-1];
    for (j=0;j<VMHL_M-1;j++) NameDataY[j]="DataY"+QString::number(j+1)+UniqueName;
    for (j=0;j<VMHL_M-1;j++) NameDataYArea[j]="DataY"+QString::number(j+1)+"Area"+UniqueName;
    for (j=0;j<VMHL_M-1;j++) NameChart[j]="Chart"+QString::number(j+1)+UniqueName;

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VMHL_MatrixXY;
    Temp_VMHL_MatrixXY=new double*[VMHL_N];
    for (i=0;i<VMHL_N;i++) Temp_VMHL_MatrixXY[i]=new double[VMHL_M];
    for (i=0;i<VMHL_N;i++)
        for (j=0;j<VMHL_M;j++)
            Temp_VMHL_MatrixXY[i][j]=VMHL_MatrixXY[i][j];

    //отсортируем массивы
    for(i=VMHL_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_MatrixXY[j][0]>Temp_VMHL_MatrixXY[j+1][0])
            {
                for (k=0;k<VMHL_M;k++)
                {
                    T x;
                    x=Temp_VMHL_MatrixXY[j+1][k];
                    Temp_VMHL_MatrixXY[j+1][k]=Temp_VMHL_MatrixXY[j][k];
                    Temp_VMHL_MatrixXY[j][k]=x;
                }
            }

    //рисуем область графика и оси
    VMHL_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VMHL_Result+="<script type=\"text/javascript\">\n";
    VMHL_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VMHL_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VMHL_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";


    //соберем в массивы javascript данные точек
    QString SDataX;
    QString *SDataY = new QString[VMHL_M-1];

    for (i=0;i<VMHL_N-1;i++)
        SDataX+=QString::number(Temp_VMHL_MatrixXY[i][0])+", ";
    SDataX+=QString::number(Temp_VMHL_MatrixXY[VMHL_N-1][0]);

    for (j=0;j<VMHL_M-1;j++)
    {
        for (i=0;i<VMHL_N-1;i++)
            SDataY[j]+=QString::number(Temp_VMHL_MatrixXY[i][j+1])+", ";
        SDataY[j]+=QString::number(Temp_VMHL_MatrixXY[VMHL_N-1][j+1]);
    }

    //запишем массивы точек
    VMHL_Result+="var "+NameDataX+" = ["+SDataX+"];\n";
    for (j=0;j<VMHL_M-1;j++)
        VMHL_Result+="var "+NameDataY[j]+" = ["+SDataY[j]+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);

        for (j=0;j<VMHL_M-1;j++)
            SDataY[j]=SBeginYAxis+", "+SDataY[j]+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VMHL_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        for (j=0;j<VMHL_M-1;j++)
            VMHL_Result+="var "+NameDataYArea[j]+" = ["+SDataY[j]+"];\n";
        for (j=0;j<VMHL_M-1;j++)
            VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea[VMHL_M-2-j]+"],{strokeColor:'"+ColorArea[VMHL_M-2-j]+"',highlightStrokeColor:'"+ColorArea[VMHL_M-2-j]+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+ColorArea[VMHL_M-2-j]+"',highlightFillColor:'"+ColorArea[VMHL_M-2-j]+"',fillOpacity:"+OpacityArea[VMHL_M-2-j]+",highlightFillOpacity:"+OpacityArea[VMHL_M-2-j]+"});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VMHL_M-1;j++)
        {
            VMHL_Result+="var "+NameChart[VMHL_M-2-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY[VMHL_M-2-j]+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart[VMHL_M-2-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M-2-j]+"','strokeWidth:"+StrokeWidth[VMHL_M-2-j]+"');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart[VMHL_M-2-j]+"[1][i].setProperty({strokeColor:'"+Color[VMHL_M-2-j]+"',highlightStrokeColor:'"+HighlightColor[VMHL_M-2-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VMHL_M-2-j]+"', size:"+StrokeWidthPoints[VMHL_M-2-j]+", strokeWidth:'"+StrokeWidth[VMHL_M-2-j]+"pt'});\n";
            VMHL_Result+="    }\n";
        }
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки
        for (j=0;j<VMHL_M-1;j++)
        {
            VMHL_Result+="var "+NameChart[VMHL_M-2-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY[VMHL_M-2-j]+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart[VMHL_M-2-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M-2-j]+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart[VMHL_M-2-j]+"[1][i].setProperty({strokeColor:'"+Color[VMHL_M-2-j]+"',highlightStrokeColor:'"+HighlightColor[VMHL_M-2-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VMHL_M-2-j]+"', size:"+StrokeWidthPoints[VMHL_M-2-j]+", strokeWidth:'"+StrokeWidth[VMHL_M-2-j]+"pt'});\n";
            VMHL_Result+="    }\n";
        }
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию
        for (j=0;j<VMHL_M-1;j++)
        {
            VMHL_Result+="var "+NameChart[VMHL_M-2-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY[VMHL_M-2-j]+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart[VMHL_M-2-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M-2-j]+"','strokeWidth:"+StrokeWidth[VMHL_M-2-j]+"');\n";
        }
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VMHL_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VMHL_Result+="</script>\n";

    // ЛЕГЕНДА
    int NameLineHowManyEmpty=0;
    for (j=0;j<VMHL_M-1;j++) if (NameLine[j].trimmed().isEmpty()!=true) NameLineHowManyEmpty++;

    if (NameLineHowManyEmpty!=0)
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;

        QString *NameDataYLegend= new QString[VMHL_M-1];
        QString *NameChartLegend= new QString[VMHL_M-1];
        QString *NameTextLegend= new QString[VMHL_M-1];

        for (j=0;j<VMHL_M-1;j++) NameDataYLegend[j]="DataY"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VMHL_M-1;j++) NameChartLegend[j]="Chart"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VMHL_M-1;j++) NameTextLegend[j]="Text"+QString::number(j+1)+"Legend"+UniqueNameLegend;


        //рисуем область графика и оси
        VMHL_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:"+QString::number(50*(VMHL_M-1))+"px;\"></div>\n";
        VMHL_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox=QString::number(VMHL_M);
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VMHL_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";

        for (j=0;j<VMHL_M-1;j++) SDataY[j]=QString::number(VMHL_M-1-j)+", "+QString::number(VMHL_M-1-j);

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            for (j=0;j<VMHL_M-1;j++) SDataY[j]=QString::number(VMHL_M-1-j)+", "+QString::number(VMHL_M-1-j)+", "+QString::number(VMHL_M-1-j);
        }

        //запишем массивы точек

        VMHL_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        for (j=0;j<VMHL_M-1;j++)
            VMHL_Result+="var "+NameDataYLegend[j]+" = ["+SDataY[j]+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            for (j=0;j<VMHL_M-1;j++)
            {
                VMHL_Result+="var "+NameChartLegend[VMHL_M-2-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VMHL_M-2-j]+"], {chartStyle:'line,point'});\n";
                VMHL_Result+=NameChartLegend[VMHL_M-2-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M-2-j]+"','strokeWidth:"+StrokeWidth[VMHL_M-2-j]+"');\n";
                VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
                VMHL_Result+="    {\n";
                VMHL_Result+="    "+NameChartLegend[VMHL_M-2-j]+"[1][i].setProperty({strokeColor:'"+Color[VMHL_M-2-j]+"',highlightStrokeColor:'"+HighlightColor[VMHL_M-2-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VMHL_M-2-j]+"', size:"+StrokeWidthPoints[VMHL_M-2-j]+", strokeWidth:'"+StrokeWidth[VMHL_M-2-j]+"pt'});\n";
                VMHL_Result+="    }\n";
            }
        }

        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            for (j=0;j<VMHL_M-1;j++)
            {
                VMHL_Result+="var "+NameChartLegend[VMHL_M-2-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VMHL_M-2-j]+"], {chartStyle:'line,point'});\n";
                VMHL_Result+=NameChartLegend[VMHL_M-2-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M-2-j]+"','strokeWidth:0');\n";
                VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
                VMHL_Result+="    {\n";
                VMHL_Result+="    "+NameChartLegend[VMHL_M-2-j]+"[1][i].setProperty({strokeColor:'"+Color[VMHL_M-2-j]+"',highlightStrokeColor:'"+HighlightColor[VMHL_M-2-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VMHL_M-2-j]+"', size:"+StrokeWidthPoints[VMHL_M-2-j]+", strokeWidth:'"+StrokeWidth[VMHL_M-2-j]+"pt'});\n";
                VMHL_Result+="    }\n";
            }
        }

        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            for (j=0;j<VMHL_M-1;j++)
            {
                VMHL_Result+="var "+NameChartLegend[VMHL_M-2-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VMHL_M-2-j]+"], {chartStyle:'line'});\n";
                VMHL_Result+=NameChartLegend[VMHL_M-2-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M-2-j]+"','strokeWidth:"+StrokeWidth[VMHL_M-2-j]+"');\n";
            }
        }

        //напишем текст
        QString Delim=";";
        for (j=0;j<VMHL_M-1;j++)
        {
            if (j==VMHL_M-2) Delim=".";
            VMHL_Result+=NameTextLegend[j]+" = "+NameBoardLegend+".create('text',[2.2,"+QString::number(VMHL_M-1-j)+", \"- "+NameLine[j]+Delim+"\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        }

        VMHL_Result+="</script>\n";

        delete [] NameDataYLegend;
        delete [] NameChartLegend;
        delete [] NameTextLegend;
    }

    delete [] Color;
    delete [] HighlightColor;
    delete [] StrokeWidth;
    delete [] FaceOfLine;
    delete [] StrokeWidthPoints;
    delete [] ColorArea;
    delete [] OpacityArea;

    delete [] NameDataY;
    delete [] NameDataYArea;
    delete [] NameChart;
    delete [] SDataY;

    for (i=0;i<VMHL_N;i++) delete [] Temp_VMHL_MatrixXY[i];
    delete [] Temp_VMHL_MatrixXY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной библиотеки отсутствием легенды (нет параметра NewLine).
    Входные параметры:
     VMHL_MatrixXY - указатель на матрицу значений X и Н графиков;
     VMHL_N - количество точек;
     VMHL_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    int M=2;
    double **data;
    data=new double*[N];
    for (int i=0;i<N;i++) X[i]=new double[M];
    data[0][0]=7;data[0][1]=6;
    data[1][0]=8;data[1][1]=4;
    data[2][0]=10;data[2][1]=7;
    data[3][0]=5;data[3][1]=12;
    data[4][0]=14;data[4][1]=4;
    data[5][0]=13;data[5][1]=8;

    Html += THQt_ShowChartsOfLineFromMatrix (data,N,M, "График", "x", "y",true,true,true,true);

    for (int i=0;i<N;i++) delete [] data[i];
    delete [] data;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;
    QString *NameLine=new QString[VMHL_M-1];
    for (int i=0;i<VMHL_M-1;i++) NameLine[i]="";

    VMHL_Result = THQt_ShowChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N, VMHL_M, TitleChart, NameVectorX, NameVectorY,NameLine, ShowLine, ShowPoints, ShowArea, ShowSpecPoints);

    delete [] NameLine;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых переменных - все по умолчанию.
    Входные параметры:
     VMHL_MatrixXY - указатель на матрицу значений X и Н графиков;
     VMHL_N - количество точек;
     VMHL_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M-1 (так как первый столбец - это X значения).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    int M=2;
    double **data;
    data=new double*[N];
    for (int i=0;i<N;i++) X[i]=new double[M];
    data[0][0]=7;data[0][1]=6;
    data[1][0]=8;data[1][1]=4;
    data[2][0]=10;data[2][1]=7;
    data[3][0]=5;data[3][1]=12;
    data[4][0]=14;data[4][1]=4;
    data[5][0]=13;data[5][1]=8;

    QString *NameLine=new QString[M-1];
    NameLine[0]="Первая линия";

    Html += THQt_ShowChartsOfLineFromMatrix (data,N,M, "График", "x", "y",NameLine);

    for (int i=0;i<N;i++) delete [] data[i];
    delete [] data;
    delete [] NameLine;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_ShowChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N, VMHL_M, TitleChart, NameVectorX, NameVectorY,NameLine, true, true, false, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VMHL_MatrixXY,int VMHL_N,int VMHL_M)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых переменных и названий осей, графиков - все по умолчанию.
    Входные параметры:
     VMHL_MatrixXY - указатель на матрицу значений X и Н графиков;
     VMHL_N - количество точек;
     VMHL_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M-1 (так как первый столбец - это X значения);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    int M=2;
    double **data;
    data=new double*[N];
    for (int i=0;i<N;i++) X[i]=new double[M];
    data[0][0]=7;data[0][1]=6;
    data[1][0]=8;data[1][1]=4;
    data[2][0]=10;data[2][1]=7;
    data[3][0]=5;data[3][1]=12;
    data[4][0]=14;data[4][1]=4;
    data[5][0]=13;data[5][1]=8;

    Html += THQt_ShowChartsOfLineFromMatrix (data,N,M);

    for (int i=0;i<N;i++) delete [] data[i];
    delete [] data;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;
    QString *NameLine=new QString[VMHL_M-1];
    for (int i=0;i<VMHL_M-1;i++) NameLine[i]="";

    VMHL_Result = THQt_ShowChartsOfLineFromMatrix (VMHL_MatrixXY, VMHL_N, VMHL_M, "", "x", "y",NameLine, true, true, false, true);

    delete [] NameLine;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Н графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную ошбласть под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VMHL_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString CoordinateColor="#88969c";
    QString HighlightCoordinateColor="#3c7693";

    QString *Color=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) Color[j]="#97bbcd";

    QString *HighlightColor=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) HighlightColor[j]="#3c7693";

    QString *ColorArea=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) ColorArea[j]="#97bbcd";

    QString *OpacityArea=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) OpacityArea[j]="0.5";

    QString *StrokeWidth=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) StrokeWidth[j]="2";

    QString *StrokeWidthPoints=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) StrokeWidthPoints[j]="2";

    QString *FaceOfLine=new QString [VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) FaceOfLine[j]="o";

    if (VMHL_M/2==2)//если два графика
    {
        Color[1]="#cccccc";
        HighlightColor[1]="#7e7e7e";
        ColorArea[1]="#cccccc";
    }
    if ((VMHL_M/2==3)&&(ShowArea))//если три графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";
        ColorArea[1]="#97bbcd";
        OpacityArea[1]="0.5";

        Color[2]="#cccccc";
        HighlightColor[2]="#7e7e7e";
        ColorArea[2]="#cccccc";
        OpacityArea[2]="0.5";
    }
    if ((VMHL_M/2==3)&&(!ShowArea))//если три графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e06c65";
        HighlightColor[2]="#9d2b24";
    }
    if ((VMHL_M/2==4)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#cccccc";
        HighlightColor[3]="#7e7e7e";
        ColorArea[3]="#cccccc";
        OpacityArea[3]="0.5";
    }
    if ((VMHL_M/2==4)&&(!ShowArea))//если 4 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";
    }
    if ((VMHL_M/2==5)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#cccccc";
        HighlightColor[4]="#7e7e7e";
        ColorArea[4]="#cccccc";
        OpacityArea[4]="0.5";
    }
    if ((VMHL_M/2==5)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";

        Color[4]="#9d50c8";
        HighlightColor[4]="#6a2b8d";
    }
    if ((VMHL_M/2==6)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#bec7cd";
        HighlightColor[4]="#5c7483";
        ColorArea[4]="#bec7cd";
        OpacityArea[4]="0.5";

        Color[5]="#cccccc";
        HighlightColor[5]="#7e7e7e";
        ColorArea[5]="#cccccc";
        OpacityArea[5]="0.5";
    }
    if ((VMHL_M/2==6)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#b5d24e";
        HighlightColor[2]="#8ca72c";

        Color[3]="#e7cc4c";
        HighlightColor[3]="#b49c28";

        Color[4]="#e06c65";
        HighlightColor[4]="#9d2b24";

        Color[5]="#9d50c8";
        HighlightColor[5]="#6a2b8d";
    }
    if ((VMHL_M/2==7)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#97bbcd";
        HighlightColor[3]="#3c7693";
        ColorArea[3]="#97bbcd";
        OpacityArea[3]="0.5";

        Color[4]="#adc2cd";
        HighlightColor[4]="#58839a";
        ColorArea[4]="#adc2cd";
        OpacityArea[4]="0.5";

        Color[5]="#bec7cd";
        HighlightColor[5]="#5c7483";
        ColorArea[5]="#bec7cd";
        OpacityArea[5]="0.5";

        Color[6]="#cccccc";
        HighlightColor[6]="#7e7e7e";
        ColorArea[6]="#cccccc";
        OpacityArea[6]="0.5";
    }
    if ((VMHL_M/2==7)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";
    }
    if ((VMHL_M/2==8)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#bec7cd";
        HighlightColor[6]="#5c7483";
        ColorArea[6]="#bec7cd";
        OpacityArea[6]="0.5";

        Color[7]="#cccccc";
        HighlightColor[7]="#7e7e7e";
        ColorArea[7]="#cccccc";
        OpacityArea[7]="0.5";
    }
    if ((VMHL_M/2==8)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";

        Color[7]="#c64f8f";
        HighlightColor[7]="#8d275e";
    }
    if ((VMHL_M/2==9)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#b6c5cd";
        HighlightColor[6]="#617580";
        ColorArea[6]="#b6c5cd";
        OpacityArea[6]="0.5";

        Color[7]="#bec7cd";
        HighlightColor[7]="#5c7483";
        ColorArea[7]="#bec7cd";
        OpacityArea[7]="0.5";

        Color[8]="#cccccc";
        HighlightColor[8]="#7e7e7e";
        ColorArea[8]="#cccccc";
        OpacityArea[8]="0.5";
    }
    if ((VMHL_M/2==9)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e9ac4c";
        HighlightColor[5]="#946b2c";

        Color[6]="#e06c65";
        HighlightColor[6]="#9d2b24";

        Color[7]="#9d50c8";
        HighlightColor[7]="#6a2b8d";

        Color[8]="#c64f8f";
        HighlightColor[8]="#8d275e";
    }
    if ((VMHL_M/2>9)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VMHL_M/2;j++)
        {
            position=j/double(VMHL_M/2);
            Color[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#537c90";
            HighlightColor[j]="#26576f";
            ColorArea[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#799bac";
            OpacityArea[j]="0.5";
        }
    }
    if ((VMHL_M/2>9)&&(!ShowArea))//если 4 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VMHL_M/2;j++)
        {
            position=j/double(VMHL_M/2);
            Color[j]=THQt_AlphaBlendingColorToColor(0.4,THQt_GiveRainbowColorRGB(position),"#ffffff");
            HighlightColor[j]="#26576f";
        }
    }
    //по точкам пройдемся
    if (VMHL_M/2>=3)
    {
        FaceOfLine[1]="[]";
        StrokeWidthPoints[1]="2";

        FaceOfLine[2]="<>";
        StrokeWidthPoints[2]="3";
    }
    if (VMHL_M/2>=4)
    {
        FaceOfLine[3]="x";
        StrokeWidthPoints[3]="3";
    }
    if (VMHL_M/2>=5)
    {
        FaceOfLine[4]="+";
        StrokeWidthPoints[4]="3";
    }
    if (VMHL_M/2>=6)
    {
        FaceOfLine[5]="^";
        StrokeWidthPoints[5]="3";
    }
    if (VMHL_M/2>=7)
    {
        FaceOfLine[6]="v";
        StrokeWidthPoints[6]="3";
    }
    if (VMHL_M/2>=8)
    {
        FaceOfLine[7]=">";
        StrokeWidthPoints[7]="3";
    }
    if (VMHL_M/2>=9)
    {
        FaceOfLine[8]="<";
        StrokeWidthPoints[8]="3";
    }
    //когда уменьшать толщину линии
    if (VMHL_M/2>5)
        for (j=0;j<VMHL_M/2;j++)
        {
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]=QString::number((StrokeWidthPoints[j].toInt())-1);
        }
    if (VMHL_M/2>9)//слишком много кривых
    {
        for (j=0;j<VMHL_M/2;j++)
        {
            FaceOfLine[j]="o";
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]="1";
        }
    }

    //Подсчитаем максимальное число N
    int VMHL_N_Max;
    VMHL_N_Max = VMHL_N_EveryCol[0];
    for (j=0;j<VMHL_M/2;j++)
        if (VMHL_N_EveryCol[j*2]>VMHL_N_Max)
            VMHL_N_Max=VMHL_N_EveryCol[j*2];

    //посчитаем гарницы изменения параметров
    T MinX=VMHL_MatrixXY[0][0];
    for (j=0;j<VMHL_M/2;j++)
        for (int i=0;i<VMHL_N_EveryCol[j*2];i++)
            if (VMHL_MatrixXY[i][j*2]<MinX)
                MinX=VMHL_MatrixXY[i][j*2];

    T MaxX=VMHL_MatrixXY[0][0];
    for (j=0;j<VMHL_M/2;j++)
        for (int i=0;i<VMHL_N_EveryCol[j*2];i++)
            if (VMHL_MatrixXY[i][j*2]>MaxX)
                MaxX=VMHL_MatrixXY[i][j*2];

    T MinY=VMHL_MatrixXY[0][1];
    for (j=0;j<VMHL_M/2;j++)
        for (int i=0;i<VMHL_N_EveryCol[j*2+1];i++)
            if (VMHL_MatrixXY[i][j*2+1]<MinY)
                MinY=VMHL_MatrixXY[i][j*2+1];

    T MaxY=VMHL_MatrixXY[0][1];
    for (j=0;j<VMHL_M/2;j++)
        for (int i=0;i<VMHL_N_EveryCol[j*2+1];i++)
            if (VMHL_MatrixXY[i][j*2+1]>MaxY)
                MaxY=VMHL_MatrixXY[i][j*2+1];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VMHL_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VMHL_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;

    QString *NameDataX=new QString[VMHL_M/2];
    QString *NameDataY=new QString[VMHL_M/2];
    QString *NameDataXArea=new QString[VMHL_M/2];
    QString *NameDataYArea=new QString[VMHL_M/2];
    QString *NameChart=new QString[VMHL_M/2];
    for (j=0;j<VMHL_M/2;j++) NameDataX[j]="DataX"+QString::number(j+1)+UniqueName;
    for (j=0;j<VMHL_M/2;j++) NameDataXArea[j]="DataX"+QString::number(j+1)+"Area"+UniqueName;
    for (j=0;j<VMHL_M/2;j++) NameDataY[j]="DataY"+QString::number(j+1)+UniqueName;
    for (j=0;j<VMHL_M/2;j++) NameDataYArea[j]="DataY"+QString::number(j+1)+"Area"+UniqueName;
    for (j=0;j<VMHL_M/2;j++) NameChart[j]="Chart"+QString::number(j+1)+UniqueName;

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VMHL_MatrixXY;
    Temp_VMHL_MatrixXY=new double*[VMHL_N_Max];
    for (i=0;i<VMHL_N_Max;i++) Temp_VMHL_MatrixXY[i]=new double[VMHL_M];
    for (j=0;j<VMHL_M;j++)
        for (i=0;i<VMHL_N_EveryCol[j];i++)
            Temp_VMHL_MatrixXY[i][j]=VMHL_MatrixXY[i][j];

    //отсортируем массивы
    for (k=0;k<VMHL_M/2;k++)
    {
    for(i=VMHL_N_EveryCol[2*k]-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_MatrixXY[j][2*k]>Temp_VMHL_MatrixXY[j+1][2*k])
            {
                    T x;
                    x=Temp_VMHL_MatrixXY[j+1][2*k];
                    Temp_VMHL_MatrixXY[j+1][2*k]=Temp_VMHL_MatrixXY[j][2*k];
                    Temp_VMHL_MatrixXY[j][2*k]=x;

                    x=Temp_VMHL_MatrixXY[j+1][2*k+1];
                    Temp_VMHL_MatrixXY[j+1][2*k+1]=Temp_VMHL_MatrixXY[j][2*k+1];
                    Temp_VMHL_MatrixXY[j][2*k+1]=x;
            }
    }

    //рисуем область графика и оси
    VMHL_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VMHL_Result+="<script type=\"text/javascript\">\n";
    VMHL_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VMHL_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VMHL_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";


    //соберем в массивы javascript данные точек
    QString *SDataX = new QString[VMHL_M/2];
    QString *SDataY = new QString[VMHL_M/2];

    for (j=0;j<VMHL_M/2;j++)
    {
        for (i=0;i<VMHL_N_EveryCol[2*j]-1;i++)
            SDataX[j]+=QString::number(Temp_VMHL_MatrixXY[i][2*j])+", ";
        SDataX[j]+=QString::number(Temp_VMHL_MatrixXY[VMHL_N_EveryCol[2*j+1]-1][2*j]);
    }

    for (j=0;j<VMHL_M/2;j++)
    {
        for (i=0;i<VMHL_N_EveryCol[2*j+1]-1;i++)
            SDataY[j]+=QString::number(Temp_VMHL_MatrixXY[i][2*j+1])+", ";
        SDataY[j]+=QString::number(Temp_VMHL_MatrixXY[VMHL_N_EveryCol[2*j+1]-1][2*j+1]);
    }

    //запишем массивы точек
    for (j=0;j<VMHL_M/2;j++)
    {
        VMHL_Result+="var "+NameDataX[j]+" = ["+SDataX[j]+"];\n";
        VMHL_Result+="var "+NameDataY[j]+" = ["+SDataY[j]+"];\n";
    }

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        for (j=0;j<VMHL_M/2;j++)
        {
            SDataX[j]=QString::number(Temp_VMHL_MatrixXY[0][2*j])+", "+SDataX[j]+", "+QString::number(Temp_VMHL_MatrixXY[VMHL_N_EveryCol[j*2]-1][2*j])+", "+QString::number(Temp_VMHL_MatrixXY[0][2*j]);
        }

        for (j=0;j<VMHL_M/2;j++)
            SDataY[j]=SBeginYAxis+", "+SDataY[j]+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        for (j=0;j<VMHL_M/2;j++)
        VMHL_Result+="var "+NameDataXArea[j]+" = ["+SDataX[j]+"];\n";
        for (j=0;j<VMHL_M/2;j++)
            VMHL_Result+="var "+NameDataYArea[j]+" = ["+SDataY[j]+"];\n";
        for (j=0;j<VMHL_M/2;j++)
            VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea[VMHL_M/2-1-j]+","+NameDataYArea[VMHL_M/2-1-j]+"],{strokeColor:'"+ColorArea[VMHL_M/2-1-j]+"',highlightStrokeColor:'"+ColorArea[VMHL_M/2-1-j]+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+ColorArea[VMHL_M/2-1-j]+"',highlightFillColor:'"+ColorArea[VMHL_M/2-1-j]+"',fillOpacity:"+OpacityArea[VMHL_M/2-1-j]+",highlightFillOpacity:"+OpacityArea[VMHL_M/2-1-j]+"});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VMHL_M/2;j++)
        {
            VMHL_Result+="var "+NameChart[VMHL_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VMHL_M/2-1-j]+","+NameDataY[VMHL_M/2-1-j]+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart[VMHL_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VMHL_M/2-1-j]+"');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N_EveryCol[VMHL_M-1-2*j])+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart[VMHL_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VMHL_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VMHL_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VMHL_M/2-1-j]+"', size:"+StrokeWidthPoints[VMHL_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VMHL_M/2-1-j]+"pt'});\n";
            VMHL_Result+="    }\n";
        }
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки
        for (j=0;j<VMHL_M/2;j++)
        {
            VMHL_Result+="var "+NameChart[VMHL_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VMHL_M/2-1-j]+","+NameDataY[VMHL_M/2-1-j]+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart[VMHL_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M/2-1-j]+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N_EveryCol[VMHL_M-1-2*j])+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart[VMHL_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VMHL_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VMHL_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VMHL_M/2-1-j]+"', size:"+StrokeWidthPoints[VMHL_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VMHL_M/2-1-j]+"pt'});\n";
            VMHL_Result+="    }\n";
        }
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию
        for (j=0;j<VMHL_M/2;j++)
        {
            VMHL_Result+="var "+NameChart[VMHL_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VMHL_M/2-1-j]+","+NameDataY[VMHL_M/2-1-j]+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart[VMHL_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VMHL_M/2-1-j]+"');\n";
        }
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VMHL_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VMHL_Result+="</script>\n";

    // ЛЕГЕНДА
    int NameLineHowManyEmpty=0;
    for (j=0;j<VMHL_M/2;j++) if (NameLine[j].trimmed().isEmpty()!=true) NameLineHowManyEmpty++;

    if (NameLineHowManyEmpty!=0)
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;

        QString *NameDataYLegend= new QString[VMHL_M/2];
        QString *NameChartLegend= new QString[VMHL_M/2];
        QString *NameTextLegend= new QString[VMHL_M/2];

        for (j=0;j<VMHL_M/2;j++) NameDataYLegend[j]="DataY"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VMHL_M/2;j++) NameChartLegend[j]="Chart"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VMHL_M/2;j++) NameTextLegend[j]="Text"+QString::number(j+1)+"Legend"+UniqueNameLegend;


        //рисуем область графика и оси
        VMHL_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:"+QString::number(50*(VMHL_M/2))+"px;\"></div>\n";
        VMHL_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox=QString::number(VMHL_M/2+1);
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VMHL_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";

        for (j=0;j<VMHL_M/2;j++) SDataY[j]=QString::number(VMHL_M/2-j)+", "+QString::number(VMHL_M/2-j);

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            for (j=0;j<VMHL_M/2;j++) SDataY[j]=QString::number(VMHL_M/2-j)+", "+QString::number(VMHL_M/2-j)+", "+QString::number(VMHL_M/2-j);
        }

        //запишем массивы точек

        VMHL_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        for (j=0;j<VMHL_M/2;j++)
            VMHL_Result+="var "+NameDataYLegend[j]+" = ["+SDataY[j]+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            for (j=0;j<VMHL_M/2;j++)
            {
                VMHL_Result+="var "+NameChartLegend[VMHL_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VMHL_M/2-1-j]+"], {chartStyle:'line,point'});\n";
                VMHL_Result+=NameChartLegend[VMHL_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VMHL_M/2-1-j]+"');\n";
                VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
                VMHL_Result+="    {\n";
                VMHL_Result+="    "+NameChartLegend[VMHL_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VMHL_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VMHL_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VMHL_M/2-1-j]+"', size:"+StrokeWidthPoints[VMHL_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VMHL_M/2-1-j]+"pt'});\n";
                VMHL_Result+="    }\n";
            }
        }

        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            for (j=0;j<VMHL_M/2;j++)
            {
                VMHL_Result+="var "+NameChartLegend[VMHL_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VMHL_M/2-1-j]+"], {chartStyle:'line,point'});\n";
                VMHL_Result+=NameChartLegend[VMHL_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M/2-1-j]+"','strokeWidth:0');\n";
                VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
                VMHL_Result+="    {\n";
                VMHL_Result+="    "+NameChartLegend[VMHL_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VMHL_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VMHL_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VMHL_M/2-1-j]+"', size:"+StrokeWidthPoints[VMHL_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VMHL_M/2-1-j]+"pt'});\n";
                VMHL_Result+="    }\n";
            }
        }

        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            for (j=0;j<VMHL_M/2;j++)
            {
                VMHL_Result+="var "+NameChartLegend[VMHL_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VMHL_M/2-1-j]+"], {chartStyle:'line'});\n";
                VMHL_Result+=NameChartLegend[VMHL_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VMHL_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VMHL_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VMHL_M/2-1-j]+"');\n";
            }
        }

        //напишем текст
        QString Delim=";";
        for (j=0;j<VMHL_M/2;j++)
        {
            if (j==VMHL_M/2-1) Delim=".";
            VMHL_Result+=NameTextLegend[j]+" = "+NameBoardLegend+".create('text',[2.2,"+QString::number(VMHL_M/2-j)+", \"- "+NameLine[j]+Delim+"\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        }

        VMHL_Result+="</script>\n";

        delete [] NameDataYLegend;
        delete [] NameChartLegend;
        delete [] NameTextLegend;
    }

    delete [] Color;
    delete [] HighlightColor;
    delete [] StrokeWidth;
    delete [] FaceOfLine;
    delete [] StrokeWidthPoints;
    delete [] ColorArea;
    delete [] OpacityArea;

    delete [] NameDataY;
    delete [] NameDataYArea;
    delete [] NameChart;
    delete [] SDataX;
    delete [] SDataY;

    for (i=0;i<VMHL_N_Max;i++) delete [] Temp_VMHL_MatrixXY[i];
    delete [] Temp_VMHL_MatrixXY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием легенды на графике.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Н графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную ошбласть под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VMHL_Result;//переменная итогового результата

    QString *NameLine=new QString[VMHL_M/2];
    for (int i=0;i<VMHL_M/2;i++) NameLine[i]="";

    VMHL_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY,VMHL_N_EveryCol,VMHL_M,TitleChart, NameVectorX, NameVectorY,NameLine, ShowLine,ShowPoints, ShowArea,ShowSpecPoints);
    delete [] NameLine;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием булевых переменных - все по умолчанию.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Н графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VMHL_Result;//переменная итогового результата

    VMHL_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY,VMHL_N_EveryCol,VMHL_M,TitleChart, NameVectorX, NameVectorY,NameLine,  true,true, false,true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VMHL_MatrixXY,int *VMHL_N_EveryCol,int VMHL_M)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием булевых переменных, названий осей, графиков - все по умолчанию.
Входные параметры:
 VMHL_MatrixXY - указатель на матрицу значений X и Н графиков;
 VMHL_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VMHL_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VMHL_M/2.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VMHL_Result;//переменная итогового результата

    QString *NameLine=new QString[VMHL_M/2];
    for (int i=0;i<VMHL_M/2;i++) NameLine[i]="";

    VMHL_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VMHL_MatrixXY,VMHL_N_EveryCol,VMHL_M,"", "x", "y",NameLine, true,true, false,true);
    delete [] NameLine;

    return VMHL_Result;    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VMHL_VectorX1 - указатель на вектор координат X точек первой линии;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_N1 - количество точек первой линии;
     VMHL_VectorX2 - указатель на вектор координат X точек второй линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,true);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VMHL_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString CoordinateColor="#88969c";

    QString Color="#e94939";
    QString HighlightColor="#9d3e38";

    //QString Color="#4b8aaa";
    //QString HighlightColor="#21546d";

    QString Color2="#97bbcd";
    QString HighlightColor2="#3c7693";


    //посчитаем гарницы изменения параметров
    T MinX1=VMHL_VectorX1[0];
    for (int i=1;i<VMHL_N1;i++)
        if (VMHL_VectorX1[i]<MinX1)
            MinX1=VMHL_VectorX1[i];

    T MinX2=VMHL_VectorX2[0];
    for (int i=1;i<VMHL_N2;i++)
        if (VMHL_VectorX2[i]<MinX2)
            MinX2=VMHL_VectorX2[i];

    T MinY1=VMHL_VectorY1[0];
    for (int i=1;i<VMHL_N1;i++)
        if (VMHL_VectorY1[i]<MinY1)
            MinY1=VMHL_VectorY1[i];

    T MinY2=VMHL_VectorY2[0];
    for (int i=1;i<VMHL_N2;i++)
        if (VMHL_VectorY2[i]<MinY2)
            MinY2=VMHL_VectorY2[i];

    T MaxX1=VMHL_VectorX1[0];
    for (int i=1;i<VMHL_N1;i++)
        if (VMHL_VectorX1[i]>MaxX1)
            MaxX1=VMHL_VectorX1[i];

    T MaxX2=VMHL_VectorX2[0];
    for (int i=1;i<VMHL_N2;i++)
        if (VMHL_VectorX2[i]>MaxX2)
            MaxX2=VMHL_VectorX2[i];

    T MaxY1=VMHL_VectorY1[0];
    for (int i=1;i<VMHL_N1;i++)
        if (VMHL_VectorY1[i]>MaxY1)
            MaxY1=VMHL_VectorY1[i];

    T MaxY2=VMHL_VectorY2[0];
    for (int i=1;i<VMHL_N2;i++)
        if (VMHL_VectorY2[i]>MaxY2)
            MaxY2=VMHL_VectorY2[i];

    T MinX;
    T MaxX;

    T MinY;
    T MaxY;

    if (MinX1<MinX2)
        MinX=MinX1;
    else
        MinX=MinX2;

    if (MaxX1>MaxX2)
        MaxX=MaxX1;
    else
        MaxX=MaxX2;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VMHL_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VMHL_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX1="DataX1"+UniqueName;
    QString NameDataX2="DataX2"+UniqueName;
    QString NameDataY1="DataY1"+UniqueName;
    QString NameDataY2="DataY2"+UniqueName;
    QString NameDataX1Area="DataX1Area"+UniqueName;
    QString NameDataX2Area="DataX2Area"+UniqueName;
    QString NameDataY1Area="DataY1Area"+UniqueName;
    QString NameDataY2Area="DataY2Area"+UniqueName;
    QString NameChart1="Chart1"+UniqueName;
    QString NameChart2="Chart2"+UniqueName;

    //рисуем область графика и оси
    VMHL_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VMHL_Result+="<script type=\"text/javascript\">\n";
    VMHL_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VMHL_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VMHL_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VMHL_VectorX1=new T[VMHL_N1];
    T *Temp_VMHL_VectorX2=new T[VMHL_N2];
    T *Temp_VMHL_VectorY1=new T[VMHL_N1];
    T *Temp_VMHL_VectorY2=new T[VMHL_N2];
    for (i=0;i<VMHL_N1;i++) Temp_VMHL_VectorX1[i]=VMHL_VectorX1[i];
    for (i=0;i<VMHL_N2;i++) Temp_VMHL_VectorX2[i]=VMHL_VectorX2[i];
    for (i=0;i<VMHL_N1;i++) Temp_VMHL_VectorY1[i]=VMHL_VectorY1[i];
    for (i=0;i<VMHL_N2;i++) Temp_VMHL_VectorY2[i]=VMHL_VectorY2[i];

    //отсортируем массивы
    for(i=VMHL_N1-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_VectorX1[j]>Temp_VMHL_VectorX1[j+1])
            {
                T x;
                x=Temp_VMHL_VectorX1[j+1];
                Temp_VMHL_VectorX1[j+1]=Temp_VMHL_VectorX1[j];
                Temp_VMHL_VectorX1[j]=x;
                x=Temp_VMHL_VectorY1[j+1];
                Temp_VMHL_VectorY1[j+1]=Temp_VMHL_VectorY1[j];
                Temp_VMHL_VectorY1[j]=x;
            }

    for(i=VMHL_N2-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VMHL_VectorX2[j]>Temp_VMHL_VectorX2[j+1])
            {
                T x;
                x=Temp_VMHL_VectorX2[j+1];
                Temp_VMHL_VectorX2[j+1]=Temp_VMHL_VectorX2[j];
                Temp_VMHL_VectorX2[j]=x;
                x=Temp_VMHL_VectorY2[j+1];
                Temp_VMHL_VectorY2[j+1]=Temp_VMHL_VectorY2[j];
                Temp_VMHL_VectorY2[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX1;
    QString SDataX2;
    QString SDataY1;
    QString SDataY2;

    for (i=0;i<VMHL_N1-1;i++)
        SDataX1+=QString::number(Temp_VMHL_VectorX1[i])+", ";
    SDataX1+=QString::number(Temp_VMHL_VectorX1[VMHL_N1-1]);

    for (i=0;i<VMHL_N2-1;i++)
        SDataX2+=QString::number(Temp_VMHL_VectorX2[i])+", ";
    SDataX2+=QString::number(Temp_VMHL_VectorX2[VMHL_N2-1]);

    for (i=0;i<VMHL_N1-1;i++)
        SDataY1+=QString::number(Temp_VMHL_VectorY1[i])+", ";
    SDataY1+=QString::number(Temp_VMHL_VectorY1[VMHL_N1-1]);

    for (i=0;i<VMHL_N2-1;i++)
        SDataY2+=QString::number(Temp_VMHL_VectorY2[i])+", ";
    SDataY2+=QString::number(Temp_VMHL_VectorY2[VMHL_N2-1]);

    //запишем массивы точек
    VMHL_Result+="var "+NameDataX1+" = ["+SDataX1+"];\n";
    VMHL_Result+="var "+NameDataX2+" = ["+SDataX2+"];\n";
    VMHL_Result+="var "+NameDataY1+" = ["+SDataY1+"];\n";
    VMHL_Result+="var "+NameDataY2+" = ["+SDataY2+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX2=QString::number(MinX2)+", "+SDataX2+", "+QString::number(MaxX2)+", "+QString::number(MinX2);
        SDataY2=SBeginYAxis+", "+SDataY2+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VMHL_Result+="var "+NameDataX2Area+" = ["+SDataX2+"];\n";
        VMHL_Result+="var "+NameDataY2Area+" = ["+SDataY2+"];\n";
        VMHL_Result+=NameBoard+".create('curve', ["+NameDataX2Area+","+NameDataY2Area+"],{strokeColor:'"+Color2+"',highlightStrokeColor:'"+Color2+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color2+"',highlightFillColor:'"+Color2+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N2)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N2)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    //Рисуем вторые точки всегда
    {
        //Нарисуем точки
        VMHL_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX1+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N1)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:1, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию 2
        VMHL_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line'});\n";
        VMHL_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
}

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VMHL_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VMHL_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine1.trimmed().isEmpty()))&& (!(NameLine2.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataY1Legend="DataY1Legend"+UniqueNameLegend;
        QString NameDataY2Legend="DataY2Legend"+UniqueNameLegend;
        QString NameChart1Legend="Chart1Legend"+UniqueNameLegend;
        QString NameChart2Legend="Chart2Legend"+UniqueNameLegend;
        QString NameText1Legend="Text1Legend"+UniqueName;
        QString NameText2Legend="Text2Legend"+UniqueName;


        //рисуем область графика и оси
        VMHL_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:100px;\"></div>\n";
        VMHL_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="3";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VMHL_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";
        SDataY2="1, 1";

        QString SDataX1="1, 1.5, 2";
        SDataY1="2, 2, 2";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY2="1, 1, 1";
        }

        //запишем массивы точек
        VMHL_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataXLegend+"1 = ["+SDataX1+"];\n";
        VMHL_Result+="var "+NameDataY1Legend+" = ["+SDataY1+"];\n";
        VMHL_Result+="var "+NameDataY2Legend+" = ["+SDataY2+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию 2
            VMHL_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line'});\n";
            VMHL_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        }

        //Всегда рисуем точки
        {
            //Нарисуем точки
            VMHL_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+"1,"+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VMHL_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VMHL_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VMHL_Result+="    {\n";
            VMHL_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:1, strokeWidth:'2pt'});\n";
            VMHL_Result+="    }\n";
        }

        //напишем текст
        VMHL_Result+=NameText1Legend+" = "+NameBoardLegend+".create('text',[2.2,2, \"- "+NameLine1+";\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        VMHL_Result+=NameText2Legend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine2+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VMHL_Result+="</script>\n";
    }

    delete [] Temp_VMHL_VectorX1;
    delete [] Temp_VMHL_VectorX2;
    delete [] Temp_VMHL_VectorY1;
    delete [] Temp_VMHL_VectorY2;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием легенды, то есть параметров NameLine1, NameLine2.
    Входные параметры:
     VMHL_VectorX1 - указатель на вектор координат X точек первой линии;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_N1 - количество точек первой линии;
     VMHL_VectorX2 - указатель на вектор координат X точек второй линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y",true,true,true,true);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfPointsAndLine (VMHL_VectorX1,VMHL_VectorY1, VMHL_N1,VMHL_VectorX2,VMHL_VectorY2, VMHL_N2, TitleChart, NameVectorX, NameVectorY,"", "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых параметров - все по умолчанию.
    Входные параметры:
     VMHL_VectorX1 - указатель на вектор координат X точек первой линии;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_N1 - количество точек первой линии;
     VMHL_VectorX2 - указатель на вектор координат X точек второй линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y","количество деревьев","количество домов");

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfPointsAndLine (VMHL_VectorX1,VMHL_VectorY1,VMHL_N1,VMHL_VectorX2,VMHL_VectorY2, VMHL_N2, TitleChart, NameVectorX, NameVectorY,NameLine1, NameLine2,true,false,false,true);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VMHL_VectorX1,T *VMHL_VectorY1,int VMHL_N1,T *VMHL_VectorX2,T *VMHL_VectorY2, int VMHL_N2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых параметров и подписей - все по умолчанию.
    Входные параметры:
     VMHL_VectorX1 - указатель на вектор координат X точек первой линии;
     VMHL_VectorY1 - указатель на вектор координат Y точек первой линии;
     VMHL_N1 - количество точек первой линии;
     VMHL_VectorX2 - указатель на вектор координат X точек второй линии;
     VMHL_VectorY2 - указатель на вектор координат Y точек второй линии;
     VMHL_N2 - количество точек второй линии.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,N1,dataX2,dataY2,N2);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfPointsAndLine (VMHL_VectorX1,VMHL_VectorY1,VMHL_N1,VMHL_VectorX2,VMHL_VectorY2, VMHL_N2, "", "x", "y","", "",true,false,false,true);
}
//---------------------------------------------------------------------------

#endif // QTHARRIXLIBRARY_H
