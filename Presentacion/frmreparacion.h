#ifndef FRMREPARACION_H
#define FRMREPARACION_H

#include <QWidget>

namespace Ui {
class FrmReparacion;
}

class FrmReparacion : public QWidget
{
    Q_OBJECT

public:
    explicit FrmReparacion(QWidget *parent = 0);
    ~FrmReparacion();

private slots:

    void on_btnNuevo_clicked();
private:
    Ui::FrmReparacion *ui;
};

#endif // FRMREPARACION_H
