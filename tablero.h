#ifndef TABLERO_H
#define TABLERO_H

#include <QGraphicsRectItem>

#include "caja.h"
class tablero
{
public:
    tablero();
    void dibujarCajas(int x, int y);//Dibujamos las cajas
    void dibujarPiezas();//Añadimos las piezas
    void CrearFichasblancas();//Creamos las fichas Blancas
    void CrearFichasNegras();//Creamos las fichas Negras
private:
    QList <pieza *> FichasBlancas;//Lista de la piezas blancas
    QList <pieza *> FichasNegras;//Lista de la piezas negras
};

#endif // TABLERO_H
