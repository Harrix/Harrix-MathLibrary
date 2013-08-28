//Библиотека для отображения различных данных в QWebView. Версия v.1.8.
//https://github.com/Harrix/QtHarrixLibraryForQWebView
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "QtHarrixLibraryForQWebView.h"

QString VMHL_HTML;
QString VMHL_Path;

//Функции для получения HTML кода для вывода в webView

void HQt_BeginHtml(QString Path)
{
    /*
    Функция обнуляет переменную HTML. Требуется когда нужно перезапустить показ информации в QWebView.
    Входные параметры:
     Path - путь к папке, в которой надо будет сохранять html код. В этой папке должен соддержаться файл index.html
    Возвращаемое значение:
     Отсутствует.
    */
    VMHL_HTML="";
    VMHL_Path=Path;
    HQt_SaveFile(VMHL_HTML, VMHL_Path+"temp.html");//сохраняем пустую пока переменную в temp.html
    HQt_SaveFile(HQt_RandomString(5), Path+"marker.html");
}
//---------------------------------------------------------------------------

void HQt_AddHtml(QString Html)
{
    /*
    Функция добавляет код html к существующему и сохраняет его в temp.html.
    Входные параметры:
     Html - добавляемый текст.
    Возвращаемое значение:
     Отсутствует.
    */
    VMHL_HTML+=Html;
    HQt_SaveFile(VMHL_HTML, VMHL_Path+"temp.html");
    //добавим маркер того, что что-то добавилось, чтобы скрипт в index.html обновил информацию из temp.html.
    HQt_SaveFile(HQt_RandomString(5), VMHL_Path+"marker.html");
}
//---------------------------------------------------------------------------

