#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsRectItem>

#include "caja.h"
class tablero
{
public:
    tablero();
    void dibujarCajas(int x, int y);
    void dibujarPiezas();
    void addPieza();
    void CrearFichasblancas();
    void CrearFichasNegras();
private:
    QList <pieza *> FichasBlancas;
    QList <pieza *> FichasNegras;
};

#endif // TABLERO_H
