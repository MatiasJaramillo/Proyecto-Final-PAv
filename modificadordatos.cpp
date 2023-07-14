#include "modificadordatos.h"
#include <QtDataVisualization>
//QScatter3DSeries *datosScatter

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

    /*graficaPC->axisX()->setTitle("X");
    graficaPC->axisY()->setTitle("Y");
    graficaPC->axisZ()->setTitle("Z");

    int m_itemCount=100;
    int m_curveDivider=10;

    arregloDatos = new QScatterDataArray;
    arregloDatos->resize(m_itemCount);
    QScatterDataItem *ptrToDataArray = &arregloDatos->first();

    float limit = qSqrt(m_itemCount) / 2.0f;
    for (float i = -limit; i < limit; i++) {
        for (float j = -limit; j < limit; j++) {
            ptrToDataArray->setPosition(QVector3D(i + 0.5f,
                                                  qCos(qDegreesToRadians((i * j) / m_curveDivider)),
                                                  j + 0.5f));
            ptrToDataArray++;
        }
    }

    graficaPC->seriesList().at(0)->dataProxy()->resetArray(arregloDatos);*/
}
ModificadorDatos::~ModificadorDatos(){
    delete graficaPC;
    delete serieDatos;
    delete datosProxy;
    delete arregloDatos;
}
void ModificadorDatos::clearDatos(){
    //try,throw,and catch para cuando no hay una list existente.
    //puede ser aqui
    int longitudScatter = graficaPC->seriesList().length();
    if(graficaPC->seriesList().length()==0){
        return;
    }
    else{
        for(int i=0;i<longitudScatter;i++){
            graficaPC->removeSeries(graficaPC->seriesList().at(0)); //Elimina todas las series de la grafica
        }
    }
    delete arregloDatos;
}
void ModificadorDatos::crearGrafica(int x, int y, int z){
    //clearDatos();

    graficaPC->axisX()->setTitle("X");
    graficaPC->axisY()->setTitle("Y");
    graficaPC->axisZ()->setTitle("Z");

    int itemCount=100;
    int limit=5;

    arregloDatos = new QScatterDataArray;
    arregloDatos->resize(itemCount);
    QScatterDataItem *ptrToDataArray = &arregloDatos->first();

    //problema puede ser aqui
    setX(x);
    setY(y);
    setZ(z);

    //puede ser aqui
    QScatterDataArray *dataX=getX();
    QScatterDataArray *dataY=getY();
    QScatterDataArray *dataZ=getZ();
    QScatterDataItem *ptrDataArrayX = &dataX->first();
    QScatterDataItem *ptrDataArrayY = &dataY->first();
    QScatterDataItem *ptrDataArrayZ = &dataZ->first();

    //puede ser aqui
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
    graficaPC->seriesList().at(0)->dataProxy()->resetArray(arregloDatos);
}
