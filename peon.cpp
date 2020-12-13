#include "peon.h"
#include "principal.h"

extern principal *juego;
peon::peon(QString team,QGraphicsItem *parent ):pieza(team,parent)
{
    if (team == "White"){
         setPixmap(QPixmap(":/piecesIma/white_pawn.png"));
    }else{
         setPixmap(QPixmap(":/piecesIma/black_pawn.png"));
    }

}
void peon::movimientos(){
    Posiblesmovimientos.clear();
    int fila= cajaContenedora->row;
    int columna= cajaContenedora->col;
    if(equipo=="Black"){
        //Primer movimiento
        if( fila<7 && columna<=7 &&!juego->boxes[fila+1][columna]->lleno){
            Posiblesmovimientos.append(juego->boxes[fila+1][columna]);
            pintarCaja(Posiblesmovimientos.last());
            if (fila==1 && !juego->boxes[fila+2][columna]->lleno){
                Posiblesmovimientos.append(juego->boxes[fila+2][columna]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
        //Matar a la izquierda
        if (fila<7 &&columna>0 && juego->boxes[fila+1][columna-1]->lleno  && (juego->boxes[fila+1][columna-1]->getColorPiece()!="Black")){
            Posiblesmovimientos.append(juego->boxes[fila+1][columna-1]);
            pintarCaja(Posiblesmovimientos.last());
        }
        //Matar a la derecha
        if (fila<7 &&columna<7 && juego->boxes[fila+1][columna+1]->lleno && (juego->boxes[fila+1][columna+1]->getColorPiece()!="Black")){
            Posiblesmovimientos.append(juego->boxes[fila+1][columna+1]);
            pintarCaja(Posiblesmovimientos.last());
        }


    }else{
        //Primer movimiento
        if( fila>0 && columna>=0 && !juego->boxes[fila-1][columna]->lleno){
            Posiblesmovimientos.append(juego->boxes[fila-1][columna]);
            pintarCaja(Posiblesmovimientos.last());
            if (fila==6 && !juego->boxes[fila-2][columna]->lleno){
                Posiblesmovimientos.append(juego->boxes[fila-2][columna]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
        //Matar a la izquierda
        if (fila>0 && columna>0 && juego->boxes[fila-1][columna-1]->lleno && (juego->boxes[fila-1][columna-1]->getColorPiece()!="White") ){
            Posiblesmovimientos.append(juego->boxes[fila-1][columna-1]);
            pintarCaja(Posiblesmovimientos.last());
        }
        //Matar a la derecha
        if (fila>0 && columna<7 && juego->boxes[fila-1][columna+1]->lleno && (juego->boxes[fila-1][columna+1]->getColorPiece()!="White")){
            Posiblesmovimientos.append(juego->boxes[fila-1][columna+1]);
            pintarCaja(Posiblesmovimientos.last());
        }
    }

}
