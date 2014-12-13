#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "Modelos/mconexion.h"
#include "Modelos/mclientes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void llenarTabla();
    QString odbcConnection = "TallerConexion";

private slots:
    void on_actionModulo_triggered();

    void on_actionReparaciones_triggered();

    void on_actionSalir_triggered();

    void on_actionAgenda_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
