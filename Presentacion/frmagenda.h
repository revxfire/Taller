#ifndef FRMAGENDA_H
#define FRMAGENDA_H

#include <QWidget>

namespace Ui {
class FrmAgenda;
}

class FrmAgenda : public QWidget
{
    Q_OBJECT

public:
    explicit FrmAgenda(QWidget *parent = 0);
    ~FrmAgenda();

private:
    Ui::FrmAgenda *ui;
};

#endif // FRMAGENDA_H
