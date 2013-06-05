//Сборник функций для Qt. Версия v.2.0.
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