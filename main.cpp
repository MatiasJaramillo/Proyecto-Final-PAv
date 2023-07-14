#include <iostream>
#include <QtDataVisualization>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QObject>
#include <QLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
#include "modificadordatos.h"
#include "crearfunciones.h"

int main(int argc, char *argv[])
{
    QApplication appProyecto(argc, argv);
    Q3DScatter *grafica=new Q3DScatter;//se crea una instancia de un objeto Q3DScatter
    QWidget *contenedorGrafica=QWidget::createWindowContainer(grafica);//se contiene el objeto Q3DScatter adentro de un window container

    QWidget *contenedorGeneral=new QWidget;//se crea un contenedor general o un div para contener todos los elementos de la aplicacion
    contenedorGeneral->setWindowTitle("Proyecto Final: Mateo Salazar & Matias Jaramillo");
    contenedorGeneral->setMinimumSize(1000,600);
    QHBoxLayout *divHorizontal=new QHBoxLayout(contenedorGeneral);//se crea un contenedor de tipo horizontal/fila para contener elementos en fila
    QVBoxLayout *divVertical=new QVBoxLayout();//se crea un contenedor de tipo verrtical/columna para contener elementos en columna
    divHorizontal->addWidget(contenedorGrafica,1);
   /*se incluye el elemento donde se encuentra el objeto 3DScatter en
    la ultima posicion del contenedor horizontal, se le da un valor de
    strech de 1 para evitar la deformacion de la grafica */
    divHorizontal->addLayout(divVertical);//se incluye igualmente el contenedor vertical en el dic horizontal en la ultima posicion, es decir, a la derecha de la grafica

    QPushButton *botonPerspectiva=new QPushButton(contenedorGeneral);
    botonPerspectiva->setText("Cambiar Perspectiva");
    botonPerspectiva->setFixedHeight(45);

    QPushButton *botonClear=new QPushButton(contenedorGeneral);
    botonClear->setText("Reset Grafica");
    botonClear->setFixedHeight(45);

    QComboBox *coorX=new QComboBox(contenedorGeneral);
    coorX->addItem(QStringLiteral("Vacio"));
    coorX->addItem(QStringLiteral("Seno"));
    coorX->addItem(QStringLiteral("Coseno"));
    coorX->addItem(QStringLiteral("Lineal"));
    coorX->addItem(QStringLiteral("Cuadratica"));
    coorX->setCurrentIndex(1);

    QComboBox *coorY=new QComboBox(contenedorGeneral);
    coorY->addItem(QStringLiteral("Vacio"));
    coorY->addItem(QStringLiteral("Seno"));
    coorY->addItem(QStringLiteral("Coseno"));
    coorY->addItem(QStringLiteral("Lineal"));
    coorY->addItem(QStringLiteral("Cuadratica"));
    coorY->setCurrentIndex(1);

    QComboBox *coorZ=new QComboBox(contenedorGeneral);
    coorZ->addItem(QStringLiteral("Vacio"));
    coorZ->addItem(QStringLiteral("Seno"));
    coorZ->addItem(QStringLiteral("Coseno"));
    coorZ->addItem(QStringLiteral("Lineal"));
    coorZ->addItem(QStringLiteral("Cuadratica"));
    coorZ->setCurrentIndex(1);

    QPushButton *botonGraficar=new QPushButton(contenedorGeneral);
    botonGraficar->setText("Graficar");
    botonGraficar->setFixedHeight(60);

    QPushButton *botonClose=new QPushButton(contenedorGeneral);
    botonClose->setText("Cerrar Apliacion");
    botonClose->setFixedHeight(40);

    QMessageBox *clearWarning=new QMessageBox(QMessageBox::Warning,"Reset Grafica","Estas seguro que quieres resetear la grafica?",QMessageBox::Yes|QMessageBox::No);

    QMessageBox *closeWarning=new QMessageBox(QMessageBox::Warning,"Cerrar Aplicacion","Estas seguro que quieres cerrar la aplicacion?",QMessageBox::Yes|QMessageBox::No);

    divVertical->addWidget(botonPerspectiva,0,Qt::AlignTop);
    divVertical->addWidget(botonClear,0,Qt::AlignTop);
    divVertical->addSpacing(70);
    divVertical->addWidget(new QLabel(QStringLiteral("Funcion con respecto a X")));
    divVertical->addWidget(coorX);
    divVertical->addWidget(new QLabel(QStringLiteral("Funcion con respecto a Y")));
    divVertical->addWidget(coorY);
    divVertical->addWidget(new QLabel(QStringLiteral("Funcion con respecto a Z")));
    divVertical->addWidget(coorZ);
    divVertical->addWidget(botonGraficar,3,Qt::AlignTop);
    divVertical->addWidget(botonClose,0,Qt::AlignBottom);

    //std::cout<<selectX<<" "<<selectY<<" "<<selectZ<<std::endl;

    ModificadorDatos *modificador=new ModificadorDatos(grafica);

    QObject::connect(botonClear, &QPushButton::clicked, [=]() {
                            clearWarning->exec();
                            if(clearWarning->result()==QMessageBox::Button::Yes){
                                modificador->clearDatos();
                            }
                        }
                     );

    QObject::connect(botonGraficar, &QPushButton::clicked, [=]() {
                            int selectX = coorX->currentIndex();
                            int selectY = coorY->currentIndex();
                            int selectZ = coorZ->currentIndex();
                            modificador->crearGrafica(selectX, selectY, selectZ);
                        }
                     );

    QObject::connect(botonClose, &QPushButton::clicked, [closeWarning] {
                            closeWarning->exec();
                            if(closeWarning->result()==QMessageBox::Button::Yes){
                                QApplication::quit();
                            }
                        }
                     );

    contenedorGeneral->show();
    return appProyecto.exec();
}