QString HQt_ShowText (QString TitleX)
{
    /*
    Функция возвращает строку с выводом некоторой строки с HTML кодами. Для добавление в html файл.
    Входные параметры:
     TitleX - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="<p><b>"+TitleX+".</b></p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_ShowSimpleText (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки с HTML кодами без всякого излишевства. Для добавление в html файл.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="<p>"+String+"</p>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_ShowH1 (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде заголовка. Для добавление в html файл.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="<h1>"+String+"</h1>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_ShowHr ()
{
    /*
    Функция возвращает строку с выводом горизонтальной линии. Для добавление в html файл.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с HTML кодами с тэгом hr.
    */
    QString VMHL_Result;

    VMHL_Result="<hr>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_ShowAlert (QString String)
{
    /*
    Функция возвращает строку с выводом некоторого предупреждения. Для добавление в html файл.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым предупреждением.
    */
    QString VMHL_Result;

    VMHL_Result="<div style=\"background: #ffdfdf url(images/box-alert.png) no-repeat 16px; border-color: #feabab;color: #c31b00;padding: 15px 20px 15px 55px;-webkit-border-radius: 5px;-moz-border-radius: 5px;border-radius: 5px;border: 1px solid;clear: both;margin: 15px 0;-webkit-box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;-moz-box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;text-align: justify; width:600px;\">"+String+"</div>\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_ReadHdataToHtmlChart (QString filename)
{
    /*
    Функция возвращает строку с HTML кодом графика в результате считывания информации из *.hdata
    версии Harrix Data 1.0. Для добавление в html файл.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     Строка с HTML кодом.
    */
    QString VMHL_Result;

    try
    {
        if (HQt_GetExpFromFilename(filename)!="hdata")
        {
            VMHL_Result+=HQt_ShowAlert ("Расширение файла не *.hdata.");
            return VMHL_Result;
        }
        if (!HQt_FileExists(filename))
        {
            VMHL_Result+=HQt_ShowAlert ("Файл отсутствует.");
            return VMHL_Result;
        }

        QStringList List = HQt_ReadFileToQStringList(filename);

        if (List.isEmpty())
        {
            VMHL_Result+=HQt_ShowAlert ("Файл пустой.");
            return VMHL_Result;
        }

        QString String;

        String=List.at(0);

        if (HQt_TextBeforeEqualSign (String)!="HarrixFileFormat")
        {
            VMHL_Result+=HQt_ShowAlert ("Это не формат HarrixFileFormat.");
            return VMHL_Result;
        }
        if (HQt_TextAfterEqualSign (String)!="Harrix Data 1.0")
        {
            VMHL_Result+=HQt_ShowAlert ("Это не версия Harrix Data 1.0.");
            return VMHL_Result;
        }

        List.removeFirst();
        String=List.at(0);

        if (HQt_TextBeforeEqualSign (String)!="Site")
        {
            VMHL_Result+=HQt_ShowAlert ("Ошибка в структуре файла: нет второй строки в виде ссылки на сайт.");
            return VMHL_Result;
        }
        if (HQt_TextAfterEqualSign (String)!="https://github.com/Harrix/HarrixFileFormats")
        {
            VMHL_Result+=HQt_ShowAlert ("Ошибка в структуре файла: сайт указан неверно во второй строке.");
            return VMHL_Result;
        }

        //параметры по умолчанию
        QString Type;
        QString Title;
        QString AxisX;
        QString AxisY;
        bool ShowLine=false;
        bool ShowPoints=false;
        bool ShowArea=false;
        bool ShowSpecPoints=false;
        bool RedLine=false;

        //предварительные переменные
        QString TempType;
        QString TempTitle;
        QString TempAxisX;
        QString TempAxisY;
        QString TempParameters;

        QString After;
        QString Before;

        List.removeFirst();

        //проанализируем строчки на наличие тех переменных, которые могут быть необязательными
        int i=0;
        int n=List.count();
        while ((i<n)&&(String!="BeginNamesOfCharts")&&(String!="BeginData"))
        {
            String = List.at(i);
            Before = HQt_TextBeforeEqualSign (String);
            After  = HQt_TextAfterEqualSign (String);

            if (Before=="Type") TempType=After;
            if (Before=="Title") TempTitle=After;
            if (Before=="AxisX") TempAxisX=After;
            if (Before=="AxisY") TempAxisY=After;
            if (Before=="Parameters") TempParameters=After;
            i++;
        }

        for (int j=0;j<i-1;j++) List.removeFirst();//удалим строчки, которые проанализировали

        //А теперь сами переменные проанализируем
        Title=TempTitle;
        AxisX=TempAxisX;
        AxisY=TempAxisY;

        if (TempType=="Line") Type="Line";
        if (TempType=="TwoLines") Type="TwoLines";
        if (TempType=="TwoIndependentLines") Type="TwoIndependentLines";
        if (TempType=="SeveralIndependentLines") Type="SeveralIndependentLines";
        if (TempType=="SeveralLines") Type="SeveralLines";
        if (TempType=="PointsAndLine") Type="PointsAndLine";

        QStringList ListParameters = TempParameters.split( ",", QString::SkipEmptyParts );
        for (int j=0;j<ListParameters.count();j++)
        {
            String=ListParameters.at(j);
            String=String.trimmed();
            if (String=="ShowLine") ShowLine=true;
            if (String=="ShowPoints") ShowPoints=true;
            if (String=="ShowArea") ShowArea=true;
            if (String=="ShowSpecPoints") ShowSpecPoints=true;
            if (String=="RedLine") RedLine=true;
        }

        if ((ShowLine==false)&&(ShowPoints==false)) ShowLine=true;


        //Теперь пытаемся поискать и обработать названия столбцов
        QStringList ListNamesOfCharts;
        String=List.at(0);
        i=0;
        if (String=="BeginNamesOfCharts")
        {
            int n=List.count();
            while ((i<n)&&(String!="EndNamesOfCharts")&&(String!="BeginData"))
            {
                String = List.at(i);

                if ((String!="BeginNamesOfCharts")&&(String!="EndNamesOfCharts")&&(String!="BeginData")&&(String!="EndData"))
                    ListNamesOfCharts << String;

                i++;
            }
        }

        for (int j=0;j<i;j++) List.removeFirst();//удалим строчки, которые проанализировали

        //Заберем данные непосредственно
        String=List.at(0);
        if (String=="BeginData")
        {

            if (List.at(List.count()-1)!="EndData")
            {
                VMHL_Result+=HQt_ShowAlert ("Ошибка в структуре файла: нет в конце строчки EndData.");
                return VMHL_Result;
            }
            List.removeFirst();
            List.removeLast();
            //теперь в List находитсz только нормальный объем данных
        }
        else
        {
            VMHL_Result+=HQt_ShowAlert ("Ошибка в структуре файла: нет строчки BeginData.");
            return VMHL_Result;
        }

        //Теперь можем наконец работать с выводом графиков согласно типу
        if (Type=="Line")
        {
            int N=HQt_CountOfRowsFromQStringList(List);
            double *dataX=new double [N];
            double *dataY=new double [N];
            THQt_ReadTwoVectorFromQStringList(List,dataX,dataY);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";

            VMHL_Result += THQt_ShowChartOfLine (dataX,dataY,N,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ShowLine,ShowPoints,ShowArea,ShowSpecPoints,RedLine);

            delete []dataX;
            delete []dataY;
        }
        if (Type=="TwoLines")
        {
            int N=HQt_CountOfRowsFromQStringList(List);
            double *dataX=new double [N];
            double *dataY1=new double [N];
            double *dataY2=new double [N];

            THQt_ReadColFromQStringList(List,0,dataX);
            THQt_ReadColFromQStringList(List,1,dataY1);
            THQt_ReadColFromQStringList(List,2,dataY2);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
            if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";

            VMHL_Result += THQt_ShowTwoChartsOfLine (dataX,dataY1,dataY2,N,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),ShowLine,ShowPoints,ShowArea,ShowSpecPoints);

            delete []dataX;
            delete []dataY1;
            delete []dataY2;
        }
        if (Type=="TwoIndependentLines")
        {
            int NX1=HQt_CountOfRowsFromQStringList(List,0);
            int NY1=HQt_CountOfRowsFromQStringList(List,1);
            int NX2=HQt_CountOfRowsFromQStringList(List,2);
            int NY2=HQt_CountOfRowsFromQStringList(List,3);
            double *dataX1=new double [NX1];
            double *dataY1=new double [NY1];
            double *dataX2=new double [NX2];
            double *dataY2=new double [NY2];

            THQt_ReadColFromQStringList(List,0,dataX1);
            THQt_ReadColFromQStringList(List,1,dataY1);
            THQt_ReadColFromQStringList(List,2,dataX2);
            THQt_ReadColFromQStringList(List,3,dataY2);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
            if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";

            VMHL_Result += THQt_ShowTwoIndependentChartsOfLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),ShowLine,ShowPoints,ShowArea,ShowSpecPoints);

            delete []dataX1;
            delete []dataX2;
            delete []dataY1;
            delete []dataY2;
        }
        if (Type=="SeveralLines")
        {
            int N,M;

            M=HQt_CountOfColsFromQStringList(List);

            int *N_EveryCol=new int[M];

            N=HQt_CountOfRowsFromQStringList(List,N_EveryCol);

            double **X;
            X=new double*[N];
            for (int i=0;i<N;i++) X[i]=new double[M];

            THQt_ReadMatrixFromQStringList(List, X);

            if (ListNamesOfCharts.count()<M-1)
                for (int j=0;j<M-1-ListNamesOfCharts.count();j++) ListNamesOfCharts << "";

            QString *NameLine=new QString[M-1];
            for (int i=0;i<M-1;i++)NameLine[i]=ListNamesOfCharts.at(i);

            VMHL_Result += THQt_ShowChartsOfLineFromMatrix (X,N,M,Title,AxisX,AxisY,NameLine,ShowLine,ShowPoints,ShowArea,ShowSpecPoints);

            for (int i=0;i<N;i++) delete [] X[i];
            delete [] X;
            delete [] N_EveryCol;
            delete [] NameLine;
        }
        if (Type=="SeveralIndependentLines")
        {
            int N,M;

            M=HQt_CountOfColsFromQStringList(List);

            int *N_EveryCol=new int[M];

            N=HQt_CountOfRowsFromQStringList(List,N_EveryCol);

            double **X;
            X=new double*[N];
            for (int i=0;i<N;i++) X[i]=new double[M];

            THQt_ReadMatrixFromQStringList(List, X);

            if (ListNamesOfCharts.count()<M/2)
                for (int j=0;j<M/2-ListNamesOfCharts.count();j++) ListNamesOfCharts << "";

            QString *NameLine=new QString[M/2];
            for (int i=0;i<M/2;i++)NameLine[i]=ListNamesOfCharts.at(i);

            VMHL_Result += THQt_ShowIndependentChartsOfLineFromMatrix (X,N_EveryCol,M, Title,AxisX,AxisY,NameLine,ShowLine,ShowPoints,ShowArea,ShowSpecPoints);

            for (int i=0;i<N;i++) delete [] X[i];
            delete [] X;
            delete [] N_EveryCol;
            delete [] NameLine;
        }
        if (Type=="PointsAndLine")
        {
            int NX1=HQt_CountOfRowsFromQStringList(List,0);
            int NY1=HQt_CountOfRowsFromQStringList(List,1);
            int NX2=HQt_CountOfRowsFromQStringList(List,2);
            int NY2=HQt_CountOfRowsFromQStringList(List,3);
            double *dataX1=new double [NX1];
            double *dataY1=new double [NY1];
            double *dataX2=new double [NX2];
            double *dataY2=new double [NY2];

            THQt_ReadColFromQStringList(List,0,dataX1);
            THQt_ReadColFromQStringList(List,1,dataY1);
            THQt_ReadColFromQStringList(List,2,dataX2);
            THQt_ReadColFromQStringList(List,3,dataY2);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
            if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";

            VMHL_Result += THQt_ShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),ShowLine,ShowPoints,ShowArea,ShowSpecPoints);

            delete []dataX1;
            delete []dataX2;
            delete []dataY1;
            delete []dataY2;
        }
    }
    catch(...)
    {
        VMHL_Result+=HQt_ShowAlert ("Неизвестная ошибка.");
        VMHL_Result="";
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
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
     Строка с HTML кодом.
    */
    QString VMHL_Result;

    int N=(Right-Left)/h;
    double *dataX=new double [N];
    double *dataY=new double [N];

    double x=Left;
    for (int i=0;i<N;i++)
    {
        dataX[i]=x;
        dataY[i]=Function(x);

        x+=h;
    }

    VMHL_Result += THQt_ShowChartOfLine (dataX,dataY,N,TitleChart,NameVectorX,NameVectorY,NameLine,ShowLine,ShowPoints,ShowArea,ShowSpecPoints,RedLine);

    delete []dataX;
    delete []dataY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл.
    Отличается от основной функцией отсутствием параметра NameLine(название графика (для легенды)).
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с HTML кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_DrawLine (Left, Right, h, Function, TitleChart, NameVectorX, NameVectorY, "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine)
{
    /*
    Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл.
    Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с HTML кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_DrawLine (Left, Right, h, Function, TitleChart, NameVectorX, NameVectorY, NameLine, true, false, false, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_DrawLine (double Left, double Right, double h, double (*Function)(double))
{
    /*
    Функция возвращает строку с HTML кодом отрисовки линии по функции Function. Для добавление в html файл.
    Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox;
     NameVectorY - название оси Oy;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с HTML кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_DrawLine (Left, Right, h, Function, "", "x", "y", true, false, false, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_ShowVector (QStringList VMHL_Vector, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого списка строк VMHL_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Vector - указатель на список строк QStringList;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><b>"+TitleVector+":</b>";

    VMHL_Result+="<table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+=NameVector;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="<tr>\n";
        QString B=VMHL_Vector.at(i);
        if (B!=B.trimmed()) B="→|"+B+"|←";
        B=B.replace(" ","&nbsp;");
        VMHL_Result+="<td class=\"number\">"+B+"</td>\n";

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

QString THQt_ShowVector (QStringList VMHL_Vector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого списка строк VMHL_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Vector - указатель на список строк QStringList;
     VMHL_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+=NameVector;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="<tr>\n";
        QString B=VMHL_Vector.at(i);
        if (B!=B.trimmed()) B="→|"+B+"|←";
        B=B.replace(" ","&nbsp;");
        VMHL_Result+="<td class=\"number\">"+B+"</td>\n";

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

QString THQt_ShowVector (QStringList VMHL_Vector)
{
    /*
    Функция возвращает строку с выводом некоторого списка строк VMHL_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VMHL_Vector - указатель на список строк QStringList;
     VMHL_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+="x";
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="<tr>\n";
        QString B=VMHL_Vector.at(i);
        if (B!=B.trimmed()) B="→|"+B+"|←";
        B=B.replace(" ","&nbsp;");

        VMHL_Result+="<td class=\"number\">"+B+"</td>\n";

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

QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><b>"+TitleMatrix+":</b>";

    VMHL_Result+="<table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+=NameMatrix;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_N;i++)
    {
        VMHL_Result+="<tr>\n";
        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            QString B=VMHL_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VMHL_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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

QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+=NameMatrix;
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_N;i++)
    {
        VMHL_Result+="<tr>\n";
        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            QString B=VMHL_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VMHL_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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

QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице.
    Возвращаемое значение:
     Отсутствует.
    */
    QString VMHL_Result;

    VMHL_Result+="<p><table>\n";
    VMHL_Result+="<tr>\n";

    VMHL_Result+="<td class=\"middle\">\n";
    VMHL_Result+="<font class=\"overline\">";
    VMHL_Result+="";
    VMHL_Result+="</font> = \n";
    VMHL_Result+="</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrixbrak\">\n";
    VMHL_Result+="<tr>\n";
    VMHL_Result+="<td class=\"lbrak\">&nbsp;</td>\n";

    VMHL_Result+="<td>\n";
    VMHL_Result+="<table class=\"matrix\">\n";

    for (int i=0;i<VMHL_N;i++)
    {
        VMHL_Result+="<tr>\n";
        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            QString B=VMHL_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VMHL_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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
