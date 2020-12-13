#ifndef PIEZA_H
#define PIEZA_H

#include <QGraphicsPixmapItem>
#include "caja.h"
class caja;
class pieza :public QGraphicsPixmapItem
{
public:
    pieza();
    pieza(QString team = "",QGraphicsItem *parent = 0);
    QString getEquipo();//Obtenemos el equipo
    void setCaja(caja *box);//Establecemos la caja contenedora
    void pintarCaja(caja *box);//Pintamos las cajas dependiendo si estan vacias o no
    caja *getCaja();//Obtenemos la caja
    QList <caja *> getPMovimientos();//Posibles movimientos
    void setLife(bool);//Vivo o muerto
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void limpiarMovimientos();//Limpiamos los movimientos
    virtual void movimientos() = 0;

protected:
    QString equipo;//Equipo
    caja *cajaContenedora;
    QList <caja *> Posiblesmovimientos;
    bool vivo;
};

#endif // PIEZA_H
