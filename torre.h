#ifndef TORRE_H
#define TORRE_H

#include "pieza.h"

class torre : public pieza
{
public:
    torre(QString team, QGraphicsItem *parent=0);
    void movimientos();
};

#endif // TORRE_H
