#ifndef REY_H
#define REY_H

#include "pieza.h"

class rey : public pieza
{
public:
    rey(QString team,QGraphicsItem *parent = 0);
    void movimientos();
};

#endif // REY_H
