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

    void MHL_ShowText (QString TitleX);
    template <class T> void MHL_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
    template <class T> void MHL_ShowNumber (T VMHL_X, QString TitleX, QString NameX);
    template <class T> QString MHL_NumberToText (T VMHL_X);
    template <class T> void MHL_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
    template <class T> void MHL_ShowMatrix (T **VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);
private slots:

    void on_listView_clicked(const QModelIndex &index);

    void on_lineEdit_4_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;
    QSortFilterProxyModel *proxyModelView;
};

double Func3(double x);
double Func(int *x,int VMHL_N);
double Func2(double *x,int VMHL_N);
double Func4(double x);

#endif // MAINWINDOW_H
