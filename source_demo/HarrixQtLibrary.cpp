//HarrixQtLibrary
//Версия 3.31
//Сборник функций для Qt.
//https://github.com/Harrix/HarrixQtLibrary
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibrary.h"

//*****************************************************************
//Обработка данных, считанных их файла
//*****************************************************************
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

    int VHQt_Result_M=A.count("\t")+1;

    return VHQt_Result_M;
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
    int VHQt_Result_N=QStringListFromFile.count();

    return VHQt_Result_N;
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
	 k - номер столбца.
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

    int VHQt_Result_N;
    if (X=="-")
        VHQt_Result_N=i-1;
    else
        VHQt_Result_N=i;

    return VHQt_Result_N;
}
//---------------------------------------------------------------------------
int HQt_CountOfRowsFromQStringList(QStringList QStringListFromFile, int *VHQt_ResultVector)
{
    /*
    Функция подсчитывает сколько строк в каждом столбце из текстового файла с матрицей, который скопировали в QStringListFromFile.
    Считается, что файл правильный, ошибки не проверяются. В строке числа разделяются через табуляцию \t,
    а десятичные числа используют точку, а не запятую. Во всех столбцах должно быть одинаковое число элементов.
    Поэтому, если в одном столбце больше элементов, чем в других, то в остальные столбцы на место недостающих
    элементов ставится знак "-".
    Входные параметры:
     QStringListFromFile - непосредственно сам файл;
     VHQt_ResultVector - сюда количество стро заносится.
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

    for (j=0;j<M;j++) VHQt_ResultVector[j]=0;

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
                VHQt_ResultVector[j]++;
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

void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QDate *VHQt_VectorResult)
{
    /*
    Функция считывает данные какого-то k столбца с датами из QStringList в виде матрицы.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     k - номер столбца, начиная с нуля, который считываем;
     VHQt_VectorResult - сюда будем записывать результат считывания столбца из матрицы.
    Возвращаемое значение:
     Отсутствует.
    Пример содержимого VHQt_VectorResult.
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
        VHQt_VectorResult[i]=DBeginDate;
    }
}
//---------------------------------------------------------------------------
void THQt_ReadColFromQStringList(QStringList QStringListFromFile, int k, QString *VHQt_VectorResult)
{
    /*
    Функция считывает данные какого-то k столбца с датами из QStringList в виде матрицы. Для строк.
    Входные параметры:
     QStringListFromFile - отсюда берем информацию;
     k - номер столбца, начиная с нуля, который считываем;
     VHQt_VectorResult - сюда будем записывать результат считывания столбца из матрицы.
    Возвращаемое значение:
     Отсутствует.
    Пример содержимого VHQt_VectorResult.
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

        VHQt_VectorResult[i]=X;
    }
}
//---------------------------------------------------------------------------


//*****************************************************************
//Получение строк-выводов по данным
//*****************************************************************
QString HQt_BoolToWord(QString Bool)
{
    /*
    Функция переводит переменную, принимающую значения "0" и "1" в слова.
    Входные параметры:
     Bool - исходная переменная.
    Возвращаемое значение:
     Слово, которое характеризует переменную.
*/
    return HQt_BoolToWord(Bool, "Нет", "Да");
}
//---------------------------------------------------------------------------
QString HQt_BoolToWord(QString Bool, QString No, QString Yes)
{
    /*
    Функция переводит переменную, принимающую значения "0" и "1" в слова.
    Входные параметры:
     Bool - исходная переменная.
     No - слово, которое означает 0.
     Yes - слово, которое означает 1.
    Возвращаемое значение:
     Слово, которое характеризует переменную.
*/
    QString Result;

    if (Bool=="0") Result=No;
    if (Bool=="1") Result=Yes;

    return Result;
}
//---------------------------------------------------------------------------
QString HQt_BoolToWord(bool Bool)
{
    /*
    Функция переводит переменную, принимающую значения "0" и "1" в слова.
    Входные параметры:
     Bool - исходная переменная.
    Возвращаемое значение:
     Слово, которое характеризует переменную.
*/
    return HQt_BoolToWord(Bool, "Нет", "Да");
}
//---------------------------------------------------------------------------
QString HQt_BoolToWord(bool Bool, QString No, QString Yes)
{
    /*
    Функция переводит переменную, принимающую значения "0" и "1" в слова.
    Входные параметры:
     Bool - исходная переменная.
     No - слово, которое означает 0.
     Yes - слово, которое означает 1.
    Возвращаемое значение:
     Слово, которое характеризует переменную.
*/
    QString Result;

    if (Bool==false) Result=No;
    if (Bool==true) Result=Yes;

    return Result;
}
//---------------------------------------------------------------------------
QString HQt_BoolToWord(int Bool)
{
    /*
    Функция переводит переменную, принимающую значения "0" и "1" в слова.
    Входные параметры:
     Bool - исходная переменная.
    Возвращаемое значение:
     Слово, которое характеризует переменную.
*/
	return HQt_BoolToWord(Bool, "Нет", "Да");
}
//---------------------------------------------------------------------------
QString HQt_BoolToWord(int Bool, QString No, QString Yes)
{
    /*
    Функция переводит переменную, принимающую значения "0" и "1" в слова.
    Входные параметры:
     Bool - исходная переменная.
     No - слово, которое означает 0.
     Yes - слово, которое означает 1.
    Возвращаемое значение:
     Слово, которое характеризует переменную.
*/
    QString Result;

    if (Bool==0) Result=No;
    if (Bool==1) Result=Yes;

    return Result;
}
//---------------------------------------------------------------------------

