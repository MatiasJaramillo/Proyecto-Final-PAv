#include "crearfunciones.h"
#include <QtDataVisualization/QScatterDataProxy>
#include <QVector3D>
//#include <Q3DCamera>
//#include <QAbstract3DGraph>
#ifndef MODIFICADORDATOS_H
#define MODIFICADORDATOS_H


class ModificadorDatos : public CrearFunciones
{
private:
    Q3DScatter *graficaPC;
    QScatter3DSeries *serieDatos;
    QScatterDataProxy *datosProxy;
    QScatterDataArray *arregloDatos;
public:
    ModificadorDatos(Q3DScatter*);
    ~ModificadorDatos();
    void clearDatos();
    void crearGrafica(int,int,int);
};

#endif // MODIFICADORDATOS_H
