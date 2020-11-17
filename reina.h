#ifndef REINA_H
#define REINA_H

#include "pieza.h"

class reina : public pieza
{
public:
    reina(QString team,QGraphicsItem *parent = 0);
    void movimientos();
};

#endif // REINA_H