QString HQt_RandomRussianLetter()
{
    /*
        Функция генерирует случайную русскую букву в нижнем регистре.
        Входные параметры:
         Отсутствуют.
        Возвращаемое значение:
         Случайная русская буква.
        Примечание:
         Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
         Рекомендую так:
         qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
        */
    QString VHQt_Result;
    QString Alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    int randomNumber = qrand() % Alphabet.length();

    VHQt_Result = Alphabet.at(randomNumber);

    return VHQt_Result;
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
    QString VHQt_Result;
    static const char alphanum[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    char *s=new char[Length+1];

    for (int i=0; i<Length; ++i)
    {
        s[i] = alphanum[qrand() % (sizeof(alphanum) - 1)];
    }

    s[Length] = 0;

    VHQt_Result = QString(s);

    delete [] s;

    return VHQt_Result;
}
//---------------------------------------------------------------------------

QString HQt_TryingReduceString(QString text, int MaxSize)
{
    /*
    Функция старается сократить строку длиной больше MaxSize символов, сокращая слова.
    Входные параметры:
     text - сокращаемая строка;
     MaxSize - с какого количества символов сокращаем строку.
    Возвращаемое значение:
     Сокращенная строка. Обратите внмиание, что строка сокращенная может быть длиннее MaxSize.
*/
    QString Result;

    if (text.count()<=MaxSize)
    {
        Result = text;
    }
    else
    {
        QStringList list = HQt_CutToWords(text);
        QStringList listnew;
        for (int i=0;i<list.count();i++)
        {
            QString temp=list.at(i);
            if (temp.count()>5)
            {
                if (temp.count()<=7)
                    temp=temp.mid(0,3)+".";
                else
                    temp=temp.mid(0,5)+".";
            }
            listnew << temp;
        }
        Result =  listnew.join(' ');
    }

    return Result;
}
//---------------------------------------------------------------------------
QString HQt_TryingReduceString(QString text)
{
    /*
    Функция старается сократить строку длиной больше 40 символов, сокращая слова.
    Входные параметры:
     text - сокращаемая строка.
    Возвращаемое значение:
     Сокращенная строка. Обратите внмиание, что строка сокращенная может быть длиннее 40.
*/
    QString Result;

    if (text.count()<=40)
    {
        Result = text;
    }
    else
    {
        QStringList list = HQt_CutToWords(text);
        QStringList listnew;
        for (int i=0;i<list.count();i++)
        {
            QString temp=list.at(i);
            if (temp.count()>5)
            {
                if (temp.count()<=7)
                    temp=temp.mid(0,3)+".";
                else
                    temp=temp.mid(0,5)+".";
            }
            listnew << temp;
        }
        Result =  listnew.join(' ');
    }

    return Result;
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


//*****************************************************************
//Работа с алфавитом и переносами
//*****************************************************************
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
    QStringList VHQt_Result;

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
                            VHQt_Result << F;
                            Te=Te.mid(mm);
                        }
                        F=Te;
                    }

                }

                if (dl==false)
                {
                    VHQt_Result << F;
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
                    VHQt_Result << F;
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
                VHQt_Result << F;
                Te=Te.mid(length-1);
            }
            F=Te;
        }
        else
        {
            VHQt_Result << F;
        }
    }

    return VHQt_Result;
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
    bool VHQt_Result=false;

    if (x==".") VHQt_Result=true;
    if (x==",") VHQt_Result=true;
    if (x==":") VHQt_Result=true;
    if (x=="!") VHQt_Result=true;
    if (x=="?") VHQt_Result=true;

    return VHQt_Result;
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
    bool VHQt_Result=false;

    if (x=="А") VHQt_Result=true;
    if (x=="а") VHQt_Result=true;
    if (x=="Б") VHQt_Result=true;
    if (x=="б") VHQt_Result=true;
    if (x=="В") VHQt_Result=true;
    if (x=="в") VHQt_Result=true;
    if (x=="Г") VHQt_Result=true;
    if (x=="г") VHQt_Result=true;
    if (x=="Д") VHQt_Result=true;
    if (x=="д") VHQt_Result=true;
    if (x=="Е") VHQt_Result=true;
    if (x=="е") VHQt_Result=true;
    if (x=="Ё") VHQt_Result=true;
    if (x=="ё") VHQt_Result=true;
    if (x=="Ж") VHQt_Result=true;
    if (x=="ж") VHQt_Result=true;
    if (x=="З") VHQt_Result=true;
    if (x=="з") VHQt_Result=true;
    if (x=="И") VHQt_Result=true;
    if (x=="и") VHQt_Result=true;
    if (x=="Й") VHQt_Result=true;
    if (x=="й") VHQt_Result=true;
    if (x=="К") VHQt_Result=true;
    if (x=="к") VHQt_Result=true;
    if (x=="Л") VHQt_Result=true;
    if (x=="л") VHQt_Result=true;
    if (x=="М") VHQt_Result=true;
    if (x=="м") VHQt_Result=true;
    if (x=="Н") VHQt_Result=true;
    if (x=="н") VHQt_Result=true;
    if (x=="О") VHQt_Result=true;
    if (x=="о") VHQt_Result=true;
    if (x=="П") VHQt_Result=true;
    if (x=="п") VHQt_Result=true;
    if (x=="Р") VHQt_Result=true;
    if (x=="р") VHQt_Result=true;
    if (x=="С") VHQt_Result=true;
    if (x=="с") VHQt_Result=true;
    if (x=="Т") VHQt_Result=true;
    if (x=="т") VHQt_Result=true;
    if (x=="У") VHQt_Result=true;
    if (x=="у") VHQt_Result=true;
    if (x=="Ф") VHQt_Result=true;
    if (x=="ф") VHQt_Result=true;
    if (x=="Х") VHQt_Result=true;
    if (x=="х") VHQt_Result=true;
    if (x=="Ц") VHQt_Result=true;
    if (x=="ц") VHQt_Result=true;
    if (x=="Ч") VHQt_Result=true;
    if (x=="ч") VHQt_Result=true;
    if (x=="Ш") VHQt_Result=true;
    if (x=="ш") VHQt_Result=true;
    if (x=="Щ") VHQt_Result=true;
    if (x=="щ") VHQt_Result=true;
    if (x=="Ъ") VHQt_Result=true;
    if (x=="ъ") VHQt_Result=true;
    if (x=="Ы") VHQt_Result=true;
    if (x=="ы") VHQt_Result=true;
    if (x=="Ь") VHQt_Result=true;
    if (x=="ь") VHQt_Result=true;
    if (x=="Э") VHQt_Result=true;
    if (x=="э") VHQt_Result=true;
    if (x=="Ю") VHQt_Result=true;
    if (x=="ю") VHQt_Result=true;
    if (x=="Я") VHQt_Result=true;
    if (x=="я") VHQt_Result=true;
    if (x=="A") VHQt_Result=true;
    if (x=="a") VHQt_Result=true;
    if (x=="B") VHQt_Result=true;
    if (x=="b") VHQt_Result=true;
    if (x=="C") VHQt_Result=true;
    if (x=="c") VHQt_Result=true;
    if (x=="D") VHQt_Result=true;
    if (x=="d") VHQt_Result=true;
    if (x=="E") VHQt_Result=true;
    if (x=="e") VHQt_Result=true;
    if (x=="F") VHQt_Result=true;
    if (x=="f") VHQt_Result=true;
    if (x=="G") VHQt_Result=true;
    if (x=="g") VHQt_Result=true;
    if (x=="H") VHQt_Result=true;
    if (x=="h") VHQt_Result=true;
    if (x=="I") VHQt_Result=true;
    if (x=="i") VHQt_Result=true;
    if (x=="J") VHQt_Result=true;
    if (x=="j") VHQt_Result=true;
    if (x=="K") VHQt_Result=true;
    if (x=="k") VHQt_Result=true;
    if (x=="L") VHQt_Result=true;
    if (x=="l") VHQt_Result=true;
    if (x=="M") VHQt_Result=true;
    if (x=="m") VHQt_Result=true;
    if (x=="N") VHQt_Result=true;
    if (x=="n") VHQt_Result=true;
    if (x=="O") VHQt_Result=true;
    if (x=="o") VHQt_Result=true;
    if (x=="P") VHQt_Result=true;
    if (x=="p") VHQt_Result=true;
    if (x=="Q") VHQt_Result=true;
    if (x=="q") VHQt_Result=true;
    if (x=="R") VHQt_Result=true;
    if (x=="r") VHQt_Result=true;
    if (x=="S") VHQt_Result=true;
    if (x=="s") VHQt_Result=true;
    if (x=="T") VHQt_Result=true;
    if (x=="t") VHQt_Result=true;
    if (x=="U") VHQt_Result=true;
    if (x=="u") VHQt_Result=true;
    if (x=="V") VHQt_Result=true;
    if (x=="v") VHQt_Result=true;
    if (x=="W") VHQt_Result=true;
    if (x=="w") VHQt_Result=true;
    if (x=="X") VHQt_Result=true;
    if (x=="x") VHQt_Result=true;
    if (x=="Y") VHQt_Result=true;
    if (x=="y") VHQt_Result=true;
    if (x=="Z") VHQt_Result=true;
    if (x=="z") VHQt_Result=true;
    if (x=="0") VHQt_Result=true;
    if (x=="1") VHQt_Result=true;
    if (x=="2") VHQt_Result=true;
    if (x=="3") VHQt_Result=true;
    if (x=="4") VHQt_Result=true;
    if (x=="5") VHQt_Result=true;
    if (x=="6") VHQt_Result=true;
    if (x=="7") VHQt_Result=true;
    if (x=="8") VHQt_Result=true;
    if (x=="9") VHQt_Result=true;
    if (x=="_") VHQt_Result=true;
    if (x==".") VHQt_Result=true;
    if (x==",") VHQt_Result=true;
    if (x==":") VHQt_Result=true;
    if (x=="!") VHQt_Result=true;
    if (x=="?") VHQt_Result=true;

    return VHQt_Result;
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
    bool VHQt_Result=false;

    QString x;

    for (int i=0;i<S.count();i++)
    {
        x=S.at(i);

        if (x=="А") VHQt_Result=true;
        if (x=="а") VHQt_Result=true;
        if (x=="Б") VHQt_Result=true;
        if (x=="б") VHQt_Result=true;
        if (x=="В") VHQt_Result=true;
        if (x=="в") VHQt_Result=true;
        if (x=="Г") VHQt_Result=true;
        if (x=="г") VHQt_Result=true;
        if (x=="Д") VHQt_Result=true;
        if (x=="д") VHQt_Result=true;
        if (x=="Е") VHQt_Result=true;
        if (x=="е") VHQt_Result=true;
        if (x=="Ё") VHQt_Result=true;
        if (x=="ё") VHQt_Result=true;
        if (x=="Ж") VHQt_Result=true;
        if (x=="ж") VHQt_Result=true;
        if (x=="З") VHQt_Result=true;
        if (x=="з") VHQt_Result=true;
        if (x=="И") VHQt_Result=true;
        if (x=="и") VHQt_Result=true;
        if (x=="Й") VHQt_Result=true;
        if (x=="й") VHQt_Result=true;
        if (x=="К") VHQt_Result=true;
        if (x=="к") VHQt_Result=true;
        if (x=="Л") VHQt_Result=true;
        if (x=="л") VHQt_Result=true;
        if (x=="М") VHQt_Result=true;
        if (x=="м") VHQt_Result=true;
        if (x=="Н") VHQt_Result=true;
        if (x=="н") VHQt_Result=true;
        if (x=="О") VHQt_Result=true;
        if (x=="о") VHQt_Result=true;
        if (x=="П") VHQt_Result=true;
        if (x=="п") VHQt_Result=true;
        if (x=="Р") VHQt_Result=true;
        if (x=="р") VHQt_Result=true;
        if (x=="С") VHQt_Result=true;
        if (x=="с") VHQt_Result=true;
        if (x=="Т") VHQt_Result=true;
        if (x=="т") VHQt_Result=true;
        if (x=="У") VHQt_Result=true;
        if (x=="у") VHQt_Result=true;
        if (x=="Ф") VHQt_Result=true;
        if (x=="ф") VHQt_Result=true;
        if (x=="Х") VHQt_Result=true;
        if (x=="х") VHQt_Result=true;
        if (x=="Ц") VHQt_Result=true;
        if (x=="ц") VHQt_Result=true;
        if (x=="Ч") VHQt_Result=true;
        if (x=="ч") VHQt_Result=true;
        if (x=="Ш") VHQt_Result=true;
        if (x=="ш") VHQt_Result=true;
        if (x=="Щ") VHQt_Result=true;
        if (x=="щ") VHQt_Result=true;
        if (x=="Ъ") VHQt_Result=true;
        if (x=="ъ") VHQt_Result=true;
        if (x=="Ы") VHQt_Result=true;
        if (x=="ы") VHQt_Result=true;
        if (x=="Ь") VHQt_Result=true;
        if (x=="ь") VHQt_Result=true;
        if (x=="Э") VHQt_Result=true;
        if (x=="э") VHQt_Result=true;
        if (x=="Ю") VHQt_Result=true;
        if (x=="ю") VHQt_Result=true;
        if (x=="Я") VHQt_Result=true;
        if (x=="я") VHQt_Result=true;
    }

    return VHQt_Result;
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
    QStringList VHQt_Result;

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
                VHQt_Result<<F;
            }
            else
            {
                VHQt_Result<<F;
                F.clear();
                F=S.at(i);
                VHQt_Result<<F;
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
                        VHQt_Result<<F;
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
                        VHQt_Result<<F;
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

    return VHQt_Result;
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
    QStringList VHQt_Result;

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
                VHQt_Result<<F;
            }
            else
            {
                VHQt_Result<<F;
                F.clear();
                F=S.at(i);
                VHQt_Result<<F;
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
                        VHQt_Result<<F;
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
                        VHQt_Result<<F;
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
                                VHQt_Result<<F;
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

    return VHQt_Result;
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
    int VHQt_Result=0;

    if (x=="A") VHQt_Result=1;
    if (x=="a") VHQt_Result=1;

    if (x=="B") VHQt_Result=2;
    if (x=="b") VHQt_Result=2;
    if (x=="C") VHQt_Result=2;
    if (x=="c") VHQt_Result=2;
    if (x=="D") VHQt_Result=2;
    if (x=="d") VHQt_Result=2;

    if (x=="E") VHQt_Result=1;
    if (x=="e") VHQt_Result=1;

    if (x=="F") VHQt_Result=2;
    if (x=="f") VHQt_Result=2;
    if (x=="G") VHQt_Result=2;
    if (x=="g") VHQt_Result=2;
    if (x=="H") VHQt_Result=2;
    if (x=="h") VHQt_Result=2;

    if (x=="I") VHQt_Result=1;
    if (x=="i") VHQt_Result=1;

    if (x=="J") VHQt_Result=2;
    if (x=="j") VHQt_Result=2;
    if (x=="K") VHQt_Result=2;
    if (x=="k") VHQt_Result=2;
    if (x=="L") VHQt_Result=2;
    if (x=="l") VHQt_Result=2;
    if (x=="M") VHQt_Result=2;
    if (x=="m") VHQt_Result=2;
    if (x=="N") VHQt_Result=2;
    if (x=="n") VHQt_Result=2;

    if (x=="O") VHQt_Result=1;
    if (x=="o") VHQt_Result=1;

    if (x=="P") VHQt_Result=2;
    if (x=="p") VHQt_Result=2;
    if (x=="Q") VHQt_Result=2;
    if (x=="q") VHQt_Result=2;
    if (x=="R") VHQt_Result=2;
    if (x=="r") VHQt_Result=2;
    if (x=="S") VHQt_Result=2;
    if (x=="s") VHQt_Result=2;
    if (x=="T") VHQt_Result=2;
    if (x=="t") VHQt_Result=2;

    if (x=="U") VHQt_Result=1;
    if (x=="u") VHQt_Result=1;

    if (x=="V") VHQt_Result=2;
    if (x=="v") VHQt_Result=2;
    if (x=="W") VHQt_Result=2;
    if (x=="w") VHQt_Result=2;
    if (x=="X") VHQt_Result=2;
    if (x=="x") VHQt_Result=2;

    if (x=="Y") VHQt_Result=1;
    if (x=="y") VHQt_Result=1;

    if (x=="Z") VHQt_Result=2;
    if (x=="z") VHQt_Result=2;

    return VHQt_Result;
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
    int VHQt_Result=0;

    if (x=="А") VHQt_Result=1;
    if (x=="а") VHQt_Result=1;

    if (x=="Б") VHQt_Result=2;
    if (x=="б") VHQt_Result=2;
    if (x=="В") VHQt_Result=2;
    if (x=="в") VHQt_Result=2;
    if (x=="Г") VHQt_Result=2;
    if (x=="г") VHQt_Result=2;
    if (x=="Д") VHQt_Result=2;
    if (x=="д") VHQt_Result=2;

    if (x=="Е") VHQt_Result=1;
    if (x=="е") VHQt_Result=1;
    if (x=="Ё") VHQt_Result=1;
    if (x=="ё") VHQt_Result=1;

    if (x=="Ж") VHQt_Result=2;
    if (x=="ж") VHQt_Result=2;
    if (x=="З") VHQt_Result=2;
    if (x=="з") VHQt_Result=2;

    if (x=="И") VHQt_Result=1;
    if (x=="и") VHQt_Result=1;

    if (x=="Й") VHQt_Result=3;
    if (x=="й") VHQt_Result=3;

    if (x=="К") VHQt_Result=2;
    if (x=="к") VHQt_Result=2;
    if (x=="Л") VHQt_Result=2;
    if (x=="л") VHQt_Result=2;
    if (x=="М") VHQt_Result=2;
    if (x=="м") VHQt_Result=2;
    if (x=="Н") VHQt_Result=2;
    if (x=="н") VHQt_Result=2;

    if (x=="О") VHQt_Result=1;
    if (x=="о") VHQt_Result=1;

    if (x=="П") VHQt_Result=2;
    if (x=="п") VHQt_Result=2;
    if (x=="Р") VHQt_Result=2;
    if (x=="р") VHQt_Result=2;
    if (x=="С") VHQt_Result=2;
    if (x=="с") VHQt_Result=2;
    if (x=="Т") VHQt_Result=2;
    if (x=="т") VHQt_Result=2;

    if (x=="У") VHQt_Result=1;
    if (x=="у") VHQt_Result=1;

    if (x=="Ф") VHQt_Result=2;
    if (x=="ф") VHQt_Result=2;
    if (x=="Х") VHQt_Result=2;
    if (x=="х") VHQt_Result=2;
    if (x=="Ц") VHQt_Result=2;
    if (x=="ц") VHQt_Result=2;
    if (x=="Ч") VHQt_Result=2;
    if (x=="ч") VHQt_Result=2;
    if (x=="Ш") VHQt_Result=2;
    if (x=="ш") VHQt_Result=2;
    if (x=="Щ") VHQt_Result=2;
    if (x=="щ") VHQt_Result=2;

    if (x=="Ъ") VHQt_Result=3;
    if (x=="ъ") VHQt_Result=3;

    if (x=="Ы") VHQt_Result=1;
    if (x=="ы") VHQt_Result=1;

    if (x=="Ь") VHQt_Result=3;
    if (x=="ь") VHQt_Result=3;

    if (x=="Э") VHQt_Result=1;
    if (x=="э") VHQt_Result=1;
    if (x=="Ю") VHQt_Result=1;
    if (x=="ю") VHQt_Result=1;
    if (x=="Я") VHQt_Result=1;
    if (x=="я") VHQt_Result=1;

    return VHQt_Result;
}
//---------------------------------------------------------------------------

