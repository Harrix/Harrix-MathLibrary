//Сборник функций для Qt. Версия v.3.6
//https://github.com/Harrix/QtHarrixLibrary
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "QtHarrixLibrary.h"

QString HQt_ReadFile(QString filename)
{
    /*
    Функция считывает текстовой файл в QString.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     Строка со всем содержимым текстового файла.
    */
    QFile file(filename);
    QString line="";
    if(!file.exists()){
        qDebug() << "Не существует "<<filename;
        return line;
    }else{
        qDebug() << filename<<" загружается...";
    }
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        line=file.readAll();
    file.close();
    return line;
}
//---------------------------------------------------------------------------

QStringList HQt_ReadFileToQStringList(QString filename)
{
    /*
    Функция считывает текстовой файл в QStringList.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     QStringList со всем содержимым текстового файла.
    */
    QString Temp=HQt_ReadFile(filename);

    return HQt_QStringToQStringList(Temp);
}
//---------------------------------------------------------------------------

void HQt_SaveFile(QString line, QString filename)
{
    /*
    Функция сохраняет QString в текстовой файл.
    Входные параметры:
     line - содержимое, которое нужно сохранить;
     filename - имя файла.
    Возвращаемое значение:
     Отсутствует.
    */
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream.setCodec(QTextCodec::codecForName("UTF-8"));
        stream << line;
    }
    file.close();
}
//---------------------------------------------------------------------------

QString HQt_ListFilesInDir(QString path)
{
    /*
    Функция считывает список файлов (включая скрытые) в директории в QString.
    Входные параметры:
     path - путь к папке.
    Возвращаемое значение:
     Строка со списком файлов в директории, разделенные \n в алфавитном порядке.
    */
    QString line="";
    QDir dir(path);
    bool ok = dir.exists();  //check if directory exist
    if (ok)
    {
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Name);
        QFileInfoList list = dir.entryInfoList();

        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            line+=fileInfo.fileName()+"\n";
        }
    }
    return line;
}
//---------------------------------------------------------------------------

QStringList HQt_ListFilesInDirQStringList(QString path)
{
    /*
    Функция считывает список файлов (включая скрытые) в директории в QStringList.
    Входные параметры:
     path - путь к папке.
    Возвращаемое значение:
     Список строк файлов в директории в алфавитном порядке.
    */
    QString line;
    line=HQt_ListFilesInDir(path);

    QStringList lines = HQt_QStringToQStringList(line);

    return lines;
}
//---------------------------------------------------------------------------

QString HQt_ListDirsInDir(QString path)
{
    /*
    Функция считывает список директорий в директории в QString.
    Входные параметры:
     path - путь к папке.
    Возвращаемое значение:
     Строка со списком директорий в директории, разделенные \n в алфавитном порядке.
    */
    QString line="";
    QDir dir(path);
    bool ok = dir.exists();  //check if directory exist
    if (ok)
    {
        dir.setFilter(QDir::NoDotAndDotDot | QDir::Dirs );
        dir.setSorting(QDir::Name);
        QFileInfoList list = dir.entryInfoList();

        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            line+=fileInfo.fileName()+"\n";
        }
    }
    return line;
}
//---------------------------------------------------------------------------

QStringList HQt_ListDirsInDirQStringList(QString path)
{
    /*
    Функция считывает список директорий в директории в QStringList.
    Входные параметры:
     path - путь к папке.
    Возвращаемое значение:
     Список строк со списком директорий в директории в алфавитном порядке.
    */
    QString line;
    line=HQt_ListDirsInDir(path);

    QStringList lines = HQt_QStringToQStringList(line);

    return lines;
}
//---------------------------------------------------------------------------

QString HQt_GetExpFromFilename(QString filename)
{
    /*
    Функция получает расширение файла по его имени.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     Строка значением расширения файла в нижнем регистре.
    */
    QString exp="";
    exp=filename.mid(filename.lastIndexOf(".")+1);
    exp=exp.toLower();
    return exp;
}
//---------------------------------------------------------------------------

QStringList HQt_QStringToQStringList(QString line)
{
    /*
    Функция переводит QString в QStringList.
    Входные параметры:
     line - строка.
    Возвращаемое значение:
     Список строк.
    */
    QStringList lines = line.split( "\n", QString::SkipEmptyParts );

    return lines;
}
//---------------------------------------------------------------------------

