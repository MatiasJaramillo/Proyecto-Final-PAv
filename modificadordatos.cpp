#include "modificadordatos.h"
#include <QtDataVisualization>
#include <exception>
#include <iostream>
using namespace std;

ModificadorDatos::ModificadorDatos(Q3DScatter *grafica){
    //se inicializan los punteros como nulos.
    graficaPC=nullptr;
    serieDatos=nullptr;
    datosProxy=nullptr;
    arregloDatos=nullptr;

    //Características generales de la grafica
    graficaPC=grafica;//Inicializacion del dato miembro de la clase con el objeto grafica del codigo main
    graficaPC->activeTheme()->setType(Q3DTheme::ThemeEbony); //Eleccion de tema para la grafica
    QFont font=graficaPC->activeTheme()->font();
    //Configuracion de la funte con la  que se muestran los datos en la grafica
    font.setPointSize(50);
    graficaPC->activeTheme()->setFont(font);
    graficaPC->setShadowQuality(QAbstract3DGraph::ShadowQualitySoftLow); //Configuracion de la calidad de sombras
    graficaPC->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront); //Configuracion de la posicion inicial de la camara

    datosProxy=new QScatterDataProxy;//Inicializacion de los punteros
    serieDatos=new QScatter3DSeries(datosProxy);
    serieDatos->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel yTitle: @yLabel @zTitle: @zLabel"));//Se añade una etique a cada elemento de la serie de datos
    serieDatos->setMeshSmooth(false);
    graficaPC->addSeries(serieDatos);//se añade la serie a la grafica

    //se crean las instancias de las funciones en x,y,z.
    functions[0]=new Function;
    functions[1]=new Function;
    functions[2]=new Function;
}
ModificadorDatos::~ModificadorDatos(){
    //se liberan todos los espacios de memoria utilizados.
    delete graficaPC;
    delete serieDatos;
    delete datosProxy;
    delete arregloDatos;
    for(int i=0;i<3;i++){
        delete functions[i];
    }
    cout<<"Espacio en memoria liberado correctamente"<<endl;
}
void ModificadorDatos::changePerspective(){
    //se va cambiando entre las posiciones de la camara.
    static int preset = Q3DCamera::CameraPresetFrontLow;

    graficaPC->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)preset);

    if (++preset > Q3DCamera::CameraPresetDirectlyBelow){
        preset = Q3DCamera::CameraPresetFrontLow;
    }
}
void ModificadorDatos::clearDatos(){
    //se eliminan los datos de la serie de datos de la grafica
    //se incluye un manejo de excepciones para revisar que la grafica no este vacia, ya que en ese caso no se debe borrar.
    try{
        while (!graficaPC->seriesList().isEmpty()) {
            graficaPC->removeSeries(graficaPC->seriesList().last());
        }

        //se libera la memoria del arreglo de datos de la serie de la grafica.
        delete arregloDatos;
        arregloDatos=nullptr;

        //se vuelve a inicializar la serie de datos ya que el espacio que ocupaba fue liberado.
        QScatter3DSeries* newSeries = new QScatter3DSeries;
        serieDatos=newSeries;
        graficaPC->addSeries(serieDatos);
        cout<<endl<<"Datos borrados y reseteados"<<endl;

        if(graficaPC->seriesList().isEmpty()){
            throw runtime_error("Serie vacia");
        }
    }
    catch(const exception& eClear){
        cout<<eClear.what()<<endl;
        return;
    }
}
void ModificadorDatos::crearGrafica(int x, int y, int z){
    clearDatos();

    cout<<endl<<"Indices seleccionados:"<<endl;
    cout<<x<<" "<<y<<" "<<z<<endl;

    //dependiendo de lo que ingresa el usuario en el menu desplegable se crea la respectiva funcion en x.
    switch(x){
    case 1:
        functions[0]->my_cos();
        break;
    case 2:
        functions[0]->my_sen();
        break;
    case 3:
        functions[0]->my_xcos();
        break;
    case 4:
        functions[0]->my_xsen();
        break;
    case 5:
        functions[0]->x();
        break;
    default:
        break;
    }
    cout<<"Funcion en X cargada"<<endl;

    //dependiendo de lo que ingresa el usuario en el menu desplegable se crea la respectiva funcion en y.
    switch(y){
    case 1:
        functions[1]->my_cos();
        break;
    case 2:
        functions[1]->my_sen();
        break;
    case 3:
        functions[1]->my_xcos();
        break;
    case 4:
        functions[1]->my_xsen();
        break;
    case 5:
        functions[1]->x();
        break;
    default:
        break;
    }
    cout<<"Funcion en Y cargada"<<endl;

    //dependiendo de lo que ingresa el usuario en el menu desplegable se crea la respectiva funcion en z.
    switch(z){
    case 1:
        functions[2]->my_cos();
        break;
    case 2:
        functions[2]->my_sen();
        break;
    case 3:
        functions[2]->my_xcos();
        break;
    case 4:
        functions[2]->my_xsen();
        break;
    case 5:
        functions[2]->x();
        break;
    default:
        break;
    }
    cout<<"Funcion en Z cargada"<<endl;

    //Se inicializa de nuevo el arreglo de datos con una nueva referencia de memoria
    QScatterDataArray *updateArray = new QScatterDataArray;
    arregloDatos=updateArray;
    //Se define el tamaño del arreglo
    arregloDatos->resize(functions[0]->getItemnum()+1);
    //Se define un puntero que apunte a la primera posicion del arreglo de datos
    QScatterDataItem *ptrToDataArray = &arregloDatos->first();


    //Mediante un lazo se itera sobre cada una de las posiciones del arreglo y se asignan valores a cada una de las componentes del arreglo de datos
    for(int i=0; i<(functions[0]->getItemnum()+1); i++){
        ptrToDataArray->setPosition(QVector3D(functions[0]->getFunData()[i],functions[1]->getFunData()[i],functions[2]->getFunData()[i]));
        ptrToDataArray++;
    }

    //Se maneja una excepcion para asegurarse de que existan elementos que graficar
    try{
        //se añade la serie a la grafica y se muestra en pantalla

        graficaPC->seriesList().at(0)->dataProxy()->resetArray(arregloDatos);
        cout<<"Grafica cargada"<<endl;

        //Si la serie esta vacia se lanza una excepcion
        if(graficaPC->seriesList().isEmpty()){
            throw runtime_error("Serie grafica vacia");
        }
    }
    //Se atrapa la excepcion y se muestra en la terminal
    catch(const exception& eGraficar){
        cout<<eGraficar.what()<<endl;
        return;
    }
}
