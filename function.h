#ifndef FUNCTION_H
#define FUNCTION_H
#include <cmath>
#include <iostream>
#include <Q3DScatter>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <qcombobox.h>
#include <QStringLiteral>
#include <QLabel>
#include <QObject>
#include <string>

using namespace std;
class Function
{
private:
    const int item_num;
    float c_step;
    float xlim,xlim2;
    float ylim,ylim2;
    float zlim,zlim2;

    float *fun_data;
public:
    Function();
    ~Function();

    void x();
    void my_cos();
    void my_sen();
    void my_xcos();
    void my_xsen();

    float* getFunData();
    int getItemnum();

};

#endif // FUNCTION_H