QString HQt_QStringListToQString(QStringList lines)
{
    /*
    Функция переводит QStringList в QString.
    Входные параметры:
     lines - список строк.
    Возвращаемое значение:
     Строка с разделениями \n.
    */
    QString line = lines.join('\n');

    return line;
}
//---------------------------------------------------------------------------

bool HQt_FileExists(QString filename)
{
    /*
    Функция проверяет сущестование файла.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     false - если файл не существует,
     true - если файл существует
    */
    QFile file(filename);
    if(!file.exists()){
        file.close();
        return false;
    }else{
        file.close();
        return true;
    }
}
//---------------------------------------------------------------------------

QString HQt_GetNameFromFilename(QString filename)
{
    /*
    Функция получает имя файла без расширения по его имени.
    Входные параметры:
     filename - имя файла (можно и с полным путем).
    Возвращаемое значение:
     Строка с именем файла без расширения.
    */
    QString name="";
    name=HQt_GetFilenameFromFullFilename(filename).mid(0,filename.lastIndexOf("."));
    return name;
}
//---------------------------------------------------------------------------

bool HQt_CopyFile(QString filename, QString dir)
{
    /*
    Функция копирует файл filename в папку dir.
    Входные параметры:
     filename - имя файла (с полным путем),
     dir - путь к папке, куда нужно скопировать файл.
    Возвращаемое значение:
     true - если скопировалось удачно,
     false - если скопировалось неудачно.
    */
    QFileInfo fileInfo(filename);

    QString Separator;
    if (filename.contains(QDir::separator())) Separator=QDir::separator();
    if (filename.contains("\\")) Separator="\\";
    if (filename.contains("/")) Separator="/";

    QString destinationFile = dir + Separator + fileInfo.fileName();
    bool result = QFile::copy(filename, destinationFile);
    return result;
}
//---------------------------------------------------------------------------

bool HQt_CopyFile(QString filename, QString dir, bool overwrite)
{
    /*
    Функция копирует файл filename в папку dir, с возможносью перезаписи.
    Входные параметры:
     filename - имя файла (с полным путем),
     dir - путь к папке, куда нужно скопировать файл.
     overwrite - если true, то перезаписывать, если false, то не перезаписывать
    Возвращаемое значение:
     true - если скопировалось удачно,
     false - если скопировалось неудачно.
    */
    QFileInfo fileInfo(filename);

    QString Separator;
    if (filename.contains(QDir::separator())) Separator=QDir::separator();
    if (filename.contains("\\")) Separator="\\";
    if (filename.contains("/")) Separator="/";

    QString destinationFile = dir + Separator + fileInfo.fileName();

    if ((QFile::exists(destinationFile))&&(overwrite==true))
    {
        QFile::remove(destinationFile);
    }

    bool result = QFile::copy(filename, destinationFile);
    return result;
}
//---------------------------------------------------------------------------

QString HQt_GetFilenameFromFullFilename(QString filename)
{
    /*
    Функция получает имя файла по полному пути.
    Входные параметры:
     filename - имя файла с путем.
    Возвращаемое значение:
     Строка с именем файла.
    */
    QString name;

    QString Separator;
    if (filename.contains(QDir::separator())) Separator=QDir::separator();
    if (filename.contains("\\")) Separator="\\";
    if (filename.contains("/")) Separator="/";

    name=filename.mid(filename.lastIndexOf(Separator)+1);
    return name;
}
//---------------------------------------------------------------------------

QString HQt_WriteTime(int t)
{
    /*
    Функция переводит миллисекунды в строку с описанием сколько это минут, секунд и др.
    Входные параметры:
     t - миллисекунды.
    Возвращаемое значение:
     Строка в виде текста - сколько секунд, минут и так далее было.
    */
    int sec=t/1000;
    int min=t/(1000*60);
    int hour=t/(1000*60*60);
    int day=t/(1000*60*60*24);

    int Hour=hour-day*24;
    int Min=min-hour*60;
    int Sec=sec-min*60;
    int Millisec=t-sec*1000;

    QString A;

    if (day!=0) A+=QString::number(day)+" дн. ";
    if (Hour!=0) A+=QString::number(Hour)+" ч. ";
    if (Min!=0) A+=QString::number(Min)+" мин. ";
    if (Sec!=0) A+=QString::number(Sec)+" сек. ";
    if (Millisec!=0) A+=QString::number(Millisec)+" миллисек.";

    return A;
}
//---------------------------------------------------------------------------

