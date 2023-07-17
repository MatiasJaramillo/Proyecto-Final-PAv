#include <QtDataVisualization/QScatterDataProxy>
#include <QVector3D>
#include "function.h"
//#include <Q3DCamera>
//#include <QAbstract3DGraph>
#ifndef MODIFICADORDATOS_H
#define MODIFICADORDATOS_H


class ModificadorDatos
{
private:
    Q3DScatter *graficaPC;
    QScatter3DSeries *serieDatos;
    QScatterDataProxy *datosProxy;
    QScatterDataArray *arregloDatos;
    Function *functions[3];
public:
    ModificadorDatos(Q3DScatter*);
    ~ModificadorDatos();

    void clearDatos();
    void crearGrafica(int,int,int);
    void changePerspective();
};

#endif // MODIFICADORDATOS_H
