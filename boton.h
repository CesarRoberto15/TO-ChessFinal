#ifndef BOTON_H
#define BOTON_H

#include <QGraphicsRectItem>


class boton :  public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    boton(QString name, QGraphicsItem* parent=NULL);//Constructor
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setText(QString);
     QGraphicsTextItem* getText();
signals:
    void clicked();
private:
     QGraphicsTextItem* text;


};

#endif // BOTON_H
