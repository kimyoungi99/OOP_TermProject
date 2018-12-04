// BadproG.com
#ifndef MOVING_SHAPE_1_BallGame_H_
#define MOVING_SHAPE_1_BallGame_H_

#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include <QPalette.h>
#include "GameEvent.h"

class BallGame : public QWidget
{
    Q_OBJECT
public:
    explicit BallGame(QWidget *parent = 0);
    // Get & Set
    int getPointX() const;
    int getPointY() const;
    void setPointX(int pointX);
    void setPointY(int pointY);
    int getStep() const;
    void setStep(int step);
    int getEllipseWidth() const;
    int getEllipseHeight() const;
    void setEllipseWidth(int ellipseWidth);
    void setEllipseHeight(int ellipseHeight);
    void setEllipsePen(int ellipsePen);
    int getEllipsePen() const;
    void moveObject();
    bool isGround(int x, int y);
    void gameEnd();
    QTimer *timer;

protected:
    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);
    void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);

private:
    int _pointX;
    int _pointY;
    int _step;
    int _ellipseWidth;
    int _ellipseHeight;
    int _ellipsePen;
    int dir;
    int isSpace;
	bool isStarted;

signals:
	void clicked();

public slots:
	void startGame();

};

#endif // MOVING_SHAPE_1_BallGame_H
