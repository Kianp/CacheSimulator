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
    blockSize = 2 ;
    mappingType = ui->mappingType->currentText().toInt()+3 ;
    QStringList a  ;
    a << "0000000000" <<"0000000000" << "0000000000" <<  "1000000000" << "0000000001" << "0000000010" << "0000000011" << "1111111111" ;
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
    mappingType = ui->mappingType->currentText().toInt() ;

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

    for ( int i=0 ; i < mappingType ; i ++ ) {
        ui->cache->insertColumn(ui->cache->columnCount());
        ui->cache->setHorizontalHeaderItem(ui->cache->columnCount()-1 , new QTableWidgetItem("Tag"));
        ui->cache->insertColumn(ui->cache->columnCount());
        ui->cache->setHorizontalHeaderItem(ui->cache->columnCount()-1 , new QTableWidgetItem("Data"));
    }
    for ( int j = 0 ; j < cacheRowCount ; j ++ ) {
        ui->cache->insertRow(ui->cache->rowCount());
        for ( int k = 0 ; k < 2*mappingType ; k ++ ) {
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
        QString word = index.right(log2(blockSize)) ;
        index = index.left(index.length()-log2(blockSize)) ;
        int TAG = tag.toInt(false ,2 ) ;
        int INDEX = index.toInt(false , 2) ;
        int ADDRESS = address.toInt(false , 2 ) ;
        int WORD = word.toInt(false , 2) ;
		QStringList datas;
		for (int w = 0; w < blockSize; w++) {
			datas << ui->mainMem->item(address.toInt(false, 2) + w, 0)->text();
		}
        qDebug() << datas;
        QString data = ui->mainMem->item(address.toInt(false , 2) , 0 )->text() ;

        qDebug() << "tag : " << tag << " , " << TAG << " INDEX : " << index << " , " << INDEX << " Word: " << WORD  ;
        qDebug() << "address : " << address << " , DATA : " << data ;

        ui->mainMem->selectRow(ADDRESS);
        ui->cache->selectRow((INDEX*blockSize));



        bool success = false ;
        for (  int i = 0  ; i < 2*mappingType ; i+= 2 ){
            if ( ui->cache->item((INDEX*blockSize) + WORD , i )->text() == tag ){
                success = true ;
                break ;
            }
            else {
                 // :|
            }
        }


        if ( success ) {
            qDebug() << "HIT" ;
            hit ++ ;
        }
        else {
            qDebug() << "MISS" ;
            miss ++ ;
            bool EMPTY = false ;
            for ( int i=0 ; i < mappingType*2 ; i += 2) {
                if ( ui->cache->item((INDEX*blockSize)+WORD , i )->text() == "null" ) {
                    for (int w = 0; w < blockSize ; w++){
                        ui->cache->setItem((INDEX*blockSize) + w, i, new QTableWidgetItem(tag));
                        ui->cache->setItem((INDEX*blockSize) + w, i + 1, new QTableWidgetItem(datas.at(w)));
					}
 
                    EMPTY = true ;
                    break ;
                }
            }


            if ( !EMPTY ){
                qDebug() << "LIFO" ;
                for ( int w = 0 ; w <  blockSize ; w ++ ) {
                    ui->cache->setItem((INDEX*blockSize)+w , (2*mappingType)-2 , new QTableWidgetItem(tag));
                    ui->cache->setItem((INDEX*blockSize)+w , (2*mappingType)-1 , new QTableWidgetItem(datas.at(w)));
                }
            }
        }
        ui->HIT->display(hit);
        ui->MISS->display(miss);
        ui->MissRate->setText(QString::number((float)(hit / ( hit + miss ) ) )) ;
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

void MainWindow::on_runAll_clicked()
{
    while ( ui->addressList->count() ) {
        this->selectFirstAddressFromMM();
    }
}
