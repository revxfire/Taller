#ifndef MCLIENTES_H
#define MCLIENTES_H
#include <QString>

class MClientes {
public:
    MClientes();
    MClientes(QString IdCliente,QString Nombre,QString Apellido, QString Direccion, QString Telefono, QString Correo);
    QString getIdcliente() const;
    void setIdcliente(const QString &value);

    QString getNombre() const;
    void setNombre(const QString &value);

    QString getApellido() const;
    void setApellido(const QString &value);

    QString getDireccion() const;
    void setDireccion(const QString &value);

    QString getTelefono() const;
    void setTelefono(const QString &value);

    QString getCorreo() const;
    void setCorreo(const QString &value);

private:
    QString idcliente,nombre,apellido,direccion,telefono,correo;

};

#endif // MCLIENTES_H