QString HQt_UniqueName ()
{
    /*
    Функция возвращает уникальную строку, которую можно использовать как некий идентификатор.
    Собирается из "HQt_" + текущее время.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Уникальная строка.
    */
    return "HQt_"+QDateTime::currentDateTime().toString("ddMMyyyyhhmmss");
}
//---------------------------------------------------------------------------

QString HQt_UniqueName (QString BeginString)
{
    /*
    Функция возвращает уникальную строку, которую можно использовать как некий идентификатор.
    Собирается из BeginString+"_" + текущее время.
    Входные параметры:
     BeginString - Приставка вначале строки.
    Возвращаемое значение:
     Уникальная строка.
    */
    return BeginString+"_"+QDateTime::currentDateTime().toString("ddMMyyyyhhmmss");
}
//---------------------------------------------------------------------------
QString HQt_UniqueNameOnlyNumbers ()
{
    /*
    Функция возвращает уникальную строку, которую можно использовать как некий идентификатор. В строке только цифры.
    Собирается из текущего времени.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Уникальная строка.
    */
    return QDateTime::currentDateTime().toString("ddMMyyyyhhmmss");
}
//---------------------------------------------------------------------------
void HQt_Delay(int MSecs)
{
    /*
    Функция делает задержку в MSecs миллисекунд.
    Входные параметры:
     MSecs - миллисекунды, сколько надо подержать работу Qt. Не меньше пяти миллисекунд должно быть.
    Возвращаемое значение:
     Отсутствуют.
    */
    QTime dieTime= QTime::currentTime().addMSecs(MSecs);
    while( QTime::currentTime() < dieTime )
        QGuiApplication::processEvents(QEventLoop::AllEvents, 100);
}
//---------------------------------------------------------------------------

QString HQt_RandomString(int Length)
{
    /*
    Функция генерирует случайную строку из английских больших и малых букв.
    Входные параметры:
     Length - длина строки, которую надо сгенерировать.
    Возвращаемое значение:
     Случайная строка.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    */
    QString VMHL_Result;
    static const char alphanum[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    char *s=new char[Length];

    for (int i=0; i<Length; ++i)
    {
        s[i] = alphanum[qrand() % (sizeof(alphanum) - 1)];
    }

    s[Length] = 0;

    VMHL_Result = QString(s);

    delete [] s;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
int HQt_DaysBetweenDates(QDate BeginDate, QDate EndDate)
{
    /*
    Функция определяет сколько дней между двумя датами.
    Входные параметры:
     BeginDate - первая дата.
     EndDate - вторая дата.
    Возвращаемое значение:
     Число дней между датами.
    */
    return abs(BeginDate.daysTo(EndDate));
}
//---------------------------------------------------------------------------
int HQt_DaysBetweenDates(QString BeginDate, QString EndDate)
{
    /*
    Функция определяет сколько дней между двумя датами.
    Входные параметры:
     BeginDate - первая дата в виде строки в формате 2013.06.16.
     EndDate - вторая дата в виде строки в формате 2012.06.16.
    Возвращаемое значение:
     Число дней между датами.
    */
    QDate DBeginDate(QDate::fromString(BeginDate, "yyyy.MM.dd"));
    QDate DEndDate(QDate::fromString(EndDate, "yyyy.MM.dd"));
    return abs(DBeginDate.daysTo(DEndDate));
}
//---------------------------------------------------------------------------

int HQt_CountOfColsFromQStringList(QStringList QStringListFromFile)
{
    /*
    Функция подсчитывает сколько столбцов в текстовом файле, который скопировали в QStringListFromFile.
    Считается, что файл правильный, ошибки не проверяются. В строке числа разделяются через табуляцию \t,
    а десятичные числа используют точку, а не запятую. Во всех столбцах должно быть одинаковое число элементов.
    Поэтому, если в одном столбце больше элементов, чем в других, то в остальные столбцы на место недостающих
    элементов ставнится знак "-".
    Входные параметры:
     QStringListFromFile - непосредственно сам файл.
    Возвращаемое значение:
     Число столбцов (по первой строке).
    Пример содержимого QStringListFromFile:
1	2.2
2.8	9
    */
    QString A=QStringListFromFile.at(0);

    int VMHL_Result_M=A.count("\t")+1;

    return VMHL_Result_M;
}
//---------------------------------------------------------------------------

int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile)
{
    /*
    Функция подсчитывает сколько строк в текстовом файле, который скопировали в QStringListFromFile.
    Считается, что файл правильный, ошибки не проверяются. В строке числа разделяются через табуляцию \t,
    а десятичные числа используют точку, а не запятую. Во всех столбцах должно быть одинаковое число элементов.
    Поэтому, если в одном столбце больше элементов, чем в других, то в остальные столбцы на место недостающих
    элементов ставнится знак "-".
    Входные параметры:
     QStringListFromFile - непосредственно сам файл.
    Возвращаемое значение:
     Число строк.
    Пример содержимого QStringListFromFile:
1	2.2
2.8	9
    */
    int VMHL_Result_N=QStringListFromFile.count();

    return VMHL_Result_N;
}
//---------------------------------------------------------------------------

int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile, int k)
{
    /*
    Функция подсчитывает сколько строк в k столбце из текстового файла, который скопировали в QStringListFromFile.
    Считается, что файл правильный, ошибки не проверяются. В строке числа разделяются через табуляцию \t,
    а десятичные числа используют точку, а не запятую. Во всех столбцах должно быть одинаковое число элементов.
    Поэтому, если в одном столбце больше элементов, чем в других, то в остальные столбцы на место недостающих
    элементов ставнится знак "-".
    Входные параметры:
     QStringListFromFile - непосредственно сам файл.
    Возвращаемое значение:
     Число строк в столбце.
    Пример содержимого QStringListFromFile:
1	2.2
2.8	9
    */
    int N = HQt_CountOfRowsFromQStringList(QStringListFromFile);
    QString A,X;
    int i,j;

    for (i=0;(i<N)&&(X!="-");i++)
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
    }

    int VMHL_Result_N;
    if (X=="-")
        VMHL_Result_N=i-1;
    else
        VMHL_Result_N=i;

    return VMHL_Result_N;
}
//---------------------------------------------------------------------------

