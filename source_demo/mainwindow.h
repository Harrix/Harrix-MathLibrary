#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>

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
    QString path;
    QString Html;

    template <class T> void MHL_ShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
    template <class T> void MHL_ShowNumber (T VMHL_X, QString TitleX, QString NameX);
    template <class T> QString MHL_NumberToText (T VMHL_X);
    template <class T> void MHL_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
    template <class T> void MHL_ShowMatrix (T **VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);
private slots:

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
