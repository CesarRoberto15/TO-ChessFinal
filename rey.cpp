#include "rey.h"
#include "principal.h"
#include <QDebug>
extern principal *juego;

rey::rey(QString team,QGraphicsItem *parent ):pieza(team,parent)
{
    if (team == "White"){
         setPixmap(QPixmap(":/piecesIma/white_king.png"));
    }else{
         setPixmap(QPixmap(":/piecesIma/black_king.png"));
    }
}
void rey::movimientos(){
    Posiblesmovimientos.clear();
    int fila= cajaContenedora->row;
    int columna= cajaContenedora->col;
    //izquierda arriba
    if(fila>0 && columna>0 && !(juego->boxes[fila-1][columna-1]->getColorPiece()==this->getEquipo())){
        Posiblesmovimientos.append(juego->boxes[fila-1][columna-1]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //derecha arriba
    if(fila>0 && columna<7 && !(juego->boxes[fila-1][columna+1]->getColorPiece()==this->getEquipo())){
        Posiblesmovimientos.append(juego->boxes[fila-1][columna+1]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //adelante
    if(fila<7 && !(juego->boxes[fila+1][columna]->getColorPiece()==this->getEquipo())){
        Posiblesmovimientos.append(juego->boxes[fila+1][columna]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //atras
    if(fila>0 && !(juego->boxes[fila-1][columna]->getColorPiece()==this->getEquipo())){
        Posiblesmovimientos.append(juego->boxes[fila-1][columna]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //izquierda abajo
    if(fila<7 && columna>0 && !(juego->boxes[fila+1][columna-1]->getColorPiece()==this->getEquipo())){
        Posiblesmovimientos.append(juego->boxes[fila+1][columna-1]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //derecha abajo
    if(fila<7 && columna<7 && !(juego->boxes[fila+1][columna+1]->getColorPiece()==this->getEquipo())){
        Posiblesmovimientos.append(juego->boxes[fila+1][columna+1]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //izquierda
    if(columna>0 && !(juego->boxes[fila][columna-1]->getColorPiece()==this->getEquipo())){
        Posiblesmovimientos.append(juego->boxes[fila][columna-1]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //derecha
    if(columna<7 && !(juego->boxes[fila][columna+1]->getColorPiece()==this->getEquipo())){
        Posiblesmovimientos.append(juego->boxes[fila][columna+1]);
        pintarCaja(Posiblesmovimientos.last());
    }
}
