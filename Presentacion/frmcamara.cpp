#include "frmcamara.h"
#include "ui_frmcamara.h"
#include <QCameraViewfinder>
#include <QCamera>
#include <QCameraInfo>
#include <QDebug>
#include <QString>
#include <QCameraImageCapture>
#include <QImage>

FrmCamara::FrmCamara(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmCamara)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    activarCamara();

}

FrmCamara::~FrmCamara()
{
    delete ui;
}


bool FrmCamara::detectarCamaras()
{
    if (QCameraInfo::availableCameras().count() > 0)
    {
        QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
        foreach (const QCameraInfo &cameraInfo, cameras) {
            ui->cbListaCamaras->addItem(cameraInfo.description());
        }
            return true;
    }
        else
            return false;
}

bool FrmCamara::activarCamara()
{
    if(detectarCamaras())
    {
        QCamera *camera = new QCamera(this);
        QCameraViewfinder *viewfinder = new QCameraViewfinder(this);
        viewfinder->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
        camera->setViewfinder(viewfinder);
        ui->layout->addWidget(viewfinder);
        //viewfinder->show();


        QCameraImageCapture *imageCaptura = new QCameraImageCapture(camera);
        camera->setCaptureMode(QCamera::CaptureStillImage);
        QObject::connect(imageCaptura,SIGNAL(imageCaptured(int,QImage)),this,SLOT(setQImage()));
        camera->start(); // to start the viewfinder
        camera->searchAndLock();
        imageCaptura->capture();
        camera->unlock();
    }
    else
        qDebug() << "No se consigue ninguna camara en el sistema";

}


void FrmCamara::on_cbListaCamaras_currentIndexChanged(int index)
{

}

void FrmCamara::on_btnCancelar_clicked()
{
    this->close();
}

void FrmCamara::on_btnTomarFoto_clicked()
{
    QImage *image = new QImage();


}

void FrmCamara::setQImage(){

}
