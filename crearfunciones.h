#include <QVector3D>
#include <QtDataVisualization>
#ifndef CREARFUNCIONES_H
#define CREARFUNCIONES_H



class CrearFunciones
{
private:
    QScatterDataArray *dataX;
    QScatterDataItem *ptrDataArrayX;
    QScatterDataArray *dataY;
    QScatterDataItem *ptrDataArrayY;
    QScatterDataArray *dataZ;
    QScatterDataItem *ptrDataArrayZ;
    float limit;
public:
    CrearFunciones();
    void setX(int);
    void setY(int);
    void setZ(int);
    QScatterDataArray* getX();
    QScatterDataArray* getY();
    QScatterDataArray* getZ();
};

#endif // CREARFUNCIONES_H
