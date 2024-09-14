#pragma once

#include <QMainWindow>
//#include "TcpCommunication.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class QTWidgetAndLib;
}
QT_END_NAMESPACE

class QTWidgetAndLib : public QMainWindow
{
    Q_OBJECT

public:
    QTWidgetAndLib(QWidget *parent = nullptr);
    ~QTWidgetAndLib();

private:
    Ui::QTWidgetAndLib *ui;
};
