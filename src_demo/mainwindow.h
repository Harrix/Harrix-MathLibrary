#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString DS;
    QString Path;
    QString Html;

    void HML_ShowText (QString TitleX);
    template <class T> void HML_ShowVector (T *VHML_Vector, int VHML_N, QString TitleVector, QString NameVector);
    template <class T> void HML_ShowNumber (T VHML_X, QString TitleX, QString NameX);
    template <class T> QString HML_NumberToText (T VHML_X);
    template <class T> void HML_ShowVectorT (T *VHML_Vector, int VHML_N, QString TitleVector, QString NameVector);
    template <class T> void HML_ShowMatrix (T **VHML_Matrix, int VHML_N, int VHML_M, QString TitleMatrix, QString NameMatrix);
private slots:

    void on_listView_clicked(const QModelIndex &index);

    void on_lineEdit_4_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;
    QSortFilterProxyModel *proxyModelView;
};

double Func3(double x);
double Func(int *x,int VHML_N);
double Func2(double *x,int VHML_N);
double Func4(double x);

#endif // MAINWINDOW_H
