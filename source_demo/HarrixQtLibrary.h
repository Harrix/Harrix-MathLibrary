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
bool HQt_DirExists(QString path);//Функция проверяет сущестование директории.
void HQt_DirMake(QString path);//Функция проверяет сущестование директории, и если ее нет, то создает.
QString HQt_GetNameFromFilename(QString filename);//Функция получает имя файла без расширения по его имени.
bool HQt_CopyFile(QString filename, QString dir);//Функция копирует файл filename в папку dir.
bool HQt_CopyFile(QString filename, QString dir, bool overwrite);//Функция копирует файл filename в папку dir, с возможносью перезаписи.
bool HQt_RenameFile(QString filename, QString newfilename);//Функция переименовывает файл filename в newfilename.
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
QStringList HQt_AddUniqueQStringInQStringList (QStringList StringList, QString String);//Функция добавляет в QStringList строку QString. Но если такая строка уже присутствует, то добавление не происходит.
int HQt_SearchQStringInQStringList (QStringList StringList, QString String);//Функция ищет в QStringList строку QString (номер первого вхождения).
QString HQt_StringForLaTeX (QString String);//Функция обрабатывает строку String так, чтобы она подходила длz публикации в LaTeX.
QString HQt_StringToLabelForLaTeX (QString String);//Функция обрабатывает строку String так, чтобы она подходила длz публикации в LaTeX в виде label.
int HQt_GetTypeCharRus(QString x);//Функция выдает тип вводимого QString (считая, что это буква). Нужно для алгоритма переноса строк П.Хpистова в модификации Дымченко и Ваpсанофьева.
bool HQt_CheckRus(QString S);//Функция проверяет наличие русских букв в строке.
bool HQt_CheckLetterFromWord(QString x);//Является ли буква символом из слова. Считается, что это или латинские буквы, или русские, или цифры или нижнее подчеркивание.
QStringList HQt_CutToWords(QString S);//Функция разбивает строку на слова и те, части, между которыми они находятся. Слова с дефисом считаются за несколько слов.
QStringList HQt_CutToWordsWithWordWrap(QString S);//Функция разбивает строку на слова и те, части, между которыми они находятся. А русские и английские слова разделяет по переносам. Слова с дефисом считаются за несколько слов.
int HQt_GetTypeCharEng(QString x);//Функция выдает тип вводимого QString (считая, что это буква английская). Нужно для алгоритма переноса строк П.Хpистова в модификации Дымченко и Ваpсанофьева.
QStringList HQt_BreakdownOfTextWithWordWrap(QString S, int length);//Функция разбивает текст на строки длиной не более length. Если может, то ставит переносы.
bool HQt_CheckIntolerablePunctuation(QString x);//Является ли символом знаком пунктуации, который нельзя переносить.
int HQt_MaxCountOfQStringList(QStringList x);//Функция выдает длину макимальной по длине строки в QStringList.
bool HQt_IsNumeric(QString x);//Функция проверяет - является ли строка числом.
double HQt_QStringToNumber (QString x);//Функция выводит строку x в число.
double HQt_QStringToNumber (QString x, bool checkcomma);//Функция выводит строку x в число с учетом возможности нахождения запятой.

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
     Отсутствует.
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
     Отсутствует.
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
     Отсутствует.
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
     Отсутствует.
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

#endif // HARRIXQTLIBRARY_H
