#include "tablero.h"
#include "caja.h"
#include "principal.h"
#include "peon.h"
#include "alfil.h"
#include "torre.h"
#include "rey.h"
#include "reina.h"
#include "caballo.h"

extern principal *juego;
tablero::tablero()
{
    CrearFichasblancas();
    CrearFichasNegras();
}

void tablero::dibujarCajas(int x, int y){
    //Espaciado
    int espacio=50;
    //Dibujamos todos los cuadrados
    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            //Creamos la caja
            caja *rect= new caja();
            juego->boxes[i][j]=rect;
            rect->row = i;
            rect->col = j;
            //Posicionamos
            rect->setPos(x+espacio*j,y+espacio*i);
            //Establecemos el color de la caja
            if((i+j)%2==0){
                QColor color(192,57,43); //Marron
                rect->setOriginalColor(color);
            }else{
                QColor color(245,176,65);//Naranja
                rect->setOriginalColor(color);
            }
            //Lo añadimos a la vista
             juego->addItem(rect);
        }
    }
}


void tablero::dibujarPiezas(){
    int aux=0;
    //Creamos las fichas negras
    for(int i=0;i<8;i++){
        caja *box =juego->boxes[0][i];
        box->addPieza(FichasNegras[aux]);
        juego->addItem(FichasNegras[aux++]);
    }
    for(int i=0;i<8;i++){
        caja *box =juego->boxes[1][i];
        box->addPieza(FichasNegras[aux]);
        juego->addItem(FichasNegras[aux++]);
    }
    aux=0;
    //Creamos las fichas blancas
    for(int i=0;i<8;i++){
        caja *box =juego->boxes[6][i];
        box->addPieza(FichasBlancas[aux]);
        juego->addItem(FichasBlancas[aux++]);
    }
    for(int i=0;i<8;i++){
        caja *box =juego->boxes[7][i];
        box->addPieza(FichasBlancas[aux]);
        juego->addItem(FichasBlancas[aux++]);
    }
}
//Creamos las fichas Blancas
void tablero::CrearFichasblancas(){
    pieza *piece;
    for(int i = 0; i < 8; i++) {
        piece = new peon("White");
        FichasBlancas.append(piece);
    }
    piece = new torre("White");
    FichasBlancas.append(piece);
    piece = new caballo("White");
    FichasBlancas.append(piece);
    piece = new alfil("White");
    FichasBlancas.append(piece);
    piece = new reina("White");
    FichasBlancas.append(piece);
    piece = new rey("White");
    FichasBlancas.append(piece);
    piece = new alfil("White");
    FichasBlancas.append(piece);
    piece = new caballo("White");
    FichasBlancas.append(piece);
    piece = new torre("White");
    FichasBlancas.append(piece);
}
//Creamos las fichas Negras
void tablero::CrearFichasNegras(){
    pieza *piece;
    piece = new torre("Black");
    FichasNegras.append(piece);
    piece = new caballo("Black");
    FichasNegras.append(piece);
    piece = new alfil("Black");
    FichasNegras.append(piece);
    piece = new reina("Black");
    FichasNegras.append(piece);
    piece = new rey("Black");
    FichasNegras.append(piece);
    piece = new alfil("Black");
    FichasNegras.append(piece);
    piece = new caballo("Black");
    FichasNegras.append(piece);
    piece = new torre("Black");
    FichasNegras.append(piece);

    for(int i = 0; i < 8; i++) {
        piece = new peon("Black");
        FichasNegras.append(piece);
    }
}
