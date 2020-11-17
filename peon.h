#ifndef PEON_H
#define PEON_H


#include "pieza.h"

class peon : public pieza
{
public:
    peon(QString team,QGraphicsItem *parent = 0);;
    void movimientos();

};

#endif // PEON_H
