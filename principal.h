#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <tablero.h>
#include "caja.h"
#include "pieza.h"
class principal :public QGraphicsView
{
public:
    principal(QWidget *parent=0);
    void iniciar();
    void addItem(QGraphicsItem  *item);
    void cambiarTurno();
    QString getTurno();
    caja *boxes[9][9];
    tablero* chess= new tablero();
    pieza *piezaSeleccionada;

private:
    QGraphicsScene *Scene;
    QString turno;

};

#endif // PRINCIPAL_H
