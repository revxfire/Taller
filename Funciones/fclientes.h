#ifndef FCLIENTES_H
#define FCLIENTES_H
#include "Modelos/mconexion.h"
#include "Modelos/mclientes.h"
#include <QSqlTableModel>
#include <QTableView>
class FClientes : public MConexion
{
public:
    FClientes();
    QSqlTableModel Mostrar();
    bool Insertar(MClientes mclientes);
    bool Modificar(MClientes mclientes);
    bool Eliminar(MClientes mclientes);
};

#endif // FCLIENTES_H