int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile, int *VMHL_ResultVector)
{
    /*
    Функция подсчитывает сколько строк в каждом столбце из текстового файла с матрицей, который скопировали в QStringListFromFile.
    Считается, что файл правильный, ошибки не проверяются. В строке числа разделяются через табуляцию \t,
    а десятичные числа используют точку, а не запятую. Во всех столбцах должно быть одинаковое число элементов.
    Поэтому, если в одном столбце больше элементов, чем в других, то в остальные столбцы на место недостающих
    элементов ставнится знак "-".
    Входные параметры:
     QStringListFromFile - непосредственно сам файл;
     VMHL_ResultVector - сюда количество стро заносится.
    Возвращаемое значение:
     Число строк в QStringListFromFile (в правильном файле это число равно максимальному числу строк в каком-нибудь столбце).
    Пример содержимого QStringListFromFile:
1	2.2
2.8	9
    */
    int i,j;
    QString A,X;
    int M=HQt_CountOfColsFromQStringList(QStringListFromFile);
    int N=QStringListFromFile.count();

    for (j=0;j<M;j++) VMHL_ResultVector[j]=0;

    int *Stop=new int[M];
    for (j=0;j<M;j++) Stop[j]=0;

    for (i=0;i<N;i++)
    {
        A=QStringListFromFile.at(i);
        A=A.trimmed();
        for (j=0;j<M;j++)
        {
            X=A.mid(0,A.indexOf("\t"));
            A=A.mid(A.indexOf("\t")+1);
            A=A.trimmed();
            if ((X!="-")&&(Stop[j]==0))
            {
                VMHL_ResultVector[j]++;
            }
            if ((X=="-"))
            {
                Stop[j]=1;
            }
        }
    }

    delete[] Stop;

    return N;
}
//---------------------------------------------------------------------------

