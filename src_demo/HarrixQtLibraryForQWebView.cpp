//HarrixQtLibraryForQWebView
//Версия 1.16
//Библиотека для отображения различных данных в QWebView.
//https://github.com/Harrix/HarrixQtLibraryForQWebView
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibraryForQWebView.h"

QString VHQt_HTML;
QString VHQt_Path;

//*****************************************************************
//Главные загрузочные функции
//*****************************************************************
void HQt_AddHtml(QString Html)
{
    /*
    Функция добавляет код html к существующему и сохраняет его в temp.html.
    Входные параметры:
     Html - добавляемый текст.
    Возвращаемое значение:
     Отсутствует.
    */
    VHQt_HTML+=Html;
    HQt_SaveFile(VHQt_HTML, VHQt_Path+"temp.html");
}
//---------------------------------------------------------------------------

void HQt_BeginHtml(QString Path)
{
    /*
    Функция обнуляет переменную HTML. Требуется когда нужно перезапустить показ информации в QWebView.
    Входные параметры:
     Path - путь к папке, в которой надо будет сохранять html код. В этой папке должен содержаться файл index.html
    Возвращаемое значение:
     Отсутствует.
    */
    VHQt_HTML="";
    VHQt_Path=QDir::toNativeSeparators(Path);
    if (VHQt_Path.at(VHQt_Path.length()-1)!='\\') VHQt_Path+="\\";
    HQt_SaveFile(VHQt_HTML, VHQt_Path+"temp.html");//сохраняем пустую пока переменную в temp.html
}
//---------------------------------------------------------------------------


//*****************************************************************
//Показ графиков
//*****************************************************************
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
    QString VHQt_Result;

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

    VHQt_Result += THQt_ShowChartOfLine (dataX,dataY,N,TitleChart,NameVectorX,NameVectorY,NameLine,ShowLine,ShowPoints,ShowArea,ShowSpecPoints,RedLine);

    delete []dataX;
    delete []dataY;

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result += HQt_DrawLine (Left, Right, h, Function, TitleChart, NameVectorX, NameVectorY, "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine);

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result += HQt_DrawLine (Left, Right, h, Function, TitleChart, NameVectorX, NameVectorY, NameLine, true, false, false, true, true);

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result += HQt_DrawLine (Left, Right, h, Function, "", "x", "y", true, false, false, true, true);

    return VHQt_Result;
}
//---------------------------------------------------------------------------


//*****************************************************************
//Показ математических выражений
//*****************************************************************
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
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
        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            QString B=VHQt_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VHQt_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
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
        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            QString B=VHQt_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VHQt_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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
QString THQt_ShowMatrix (QStringList *VHQt_Matrix, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с HTML кодами. Для добавление в html файл.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк. Каждый
    QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="<p><table>\n";
    VHQt_Result+="<tr>\n";

    VHQt_Result+="<td class=\"middle\">\n";
    VHQt_Result+="<font class=\"overline\">";
    VHQt_Result+="";
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
        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            QString B=VHQt_Matrix[i].at(j);
            if (B!=B.trimmed()) B="→|"+B+"|←";
            B=B.replace(" ","&nbsp;");
            VHQt_Result+="<td class=\"number\">"+B+"</td>\n";
        }

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

QString THQt_ShowVector (QStringList VHQt_Vector, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого списка строк VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на список строк QStringList;
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

    for (int i=0;i<VHQt_Vector.count();i++)
    {
        VHQt_Result+="<tr>\n";
        QString B=VHQt_Vector.at(i);
        if (B!=B.trimmed()) B="→|"+B+"|←";
        B=B.replace(" ","&nbsp;");
        VHQt_Result+="<td class=\"number\">"+B+"</td>\n";

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
QString THQt_ShowVector (QStringList VHQt_Vector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого списка строк VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на список строк QStringList;
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

    for (int i=0;i<VHQt_Vector.count();i++)
    {
        VHQt_Result+="<tr>\n";
        QString B=VHQt_Vector.at(i);
        if (B!=B.trimmed()) B="→|"+B+"|←";
        B=B.replace(" ","&nbsp;");
        VHQt_Result+="<td class=\"number\">"+B+"</td>\n";

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
QString THQt_ShowVector (QStringList VHQt_Vector)
{
    /*
    Функция возвращает строку с выводом некоторого списка строк VHQt_Vector с HTML кодами. Для добавление в html файл.
    Входные параметры:
     VHQt_Vector - указатель на список строк QStringList;
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

    for (int i=0;i<VHQt_Vector.count();i++)
    {
        VHQt_Result+="<tr>\n";
        QString B=VHQt_Vector.at(i);
        if (B!=B.trimmed()) B="→|"+B+"|←";
        B=B.replace(" ","&nbsp;");

        VHQt_Result+="<td class=\"number\">"+B+"</td>\n";

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


//*****************************************************************
//Показ текста
//*****************************************************************
QString HQt_ShowAlert (QString String)
{
    /*
    Функция возвращает строку с выводом некоторого предупреждения. Для добавление в html файл.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимым предупреждением.
    */
    QString VHQt_Result;

    VHQt_Result="<div style=\"background: #ffdfdf url(images/box-alert.png) no-repeat 16px; border-color: #feabab;color: #c31b00;padding: 15px 20px 15px 55px;-webkit-border-radius: 5px;-moz-border-radius: 5px;border-radius: 5px;border: 1px solid;clear: both;margin: 15px 0;-webkit-box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;-moz-box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;box-shadow: 0 0 3px rgba(0, 0, 0, 0.1), 0 1px 0 #FFFFFF inset, 0 -1px 0 #FFFFFF inset;text-align: justify; width:600px;\">"+String+"</div>\n";

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result="<h1>"+String+"</h1>\n";

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result="<hr>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------

QString HQt_ShowSimpleText (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки с HTML кодами без всякого излишества. Для добавление в html файл.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с HTML кодами с выводимой строкой.
    */
    QString VHQt_Result;

    VHQt_Result="<p>"+String+"</p>\n";

    return VHQt_Result;
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
    QString VHQt_Result;

    VHQt_Result="<p><b>"+TitleX+".</b></p>\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
