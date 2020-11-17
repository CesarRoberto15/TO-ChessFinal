#include "caballo.h"
#include "principal.h"
extern principal *juego;

caballo::caballo(QString team,QGraphicsItem *parent ):pieza(team,parent)
{
    if (team == "White"){
         setPixmap(QPixmap(":/piecesIma/white_horse.png"));
    }else{
         setPixmap(QPixmap(":/piecesIma/black_horse.png"));
    }

}
void caballo::movimientos(){
    Posiblesmovimientos.clear();
    int fila= cajaContenedora->row;
    int columna= cajaContenedora->col;
    //L parado
    if(fila+2<=7 && columna-1>=0 && juego->boxes[fila+2][columna-1]->getColorPiece()!=this->getEquipo()){
        Posiblesmovimientos.append(juego->boxes[fila+2][columna-1]);
        pintarCaja(Posiblesmovimientos.last());
    }
    if(fila+2<=7 && columna+1<=7 && juego->boxes[fila+2][columna+1]->getColorPiece()!=this->getEquipo()){
        Posiblesmovimientos.append(juego->boxes[fila+2][columna+1]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //L no parado
    if(fila+1<=7 && columna-2>=0 && juego->boxes[fila+1][columna-2]->getColorPiece()!=this->getEquipo()){
        Posiblesmovimientos.append(juego->boxes[fila+1][columna-2]);
        pintarCaja(Posiblesmovimientos.last());
    }
    if(fila+1<=7 && columna+2<=7 && juego->boxes[fila+1][columna+2]->getColorPiece()!=this->getEquipo()){
        Posiblesmovimientos.append(juego->boxes[fila+1][columna+2]);
        pintarCaja(Posiblesmovimientos.last());
    }

    //L parado
    if(fila-2>=0 && columna-1>=0 && juego->boxes[fila-2][columna-1]->getColorPiece()!=this->getEquipo()){
        Posiblesmovimientos.append(juego->boxes[fila-2][columna-1]);
        pintarCaja(Posiblesmovimientos.last());
    }

    if(fila-2>=0 && columna+1<=7 && juego->boxes[fila-2][columna+1]->getColorPiece()!=this->getEquipo()){
        Posiblesmovimientos.append(juego->boxes[fila-2][columna+1]);
        pintarCaja(Posiblesmovimientos.last());
    }
    //L no parado
    if(fila-1>=0 && columna-2>=0 && juego->boxes[fila-1][columna-2]->getColorPiece()!=this->getEquipo()){
        Posiblesmovimientos.append(juego->boxes[fila-1][columna-2]);
        pintarCaja(Posiblesmovimientos.last());
    }
    if(fila-1>=0 && columna+2<=7 && juego->boxes[fila-1][columna+2]->getColorPiece()!=this->getEquipo()){
        Posiblesmovimientos.append(juego->boxes[fila-1][columna+2]);
        pintarCaja(Posiblesmovimientos.last());
    }
}
