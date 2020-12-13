#ifndef CAJA_H
#define CAJA_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "pieza.h"

class pieza;
class caja: public QGraphicsRectItem
{

public:
    caja(QGraphicsItem *parent=0);
    void addPieza(pieza *peace);//Añadimos la pieza a la caja
    void setOriginalColor(QColor);//Establecemos el color original
    void setColor(QColor);//Actualizamos el color
    void resetColor();//Volvemos al color original
    void mousePressEvent(QGraphicsSceneMouseEvent *event);//Evento mouse
    QString getColorPiece();//Obtenemos el color de la pieza almacenda
    void verificarJaque();//Verificamos si hacemos Jaque
    void verificarPromocion();//Verificamos si hay peon en promocion

    pieza *data; //Pieza almacenada
    bool lleno; //Si esta vacio o no
    QColor colorOriginal; //Color original
    int row; //Fila
    int col; //Columna
    QBrush brush;
    QString piezaColor;
};

#endif // CAJA_H
