//HarrixQtLibrary
//Версия 3.17
//Сборник функций для Qt.
//https://github.com/Harrix/HarrixQtLibrary
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibrary.h"

QString HQt_ReadFile(QString filename)
{
    /*
    Функция считывает текстовой файл в QString.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     Строка со всем содержимым текстового файла.
    */
    filename = QDir::toNativeSeparators(filename);
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
    filename = QDir::toNativeSeparators(filename);
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
    path = QDir::toNativeSeparators(path);
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
    path = QDir::toNativeSeparators(path);
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
    Функция проверяет существование файла.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     false - если файл не существует,
     true - если файл существует.
    */
    filename = QDir::toNativeSeparators(filename);
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

bool HQt_DirExists(QString path)
{
    /*
    Функция проверяет существование директории.
    Входные параметры:
     path - полный путь к папке.
    Возвращаемое значение:
     false - если папка не существует,
     true - если папка существует.
    */
    path = QDir::toNativeSeparators(path);
    QDir dir(path);
    if(dir.exists())
       return true;
    else
      return false;
}
//---------------------------------------------------------------------------

void HQt_DirMake(QString path)
{
    /*
    Функция проверяет существование директории, и если ее нет, то создает.
    Входные параметры:
     path - полный путь к папке.
    Возвращаемое значение:
     Отсутствует.
    */
    path = QDir::toNativeSeparators(path);
    QString Separator="\\";

    QString Sub;
    QString Subpath;

    while(path.indexOf(Separator)>0)
    {
    Sub=path.mid(0,path.indexOf(Separator)+1);
    path=path.mid(path.indexOf(Separator)+1);

    Subpath+=Sub;
    QDir dir(Subpath);
    if(!dir.exists()) dir.mkdir(Subpath);
    }

    Subpath+=path;
    QDir dir(Subpath);
    if(!dir.exists()) dir.mkdir(Subpath);
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
    filename = QDir::toNativeSeparators(filename);
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
    filename = QDir::toNativeSeparators(filename);
    QFileInfo fileInfo(filename);

    QString Separator="\\";

    QString destinationFile = dir + Separator + fileInfo.fileName();
    bool result = QFile::copy(filename, destinationFile);
    return result;
}
//---------------------------------------------------------------------------

bool HQt_CopyFile(QString filename, QString dir, bool overwrite)
{
    /*
    Функция копирует файл filename в папку dir, с возможностью перезаписи.
    Входные параметры:
     filename - имя файла (с полным путем),
     dir - путь к папке, куда нужно скопировать файл.
     overwrite - если true, то перезаписывать, если false, то не перезаписывать
    Возвращаемое значение:
     true - если скопировалось удачно,
     false - если скопировалось неудачно.
    */
    filename = QDir::toNativeSeparators(filename);
    QFileInfo fileInfo(filename);

    QString Separator="\\";

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
    filename = QDir::toNativeSeparators(filename);
    QString name;

    QString Separator="\\";

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

QString HQt_WriteTime(qint64 t)
{
    /*
    Функция переводит миллисекунды в строку с описанием сколько это минут, секунд и др.
    Входные параметры:
     t - миллисекунды.
    Возвращаемое значение:
     Строка в виде текста - сколько секунд, минут и так далее было.
    */
    qint64 sec=t/1000;
    qint64 min=t/(1000*60);
    qint64 hour=t/(1000*60*60);
    qint64 day=t/(1000*60*60*24);

    qint64 Hour=hour-day*24;
    qint64 Min=min-hour*60;
    qint64 Sec=sec-min*60;
    qint64 Millisec=t-sec*1000;

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

    char *s=new char[Length+1];

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
    элементов ставится знак "-".
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
    элементов ставится знак "-".
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
    элементов ставится знак "-".
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
     Список строк с добавленной строкой.
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

QString HQt_StringForLaTeX (QString String)
{
    /*
    Функция обрабатывает строку String так, чтобы она подходила для публикации в LaTeX.
    Входные параметры:
     String - обрабатываемая строка.
    Возвращаемое значение:
     Обработанная строка.
    */
    QString VMHL_Result;

    VMHL_Result=String.replace("_","\\_");

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_StringToLabelForLaTeX (QString String)
{
    /*
    Функция обрабатывает строку String так, чтобы она подходила для публикации в LaTeX в виде label.
    Входные параметры:
     String - обрабатываемая строка.
    Возвращаемое значение:
     Обработанная строка.
    */
    QString VMHL_Result;

    VMHL_Result=String.replace("_","");

    return VMHL_Result;
}
//---------------------------------------------------------------------------

bool HQt_RenameFile(QString filename, QString newfilename)
{
    /*
    Функция переименовывает файл filename в newfilename.
    Входные параметры:
     filename - имя файла (с полным путем),
     newfilename - новое имя файла (без полного пути).
    Возвращаемое значение:
     true - если скопировалось удачно,
     false - если скопировалось неудачно.
    */
    filename = QDir::toNativeSeparators(filename);
    newfilename = QDir::toNativeSeparators(newfilename);
    QString Separator="\\";

    QString refilename = filename.mid(0,filename.lastIndexOf(Separator)+1) + newfilename;

    bool result = QFile::rename(filename,refilename);
    return result;
}
//---------------------------------------------------------------------------

int HQt_GetTypeCharRus(QString x)
{
    /*
    Функция выдает тип вводимого QString (считая, что это буква). Нужно для алгоритма переноса строк П.Хpистова в модификации Дымченко и Ваpсанофьева.
    Входные параметры:
     x - некая буква.
    Возвращаемое значение:
     1 - гласная;
     2 - согласная;
     3 - буква из множества ьъй;
     0 - иначе (английские или какие-то иные).
    */
    int VMHL_Result=0;

    if (x=="А") VMHL_Result=1;
    if (x=="а") VMHL_Result=1;

    if (x=="Б") VMHL_Result=2;
    if (x=="б") VMHL_Result=2;
    if (x=="В") VMHL_Result=2;
    if (x=="в") VMHL_Result=2;
    if (x=="Г") VMHL_Result=2;
    if (x=="г") VMHL_Result=2;
    if (x=="Д") VMHL_Result=2;
    if (x=="д") VMHL_Result=2;

    if (x=="Е") VMHL_Result=1;
    if (x=="е") VMHL_Result=1;
    if (x=="Ё") VMHL_Result=1;
    if (x=="ё") VMHL_Result=1;

    if (x=="Ж") VMHL_Result=2;
    if (x=="ж") VMHL_Result=2;
    if (x=="З") VMHL_Result=2;
    if (x=="з") VMHL_Result=2;

    if (x=="И") VMHL_Result=1;
    if (x=="и") VMHL_Result=1;

    if (x=="Й") VMHL_Result=3;
    if (x=="й") VMHL_Result=3;

    if (x=="К") VMHL_Result=2;
    if (x=="к") VMHL_Result=2;
    if (x=="Л") VMHL_Result=2;
    if (x=="л") VMHL_Result=2;
    if (x=="М") VMHL_Result=2;
    if (x=="м") VMHL_Result=2;
    if (x=="Н") VMHL_Result=2;
    if (x=="н") VMHL_Result=2;

    if (x=="О") VMHL_Result=1;
    if (x=="о") VMHL_Result=1;

    if (x=="П") VMHL_Result=2;
    if (x=="п") VMHL_Result=2;
    if (x=="Р") VMHL_Result=2;
    if (x=="р") VMHL_Result=2;
    if (x=="С") VMHL_Result=2;
    if (x=="с") VMHL_Result=2;
    if (x=="Т") VMHL_Result=2;
    if (x=="т") VMHL_Result=2;

    if (x=="У") VMHL_Result=1;
    if (x=="у") VMHL_Result=1;

    if (x=="Ф") VMHL_Result=2;
    if (x=="ф") VMHL_Result=2;
    if (x=="Х") VMHL_Result=2;
    if (x=="х") VMHL_Result=2;
    if (x=="Ц") VMHL_Result=2;
    if (x=="ц") VMHL_Result=2;
    if (x=="Ч") VMHL_Result=2;
    if (x=="ч") VMHL_Result=2;
    if (x=="Ш") VMHL_Result=2;
    if (x=="ш") VMHL_Result=2;
    if (x=="Щ") VMHL_Result=2;
    if (x=="щ") VMHL_Result=2;

    if (x=="Ъ") VMHL_Result=3;
    if (x=="ъ") VMHL_Result=3;

    if (x=="Ы") VMHL_Result=1;
    if (x=="ы") VMHL_Result=1;

    if (x=="Ь") VMHL_Result=3;
    if (x=="ь") VMHL_Result=3;

    if (x=="Э") VMHL_Result=1;
    if (x=="э") VMHL_Result=1;
    if (x=="Ю") VMHL_Result=1;
    if (x=="ю") VMHL_Result=1;
    if (x=="Я") VMHL_Result=1;
    if (x=="я") VMHL_Result=1;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

bool HQt_CheckRus(QString S)
{
    /*
    Функция проверяет наличие русских букв в строке.
    Входные параметры:
     S - проверяемая строка.
    Возвращаемое значение:
     true - естm буквы русские;
     false - нет букв русских.
    */
    bool VMHL_Result=false;

    QString x;

    for (int i=0;i<S.count();i++)
    {
        x=S.at(i);

        if (x=="А") VMHL_Result=true;
        if (x=="а") VMHL_Result=true;
        if (x=="Б") VMHL_Result=true;
        if (x=="б") VMHL_Result=true;
        if (x=="В") VMHL_Result=true;
        if (x=="в") VMHL_Result=true;
        if (x=="Г") VMHL_Result=true;
        if (x=="г") VMHL_Result=true;
        if (x=="Д") VMHL_Result=true;
        if (x=="д") VMHL_Result=true;
        if (x=="Е") VMHL_Result=true;
        if (x=="е") VMHL_Result=true;
        if (x=="Ё") VMHL_Result=true;
        if (x=="ё") VMHL_Result=true;
        if (x=="Ж") VMHL_Result=true;
        if (x=="ж") VMHL_Result=true;
        if (x=="З") VMHL_Result=true;
        if (x=="з") VMHL_Result=true;
        if (x=="И") VMHL_Result=true;
        if (x=="и") VMHL_Result=true;
        if (x=="Й") VMHL_Result=true;
        if (x=="й") VMHL_Result=true;
        if (x=="К") VMHL_Result=true;
        if (x=="к") VMHL_Result=true;
        if (x=="Л") VMHL_Result=true;
        if (x=="л") VMHL_Result=true;
        if (x=="М") VMHL_Result=true;
        if (x=="м") VMHL_Result=true;
        if (x=="Н") VMHL_Result=true;
        if (x=="н") VMHL_Result=true;
        if (x=="О") VMHL_Result=true;
        if (x=="о") VMHL_Result=true;
        if (x=="П") VMHL_Result=true;
        if (x=="п") VMHL_Result=true;
        if (x=="Р") VMHL_Result=true;
        if (x=="р") VMHL_Result=true;
        if (x=="С") VMHL_Result=true;
        if (x=="с") VMHL_Result=true;
        if (x=="Т") VMHL_Result=true;
        if (x=="т") VMHL_Result=true;
        if (x=="У") VMHL_Result=true;
        if (x=="у") VMHL_Result=true;
        if (x=="Ф") VMHL_Result=true;
        if (x=="ф") VMHL_Result=true;
        if (x=="Х") VMHL_Result=true;
        if (x=="х") VMHL_Result=true;
        if (x=="Ц") VMHL_Result=true;
        if (x=="ц") VMHL_Result=true;
        if (x=="Ч") VMHL_Result=true;
        if (x=="ч") VMHL_Result=true;
        if (x=="Ш") VMHL_Result=true;
        if (x=="ш") VMHL_Result=true;
        if (x=="Щ") VMHL_Result=true;
        if (x=="щ") VMHL_Result=true;
        if (x=="Ъ") VMHL_Result=true;
        if (x=="ъ") VMHL_Result=true;
        if (x=="Ы") VMHL_Result=true;
        if (x=="ы") VMHL_Result=true;
        if (x=="Ь") VMHL_Result=true;
        if (x=="ь") VMHL_Result=true;
        if (x=="Э") VMHL_Result=true;
        if (x=="э") VMHL_Result=true;
        if (x=="Ю") VMHL_Result=true;
        if (x=="ю") VMHL_Result=true;
        if (x=="Я") VMHL_Result=true;
        if (x=="я") VMHL_Result=true;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------

bool HQt_CheckLetterFromWord(QString x)
{
    /*
    Является ли буква символом из слова. Считается, что это или латинские буквы, или русские,
    или цифры или нижнее подчеркивание. Плюc некоторые знаки препинания, так как их нельзя переносить.
    Входные параметры:
     x - некая буква.
    Возвращаемое значение:
     true - буква из слова;
     false - не из слова.
    */
    bool VMHL_Result=false;

    if (x=="А") VMHL_Result=true;
    if (x=="а") VMHL_Result=true;
    if (x=="Б") VMHL_Result=true;
    if (x=="б") VMHL_Result=true;
    if (x=="В") VMHL_Result=true;
    if (x=="в") VMHL_Result=true;
    if (x=="Г") VMHL_Result=true;
    if (x=="г") VMHL_Result=true;
    if (x=="Д") VMHL_Result=true;
    if (x=="д") VMHL_Result=true;
    if (x=="Е") VMHL_Result=true;
    if (x=="е") VMHL_Result=true;
    if (x=="Ё") VMHL_Result=true;
    if (x=="ё") VMHL_Result=true;
    if (x=="Ж") VMHL_Result=true;
    if (x=="ж") VMHL_Result=true;
    if (x=="З") VMHL_Result=true;
    if (x=="з") VMHL_Result=true;
    if (x=="И") VMHL_Result=true;
    if (x=="и") VMHL_Result=true;
    if (x=="Й") VMHL_Result=true;
    if (x=="й") VMHL_Result=true;
    if (x=="К") VMHL_Result=true;
    if (x=="к") VMHL_Result=true;
    if (x=="Л") VMHL_Result=true;
    if (x=="л") VMHL_Result=true;
    if (x=="М") VMHL_Result=true;
    if (x=="м") VMHL_Result=true;
    if (x=="Н") VMHL_Result=true;
    if (x=="н") VMHL_Result=true;
    if (x=="О") VMHL_Result=true;
    if (x=="о") VMHL_Result=true;
    if (x=="П") VMHL_Result=true;
    if (x=="п") VMHL_Result=true;
    if (x=="Р") VMHL_Result=true;
    if (x=="р") VMHL_Result=true;
    if (x=="С") VMHL_Result=true;
    if (x=="с") VMHL_Result=true;
    if (x=="Т") VMHL_Result=true;
    if (x=="т") VMHL_Result=true;
    if (x=="У") VMHL_Result=true;
    if (x=="у") VMHL_Result=true;
    if (x=="Ф") VMHL_Result=true;
    if (x=="ф") VMHL_Result=true;
    if (x=="Х") VMHL_Result=true;
    if (x=="х") VMHL_Result=true;
    if (x=="Ц") VMHL_Result=true;
    if (x=="ц") VMHL_Result=true;
    if (x=="Ч") VMHL_Result=true;
    if (x=="ч") VMHL_Result=true;
    if (x=="Ш") VMHL_Result=true;
    if (x=="ш") VMHL_Result=true;
    if (x=="Щ") VMHL_Result=true;
    if (x=="щ") VMHL_Result=true;
    if (x=="Ъ") VMHL_Result=true;
    if (x=="ъ") VMHL_Result=true;
    if (x=="Ы") VMHL_Result=true;
    if (x=="ы") VMHL_Result=true;
    if (x=="Ь") VMHL_Result=true;
    if (x=="ь") VMHL_Result=true;
    if (x=="Э") VMHL_Result=true;
    if (x=="э") VMHL_Result=true;
    if (x=="Ю") VMHL_Result=true;
    if (x=="ю") VMHL_Result=true;
    if (x=="Я") VMHL_Result=true;
    if (x=="я") VMHL_Result=true;
    if (x=="A") VMHL_Result=true;
    if (x=="a") VMHL_Result=true;
    if (x=="B") VMHL_Result=true;
    if (x=="b") VMHL_Result=true;
    if (x=="C") VMHL_Result=true;
    if (x=="c") VMHL_Result=true;
    if (x=="D") VMHL_Result=true;
    if (x=="d") VMHL_Result=true;
    if (x=="E") VMHL_Result=true;
    if (x=="e") VMHL_Result=true;
    if (x=="F") VMHL_Result=true;
    if (x=="f") VMHL_Result=true;
    if (x=="G") VMHL_Result=true;
    if (x=="g") VMHL_Result=true;
    if (x=="H") VMHL_Result=true;
    if (x=="h") VMHL_Result=true;
    if (x=="I") VMHL_Result=true;
    if (x=="i") VMHL_Result=true;
    if (x=="J") VMHL_Result=true;
    if (x=="j") VMHL_Result=true;
    if (x=="K") VMHL_Result=true;
    if (x=="k") VMHL_Result=true;
    if (x=="L") VMHL_Result=true;
    if (x=="l") VMHL_Result=true;
    if (x=="M") VMHL_Result=true;
    if (x=="m") VMHL_Result=true;
    if (x=="N") VMHL_Result=true;
    if (x=="n") VMHL_Result=true;
    if (x=="O") VMHL_Result=true;
    if (x=="o") VMHL_Result=true;
    if (x=="P") VMHL_Result=true;
    if (x=="p") VMHL_Result=true;
    if (x=="Q") VMHL_Result=true;
    if (x=="q") VMHL_Result=true;
    if (x=="R") VMHL_Result=true;
    if (x=="r") VMHL_Result=true;
    if (x=="S") VMHL_Result=true;
    if (x=="s") VMHL_Result=true;
    if (x=="T") VMHL_Result=true;
    if (x=="t") VMHL_Result=true;
    if (x=="U") VMHL_Result=true;
    if (x=="u") VMHL_Result=true;
    if (x=="V") VMHL_Result=true;
    if (x=="v") VMHL_Result=true;
    if (x=="W") VMHL_Result=true;
    if (x=="w") VMHL_Result=true;
    if (x=="X") VMHL_Result=true;
    if (x=="x") VMHL_Result=true;
    if (x=="Y") VMHL_Result=true;
    if (x=="y") VMHL_Result=true;
    if (x=="Z") VMHL_Result=true;
    if (x=="z") VMHL_Result=true;
    if (x=="0") VMHL_Result=true;
    if (x=="1") VMHL_Result=true;
    if (x=="2") VMHL_Result=true;
    if (x=="3") VMHL_Result=true;
    if (x=="4") VMHL_Result=true;
    if (x=="5") VMHL_Result=true;
    if (x=="6") VMHL_Result=true;
    if (x=="7") VMHL_Result=true;
    if (x=="8") VMHL_Result=true;
    if (x=="9") VMHL_Result=true;
    if (x=="_") VMHL_Result=true;
    if (x==".") VMHL_Result=true;
    if (x==",") VMHL_Result=true;
    if (x==":") VMHL_Result=true;
    if (x=="!") VMHL_Result=true;
    if (x=="?") VMHL_Result=true;

    return VMHL_Result;
}
//---------------------------------------------------------------------------


QStringList HQt_CutToWords(QString S)
{
    /*
    Функция разбивает строку на слова и те, части, между которыми они находятся. Слова с дефисом считаются за несколько слов.
    Входные параметры:
     S - разбиваемая строка.
    Возвращаемое значение:
     Список подстрок, на которые можно разбить слово.
    Примечание:
     Если кроме русского и английского языка у вас могут слова других языков, то дополните функцию HQt_CheckLetterFromWord.
    */
    QStringList VMHL_Result;

    QString F;

    int N=S.count();
    int type=-1;
    int typebefore=-1;
    int len=0;

    for (int i=0;i<N;i++)
    {
        if (i==N-1)
        {
            typebefore=type;
            type=int(HQt_CheckLetterFromWord(S.at(i)));
            if (type==typebefore)
            {
                F+=S.at(i);
                VMHL_Result<<F;
            }
            else
            {
                VMHL_Result<<F;
                F.clear();
                F=S.at(i);
                VMHL_Result<<F;
            }
        }
        else
        {
            if (i<=1)
            {
                if (i==0)
                {
                    F=S.at(i);
                    type=int(HQt_CheckLetterFromWord(S.at(i)));
                    len++;
                }
                if (i==1)
                {
                    typebefore=type;
                    type=int(HQt_CheckLetterFromWord(S.at(i)));
                    if (type==typebefore)
                    {
                        F+=S.at(i);
                        len++;
                    }
                    else
                    {
                        VMHL_Result<<F;
                        F.clear();
                        F=S.at(i);
                        len=1;
                    }
                }
            }
            else
            {
                typebefore=type;
                type=int(HQt_CheckLetterFromWord(S.at(i)));
                if (len==0)
                {
                    F+=S.at(i);
                    len++;
                }
                else
                {
                    if (type!=typebefore)
                    {
                        VMHL_Result<<F;
                        F.clear();
                        F=S.at(i);
                        len=1;
                    }
                    else
                    {
                        F+=S.at(i);
                        len++;
                    }
                }

            }

        }

    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QStringList HQt_CutToWordsWithWordWrap(QString S)
{
    /*
    Функция разбивает строку на слова и те, части, между которыми они находятся. А русские и английские слова разделяет по переносам. Слова с дефисом считаются за несколько слов.
    Входные параметры:
     S - разбиваемая строка.
    Возвращаемое значение:
     Список подстрок, на которые можно разбить слово.
    Примечание:
     Если кроме русского и английского языка у вас могут слова других языков, то дополните функцию HQt_CheckLetterFromWord.
    Примечание:
     Перевод слов производится по алгоритму П. Хpистова в модификации Дымченко и Ваpсанофьева.
    */
    QStringList VMHL_Result;

    QString F;

    int N=S.count();
    int type=-1;
    int typebefore=-1;
    int len=0;

    for (int i=0;i<N;i++)
    {
        if (i==N-1)
        {
            typebefore=type;
            type=int(HQt_CheckLetterFromWord(S.at(i)));
            if (type==typebefore)
            {
                F+=S.at(i);
                VMHL_Result<<F;
            }
            else
            {
                VMHL_Result<<F;
                F.clear();
                F=S.at(i);
                VMHL_Result<<F;
            }
        }
        else
        {
            if (i<=1)
            {
                if (i==0)
                {
                    F=S.at(i);
                    type=int(HQt_CheckLetterFromWord(S.at(i)));
                    len++;
                }
                if (i==1)
                {
                    typebefore=type;
                    type=int(HQt_CheckLetterFromWord(S.at(i)));
                    if (type==typebefore)
                    {
                        F+=S.at(i);
                        len++;
                    }
                    else
                    {
                        VMHL_Result<<F;
                        F.clear();
                        F=S.at(i);
                        len=1;
                    }
                }
            }
            else
            {
                typebefore=type;
                type=int(HQt_CheckLetterFromWord(S.at(i)));
                if (len==0)
                {
                    F+=S.at(i);
                    len++;
                }
                else
                {
                    if (type!=typebefore)
                    {
                        VMHL_Result<<F;
                        F.clear();
                        F=S.at(i);
                        len=1;
                    }
                    else
                    {
                        if (len>=1)
                        {
                            bool cut=false;

                            //«Х-»
                            if ((i>=1)&&(i!=N-1))
                            {
                                if ((HQt_GetTypeCharRus(S.at(i-1))==3)&&(HQt_GetTypeCharRus(S.at(i))!=0)&&(HQt_GetTypeCharRus(S.at(i+1))!=0))
                                    cut=true;
                            }

                            //«Г-Г»
                            if ((i>=1)&&(i!=N-1))
                            {
                                if ((HQt_GetTypeCharRus(S.at(i-1))==1)&&(HQt_GetTypeCharRus(S.at(i))==1)&&(HQt_GetTypeCharRus(S.at(i+1))!=0))
                                    cut=true;
                            }

                            //«ГС-СГ»
                            if ((i>=2)&&(i<=N-2))
                            {
                                if ((HQt_GetTypeCharRus(S.at(i-2))==1)&&(HQt_GetTypeCharRus(S.at(i-1))==2)&&(HQt_GetTypeCharRus(S.at(i))==2)&&(HQt_GetTypeCharRus(S.at(i+1))==1))
                                    cut=true;
                            }

                            //«СГ-СГ»
                            if ((i>=2)&&(i<=N-2))
                            {
                                if ((HQt_GetTypeCharRus(S.at(i-2))==2)&&(HQt_GetTypeCharRus(S.at(i-1))==1)&&(HQt_GetTypeCharRus(S.at(i))==2)&&(HQt_GetTypeCharRus(S.at(i+1))==1))
                                    cut=true;
                            }

                            //«ГС-ССГ»
                            if ((i>=2)&&(i<=N-3))
                            {
                                if ((HQt_GetTypeCharRus(S.at(i-2))==1)&&(HQt_GetTypeCharRus(S.at(i-1))==2)&&(HQt_GetTypeCharRus(S.at(i))==2)&&(HQt_GetTypeCharRus(S.at(i+1))==2)&&(HQt_GetTypeCharRus(S.at(i+2))==1))
                                    cut=true;
                            }

                            //«ГСС-ССГ»
                            if ((i>=3)&&(i<=N-3))
                            {
                                if ((HQt_GetTypeCharRus(S.at(i-3))==1)&&(HQt_GetTypeCharRus(S.at(i-2))==2)&&(HQt_GetTypeCharRus(S.at(i-1))==2)&&(HQt_GetTypeCharRus(S.at(i))==2)&&(HQt_GetTypeCharRus(S.at(i+1))==2)&&(HQt_GetTypeCharRus(S.at(i+2))==1))
                                    cut=true;
                            }

                            //Для английского
                            //«Г-Г»
                            if ((i>=1)&&(i!=N-1))
                            {
                                if ((HQt_GetTypeCharEng(S.at(i-1))==1)&&(HQt_GetTypeCharEng(S.at(i))==1)&&(HQt_GetTypeCharEng(S.at(i+1))!=0))
                                    cut=true;
                            }

                            //«ГС-СГ»
                            if ((i>=2)&&(i<=N-2))
                            {
                                if ((HQt_GetTypeCharEng(S.at(i-2))==1)&&(HQt_GetTypeCharEng(S.at(i-1))==2)&&(HQt_GetTypeCharEng(S.at(i))==2)&&(HQt_GetTypeCharEng(S.at(i+1))==1))
                                    cut=true;
                            }

                            //«СГ-СГ»
                            if ((i>=2)&&(i<=N-2))
                            {
                                if ((HQt_GetTypeCharEng(S.at(i-2))==2)&&(HQt_GetTypeCharEng(S.at(i-1))==1)&&(HQt_GetTypeCharEng(S.at(i))==2)&&(HQt_GetTypeCharEng(S.at(i+1))==1))
                                    cut=true;
                            }

                            //«ГС-ССГ»
                            if ((i>=2)&&(i<=N-3))
                            {
                                if ((HQt_GetTypeCharEng(S.at(i-2))==1)&&(HQt_GetTypeCharEng(S.at(i-1))==2)&&(HQt_GetTypeCharEng(S.at(i))==2)&&(HQt_GetTypeCharEng(S.at(i+1))==2)&&(HQt_GetTypeCharEng(S.at(i+2))==1))
                                    cut=true;
                            }

                            //«ГСС-ССГ»
                            if ((i>=3)&&(i<=N-3))
                            {
                                if ((HQt_GetTypeCharEng(S.at(i-3))==1)&&(HQt_GetTypeCharEng(S.at(i-2))==2)&&(HQt_GetTypeCharEng(S.at(i-1))==2)&&(HQt_GetTypeCharEng(S.at(i))==2)&&(HQt_GetTypeCharEng(S.at(i+1))==2)&&(HQt_GetTypeCharEng(S.at(i+2))==1))
                                    cut=true;
                            }

                            if (cut==false)
                            {
                                F+=S.at(i);
                                len++;
                            }
                            else
                            {
                                VMHL_Result<<F;
                                F.clear();
                                F=S.at(i);
                                len=1;
                            }

                        }
                        else
                        {
                            F+=S.at(i);
                            len++;
                        }
                    }
                }

            }

        }

    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------

int HQt_GetTypeCharEng(QString x)
{
    /*
    Функция выдает тип вводимого QString (считая, что это буква английская). Нужно для алгоритма переноса строк П.Хpистова в модификации Дымченко и Ваpсанофьева.
    Входные параметры:
     x - некая буква.
    Возвращаемое значение:
     1 - гласная;
     2 - согласная;
     0 - иначе.
    */
    int VMHL_Result=0;

    if (x=="A") VMHL_Result=1;
    if (x=="a") VMHL_Result=1;

    if (x=="B") VMHL_Result=2;
    if (x=="b") VMHL_Result=2;
    if (x=="C") VMHL_Result=2;
    if (x=="c") VMHL_Result=2;
    if (x=="D") VMHL_Result=2;
    if (x=="d") VMHL_Result=2;

    if (x=="E") VMHL_Result=1;
    if (x=="e") VMHL_Result=1;

    if (x=="F") VMHL_Result=2;
    if (x=="f") VMHL_Result=2;
    if (x=="G") VMHL_Result=2;
    if (x=="g") VMHL_Result=2;
    if (x=="H") VMHL_Result=2;
    if (x=="h") VMHL_Result=2;

    if (x=="I") VMHL_Result=1;
    if (x=="i") VMHL_Result=1;

    if (x=="J") VMHL_Result=2;
    if (x=="j") VMHL_Result=2;
    if (x=="K") VMHL_Result=2;
    if (x=="k") VMHL_Result=2;
    if (x=="L") VMHL_Result=2;
    if (x=="l") VMHL_Result=2;
    if (x=="M") VMHL_Result=2;
    if (x=="m") VMHL_Result=2;
    if (x=="N") VMHL_Result=2;
    if (x=="n") VMHL_Result=2;

    if (x=="O") VMHL_Result=1;
    if (x=="o") VMHL_Result=1;

    if (x=="P") VMHL_Result=2;
    if (x=="p") VMHL_Result=2;
    if (x=="Q") VMHL_Result=2;
    if (x=="q") VMHL_Result=2;
    if (x=="R") VMHL_Result=2;
    if (x=="r") VMHL_Result=2;
    if (x=="S") VMHL_Result=2;
    if (x=="s") VMHL_Result=2;
    if (x=="T") VMHL_Result=2;
    if (x=="t") VMHL_Result=2;

    if (x=="U") VMHL_Result=1;
    if (x=="u") VMHL_Result=1;

    if (x=="V") VMHL_Result=2;
    if (x=="v") VMHL_Result=2;
    if (x=="W") VMHL_Result=2;
    if (x=="w") VMHL_Result=2;
    if (x=="X") VMHL_Result=2;
    if (x=="x") VMHL_Result=2;

    if (x=="Y") VMHL_Result=1;
    if (x=="y") VMHL_Result=1;

    if (x=="Z") VMHL_Result=2;
    if (x=="z") VMHL_Result=2;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QStringList HQt_BreakdownOfTextWithWordWrap(QString S, int length)
{
    /*
    Функция разбивает текст на строки длиной не более length. Если может, то ставит переносы.
    Входные параметры:
     S - проверяемая строка,
     length -  длина строки.
    Возвращаемое значение:
     Список строк, на которые разбивается текст.
    Примечание:
     Перевод слов производится по алгоритму П.Хpистова в модификации Дымченко и Ваpсанофьева.
    */
    QStringList VMHL_Result;

    QStringList Temp=HQt_CutToWordsWithWordWrap(S);

    QString F;
    QString now,after;
    int typenow, typeafter;
    QString Te;

    for (int i=0;i<Temp.count();i++)
    {
        if ((F+Temp.at(i)).length()<length)
        {
            F+=Temp.at(i);
        }
        else
        {

            if (i!=0)
            {
                after=Temp.at(i-1);
                now=Temp.at(i);
                typeafter=HQt_CheckLetterFromWord(after.at(after.length()-1));
                typenow=HQt_CheckLetterFromWord(now.at(0));

                if ((typeafter==typenow)&&(typeafter==1)) F+="-";

                bool dl=false;
                if (typeafter!=typenow)
                {
                    if (Temp.at(i).length()>length/3)
                    {
                        dl=true;
                        Te=F+Temp.at(i);
                        int mm;
                        QString nn;
                        if (typenow==1) mm=length-1;else mm=length;
                        if (typenow==1) nn="-";else nn="";
                        while (Te.length()>mm)
                        {
                            F=Te.mid(0,mm)+nn;
                            VMHL_Result << F;
                            Te=Te.mid(mm);
                        }
                        F=Te;
                    }

                }

                if (dl==false)
                {
                    VMHL_Result << F;
                    F.clear();
                    F=Temp.at(i);
                }


            }
            else
            {
                Te=F+Temp.at(i);
                while (Te.length()>length-1)
                {
                    F=Te.mid(0,length-1)+"-";
                    VMHL_Result << F;
                    Te=Te.mid(length-1);
                }
                F=Te;
            }

        }

    }

    if (F.length()!=0)
    {
        if (F.length()>length-1)
        {
            Te=F;
            while (Te.length()>length-1)
            {
                F=Te.mid(0,length-1)+"-";
                VMHL_Result << F;
                Te=Te.mid(length-1);
            }
            F=Te;
        }
        else
        {
            VMHL_Result << F;
        }
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------

bool HQt_CheckIntolerablePunctuation(QString x)
{
    /*
    Является ли символом знаком пунктуации, который нельзя переносить.
    Входные параметры:
     x - некий символ.
    Возвращаемое значение:
     true - символ есть непереносимый символ;
     false - не из слова.
    */
    bool VMHL_Result=false;

    if (x==".") VMHL_Result=true;
    if (x==",") VMHL_Result=true;
    if (x==":") VMHL_Result=true;
    if (x=="!") VMHL_Result=true;
    if (x=="?") VMHL_Result=true;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

int HQt_MaxCountOfQStringList(QStringList x)
{
    /*
    Функция выдает длину макимальной по длине строки в QStringList.
    Входные параметры:
     x - список строк.
    Возвращаемое значение:
     Длина макимальной по длине строки.
    */
    int VMHL_Result=0;

    VMHL_Result=x.at(0).count();

    for (int i=1;i<x.count();i++)
    {
        if (x.at(i).count()>VMHL_Result) VMHL_Result=x.at(i).count();
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------

bool HQt_IsNumeric(QString x)
{
    /*
    Функция проверяет - является ли строка числом.
    Входные параметры:
     x - проверяемая строка.
    Возвращаемое значение:
     true - является числом;
     false - нt является числом.
    */
    bool VMHL_Result;

    x=x.replace(",",".");

    x.toDouble(&VMHL_Result);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

double HQt_QStringToNumber (QString x)
{
    /*
    Функция выводит строку x в число.
    Входные параметры:
     VMHL_X - строка.
    Возвращаемое значение:
     Число из строки.
    */
    double VMHL_Result;

    VMHL_Result=x.toDouble();

    return VMHL_Result;
}
//---------------------------------------------------------------------------

double HQt_QStringToNumber (QString x, bool checkcomma)
{
    /*
    Функция выводит строку x в число.
    Входные параметры:
     VMHL_X - строка;
     checkcomma - проверять наличие запятой.
    Возвращаемое значение:
     Число из строки.
    */
    double VMHL_Result;

    if (checkcomma) x=x.replace(",",".");

    VMHL_Result=x.toDouble();

    return VMHL_Result;
}
//---------------------------------------------------------------------------
