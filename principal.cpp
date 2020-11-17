#include "principal.h"

principal::principal(QWidget *parent ):QGraphicsView(parent)
{
    //Creamos la escena
    setFixedSize(800,500);
    //Quitamos la barra de movimiento
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Creamos los componentes
    Scene= new QGraphicsScene();
    Scene->setSceneRect(0,0,800,400);
    piezaSeleccionada=NULL;
    turno="White";
    setScene(Scene);
}

void principal::addItem(QGraphicsItem  *item){
    Scene->addItem(item);
}

void principal::iniciar(){
    chess->dibujarCajas(200,20);
    chess->dibujarPiezas();

    //Titulos de la zona de fichas muertas
    QGraphicsTextItem *fichasB= new QGraphicsTextItem("Fichas Blancas Perdidadas");
    fichasB->setPos(0,0);

    QGraphicsTextItem *fichasN= new QGraphicsTextItem("Fichas Negras Perdidadas");
    fichasN->setPos(650,0);

    //Añadimos los componentes a la ventana
    Scene->addItem(fichasB);
    Scene->addItem(fichasN);

    //Letras al borde del tablero
    int espacio=50;
    //Las letras a escribir
    QList <QString> letras;
    letras.append("A");
    letras.append("B");
    letras.append("C");
    letras.append("D");
    letras.append("E");
    letras.append("F");
    letras.append("G");
    letras.append("H");
    //Letras en la parte de arriba
    for(int i=0; i<8;i++){
        QGraphicsTextItem *fichas= new QGraphicsTextItem(letras[i]);
        fichas->setPos(i*espacio+ 220,0);
        Scene->addItem(fichas);
    }
    //Numeros en la parte izquierda
     for(int i=0,j=0; i<8;i++,j++){
         QString cad= QString::number(j+1);
         QGraphicsTextItem *fichas= new QGraphicsTextItem(cad);
         fichas->setPos(150,30+espacio*i);
         Scene->addItem(fichas);
     }
     //Letras en la parte de abajo
     for(int i=0; i<8;i++){
         QGraphicsTextItem *fichas= new QGraphicsTextItem(letras[i]);
         fichas->setPos(i*espacio+ 220,425);
         Scene->addItem(fichas);
     }
     //Numeros en la parte derecha
     for(int i=0,j=0; i<8;i++,j++){
         QString cad= QString::number(j+1);
         QGraphicsTextItem *fichas= new QGraphicsTextItem(cad);
         fichas->setPos(620,30+espacio*i);
         Scene->addItem(fichas);
     }
}
void principal::cambiarTurno(){
    if (turno=="White"){
        turno="Black";
    }else{
        turno="White";
    }
}
QString principal::getTurno(){
    return this->turno;
}
