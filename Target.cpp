#include "Target.h"
#include <QDebug>
#include <QMessageBox>

Target::Target(int i, int j, QWidget* parent, Qt::WindowFlags f)
    : QPushButton(parent), i(i), j(j) {
    this->isTarget = false;
}

Target::~Target() {}

void Target::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}



