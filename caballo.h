#ifndef CABALLO_H
#define CABALLO_H

#include "pieza.h"

class caballo : public pieza
{
public:
    caballo(QString team, QGraphicsItem *parent = 0);
    void movimientos();
};

#endif // CABALLO_H
