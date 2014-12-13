#include "mconexion.h"
#include <qstring.h>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>
#include <QStringList>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlQuery>

MConexion::MConexion()
{

}

bool MConexion::Conectar()
 {
    if(!QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase:: addDatabase ("QODBC");
        db.setDatabaseName("TallerConexion");
        db.setUserName("sa");
        db.setPassword("123456");
        if (!db.open()) {
            qDebug() << db.lastError().text();
        return false;
        }
        else {
            qDebug() << "Conexion SQL Exitosa!";

            return true;
        }
    }
    return false;
 }


bool MConexion::Desconectar()
{

    if(this->db.open())
    {
        this->db.close();
        qDebug() << "Desconectado";
        return true;
    }
    else
        return false;
}

void MConexion::verificarDrivers(){
    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
    qDebug() << "\t" << driver;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    qDebug() << "ODBC driver valid?" << db.isValid();
}
