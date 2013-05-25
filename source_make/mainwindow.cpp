#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardItemModel>

#include "QtHarrixLibrary.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Сборка проекта Harrix Math Library

    ui->textEdit->clear();

    QString DS=QDir::separator();
    QString path=QGuiApplication::applicationDirPath()+DS+".."+DS+"source_library"+DS;//путь к папке
    QString temp_library_path;//папка где находятся собранные файлы
    temp_library_path=QGuiApplication::applicationDirPath()+DS+".."+DS+"temp_library"+DS;//путь к папке

    if (!(QDir(temp_library_path).exists()==true) )
    {
        QDir().mkdir(temp_library_path);
    }

    if (!(QDir(temp_library_path+DS+"images"+DS).exists()==true) )
    {
        QDir().mkdir(temp_library_path+DS+"images"+DS);
    }

    QString ResultCpp="";//итоговый cpp документ
    QString ResultTpp="";//сюда пишем шаблоны, которые потом воткнем в h файл
    QString ResultH="";//итоговый h файл
    QString ResultTex="";//итоговый cpp документ
    QString ResultTexList="";//временный список функций
    QString ResultTexFunctions="";//временная перемнная для справки по функциям
    QString Temp;//переменная для временного содержания загружаемых файлов
    int countoferrors=0;//количество ошибок
    int countneed;//количество рассмотренных нами файлов
    int countcpp=0;//количество функций в виде cpp файлов
    int counth=0;//количество функций в виде h файлов
    int counttex=0;//количество функций в виде tex файлов
    int countdesc=0;//количество функций в виде desc файлов
    int countpng=0;//количество функций в виде png файлов
    int countpdf=0;//количество функций в виде pdf файлов
    int countuse=0;//количество функций в виде use файлов
    bool b;
    ui->textEdit->insertHtml("<font color=\"#858585\">Начало формирования файлов библиотеки...<\font><br>");

    ResultH += "#ifndef MATHHARRIXLIBRARY_H\n";
    ResultH += "#define MATHHARRIXLIBRARY_H\n";

    ResultTpp += "//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    ResultTpp += "// РЕАЛИЗАЦИЯ ШАБЛОНОВ\n";//добавляем название папки (раздела)
    ResultTpp += "//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

    Temp = HQt_ReadFile(path+"Header.cpp")+"\n\n";//основа cpp файла
    ResultCpp += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Header.cpp</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Header.cpp</b><\font><br>");countoferrors++;}

    Temp = HQt_ReadFile(path+"AdditionalVariables.cpp")+"\n\n";//дополнительные глобальные переменные
    ResultCpp += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>AdditionalVariables.cpp</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>AdditionalVariables.cpp</b><\font><br>");countoferrors++;}


    Temp = HQt_ReadFile(path+"Random.cpp")+"\n\n";//две основные функции по случайнм числам
    ResultCpp += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Random.cpp</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Random.cpp</b><\font><br>");countoferrors++;}

    Temp = HQt_ReadFile(path+"Const.h")+"\n\n";//константы
    ResultH += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Const.h</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Const.h</b><\font><br>");countoferrors++;}

    Temp = HQt_ReadFile(path+"Random.h")+"\n\n";//две основные функции по случайнм числам
    ResultH += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Random.h</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Random.h</b><\font><br>");countoferrors++;}

    Temp = HQt_ReadFile(path+"Enum.h")+"\n\n";//переменные перечисляемого типа
    ResultH += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Enum.h</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Enum.h</b><\font><br>");countoferrors++;}

    Temp = HQt_ReadFile(path+"Install.tex")+"\n\n";//содержит информацию об установке и использованию библиотеки
    ResultTex += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Install.tex</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Install.tex</b><\font><br>");countoferrors++;}

    Temp = HQt_ReadFile(path+"Random.tex")+"\n\n";//информация о случайных числах в библиотеке
    ResultTex += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Random.tex</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Random.tex</b><\font><br>");countoferrors++;}

    Temp = HQt_ReadFile(path+"Addnew.tex")+"\n\n";//информация о том, как добавлять новые функции в библиотеку
    ResultTex += Temp;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Addnew.tex</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Addnew.tex</b><\font><br>");countoferrors++;}

    ResultH += "//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    ResultH += "// ОБЪЯВЛЕНИЯ ФУНКЦИЙ\n";//добавляем название папки (раздела)
    ResultH += "//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

    //дополнительные переменные
    QString dirname,filename,path2,exp;
    QStringList listfiles,listdirs;
    int i,j,n,m;

    //Теперь начинаем пробегать по всем папкам
    listdirs = HQt_ListDirsInDirQStringList(path);//список папок

    n=listdirs.count();//количество папок разделов
    ui->textEdit->insertHtml("<br>Было найдено  <b>"+QString::number(n)+"</b> папок - разделов библиотеки<br>");
    if (n==0) {ui->textEdit->insertHtml("<font color=\"red\">Не найдены разделы библиотек. Это очень плохо.<\font><br>");countoferrors++;}

    ResultTexList="\\newpage\n\\section{Список функций}\\label{section_listfunctions}\n";
    ResultTexFunctions="\\newpage\n\\section{Функции}\n";

    for (i=0;i<n;i++)//пробегаем по всем разделам
    {
        dirname=listdirs.at(i);//получаем имя папки
        path2=path+dirname+"/";
        ui->textEdit->insertHtml("<br>Рассматриваем папку <b>"+dirname+"</b>");

        listfiles=HQt_ListFilesInDirQStringList(path2);//список файлов в папке

        m=listfiles.count();//количество файлов в папке
        ui->textEdit->insertHtml("<br>Было найдено  <b>"+QString::number(m)+"</b> файлов в папке<br><br>");
        if (m==0) {ui->textEdit->insertHtml("<font color=\"red\">Не найдены файлы в разделе. То есть в разделе нет функций?<\font><br>");countoferrors++;}


        ResultCpp += "//*****************************************************************\n";
        ResultCpp += "//"+dirname+"\n";//добавляем название папки (раздела)
        ResultCpp += "//*****************************************************************\n";

        ResultTpp += "//*****************************************************************\n";
        ResultTpp += "//"+dirname+"\n";//добавляем название папки (раздела)
        ResultTpp += "//*****************************************************************\n";

        ResultH   += "//"+dirname+"\n";//добавляем название папки (раздела)

        ResultTexList += "\\textbf{"+dirname+"}\n";
        ResultTexList += "\\begin{enumerate}\n\n";

        ResultTexFunctions += "\\subsection{"+dirname+"}\n\n";

        countneed=0;

        for (j=0;j<m;j++)//пробегаем по файлам папки
        {
            filename=listfiles.at(j);//получаем имя файла
            exp=HQt_GetExpFromFilename(filename);//расширение файла

            if (exp=="desc")
            {
                countneed++;
                countdesc++;

                QString nameof_func=HQt_GetNameFromFilename(filename);//имя функции по названию файла
                QString nameof_func_=nameof_func;//имя функции с преобразованными знаками _
                nameof_func_=nameof_func_.replace("_","\\_");

                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла

                ResultTexList += "\\item \\textbf{\\hyperref[" + nameof_func + "]{" + nameof_func_ + "}} --- " + Temp+"\n";

                ResultTexFunctions+="\\subsubsection{" + nameof_func_ + "}\\label{"+nameof_func+"}\n\n" + Temp+"\n\n";

                if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>");countoferrors++;}

                //Проверим наличие сопутствующих файлов
                QString F=HQt_GetNameFromFilename(filename);
                if (HQt_FileExists(path2+F+".h")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".h</b> файл<\font><br>");countoferrors++;}
                if ((HQt_FileExists(path2+F+".cpp")==false)&&(HQt_FileExists(path2+F+".tpp")==false)) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".cpp</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".tex")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".tex</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".use")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".use</b> файл<\font><br>");countoferrors++;}

            }
            if ((exp=="cpp")||(exp=="tpp"))
            {
                countneed++;
                countcpp++;

                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла в cpp файл

                if (exp=="cpp")
                {
                    ResultCpp += Temp;
                    ResultCpp += "//---------------------------------------------------------------------------\n";
                    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>");countoferrors++;}
                }

                if (exp=="tpp")
                {
                    ResultTpp += Temp;
                    ResultTpp += "//---------------------------------------------------------------------------\n";
                    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>");countoferrors++;}
                }

                //Проверим наличие сопутствующих файлов
                QString F=HQt_GetNameFromFilename(filename);
                if (HQt_FileExists(path2+F+".h")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".h</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".desc")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".desc</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".tex")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".tex</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".use")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".use</b> файл<\font><br>");countoferrors++;}
            }
            if (exp=="h")
            {
                countneed++;
                counth++;

                QString nameof_func=HQt_GetNameFromFilename(filename);//имя функции по названию файла
                //QString nameof_func_=nameof_func;//имя функции с преобразованными знаками _
                //nameof_func_=nameof_func_.replace("_","\\_");


                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла в h файл
                ResultH += Temp;
                if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>");countoferrors++;}

                ResultTexFunctions+="\\begin{lstlisting}[label=code_syntax_"+nameof_func+",caption=Синтаксис]\n";
                ResultTexFunctions+=Temp;
                ResultTexFunctions+="\\end{lstlisting}\n\n";

                //Проверим наличие сопутствующих файлов
                QString F=HQt_GetNameFromFilename(filename);
                if ((HQt_FileExists(path2+F+".cpp")==false)&&(HQt_FileExists(path2+F+".tpp")==false)) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".cpp</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".desc")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".desc</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".tex")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".tex</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".use")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".use</b> файл<\font><br>");countoferrors++;}
            }
            if (exp=="tex")
            {
                countneed++;
                counttex++;

                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла

                ResultTexFunctions+=Temp+"\n\n";

                if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>");countoferrors++;}

                //Проверим наличие сопутствующих файлов
                QString F=HQt_GetNameFromFilename(filename);
                if (HQt_FileExists(path2+F+".h")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".h</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".desc")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".desc</b> файл<\font><br>");countoferrors++;}
                if ((HQt_FileExists(path2+F+".cpp")==false)&&(HQt_FileExists(path2+F+".tpp")==false)) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".cpp</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".use")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".use</b> файл<\font><br>");countoferrors++;}
            }
            if (exp=="png")
            {
                countneed++;
                countpng++;

                b=HQt_CopyFile(path2+filename, temp_library_path+DS+"images"+DS,true);
                if (b) ui->textEdit->insertHtml("Скопировали файл <b>"+filename+"</b><br>");
                else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>");countoferrors++;}
            }
            if (exp=="pdf")
            {
                countneed++;
                countpdf++;

                b=HQt_CopyFile(path2+filename, temp_library_path+DS+"images"+DS,true);
                if (b) ui->textEdit->insertHtml("Скопировали файл <b>"+filename+"</b><br>");
                else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>");countoferrors++;}
            }
            if (exp=="use")
            {
                countneed++;
                countuse++;

                QString nameof_func=HQt_GetNameFromFilename(filename);//имя функции по названию файла
                QString nameof_func_=nameof_func;//имя функции с преобразованными знаками _
                nameof_func_=nameof_func_.replace("_","\\_");

                Temp = HQt_ReadFile(path2+filename)+"\n";//добавляем текст файла

                ResultTexFunctions+="\\begin{lstlisting}[label=code_use_"+nameof_func+",caption=Пример использования]\n";
                ResultTexFunctions+=Temp;
                ResultTexFunctions+="\\end{lstlisting}\n\n";


                if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>"+filename+"</b><br>");
                else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>"+filename+"</b><\font><br>");countoferrors++;}

                //Проверим наличие сопутствующих файлов
                QString F=HQt_GetNameFromFilename(filename);
                if (HQt_FileExists(path2+F+".h")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".h</b> файл<\font><br>");countoferrors++;}
                if ((HQt_FileExists(path2+F+".cpp")==false)&&(HQt_FileExists(path2+F+".tpp")==false)) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".cpp</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".tex")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".tex</b> файл<\font><br>");countoferrors++;}
                if (HQt_FileExists(path2+F+".desc")==false) {ui->textEdit->insertHtml("<font color=\"red\">Не обнаружен <b>"+F+".desc</b> файл<\font><br>");countoferrors++;}

            }

            QGuiApplication::processEvents();

            QTextCursor c =  ui->textEdit->textCursor();
            c.movePosition(QTextCursor::End);
            ui->textEdit->setTextCursor(c);
        }

        ui->textEdit->insertHtml("Из <b>"+QString::number(m)+"</b> файлов нужными нам оказалось <b>"+QString::number(countneed)+"</b> файлов в папке<br>");

        ResultCpp += "\n";
        ResultH   += "\n";

        ResultTexList += "\\end{enumerate}\n\n";

    }

    ResultH += ResultTpp;

    ResultTex+=ResultTexList+"\n";
    ResultTex+=ResultTexFunctions;
    ResultTex+="\\newpage\n\n\\end{document}";


    Temp = HQt_ReadFile(path+"Description_part2.tex")+"\n\n";//описание библиотеки
    ResultTex = Temp+ResultTex;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("<br>Загрузили файл <b>Description_part2.tex</b><br>");
    else {ui->textEdit->insertHtml("<br><font color=\"red\">Ошибка с файлом <b>Description_part2.tex</b><\font><br>");countoferrors++;}

    ResultTex=QString::number(countcpp)+ResultTex;

    Temp = HQt_ReadFile(path+"Description_part1.tex");//описание библиотеки
    ResultTex = Temp+ResultTex;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Description_part1.tex</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Description_part1.tex</b><\font><br>");countoferrors++;}

    Temp = HQt_ReadFile(path+"Title.tex")+"\n\n";// титульная информация и содержание справки
    ResultTex = Temp+ResultTex;
    if (!(Temp.trimmed().isEmpty())) ui->textEdit->insertHtml("Загрузили файл <b>Title.tex</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>Title.tex</b><\font><br>");countoferrors++;}

    ResultH += "\n#endif // MATHHARRIXLIBRARY_H";

    HQt_SaveFile(ResultCpp,temp_library_path+"MathHarrixLibrary.cpp");
    ui->textEdit->insertHtml("<br>Сохранили файл <b>MathHarrixLibrary.cpp</b><br>");
    HQt_SaveFile(ResultH,temp_library_path+"MathHarrixLibrary.h");
    ui->textEdit->insertHtml("Сохранили файл <b>MathHarrixLibrary.h</b><br>");

    HQt_SaveFile(ResultTex,temp_library_path+"MathHarrixLibrary_Help.tex");
    ui->textEdit->insertHtml("Сохранили файл <b>MathHarrixLibrary_Help.tex</b><br>");

    //Начнем копирование некоторых файлов целиком
    b=HQt_CopyFile(path+"names.tex", temp_library_path,true);
    if (b) ui->textEdit->insertHtml("<br>Скопировали файл <b>names.tex</b>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>names.tex</b><\font><br>");countoferrors++;}

    b=HQt_CopyFile(path+"packages.tex", temp_library_path,true);
    if (b) ui->textEdit->insertHtml("<br>Скопировали файл <b>packages.tex</b>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>packages.tex</b><\font><br>");countoferrors++;}

    b=HQt_CopyFile(path+"styles.tex", temp_library_path,true);
    if (b)  ui->textEdit->insertHtml("<br>Скопировали файл <b>styles.tex</b><br>");
    else {ui->textEdit->insertHtml("<font color=\"red\">Ошибка с файлом <b>styles.tex</b><\font><br>");countoferrors++;}

    if (countoferrors==0) ui->textEdit->insertHtml("<br>Ошибки не были зафиксированы.<br>");
    else ui->textEdit->insertHtml("<br><font color=\"red\">Ошибок <b>"+QString::number(countoferrors)+"</b> штук<\font><br>");

    ui->textEdit->insertHtml("<font color=\"#858585\">Конец формирования файлов библиотеки.<\font><br>");

    QTextCursor c =  ui->textEdit->textCursor();
    c.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(c);

    //открытие папки с собранными файлами
    QDesktopServices::openUrl(QUrl::fromLocalFile(temp_library_path));
}
