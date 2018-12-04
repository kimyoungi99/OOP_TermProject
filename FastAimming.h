#ifndef MSFRAME_H
#define MSFRAME_H

#include "FastAimmingControl.h"
#include "Target.h"
#include <QtDebug>
#include <QPushButton>
#include <iostream>
#include <QGridLayout>
#include <QPixmap>
#include <QImage>
#include <QWidget>


class FastAimming : public QWidget
{
    Q_OBJECT

public:
    FastAimming(QWidget *parnet = 0);
    ~FastAimming();
	FastAimmingControl *control;
private:

};


#endif // MSFRAME_H
