#include "frmclientes.h"
#include "ui_frmclientes.h"
#include "Modelos/mclientes.h"
#include "Funciones/fclientes.h"
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>

FrmClientes::FrmClientes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmClientes)
{
    ui->setupUi(this);

    //FORM LOAD
    llenarTabla();
    llenarCbBusqueda();
}

FrmClientes::~FrmClientes()
{
    delete ui;
}

void FrmClientes::limpiar(){
    ui->lineCI->clear();
    ui->lineNombre->clear();
    ui->lineApellido->clear();
    ui->lineDireccion->clear();
    ui->lineTelefono->clear();
    ui->lineCorreo->clear();
    ui->btnGuardar->setText("Guardar");
    this->botonModificar = false;
}

void FrmClientes::llenarTabla(){

    mconexion.Conectar();
    model->setQuery("SELECT * FROM CLIENTES");
    model->setHeaderData(0,Qt::Horizontal,"CI/RIF");
    model->setHeaderData(1,Qt::Horizontal,"Nombre");
    model->setHeaderData(2,Qt::Horizontal,"Apellido");
    model->setHeaderData(3,Qt::Horizontal,"Direccion");
    model->setHeaderData(4,Qt::Horizontal,"Telefono");
    model->setHeaderData(5,Qt::Horizontal,"Correo");
    ui->tablaListado->setModel(model);
}

bool FrmClientes::verificarErrores()
{
//TODO: Terminar verificaciones.
    bool bandera = false;
    if(ui->lineCI->text().length() > 0){
        bandera = true;
    }
    else
        bandera = false;

    if(ui->lineNombre->text().length() > 0){
        bandera = true;
    }
    else
        bandera = false;
    if(ui->lineApellido->text().length() > 0){
        bandera = true;
    }
    else
        bandera = false;
    if(ui->lineDireccion->text().length() > 0){
        bandera = true;
    }
    else
        bandera = false;
    if(ui->lineTelefono->text().length() > 0){
        bandera = true;
    }
    else
        bandera = false;
    if(ui->lineCorreo->text().length() > 0){
        bandera = true;
    }
    else
        bandera = false;

    return bandera;

}

void FrmClientes::on_btnNuevo_clicked()
{
    limpiar();
    ui->btnGuardar->setText("Guardar");
    this->botonModificar = true;
}

void FrmClientes::on_tablaListado_clicked(const QModelIndex &index)
{
    //LLENANDO LINEEDITS
    ui->lineCI->setText(ui->tablaListado->model()->data(ui->tablaListado->model()->index(index.row(),0)).toString());
    ui->lineNombre->setText(ui->tablaListado->model()->data(ui->tablaListado->model()->index(index.row(),1)).toString());
    ui->lineApellido->setText(ui->tablaListado->model()->data(ui->tablaListado->model()->index(index.row(),2)).toString());
    ui->lineDireccion->setText(ui->tablaListado->model()->data(ui->tablaListado->model()->index(index.row(),3)).toString());
    ui->lineTelefono->setText(ui->tablaListado->model()->data(ui->tablaListado->model()->index(index.row(),4)).toString());
    ui->lineCorreo->setText(ui->tablaListado->model()->data(ui->tablaListado->model()->index(index.row(),5)).toString());
    ui->btnGuardar->setText("Modificar");
    this->botonModificar = false;
}

void FrmClientes::on_btnGuardar_clicked()
{
    FClientes func;
    MClientes model;
    model.setIdcliente(ui->lineCI->text());
    model.setNombre(ui->lineNombre->text());
    model.setApellido(ui->lineApellido->text());
    model.setDireccion(ui->lineDireccion->text());
    model.setTelefono(ui->lineTelefono->text());
    model.setCorreo(ui->lineCorreo->text());
    if(this->botonModificar) //PROCESO GUARDAR NUEVO CLIENTE
    {
        if(verificarErrores())
        {
            func.Insertar(model);
            limpiar();
        }
        else
            QMessageBox::critical(0,"Sistema de Errores:","Debe Completar los campos");
    }
    else //MODIFICAR CLIENTE
    {
        if(verificarErrores())
        {
            func.Modificar(model);
            limpiar();
        }
        else
            QMessageBox::critical(0,"Sistema de Errores:","Debe Completar los campos");
    }
    llenarTabla();

}

void FrmClientes::on_btnEliminar_clicked()
{
    FClientes func;
    MClientes model;
    model.setIdcliente(ui->lineCI->text());

        if(ui->lineCI->text().length() > 0)
        {
            QMessageBox::StandardButton respuesta;
            respuesta  = QMessageBox::question(this, "Clientes","Desea eliminar el cliente?",QMessageBox::Yes|QMessageBox::No);
            if (respuesta == QMessageBox::Yes)
            {
                func.Eliminar(model);
                limpiar();

            }

        }
        else
            QMessageBox::critical(0,"Sistema de Errores:","Debe Existir un ID");


    llenarTabla();
}

void FrmClientes::llenarCbBusqueda(){
    QStringList lista;
    lista << "CI" << "Nombre" << "Correo";
    ui->cbBusqueda->addItems(lista);
}


void FrmClientes::on_btnBuscar_clicked()
{
   /* QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTES where :campo like ':value %'");
    qry.bindValue(":campo", ui->cbBusqueda->currentText());
    qry.bindValue(":value", ui->lineBuscar->text());*/
    if (ui->cbBusqueda->currentIndex() == 0)
        model->setQuery(QString("SELECT * FROM clientes WHERE idcliente like '%1%'").arg(ui->lineBuscar->text()));
    else
        model->setQuery(QString("SELECT * FROM clientes WHERE %1 like '%2%'").arg(ui->cbBusqueda->currentText()).arg(ui->lineBuscar->text()));
    ui->tablaListado->setModel(model);

}
