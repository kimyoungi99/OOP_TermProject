#include "FastAimming.h"

FastAimming::FastAimming(QWidget *parent): QWidget(parent) {
    this->setFixedSize(QSize(800, 600));
    this->control = new FastAimmingControl(5);
    QGridLayout *layout = new QGridLayout();
    layout->setMargin(0);
    layout->setSpacing(0);
    this->setLayout(layout);
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 20; j++) {
            layout->addWidget(this->control->board[i][j], i, j);
        }
    this->setStyleSheet("QFrame { background-color : white; border: none;}");
}

FastAimming::~FastAimming()
{

}
