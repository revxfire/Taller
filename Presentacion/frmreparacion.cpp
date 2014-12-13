#include "frmreparacion.h"
#include "ui_frmreparacion.h"
#include <QCalendarWidget>

FrmReparacion::FrmReparacion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmReparacion)
{
    ui->setupUi(this);
}

FrmReparacion::~FrmReparacion()
{
    delete ui;
}



void FrmReparacion::on_btnNuevo_clicked()
{
    ui->lineOrden->setEnabled(true);
    ui->lineCI->setEnabled(true);
    ui->lineNombre->setEnabled(true);
    ui->lineFecha->setEnabled(true);
    ui->lineDireccion->setEnabled(true);
    ui->lineCorreo->setEnabled(true);
    ui->lineTelefonos->setEnabled(true);
    ui->lineDescripcion->setEnabled(true);
    ui->lineMarca->setEnabled(true);
    ui->lineModelo->setEnabled(true);
    ui->lineSerial->setEnabled(true);
    ui->lineContrasena->setEnabled(true);
    ui->textDano->setEnabled(true);
    ui->textNotas->setEnabled(true);


}