QString HQt_RussianLetter(int i)
{
    /*
        Функция генерирует русскую букву в нижнем регистре по номеру ее в алфавите.
        Входные параметры:
         i - номер буквы в русском алфавите (нумерация с нуля идет).
        Возвращаемое значение:
         Русская буква.
        */
    QString VHQt_Result;
    QString Alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    VHQt_Result = Alphabet.at(i);

    return VHQt_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Работа с датами
//*****************************************************************
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


//*****************************************************************
//Работа с файлами и папками
//*****************************************************************
bool HQt_CopyFile(QString filename, QString dir)
{
    /*
    Функция копирует файл filename в папку dir.
    Входные параметры:
     filename - имя файла (с полным путем);
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
     filename - имя файла (с полным путем);
     dir - путь к папке, куда нужно скопировать файл;
     overwrite - если true, то перезаписывать, если false, то не перезаписывать;
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
bool HQt_CopyFile(QString filename, QString dir, bool overwrite, bool dirmake)
{
    /*
    Функция копирует файл filename в папку dir, с возможностью перезаписи.
    Входные параметры:
     filename - имя файла (с полным путем);
     dir - путь к папке, куда нужно скопировать файл;
     overwrite - если true, то перезаписывать, если false, то не перезаписывать;
     dirmake - если true, то если нет директории, то она создается.
    Возвращаемое значение:
     true - если скопировалось удачно,
     false - если скопировалось неудачно.
    */
    filename = QDir::toNativeSeparators(filename);
    QFileInfo fileInfo(filename);

    QString Separator="\\";

    QString destinationFile = dir + Separator + fileInfo.fileName();

    if ((!HQt_DirExists(dir))&&(dirmake==true))
    {
        HQt_DirMake(dir);
    }

    if ((QFile::exists(destinationFile))&&(overwrite==true))
    {
        QFile::remove(destinationFile);
    }

    bool result = QFile::copy(filename, destinationFile);
    return result;
}
//---------------------------------------------------------------------------

bool HQt_DirDelete(QString path)
{
    /*
    Функция удаляет директорию и всё ее содержимое.
    Входные параметры:
     path - полный путь к папке.
    Возвращаемое значение:
     true - если удаление прошло нормально.
     false -  если удаление прошло не нормально.
    */
    bool result = true;
    QDir dir(path);

    if (dir.exists(path)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = HQt_DirDelete(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(path);
    }
    return result;
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

QString HQt_GetExpFromFilename(QString filename)
{
    /*
    Функция получает расширение файла по его имени.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     Строка значением расширения файла в нижнем регистре.
    */
    QString exp;
    exp=filename.mid(filename.lastIndexOf(".")+1);
    exp=exp.toLower();
    return exp;
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
    QString line;
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
    QString line;
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

bool HQt_RenameFile(QString filename, QString newfilename)
{
    /*
    Функция переименовывает файл filename в newfilename.
    Входные параметры:
     filename - имя файла (с полным путем),
     newfilename - новое имя файла (без полного пути).
    Возвращаемое значение:
     true - если переименовалось удачно,
     false - если переименовалось неудачно.
    */
    filename = QDir::toNativeSeparators(filename);
    newfilename = QDir::toNativeSeparators(newfilename);
    QString Separator="\\";

    QString refilename = filename.mid(0,filename.lastIndexOf(Separator)+1) + newfilename;

    bool result = QFile::rename(filename,refilename);
    return result;
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


//*****************************************************************
//Работа с цветом
//*****************************************************************
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
     Отсутствует.
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


//*****************************************************************
//Работа со строками и списками строк
//*****************************************************************
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

    QStringList GG = StringList;

    for (int i=0;i<GG.count();i++)
    {
        if (GG.at(i)==String)
            in=true;
    }

    if (!in) GG << String;

    return GG;
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
     false - не является числом.
    */
    bool VHQt_Result;

    x=x.replace(",",".");

    x.toDouble(&VHQt_Result);

    return VHQt_Result;
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
    int VHQt_Result=0;

    VHQt_Result=x.at(0).count();

    for (int i=1;i<x.count();i++)
    {
        if (x.at(i).count()>VHQt_Result) VHQt_Result=x.at(i).count();
    }

    return VHQt_Result;
}
//---------------------------------------------------------------------------

bool HQt_NaturalCompareTwoQStrings(const QString& s1,const QString& s2)
{
    /*
    Функция сравнивает две строки и определяет какая строчка идет первой. Служебная функция для сортировки строк
    в обычном стиле, когда строки: z1, z10, z2 сортируются как z1, z2, z10.
    Входные параметры:
     s1 - первая строка;
     s2 - вторая строка.
    Возвращаемое значение:
     false - когда вторая строка должна быть первой;
     true - когда первая строка должна быть первой.
    Примечание:
     Функция взята отсюда: http://www.qtcentre.org/archive/index.php/t-21411.html
    */
    // ignore common prefix..
    int i = 0;
    while ((i < s1.length()) && (i < s2.length()) && (s1.at(i).toLower() == s2.at(i).toLower()))
        ++i;
    ++i;
    // something left to compare?
    if ((i < s1.length()) && (i < s2.length()))
    {
        // get number prefix from position i - doesnt matter from which string
        int k = i-1;
        //If not number return native comparator
        if(!s1.at(k).isNumber() || !s2.at(k).isNumber())
        {
            //Two next lines
            //E.g. 1_... < 12_...
            if(s1.at(k).isNumber())
                return false;
            if(s2.at(k).isNumber())
                return true;
            return QString::compare(s1, s2, Qt::CaseSensitive) < 0;
        }
        QString n = "";
        k--;
        while ((k >= 0) && (s1.at(k).isNumber()))
        {
            n = s1.at(k)+n;
            --k;
        }
        // get relevant/signficant number string for s1
        k = i-1;
        QString n1 = "";
        while ((k < s1.length()) && (s1.at(k).isNumber()))
        {
            n1 += s1.at(k);
            ++k;
        }

        // get relevant/signficant number string for s2
        //Decrease by
        k = i-1;
        QString n2 = "";
        while ((k < s2.length()) && (s2.at(k).isNumber()))
        {
            n2 += s2.at(k);
            ++k;
        }

        // got two numbers to compare?
        if (!n1.isEmpty() && !n2.isEmpty())
            return (n+n1).toInt() < (n+n2).toInt();
        else
        {
            // not a number has to win over a number.. number could have ended earlier... same prefix..
            if (!n1.isEmpty())
                return false;
            if (!n2.isEmpty())
                return true;
            return s1.at(i) < s2.at(i);
        }
    }
    else
    {
        // shortest string wins
        return s1.length() < s2.length();
    }
}
//---------------------------------------------------------------------------

QStringList HQt_NaturalSortingQStringList (QStringList StringList)
{
    /*
    Функция сортировки строк в сортировки строк QStringList в натуральном виде, например,
    строки: z1, z10, z2 сортируются как z1, z2, z10.
    Входные параметры:
     StringList - сортируемый список строк.
    Возвращаемое значение:
     Отсортированный список строк.
    */
    QStringList SortList=StringList;

    qSort(SortList.begin(),SortList.end(),HQt_NaturalCompareTwoQStrings);

    return SortList;
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

double HQt_QStringToNumber (QString x)
{
    /*
    Функция выводит строку x в число.
    Входные параметры:
     x - строка.
    Возвращаемое значение:
     Число из строки.
    */
    double VHQt_Result;

    VHQt_Result=x.toDouble();

    return VHQt_Result;
}
//---------------------------------------------------------------------------
double HQt_QStringToNumber (QString x, bool checkcomma)
{
    /*
    Функция выводит строку x в число.
    Входные параметры:
     x - строка;
     checkcomma - проверять наличие запятой.
    Возвращаемое значение:
     Число из строки.
    */
    double VHQt_Result;

    if (checkcomma) x=x.replace(",",".");

    VHQt_Result=x.toDouble();

    return VHQt_Result;
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
    int VHQt_Result = -1;
    bool in=false;
    int i=0;

    while ((i<StringList.count())&&(in!=true))
    {
        if (StringList.at(i)==String)
            VHQt_Result=i;
        i++;
    }

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result=String.replace("_","\\_").replace("#","\\#").replace("~", "$\\sim$");

    return VHQt_Result;
}
//---------------------------------------------------------------------------

QString HQt_StringFromLaTeX (QString String)
{
    /*
	Функция обрабатывает строку String из переделки функции HQt_StringForLaTeX в нормальную строку.
	Еще удаляются знаки $, которые обрамляют формулы.
    Входные параметры:
     String - обрабатываемая строка.
    Возвращаемое значение:
     Обработанная строка.
    */
    QString VHQt_Result;

    VHQt_Result=String.replace("\\_","_").replace("$","").replace("$\\sim$","~").replace("\\#","#");

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result=String.replace("_","").replace("#","\\#");

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result=String.mid(String.indexOf("=")+1);

    VHQt_Result=VHQt_Result.trimmed();

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result=String.mid(0,String.indexOf("="));

    VHQt_Result=VHQt_Result.trimmed();

    return VHQt_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Служебные функции
//*****************************************************************
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