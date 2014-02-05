//HarrixQtLibraryForQWebView
//Версия 1.13
//Библиотека для отображения различных данных в QWebView.
//https://github.com/Harrix/HarrixQtLibraryForQWebView
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibraryForQWebView.h"

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
