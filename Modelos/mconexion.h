#ifndef CLSCONEXION_H
#define CLSCONEXION_H
#include <QString>
#include <QSqlDatabase>

class MConexion
{
public:
    MConexion();
    bool Conectar();
    void verificarDrivers();
    bool Desconectar();
    QSqlDatabase db;

};

#endif // CLSCONEXION_H
