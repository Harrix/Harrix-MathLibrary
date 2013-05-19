#ifndef QTHARRIXLIBRARY_H
#define QTHARRIXLIBRARY_H

#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QTextCodec>

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

#endif // QTHARRIXLIBRARY_H
