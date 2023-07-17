#include "function.h"

Function::Function()
    :item_num(100),xlim(6),xlim2(-6),ylim(6),ylim2(-6), zlim(6),zlim2(-6)
{
    //se inicializa los valores para el paso de incremento y tambien el arreglo de valores para la grafica.
    this->c_step=(xlim-xlim2)/item_num;

    fun_data= new float[item_num+1];
}
Function::~Function(){
    delete fun_data;
}
//funcion identidad se agrega al arreglo de valores
void Function::x(){
    for(int i=0; i<item_num+1; i++){
        fun_data[i]= xlim2+ (i*c_step);
    }
}
//funcion xsen se agrega al arreglo de valores
void Function:: my_xsen(){
    for(int i=0; i<item_num+1; i++){
        fun_data[i]= (xlim2+ (i*c_step))*sin(xlim2+ (i*c_step));
    }
}
//funcion xcos se agrega al arreglo de valores
void Function:: my_xcos(){
    for(int i=0; i<item_num+1; i++){
        fun_data[i]= (xlim2+ (i*c_step))*::cos(xlim2+ (i*c_step));
    }
}
//funcion seno se agrega al arreglo de valores
void Function:: my_sen(){
    for(int i=0; i<item_num+1; i++){
        fun_data[i]= sin(xlim2+ (i*c_step));
    }
}
//funcion coseno se agrega al arreglo de valores
void Function:: my_cos(){
    for(int i=0; i<item_num+1; i++){
        fun_data[i]=cos(xlim2+ (i*c_step));
    }
}
float* Function::getFunData(){
    return fun_data;
}
int Function::getItemnum(){
    return item_num;
}