void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QDate *VMHL_VectorResult)
{
    /*
    Функция считывает данные какого-то k столбца с датами из QStringList в виде матрицы.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     k - номер столбца, начиная с нуля, который считываем;
     VMHL_VectorResult - сюда будем записывать результат считывания столбца из матрицы.
    Возвращаемое значение:
     Отсутствует.
    Пример содержимого VMHL_VectorResult.
1	2013.04.05	6
52	2013.02.25	96
6.4	2013.01.15	4
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

        int p1=X.lastIndexOf(".");
        int p2=X.indexOf(".");

        QDate DBeginDate;
        if ((p1==2)&&(p2==5))
            DBeginDate=QDate::fromString(X, "yyyy.MM.dd");
        else
            DBeginDate=QDate::fromString(X, "dd.MM.yyyy");
        VMHL_VectorResult[i]=DBeginDate;
    }
}
//---------------------------------------------------------------------------

void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QString *VMHL_VectorResult)
{
    /*
    Функция считывает данные какого-то k столбца с датами из QStringList в виде матрицы. Для строк.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     k - номер столбца, начиная с нуля, который считываем;
     VMHL_VectorResult - сюда будем записывать результат считывания столбца из матрицы.
    Возвращаемое значение:
     Отсутствует.
    Пример содержимого VMHL_VectorResult.
1	2013.04.05	6
52	2013.02.25	96
6.4	2013.01.15	4
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

        VMHL_VectorResult[i]=X;
    }
}
//---------------------------------------------------------------------------

QString THQt_ThreeNumbersToRGBString(int R, int G, int B)
{
    /*
    Функция переводит три числа в строку RGB типа #25ffb5, как в Photoshop или HTML.
    Входные параметры:
     int R - число от 0 до 255 включительно означающее красный цвет;
     int G - число от 0 до 255 включительно означающее зеленый цвет;
     int B - число от 0 до 255 включительно означающее синий цвет.
    Возвращаемое значение:
     Строка содержащая код цвета, например: #25ffb5.
    */
    if (R<0) R=0;
    if (R>255) R=255;
    if (G<0) G=0;
    if (G>255) G=255;
    if (B<0) B=0;
    if (B>255) B=255;

    QString RR=QString::number(R, 16);
    QString GG=QString::number(G, 16);
    QString BB=QString::number(B, 16);

    if (RR.length()==1) RR="0"+RR;
    if (GG.length()==1) GG="0"+GG;
    if (BB.length()==1) BB="0"+BB;

    QString RGB="#"+RR+GG+BB;

    return RGB;
}
//---------------------------------------------------------------------------
void THQt_RGBStringToThreeNumbers(QString RGB, int *R, int *G, int *B)
{
    /*
    Функция переводит строку RGB типа #25ffb5 в три числа от 0 до 255,
    которые кодируют  цвета.
    Входные параметры:
     RGB - строка, которая содержит код RGB цвета вида: #25ffb5.
     R - число от 0 до 255 включительно означающее красный цвет;
     G - число от 0 до 255 включительно означающее зеленый цвет;
     B - число от 0 до 255 включительно означающее синий цвет.
    Возвращаемое значение:
     Строка содержащая код цвета, например: #25ffb5.
    */
    *R=0;
    *G=0;
    *B=0;

    if (RGB.length()==7)
    {
        RGB=RGB.mid(1);

        QString RR=RGB.mid(0,2);
        QString GG=RGB.mid(2,2);
        QString BB=RGB.mid(4,2);

        bool ok;

        *R=RR.toInt(&ok,16);
        *G=GG.toInt(&ok,16);
        *B=BB.toInt(&ok,16);
    }
}
//---------------------------------------------------------------------------

QString THQt_ColorFromGradient(double position, QString FirstRGB, QString SecondRGB)
{
    /*
    Функция выдает код RGB из градиента от одного цвета FirstRGB к другому цвету SecondRGB согласно позиции от 0 до 1.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента;
     FirstRGB - строка RGB кода первого цвета градиента, например: #63ddb2;
     SecondRGB - строка RGB кода последнего цвета градиента, например: #5845da.
    Возвращаемое значение:
     Строка содержащая код цвета, например: #25ffb5.
    */
    int R,G,B;
    int R1,G1,B1;
    int R2,G2,B2;

    THQt_RGBStringToThreeNumbers(FirstRGB, &R1, &G1, &B1);
    THQt_RGBStringToThreeNumbers(SecondRGB, &R2, &G2, &B2);

    R=R1+position*(R2-R1);
    G=G1+position*(G2-G1);
    B=B1+position*(B2-B1);

    return THQt_ThreeNumbersToRGBString(R, G, B);
}
//---------------------------------------------------------------------------

