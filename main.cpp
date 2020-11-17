#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>

#include "principal.h"

class Caja: public QGraphicsRectItem{
public:
    Caja(QGraphicsItem *parent=0):QGraphicsRectItem(parent){
        setRect(0,0,50,50);
    }
   QBrush brush;
   QGraphicsPixmapItem *pie;
   void addMap(){
      pie = new QGraphicsPixmapItem();
      pie->setPixmap(QPixmap(":/pawn.png"));
   }
};
principal *juego;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
   QGraphicsScene *scene= new QGraphicsScene();
   scene->setSceneRect(0,0,800,400);



    Caja *box[9][9];
    QGraphicsTextItem *fichasB= new QGraphicsTextItem("Fichas Blancas Perdidadas");
    fichasB->setPos(0,0);
    scene->addItem(fichasB);

    int espacio=50;
    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            Caja *rect= new Caja();
            box[i][j]=rect;
            rect->setRect(200+espacio*j,20+espacio*i,50,50);
            if((i+j)%2==0)
                rect->setBrush(Qt::black);
            else
                rect->setBrush(Qt::white);
            QGraphicsPixmapItem *dd= new QGraphicsPixmapItem();
            dd->setPos(190+espacio*j,10+espacio*i);
            dd->setPixmap(QPixmap(":/pawn.png"));
            rect->
    scene->addIpie=dd;
            scene->addItem(rect);

        }
    }
    QGraphicsTextItem *fichasN= new QGraphicsTextItem("Fichas Negras Perdidadas");
    fichasN->setPos(650,0);tem(fichasN);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(800,500);
    view->show();
*/
   /* MainWindow w;
    w.show();*/
    juego= new principal();
    juego->show();
    juego->iniciar();
    return a.exec();
}
