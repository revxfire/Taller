#include "fclientes.h"
#include <QDebug>
#include <QSqlRecord>
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
FClientes::FClientes()
{
}

bool FClientes::Insertar(MClientes mclientes)
{
    Conectar();
    QSqlQuery qry;
    qry.prepare("INSERT INTO clientes VALUES(:idcliente,:nombre,:apellido,:direccion,:telefono,:correo)");
    qry.bindValue(":idcliente",mclientes.getIdcliente());
    qry.bindValue(":nombre",mclientes.getNombre());
    qry.bindValue(":apellido",mclientes.getApellido());
    qry.bindValue(":direccion",mclientes.getDireccion());
    qry.bindValue(":telefono",mclientes.getTelefono());
    qry.bindValue(":correo",mclientes.getCorreo());
    if(qry.exec()){
       QMessageBox::information(0,"Clientes","Cliente agregado correctamente");
       Desconectar();
       return true;

    }
    else{
        QMessageBox::critical(0, "Clientes", "Se produjo un error, intente nuevamente");
        Desconectar();
        return false;
    }
}

bool FClientes::Modificar(MClientes mclientes){
    Conectar();
    QSqlQuery qry;
    qry.prepare("UPDATE clientes SET nombre = :nombre,apellido = :apellido,direccion = :direccion,telefono = :telefono,correo = :correo WHERE :idcliente = idcliente");
    qry.bindValue(":idcliente",mclientes.getIdcliente());
    qry.bindValue(":nombre",mclientes.getNombre());
    qry.bindValue(":apellido",mclientes.getApellido());
    qry.bindValue(":direccion",mclientes.getDireccion());
    qry.bindValue(":telefono",mclientes.getTelefono());
    qry.bindValue(":correo",mclientes.getCorreo());
    if(qry.exec()){
       QMessageBox::information(0,"Clientes","Cliente Modificado correctamente");
       Desconectar();
       return true;

    }
    else{
        QMessageBox::critical(0, "Clientes", "Se produjo un error, intente nuevamente");
        Desconectar();
        return false;
    }
}

bool FClientes::Eliminar(MClientes mclientes)
{
    Conectar();
    QSqlQuery qry;
    qry.prepare("DELETE FROM clientes WHERE idcliente = :idcliente");
    qry.bindValue(":idcliente",mclientes.getIdcliente());

    if(qry.exec()){
       QMessageBox::information(0,"Clientes","Cliente Eliminado correctamente");
       Desconectar();
       return true;

    }
    else{
        QMessageBox::critical(0, "Clientes", "Se produjo un error, intente nuevamente");
        Desconectar();
        return false;
    }
}


