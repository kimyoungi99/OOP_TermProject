// BadproG.com
#include "ui_mainwindow.h"
#include "Jump.h"
#include "ballgame.h"
#include "QLayout"

Jump::Jump(QWidget *parent) :QWidget(parent)
{
	QLayout *layout = new QGridLayout();
	_shape = new BallGame(this);
	layout->setSpacing (0);
    layout->setContentsMargins (0, 0, 0, 0);
	this->setFixedSize(800, 600);
	this->setLayout(layout);
	layout->addWidget(_shape);
}

Jump::~Jump() {
    delete _shape;
    delete this;
}
