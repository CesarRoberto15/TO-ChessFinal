#ifndef CAJA_H
#define CAJA_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "pieza.h"
class pieza;
class caja : public QGraphicsRectItem
{
public:
    caja(QGraphicsItem *parent=0);
    void addPieza(pieza *peace);
    void setOriginalColor(QColor);
    void setColor(QColor);
    void resetColor();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QString getColorPiece();

    pieza *data;
    bool lleno;
    QColor colorOriginal;
    int row;
    int col;
    QBrush brush;
    QString piezaColor;
};

#endif // CAJA_H
