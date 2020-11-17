#include "caja.h"
#include "principal.h"
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
   piece->setPos(x()-10 ,y()-5);
   piece->setCaja(this);
   data=piece;
   lleno=true;
   piezaColor=piece->getEquipo();

}
void caja::setOriginalColor(QColor color){
    brush.setColor(color);
    setBrush(color);
    colorOriginal=color;
}
void caja::setColor(QColor color){
    brush.setColor(color);
    setBrush(color);
}
void caja::resetColor(){
    brush.setColor(colorOriginal);
    setBrush(colorOriginal);
}
void caja::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug() << getColorPiece();
   if(data == juego->piezaSeleccionada && data ){
        data->mousePressEvent(event);
        return;
     }
    if(juego->piezaSeleccionada){

        if(this->getColorPiece() == juego->piezaSeleccionada->getEquipo())
            return;

        QList <caja *> posicionMovimientos = juego->piezaSeleccionada->getPMovimientos();
        int check = 0;
        for(size_t i = 0, n = posicionMovimientos.size(); i < n;i++) {
            if(posicionMovimientos[i] == this) {
                check++;

            }
        }
        if(check == 0)
            return;
         juego->piezaSeleccionada->limpiarMovimientos();

        if(this->lleno){
            this->data->setColocado(false);
            this->data->setCaja(NULL);
            this->data->setPos(20,20);
        }
        juego->piezaSeleccionada->getCaja()->lleno=false;
        juego->piezaSeleccionada->getCaja()->data = NULL;
        juego->piezaSeleccionada->getCaja()->piezaColor = "NONE";
        juego->piezaSeleccionada->getCaja()->resetColor();

        addPieza(juego->piezaSeleccionada);
        juego->piezaSeleccionada = NULL;
        juego->cambiarTurno();

    }
    else if(this->lleno)
    {
        this->data->mousePressEvent(event);
    }
}
QString caja::getColorPiece(){
    return piezaColor;
}
