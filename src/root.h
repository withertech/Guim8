//
// Created by witherking25 on 6/7/21.
//

#ifndef GUIM8_ROOT_H
#define GUIM8_ROOT_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Root; }
QT_END_NAMESPACE

class Root : public QMainWindow {
Q_OBJECT

public:
    explicit Root(QWidget *parent = nullptr);

    ~Root() override;

public slots:
    void bootPushButton_clicked();
    void consoleTermWidget_closed();
private:
    Ui::Root *ui;
};


#endif //GUIM8_ROOT_H
