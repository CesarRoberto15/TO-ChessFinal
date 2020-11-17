#include "reina.h"
#include "principal.h"
#include <QDebug>
extern principal *juego;

reina::reina(QString team,QGraphicsItem *parent ):pieza(team,parent)
{
    if (team == "White"){
         setPixmap(QPixmap(":/piecesIma/white_queen.png"));
    }else{
         setPixmap(QPixmap(":/piecesIma/black_queen.png"));
    }
}
void reina::movimientos(){
    Posiblesmovimientos.clear();
    int fila= cajaContenedora->row;
    int columna= cajaContenedora->col;

    //Derecha abajo
    for(int i=fila,j=columna;i< 7 && j<7;i++,j++){
        if(this->getEquipo()==juego->boxes[i+1][j+1]->getColorPiece()){
            break;
        }else{
            if (this->getEquipo()!=juego->boxes[i+1][j+1]->getColorPiece() && juego->boxes[i+1][j+1]->lleno ){
                Posiblesmovimientos.append(juego->boxes[i+1][j+1]);
                pintarCaja(Posiblesmovimientos.last());
                break;
            }else{
                Posiblesmovimientos.append(juego->boxes[i+1][j+1]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
    }
    //Izquierda abajo
    for(int i=fila,j=columna;i <7 && j>0;i++,j--){
        if(this->getEquipo()==juego->boxes[i+1][j-1]->getColorPiece()){
            break;
        }else{
            if (this->getEquipo()!=juego->boxes[i+1][j-1]->getColorPiece() && juego->boxes[i+1][j-1]->lleno){
                Posiblesmovimientos.append(juego->boxes[i+1][j-1]);
                pintarCaja(Posiblesmovimientos.last());
                break;
            }else{
                Posiblesmovimientos.append(juego->boxes[i+1][j-1]);
                pintarCaja(Posiblesmovimientos.last());
            }

        }
    }

    //Derecha arriba
    for(int i=fila,j=columna;i > 0&& j<7;i--,j++){
        if(this->getEquipo()==juego->boxes[i-1][j+1]->getColorPiece()){
            break;
        }else{
            if (this->getEquipo()!=juego->boxes[i-1][j+1]->getColorPiece() && juego->boxes[i-1][j+1]->lleno ){
                Posiblesmovimientos.append(juego->boxes[i-1][j+1]);
                pintarCaja(Posiblesmovimientos.last());
                break;
            }else{
                Posiblesmovimientos.append(juego->boxes[i-1][j+1]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
    }
    //Izquierda arriba
    for(int i=fila,j=columna;i > 0&& j>0;i--,j--){
        if(this->getEquipo()==juego->boxes[i-1][j-1]->getColorPiece()){
            break;
        }else{
            if (this->getEquipo()!=juego->boxes[i-1][j-1]->getColorPiece() && juego->boxes[i-1][j-1]->lleno ){
                Posiblesmovimientos.append(juego->boxes[i-1][j-1]);
                pintarCaja(Posiblesmovimientos.last());
                break;
            }else{
                Posiblesmovimientos.append(juego->boxes[i-1][j-1]);
                pintarCaja(Posiblesmovimientos.last());
            }
        }
    }
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
