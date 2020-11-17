#include "pieza.h"
#include "principal.h"
extern principal *juego;
pieza::pieza()
{

}
pieza::pieza(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    colocado = true;
    equipo = team;


}

void pieza::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //Lo desseleccionamos
    if (this==juego->piezaSeleccionada){
        juego->piezaSeleccionada->cajaContenedora->resetColor();
        juego->piezaSeleccionada->limpiarMovimientos();
        juego->piezaSeleccionada = NULL;
        return;
    }

    if((!colocado )|| ( (juego->getTurno() != this->equipo)&& (!juego->piezaSeleccionada)) )
            return;
    //Se vuelve la pieza seleccionada
  if(!juego->piezaSeleccionada){
      juego->piezaSeleccionada = this;
      juego->piezaSeleccionada->cajaContenedora->setColor(Qt::red);
      juego->piezaSeleccionada->movimientos();
   }
     else if(this->equipo != juego->piezaSeleccionada->equipo){
      this->cajaContenedora->mousePressEvent(event);
   }

}
QString pieza::getEquipo(){
    return this->equipo;
}
void pieza::setCaja(caja *box){
    this->cajaContenedora=box;
}
void pieza::pintarCaja(caja *box){
    if (box->lleno){
        box->setColor(Qt::yellow);
    }else{
        Posiblesmovimientos.last()->setColor(Qt::blue);
    }
}
void pieza::limpiarMovimientos(){
    for(int i=0;i < Posiblesmovimientos.size();i++){
        Posiblesmovimientos[i]->resetColor();
    }
}
caja * pieza::getCaja(){
    return this->cajaContenedora;
}
QList <caja *> pieza::getPMovimientos(){
    return this->Posiblesmovimientos;
}
void pieza::setColocado(bool valor){
    this->colocado=valor;
}
