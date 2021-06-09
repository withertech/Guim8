//
// Created by witherking25 on 6/7/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Root.h" resolved

#include <sstream>
#include <qtermwidget.h>
#include "root.h"
#include "ui_root.h"


Root::Root(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Root) {
    ui->setupUi(this);
    ui->statusbar->clearMessage();
    ui->statusbar->showMessage("Idle");
    connect(ui->bootPushButton, SIGNAL(clicked()), this, SLOT(bootPushButton_clicked()));
}

Root::~Root() {
    delete ui;
}

void Root::bootPushButton_clicked()
{
    ui->statusbar->clearMessage();
    ui->statusbar->showMessage("Booting");
    QTermWidget *console = new QTermWidget(0);
    connect(console, SIGNAL(finished()), console, SLOT(close()));
    connect(console, SIGNAL(destroyed()), this, SLOT(consoleTermWidget_closed()));
    console->setShellProgram("/bin/bash");
    console->startShellProgram();
    console->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose, true);\
    console->show();
}

void Root::consoleTermWidget_closed()
{
    ui->statusbar->clearMessage();
    ui->statusbar->showMessage("Idle");
}

