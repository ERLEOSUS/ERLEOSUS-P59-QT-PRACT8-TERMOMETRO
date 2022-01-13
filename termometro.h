#ifndef TERMOMETRO_H
#define TERMOMETRO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Termometro; }
QT_END_NAMESPACE

class Termometro : public QMainWindow
{
    Q_OBJECT

public:
    Termometro(QWidget *parent = nullptr);
    ~Termometro();

public slots:
    float cent2Fahr(int);
    float fahr2Cent(int);
    float kelv2Cent(int);
    void dialPresionado();
    void dialRelajado();

private:
    Ui::Termometro *ui;
};
#endif // TERMOMETRO_H
