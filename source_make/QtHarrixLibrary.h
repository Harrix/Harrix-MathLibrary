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
int HQt_SizeMatrixOrVectorFromQStringList(QStringList QStringListFromFile, int* VMHL_Result_M);//Функция подсчитывает сколько строк и столбцов в текстовом файле, который скопировали в QStringListFromFile.
int HQt_SizeMatrixOrVectorFromQStringList(QStringList QStringListFromFile);//Функция подсчитывает сколько строк в текстовом файле, который скопировали в QStringListFromFile.
template <class T> void THQt_ReadVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult);//Функция считывает данные из QStringList в вектор.
template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult1, T *VMHL_VectorResult2);//Функция считывает данные из QStringList в два вектора.
template <class T> void THQt_ReadTwoVectorFromQStringList(QStringList QStringListFromFile, T *VMHL_VectorResult1, QDate *VMHL_VectorResult2);//Функция считывает данные из QStringList в два вектора (второй вектор - это даты).
template <class T> void THQt_ReadMatrixFromQStringList(QStringList QStringListFromFile, T **VMHL_MatrixResult);//Функция считывает данные из QStringList в матрицу.
template <class T> void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, T *VMHL_VectorResult);//Функция считывает данные какого-то k столбца из QStringList в виде матрицы.
void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QDate *VMHL_VectorResult);//Функция считывает данные какого-то k столбца с датами из QStringList в виде матрицы.

//Для отображения HTML текста
QString HQt_BeginHtml (); //Функция возвращает строку с началом HTML файла, в который другими функциями добавляются иные данные.
QString HQt_EndHtml (); //Функция возвращает строку с концовкой HTML файла, в который другими функциями добавляются иные данные.
QString HQt_ShowText (QString TitleX);
template <class T> QString THQt_ShowNumber (T VMHL_X, QString TitleX, QString NameX);//Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами.
template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);//Функция возвращает строку с выводом некоторый вектора VMHL_Vector с HTML кодами.
template <class T> QString THQt_NumberToText (T VMHL_X);//Функция выводит число VMHL_X в строку.
template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);//Функция возвращает строку с выводом некоторый вектора VMHL_Vector в траснпонированном виде с HTML кодами.
template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);//Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами.
template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine=true,bool ShowPoints=true,bool ShowArea=true,bool ShowSpecPoints=true);//Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.

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
N=HQt_SizeMatrixOrVectorFromQStringList(List);
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
N=HQt_SizeMatrixOrVectorFromQStringList(List);
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
    Пример использования:
///////////////////////////////////

QString DS=QDir::separator();
QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке
QStringList List = HQt_ReadFileToQStringList(path+"5.txt");

int N,M;
N=HQt_SizeMatrixOrVectorFromQStringList(List,&M);

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
    N = HQt_SizeMatrixOrVectorFromQStringList(QStringListFromFile,&M);
    QString A,X;

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
     Отсуствует.
    Примечание:
     Десятичные числа должны разделяться точкой.
    Пример содержимого VMHL_VectorResult.
1	2	6
52	3	96
6.4	7	4
    Пример использования:
///////////////////////////////////
QString DS=QDir::separator();
QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

QStringList List = HQt_ReadFileToQStringList(path+"5.txt");
int N;
N=HQt_SizeMatrixOrVectorFromQStringList(List);

double *X;
X=new double[N];

int k=2;//номер столбца

THQt_ReadColFromQStringList(List, k, X);

delete [] X;
///////////////////////////////////
    */
    int i,j;
    int N,M;
    N = HQt_SizeMatrixOrVectorFromQStringList(QStringListFromFile,&M);
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

    VMHL_Result+=NameX+"=<b><font color=\"#4200ff\">"+QString::number(VMHL_X)+"</font></b></p>\n";

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
    VMHL_Result="<b><font color=\"#4200ff\">"+QString::number(VMHL_X)+"</font></b>";
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
        VMHL_Result+="<td><b><font color=\"#4200ff\">"+QString::number(VMHL_Vector[i])+"</font></b></td>\n";

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
        VMHL_Result+="<td><b><font color=\"#4200ff\">"+QString::number(VMHL_Vector[i])+"</font></b></td>\n";
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
            VMHL_Result+="<td><b><font color=\"#4200ff\">"+QString::number(VMHL_Matrix[i][j])+"</font></b></td>\n";

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
template <class T> QString THQt_ShowChartOfLine (T *VMHL_VectorX,T *VMHL_VectorY, int VMHL_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine=true,bool ShowPoints=true,bool ShowArea=true,bool ShowSpecPoints=true)
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
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y",true,true);
    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y",true,false);
    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y",false,true);
    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y",false,false);

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

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        VMHL_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }
    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем график
        VMHL_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line,point'});\n";
        VMHL_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VMHL_Result+="for(var i=0; i<"+QString::number(VMHL_N)+";i++) \n";
        VMHL_Result+="    {\n";
        VMHL_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VMHL_Result+="    }\n";
    }
    if ((!ShowPoints)&&(ShowLine))
    {
        VMHL_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line'});\n";
        VMHL_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
    }

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);
        SDataY=SBeginYAxis+", "+SDataY+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VMHL_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        VMHL_Result+="var "+NameDataYArea+" = ["+SDataY+"];\n";
        VMHL_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub>="+SBeginXAxis+", Min<sub>y</sub>="+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VMHL_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub>="+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VMHL_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub>="+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VMHL_Result+="</script>\n";

    delete [] Temp_VMHL_VectorX;
    delete [] Temp_VMHL_VectorY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

#endif // QTHARRIXLIBRARY_H
