#include "mainwindow.h"
#include <QApplication>
#include "Presentacion/frmcamara.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrmCamara w;
    w.show();

    return a.exec();
}
