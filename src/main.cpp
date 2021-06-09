#include <QApplication>
#include <QPushButton>
#include "root.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Root root(nullptr);
    root.show();
    return QApplication::exec();
}
