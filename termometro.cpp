#include "termometro.h"
#include "ui_termometro.h"
#include <QDebug>

Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);

    connect(ui->dialCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Fahr(int)));
    connect(ui->dialFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Cent(int)));
    connect(ui->dialKel, SIGNAL(valueChanged(int)),
            this, SLOT(kelv2Cent(int)));

    connect(ui->dialCent, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));
    connect(ui->dialFahr, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));

    connect(ui->dialCent, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));
    connect(ui->dialFahr, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));

    ui->dialFahr->setValue(32);

}

Termometro::~Termometro()
{
    delete ui;
}

float Termometro::cent2Fahr(int valor)
{
    if (ui->dialCent->hasFocus()){
        float f = valor * 9.0/5 + 32;
        float k= valor+273.15;
        ui->dialFahr->setValue(f);
        ui->dialKel->setValue(k);
        return f;
    }
    return 0;
}

float Termometro::fahr2Cent(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float c = (valor - 32) * 5.0/9;
        ui->dialCent->setValue(c);
        return c;
    }
    return 0;
}

float Termometro::kelv2Cent(int valor)
{
    if(ui->dialKel->hasFocus()){
        float c = valor - 273.15;
        float f= 1.8*(valor-273)+32;
        ui->dialFahr->valueChanged(f);
        ui->dialCent->setValue(c);
        return c;
    }
    return 0;
}

void Termometro::dialPresionado()
{
    // if (ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::ClosedHandCursor);
    // }else{
        ui->dialFahr->setCursor(Qt::ClosedHandCursor);
    // }
}

void Termometro::dialRelajado()
{
    // if (ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::ArrowCursor);
    // }else{
        ui->dialFahr->setCursor(Qt::ArrowCursor);
    // }

}
