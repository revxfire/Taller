#ifndef FRMCLIENTES_H
#define FRMCLIENTES_H

#include <QWidget>
#include <QSqlQueryModel>
#include "Modelos/mconexion.h"
#include <QSortFilterProxyModel>
namespace Ui {
class FrmClientes;
}

class FrmClientes : public QWidget
{
    Q_OBJECT

public:
    explicit FrmClientes(QWidget *parent = 0);
    ~FrmClientes();
    void llenarTabla();
    void limpiar();
    bool verificarErrores();
    void llenarCbBusqueda();
    MConexion mconexion;


private slots:
    void on_btnNuevo_clicked();

    void on_tablaListado_clicked(const QModelIndex &index);

    void on_btnGuardar_clicked();

    void on_btnEliminar_clicked();

    void on_btnBuscar_clicked();



private:
    Ui::FrmClientes *ui;
    bool botonModificar = false; //SE USA PARA SUAR BOTON MODIFICAR O GUARDAR
    QSqlQueryModel *model = new QSqlQueryModel(this);

};

#endif // FRMCLIENTES_H
