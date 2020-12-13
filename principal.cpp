#include "principal.h"
#include "rey.h"
#include "caballo.h"
#include "reina.h"
#include "torre.h"
#include "alfil.h"
#include <QDebug>

principal::principal(QWidget *parent ):QGraphicsView(parent)
{
    //Creamos la escena
    setFixedSize(800,650);
    //Quitamos la barra de movimiento
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Creamos los componentes
    Scene= new QGraphicsScene();
    Scene->setSceneRect(0,0,800,650);
    //Inicializamos
    piezaSeleccionada=NULL;
    turno="White";
    setScene(Scene);
}
//Añade un elemento a la vista
void principal::addItem(QGraphicsItem  *item){
    Scene->addItem(item);
}
//Remueve un elemento de la vista
void principal::remove(QGraphicsItem *item){
    Scene->removeItem(item);
}
//Inicia todos los componentes
void principal::iniciar(){
    //Dibujamos el tablero
    chess->dibujarCajas(200,20);
    chess->dibujarPiezas();

    //Titulos de la zona de fichas muertas
    QGraphicsTextItem *fichasB= new QGraphicsTextItem("Fichas Blancas Perdidadas");
    fichasB->setPos(0,0);

    QGraphicsTextItem *fichasN= new QGraphicsTextItem("Fichas Negras Perdidadas");
    fichasN->setPos(650,0);

    //Añadimos los componentes a la ventana
    Scene->addItem(fichasB);
    Scene->addItem(fichasN);

    //Letras al borde del tablero
    int espacio=50;
    //Las letras a escribir
    QList <QString> letras;
    letras.append("A");
    letras.append("B");
    letras.append("C");
    letras.append("D");
    letras.append("E");
    letras.append("F");
    letras.append("G");
    letras.append("H");
    //Letras en la parte de arriba
    for(int i=0; i<8;i++){
        QGraphicsTextItem *fichas= new QGraphicsTextItem(letras[i]);
        fichas->setPos(i*espacio+ 220,0);
        Scene->addItem(fichas);
    }
    //Numeros en la parte izquierda
     for(int i=0,j=0; i<8;i++,j++){
         QString cad= QString::number(j+1);
         QGraphicsTextItem *fichas= new QGraphicsTextItem(cad);
         fichas->setPos(170,30+espacio*i);
         Scene->addItem(fichas);
     }
     //Letras en la parte de abajo
     for(int i=0; i<8;i++){
         QGraphicsTextItem *fichas= new QGraphicsTextItem(letras[i]);
         fichas->setPos(i*espacio+ 220,425);
         Scene->addItem(fichas);
     }
     //Numeros en la parte derecha
     for(int i=0,j=0; i<8;i++,j++){
         QString cad= QString::number(j+1);
         QGraphicsTextItem *fichas= new QGraphicsTextItem(cad);
         fichas->setPos(620,30+espacio*i);
         Scene->addItem(fichas);
     }

     //Indicacion de turno
     TurnoActual= new QGraphicsTextItem("Turno Actual : White");
     TurnoActual->setFont(QFont("",15));
     TurnoActual->setPos(200,460);
     Scene->addItem(TurnoActual);

     //Indicamos el jaque Mate
     jaque= new QGraphicsTextItem("Jaque");
     jaque->setFont(QFont("",15));
     jaque->setPos(400,460);
     jaque->setVisible(false);
     Scene->addItem(jaque);

    //Indicamos el boton para Habilitar el cronometro
     HabilitarBoton=new boton("Habilitar tiempo");
     HabilitarBoton->setPos(50,450);
     connect(HabilitarBoton,SIGNAL(clicked()),this,SLOT(habilitarCronometro()));
     Scene->addItem(HabilitarBoton);

     //Indicamos el reloj
     reloj= new QGraphicsTextItem(QString::number(contador));
     reloj->setFont(QFont("",15));
     reloj->setPos(20,450);
     reloj->setVisible(true);
     Scene->addItem(reloj);

     //Titulo Tiempo de las Blancas
     tiempoRB= new QGraphicsTextItem("Tiempo Restante de las blancas");
     tiempoRB->setFont(QFont("",10));
     tiempoRB->setPos(20,500);
     tiempoRB->setVisible(true);
     Scene->addItem(tiempoRB);

     //Tiempo de las Blancas
     tiempoB= new QGraphicsTextItem(QString::number(contadorB));
     tiempoB->setFont(QFont("",15));
     tiempoB->setPos(20,550);
     tiempoB->setVisible(true);
     Scene->addItem(tiempoB);

     //Titulo Tiempo de las Negras
     tiempoRN= new QGraphicsTextItem("Tiempo Restante de las negras");
     tiempoRN->setFont(QFont("",10));
     tiempoRN->setPos(600,500);
     tiempoRN->setVisible(true);
     Scene->addItem(tiempoRN);

     //Tiempo de las Negras
     tiempoN= new QGraphicsTextItem(QString::number(contadorN));
     tiempoN->setFont(QFont("",15));
     tiempoN->setPos(600,550);
     tiempoN->setVisible(true);
     Scene->addItem(tiempoN);

     //Conectamos el cronometro
     connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));

     //Titulo de la promocion
     promocionTitulo= new QGraphicsTextItem("Selecciona a que pieza se convertira el peon");
     promocionTitulo->setFont(QFont("",10));
     promocionTitulo->setPos(50,570);
     promocionTitulo->setVisible(false);
     Scene->addItem(promocionTitulo);


     //Indicamos el boton para promocion a reina
     reinaBoton=new boton("A reina");
     reinaBoton->setPos(50,600);
     reinaBoton->setVisible(false);
     reinaBoton->setEnabled(false);
     connect(reinaBoton,SIGNAL(clicked()),this,SLOT(reinaPromocion()));
     Scene->addItem(reinaBoton);

     //Indicamos el boton para promocion a reina
     caballoBoton=new boton("A Caballo");
     caballoBoton->setPos(160,600);
     caballoBoton->setVisible(false);
     caballoBoton->setEnabled(false);
     connect(caballoBoton,SIGNAL(clicked()),this,SLOT(caballoPromocion()));
     Scene->addItem(caballoBoton);

     //Indicamos el boton para promocion a torre
     torreBoton=new boton("A Torre");
     torreBoton->setPos(270,600);
     torreBoton->setVisible(false);
     torreBoton->setEnabled(false);
     connect(torreBoton,SIGNAL(clicked()),this,SLOT(torrePromocion()));
     Scene->addItem(torreBoton);

     //Indicamos el boton para promocion a alfil
     alfilBoton=new boton("A Alfil");
     alfilBoton->setPos(380,600);
     alfilBoton->setVisible(false);
     alfilBoton->setEnabled(false);
     connect(alfilBoton,SIGNAL(clicked()),this,SLOT(alfilPromocion()));
     Scene->addItem(alfilBoton);

}
//Cambia el turno actual
void principal::cambiarTurno(){
    if (turno=="White"){
        turno="Black";
    }else{
        turno="White";
    }
    this->TurnoActual->setPlainText("Turno Actual : "+this->getTurno());
    contador=0;
}
//Devolvemos el turno
QString principal::getTurno(){
    return this->turno;
}
//Indicamos que murio una pieza
void principal::fichaMuerta(pieza *piece){
    //Verificamos el equipo para desplazarla a la zona de muerte
    if(piece->getEquipo()=="White"){
        this->muertaBlanca(piece);
    }else{
        this->muertaNegra(piece);
    }
}
void principal::muertaBlanca(pieza *piece){
     //Verificamos si la pieza muerta es un rey
    rey *king = dynamic_cast <rey *>(piece);
    if(king){
        qDebug() << "Rey blanco muerto";
        this->finJuego("Black");
    }
     //Posicionamos la ficha
    piece->setPos(50*auxMBX,15+auxMBY);
    if(auxMBX==2){
        auxMBX=0;
        auxMBY=auxMBY+60;
    }else{
        auxMBX++;
    }
}
void principal::muertaNegra(pieza *piece){
    //Verificamos si la pieza muerta es un rey
    rey *king = dynamic_cast <rey *>(piece);
    if(king){
        qDebug() << "Rey Negro muerto";
        this->finJuego("White");
    }
    //Posicionamos la ficha
    piece->setPos(630+50*auxMNX,15+auxMNY);
    if(auxMNX==2){
        auxMNX=0;
        auxMNY=auxMNY+60;
    }else{
        auxMNX++;
    }
}
void principal::finJuego(QString ganador){
    //Desabilitamos todos los item de la escena
    for (size_t i=0,n=Scene->items().size(); i<n ;i++){
        Scene->items()[i]->setEnabled(false);
    }

    QGraphicsTextItem* mensaje = new QGraphicsTextItem(ganador);
    cronometro->stop();
    QColor color2(128,128,128);
    if(ganador=="White"){
        mensaje->setPlainText("GANADOR BLANCAS");
        QColor color(245,176,65);

        //panel semitransparente
        dibujarPanel(0,0,1024,768,color,0.65);

        //dibujar panel
        dibujarPanel(250,150,320,200,color2,0.75);
    }else{
         mensaje->setPlainText("GANADOR NEGRAS");
        QColor color(192,57,43);
        //panel semitransparente
        dibujarPanel(0,0,1024,768,color,0.65);
        //dibujar panel
        dibujarPanel(250,150,320,200,color2,0.75);
    }
       //mensaje del panel de Victoria
       mensaje->setPos(270,200);
       mensaje->setFont(QFont("",15));
       Scene->addItem(mensaje);
}
//Dibujamos un panel
void principal::dibujarPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    Scene->addItem(panel);
}
//Dibujamos la promocion del peon
void principal::dibujarPromocion(QString equipo,int x,int y){
    //Desactivamos los demas elementos
    for (size_t i=0,n=Scene->items().size(); i<n ;i++){
        Scene->items()[i]->setEnabled(false);
    }

    //Cargamos las varaibles auxiliares
    this->auxPX=x;
    this->auxPY=y;
    colorPromocion=equipo;
    //Habilitamos los elementos para que se escoja la promocion
    promocionTitulo->setVisible(true);

    reinaBoton->setVisible(true);
    reinaBoton->setEnabled(true);
    reinaBoton->getText()->setEnabled(true);

    caballoBoton->setVisible(true);
    caballoBoton->setEnabled(true);
    caballoBoton->getText()->setEnabled(true);

    torreBoton->setVisible(true);
    torreBoton->setEnabled(true);
    torreBoton->getText()->setEnabled(true);

    alfilBoton->setVisible(true);
    alfilBoton->setEnabled(true);
    alfilBoton->getText()->setEnabled(true);
}
//Quitamos la promocion del peon
void principal::desactivarPromocion(){
    //Activamos los  elementos
    for (size_t i=0,n=Scene->items().size(); i<n ;i++){
        Scene->items()[i]->setEnabled(true);
    }
    if(verfContador==1){
        cronometro->start(1000);
    }
    //Desabilitamos los elementos para que se escoja la promocion
    promocionTitulo->setVisible(false);

    reinaBoton->setVisible(false);
    reinaBoton->setEnabled(false);

    caballoBoton->setVisible(false);
    caballoBoton->setEnabled(false);

    torreBoton->setVisible(false);
    torreBoton->setEnabled(false);

    alfilBoton->setVisible(false);
    alfilBoton->setEnabled(false);

}
//SLOTS

