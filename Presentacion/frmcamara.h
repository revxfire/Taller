#ifndef FRMCAMARA_H
#define FRMCAMARA_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>

namespace Ui {
class FrmCamara;
}

class FrmCamara : public QWidget
{
    Q_OBJECT

public:
    explicit FrmCamara(QWidget *parent = 0);
    ~FrmCamara();


private slots:
    void on_cbListaCamaras_currentIndexChanged(int index);

    void on_btnCancelar_clicked();

    void on_btnTomarFoto_clicked();

    void setQImage();

private:
    Ui::FrmCamara *ui;
    bool detectarCamaras();
    bool activarCamara();
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCaptura;
};

#endif // FRMCAMARA_H
