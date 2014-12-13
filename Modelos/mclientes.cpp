#include "mclientes.h"

MClientes::MClientes()
{

}

MClientes::MClientes(QString IdCliente,QString Nombre,QString Apellido, QString Direccion, QString Telefono, QString Correo){
    this->idcliente = IdCliente;
    this->nombre = Nombre;
    this->apellido = Apellido;
    this->direccion = Direccion;
    this->telefono = Telefono;
    this->correo = Correo;
}

QString MClientes::getIdcliente() const
{
    return idcliente;
}

void MClientes::setIdcliente(const QString &value)
{
    idcliente = value;
}
QString MClientes::getNombre() const
{
    return nombre;
}

void MClientes::setNombre(const QString &value)
{
    nombre = value;
}
QString MClientes::getApellido() const
{
    return apellido;
}

void MClientes::setApellido(const QString &value)
{
    apellido = value;
}
QString MClientes::getDireccion() const
{
    return direccion;
}

void MClientes::setDireccion(const QString &value)
{
    direccion = value;
}
QString MClientes::getTelefono() const
{
    return telefono;
}

void MClientes::setTelefono(const QString &value)
{
    telefono = value;
}
QString MClientes::getCorreo() const
{
    return correo;
}

void MClientes::setCorreo(const QString &value)
{
    correo = value;
}










