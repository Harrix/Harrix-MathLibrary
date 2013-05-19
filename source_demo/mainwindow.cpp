#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardItemModel>

#include "MathHarrixLibrary.h"

#include "QtHarrixLibrary.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DS=QDir::separator();
    path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    MHL_SeedRandom();//Инициализация датчика случайных чисел

    QStandardItemModel *model = new QStandardItemModel;//новая модель списка
    QStandardItem *item;//элемент списка

    //добавление новых элементов
    item = new QStandardItem(QString("TMHL_FillVector"));
    model->appendRow(item);

    //соединение модели списка с конкретным списком
    ui->listView->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//---------------------------------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}
//---------------------------------------------------------------------------

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    Html="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" />\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n<style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n";

    QString NameFunction;//Какая функция вызывается

    //выдергиваем текст
    NameFunction=index.data(Qt::DisplayRole).toString();

    //используем результат
    if (NameFunction=="TMHL_FillVector")
    {
        int VMHL_N=10;//Размер массива
        int *a;
        a=new int[VMHL_N];

        int x=5;//заполнитель

        //Вызов функции
        TMHL_FillVector(a,VMHL_N,x);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        // a[0] = 5
        // a[1] = 5
        // a[2] = 5
        // a[3] = 5
        // a[4] = 5
        // a[5] = 5
        // a[6] = 5
        // a[7] = 5
        // a[8] = 5
        // a[9] = 5
        delete [] a;
    }

    //Показ итогового результата
    Html+="</body></html>";
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowNumber (T VMHL_X, QString TitleX, QString NameX)
{
    /*
    Функция выводит число VMHL_X в textEdit.
    Входные параметры:
     VMHL_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowNumber (VMHL_X, TitleX, NameX);// из QtHarrixLibrary.h
    Html+=VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString MainWindow::MHL_NumberToText (T VMHL_X)
{
    /*
    Функция выводит число VMHL_X в строку.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_NumberToText (VMHL_X);
    return VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VMHL_Vector в textEdit
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowVector (VMHL_Vector,VMHL_N, TitleVector, NameVector);// из QtHarrixLibrary.h
    Html+=VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция выводит вектор VMHL_Vector в textEdit в траснпонированном виде
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowVectorT (VMHL_Vector,VMHL_N, TitleVector, NameVector);// из QtHarrixLibrary.h
    Html+=VMHL_Result;
}
//---------------------------------------------------------------------------

template <class T> void MainWindow::MHL_ShowMatrix (T **VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция выводит матрицу VMHL_Matrix в textEdit
    Входные параметры:
     VMHL_Matrix - указатель на указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;
    VMHL_Result=THQt_ShowMatrix (VMHL_Matrix, VMHL_N ,VMHL_M, TitleMatrix, NameMatrix);// из QtHarrixLibrary.h
    Html+=VMHL_Result;
}
//---------------------------------------------------------------------------


