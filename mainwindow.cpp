#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Funciones/fclientes.h"
#include "Presentacion/frmclientes.h"
#include "Presentacion/frmreparacion.h"
#include "Presentacion/frmagenda.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow::on_actionModulo_triggered()
{
    FrmClientes *frmclientes = new FrmClientes(this);
    this->ui->mdiArea->addSubWindow(frmclientes);
    frmclientes->show();
}

void MainWindow::on_actionReparaciones_triggered()
{
    FrmReparacion *frmreparacion = new FrmReparacion(this);
    this->ui->mdiArea->addSubWindow(frmreparacion);
    frmreparacion->show();
}

void MainWindow::on_actionSalir_triggered()
{
    this->close();
}

void MainWindow::on_actionAgenda_triggered()
{
    FrmAgenda *frmagenda = new FrmAgenda(this);
    this->ui->mdiArea->addSubWindow(frmagenda);
    frmagenda->show();
}
