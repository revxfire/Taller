#include "frmagenda.h"
#include "ui_frmagenda.h"

FrmAgenda::FrmAgenda(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmAgenda)
{
    ui->setupUi(this);
}

FrmAgenda::~FrmAgenda()
{
    delete ui;
}
