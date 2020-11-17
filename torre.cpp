#include "torre.h"
#include "principal.h"

extern principal *juego;

torre::torre(QString team,QGraphicsItem *parent ):pieza(team,parent)
{
    if (team == "White"){
         setPixmap(QPixmap(":/piecesIma/white_rook.png"));
    }else{
         setPixmap(QPixmap(":/piecesIma/black_rook.png"));
    }

}
void torre::movimientos(){
    Posiblesmovimientos.clear();
    int fila= cajaContenedora->row;
    int columna= cajaContenedora->col;
    for(int i=fila-1;i>=0;--i){
        if(juego->boxes[i][columna]->getColorPiece()==this->getEquipo()){
            break;
        }else{
            if (this->getEquipo()!=juego->boxes[i][columna]->getColorPiece() && juego->boxes[i][columna]->lleno){
                Posiblesmovimientos.append(juego->boxes[i][columna]);
                pintarCaja(Posiblesmovimientos.last());
                break;
            }else{
                Posiblesmovimientos.append(juego->boxes[i][columna]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
    }
    for(int i=fila+1;i<=7;++i){
        if(juego->boxes[i][columna]->getColorPiece()==this->getEquipo()){
            break;
        }else{
            if (this->getEquipo()!=juego->boxes[i][columna]->getColorPiece() && juego->boxes[i][columna]->lleno){
                Posiblesmovimientos.append(juego->boxes[i][columna]);
                pintarCaja(Posiblesmovimientos.last());
                break;
            }else{
                Posiblesmovimientos.append(juego->boxes[i][columna]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
    }
    for(int j=columna-1;j>=0;--j) {
        if(juego->boxes[fila][j]->getColorPiece()==this->getEquipo()) {
            break;
        }else{
            if (this->getEquipo()!=juego->boxes[fila][j]->getColorPiece() && juego->boxes[fila][j]->lleno){
                Posiblesmovimientos.append(juego->boxes[fila][j]);
                pintarCaja(Posiblesmovimientos.last());
                break;
            }else{
                Posiblesmovimientos.append(juego->boxes[fila][j]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
    }
    for(int j=columna+1;j<=7;++j){
        if(juego->boxes[fila][j]->getColorPiece()==this->getEquipo()){
            break;
        }else{
            if (this->getEquipo()!=juego->boxes[fila][j]->getColorPiece() && juego->boxes[fila][j]->lleno){
                Posiblesmovimientos.append(juego->boxes[fila][j]);
                pintarCaja(Posiblesmovimientos.last());
                break;
            }else{
                Posiblesmovimientos.append(juego->boxes[fila][j]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
    }

}
