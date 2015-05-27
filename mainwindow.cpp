#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    dataWidth = 10 ;

    // developement
    memorySize = 10 ;
    cacheSize = 5 ;
    mappingType = ui->mappingType->currentText().toInt() ;
    QStringList a  ;
    a << "0000000000" << "0000000001" << "0000000010" << "000 000011" ;
    ui->addressList->addItems(a);
    this->generateData();

}

QString MainWindow::randomBinaryNumberGenerator(int width)
{
    QString res;
    for ( int i=0 ; i < width ; i ++ ) {
        int rand = qrand() % 2 ;
        if ( rand ) { res.append('0') ;}
        else { res.append('1') ; }
    }
    return res;
}


void MainWindow::generateData()
{
    // development
//    blockSize = ui->blockSize->text().toInt() ;
//    memorySize = ui->memSize->text().toInt() ;
//    cacheSize = ui->cacheSize->text().toInt() ;
//    mappingType = ui->mappingType->currentText().toInt() ;

    ui->mainMem->clear();
    ui->mainMem->setRowCount(0);
    ui->mainMem->setColumnCount(0);

    ui->mainMem->insertColumn(0);
    int memRowCount = qPow(2 , memorySize) ;
    ui->mainMem->setHorizontalHeaderItem(0 , new QTableWidgetItem("Data"));
    for ( int i = 0 ; i < memRowCount  ; i ++ ) {
        ui->mainMem->insertRow(ui->mainMem->rowCount());
        QString data = this->randomBinaryNumberGenerator(dataWidth) ;
        ui->mainMem->setItem(ui->mainMem->rowCount()-1 , 0 , new QTableWidgetItem(data) );
    }



    ui->cache->clear();
    ui->cache->setRowCount(0);
    ui->cache->setColumnCount(0);

    int cacheRowCount = qPow(2 , cacheSize);
    qDebug() << mappingType ;
    for ( int i=0 ; i < mappingType ; i ++ ) {
        ui->cache->insertColumn(ui->cache->columnCount());
        ui->cache->setHorizontalHeaderItem(ui->cache->columnCount()-1 , new QTableWidgetItem("Tag"));
        ui->cache->insertColumn(ui->cache->columnCount());
        ui->cache->setHorizontalHeaderItem(ui->cache->columnCount()-1 , new QTableWidgetItem("Data"));
    }
    for ( int j = 0 ; j < cacheRowCount ; j ++ ) {
        ui->cache->insertRow(ui->cache->rowCount());
        for ( int k = 0 ; k < qPow(2,mappingType) ; k ++ ) {
            ui->cache->setItem(ui->cache->rowCount()-1 , k , new QTableWidgetItem("null"));
            ui->cache->setItem(ui->cache->rowCount()-1 , k , new QTableWidgetItem("null"));
        }
    }
}

void MainWindow::selectFirstAddressFromMM()
{
    if ( ui->addressList->count()) {

        QString address = ui->addressList->takeItem(0)->text() ;
        QString index= address.right(cacheSize) ;
        QString tag = address.left(memorySize-cacheSize) ;
        int TAG = tag.toInt(false ,2 ) ;
        int INDEX = index.toInt(false , 2) ;
        ui->mainMem->selectRow(INDEX);
        ui->cache->selectRow(INDEX);

        for (int i = 0  ; i < mappingType ; i++ ) {
            if ( ui->cache->itemAt(INDEX , i )->text() == tag ){
                qDebug() << "hit" ;
            }
            else {
                qDebug() << "miss" ;
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Generate_clicked()
{
    this->generateData();
}

void MainWindow::on_InsertAddress_clicked()
{
    if ( ui->addressInput->text().length() == memorySize) {
        ui->addressList->addItem(ui->addressInput->text());
    }

}

void MainWindow::on_addressInput_returnPressed()
{
    if ( ui->addressInput->text().length() == memorySize) {
        ui->addressList->addItem(ui->addressInput->text());
    }
}

void MainWindow::on_runOne_clicked()
{
    this->selectFirstAddressFromMM();
}
