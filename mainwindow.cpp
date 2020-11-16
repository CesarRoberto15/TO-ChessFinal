#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGridLayout>
#include <string>
#include "pawn.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        bool color=true;
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                cuadros[i][j]=new QLabel();
                if(color){
                    cuadros[i][j]->setStyleSheet("background-color:#EEA21C;" "width: 50px;" "height:50px");
                }else{
                    cuadros[i][j]->setStyleSheet("background-color:#FFFFFF;" "width: 50px;" "height:50px");
                    //cuadros[i][j]->setIcon(QIcon("C:/Users/LENOVO/Desktop/unsa 2020/TO/ProyectoFinal/TO-ChessFinal/piecesIma/king"));
                }
                if(j!=7){
                    color=!color;
                }
                ui->tablero->addWidget(cuadros[i][j],9-i,j);
            }
        }
}



MainWindow::~MainWindow()
{
    delete ui;
}

