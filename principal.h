#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QTimer>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <tablero.h>
#include "caja.h"
#include "pieza.h"
#include "boton.h"
class principal :public QGraphicsView
{
    Q_OBJECT
public:
    principal(QWidget *parent=0);
    void iniciar(); //Inicia todos los componentes
    void addItem(QGraphicsItem  *item);//Añade un elemento a la vista
    void remove(QGraphicsItem  *item);//Remueve un elemento de la vista
    void cambiarTurno(); //Cambia el turno actual
    void fichaMuerta(pieza *piece);//Indicamos que murio una pieza
    void muertaBlanca(pieza *piece);//Posicionamos la pieza muerta
    void muertaNegra(pieza *piece);//Posicionamos la pieza muerta
    void finJuego(QString);//Terminamos el juego
    void dibujarPanel(int x, int y, int ancho, int altura, QColor color, double opacidad);//Dibujamos un panel
    void dibujarPromocion(QString,int,int);//Dibujamos la promocion del peon
    void desactivarPromocion();//Quitamos la promocion del peon

    QString getTurno();//Devolvemos el turno
    caja *boxes[9][9];//Tablero
    tablero* chess= new tablero();
    pieza *piezaSeleccionada;
    QGraphicsTextItem *jaque;
    QGraphicsTextItem *reloj;

    QTimer *cronometro=new QTimer(this);//Cronometro

public slots:
    void funcionActivacionTimer();
    void habilitarCronometro();
    void reinaPromocion();
    void caballoPromocion();
    void torrePromocion();
    void alfilPromocion();
private:
    QGraphicsScene *Scene; //Vista
    QString turno;   //Turno
    QGraphicsTextItem *TurnoActual; //Vista del turno

    //Variables auxiliares para posicionar las fichas muertas

    //Blancas
    int auxMBX=0;
    int auxMBY=0;
    //Negras
    int auxMNX=0;
    int auxMNY=0;

    //Variables auxiliares para el control del tiempo

    //Titulo de los tiempos
    QGraphicsTextItem *tiempoRB;
    QGraphicsTextItem *tiempoRN;

    //Valores de los tiempos
    QGraphicsTextItem *tiempoB;
    QGraphicsTextItem *tiempoN;

    //Valor del cronometro
    int contador = 0;
    //Verificacion de si esta habilitado el cronometro
    int verfContador=0;// 0->desactivado 1->activado

    //Tiempo para cada equipo
    int contadorB=900;
    int contadorN=900;
    //Boton para habilitar el tiempo
    boton *HabilitarBoton;
    //Variables auxiliares para la promocion del peon

    //Titulo de la promocion
    QGraphicsTextItem *promocionTitulo;
    //Botones para seleccionar la promocion
    boton *reinaBoton;
    boton *caballoBoton;
    boton *torreBoton;
    boton *alfilBoton;
    //Variables para posicionar la promocion
    int auxPX=0;
    int auxPY=0;
    //Color de la promocion
    QString colorPromocion;

};



#endif // PRINCIPAL_H
