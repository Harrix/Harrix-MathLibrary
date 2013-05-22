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

    item = new QStandardItem(QString("TMHL_MaximumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_MinimumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SumVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SumSquareVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_ZeroVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_VectorToVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_DegToRad"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RadToDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_BitNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealMatrix"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomUniform"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomNormal"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomUniformInt"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealMatrixInCols"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealMatrixInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealMatrixInRows"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomRealVectorInElements"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_RandomVectorOfProbability"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cos"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CosDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cosec"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CosecDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cotan"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_CotanDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Sec"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SecDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Sin"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_SinDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Tan"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_TanDeg"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_OrdinalVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_OrdinalVectorZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SearchFirstNotZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_SearchFirstZero"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_VectorMinusVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_VectorPlusVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_VectorMultiplyNumber"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cosech"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cosh"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Cotanh"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Sech"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Sinh"));
    model->appendRow(item);

    item = new QStandardItem(QString("MHL_Tanh"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfMaximumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfMinimumOfVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfNegativeValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfPositiveValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_NumberOfZeroValues"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_FibonacciNumbersVector"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_EqualityOfVectors"));
    model->appendRow(item);

    item = new QStandardItem(QString("TMHL_CheckElementInVector"));
    model->appendRow(item);


    model->sort(0);

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

    if (NameFunction=="TMHL_MaximumOfVector")
    {
        int VMHL_N=10;//Размер массива
        double max;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        max=TMHL_MaximumOfVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //0.0988159
        //0.61557
        //0.674866
        //0.937286
        //0.521759
        //0.074585
        //0.733337
        //0.5979
        //0.604309
        //0.917114

        MHL_ShowNumber (max,"Максимальное значение в векторе", "max");
        //Максимальное значение в векторе:
        //max=0.937286

        delete [] a;
    }

    if (NameFunction=="TMHL_MinimumOfVector")
    {
        int VMHL_N=10;//Размер массива
        double min;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        min=TMHL_MinimumOfVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //0.777496
        //0.446411
        //0.14621
        //0.938232
        //0.354156
        //0.831604
        //0.420349
        //0.50061
        //0.491394
        //0.0112305

        MHL_ShowNumber (min,"Минимальное значение в векторе", "min");
        //Максимальное значение в векторе:
        //max=0.0112305

        delete [] a;
    }

    if (NameFunction=="TMHL_SumVector")
    {
        int VMHL_N=10;//Размер массива
        double sum;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomNumber();//Заполняем случайными значениями

        //Вызов функции
        sum=TMHL_SumVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //0.886475
        //0.998413
        //0.242859
        //0.221405
        //0.292175
        //0.134247
        //0.723846
        //0.271393
        //0.188904
        //0.727936

        MHL_ShowNumber (sum,"Сумма элементов массива", "sum");
        //Сумма элементов массива:
        //sum=4.68765

        delete [] a;
    }

    if (NameFunction=="TMHL_SumSquareVector")
    {
        int VMHL_N=10;//Размер массива
        double sum;
        double *a;
        a=new double[VMHL_N];

        for (int i=0;i<VMHL_N;i++) a[i]=i;//Заполняем значениями

        //Вызов функции
        sum=TMHL_SumSquareVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Заполненный вектор", "a");
        //Заполненный вектор:
        //a =
        //0
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9

        MHL_ShowNumber (sum,"Сумма квадратов элементов массива", "sum");
        //Сумма квадратов элементов массива:
        //sum=285

        delete [] a;
    }

    if (NameFunction=="TMHL_ZeroVector")
    {
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];

        //Вызов функции
        TMHL_ZeroVector(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Зануленный вектор", "a");
        //Зануленный вектор:
        //a =
        //0
        //0
        //0
        //0
        //0
        //0
        //0
        //0
        //0
        //0

        delete [] a;
    }

    if (NameFunction=="TMHL_VectorToVector")
    {
        int VMHL_N=10;//Размер массива

        double *a;
        a=new double[VMHL_N];
        for (int i=0;i<VMHL_N;i++) a[i]=MHL_RandomNumber();//Заполняем случайными значениями

        double *b;
        b=new double[VMHL_N];

        //Вызов функции
        TMHL_VectorToVector(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Первоначальный вектор", "a");
        //Первоначальный вектор:
        //a =
        //0.874634
        //0.28656
        //0.676056
        //0.861755
        //0.0521851
        //0.308319
        //0.348267
        //0.431671
        //0.186462
        //0.562805

        MHL_ShowVector (b,VMHL_N,"Вектор, в который скопировали первый", "b");
        //Вектор, в который скопировали первый:
        //b =
        //0.874634
        //0.28656
        //0.676056
        //0.861755
        //0.0521851
        //0.308319
        //0.348267
        //0.431671
        //0.186462
        //0.562805

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="MHL_DegToRad")
    {
        double Rad;
        double Deg=90;//Угол в градусах

        //Вызов функции
        Rad=MHL_DegToRad(Deg);

        //Используем полученный результат
        MHL_ShowNumber(Rad,"Угол "+MHL_NumberToText(Deg)+" градусов","равен в радианах");
        //Угол 90 градусов:
        //равен в радианах=1.5708
    }

    if (NameFunction=="MHL_RadToDeg")
    {
        double Deg;
        double Rad=MHL_PI;//Угол в радианах

        //Вызов функции
        Deg=MHL_RadToDeg(Rad);

        //Используем полученный результат
        MHL_ShowNumber(Deg,"Угол "+MHL_NumberToText(Rad)+" радиан","равен в градусах");
        //Угол 3.14159 радиан:
        //равен в градусах=180
    }

    if (NameFunction=="MHL_BitNumber")
    {
        int x;
        double P=0.8;//Угол в радианах

        //Вызов функции
        x=MHL_BitNumber(P);

        //Используем полученный результат
        MHL_ShowNumber(x,"Из 0 и 1 с вероятностью "+MHL_NumberToText(P),"выбрано");

        //Вызов функции
        x=MHL_BitNumber();

        //Используем полученный результат
        MHL_ShowNumber(x,"Из 0 и 1 с вероятностью 0.5","выбрано");
    }

    if (NameFunction=="MHL_RandomUniform")
    {
        double x;

        //Вызов функции
        x=MHL_RandomUniform(10,100);

        //Используем полученный результат
        MHL_ShowNumber(x,"Случайное число из интервала [10;100]","x");
        //Случайное число из интервала [10;100]:
        //x=68.4308
    }

    if (NameFunction=="MHL_RandomRealMatrix")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];

        double Left=-3;//левая граница интервала;
        double Right=3;//правая граница интервала;

        //Вызов функции
        MHL_RandomRealMatrix(a,Left,Right,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //1.97571	0.862793	-0.357422
        //-2.62701	-0.202515	-2.79932
        //1.38794	1.35535	-2.29449

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
    }

    if (NameFunction=="MHL_RandomNormal")
    {
        double x;
        double Mean=10;//математическое ожидание
        double StdDev=3;//среднеквадратичное отклонение

        //Вызов функции
        x=MHL_RandomNormal(Mean,StdDev);

        //Используем полученный результат
        MHL_ShowNumber(x,"Случайное число по нормальному закону (Mean="+MHL_NumberToText(Mean)+", StdDev="+MHL_NumberToText(StdDev)+")","x");
        //Случайное число по нормальному закону (Mean=10, StdDev=3):
        //x=10.9968
    }

    if (NameFunction=="MHL_RandomUniformInt")
    {
        double x;
        int s0=0,s1=0,s2=0,s3=0;

        //Вызов функции
        for (int i=0;i<1000;i++)
        {
        x=MHL_RandomUniformInt(0,3);
        if (x==0) s0++;
        if (x==1) s1++;
        if (x==2) s2++;
        if (x==3) s3++;
        }

        //Используем полученный результат
        MHL_ShowNumber(x,"Случайное целое число из интервала [0;3)","x");
        MHL_ShowNumber(s0,"Число выпадений 0","s0");
        MHL_ShowNumber(s1,"Число выпадений 1","s0");
        MHL_ShowNumber(s2,"Число выпадений 2","s0");
        MHL_ShowNumber(s3,"Число выпадений 3","s0");
        //Случайное целое число из интервала [0;3):
        //x=1
        //Число выпадений 0:
        //s0=324
        //Число выпадений 1:
        //s0=374
        //Число выпадений 2:
        //s0=302
        //Число выпадений 3:
        //s0=0
    }

    if (NameFunction=="MHL_RandomRealMatrixInCols")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];
        double *Left;
        Left=new double[VMHL_M];
        double *Right;
        Right=new double[VMHL_M];

        Left[0]=-5;//левая границы интервала изменения 1 столбца
        Right[0]=-4; //правая граница интервала изменения 1 столбца

        Left[1]=0;//левая границы интервала изменения 2 столбца
        Right[1]=3; //правая граница интервала изменения 2 столбца

        Left[2]=100;//левая границы интервала изменения 3 столбца
        Right[2]=200; //правая граница интервала изменения 3 столбца

        //Вызов функции
        MHL_RandomRealMatrixInCols(a,Left,Right,VMHL_N,VMHL_M);

        //Используем полученный результат
        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        //Случайная матрица:
        //a =
        //-4.20267	2.20367	148.468
        //-4.42432	2.09418	138.654
        //-4.07089	1.95831	140.198

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="MHL_RandomRealMatrixInElements")
    {
        int i,j;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];
        double **Left;
        Left=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Left[i]=new double[VMHL_M];
        double **Right;
        Right=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) Right[i]=new double[VMHL_M];

        //Возьмем для примера границы интервала равными около номера ячейки в матрице
        for (i=0;i<VMHL_N;i++)
         for (j=0;j<VMHL_M;j++)
          {
          Left[i][j]=i*VMHL_N+j-0.1;
          Right[i][j]=Left[i][j]+0.2;
          }

        //Вызов функции
        MHL_RandomRealMatrixInElements(a,Left,Right,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (Left,VMHL_N,VMHL_M,"Матрица левых границ", "Left");
        // Матрица левых границ:
        //Left =
        //-0.1	0.9	1.9
        //2.9	3.9	4.9
        //5.9	6.9	7.9

        MHL_ShowMatrix (Right,VMHL_N,VMHL_M,"Матрица правых границ", "Right");
        // Матрица правых границ:
        //Right =
        //0.1	1.1	2.1
        //3.1	4.1	5.1
        //6.1	7.1	8.1

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //0.0829529	1.04504	1.9892
        //2.90126	3.92388	4.90221
        //5.96102	6.90623	8.09661

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        for (i=0;i<VMHL_N;i++) delete [] Left[i];
        delete [] Left;
        for (i=0;i<VMHL_N;i++) delete [] Right[i];
        delete [] Right;
    }

    if (NameFunction=="MHL_RandomRealMatrixInRows")
    {
        int i;
        int VMHL_N=3;//Размер массива (число строк)
        int VMHL_M=3;//Размер массива (число столбцов)
        double **a;
        a=new double*[VMHL_N];
        for (i=0;i<VMHL_N;i++) a[i]=new double[VMHL_M];
        double *Left;
        Left=new double[VMHL_N];
        double *Right;
        Right=new double[VMHL_N];

        Left[0]=-5;//левая границы интервала изменения 1 строки
        Right[0]=-4; //правая граница интервала изменения 1 строки

        Left[1]=0;//левая границы интервала изменения 2 строки
        Right[1]=3; //правая граница интервала изменения 2 строки

        Left[2]=100;//левая границы интервала изменения 3 строки
        Right[2]=200; //правая граница интервала изменения 3 строки

        //Вызов функции
        MHL_RandomRealMatrixInRows(a,Left,Right,VMHL_N,VMHL_M);

        //Используем полученный результат

        MHL_ShowMatrix (a,VMHL_N,VMHL_M,"Случайная матрица", "a");
        // Случайная матрица:
        //a =
        //-4.98376	-4.64868	-4.38959
        //1.14386	2.70071	2.76151
        //141.309	192.12	100.122

        for (i=0;i<VMHL_N;i++) delete [] a[i];
        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="MHL_RandomRealVector")
    {
        int VMHL_N=10;//Размер массива
        double *a;
        a=new double[VMHL_N];

        double Left=-3;
        double Right=3;

        //Вызов функции
        MHL_RandomRealVector(a,Left,Right,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Массив", "a");
        //a =
        //1.73822
        //-0.406311
        //-2.7572
        //-0.351013
        //0.367493
        //1.40991
        //0.662476
        //-1.15576
        //-1.75781
        //-2.06927

        delete [] a;
    }

    if (NameFunction=="MHL_RandomRealVectorInElements")
    {
        int VMHL_N=2;//Размер массива
        double *a;
        a=new double[VMHL_N];

        double *Left;
        Left=new double[VMHL_N];
        Left[0]=-3;//Левая граница изменения первого элемента массива
        Left[1]=5;//Левая граница изменения второго элемента массива

        double *Right;
        Right=new double[VMHL_N];
        Right[0]=3;//Правая граница изменения первого элемента массива
        Right[1]=10;//Правая граница изменения второго элемента массива

        //Вызов функции
        MHL_RandomRealVectorInElements(a,Left,Right,VMHL_N);

        //Используем полученный результат

        MHL_ShowVector (Left,VMHL_N,"Массив левых границ", "Left");
        // Массив левых границ:
        //Left =
        //-3
        //5

        MHL_ShowVector (Right,VMHL_N,"Массив правых границ", "Right");
        // Массив правых границ:
        //Right =
        //3
        //10

        MHL_ShowVector (a,VMHL_N,"Случайных массив", "a");
        // Случайных массив:
        //a =
        //1.32111
        //6.5625

        delete [] a;
        delete [] Left;
        delete [] Right;
    }

    if (NameFunction=="MHL_RandomVectorOfProbability")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];

        //Заполним вектор случайными значениями вероятностей
        //Вызов функции
        MHL_RandomVectorOfProbability(a, VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор вероятностей выбора", "a");
        // Вектор вероятностей выбора:
        //a =
        //0.0662721
        //0.0681826
        //0.083972
        //0.0554142
        //0.18878
        //0.160006
        //0.0698625
        //0.0652843
        //0.127822
        //0.114404

        MHL_ShowNumber (TMHL_SumVector(a,VMHL_N),"Его сумма", "Sum");
        // Его сумма:
        //Sum=1
    }

    if (NameFunction=="MHL_Cos")
    {
        double y;
        double Angle=MHL_PI;//Угол в радинах

        //Вызов функции
        y=MHL_Cos(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Косинус угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Косинус угла 3.14159 радианов:
        //равен=-1
    }

    if (NameFunction=="MHL_CosDeg")
    {
        double y;
        double Angle=180;//Угол в градусах

        //Вызов функции
        y=MHL_CosDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Косинус угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Косинус угла 180 градусов:
        //равен=-1
    }

    if (NameFunction=="MHL_Cosec")
    {
        double y;
        double Angle=MHL_PI/4.;//Угол в радинах

        //Вызов функции
        y=MHL_Cosec(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Косеканс угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Косеканс угла 0.785398 радианов:
        //равен=1.41421
    }

    if (NameFunction=="MHL_CosecDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=MHL_CosecDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Косеканс угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Косеканс угла 45 градусов:
        //равен=1.41421
    }

    if (NameFunction=="MHL_Cotan")
    {
        double y;
        double Angle=MHL_PI/4.;//Угол в радинах

        //Вызов функции
        y=MHL_Cotan(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Котангенс угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Котангенс угла 0.785398 радианов:
        //равен=1
    }

    if (NameFunction=="MHL_CotanDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=MHL_CotanDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Котангенс угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Котангенс угла 45 градусов:
        //равен=1
    }

    if (NameFunction=="MHL_Sec")
    {
        double y;
        double Angle=MHL_PI/4.;//Угол в радинах

        //Вызов функции
        y=MHL_Sec(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Секанс угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Секанс угла 0.785398 радианов:
        //равен=1.41421
    }

    if (NameFunction=="MHL_SecDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=MHL_SecDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Секанс угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Секанс угла 45 градусов:
        //равен=1.41421
    }

    if (NameFunction=="MHL_Sin")
    {
        double y;
        double Angle=MHL_PI/2.;//Угол в радинах

        //Вызов функции
        y=MHL_Sin(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Синус угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Синус угла 1.5708 радианов:
        //равен=1
    }

    if (NameFunction=="MHL_SinDeg")
    {
        double y;
        double Angle=90;//Угол в градусах

        //Вызов функции
        y=MHL_SinDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Синус угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Синус угла 90 градусов:
        //равен=1
    }

    if (NameFunction=="MHL_Tan")
    {
        double y;
        double Angle=MHL_PI/4.;//Угол в радинах

        //Вызов функции
        y=MHL_Tan(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Тангенс угла "+MHL_NumberToText(Angle)+" радианов","равен");
        //Тангенс угла 0.785398 радианов:
        //равен=1
    }

    if (NameFunction=="MHL_TanDeg")
    {
        double y;
        double Angle=45;//Угол в градусах

        //Вызов функции
        y=MHL_TanDeg(Angle);

        //Используем полученный результат
        MHL_ShowNumber(y,"Тангенс угла "+MHL_NumberToText(Angle)+" градусов","равен");
        //Тангенс угла 45 градусов:
        //равен=1
    }

    if (NameFunction=="TMHL_OrdinalVector")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];

        //Вызов функции
        TMHL_OrdinalVector(a,VMHL_N);
        //Вектор:
        //a =
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9
        //10

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");

        delete [] a;
    }

    if (NameFunction=="TMHL_OrdinalVectorZero")
    {
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];

        //Вызов функции
        TMHL_OrdinalVectorZero(a,VMHL_N);
        //Вектор:
        //a =
        //0
        //1
        //2
        //3
        //4
        //5
        //6
        //7
        //8
        //9

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");

        delete [] a;
    }

    if (NameFunction=="TMHL_SearchFirstNotZero")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(0,2);

        //Вызов функции
        int Number=TMHL_SearchFirstNotZero(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //0
        //0
        //0
        //1
        //0
        //0
        //0
        //1
        //1
        //0

        MHL_ShowNumber (Number,"Номер первого ненулевого элемента", "Number");
        //Номер первого ненулевого элемента:
        //Number=3

        delete [] a;
    }

    if (NameFunction=="TMHL_SearchFirstZero")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(0,2);

        //Вызов функции
        int Number=TMHL_SearchFirstZero(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //1
        //1
        //1
        //0
        //0
        //1
        //0
        //0
        //0
        //1

        MHL_ShowNumber (Number,"Номер первого нулевого элемента", "Number");
        //Номер первого нулевого элемента:
        //Number=3

        delete [] a;
    }

    if (NameFunction=="TMHL_VectorMinusVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        int *b;
        b=new int[VMHL_N];
        int *c;
        c=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(0,10);
        for (i=0;i<VMHL_N;i++)
         b[i]=MHL_RandomUniformInt(0,10);

        //Вызов функции
        TMHL_VectorMinusVector(a,b,c,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //0	7	0	0	8	5	0	4	8	2

        MHL_ShowVectorT (b,VMHL_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //6	1	3	1	2	7	2	6	1	4

        MHL_ShowVectorT (c,VMHL_N,"Их разница", "c");
        //Их разница:
        //c =
        //-6	6	-3	-1	6	-2	-2	-2	7	-2

        delete [] a;
        delete [] b;
        delete [] c;

        //Для  переопределенной функции
        VMHL_N=10;//Размер массива (число строк)
        a=new int[VMHL_N];
        b=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(0,10);
        for (i=0;i<VMHL_N;i++)
         b[i]=MHL_RandomUniformInt(0,10);

        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //6	9	3	0	2	9	4	2	3	7

        //Вызов функции
        TMHL_VectorMinusVector(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (b,VMHL_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //5	6	3	8	5	0	7	6	4	4

        MHL_ShowVectorT (a,VMHL_N,"Из первого вычли второй", "a");
        //Из первого вычли второй:
        //a =
        //1	3	0	-8	-3	9	-3	-4	-1	3

        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_VectorPlusVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        int *b;
        b=new int[VMHL_N];
        int *c;
        c=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(0,10);
        for (i=0;i<VMHL_N;i++)
         b[i]=MHL_RandomUniformInt(0,10);

        //Вызов функции
        TMHL_VectorPlusVector(a,b,c,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //2	7	9	2	3	3	3	2	8	8


        MHL_ShowVectorT (b,VMHL_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //3	7	2	9	5	3	2	7	2	7

        MHL_ShowVectorT (c,VMHL_N,"Их сумма", "c");
        //Их сумма:
        //c =
        //5	14	11	11	8	6	5	9	10	15

        delete [] a;
        delete [] b;
        delete [] c;

        //Для  переопределенной функции
        VMHL_N=10;//Размер массива (число строк)
        a=new int[VMHL_N];
        b=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(0,10);
        for (i=0;i<VMHL_N;i++)
         b[i]=MHL_RandomUniformInt(0,10);

        MHL_ShowVectorT (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //0	6	7	4	9	3	9	8	5	6

        //Вызов функции
        TMHL_VectorPlusVector(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVectorT (b,VMHL_N,"Случайный вектор", "b");
        //Случайный вектор:
        //b =
        //1	7	0	5	4	0	9	5	7	7

        MHL_ShowVectorT (a,VMHL_N,"К первому прибавили второй", "a");
        //К первому прибавили второй:
        //a =
        //1	13	7	9	13	3	18	13	12	13

        delete [] a;
        delete [] b;

    }

    if (NameFunction=="TMHL_VectorMultiplyNumber")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        double *a;
        a=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(0,10);

        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //4
        //6
        //3
        //5
        //4
        //7
        //8
        //2
        //1
        //0

        double Number=MHL_RandomUniform(0,10);

        //Вызов функции
        TMHL_VectorMultiplyNumber(a,VMHL_N,Number);

        //Используем полученный результат
        MHL_ShowNumber (Number,"Случайный множитель", "Number");
        //Случайный множитель:
        //Number=3.57941

        MHL_ShowVector (a,VMHL_N,"Умножили на число Number", "a");
        //Умножили на число Number:
        //a =
        //14.3176
        //21.4764
        //10.7382
        //17.897
        //14.3176
        //25.0558
        //28.6353
        //7.15881
        //3.57941
        //0

        delete [] a;
    }

    if (NameFunction=="MHL_Cosech")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Cosech(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический косеканс от x="+MHL_NumberToText(x),"равен");
        //Гиперболический косеканс от x=0.571289:
        //равен=1.65872
    }

    if (NameFunction=="MHL_Cosh")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Cosh(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический косинус от x="+MHL_NumberToText(x),"равен");
        //Гиперболический косинус от x=4.04968:
        //равен=28.6983
    }

    if (NameFunction=="MHL_Cotanh")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Cotanh(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический котангенс от x="+MHL_NumberToText(x),"равен");
        //Гиперболический котангенс от x=1.92505:
        //равен=1.04348
    }

    if (NameFunction=="MHL_Sech")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Sech(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический секанс от x="+MHL_NumberToText(x),"равен");
        //Гиперболический секанс от x=0.679932:
        //равен=0.806323
    }

    if (NameFunction=="MHL_Sinh")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Sinh(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический синус от x="+MHL_NumberToText(x),"равен");
        //Гиперболический синус от x=0.166321:
        //равен=0.167089
    }

    if (NameFunction=="MHL_Tanh")
    {
        double x=MHL_RandomUniform(0,10);

        //Вызов функции
        double Result=MHL_Tanh(x);

        //Используем полученный результат
        MHL_ShowNumber(Result,"Гиперболический тангенс от x="+MHL_NumberToText(x),"равен");
        //Гиперболический тангенс от x=4.27643:
        //равен=0.999614
    }

    if (NameFunction=="TMHL_NumberOfMaximumOfVector")
    {
        int i;
        int VMHL_N=10;//Размер массива
        double *Vector=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++) Vector[i]=MHL_RandomNumber();

        //Вызов функции
        double Number=TMHL_NumberOfMaximumOfVector(Vector,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (Vector,VMHL_N,"Случайный массив", "Vector");
        //Случайный массив:
        //Vector =
        //0.9245
        //0.221466
        //0.301544
        //0.643951
        //0.881958
        //0.832764
        //0.104462
        //0.0611267
        //0.943604
        //0.335205

        MHL_ShowNumber(Number,"Номер максимального элемента","Number");//Например, выводим результат
        // Номер максимального элемента:
        //Number=8
        delete [] Vector;
    }

    if (NameFunction=="TMHL_NumberOfMinimumOfVector")
    {
        int i;
        int VMHL_N=10;//Размер массива
        double *Vector=new double[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++) Vector[i]=MHL_RandomNumber();

        //Вызов функции
        double Number=TMHL_NumberOfMinimumOfVector(Vector,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (Vector,VMHL_N,"Случайный массив", "Vector");
        //Случайный массив:
        //Vector =
        //0.958344
        //0.0968323
        //0.689697
        //0.102264
        //0.142242
        //0.135925
        //0.473816
        //0.0245056
        //0.616333
        //0.798065

        MHL_ShowNumber(Number,"Номер минимального элемента","Number");//Например, выводим результат
        //Номер минимального элемента:
        //Number=7
        delete [] Vector;
    }

    if (NameFunction=="TMHL_NumberOfNegativeValues")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(-20,20);

        //Вызов функции
        int NumberOfNegative=TMHL_NumberOfNegativeValues(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //12
        //19
        //-11
        //-20
        //13
        //4
        //-6
        //-1
        //1
        //-8

        MHL_ShowNumber (NumberOfNegative,"Число отрицательных значений в векторе", "NumberOfNegative");
        //Число отрицательных значений в векторе:
        //NumberOfNegative=5

        delete [] a;
    }

    if (NameFunction=="TMHL_NumberOfPositiveValues")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(-20,20);

        //Вызов функции
        int NumberOfNegative=TMHL_NumberOfPositiveValues(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //6
        //14
        //14
        //13
        //-19
        //-18
        //11
        //-18
        //-20
        //5

        MHL_ShowNumber (NumberOfNegative,"Число положительных значений в векторе", "NumberOfNegative");
        //Число положительных значений в векторе:
        //NumberOfNegative=6

        delete [] a;
    }

    if (NameFunction=="TMHL_NumberOfZeroValues")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(-2,2);

        //Вызов функции
        int NumberOfNegative=TMHL_NumberOfZeroValues(a,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Случайный вектор", "a");
        //Случайный вектор:
        //a =
        //1
        //1
        //0
        //0
        //0
        //-1
        //1
        //1
        //0
        //1

        MHL_ShowNumber (NumberOfNegative,"Число нулевых значений в векторе", "NumberOfNegative");
        //Число нулевых значений в векторе:
        //NumberOfNegative=4

        delete [] a;
    }

    if (NameFunction=="TMHL_FibonacciNumbersVector")
    {
        int VMHL_N=MHL_RandomUniformInt(5,15);//Размер массива
        double *x;
        x=new double[VMHL_N];

        //Вызов функции
        TMHL_FibonacciNumbersVector(x,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (x,VMHL_N,"Вектор, заполненый числами Фибоначи", "x");
        //Вектор, заполненый числами Фибоначи:
        //x =
        //1
        //1
        //2
        //3
        //5
        //8
        //13
        //21
        //34
        //55
        //89
        //144

        delete [] x;
    }

    if (NameFunction=="TMHL_EqualityOfVectors")
    {
        int VMHL_N=5;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        int *b;
        b=new int[VMHL_N];

        int x=MHL_RandomUniformInt(0,2);//заполнитель для вектора a
        int y=MHL_RandomUniformInt(0,2);//заполнитель для вектора b
        TMHL_FillVector (a, VMHL_N, x);
        TMHL_FillVector (b, VMHL_N, y);


        //Вызов функции
        int Q=TMHL_EqualityOfVectors(a,b,VMHL_N);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");
        //Вектор:
        //a =
        //1
        //1
        //1
        //1
        //1

        MHL_ShowVector (b,VMHL_N,"Вектор", "b");
        //Вектор:
        //b =
        //0
        //0
        //0
        //0
        //0

        MHL_ShowNumber (Q,"Равны ли вектора", "Q");
        // Равны ли вектора:
        //Q=0


        delete [] a;
        delete [] b;
    }

    if (NameFunction=="TMHL_CheckElementInVector")
    {
        int i;
        int VMHL_N=10;//Размер массива (число строк)
        int *a;
        a=new int[VMHL_N];
        //Заполним случайными числами
        for (i=0;i<VMHL_N;i++)
         a[i]=MHL_RandomUniformInt(0,5);
        int k=MHL_RandomUniformInt(0,5);//искомое число

        //Вызов функции
        int Search=TMHL_CheckElementInVector(a,VMHL_N,k);

        //Используем полученный результат
        MHL_ShowVector (a,VMHL_N,"Вектор", "a");
        //Вектор:
        //a =
        //2
        //1
        //2
        //1
        //0
        //1
        //0
        //3
        //0
        //0

        MHL_ShowNumber (k,"Искомое число", "k");
        //Искомое число:
        //k=3

        MHL_ShowNumber (Search,"находится в векторе a под номером", "Search");
        //находится в векторе a под номером:
        //Search=7
        delete [] a;
    }

    //Показ итогового результата
    Html+="</body></html>";
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
}
//---------------------------------------------------------------------------
