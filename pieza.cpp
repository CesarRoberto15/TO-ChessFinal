#include "pieza.h"
#include "principal.h"
extern principal *juego;
pieza::pieza()
{

}
pieza::pieza(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    vivo = true;
    equipo = team;

}

void pieza::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //Reiniciamos el JAQUE
     juego->jaque->setVisible(false);
    //Lo desseleccionamos
    if (this==juego->piezaSeleccionada){
        juego->piezaSeleccionada->cajaContenedora->resetColor();
        juego->piezaSeleccionada->limpiarMovimientos();
        juego->piezaSeleccionada = NULL;
        return;
    }
    //Verificamos si esta vivo y si es su turno o no, de no serlo ,
    //no se le puede seleccionar
    if((!vivo )|| ( (juego->getTurno() != this->equipo)&& (!juego->piezaSeleccionada)) )
            return;
    //Se vuelve la pieza seleccionada
      if(!juego->piezaSeleccionada){
          juego->piezaSeleccionada = this;
          juego->piezaSeleccionada->cajaContenedora->setColor(Qt::red);
          juego->piezaSeleccionada->movimientos();
       }
      //Si hay una pieza selecionada y seleccionamos a otra ficha
      //del otro equipo
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
//Pintamos las cajas dependiendo si estan vacias o no
void pieza::pintarCaja(caja *box){
    if (box->lleno){
        box->setColor(Qt::yellow);
    }else{
        Posiblesmovimientos.last()->setColor(Qt::blue);
    }
}
//Limpiamos los movimientos
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
void pieza::setLife(bool valor){
    this->vivo=valor;
}
