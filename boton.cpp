#include "boton.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QDebug>
#include "principal.h"

boton::boton(QString texto, QGraphicsItem* parent): QGraphicsRectItem(parent)
{
    setRect(0,0,100,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // Posicionamos el texto
    text = new QGraphicsTextItem(texto,this);
    int x = rect().width()/2 - text->boundingRect().width()/2;
    int y = rect().height()/2 - text->boundingRect().height()/2 ;
    text->setPos(x,y);


}

void boton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Emitimos las señal de que se clikeo
    emit clicked();
}
void boton::setText(QString valor){
     // Posicionamos el texto
    text->setPlainText(valor);
    int x = rect().width()/2 - text->boundingRect().width()/2;
    int y = rect().height()/2 - text->boundingRect().height()/2 ;
    text->setPos(x,y);
}
QGraphicsTextItem* boton::getText(){
    return text;
}