//Funcion del cronometro, se usara cada segundo que pase
void principal::funcionActivacionTimer(){
    //Aumentamos el contador
    contador++;
    //Lo actualizamos en la vista
    this->reloj->setPlainText(QString::number(contador));
    //Dependiendo del turno se quita el tiempo
    if (this->getTurno()=="White"){
        contadorB--;
        //si el tiempo llega a 0 ganan las negras
        this->tiempoB->setPlainText(QString::number(contadorB));
        if (contadorB==0){
            this->finJuego("Black");
        }
    }else{
        contadorN--;
        //si el tiempo llega a 0 ganan las blancas
        this->tiempoN->setPlainText(QString::number(contadorN));
        if (contadorN==0){
            this->finJuego("White");
        }
    }

}
//Habilitamos el cronometro
void principal::habilitarCronometro(){
    //Si no esta activado, lo activamos
    if (verfContador==0){
        cronometro->start(1000);
        verfContador=1;
        this->HabilitarBoton->setText("Desactivar Tiempo");
     //Si esta activado, lo desactivamos
    }else{
        cronometro->stop();
        verfContador=0;
        this->HabilitarBoton->setText("Habilitar Tiempo");

    }
    contador=0;
    this->reloj->setPlainText(QString::number(contador));
}
//Metodos para la promocion del peon, se agrega la pieza
//correspondiente en la posicion correspondiente
void principal::reinaPromocion(){
    reina* prueba= new reina(colorPromocion);
    boxes[auxPX][auxPY]->addPieza(prueba);
    this->addItem(prueba);

    this->desactivarPromocion();
}
void principal::caballoPromocion(){
    caballo* prueba= new caballo(colorPromocion);
    boxes[auxPX][auxPY]->addPieza(prueba);
    this->addItem(prueba);

     this->desactivarPromocion();
}
void principal::torrePromocion(){
    torre* prueba= new torre(colorPromocion);
    boxes[auxPX][auxPY]->addPieza(prueba);
    this->addItem(prueba);

     this->desactivarPromocion();
}
void principal::alfilPromocion(){
    alfil* prueba= new alfil(colorPromocion);
    boxes[auxPX][auxPY]->addPieza(prueba);
    this->addItem(prueba);

     this->desactivarPromocion();
}
