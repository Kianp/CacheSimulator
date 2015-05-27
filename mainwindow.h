#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "qmath.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int memorySize ;
    int cacheSize ;
    int mappingType ;
    int blockSize ;
    int dataWidth ;
    int miss = 0 ;
    int hit = 0 ;
    explicit MainWindow(QWidget *parent = 0);
    QString randomBinaryNumberGenerator(int) ;
    void generateData() ;
    void selectFirstAddressFromMM() ;
    ~MainWindow();

private slots:
    void on_Generate_clicked();
    void on_InsertAddress_clicked();
    void on_addressInput_returnPressed();

    void on_runOne_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
