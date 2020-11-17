#include "alfil.h"
#include "principal.h"
#include <QDebug>
extern principal *juego;
alfil::alfil(QString team,QGraphicsItem *parent ):pieza(team,parent)
{
    if (team == "White"){
         setPixmap(QPixmap(":/piecesIma/white_bishop.png"));
    }else{
         setPixmap(QPixmap(":/piecesIma/black_bishop.png"));
    }
}
void alfil::movimientos(){
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
        /*
        //Verificamos si es aliado o enemigo
        if(i<7 && row < 7 && this->getEquipo()!=juego->boxes[row+1][i+1]->getColorPiece()){
            Posiblesmovimientos.append(juego->boxes[row+1][i+1]);
            pintarCaja(Posiblesmovimientos.last());
        }else{
            continue;
        }
        //Casillas vacias
        if(i<7 && row <7 && !juego->boxes[row+1][i+1]->lleno ){
             Posiblesmovimientos.append(juego->boxes[row+1][i+1]);
             pintarCaja(Posiblesmovimientos.last());
         }
         row++;
    }
    //izquierda abajo
    int row2=fila;
    for(int i=columna;i>0;i--){
        //Verificamos si es aliado o enemigo
        if(i>0 && row2 < 7 && this->getEquipo()!=juego->boxes[row2+1][i-1]->getColorPiece()){
            Posiblesmovimientos.append(juego->boxes[row2+1][i-1]);
            pintarCaja(Posiblesmovimientos.last());
        }else{
            continue;
        }
        //Casillas vacias
        if(i>0 && row2 <7 && !juego->boxes[row2+1][i-1]->lleno ){
             Posiblesmovimientos.append(juego->boxes[row2+1][i-1]);
             pintarCaja(Posiblesmovimientos.last());
         }
         row2++;
    }*/

}
