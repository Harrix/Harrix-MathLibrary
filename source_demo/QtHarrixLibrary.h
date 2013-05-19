#ifndef QTHARRIXLIBRARY_H
#define QTHARRIXLIBRARY_H

#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QTextCodec>
#include <QTextEdit>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

QString HQt_ReadFile(QString filename);//Функция считывает текстовой файл в QString.
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

template <class T> QString THQt_ShowNumber (T VMHL_X, QString TitleX, QString NameX);//Функция возвращает строку с выводом некоторого числа VMHL_X с HTML кодами.
template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);//Функция возвращает строку с выводом некоторый вектора VMHL_Vector с HTML кодами.
template <class T> QString THQt_NumberToText (T VMHL_X);//Функция выводит число VMHL_X в строку.
template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);//Функция возвращает строку с выводом некоторый вектора VMHL_Vector в траснпонированном виде с HTML кодами.
template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);//Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами.


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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

#endif // QTHARRIXLIBRARY_H
