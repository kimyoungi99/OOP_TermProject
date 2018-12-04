// BadproG.com
#ifndef MOVING_SHAPE_1_MAINWINDOW_H
#define MOVING_SHAPE_1_MAINWINDOW_H

#include <QWidget>
#include <QPushButton.h>

class BallGame;


class Jump : public QWidget
{
    Q_OBJECT

public:
    explicit Jump(QWidget *parent = 0);
    ~Jump();

private:
    BallGame *_shape;


};

#endif // MOVING_SHAPE_1_MAINWINDOW_H
