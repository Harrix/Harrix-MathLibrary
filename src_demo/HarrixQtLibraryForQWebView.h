#ifndef HARRIXQTLIBRARYFORQWEBVIEW_H
#define HARRIXQTLIBRARYFORQWEBVIEW_H

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

#include "HarrixQtLibrary.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Главные загрузочные функции
void HQt_AddHtml(QString Html);
void HQt_BeginHtml(QString Path);

//Показ графиков
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double));
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine);
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine);
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N);
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M);
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine);
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M);
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N);
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2);
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints);
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2);
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2);

//Показ математических выражений
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString TitleMatrix, QString NameMatrix);
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString NameMatrix);
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M);
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString TitleMatrix, QString NameMatrix);
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString NameMatrix);
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N);
template <class T> QString THQt_ShowNumber (T VHQt_X, QString TitleX, QString NameX);
template <class T> QString THQt_ShowNumber (T VHQt_X, QString NameX);
template <class T> QString THQt_ShowNumber (T VHQt_X);
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector);
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N, QString NameVector);
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N);
QString THQt_ShowVector (QStringList VHQt_Vector, QString TitleVector, QString NameVector);
QString THQt_ShowVector (QStringList VHQt_Vector, QString NameVector);
QString THQt_ShowVector (QStringList VHQt_Vector);
template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector);
template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N, QString NameVector);
template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N);

