#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <string.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton* cuadros[8][8];
    bool color=true;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cuadros[i][j]=new QPushButton();
            if(color){
                cuadros[i][j]->setStyleSheet("background-color:#EEA21C;" "width: 50px;" "height:50px");
            }else{
                cuadros[i][j]->setStyleSheet("background-color:#FFFFFF;" "width: 50px;" "height:50px");
            }
            if(j!=7){
                color=!color;
            }
            ui->gridLayout->addWidget(cuadros[i][j],9-i,j);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

