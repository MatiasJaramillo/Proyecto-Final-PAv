#include "modificadordatos.h"
#include <QtDataVisualization>
#include <exception>
#include <iostream>
using namespace std;

ModificadorDatos::ModificadorDatos(Q3DScatter *grafica){
    graficaPC=nullptr;
    serieDatos=nullptr;
    datosProxy=nullptr;
    arregloDatos=nullptr;

    graficaPC=grafica;
    graficaPC->activeTheme()->setType(Q3DTheme::ThemeEbony);
    QFont font=graficaPC->activeTheme()->font();
    font.setPointSize(50);
    graficaPC->activeTheme()->setFont(font);
    graficaPC->setShadowQuality(QAbstract3DGraph::ShadowQualitySoftLow);
    graficaPC->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);

    datosProxy=new QScatterDataProxy;
    serieDatos=new QScatter3DSeries;
    serieDatos->setDataProxy(datosProxy);
    serieDatos->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel yTitle: @yLabel @zTitle: @zLabel"));
    serieDatos->setMeshSmooth(false);
    graficaPC->addSeries(serieDatos);
}
ModificadorDatos::~ModificadorDatos(){
    delete graficaPC;
    delete serieDatos;
    delete datosProxy;
    delete arregloDatos;
}
void ModificadorDatos::clearDatos(){
    try{
        while (!graficaPC->seriesList().isEmpty()) {
            graficaPC->removeSeries(graficaPC->seriesList().last());
        }

        delete arregloDatos;
        arregloDatos=nullptr;
        if(graficaPC->seriesList().isEmpty()){
            throw runtime_error("Lista vacia");
        }
    }
    catch(const exception& e){
        cout<<e.what()<<endl;
        return;
    }
}
void ModificadorDatos::crearGrafica(int x, int y, int z){
    clearDatos();

    QScatter3DSeries* newSeries = new QScatter3DSeries;
    serieDatos=newSeries;
    graficaPC->addSeries(serieDatos);

    graficaPC->axisX()->setTitle("X");
    graficaPC->axisY()->setTitle("Y");
    graficaPC->axisZ()->setTitle("Z");

    int itemCount=100;
    int limit=5;

    QScatterDataArray *updateArray = new QScatterDataArray;
    arregloDatos=updateArray;
    arregloDatos->resize(itemCount);
    QScatterDataItem *ptrToDataArray = &arregloDatos->first();

    setX(x);
    setY(y);
    setZ(z);

    QScatterDataArray *dataX=getX();
    QScatterDataArray *dataY=getY();
    QScatterDataArray *dataZ=getZ();
    QScatterDataItem *ptrDataArrayX = nullptr;
    QScatterDataItem *ptrDataArrayY = nullptr;
    QScatterDataItem *ptrDataArrayZ = nullptr;

    if (!dataX->isEmpty()) {
        ptrDataArrayX = &dataX->first();
    }

    if (!dataY->isEmpty()) {
        ptrDataArrayY = &dataY->first();
    }

    if (!dataZ->isEmpty()) {
        ptrDataArrayZ = &dataZ->first();
    }

    for(int i = 0; i < 100; i++){
        QVector3D vector;
        vector+=ptrDataArrayX->position();
        vector+=ptrDataArrayY->position();
        vector+=ptrDataArrayZ->position();
        ptrToDataArray->setPosition(vector);
        ptrToDataArray++;
        ptrDataArrayX++;
        ptrDataArrayY++;
        ptrDataArrayZ++;
    }
    cout<<"problema"<<endl;

    graficaPC->seriesList().at(0)->dataProxy()->resetArray(arregloDatos);
}
