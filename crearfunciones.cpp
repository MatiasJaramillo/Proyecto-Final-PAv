#include "crearfunciones.h"
#include <cmath>

CrearFunciones::CrearFunciones(){
    dataX=new QScatterDataArray;
    dataY=new QScatterDataArray;
    dataZ=new QScatterDataArray;
    dataX->resize(100);
    dataY->resize(100);
    dataZ->resize(100);
    ptrDataArrayX=&dataX->first();
    ptrDataArrayY=&dataY->first();
    ptrDataArrayZ=&dataZ->first();
    limit = 5;
}
void CrearFunciones::setX(int x){
    delete dataX;
    dataX=new QScatterDataArray;
    dataX->resize(100);
    ptrDataArrayX=&dataX->first();
    if(x==0){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayX->setPosition(QVector3D());
                ptrDataArrayX++;
            }
        }
    }
    else if(x==1){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayX->setPosition(QVector3D(i,sin(i),0));
                ptrDataArrayX++;
            }
        }
    }
    else if(x==2){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayX->setPosition(QVector3D(i,cos(i),0));
                ptrDataArrayX++;
            }
        }
    }
    else if(x==3){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayX->setPosition(QVector3D(i,i,0));
                ptrDataArrayX++;
            }
        }
    }
    else if(x==4){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayX->setPosition(QVector3D(i,i*i,0));
                ptrDataArrayX++;
            }
        }
    }
}
void CrearFunciones::setY(int y){
    delete dataY;
    dataY=new QScatterDataArray;
    dataY->resize(100);
    ptrDataArrayY=&dataY->first();
    if(y==0){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayY->setPosition(QVector3D());
                ptrDataArrayY++;
            }
        }
    }
    else if(y==1){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayY->setPosition(QVector3D(sin(j),j,0));
                ptrDataArrayY++;
            }
        }
    }
    else if(y==2){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayY->setPosition(QVector3D(cos(j),j,0));
                ptrDataArrayY++;
            }
        }
    }
    else if(y==3){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayY->setPosition(QVector3D(j,j,0));
                ptrDataArrayY++;
            }
        }
    }
    else if(y==4){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayY->setPosition(QVector3D(j*j,j,0));
                ptrDataArrayY++;
            }
        }
    }
}
void CrearFunciones::setZ(int z){
    delete dataZ;
    dataZ=new QScatterDataArray;
    dataZ->resize(100);
    ptrDataArrayZ=&dataZ->first();
    if(z==0){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayZ->setPosition(QVector3D());
                ptrDataArrayZ++;
            }
        }
    }
    else if(z==1){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayZ->setPosition(QVector3D(0,sin(i),i));
                ptrDataArrayZ++;
            }
        }
    }
    else if(z==2){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayZ->setPosition(QVector3D(0,cos(i),i));
                ptrDataArrayZ++;
            }
        }
    }
    else if(z==3){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayZ->setPosition(QVector3D(0,i,i));
                ptrDataArrayZ++;
            }
        }
    }
    else if(z==4){
        for (float i = -limit; i < limit; i++) {
            for (float j = -limit; j < limit; j++) {
                ptrDataArrayZ->setPosition(QVector3D(0,i*i,i));
                ptrDataArrayZ++;
            }
        }
    }
}
QScatterDataArray* CrearFunciones::getX(){
    return dataX;
}
QScatterDataArray* CrearFunciones::getY(){
    return dataY;
}
QScatterDataArray* CrearFunciones::getZ(){
    return dataZ;
}