QString THQt_AlphaBlendingColorToColor(double alpha, QString FirstRGB, QString SecondRGB)
{
    /*
    Функция накладывает сверху на цвет другой цвет с определенной прозрачностью.
    Входные параметры:
     alpha - прозрачность второго накладываемого цвета из интервала [0;1];
     FirstRGB - строка RGB кода первого цвета градиента, например: #63ddb2;
     SecondRGB - строка RGB кода последнего цвета градиента, например: #5845da.
    Возвращаемое значение:
     Строка содержащая код цвета, например: #25ffb5.
    */
    int R,G,B;
    int R1,G1,B1;
    int R2,G2,B2;

    THQt_RGBStringToThreeNumbers(FirstRGB, &R1, &G1, &B1);
    THQt_RGBStringToThreeNumbers(SecondRGB, &R2, &G2, &B2);

    R=alpha*R2+(1-alpha)*R1;
    G=alpha*G2+(1-alpha)*G1;
    B=alpha*B2+(1-alpha)*B1;

    return THQt_ThreeNumbersToRGBString(R, G, B);
}
//---------------------------------------------------------------------------

QString THQt_GiveRainbowColorRGB(double position)
{
    /*
    Функция выдает код RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента.
    То есть это перевод числа в RGB (из радуги).
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из радуги.
    Возвращаемое значение:
     Строка содержащая код цвета, например: #25ffb5.
    */
    if (position<0) position=0;
    if (position>1) position=1;

    int R=0, G=0, B=0;//

    int nmax=6;// number of color bars
    double m=nmax* position;
    int n=int(m); // integer of m
    double f=m-n;  // fraction of m
    int t=int(f*255);

    switch( n){
    case 0: {
        R = 255;
        G = t;
        B = 0;
        break;
    };
    case 1: {
        R = 255 - t;
        G = 255;
        B = 0;
        break;
    };
    case 2: {
        R = 0;
        G = 255;
        B = t;
        break;
    };
    case 3: {
        R = 0;
        G = 255 - t;
        B = 255;
        break;
    };
    case 4: {
        R = t;
        G = 0;
        B = 255;
        break;
    };
    case 5: {
        R = 255;
        G = 0;
        B = 255 - t;
        break;
    };

    }; // case

    QString RGB=THQt_ThreeNumbersToRGBString(R,G,B);

    return RGB;
}
//---------------------------------------------------------------------------

QString HQt_TextBeforeEqualSign (QString String)
{
    /*
    Функция возвращает текст строки до первого знака =.
    Входные параметры:
     String - строка вида:
     Title = Пример
    Возвращаемое значение:
     Текст строки до первого знака =.
    */
    QString VMHL_Result;

    VMHL_Result=String.mid(0,String.indexOf("="));

    VMHL_Result=VMHL_Result.trimmed();

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_TextAfterEqualSign (QString String)
{
    /*
    Функция возвращает текст строки после первого знака =.
    Входные параметры:
     String - строка вида:
     Title = Пример
    Возвращаемое значение:
     Текст строки после первого знака =.
    */
    QString VMHL_Result;

    VMHL_Result=String.mid(String.indexOf("=")+1);

    VMHL_Result=VMHL_Result.trimmed();

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QStringList HQt_AddUniqueQStringInQStringList (QStringList StringList, QString String)
{
    /*
    Функция добавляет в QStringList строку QString. Но если такая строка уже присутствует, то добавление не происходит.
    Входные параметры:
     StringList - QStringList, в который мы добавляем строку (добавление в возвращаемом элементе);
     String - добавляемая строка.
    Возвращаемое значение:
     Отсутствует.
    */
    bool in=false;

    for (int i=0;i<StringList.count();i++)
    {
        if (StringList.at(i)==String)
            in=true;
    }

    if (!in) StringList << String;

    return StringList;
}
//---------------------------------------------------------------------------

int HQt_SearchQStringInQStringList (QStringList StringList, QString String)
{
    /*
    Функция ищет в QStringList строку QString (номер первого вхождения).
    Входные параметры:
     StringList - QStringList, в который мы ищем строку;
     String - добавляемая строка.
    Возвращаемое значение:
     Номер найденной строки. Если не найдено, то возвращается -1.
    */
    int VMHL_Result = -1;
    bool in=false;
    int i=0;

    while ((i<StringList.count())&&(in!=true))
    {
        if (StringList.at(i)==String)
           VMHL_Result=i;
        i++;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
