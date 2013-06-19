//Сборник функций для Qt. Версия v.2.6.
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
    QString destinationFile = dir + QDir::separator() + fileInfo.fileName();
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
    QString destinationFile = dir + QDir::separator() + fileInfo.fileName();

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
    QString name="";
    name=filename.mid(filename.lastIndexOf(QDir::separator())+1);
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

int HQt_SizeMatrixOrVectorFromQStringList(QStringList QStringListFromFile, int* VMHL_Result_M)
{
    /*
    Функция подсчитывает сколько строк и столбцов в текстовом файле, который скопировали в QStringListFromFile.
    Считается, что файл правильный, ошибки не проверяются. в строке числа разделяются через табуляцию \t,
    а десятичные числа используют точку, а не запятую.
    Входные параметры:
     QStringListFromFile - непосредственно сам файл;
     VMHL_Result_M - сюда будем записывать число столбцов в матрице (число знаков табуляции + 1).
    Возвращаемое значение:
     Число строк.
    Пример содержимого QStringListFromFile:
1	2.2
2.8	9
    */
    int VMHL_Result_N=QStringListFromFile.count();

    QString A=QStringListFromFile.at(0);

    *VMHL_Result_M=A.count("\t")+1;

    return VMHL_Result_N;
}
//---------------------------------------------------------------------------
int HQt_SizeMatrixOrVectorFromQStringList(QStringList QStringListFromFile)
{
    /*
    Функция подсчитывает сколько строк в текстовом файле, который скопировали в QStringListFromFile.
    Считается, что файл правильный, ошибки не проверяются. в строке числа разделяются через табуляцию \t,
    а десятичные числа используют точку, а не запятую.
    Входные параметры:
     QStringListFromFile - непосредственно сам файл.
    Возвращаемое значение:
     Число строк.
    Пример содержимого QStringListFromFile:
1
2.8
    */
    int VMHL_Result_N=QStringListFromFile.count();

    return VMHL_Result_N;
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
     Отсуствует.
    Пример содержимого VMHL_VectorResult.
1	2013.04.05	6
52	2013.02.25	96
6.4	2013.01.15	4
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

//Функции для получения HTML кода для вывода в webView

QString HQt_ShowText (QString TitleX)
{
    /*
    Функция возвращает строку с выводом некотороq строки с HTML кодами. Для добавление в html файл.
    Входные параметры:
     TitleX - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result="<p><b>"+TitleX+":</b><br>";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_BeginHtml ()
{
    /*
    Функция возвращает строку с началом HTML файла, в который другими функциями
    добавляются иные данные. Для добавление в html файл.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с началом HTML файла.
    */
    QString VMHL_Result;

    VMHL_Result+="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n";
    VMHL_Result+="<html>\n";
    VMHL_Result+="<head>\n";
    VMHL_Result+="<meta name=\"qrichtext\" content=\"1\" />\n";
    VMHL_Result+="<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n\n";
    VMHL_Result+="<style type=\"text/css\">\n";
    VMHL_Result+="p, li { white-space: pre-wrap; }\n";
    VMHL_Result+="h1 { font-size:140% }\n";
    VMHL_Result+="h2 { font-size:120% }\n";
    VMHL_Result+="h3,h4,h5,h6 { font-size:110% }\n";
    VMHL_Result+="body { font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; }\n";
    VMHL_Result+="</style>\n\n";

    //Подключение двух файлов для отображения графиков
    //https://github.com/jsxgraph/jsxgraph
    VMHL_Result+="<link rel=\"stylesheet\" type=\"text/css\" href=\"jsxgraph.css\" />\n";
    VMHL_Result+="<script type=\"text/javascript\" src=\"jsxgraphcore.js\"></script>";

    VMHL_Result+="</head>\n\n";
    VMHL_Result+="<body>\n";


    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_EndHtml ()
{
    /*
    Функция возвращает строку с концовкой HTML файла, в который другими функциями
    добавляются иные данные. Для добавление в html файл.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с концовкой HTML файла.
    */
    QString VMHL_Result;

    VMHL_Result="</body>\n</html>";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
