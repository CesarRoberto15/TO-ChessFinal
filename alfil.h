#ifndef ALFIL_H
#define ALFIL_H
#include "pieza.h"

class alfil:public pieza
{
public:
    alfil(QString team,QGraphicsItem *parent = 0);
    void movimientos();
};

#endif // ALFIL_H
