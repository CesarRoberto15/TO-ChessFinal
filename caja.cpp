#include "caja.h"
#include "principal.h"
#include "rey.h"
#include "peon.h"
#include "reina.h"
#include "pieza.h"
#include "caballo.h"
#include "boton.h"
extern principal *juego;
#include <QDebug>


caja::caja(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,50,50);
    lleno=false;
    data=NULL;
    piezaColor="NONE";
}

void caja::addPieza(pieza * piece){
    //La ubicamos
   piece->setPos(x()-5 ,y()-5);
   //Indicamos a la pieza que esta sera su caja contenedora
   piece->setCaja(this);
   //Añadimos la pieza
   data=piece;
   //La caja ya no esta vacia
   lleno=true;
   //Indicamos el color de la pieza de la caja
   if (piece){
       piezaColor=piece->getEquipo();
   }else{
       piezaColor="NONE";
   }

}
//Establecemos el color original
void caja::setOriginalColor(QColor color){
    brush.setColor(color);
    setBrush(color);
    colorOriginal=color;
}
//Actualizamos el color
void caja::setColor(QColor color){
    brush.setColor(color);
    setBrush(color);
}
//Volvemos al color original
void caja::resetColor(){
    brush.setColor(colorOriginal);
    setBrush(colorOriginal);
}
void caja::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug() << getColorPiece();
    qDebug() << lleno;
   //Verificamos si la caja seleccionada contiene a la pieza seleccionada
   // y si no esta vacio
   if(data == juego->piezaSeleccionada && data ){
        data->mousePressEvent(event);
        return;
     }
   //Verificamos si hay una pieza seleccionada
    if(juego->piezaSeleccionada){
        //Verificamos si son del mismo equipo
        if(this->getColorPiece() == juego->piezaSeleccionada->getEquipo())
            return;
        //Verificamos si la caja seleccionada pertenece al grupo de
        //Posibles moviementos de la pieza seleccionada
        QList <caja *> posicionMovimientos = juego->piezaSeleccionada->getPMovimientos();
        int check = 0;
        for(size_t i = 0, n = posicionMovimientos.size(); i < n;i++) {
            if(posicionMovimientos[i] == this) {
                check++;

            }
        }
        // Si es que no pertenece al grupo de movimientos salimos
        if(check == 0)
            return;
        //Limpiamos las cajas pintadas
         juego->piezaSeleccionada->limpiarMovimientos();

        //Si esta lleno entonces la comemos y movemos esa pieza a la
        // zona de piezas muertas
        if(this->lleno){
            this->data->setLife(false);
            this->data->setCaja(NULL);
            juego->fichaMuerta(this->data);
        }
        //Borramos los datos de la caja dela pieza seleccionada
        juego->piezaSeleccionada->getCaja()->lleno=false;
        juego->piezaSeleccionada->getCaja()->data = NULL;
        juego->piezaSeleccionada->getCaja()->piezaColor = "NONE";
        juego->piezaSeleccionada->getCaja()->resetColor();
        //Añadimos la ficha seleccionada a su nueva ubicacion
        addPieza(juego->piezaSeleccionada);
        //Reiniciamos la pieza seleccionada
        juego->piezaSeleccionada = NULL;
        //Verificamos si hay Jaque
        verificarJaque();
        verificarPromocion();
        //Cambiamos turno
        juego->cambiarTurno();

    }
    //Si seleccionamos una caja llena mandamos al evento a la pieza
    else if(this->lleno){
        this->data->mousePressEvent(event);
    }
}
//Obtenemos el color de la pieza almacenda
QString caja::getColorPiece(){
    return piezaColor;
}
void caja::verificarJaque(){
    //Llenamos internamente los posibles movimientos
    this->data->movimientos();
    //Obtenemos todos los movimientos de la ficha nueva
    QList <caja *> posicionMovimientos= this->data->getPMovimientos();
    for(size_t i = 0, n = posicionMovimientos.size(); i < n;i++) {
        //Buscamos si dentro de nuestros movimientos hay un rey
         rey *king = dynamic_cast <rey *>(posicionMovimientos[i]->data);
         if(king){
             juego->jaque->setPlainText("JAQUE");
             juego->jaque->setVisible(true);
         }
    }
   //Limpiamos las cajas
   this->data->limpiarMovimientos();
}
void caja::verificarPromocion(){
    //casteamos a peon
    peon *pawn= dynamic_cast <peon *>(data);
    QString color=piezaColor;
    //Si el casteo es correcto y esta en alguna posicion de promocion
    if (pawn && ((row==0 && col>=0 && col<=7 )|| (row==7 && col>=0 && col<=7))  ){
        qDebug() <<" Peon en promocion";
        //Habilitamos la promocion
        juego->dibujarPromocion(this->getColorPiece(),this->row,this->col);
        //Eliminamos el enlace y lo movemos a la zona de muerte
        this->data->setLife(false);
        this->data->setCaja(NULL);
        juego->fichaMuerta(this->data);        
        //Reiniciamos los datos de la caja
        this->lleno=false;
        this->data = NULL;
        this->piezaColor = "NONE";
        this->resetColor();

    }
}