//Показ текста
QString HQt_ShowAlert (QString String);
QString HQt_ShowH1 (QString String);
QString HQt_ShowHr ();
QString HQt_ShowSimpleText (QString String);
QString HQt_ShowText (QString TitleX);
template <class T> QString THQt_NumberToText (T VHQt_X);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// РЕАЛИЗАЦИЯ ШАБЛОНОВ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//*****************************************************************
//Главные загрузочные функции
//*****************************************************************
//*****************************************************************
//Показ графиков
//*****************************************************************
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - название первого графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y","линия",true,true,true,true,false);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString Color="#97bbcd";
    QString HighlightColor="#3c7693";
    QString CoordinateColor="#88969c";
    QString RedColor="#ff0000";
    QString HighlightRedColor="#8b0909";

    //посчитаем гарницы изменения параметров
    T MinX=VHQt_VectorX[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorX[i]<MinX)
            MinX=VHQt_VectorX[i];

    T MinY=VHQt_VectorY[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY[i]<MinY)
            MinY=VHQt_VectorY[i];

    T MaxX=VHQt_VectorX[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorX[i]>MaxX)
            MaxX=VHQt_VectorX[i];

    T MaxY=VHQt_VectorY[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY[i]>MaxY)
            MaxY=VHQt_VectorY[i];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;

    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;

    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VHQt_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VHQt_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    //QString UniqueName=HQt_UniqueNameOnlyNumbers();
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX="DataX"+UniqueName;
    QString NameDataY="DataY"+UniqueName;
    QString NameDataXArea="DataXArea"+UniqueName;
    QString NameDataYArea="DataYArea"+UniqueName;
    QString NameChart="Chart"+UniqueName;


    //рисуем область графика и оси
    VHQt_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VHQt_Result+="<script type=\"text/javascript\">\n";
    VHQt_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VHQt_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VHQt_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VHQt_VectorX=new T[VHQt_N];
    T *Temp_VHQt_VectorY=new T[VHQt_N];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorX[i]=VHQt_VectorX[i];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorY[i]=VHQt_VectorY[i];

    //отсортируем массивы
    for(i=VHQt_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX[j]>Temp_VHQt_VectorX[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX[j+1];
                Temp_VHQt_VectorX[j+1]=Temp_VHQt_VectorX[j];
                Temp_VHQt_VectorX[j]=x;
                x=Temp_VHQt_VectorY[j+1];
                Temp_VHQt_VectorY[j+1]=Temp_VHQt_VectorY[j];
                Temp_VHQt_VectorY[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX;
    QString SDataY;
    for (i=0;i<VHQt_N-1;i++)
        SDataX+=QString::number(Temp_VHQt_VectorX[i])+", ";
    SDataX+=QString::number(Temp_VHQt_VectorX[VHQt_N-1]);
    for (i=0;i<VHQt_N-1;i++)
        SDataY+=QString::number(Temp_VHQt_VectorY[i])+", ";
    SDataY+=QString::number(Temp_VHQt_VectorY[VHQt_N-1]);

    //запишем массивы точек
    VHQt_Result+="var "+NameDataX+" = ["+SDataX+"];\n";
    VHQt_Result+="var "+NameDataY+" = ["+SDataY+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);
        SDataY=SBeginYAxis+", "+SDataY+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VHQt_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        VHQt_Result+="var "+NameDataYArea+" = ["+SDataY+"];\n";
        if (!RedLine)
            VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
        else
            VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea+"],{strokeColor:'"+RedColor+"',highlightStrokeColor:'"+RedColor+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+RedColor+"',highlightFillColor:'"+RedColor+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        VHQt_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line,point'});\n";
        if (!RedLine)
            VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        else
            VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
        VHQt_Result+="    {\n";
        if (!RedLine)
            VHQt_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        else
            VHQt_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";

        VHQt_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем график
        VHQt_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
        VHQt_Result+="    {\n";
        if (!RedLine)
            VHQt_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        else
            VHQt_Result+="    "+NameChart+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
        VHQt_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        VHQt_Result+="var "+NameChart+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY+"], {chartStyle:'line'});\n";
        if (!RedLine)
            VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        else
            VHQt_Result+=NameChart+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VHQt_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VHQt_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataYLegend="DataYLegend"+UniqueNameLegend;
        QString NameChartLegend="ChartLegend"+UniqueNameLegend;
        QString NameTextLegend="TextLegend"+UniqueName;

        //рисуем область графика и оси
        VHQt_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:50px;\"></div>\n";
        VHQt_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="2";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VHQt_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        SDataX="1, 2";
        SDataY="1, 1";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY="1, 1, 1";
        }

        //запишем массивы точек
        VHQt_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VHQt_Result+="var "+NameDataYLegend+" = ["+SDataY+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            VHQt_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line,point'});\n";
            if (!RedLine)
                VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            else
                VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VHQt_Result+="    {\n";
            if (!RedLine)
                VHQt_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            else
                VHQt_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
            VHQt_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            VHQt_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VHQt_Result+="    {\n";
            if (!RedLine)
                VHQt_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            else
                VHQt_Result+="    "+NameChartLegend+"[1][i].setProperty({strokeColor:'"+RedColor+"',highlightStrokeColor:'"+HighlightRedColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'1pt'});\n";
            VHQt_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            VHQt_Result+="var "+NameChartLegend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend+"], {chartStyle:'line'});\n";
            if (!RedLine)
                VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            else
                VHQt_Result+=NameChartLegend+"[0].setProperty('strokeColor:"+RedColor+"','highlightStrokeColor:"+HighlightRedColor+"','strokeWidth:1');\n";
        }

        //напишем текст
        VHQt_Result+=NameTextLegend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VHQt_Result+="</script>\n";
    }

    delete [] Temp_VHQt_VectorX;
    delete [] Temp_VHQt_VectorY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием параметра NameLine(название первого графика (для легенды)).
    То есть не будет легенды у графика.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синию.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y",true,true,true,true);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VHQt_VectorX,VHQt_VectorY,VHQt_N,TitleChart,NameVectorX, NameVectorY, "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - название первого графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N,"Тестовый график","x","y","линия");

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VHQt_VectorX,VHQt_VectorY,VHQt_N,TitleChart,NameVectorX, NameVectorY, NameLine, true, true, true, true, false);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartOfLine (T *VHQt_VectorX,T *VHQt_VectorY, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого графика по точкам с HTML кодами. Для добавление в html файл.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY - указатель на вектор координат Y точек;
     VHQt_N - количество точек.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY=new double [N];
    dataX[0]=7;dataY[0]=6;
    dataX[1]=8;dataY[1]=4;
    dataX[2]=10;dataY[2]=7;
    dataX[3]=5;dataY[3]=12;
    dataX[4]=14;dataY[4]=4;
    dataX[5]=13;dataY[5]=8;

    Html += THQt_ShowChartOfLine (dataX,dataY,N);

    delete []dataX;
    delete []dataY;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowChartOfLine (VHQt_VectorX,VHQt_VectorY,VHQt_N,"","x", "y", "", true, true, true, true, false);
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Y графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    int M=2;
    double **data;
    data=new double*[N];
    for (int i=0;i<N;i++) X[i]=new double[M];
    data[0][0]=7;data[0][1]=6;
    data[1][0]=8;data[1][1]=4;
    data[2][0]=10;data[2][1]=7;
    data[3][0]=5;data[3][1]=12;
    data[4][0]=14;data[4][1]=4;
    data[5][0]=13;data[5][1]=8;

    QString *NameLine=new QString[M-1];
    NameLine[0]="Первая линия";

    Html += THQt_ShowChartsOfLineFromMatrix (data,N,M, "График", "x", "y",NameLine,true,true,true,true);

    for (int i=0;i<N;i++) delete [] data[i];
    delete [] data;
    delete [] NameLine;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString CoordinateColor="#88969c";
    QString HighlightCoordinateColor="#3c7693";

    QString *Color=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) Color[j]="#97bbcd";

    QString *HighlightColor=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) HighlightColor[j]="#3c7693";

    QString *ColorArea=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) ColorArea[j]="#97bbcd";

    QString *OpacityArea=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) OpacityArea[j]="0.5";

    QString *StrokeWidth=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) StrokeWidth[j]="2";

    QString *StrokeWidthPoints=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) StrokeWidthPoints[j]="2";

    QString *FaceOfLine=new QString [VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) FaceOfLine[j]="o";

    if (VHQt_M-1==2)//если два графика
    {
        Color[1]="#cccccc";
        HighlightColor[1]="#7e7e7e";
        ColorArea[1]="#cccccc";
    }
    if ((VHQt_M-1==3)&&(ShowArea))//если три графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";
        ColorArea[1]="#97bbcd";
        OpacityArea[1]="0.5";

        Color[2]="#cccccc";
        HighlightColor[2]="#7e7e7e";
        ColorArea[2]="#cccccc";
        OpacityArea[2]="0.5";
    }
    if ((VHQt_M-1==3)&&(!ShowArea))//если три графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e06c65";
        HighlightColor[2]="#9d2b24";
    }
    if ((VHQt_M-1==4)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#cccccc";
        HighlightColor[3]="#7e7e7e";
        ColorArea[3]="#cccccc";
        OpacityArea[3]="0.5";
    }
    if ((VHQt_M-1==4)&&(!ShowArea))//если 4 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";
    }
    if ((VHQt_M-1==5)&&(ShowArea))//если 5 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#cccccc";
        HighlightColor[4]="#7e7e7e";
        ColorArea[4]="#cccccc";
        OpacityArea[4]="0.5";
    }
    if ((VHQt_M-1==5)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";

        Color[4]="#9d50c8";
        HighlightColor[4]="#6a2b8d";
    }
    if ((VHQt_M-1==6)&&(ShowArea))//если 6 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#bec7cd";
        HighlightColor[4]="#5c7483";
        ColorArea[4]="#bec7cd";
        OpacityArea[4]="0.5";

        Color[5]="#cccccc";
        HighlightColor[5]="#7e7e7e";
        ColorArea[5]="#cccccc";
        OpacityArea[5]="0.5";
    }
    if ((VHQt_M-1==6)&&(!ShowArea))//если 6 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#b5d24e";
        HighlightColor[2]="#8ca72c";

        Color[3]="#e7cc4c";
        HighlightColor[3]="#b49c28";

        Color[4]="#e06c65";
        HighlightColor[4]="#9d2b24";

        Color[5]="#9d50c8";
        HighlightColor[5]="#6a2b8d";
    }
    if ((VHQt_M-1==7)&&(ShowArea))//если 7 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#97bbcd";
        HighlightColor[3]="#3c7693";
        ColorArea[3]="#97bbcd";
        OpacityArea[3]="0.5";

        Color[4]="#adc2cd";
        HighlightColor[4]="#58839a";
        ColorArea[4]="#adc2cd";
        OpacityArea[4]="0.5";

        Color[5]="#bec7cd";
        HighlightColor[5]="#5c7483";
        ColorArea[5]="#bec7cd";
        OpacityArea[5]="0.5";

        Color[6]="#cccccc";
        HighlightColor[6]="#7e7e7e";
        ColorArea[6]="#cccccc";
        OpacityArea[6]="0.5";
    }
    if ((VHQt_M-1==7)&&(!ShowArea))//если 7 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";
    }
    if ((VHQt_M-1==8)&&(ShowArea))//если 8 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#bec7cd";
        HighlightColor[6]="#5c7483";
        ColorArea[6]="#bec7cd";
        OpacityArea[6]="0.5";

        Color[7]="#cccccc";
        HighlightColor[7]="#7e7e7e";
        ColorArea[7]="#cccccc";
        OpacityArea[7]="0.5";
    }
    if ((VHQt_M-1==8)&&(!ShowArea))//если 8 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";

        Color[7]="#c64f8f";
        HighlightColor[7]="#8d275e";
    }
    if ((VHQt_M-1==9)&&(ShowArea))//если 9 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#b6c5cd";
        HighlightColor[6]="#617580";
        ColorArea[6]="#b6c5cd";
        OpacityArea[6]="0.5";

        Color[7]="#bec7cd";
        HighlightColor[7]="#5c7483";
        ColorArea[7]="#bec7cd";
        OpacityArea[7]="0.5";

        Color[8]="#cccccc";
        HighlightColor[8]="#7e7e7e";
        ColorArea[8]="#cccccc";
        OpacityArea[8]="0.5";
    }
    if ((VHQt_M-1==9)&&(!ShowArea))//если 9 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e9ac4c";
        HighlightColor[5]="#946b2c";

        Color[6]="#e06c65";
        HighlightColor[6]="#9d2b24";

        Color[7]="#9d50c8";
        HighlightColor[7]="#6a2b8d";

        Color[8]="#c64f8f";
        HighlightColor[8]="#8d275e";
    }
	if ((VHQt_M-1>9)&&(ShowArea))//если больше 9 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VHQt_M-1;j++)
        {
            position=j/double(VHQt_M-1);
            Color[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#537c90";
            HighlightColor[j]="#26576f";
            ColorArea[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#799bac";
            OpacityArea[j]="0.5";
        }
    }
	if ((VHQt_M-1>9)&&(!ShowArea))//если больше 9 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VHQt_M-1;j++)
        {
            position=j/double(VHQt_M-1);
            Color[j]=THQt_AlphaBlendingColorToColor(0.4,THQt_GiveRainbowColorRGB(position),"#ffffff");
            HighlightColor[j]="#26576f";
        }
    }
    //по точкам пройдемся
    if (VHQt_M-1>=3)
    {
        FaceOfLine[1]="[]";
        StrokeWidthPoints[1]="2";

        FaceOfLine[2]="<>";
        StrokeWidthPoints[2]="3";
    }
    if (VHQt_M-1>=4)
    {
        FaceOfLine[3]="x";
        StrokeWidthPoints[3]="3";
    }
    if (VHQt_M-1>=5)
    {
        FaceOfLine[4]="+";
        StrokeWidthPoints[4]="3";
    }
    if (VHQt_M-1>=6)
    {
        FaceOfLine[5]="^";
        StrokeWidthPoints[5]="3";
    }
    if (VHQt_M-1>=7)
    {
        FaceOfLine[6]="v";
        StrokeWidthPoints[6]="3";
    }
    if (VHQt_M-1>=8)
    {
        FaceOfLine[7]=">";
        StrokeWidthPoints[7]="3";
    }
    if (VHQt_M-1>=9)
    {
        FaceOfLine[8]="<";
        StrokeWidthPoints[8]="3";
    }
    //когда уменьшать толщину линии
    if (VHQt_M-1>5)
        for (j=0;j<VHQt_M-1;j++)
        {
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]=QString::number((StrokeWidthPoints[j].toInt())-1);
        }
    if (VHQt_M-1>9)//слишком много кривых
    {
        for (j=0;j<VHQt_M-1;j++)
        {
            FaceOfLine[j]="o";
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]="1";
        }
    }

    //посчитаем гарницы изменения параметров
    T MinX=VHQt_MatrixXY[0][0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_MatrixXY[i][0]<MinX)
            MinX=VHQt_MatrixXY[i][0];

    T MaxX=VHQt_MatrixXY[0][0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_MatrixXY[i][0]>MaxX)
            MaxX=VHQt_MatrixXY[i][0];

    T MinY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M-1;j++)
        for (int i=0;i<VHQt_N;i++)
            if (VHQt_MatrixXY[i][j+1]<MinY)
                MinY=VHQt_MatrixXY[i][j+1];

    T MaxY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M-1;j++)
        for (int i=0;i<VHQt_N;i++)
            if (VHQt_MatrixXY[i][j+1]>MaxY)
                MaxY=VHQt_MatrixXY[i][j+1];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VHQt_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VHQt_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX="DataX"+UniqueName;
    QString NameDataXArea="DataX1Area"+UniqueName;

    QString *NameDataY=new QString[VHQt_M-1];
    QString *NameDataYArea=new QString[VHQt_M-1];
    QString *NameChart=new QString[VHQt_M-1];
    for (j=0;j<VHQt_M-1;j++) NameDataY[j]="DataY"+QString::number(j+1)+UniqueName;
    for (j=0;j<VHQt_M-1;j++) NameDataYArea[j]="DataY"+QString::number(j+1)+"Area"+UniqueName;
    for (j=0;j<VHQt_M-1;j++) NameChart[j]="Chart"+QString::number(j+1)+UniqueName;

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VHQt_MatrixXY;
    Temp_VHQt_MatrixXY=new double*[VHQt_N];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_MatrixXY[i]=new double[VHQt_M];
    for (i=0;i<VHQt_N;i++)
        for (j=0;j<VHQt_M;j++)
            Temp_VHQt_MatrixXY[i][j]=VHQt_MatrixXY[i][j];

    //отсортируем массивы
    for(i=VHQt_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_MatrixXY[j][0]>Temp_VHQt_MatrixXY[j+1][0])
            {
                for (k=0;k<VHQt_M;k++)
                {
                    T x;
                    x=Temp_VHQt_MatrixXY[j+1][k];
                    Temp_VHQt_MatrixXY[j+1][k]=Temp_VHQt_MatrixXY[j][k];
                    Temp_VHQt_MatrixXY[j][k]=x;
                }
            }

    //рисуем область графика и оси
    VHQt_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VHQt_Result+="<script type=\"text/javascript\">\n";
    VHQt_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VHQt_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VHQt_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";


    //соберем в массивы javascript данные точек
    QString SDataX;
    QString *SDataY = new QString[VHQt_M-1];

    for (i=0;i<VHQt_N-1;i++)
        SDataX+=QString::number(Temp_VHQt_MatrixXY[i][0])+", ";
    SDataX+=QString::number(Temp_VHQt_MatrixXY[VHQt_N-1][0]);

    for (j=0;j<VHQt_M-1;j++)
    {
        for (i=0;i<VHQt_N-1;i++)
            SDataY[j]+=QString::number(Temp_VHQt_MatrixXY[i][j+1])+", ";
        SDataY[j]+=QString::number(Temp_VHQt_MatrixXY[VHQt_N-1][j+1]);
    }

    //запишем массивы точек
    VHQt_Result+="var "+NameDataX+" = ["+SDataX+"];\n";
    for (j=0;j<VHQt_M-1;j++)
        VHQt_Result+="var "+NameDataY[j]+" = ["+SDataY[j]+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);

        for (j=0;j<VHQt_M-1;j++)
            SDataY[j]=SBeginYAxis+", "+SDataY[j]+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VHQt_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        for (j=0;j<VHQt_M-1;j++)
            VHQt_Result+="var "+NameDataYArea[j]+" = ["+SDataY[j]+"];\n";
        for (j=0;j<VHQt_M-1;j++)
            VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataYArea[VHQt_M-2-j]+"],{strokeColor:'"+ColorArea[VHQt_M-2-j]+"',highlightStrokeColor:'"+ColorArea[VHQt_M-2-j]+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+ColorArea[VHQt_M-2-j]+"',highlightFillColor:'"+ColorArea[VHQt_M-2-j]+"',fillOpacity:"+OpacityArea[VHQt_M-2-j]+",highlightFillOpacity:"+OpacityArea[VHQt_M-2-j]+"});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VHQt_M-1;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M-2-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY[VHQt_M-2-j]+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart[VHQt_M-2-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M-2-j]+"','strokeWidth:"+StrokeWidth[VHQt_M-2-j]+"');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart[VHQt_M-2-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M-2-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M-2-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M-2-j]+"', size:"+StrokeWidthPoints[VHQt_M-2-j]+", strokeWidth:'"+StrokeWidth[VHQt_M-2-j]+"pt'});\n";
            VHQt_Result+="    }\n";
        }
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки
        for (j=0;j<VHQt_M-1;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M-2-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY[VHQt_M-2-j]+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart[VHQt_M-2-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M-2-j]+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart[VHQt_M-2-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M-2-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M-2-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M-2-j]+"', size:"+StrokeWidthPoints[VHQt_M-2-j]+", strokeWidth:'"+StrokeWidth[VHQt_M-2-j]+"pt'});\n";
            VHQt_Result+="    }\n";
        }
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию
        for (j=0;j<VHQt_M-1;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M-2-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY[VHQt_M-2-j]+"], {chartStyle:'line'});\n";
            VHQt_Result+=NameChart[VHQt_M-2-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M-2-j]+"','strokeWidth:"+StrokeWidth[VHQt_M-2-j]+"');\n";
        }
    }

    if (ShowSpecPoints)
    {
        //Теперь поставим точки
        //Нулевая точка
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VHQt_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VHQt_Result+="</script>\n";

    // ЛЕГЕНДА
    int NameLineHowManyEmpty=0;
    for (j=0;j<VHQt_M-1;j++) if (NameLine[j].trimmed().isEmpty()!=true) NameLineHowManyEmpty++;

    if (NameLineHowManyEmpty!=0)
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;

        QString *NameDataYLegend= new QString[VHQt_M-1];
        QString *NameChartLegend= new QString[VHQt_M-1];
        QString *NameTextLegend= new QString[VHQt_M-1];

        for (j=0;j<VHQt_M-1;j++) NameDataYLegend[j]="DataY"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VHQt_M-1;j++) NameChartLegend[j]="Chart"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VHQt_M-1;j++) NameTextLegend[j]="Text"+QString::number(j+1)+"Legend"+UniqueNameLegend;


        //рисуем область графика и оси
        VHQt_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:"+QString::number(50*(VHQt_M-1))+"px;\"></div>\n";
        VHQt_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox=QString::number(VHQt_M);
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VHQt_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";

        for (j=0;j<VHQt_M-1;j++) SDataY[j]=QString::number(VHQt_M-1-j)+", "+QString::number(VHQt_M-1-j);

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            for (j=0;j<VHQt_M-1;j++) SDataY[j]=QString::number(VHQt_M-1-j)+", "+QString::number(VHQt_M-1-j)+", "+QString::number(VHQt_M-1-j);
        }

        //запишем массивы точек

        VHQt_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        for (j=0;j<VHQt_M-1;j++)
            VHQt_Result+="var "+NameDataYLegend[j]+" = ["+SDataY[j]+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            for (j=0;j<VHQt_M-1;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M-2-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M-2-j]+"], {chartStyle:'line,point'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M-2-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M-2-j]+"','strokeWidth:"+StrokeWidth[VHQt_M-2-j]+"');\n";
                VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
                VHQt_Result+="    {\n";
                VHQt_Result+="    "+NameChartLegend[VHQt_M-2-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M-2-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M-2-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M-2-j]+"', size:"+StrokeWidthPoints[VHQt_M-2-j]+", strokeWidth:'"+StrokeWidth[VHQt_M-2-j]+"pt'});\n";
                VHQt_Result+="    }\n";
            }
        }

        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            for (j=0;j<VHQt_M-1;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M-2-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M-2-j]+"], {chartStyle:'line,point'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M-2-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M-2-j]+"','strokeWidth:0');\n";
                VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
                VHQt_Result+="    {\n";
                VHQt_Result+="    "+NameChartLegend[VHQt_M-2-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M-2-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M-2-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M-2-j]+"', size:"+StrokeWidthPoints[VHQt_M-2-j]+", strokeWidth:'"+StrokeWidth[VHQt_M-2-j]+"pt'});\n";
                VHQt_Result+="    }\n";
            }
        }

        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            for (j=0;j<VHQt_M-1;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M-2-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M-2-j]+"], {chartStyle:'line'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M-2-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M-2-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M-2-j]+"','strokeWidth:"+StrokeWidth[VHQt_M-2-j]+"');\n";
            }
        }

        //напишем текст
        QString Delim=";";
        for (j=0;j<VHQt_M-1;j++)
        {
            if (j==VHQt_M-2) Delim=".";
            VHQt_Result+=NameTextLegend[j]+" = "+NameBoardLegend+".create('text',[2.2,"+QString::number(VHQt_M-1-j)+", \"- "+NameLine[j]+Delim+"\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        }

        VHQt_Result+="</script>\n";

        delete [] NameDataYLegend;
        delete [] NameChartLegend;
        delete [] NameTextLegend;
    }

    delete [] Color;
    delete [] HighlightColor;
    delete [] StrokeWidth;
    delete [] FaceOfLine;
    delete [] StrokeWidthPoints;
    delete [] ColorArea;
    delete [] OpacityArea;

    delete [] NameDataY;
    delete [] NameDataYArea;
    delete [] NameChart;
    delete [] SDataY;

    for (i=0;i<VHQt_N;i++) delete [] Temp_VHQt_MatrixXY[i];
    delete [] Temp_VHQt_MatrixXY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной библиотеки отсутствием легенды (нет параметра NewLine).
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    int M=2;
    double **data;
    data=new double*[N];
    for (int i=0;i<N;i++) X[i]=new double[M];
    data[0][0]=7;data[0][1]=6;
    data[1][0]=8;data[1][1]=4;
    data[2][0]=10;data[2][1]=7;
    data[3][0]=5;data[3][1]=12;
    data[4][0]=14;data[4][1]=4;
    data[5][0]=13;data[5][1]=8;

    Html += THQt_ShowChartsOfLineFromMatrix (data,N,M, "График", "x", "y",true,true,true,true);

    for (int i=0;i<N;i++) delete [] data[i];
    delete [] data;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;
    QString *NameLine=new QString[VHQt_M-1];
    for (int i=0;i<VHQt_M-1;i++) NameLine[i]="";

    VHQt_Result = THQt_ShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY,NameLine, ShowLine, ShowPoints, ShowArea, ShowSpecPoints);

    delete [] NameLine;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых переменных - все по умолчанию.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    int M=2;
    double **data;
    data=new double*[N];
    for (int i=0;i<N;i++) X[i]=new double[M];
    data[0][0]=7;data[0][1]=6;
    data[1][0]=8;data[1][1]=4;
    data[2][0]=10;data[2][1]=7;
    data[3][0]=5;data[3][1]=12;
    data[4][0]=14;data[4][1]=4;
    data[5][0]=13;data[5][1]=8;

    QString *NameLine=new QString[M-1];
    NameLine[0]="Первая линия";

    Html += THQt_ShowChartsOfLineFromMatrix (data,N,M, "График", "x", "y",NameLine);

    for (int i=0;i<N;i++) delete [] data[i];
    delete [] data;
    delete [] NameLine;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_ShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, TitleChart, NameVectorX, NameVectorY,NameLine, true, true, false, true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowChartsOfLineFromMatrix (T **VHQt_MatrixXY,int VHQt_N,int VHQt_M)
{
    /*
    Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
    Первый столбец - это значения вектора X, одинакового для всех графиков.
    Все остальные столбцы - значения векторов Y для графиков. Число графиков равно числу этих столбцов.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых переменных и названий осей, графиков - все по умолчанию.
    Входные параметры:
     VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
     VHQt_N - количество точек;
     VHQt_M - количество столбцов матрицы (1+количество графиков);
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M-1 (так как первый столбец - это X значения);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    int M=2;
    double **data;
    data=new double*[N];
    for (int i=0;i<N;i++) X[i]=new double[M];
    data[0][0]=7;data[0][1]=6;
    data[1][0]=8;data[1][1]=4;
    data[2][0]=10;data[2][1]=7;
    data[3][0]=5;data[3][1]=12;
    data[4][0]=14;data[4][1]=4;
    data[5][0]=13;data[5][1]=8;

    Html += THQt_ShowChartsOfLineFromMatrix (data,N,M);

    for (int i=0;i<N;i++) delete [] data[i];
    delete [] data;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;
    QString *NameLine=new QString[VHQt_M-1];
    for (int i=0;i<VHQt_M-1;i++) NameLine[i]="";

    VHQt_Result = THQt_ShowChartsOfLineFromMatrix (VHQt_MatrixXY, VHQt_N, VHQt_M, "", "x", "y",NameLine, true, true, false, true);

    delete [] NameLine;

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine, bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VHQt_Result;//переменная итогового результата
    int i,j,k;

    //цвета
    QString CoordinateColor="#88969c";
    QString HighlightCoordinateColor="#3c7693";

    QString *Color=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) Color[j]="#97bbcd";

    QString *HighlightColor=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) HighlightColor[j]="#3c7693";

    QString *ColorArea=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) ColorArea[j]="#97bbcd";

    QString *OpacityArea=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) OpacityArea[j]="0.5";

    QString *StrokeWidth=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) StrokeWidth[j]="2";

    QString *StrokeWidthPoints=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) StrokeWidthPoints[j]="2";

    QString *FaceOfLine=new QString [VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) FaceOfLine[j]="o";

    if (VHQt_M/2==2)//если два графика
    {
        Color[1]="#cccccc";
        HighlightColor[1]="#7e7e7e";
        ColorArea[1]="#cccccc";
    }
    if ((VHQt_M/2==3)&&(ShowArea))//если три графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";
        ColorArea[1]="#97bbcd";
        OpacityArea[1]="0.5";

        Color[2]="#cccccc";
        HighlightColor[2]="#7e7e7e";
        ColorArea[2]="#cccccc";
        OpacityArea[2]="0.5";
    }
    if ((VHQt_M/2==3)&&(!ShowArea))//если три графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e06c65";
        HighlightColor[2]="#9d2b24";
    }
    if ((VHQt_M/2==4)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#cccccc";
        HighlightColor[3]="#7e7e7e";
        ColorArea[3]="#cccccc";
        OpacityArea[3]="0.5";
    }
    if ((VHQt_M/2==4)&&(!ShowArea))//если 4 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";
    }
    if ((VHQt_M/2==5)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#cccccc";
        HighlightColor[4]="#7e7e7e";
        ColorArea[4]="#cccccc";
        OpacityArea[4]="0.5";
    }
    if ((VHQt_M/2==5)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#e7cc4c";
        HighlightColor[2]="#b49c28";

        Color[3]="#e06c65";
        HighlightColor[3]="#9d2b24";

        Color[4]="#9d50c8";
        HighlightColor[4]="#6a2b8d";
    }
    if ((VHQt_M/2==6)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#799bac";
        HighlightColor[0]="#9d2b24";
        ColorArea[0]="#799bac";
        OpacityArea[0]="0.5";

        Color[1]="#83a6b7";
        HighlightColor[1]="#336278";
        ColorArea[1]="#83a6b7";
        OpacityArea[1]="0.5";

        Color[2]="#97bbcd";
        HighlightColor[2]="#3c7693";
        ColorArea[2]="#97bbcd";
        OpacityArea[2]="0.5";

        Color[3]="#adc2cd";
        HighlightColor[3]="#58839a";
        ColorArea[3]="#adc2cd";
        OpacityArea[3]="0.5";

        Color[4]="#bec7cd";
        HighlightColor[4]="#5c7483";
        ColorArea[4]="#bec7cd";
        OpacityArea[4]="0.5";

        Color[5]="#cccccc";
        HighlightColor[5]="#7e7e7e";
        ColorArea[5]="#cccccc";
        OpacityArea[5]="0.5";
    }
    if ((VHQt_M/2==6)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#97bbcd";
        HighlightColor[0]="#3c7693";

        Color[1]="#4ac955";
        HighlightColor[1]="#2b8c34";

        Color[2]="#b5d24e";
        HighlightColor[2]="#8ca72c";

        Color[3]="#e7cc4c";
        HighlightColor[3]="#b49c28";

        Color[4]="#e06c65";
        HighlightColor[4]="#9d2b24";

        Color[5]="#9d50c8";
        HighlightColor[5]="#6a2b8d";
    }
    if ((VHQt_M/2==7)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#97bbcd";
        HighlightColor[3]="#3c7693";
        ColorArea[3]="#97bbcd";
        OpacityArea[3]="0.5";

        Color[4]="#adc2cd";
        HighlightColor[4]="#58839a";
        ColorArea[4]="#adc2cd";
        OpacityArea[4]="0.5";

        Color[5]="#bec7cd";
        HighlightColor[5]="#5c7483";
        ColorArea[5]="#bec7cd";
        OpacityArea[5]="0.5";

        Color[6]="#cccccc";
        HighlightColor[6]="#7e7e7e";
        ColorArea[6]="#cccccc";
        OpacityArea[6]="0.5";
    }
    if ((VHQt_M/2==7)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";
    }
    if ((VHQt_M/2==8)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#bec7cd";
        HighlightColor[6]="#5c7483";
        ColorArea[6]="#bec7cd";
        OpacityArea[6]="0.5";

        Color[7]="#cccccc";
        HighlightColor[7]="#7e7e7e";
        ColorArea[7]="#cccccc";
        OpacityArea[7]="0.5";
    }
    if ((VHQt_M/2==8)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e06c65";
        HighlightColor[5]="#9d2b24";

        Color[6]="#9d50c8";
        HighlightColor[6]="#6a2b8d";

        Color[7]="#c64f8f";
        HighlightColor[7]="#8d275e";
    }
    if ((VHQt_M/2==9)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        Color[0]="#6a8795";
        HighlightColor[0]="#26576f";
        ColorArea[0]="#6a8795";
        OpacityArea[0]="0.5";

        Color[1]="#799bac";
        HighlightColor[1]="#9d2b24";
        ColorArea[1]="#799bac";
        OpacityArea[1]="0.5";

        Color[2]="#83a6b7";
        HighlightColor[2]="#336278";
        ColorArea[2]="#83a6b7";
        OpacityArea[2]="0.5";

        Color[3]="#8eb1c3";
        HighlightColor[3]="#4d7183";
        ColorArea[3]="#8eb1c3";
        OpacityArea[3]="0.5";

        Color[4]="#97bbcd";
        HighlightColor[4]="#3c7693";
        ColorArea[4]="#97bbcd";
        OpacityArea[4]="0.5";

        Color[5]="#adc2cd";
        HighlightColor[5]="#58839a";
        ColorArea[5]="#adc2cd";
        OpacityArea[5]="0.5";

        Color[6]="#b6c5cd";
        HighlightColor[6]="#617580";
        ColorArea[6]="#b6c5cd";
        OpacityArea[6]="0.5";

        Color[7]="#bec7cd";
        HighlightColor[7]="#5c7483";
        ColorArea[7]="#bec7cd";
        OpacityArea[7]="0.5";

        Color[8]="#cccccc";
        HighlightColor[8]="#7e7e7e";
        ColorArea[8]="#cccccc";
        OpacityArea[8]="0.5";
    }
    if ((VHQt_M/2==9)&&(!ShowArea))//если 5 графика и не показаны закрашенные области
    {
        Color[0]="#6250c9";
        HighlightColor[0]="#392b86";

        Color[1]="#97bbcd";
        HighlightColor[1]="#3c7693";

        Color[2]="#4ac955";
        HighlightColor[2]="#2b8c34";

        Color[3]="#b5d24e";
        HighlightColor[3]="#8ca72c";

        Color[4]="#e7cc4c";
        HighlightColor[4]="#b49c28";

        Color[5]="#e9ac4c";
        HighlightColor[5]="#946b2c";

        Color[6]="#e06c65";
        HighlightColor[6]="#9d2b24";

        Color[7]="#9d50c8";
        HighlightColor[7]="#6a2b8d";

        Color[8]="#c64f8f";
        HighlightColor[8]="#8d275e";
    }
    if ((VHQt_M/2>9)&&(ShowArea))//если 4 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VHQt_M/2;j++)
        {
            position=j/double(VHQt_M/2);
            Color[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#537c90";
            HighlightColor[j]="#26576f";
            ColorArea[j]=THQt_ColorFromGradient(position,"#6a8795","#cccccc");//"#799bac";
            OpacityArea[j]="0.5";
        }
    }
    if ((VHQt_M/2>9)&&(!ShowArea))//если 4 графика и показаны закрашенные области
    {
        double position;
        for (j=0;j<VHQt_M/2;j++)
        {
            position=j/double(VHQt_M/2);
            Color[j]=THQt_AlphaBlendingColorToColor(0.4,THQt_GiveRainbowColorRGB(position),"#ffffff");
            HighlightColor[j]="#26576f";
        }
    }
    //по точкам пройдемся
    if (VHQt_M/2>=3)
    {
        FaceOfLine[1]="[]";
        StrokeWidthPoints[1]="2";

        FaceOfLine[2]="<>";
        StrokeWidthPoints[2]="3";
    }
    if (VHQt_M/2>=4)
    {
        FaceOfLine[3]="x";
        StrokeWidthPoints[3]="3";
    }
    if (VHQt_M/2>=5)
    {
        FaceOfLine[4]="+";
        StrokeWidthPoints[4]="3";
    }
    if (VHQt_M/2>=6)
    {
        FaceOfLine[5]="^";
        StrokeWidthPoints[5]="3";
    }
    if (VHQt_M/2>=7)
    {
        FaceOfLine[6]="v";
        StrokeWidthPoints[6]="3";
    }
    if (VHQt_M/2>=8)
    {
        FaceOfLine[7]=">";
        StrokeWidthPoints[7]="3";
    }
    if (VHQt_M/2>=9)
    {
        FaceOfLine[8]="<";
        StrokeWidthPoints[8]="3";
    }
    //когда уменьшать толщину линии
    if (VHQt_M/2>5)
        for (j=0;j<VHQt_M/2;j++)
        {
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]=QString::number((StrokeWidthPoints[j].toInt())-1);
        }
    if (VHQt_M/2>9)//слишком много кривых
    {
        for (j=0;j<VHQt_M/2;j++)
        {
            FaceOfLine[j]="o";
            StrokeWidth[j]="1";
            StrokeWidthPoints[j]="1";
        }
    }

    //Подсчитаем максимальное число N
    int VHQt_N_Max;
    VHQt_N_Max = VHQt_N_EveryCol[0];
    for (j=0;j<VHQt_M/2;j++)
        if (VHQt_N_EveryCol[j*2]>VHQt_N_Max)
            VHQt_N_Max=VHQt_N_EveryCol[j*2];

    //посчитаем гарницы изменения параметров
    T MinX=VHQt_MatrixXY[0][0];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2];i++)
            if (VHQt_MatrixXY[i][j*2]<MinX)
                MinX=VHQt_MatrixXY[i][j*2];

    T MaxX=VHQt_MatrixXY[0][0];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2];i++)
            if (VHQt_MatrixXY[i][j*2]>MaxX)
                MaxX=VHQt_MatrixXY[i][j*2];

    T MinY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2+1];i++)
            if (VHQt_MatrixXY[i][j*2+1]<MinY)
                MinY=VHQt_MatrixXY[i][j*2+1];

    T MaxY=VHQt_MatrixXY[0][1];
    for (j=0;j<VHQt_M/2;j++)
        for (int i=0;i<VHQt_N_EveryCol[j*2+1];i++)
            if (VHQt_MatrixXY[i][j*2+1]>MaxY)
                MaxY=VHQt_MatrixXY[i][j*2+1];

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VHQt_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VHQt_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;

    QString *NameDataX=new QString[VHQt_M/2];
    QString *NameDataY=new QString[VHQt_M/2];
    QString *NameDataXArea=new QString[VHQt_M/2];
    QString *NameDataYArea=new QString[VHQt_M/2];
    QString *NameChart=new QString[VHQt_M/2];
    for (j=0;j<VHQt_M/2;j++) NameDataX[j]="DataX"+QString::number(j+1)+UniqueName;
    for (j=0;j<VHQt_M/2;j++) NameDataXArea[j]="DataX"+QString::number(j+1)+"Area"+UniqueName;
    for (j=0;j<VHQt_M/2;j++) NameDataY[j]="DataY"+QString::number(j+1)+UniqueName;
    for (j=0;j<VHQt_M/2;j++) NameDataYArea[j]="DataY"+QString::number(j+1)+"Area"+UniqueName;
    for (j=0;j<VHQt_M/2;j++) NameChart[j]="Chart"+QString::number(j+1)+UniqueName;

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T **Temp_VHQt_MatrixXY;
    Temp_VHQt_MatrixXY=new double*[VHQt_N_Max];
    for (i=0;i<VHQt_N_Max;i++) Temp_VHQt_MatrixXY[i]=new double[VHQt_M];
    for (j=0;j<VHQt_M;j++)
        for (i=0;i<VHQt_N_EveryCol[j];i++)
            Temp_VHQt_MatrixXY[i][j]=VHQt_MatrixXY[i][j];

    //отсортируем массивы
    for (k=0;k<VHQt_M/2;k++)
    {
    for(i=VHQt_N_EveryCol[2*k]-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_MatrixXY[j][2*k]>Temp_VHQt_MatrixXY[j+1][2*k])
            {
                    T x;
                    x=Temp_VHQt_MatrixXY[j+1][2*k];
                    Temp_VHQt_MatrixXY[j+1][2*k]=Temp_VHQt_MatrixXY[j][2*k];
                    Temp_VHQt_MatrixXY[j][2*k]=x;

                    x=Temp_VHQt_MatrixXY[j+1][2*k+1];
                    Temp_VHQt_MatrixXY[j+1][2*k+1]=Temp_VHQt_MatrixXY[j][2*k+1];
                    Temp_VHQt_MatrixXY[j][2*k+1]=x;
            }
    }

    //рисуем область графика и оси
    VHQt_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VHQt_Result+="<script type=\"text/javascript\">\n";
    VHQt_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VHQt_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VHQt_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";


    //соберем в массивы javascript данные точек
    QString *SDataX = new QString[VHQt_M/2];
    QString *SDataY = new QString[VHQt_M/2];

    for (j=0;j<VHQt_M/2;j++)
    {
        for (i=0;i<VHQt_N_EveryCol[2*j]-1;i++)
            SDataX[j]+=QString::number(Temp_VHQt_MatrixXY[i][2*j])+", ";
        SDataX[j]+=QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[2*j+1]-1][2*j]);
    }

    for (j=0;j<VHQt_M/2;j++)
    {
        for (i=0;i<VHQt_N_EveryCol[2*j+1]-1;i++)
            SDataY[j]+=QString::number(Temp_VHQt_MatrixXY[i][2*j+1])+", ";
        SDataY[j]+=QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[2*j+1]-1][2*j+1]);
    }

    //запишем массивы точек
    for (j=0;j<VHQt_M/2;j++)
    {
        VHQt_Result+="var "+NameDataX[j]+" = ["+SDataX[j]+"];\n";
        VHQt_Result+="var "+NameDataY[j]+" = ["+SDataY[j]+"];\n";
    }

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить сплошную область.

        for (j=0;j<VHQt_M/2;j++)
        {
            SDataX[j]=QString::number(Temp_VHQt_MatrixXY[0][2*j])+", "+SDataX[j]+", "+QString::number(Temp_VHQt_MatrixXY[VHQt_N_EveryCol[j*2]-1][2*j])+", "+QString::number(Temp_VHQt_MatrixXY[0][2*j]);
        }

        for (j=0;j<VHQt_M/2;j++)
            SDataY[j]=SBeginYAxis+", "+SDataY[j]+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        for (j=0;j<VHQt_M/2;j++)
        VHQt_Result+="var "+NameDataXArea[j]+" = ["+SDataX[j]+"];\n";
        for (j=0;j<VHQt_M/2;j++)
            VHQt_Result+="var "+NameDataYArea[j]+" = ["+SDataY[j]+"];\n";
        for (j=0;j<VHQt_M/2;j++)
            VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea[VHQt_M/2-1-j]+","+NameDataYArea[VHQt_M/2-1-j]+"],{strokeColor:'"+ColorArea[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+ColorArea[VHQt_M/2-1-j]+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+ColorArea[VHQt_M/2-1-j]+"',highlightFillColor:'"+ColorArea[VHQt_M/2-1-j]+"',fillOpacity:"+OpacityArea[VHQt_M/2-1-j]+",highlightFillOpacity:"+OpacityArea[VHQt_M/2-1-j]+"});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график
        for (j=0;j<VHQt_M/2;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VHQt_M/2-1-j]+","+NameDataY[VHQt_M/2-1-j]+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VHQt_M/2-1-j]+"');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N_EveryCol[VHQt_M-1-2*j])+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart[VHQt_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M/2-1-j]+"', size:"+StrokeWidthPoints[VHQt_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VHQt_M/2-1-j]+"pt'});\n";
            VHQt_Result+="    }\n";
        }
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки
        for (j=0;j<VHQt_M/2;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VHQt_M/2-1-j]+","+NameDataY[VHQt_M/2-1-j]+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N_EveryCol[VHQt_M-1-2*j])+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart[VHQt_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M/2-1-j]+"', size:"+StrokeWidthPoints[VHQt_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VHQt_M/2-1-j]+"pt'});\n";
            VHQt_Result+="    }\n";
        }
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию
        for (j=0;j<VHQt_M/2;j++)
        {
            VHQt_Result+="var "+NameChart[VHQt_M/2-1-j]+"= "+NameBoard+".createElement('chart', ["+NameDataX[VHQt_M/2-1-j]+","+NameDataY[VHQt_M/2-1-j]+"], {chartStyle:'line'});\n";
            VHQt_Result+=NameChart[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VHQt_M/2-1-j]+"');\n";
        }
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VHQt_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightCoordinateColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VHQt_Result+="</script>\n";

    // ЛЕГЕНДА
    int NameLineHowManyEmpty=0;
    for (j=0;j<VHQt_M/2;j++) if (NameLine[j].trimmed().isEmpty()!=true) NameLineHowManyEmpty++;

    if (NameLineHowManyEmpty!=0)
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;

        QString *NameDataYLegend= new QString[VHQt_M/2];
        QString *NameChartLegend= new QString[VHQt_M/2];
        QString *NameTextLegend= new QString[VHQt_M/2];

        for (j=0;j<VHQt_M/2;j++) NameDataYLegend[j]="DataY"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VHQt_M/2;j++) NameChartLegend[j]="Chart"+QString::number(j+1)+"Legend"+UniqueNameLegend;
        for (j=0;j<VHQt_M/2;j++) NameTextLegend[j]="Text"+QString::number(j+1)+"Legend"+UniqueNameLegend;


        //рисуем область графика и оси
        VHQt_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:"+QString::number(50*(VHQt_M/2))+"px;\"></div>\n";
        VHQt_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox=QString::number(VHQt_M/2+1);
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VHQt_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";

        for (j=0;j<VHQt_M/2;j++) SDataY[j]=QString::number(VHQt_M/2-j)+", "+QString::number(VHQt_M/2-j);

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            for (j=0;j<VHQt_M/2;j++) SDataY[j]=QString::number(VHQt_M/2-j)+", "+QString::number(VHQt_M/2-j)+", "+QString::number(VHQt_M/2-j);
        }

        //запишем массивы точек

        VHQt_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        for (j=0;j<VHQt_M/2;j++)
            VHQt_Result+="var "+NameDataYLegend[j]+" = ["+SDataY[j]+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            for (j=0;j<VHQt_M/2;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M/2-1-j]+"], {chartStyle:'line,point'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VHQt_M/2-1-j]+"');\n";
                VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
                VHQt_Result+="    {\n";
                VHQt_Result+="    "+NameChartLegend[VHQt_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M/2-1-j]+"', size:"+StrokeWidthPoints[VHQt_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VHQt_M/2-1-j]+"pt'});\n";
                VHQt_Result+="    }\n";
            }
        }

        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            for (j=0;j<VHQt_M/2;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M/2-1-j]+"], {chartStyle:'line,point'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:0');\n";
                VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
                VHQt_Result+="    {\n";
                VHQt_Result+="    "+NameChartLegend[VHQt_M/2-1-j]+"[1][i].setProperty({strokeColor:'"+Color[VHQt_M/2-1-j]+"',highlightStrokeColor:'"+HighlightColor[VHQt_M/2-1-j]+"',fillColor:'white',highlightFillColor:'white',face:'"+FaceOfLine[VHQt_M/2-1-j]+"', size:"+StrokeWidthPoints[VHQt_M/2-1-j]+", strokeWidth:'"+StrokeWidth[VHQt_M/2-1-j]+"pt'});\n";
                VHQt_Result+="    }\n";
            }
        }

        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            for (j=0;j<VHQt_M/2;j++)
            {
                VHQt_Result+="var "+NameChartLegend[VHQt_M/2-1-j]+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataYLegend[VHQt_M/2-1-j]+"], {chartStyle:'line'});\n";
                VHQt_Result+=NameChartLegend[VHQt_M/2-1-j]+"[0].setProperty('strokeColor:"+Color[VHQt_M/2-1-j]+"','highlightStrokeColor:"+HighlightColor[VHQt_M/2-1-j]+"','strokeWidth:"+StrokeWidth[VHQt_M/2-1-j]+"');\n";
            }
        }

        //напишем текст
        QString Delim=";";
        for (j=0;j<VHQt_M/2;j++)
        {
            if (j==VHQt_M/2-1) Delim=".";
            VHQt_Result+=NameTextLegend[j]+" = "+NameBoardLegend+".create('text',[2.2,"+QString::number(VHQt_M/2-j)+", \"- "+NameLine[j]+Delim+"\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        }

        VHQt_Result+="</script>\n";

        delete [] NameDataYLegend;
        delete [] NameChartLegend;
        delete [] NameTextLegend;
    }

    delete [] Color;
    delete [] HighlightColor;
    delete [] StrokeWidth;
    delete [] FaceOfLine;
    delete [] StrokeWidthPoints;
    delete [] ColorArea;
    delete [] OpacityArea;

    delete [] NameDataY;
    delete [] NameDataYArea;
    delete [] NameChart;
    delete [] SDataX;
    delete [] SDataY;

    for (i=0;i<VHQt_N_Max;i++) delete [] Temp_VHQt_MatrixXY[i];
    delete [] Temp_VHQt_MatrixXY;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием легенды на графике.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2;
 ShowLine - показывать ли линию;
 ShowPoints - показывать ли точки;
 ShowArea - показывать ли закрашенную область под кривой;
 ShowSpecPoints - показывать ли специальные точки.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VHQt_Result;//переменная итогового результата

    QString *NameLine=new QString[VHQt_M/2];
    for (int i=0;i<VHQt_M/2;i++) NameLine[i]="";

    VHQt_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY,VHQt_N_EveryCol,VHQt_M,TitleChart, NameVectorX, NameVectorY,NameLine, ShowLine,ShowPoints, ShowArea,ShowSpecPoints);
    delete [] NameLine;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M, QString TitleChart, QString NameVectorX, QString NameVectorY,QString *NameLine)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием булевых переменных - все по умолчанию.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VHQt_Result;//переменная итогового результата

    VHQt_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY,VHQt_N_EveryCol,VHQt_M,TitleChart, NameVectorX, NameVectorY,NameLine,  true,true, false,true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowIndependentChartsOfLineFromMatrix (T **VHQt_MatrixXY,int *VHQt_N_EveryCol,int VHQt_M)
{
    /*
Функция возвращает строку с выводом графиков из матрицы по точкам с HTML кодами. Для добавление в html файл.
Нечетные столбцы - это значения координат X графиков. Следующие за ними четные столбцы - соответствующие
значения Y. То есть графики друг от друга независимы.
Количество графиков равно половине столбцов в матрице.
Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
Отличается от основной функции отсутствием булевых переменных, названий осей, графиков - все по умолчанию.
Входные параметры:
 VHQt_MatrixXY - указатель на матрицу значений X и Н графиков;
 VHQt_N_EveryCol - количество элементов в каждом столбце (так как столбцы идут по парам, то число элементов в нечетном и
 следующем за ним четном столбце должны совпадать, например 10,10,5,5,7,7);
 VHQt_M - количество столбцов матрицы (должно быть четным числом конечно);
 TitleChart - заголовок графика;
 NameVectorX - название оси Ox;
 NameVectorY - название оси Oy;
 NameLine - указатель на вектор названий графиков (для легенды) количество элементов VHQt_M/2.
Возвращаемое значение:
 Строка с HTML кодами с выводимым графиком.
Примечание:
 Используются случайные числа, так что рекомендуется вызвать в программе инициализатор случайных чисел qsrand.
 Рекомендую так:
 qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
*/
    QString VHQt_Result;//переменная итогового результата

    QString *NameLine=new QString[VHQt_M/2];
    for (int i=0;i<VHQt_M/2;i++) NameLine[i]="";

    VHQt_Result = THQt_ShowIndependentChartsOfLineFromMatrix (VHQt_MatrixXY,VHQt_N_EveryCol,VHQt_M,"", "x", "y",NameLine, true,true, false,true);
    delete [] NameLine;

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,true);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString CoordinateColor="#88969c";

    QString Color="#97bbcd";
    QString HighlightColor="#3c7693";

    QString Color2="#cccccc";
    QString HighlightColor2="#7e7e7e";

    //посчитаем гарницы изменения параметров
    T MinX=VHQt_VectorX[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorX[i]<MinX)
            MinX=VHQt_VectorX[i];

    T MinY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY1[i]<MinY1)
            MinY1=VHQt_VectorY1[i];

    T MinY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY2[i]<MinY2)
            MinY2=VHQt_VectorY2[i];

    T MaxX=VHQt_VectorX[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorX[i]>MaxX)
            MaxX=VHQt_VectorX[i];

    T MaxY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY1[i]>MaxY1)
            MaxY1=VHQt_VectorY1[i];

    T MaxY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N;i++)
        if (VHQt_VectorY2[i]>MaxY2)
            MaxY2=VHQt_VectorY2[i];

    T MinY;
    T MaxY;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VHQt_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VHQt_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX="DataX"+UniqueName;
    QString NameDataY1="DataY1"+UniqueName;
    QString NameDataY2="DataY2"+UniqueName;
    QString NameDataXArea="DataXArea"+UniqueName;
    QString NameDataY1Area="DataY1Area"+UniqueName;
    QString NameDataY2Area="DataY2Area"+UniqueName;
    QString NameChart1="Chart1"+UniqueName;
    QString NameChart2="Chart2"+UniqueName;

    //рисуем область графика и оси
    VHQt_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VHQt_Result+="<script type=\"text/javascript\">\n";
    VHQt_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VHQt_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VHQt_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VHQt_VectorX=new T[VHQt_N];
    T *Temp_VHQt_VectorY1=new T[VHQt_N];
    T *Temp_VHQt_VectorY2=new T[VHQt_N];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorX[i]=VHQt_VectorX[i];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorY1[i]=VHQt_VectorY1[i];
    for (i=0;i<VHQt_N;i++) Temp_VHQt_VectorY2[i]=VHQt_VectorY2[i];

    //отсортируем массивы
    for(i=VHQt_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX[j]>Temp_VHQt_VectorX[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX[j+1];
                Temp_VHQt_VectorX[j+1]=Temp_VHQt_VectorX[j];
                Temp_VHQt_VectorX[j]=x;
                x=Temp_VHQt_VectorY1[j+1];
                Temp_VHQt_VectorY1[j+1]=Temp_VHQt_VectorY1[j];
                Temp_VHQt_VectorY1[j]=x;
                x=Temp_VHQt_VectorY2[j+1];
                Temp_VHQt_VectorY2[j+1]=Temp_VHQt_VectorY2[j];
                Temp_VHQt_VectorY2[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX;
    QString SDataY1;
    QString SDataY2;
    for (i=0;i<VHQt_N-1;i++)
        SDataX+=QString::number(Temp_VHQt_VectorX[i])+", ";
    SDataX+=QString::number(Temp_VHQt_VectorX[VHQt_N-1]);
    for (i=0;i<VHQt_N-1;i++)
        SDataY1+=QString::number(Temp_VHQt_VectorY1[i])+", ";
    SDataY1+=QString::number(Temp_VHQt_VectorY1[VHQt_N-1]);

    for (i=0;i<VHQt_N-1;i++)
        SDataY2+=QString::number(Temp_VHQt_VectorY2[i])+", ";
    SDataY2+=QString::number(Temp_VHQt_VectorY2[VHQt_N-1]);

    //запишем массивы точек
    VHQt_Result+="var "+NameDataX+" = ["+SDataX+"];\n";
    VHQt_Result+="var "+NameDataY1+" = ["+SDataY1+"];\n";
    VHQt_Result+="var "+NameDataY2+" = ["+SDataY2+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX=QString::number(MinX)+", "+SDataX+", "+QString::number(MaxX)+", "+QString::number(MinX);
        SDataY1=SBeginYAxis+", "+SDataY1+", "+SBeginYAxis+", "+SBeginYAxis;
        SDataY2=SBeginYAxis+", "+SDataY2+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VHQt_Result+="var "+NameDataXArea+" = ["+SDataX+"];\n";
        VHQt_Result+="var "+NameDataY1Area+" = ["+SDataY1+"];\n";
        VHQt_Result+="var "+NameDataY2Area+" = ["+SDataY2+"];\n";
        VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataY2Area+"],{strokeColor:'"+Color2+"',highlightStrokeColor:'"+Color2+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color2+"',highlightFillColor:'"+Color2+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
        VHQt_Result+=NameBoard+".create('curve', ["+NameDataXArea+","+NameDataY1Area+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";

        //Нарисуем график
        VHQt_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";

        //Нарисуем точки
        VHQt_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию 2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY2+"], {chartStyle:'line'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";

        //Нарисуем только линию
        VHQt_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX+","+NameDataY1+"], {chartStyle:'line'});\n";
        VHQt_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VHQt_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VHQt_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine1.trimmed().isEmpty()))&& (!(NameLine2.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataY1Legend="DataY1Legend"+UniqueNameLegend;
        QString NameDataY2Legend="DataY2Legend"+UniqueNameLegend;
        QString NameChart1Legend="Chart1Legend"+UniqueNameLegend;
        QString NameChart2Legend="Chart2Legend"+UniqueNameLegend;
        QString NameText1Legend="Text1Legend"+UniqueName;
        QString NameText2Legend="Text2Legend"+UniqueName;


        //рисуем область графика и оси
        VHQt_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:100px;\"></div>\n";
        VHQt_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="3";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VHQt_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        SDataX="1, 2";
        SDataY1="2, 2";
        SDataY2="1, 1";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY1="2, 2, 2";
            SDataY2="1, 1, 1";
        }

        //запишем массивы точек
        VHQt_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VHQt_Result+="var "+NameDataY1Legend+" = ["+SDataY1+"];\n";
        VHQt_Result+="var "+NameDataY2Legend+" = ["+SDataY2+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            VHQt_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";

            //Нарисуем график2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            VHQt_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";

            //Нарисуем точки2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            VHQt_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line'});\n";
            VHQt_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";

            //Нарисуем только линию 2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        }

        //напишем текст
        VHQt_Result+=NameText1Legend+" = "+NameBoardLegend+".create('text',[2.2,2, \"- "+NameLine1+";\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        VHQt_Result+=NameText2Legend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine2+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VHQt_Result+="</script>\n";
    }

    delete [] Temp_VHQt_VectorX;
    delete [] Temp_VHQt_VectorY1;
    delete [] Temp_VHQt_VectorY2;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается отсуствием параметров NameLine1 и NameLine2. То есть нет легенды у графика.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y",true,true,true,true);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VHQt_VectorX,VHQt_VectorY1,VHQt_VectorY2, VHQt_N,TitleChart,NameVectorX, NameVectorY,"", "",ShowLine,ShowPoints,ShowArea, ShowSpecPoints);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевских переменных - все по умолчанию.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,"Тестовый график","x","y","количество деревьев","количество домов");

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VHQt_VectorX,VHQt_VectorY1,VHQt_VectorY2, VHQt_N, TitleChart, NameVectorX, NameVectorY, NameLine1, NameLine2,true,true,true,true);

}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoChartsOfLine (T *VHQt_VectorX,T *VHQt_VectorY1,T *VHQt_VectorY2, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого двух графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков одинаковый массив значений X.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевских переменных и названий графика, осей, линий - все по умолчанию.
    Входные параметры:
     VHQt_VectorX - указатель на вектор координат X точек;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N - количество точек;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N=6;
    double *dataX=new double [N];
    double *dataY1=new double [N];
    double *dataY2=new double [N];
    dataX[0]=7;dataY1[0]=6;dataY2[0]=1;
    dataX[1]=8;dataY1[1]=4;dataY2[0]=2;
    dataX[2]=10;dataY1[2]=7;dataY2[0]=3;
    dataX[3]=5;dataY1[3]=12;dataY2[0]=4;
    dataX[4]=14;dataY1[4]=4;dataY2[0]=4;
    dataX[5]=13;dataY1[5]=8;dataY2[0]=3;

    Html += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N);

    delete []dataX;
    delete []dataY1;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoChartsOfLine (VHQt_VectorX,VHQt_VectorY1,VHQt_VectorY2, VHQt_N, "", "x", "y", "", "",true,true,true,true);
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,true);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString CoordinateColor="#88969c";

    QString Color="#97bbcd";
    QString HighlightColor="#3c7693";

    QString Color2="#cccccc";
    QString HighlightColor2="#7e7e7e";

    //посчитаем гарницы изменения параметров
    T MinX1=VHQt_VectorX1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorX1[i]<MinX1)
            MinX1=VHQt_VectorX1[i];

    T MinX2=VHQt_VectorX2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorX2[i]<MinX2)
            MinX2=VHQt_VectorX2[i];

    T MinY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorY1[i]<MinY1)
            MinY1=VHQt_VectorY1[i];

    T MinY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorY2[i]<MinY2)
            MinY2=VHQt_VectorY2[i];

    T MaxX1=VHQt_VectorX1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorX1[i]>MaxX1)
            MaxX1=VHQt_VectorX1[i];

    T MaxX2=VHQt_VectorX2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorX2[i]>MaxX2)
            MaxX2=VHQt_VectorX2[i];

    T MaxY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorY1[i]>MaxY1)
            MaxY1=VHQt_VectorY1[i];

    T MaxY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorY2[i]>MaxY2)
            MaxY2=VHQt_VectorY2[i];

    T MinX;
    T MaxX;

    T MinY;
    T MaxY;

    if (MinX1<MinX2)
        MinX=MinX1;
    else
        MinX=MinX2;

    if (MaxX1>MaxX2)
        MaxX=MaxX1;
    else
        MaxX=MaxX2;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VHQt_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VHQt_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX1="DataX1"+UniqueName;
    QString NameDataX2="DataX2"+UniqueName;
    QString NameDataY1="DataY1"+UniqueName;
    QString NameDataY2="DataY2"+UniqueName;
    QString NameDataX1Area="DataX1Area"+UniqueName;
    QString NameDataX2Area="DataX2Area"+UniqueName;
    QString NameDataY1Area="DataY1Area"+UniqueName;
    QString NameDataY2Area="DataY2Area"+UniqueName;
    QString NameChart1="Chart1"+UniqueName;
    QString NameChart2="Chart2"+UniqueName;

    //рисуем область графика и оси
    VHQt_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VHQt_Result+="<script type=\"text/javascript\">\n";
    VHQt_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VHQt_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VHQt_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VHQt_VectorX1=new T[VHQt_N1];
    T *Temp_VHQt_VectorX2=new T[VHQt_N2];
    T *Temp_VHQt_VectorY1=new T[VHQt_N1];
    T *Temp_VHQt_VectorY2=new T[VHQt_N2];
    for (i=0;i<VHQt_N1;i++) Temp_VHQt_VectorX1[i]=VHQt_VectorX1[i];
    for (i=0;i<VHQt_N2;i++) Temp_VHQt_VectorX2[i]=VHQt_VectorX2[i];
    for (i=0;i<VHQt_N1;i++) Temp_VHQt_VectorY1[i]=VHQt_VectorY1[i];
    for (i=0;i<VHQt_N2;i++) Temp_VHQt_VectorY2[i]=VHQt_VectorY2[i];

    //отсортируем массивы
    for(i=VHQt_N1-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX1[j]>Temp_VHQt_VectorX1[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX1[j+1];
                Temp_VHQt_VectorX1[j+1]=Temp_VHQt_VectorX1[j];
                Temp_VHQt_VectorX1[j]=x;
                x=Temp_VHQt_VectorY1[j+1];
                Temp_VHQt_VectorY1[j+1]=Temp_VHQt_VectorY1[j];
                Temp_VHQt_VectorY1[j]=x;
            }

    for(i=VHQt_N2-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX2[j]>Temp_VHQt_VectorX2[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX2[j+1];
                Temp_VHQt_VectorX2[j+1]=Temp_VHQt_VectorX2[j];
                Temp_VHQt_VectorX2[j]=x;
                x=Temp_VHQt_VectorY2[j+1];
                Temp_VHQt_VectorY2[j+1]=Temp_VHQt_VectorY2[j];
                Temp_VHQt_VectorY2[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX1;
    QString SDataX2;
    QString SDataY1;
    QString SDataY2;

    for (i=0;i<VHQt_N1-1;i++)
        SDataX1+=QString::number(Temp_VHQt_VectorX1[i])+", ";
    SDataX1+=QString::number(Temp_VHQt_VectorX1[VHQt_N1-1]);

    for (i=0;i<VHQt_N2-1;i++)
        SDataX2+=QString::number(Temp_VHQt_VectorX2[i])+", ";
    SDataX2+=QString::number(Temp_VHQt_VectorX2[VHQt_N2-1]);

    for (i=0;i<VHQt_N1-1;i++)
        SDataY1+=QString::number(Temp_VHQt_VectorY1[i])+", ";
    SDataY1+=QString::number(Temp_VHQt_VectorY1[VHQt_N1-1]);

    for (i=0;i<VHQt_N2-1;i++)
        SDataY2+=QString::number(Temp_VHQt_VectorY2[i])+", ";
    SDataY2+=QString::number(Temp_VHQt_VectorY2[VHQt_N2-1]);

    //запишем массивы точек
    VHQt_Result+="var "+NameDataX1+" = ["+SDataX1+"];\n";
    VHQt_Result+="var "+NameDataX2+" = ["+SDataX2+"];\n";
    VHQt_Result+="var "+NameDataY1+" = ["+SDataY1+"];\n";
    VHQt_Result+="var "+NameDataY2+" = ["+SDataY2+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX1=QString::number(MinX1)+", "+SDataX1+", "+QString::number(MaxX1)+", "+QString::number(MinX1);
        SDataX2=QString::number(MinX2)+", "+SDataX2+", "+QString::number(MaxX2)+", "+QString::number(MinX2);
        SDataY1=SBeginYAxis+", "+SDataY1+", "+SBeginYAxis+", "+SBeginYAxis;
        SDataY2=SBeginYAxis+", "+SDataY2+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VHQt_Result+="var "+NameDataX1Area+" = ["+SDataX1+"];\n";
        VHQt_Result+="var "+NameDataX2Area+" = ["+SDataX2+"];\n";
        VHQt_Result+="var "+NameDataY1Area+" = ["+SDataY1+"];\n";
        VHQt_Result+="var "+NameDataY2Area+" = ["+SDataY2+"];\n";
        VHQt_Result+=NameBoard+".create('curve', ["+NameDataX2Area+","+NameDataY2Area+"],{strokeColor:'"+Color2+"',highlightStrokeColor:'"+Color2+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color2+"',highlightFillColor:'"+Color2+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
        VHQt_Result+=NameBoard+".create('curve', ["+NameDataX1Area+","+NameDataY1Area+"],{strokeColor:'"+Color+"',highlightStrokeColor:'"+Color+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color+"',highlightFillColor:'"+Color+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N2)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";

        //Нарисуем график
        VHQt_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX1+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N1)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N2)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";

        //Нарисуем точки
        VHQt_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX1+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N1)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию 2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";

        //Нарисуем только линию
        VHQt_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX1+","+NameDataY1+"], {chartStyle:'line'});\n";
        VHQt_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
    }

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VHQt_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VHQt_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine1.trimmed().isEmpty()))&& (!(NameLine2.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataY1Legend="DataY1Legend"+UniqueNameLegend;
        QString NameDataY2Legend="DataY2Legend"+UniqueNameLegend;
        QString NameChart1Legend="Chart1Legend"+UniqueNameLegend;
        QString NameChart2Legend="Chart2Legend"+UniqueNameLegend;
        QString NameText1Legend="Text1Legend"+UniqueName;
        QString NameText2Legend="Text2Legend"+UniqueName;


        //рисуем область графика и оси
        VHQt_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:100px;\"></div>\n";
        VHQt_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="3";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VHQt_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";
        SDataY1="2, 2";
        SDataY2="1, 1";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY1="2, 2, 2";
            SDataY2="1, 1, 1";
        }

        //запишем массивы точек
        VHQt_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VHQt_Result+="var "+NameDataY1Legend+" = ["+SDataY1+"];\n";
        VHQt_Result+="var "+NameDataY2Legend+" = ["+SDataY2+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график
            VHQt_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";

            //Нарисуем график2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки
            VHQt_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";

            //Нарисуем точки2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'[]', size:3, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию
            VHQt_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY1Legend+"], {chartStyle:'line'});\n";
            VHQt_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:2');\n";

            //Нарисуем только линию 2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        }

        //напишем текст
        VHQt_Result+=NameText1Legend+" = "+NameBoardLegend+".create('text',[2.2,2, \"- "+NameLine1+";\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        VHQt_Result+=NameText2Legend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine2+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VHQt_Result+="</script>\n";
    }

    delete [] Temp_VHQt_VectorX1;
    delete [] Temp_VHQt_VectorX2;
    delete [] Temp_VHQt_VectorY1;
    delete [] Temp_VHQt_VectorY2;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием легенды, то есть параметров NameLine1, NameLine2.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную ошбласть под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y",true,true,true,true);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfLine (VHQt_VectorX1,VHQt_VectorY1, VHQt_N1,VHQt_VectorX2,VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY,"", "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых параметров - все по умолчанию.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y","количество деревьев","количество домов");

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfLine (VHQt_VectorX1,VHQt_VectorY1,VHQt_N1,VHQt_VectorX2,VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY,NameLine1, NameLine2,true,true,true,true);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых параметров и подписей - все по умолчанию.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,N1,dataX2,dataY2,N2);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfLine (VHQt_VectorX1,VHQt_VectorY1,VHQt_N1,VHQt_VectorX2,VHQt_VectorY2, VHQt_N2, "", "x", "y","", "",true,true,true,true);
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y","количество деревьев","количество домов",true,true,true,true);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    QString VHQt_Result;//переменная итогового результата
    int i,j;

    //цвета
    QString CoordinateColor="#88969c";

    QString Color="#e94939";
    QString HighlightColor="#9d3e38";

    //QString Color="#4b8aaa";
    //QString HighlightColor="#21546d";

    QString Color2="#97bbcd";
    QString HighlightColor2="#3c7693";


    //посчитаем гарницы изменения параметров
    T MinX1=VHQt_VectorX1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorX1[i]<MinX1)
            MinX1=VHQt_VectorX1[i];

    T MinX2=VHQt_VectorX2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorX2[i]<MinX2)
            MinX2=VHQt_VectorX2[i];

    T MinY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorY1[i]<MinY1)
            MinY1=VHQt_VectorY1[i];

    T MinY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorY2[i]<MinY2)
            MinY2=VHQt_VectorY2[i];

    T MaxX1=VHQt_VectorX1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorX1[i]>MaxX1)
            MaxX1=VHQt_VectorX1[i];

    T MaxX2=VHQt_VectorX2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorX2[i]>MaxX2)
            MaxX2=VHQt_VectorX2[i];

    T MaxY1=VHQt_VectorY1[0];
    for (int i=1;i<VHQt_N1;i++)
        if (VHQt_VectorY1[i]>MaxY1)
            MaxY1=VHQt_VectorY1[i];

    T MaxY2=VHQt_VectorY2[0];
    for (int i=1;i<VHQt_N2;i++)
        if (VHQt_VectorY2[i]>MaxY2)
            MaxY2=VHQt_VectorY2[i];

    T MinX;
    T MaxX;

    T MinY;
    T MaxY;

    if (MinX1<MinX2)
        MinX=MinX1;
    else
        MinX=MinX2;

    if (MaxX1>MaxX2)
        MaxX=MaxX1;
    else
        MaxX=MaxX2;

    if (MinY1<MinY2)
        MinY=MinY1;
    else
        MinY=MinY2;

    if (MaxY1>MaxY2)
        MaxY=MaxY1;
    else
        MaxY=MaxY2;

    T LengthX=MaxX-MinX;
    T LengthY=MaxY-MinY;

    //посчитаем область графика, в которой все будет рисоваться
    T LeftXBoundingBox=MinX-LengthX/10.;
    T LeftYBoundingBox=MinY-LengthY/5.;
    T RightXBoundingBox=MaxX+LengthX/5.;
    T RightYBoundingBox=MaxY+LengthY/5.;

    if (MinX==MaxX) { LeftXBoundingBox-=1; LengthX=2; RightXBoundingBox+=1;}
    if (MinY==MaxY) { LeftYBoundingBox-=1; LengthY=2; RightYBoundingBox+=1;}

    QString SLeftXBoundingBox=QString::number(LeftXBoundingBox);
    QString SLeftYBoundingBox=QString::number(LeftYBoundingBox);
    QString SRightXBoundingBox=QString::number(RightXBoundingBox);
    QString SRightYBoundingBox=QString::number(RightYBoundingBox);
    SLeftXBoundingBox.replace(',', '.');
    SLeftYBoundingBox.replace(',', '.');
    SRightXBoundingBox.replace(',', '.');
    SRightYBoundingBox.replace(',', '.');

    //посчитаем, где будем рисовать оси
    T BeginXAxis=MinX;
    T BeginYAxis=MinY;
    T UpXAxis=BeginXAxis+1.;
    T UpYAxis=BeginYAxis+1.;
    QString SBeginXAxis=QString::number(BeginXAxis);
    QString SBeginYAxis=QString::number(BeginYAxis);
    QString SUpXAxis=QString::number(UpXAxis);
    QString SUpYAxis=QString::number(UpYAxis);
    SUpXAxis.replace(',', '.');
    SUpYAxis.replace(',', '.');

    VHQt_Result+="<!--Вывод графика-->\n";

    if ((!(TitleChart.trimmed().isEmpty())))
        VHQt_Result+="<h2>"+TitleChart+"</h2>";

    //имена объектов в графике
    QString UniqueName=HQt_RandomString(6);
    QString NameBox="Box"+UniqueName;
    QString NameBoard="Board"+UniqueName;
    QString NameAxisX="AxisX"+UniqueName;
    QString NameAxisY="AxisY"+UniqueName;
    QString NameDataX1="DataX1"+UniqueName;
    QString NameDataX2="DataX2"+UniqueName;
    QString NameDataY1="DataY1"+UniqueName;
    QString NameDataY2="DataY2"+UniqueName;
    QString NameDataX1Area="DataX1Area"+UniqueName;
    QString NameDataX2Area="DataX2Area"+UniqueName;
    QString NameDataY1Area="DataY1Area"+UniqueName;
    QString NameDataY2Area="DataY2Area"+UniqueName;
    QString NameChart1="Chart1"+UniqueName;
    QString NameChart2="Chart2"+UniqueName;

    //рисуем область графика и оси
    VHQt_Result+="<div id=\""+NameBox+"\" class=\"jxgbox\" style=\"width:600px; height:300px;\"></div>\n";
    VHQt_Result+="<script type=\"text/javascript\">\n";
    VHQt_Result+="var "+NameBoard+" = JXG.JSXGraph.initBoard('"+NameBox+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: true}});\n";
    VHQt_Result+="var "+NameAxisX+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SUpXAxis+", "+SBeginYAxis+"]],{withLabel: true, name: '"+NameVectorX+"',label: {position:'lft',offset:[10,-21]}});\n";
    VHQt_Result+="var "+NameAxisY+" = "+NameBoard+".create('axis', [["+SBeginXAxis+", "+SBeginYAxis+"], ["+SBeginXAxis+", "+SUpYAxis+"]],{withLabel: true, name: '"+NameVectorY+"',label: { position:'lrt',offset: [20,0]}});\n";

    //копируем во временный массив наши массивы, чтобы их не потревожить
    T *Temp_VHQt_VectorX1=new T[VHQt_N1];
    T *Temp_VHQt_VectorX2=new T[VHQt_N2];
    T *Temp_VHQt_VectorY1=new T[VHQt_N1];
    T *Temp_VHQt_VectorY2=new T[VHQt_N2];
    for (i=0;i<VHQt_N1;i++) Temp_VHQt_VectorX1[i]=VHQt_VectorX1[i];
    for (i=0;i<VHQt_N2;i++) Temp_VHQt_VectorX2[i]=VHQt_VectorX2[i];
    for (i=0;i<VHQt_N1;i++) Temp_VHQt_VectorY1[i]=VHQt_VectorY1[i];
    for (i=0;i<VHQt_N2;i++) Temp_VHQt_VectorY2[i]=VHQt_VectorY2[i];

    //отсортируем массивы
    for(i=VHQt_N1-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX1[j]>Temp_VHQt_VectorX1[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX1[j+1];
                Temp_VHQt_VectorX1[j+1]=Temp_VHQt_VectorX1[j];
                Temp_VHQt_VectorX1[j]=x;
                x=Temp_VHQt_VectorY1[j+1];
                Temp_VHQt_VectorY1[j+1]=Temp_VHQt_VectorY1[j];
                Temp_VHQt_VectorY1[j]=x;
            }

    for(i=VHQt_N2-1;i>0;i--)
        for(j=0;j<i;j++)
            if(Temp_VHQt_VectorX2[j]>Temp_VHQt_VectorX2[j+1])
            {
                T x;
                x=Temp_VHQt_VectorX2[j+1];
                Temp_VHQt_VectorX2[j+1]=Temp_VHQt_VectorX2[j];
                Temp_VHQt_VectorX2[j]=x;
                x=Temp_VHQt_VectorY2[j+1];
                Temp_VHQt_VectorY2[j+1]=Temp_VHQt_VectorY2[j];
                Temp_VHQt_VectorY2[j]=x;
            }

    //соберем в массивы javascript данные точек
    QString SDataX1;
    QString SDataX2;
    QString SDataY1;
    QString SDataY2;

    for (i=0;i<VHQt_N1-1;i++)
        SDataX1+=QString::number(Temp_VHQt_VectorX1[i])+", ";
    SDataX1+=QString::number(Temp_VHQt_VectorX1[VHQt_N1-1]);

    for (i=0;i<VHQt_N2-1;i++)
        SDataX2+=QString::number(Temp_VHQt_VectorX2[i])+", ";
    SDataX2+=QString::number(Temp_VHQt_VectorX2[VHQt_N2-1]);

    for (i=0;i<VHQt_N1-1;i++)
        SDataY1+=QString::number(Temp_VHQt_VectorY1[i])+", ";
    SDataY1+=QString::number(Temp_VHQt_VectorY1[VHQt_N1-1]);

    for (i=0;i<VHQt_N2-1;i++)
        SDataY2+=QString::number(Temp_VHQt_VectorY2[i])+", ";
    SDataY2+=QString::number(Temp_VHQt_VectorY2[VHQt_N2-1]);

    //запишем массивы точек
    VHQt_Result+="var "+NameDataX1+" = ["+SDataX1+"];\n";
    VHQt_Result+="var "+NameDataX2+" = ["+SDataX2+"];\n";
    VHQt_Result+="var "+NameDataY1+" = ["+SDataY1+"];\n";
    VHQt_Result+="var "+NameDataY2+" = ["+SDataY2+"];\n";

    if (ShowArea)
    {
        //добавим точки для того, чтобы можно было закрасить спрошную область.

        SDataX2=QString::number(MinX2)+", "+SDataX2+", "+QString::number(MaxX2)+", "+QString::number(MinX2);
        SDataY2=SBeginYAxis+", "+SDataY2+", "+SBeginYAxis+", "+SBeginYAxis;

        //нарисуем закрашенную область
        VHQt_Result+="var "+NameDataX2Area+" = ["+SDataX2+"];\n";
        VHQt_Result+="var "+NameDataY2Area+" = ["+SDataY2+"];\n";
        VHQt_Result+=NameBoard+".create('curve', ["+NameDataX2Area+","+NameDataY2Area+"],{strokeColor:'"+Color2+"',highlightStrokeColor:'"+Color2+"',strokeWidth:0,highlightStrokeWidth:0,dash:0, fillColor:'"+Color2+"',highlightFillColor:'"+Color2+"',fillOpacity:0.5,highlightFillOpacity:0.5});\n";
    }

    if ((ShowPoints)&&(ShowLine))
    {
        //Нарисуем график2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N2)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";
    }

    if ((ShowPoints)&&(!ShowLine))
    {
        //Нарисуем точки2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N2)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart2+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";
    }

    //Рисуем вторые точки всегда
    {
        //Нарисуем точки
        VHQt_Result+="var "+NameChart1+"= "+NameBoard+".createElement('chart', ["+NameDataX1+","+NameDataY1+"], {chartStyle:'line,point'});\n";
        VHQt_Result+=NameChart1+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
        VHQt_Result+="for(var i=0; i<"+QString::number(VHQt_N1)+";i++) \n";
        VHQt_Result+="    {\n";
        VHQt_Result+="    "+NameChart1+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:1, strokeWidth:'2pt'});\n";
        VHQt_Result+="    }\n";
    }

    if ((!ShowPoints)&&(ShowLine))
    {
        //Нарисуем только линию 2
        VHQt_Result+="var "+NameChart2+"= "+NameBoard+".createElement('chart', ["+NameDataX2+","+NameDataY2+"], {chartStyle:'line'});\n";
        VHQt_Result+=NameChart2+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
}

    if (ShowSpecPoints)
    {
        //Теперь проставим точки
        //Нулевая точка
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Min<sub>x</sub> = "+SBeginXAxis+", Min<sub>y</sub> = "+SBeginYAxis+"',label:{fontsize:10}});\n";
        //Максимальная по Y
        VHQt_Result+=NameBoard+".create('point',["+SBeginXAxis+","+QString::number(MaxY)+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>y</sub> = "+QString::number(MaxY)+"',label:{fontsize:10}});\n";
        //Максимальная по X
        VHQt_Result+=NameBoard+".create('point',["+QString::number(MaxX)+","+SBeginYAxis+"], {strokeColor:'"+CoordinateColor+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',strokeWidth:'2pt',face:'o', size:1, name:'Max<sub>x</sub> = "+QString::number(MaxX)+"',label:{fontsize:10}});\n";
    }

    VHQt_Result+="</script>\n";

    // ЛЕГЕНДА
    if ((!(NameLine1.trimmed().isEmpty()))&& (!(NameLine2.trimmed().isEmpty())))
    {
        //имена объектов в легенде
        QString UniqueNameLegend=HQt_RandomString(6);
        QString NameBoxNameLegend="BoxLegend"+UniqueNameLegend;
        QString NameBoardLegend="BoardLegend"+UniqueNameLegend;
        QString NameDataXLegend="DataXLegend"+UniqueNameLegend;
        QString NameDataY1Legend="DataY1Legend"+UniqueNameLegend;
        QString NameDataY2Legend="DataY2Legend"+UniqueNameLegend;
        QString NameChart1Legend="Chart1Legend"+UniqueNameLegend;
        QString NameChart2Legend="Chart2Legend"+UniqueNameLegend;
        QString NameText1Legend="Text1Legend"+UniqueName;
        QString NameText2Legend="Text2Legend"+UniqueName;


        //рисуем область графика и оси
        VHQt_Result+="<div id=\""+NameBoxNameLegend+"\" class=\"jxgbox\" style=\"width:600px; height:100px;\"></div>\n";
        VHQt_Result+="<script type=\"text/javascript\">\n";
        SLeftXBoundingBox="0";
        SRightYBoundingBox="3";
        SRightXBoundingBox="11.5";
        SLeftYBoundingBox="0";
        VHQt_Result+="var "+NameBoardLegend+" = JXG.JSXGraph.initBoard('"+NameBoxNameLegend+"', {boundingbox: ["+SLeftXBoundingBox+", "+SRightYBoundingBox+", "+SRightXBoundingBox+", "+SLeftYBoundingBox+"], axis:false,keepaspectratio: false,showcopyright: false,showNavigation: false, zoom: {wheel: false}});\n";

        //соберем в массивы javascript данные точек
        QString SDataX="1, 2";
        SDataY2="1, 1";

        QString SDataX1="1, 1.5, 2";
        SDataY1="2, 2, 2";

        if ((ShowPoints)&&(!ShowLine))
        {
            //на одну точку больше
            SDataX="1, 1.5, 2";
            SDataY2="1, 1, 1";
        }

        //запишем массивы точек
        VHQt_Result+="var "+NameDataXLegend+" = ["+SDataX+"];\n";
        VHQt_Result+="var "+NameDataXLegend+"1 = ["+SDataX1+"];\n";
        VHQt_Result+="var "+NameDataY1Legend+" = ["+SDataY1+"];\n";
        VHQt_Result+="var "+NameDataY2Legend+" = ["+SDataY2+"];\n";

        if ((ShowPoints)&&(ShowLine))
        {
            //Нарисуем график2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(2)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";
        }
        if ((ShowPoints)&&(!ShowLine))
        {
            //Нарисуем точки2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart2Legend+"[1][i].setProperty({strokeColor:'"+Color2+"',highlightStrokeColor:'"+HighlightColor2+"',fillColor:'white',highlightFillColor:'white',face:'o', size:2, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";
        }
        if (((!ShowPoints)&&(ShowLine))||((!ShowPoints)&&(!ShowLine)))
        {
            //Нарисуем только линию 2
            VHQt_Result+="var "+NameChart2Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+","+NameDataY2Legend+"], {chartStyle:'line'});\n";
            VHQt_Result+=NameChart2Legend+"[0].setProperty('strokeColor:"+Color2+"','highlightStrokeColor:"+HighlightColor2+"','strokeWidth:2');\n";
        }

        //Всегда рисуем точки
        {
            //Нарисуем точки
            VHQt_Result+="var "+NameChart1Legend+"= "+NameBoardLegend+".createElement('chart', ["+NameDataXLegend+"1,"+NameDataY1Legend+"], {chartStyle:'line,point'});\n";
            VHQt_Result+=NameChart1Legend+"[0].setProperty('strokeColor:"+Color+"','highlightStrokeColor:"+HighlightColor+"','strokeWidth:0');\n";
            VHQt_Result+="for(var i=0; i<"+QString::number(3)+";i++) \n";
            VHQt_Result+="    {\n";
            VHQt_Result+="    "+NameChart1Legend+"[1][i].setProperty({strokeColor:'"+Color+"',highlightStrokeColor:'"+HighlightColor+"',fillColor:'white',highlightFillColor:'white',face:'o', size:1, strokeWidth:'2pt'});\n";
            VHQt_Result+="    }\n";
        }

        //напишем текст
        VHQt_Result+=NameText1Legend+" = "+NameBoardLegend+".create('text',[2.2,2, \"- "+NameLine1+";\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";
        VHQt_Result+=NameText2Legend+" = "+NameBoardLegend+".create('text',[2.2,1, \"- "+NameLine2+".\"], {display:'internal', anchorX:'left',frozen: true, strokeColor:'#000000',highlightStrokeColor:'#000000'});\n";

        VHQt_Result+="</script>\n";
    }

    delete [] Temp_VHQt_VectorX1;
    delete [] Temp_VHQt_VectorX2;
    delete [] Temp_VHQt_VectorY1;
    delete [] Temp_VHQt_VectorY2;

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,bool ShowLine,bool ShowPoints,bool ShowArea,bool ShowSpecPoints)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием легенды, то есть параметров NameLine1, NameLine2.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y",true,true,true,true);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfPointsAndLine (VHQt_VectorX1,VHQt_VectorY1, VHQt_N1,VHQt_VectorX2,VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY,"", "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2, QString TitleChart, QString NameVectorX, QString NameVectorY,QString NameLine1, QString NameLine2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых параметров - все по умолчанию.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     NameLine1 - название первого графика (для легенды);
     NameLine2 - название второго графика (для легенды).
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,N1,dataX2,dataY2,N2,"Тестовый график","x","y","количество деревьев","количество домов");

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfPointsAndLine (VHQt_VectorX1,VHQt_VectorY1,VHQt_N1,VHQt_VectorX2,VHQt_VectorY2, VHQt_N2, TitleChart, NameVectorX, NameVectorY,NameLine1, NameLine2,true,false,false,true);
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowTwoIndependentChartsOfPointsAndLine (T *VHQt_VectorX1,T *VHQt_VectorY1,int VHQt_N1,T *VHQt_VectorX2,T *VHQt_VectorY2, int VHQt_N2)
{
    /*
    Функция возвращает строку с выводом некоторого двух независимых графиков по точкам с HTML кодами. Для добавление в html файл.
    Один график выводится в виде точек, а второй в виде линии. Удобно для отображения регрессий.
    У обоих графиков разные массивы значений X и Y.
    Требует наличия в папке с html файлом файлы jsxgraph.css и jsxgraphcore.js из библиотеки JSXGraph.
    Отличается от основной функции отсутствием булевых параметров и подписей - все по умолчанию.
    Входные параметры:
     VHQt_VectorX1 - указатель на вектор координат X точек первой линии;
     VHQt_VectorY1 - указатель на вектор координат Y точек первой линии;
     VHQt_N1 - количество точек первой линии;
     VHQt_VectorX2 - указатель на вектор координат X точек второй линии;
     VHQt_VectorY2 - указатель на вектор координат Y точек второй линии;
     VHQt_N2 - количество точек второй линии.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым графиком.
    Примечание:
     Используются случайные числа, так что рекомендуется вызвать в программе иницилизатор случайных чисел qsrand.
     Рекомендую так:
     qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);
    Пример использования:

    ///////////////////////////////
    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS;//путь к папке

    QString Html;
    Html=HQt_BeginHtml ();

    int N1=6;
    double *dataX1=new double [N1];
    double *dataY1=new double [N1];
    dataX1[0]=7;dataY1[0]=6;
    dataX1[1]=8;dataY1[1]=4;
    dataX1[2]=10;dataY1[2]=7;
    dataX1[3]=5;dataY1[3]=12;
    dataX1[4]=14;dataY1[4]=4;
    dataX1[5]=13;dataY1[5]=8;

    int N2=3;
    double *dataX2=new double [N1];
    double *dataY2=new double [N2];
    dataX2[0]=1;dataY2[0]=8;
    dataX2[1]=2;dataY2[1]=4;
    dataX2[2]=3;dataY2[2]=5;

    Html += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,N1,dataX2,dataY2,N2);

    delete []dataX1;
    delete []dataY1;
    delete []dataX2;
    delete []dataY2;

    Html+=HQt_EndHtml();
    HQt_SaveFile(Html, path+"temp.html");
    ui->webView->setUrl(QUrl::fromLocalFile(path+"temp.html"));
    ///////////////////////////////
    */
    return THQt_ShowTwoIndependentChartsOfPointsAndLine (VHQt_VectorX1,VHQt_VectorY1,VHQt_N1,VHQt_VectorX2,VHQt_VectorY2, VHQt_N2, "", "x", "y","", "",true,false,false,true);
}
//---------------------------------------------------------------------------

