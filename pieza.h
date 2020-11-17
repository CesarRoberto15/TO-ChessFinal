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
    QString getEquipo();
    void setCaja(caja *box);
    void pintarCaja(caja *box);
    caja *getCaja();
    QList <caja *> getPMovimientos();
    void setColocado(bool);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void limpiarMovimientos();
    virtual void movimientos() = 0;

protected:
    QString equipo;
    caja *cajaContenedora;
    QList <caja *> Posiblesmovimientos;
    bool colocado;
};

#endif // PIEZA_H