//*****************************************************************
//Показ математических выражений
//*****************************************************************
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><b>"+TitleMatrix+":</b>";

    VHQt_Result+="<table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameMatrix;
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        for (int j=0;j<VHQt_M;j++)
            VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Matrix[i][j])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameMatrix;
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        for (int j=0;j<VHQt_M;j++)
            VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Matrix[i][j])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+="x";
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        for (int j=0;j<VHQt_M;j++)
            VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Matrix[i][j])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowNumber (T VHQt_X, QString TitleX, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result="<p><b>"+TitleX+":</b><br>";

    VHQt_Result+=NameX+"=<b><font class=\"number\">"+QString::number(VHQt_X)+"</font></b></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowNumber (T VHQt_X, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_X - выводимое число;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result="<p>"+NameX+"=<b><font class=\"number\">"+QString::number(VHQt_X)+"</font></b></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowNumber (T VHQt_X)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_X - выводимое число.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result="<p>x=<b><font class=\"number\">"+QString::number(VHQt_X)+"</font></b></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><b>"+TitleVector+":</b>";

    VHQt_Result+="<table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameVector;
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Vector[i])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameVector;
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Vector[i])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowVector (T *VHQt_Vector, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+="x";
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+="<tr>\n";
        VHQt_Result+="<td class=\"number\">"+QString::number(VHQt_Vector[i])+"</td>\n";

        VHQt_Result+="</tr>\n";
    }

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector в траснпонированном виде с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><b>"+TitleVector+":</b>";

    VHQt_Result+="<table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameVector;
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    VHQt_Result+="<tr>\n";
    for (int i=0;i<VHQt_N;i++)
        VHQt_Result+="<td>"+QString::number(VHQt_Vector[i])+"</td>\n";
    VHQt_Result+="</tr>\n";

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"Tsmall\">ᵀ</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector в траснпонированном виде с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+=NameVector;
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    VHQt_Result+="<tr>\n";
    for (int i=0;i<VHQt_N;i++)
        VHQt_Result+="<td>"+QString::number(VHQt_Vector[i])+"</td>\n";
    VHQt_Result+="</tr>\n";

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"Tsmall\">ᵀ</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_ShowVectorT (T *VHQt_Vector, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector в траснпонированном виде с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+="x";
    VHQt_Result+="</font> = \n";
    VHQt_Result+="</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrixbrak\">\n";
    VHQt_Result+="<tr>\n";
    VHQt_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VHQt_Result+="<td>\n";
    VHQt_Result+="<table class=\"matrix\">\n";

    VHQt_Result+="<tr>\n";
    for (int i=0;i<VHQt_N;i++)
        VHQt_Result+="<td>"+QString::number(VHQt_Vector[i])+"</td>\n";
    VHQt_Result+="</tr>\n";

    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"rbrak\">&nbsp;</td>\n";
    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table>\n";
    VHQt_Result+="</td>\n";
    VHQt_Result+="<td class=\"Tsmall\">ᵀ</td>\n";

    VHQt_Result+="</tr>\n";
    VHQt_Result+="</table></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

//*****************************************************************
//Показ текста
//*****************************************************************
template <class T> QString THQt_NumberToText (T VHQt_X)
{
    /*
    Функция выводит число VHQt_X в строку.
    Входные параметры:
     VHQt_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VHQt_Result;
    VHQt_Result="<b><font class=\"number\">"+QString::number(VHQt_X)+"</font></b>";
    return VHQt_Result;
}
//---------------------------------------------------------------------------
#endif // HARRIXQTLIBRARYFORQWEBVIEW_H
