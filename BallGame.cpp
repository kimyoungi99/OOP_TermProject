// BadproG.com
#include "BallGame.h"
#include <QPainter>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QWidget>

// ============================================================================
// Constructor
// ============================================================================

BallGame::BallGame(QWidget *parent) : QWidget(parent) {
    this->setFixedSize(800, 600);
	setFocusPolicy(Qt::StrongFocus);
	connect(this, SIGNAL(clicked()), this, SLOT(startGame()));
	this->isStarted = false;
}

void BallGame::startGame(){
	setPointX(100);
	setPointY(500);
	setStep(3);
	setEllipseWidth(20);
	setEllipseHeight(20);
	setEllipsePen(1);
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &BallGame::moveObject);
	timer->start(10);
	this->dir = 4;
	this->isSpace = 0;
	this->isStarted = true;
}

// ============================================================================
// Game Objects
// ============================================================================

void BallGame::moveObject() {
    switch(this->dir) {
    case 1:
        setPointX(getPointX() + getStep());
        break;
    case 3:
        setPointX(getPointX() - getStep());
    }

    if(!isGround(getPointX(), getPointY()) && this->isSpace == 0){
        setPointY(getPointY() + getStep() * 2);
    }
    else if(this->isSpace > 0) {    //Jumping
        setPointY(getPointY() - getStep() * 2);
        isSpace--;
    }
    QWidget::update();
}


bool BallGame::isGround(int x, int y) {
    if ((90 <= x && 130 >= x) && (76 <= y && 116 >= y)) {
        this->gameEnd();
    }
    else if((x > 80 && x < 200) && (y <= 432 && y >= 426)) {
        y = 426;
        return true;
    }
    else if((x > 80 && x < 200) && (y <= 450 && y > 432)) {
        this->isSpace = 0;
        return false;
    }
    else if((x > 280 && x < 400) && (y <= 432 && y >= 426)) {
        y = 426;
        return true;
    }
    else if((x >280 && x < 400) && (y <= 450 && y > 432)) {
        this->isSpace = 0;
        return false;
    }
    else if((x > 80 && x < 200) && (y <= 322 && y >= 316)) {
        y = 316;
        return true;
    }
    else if((x > 80 && x < 200) && (y <= 340 && y > 322)) {
        this->isSpace = 0;
        return false;
    }
    else if((x >280 && x < 400) && (y <= 322 && y >= 316)) {
        y = 316;
        return true;
    }
    else if((x > 280 && x < 400) && (y <= 340 && y > 322)) {
        this->isSpace = 0;
        return false;
    }
    else if((x > 480 && x < 600) && (y <= 322 && y >= 316)) {
        y = 322;
        return true;
    }
    else if((x > 480 && x < 600) && (y <= 340 && y > 322)) {
        this->isSpace = 0;
        return false;
    }
    else if((x > 480 && x < 600) && (y <= 212 && y >= 206)) {
        y = 206;
        return true;
    }
    else if((x > 480 && x < 600) && (y <= 230 && y > 212)) {
        this->isSpace = 0;
        return false;
    }
    else if((x > 480 && x < 600) && (y <= 102 && y >= 96)) {
        y = 96;
        return true;
    }
    else if((x > 480 && x < 600) && (y <= 120 && y > 102)) {
        this->isSpace = 0;
        return false;
    }
    else if((x > 280 && x < 400) && (y <= 102 && y >= 96)) {
        y = 96;
        return true;
    }
    else if((x > 280 && x < 400) && (y <= 120 && y > 102)) {
        this->isSpace = 0;
        return false;
    }
    else if((x > 80 && x < 200) && (y <= 102 && y >= 96)) {
        y = 96;
        return true;
    }
    else if((x > 80 && x < 200) && (y <= 120 && y > 102)) {
        this->isSpace = 0;
        return false;
    }
    else if (y >= 535) {
        y = 535;
        return true;
    }
    return false;
}

void BallGame::gameEnd() {
    disconnect(timer, &QTimer::timeout, this, &BallGame::moveObject);
	GameEndSource::endSource->GameEndEvent(2);
}
// ============================================================================
// Paint
// ============================================================================

void BallGame::paintEvent(QPaintEvent *event) {
	if (this->isStarted) {
		Q_UNUSED(event);
		QPainter painter;
		QRectF rectangle(getPointX(), getPointY(), getEllipseWidth(), getEllipseHeight());
		QRectF target(110, 96, 20, 20);
		QPen pen_ellipse(Qt::black);

		pen_ellipse.setWidth(getEllipsePen());
		painter.begin(this);
		painter.setPen(pen_ellipse);
		painter.setBrush(Qt::cyan);
		this->setAutoFillBackground(false);

		painter.drawLine(300, 120, 400, 120);
		painter.drawLine(300, 119, 400, 119);
		painter.drawLine(300, 118, 400, 118);
		painter.drawLine(300, 117, 400, 117);

		painter.drawLine(100, 120, 200, 120);
		painter.drawLine(100, 119, 200, 119);
		painter.drawLine(100, 118, 200, 118);
		painter.drawLine(100, 117, 200, 117);

		painter.drawLine(500, 120, 600, 120);
		painter.drawLine(500, 119, 600, 119);
		painter.drawLine(500, 118, 600, 118);
		painter.drawLine(500, 117, 600, 117);

		painter.drawLine(500, 230, 600, 230);
		painter.drawLine(500, 229, 600, 229);
		painter.drawLine(500, 228, 600, 228);
		painter.drawLine(500, 227, 600, 227);

		painter.drawLine(100, 340, 200, 340);
		painter.drawLine(100, 339, 200, 339);
		painter.drawLine(100, 338, 200, 338);
		painter.drawLine(100, 337, 200, 337);

		painter.drawLine(300, 340, 400, 340);
		painter.drawLine(300, 339, 400, 339);
		painter.drawLine(300, 338, 400, 338);
		painter.drawLine(300, 337, 400, 337);

		painter.drawLine(500, 340, 600, 340);
		painter.drawLine(500, 339, 600, 339);
		painter.drawLine(500, 338, 600, 338);
		painter.drawLine(500, 337, 600, 337);

		painter.drawLine(100, 450, 200, 450);
		painter.drawLine(100, 449, 200, 449);
		painter.drawLine(100, 448, 200, 448);
		painter.drawLine(100, 447, 200, 447);

		painter.drawLine(300, 450, 400, 450);
		painter.drawLine(300, 449, 400, 449);
		painter.drawLine(300, 448, 400, 448);
		painter.drawLine(300, 447, 400, 447);

		painter.drawLine(0, 559, 800, 559);
		painter.drawLine(0, 558, 800, 558);
		painter.drawLine(0, 557, 800, 557);
		painter.drawLine(0, 556, 800, 556);

		painter.drawRect(target);
		painter.drawEllipse(rectangle);
		painter.end();
	}
	else {
		QPalette pal = palette();
		pal.setColor(QPalette::Background, Qt::green);
		this->setAutoFillBackground(true);
		this->setPalette(pal);

	}
}
// ============================================================================
// Key
// ============================================================================

void BallGame::keyPressEvent(QKeyEvent *keyEvent) {
    switch (keyEvent->key()) {
    case Qt::Key_Down:
        this->dir = 2;
        break;
    case Qt::Key_S:
        this->dir = 2;
        break;
    case Qt::Key_Left:
        this->dir = 3;
        break;
    case Qt::Key_A:
        this->dir = 3;
        break;
    case Qt::Key_Right:
        this->dir = 1;
        break;
    case Qt::Key_D:
        this->dir = 1;
        break;
    case Qt::Key_Up:
        this->dir = 0;
        break;
    case Qt::Key_W:
        this->dir = 0;
        break;
    case Qt::Key_Space:
        if(isGround(getPointX(), getPointY()))
            this->isSpace = 22;
        break;
    default:
        break;
    }
}

void BallGame::keyReleaseEvent(QKeyEvent *keyEvent) {
    switch (keyEvent->key()) {
    case Qt::Key_Down:
        if(this->dir == 2)
            this->dir = 4;
        break;
    case Qt::Key_S:
        if(this->dir == 2)
            this->dir = 4;
        break;
    case Qt::Key_Left:
        if(this->dir == 3)
            this->dir = 4;
        break;
    case Qt::Key_A:
        if(this->dir == 3)
            this->dir = 4;
        break;
    case Qt::Key_Right:
        if(this->dir == 1)
            this->dir = 4;
        break;
    case Qt::Key_D:
        if(this->dir == 1)
            this->dir = 4;
        break;
    case Qt::Key_Up:
        if(this->dir == 4)
            this->dir = 4;
        break;
    case Qt::Key_W:
        if(this->dir == 4)
            this->dir = 4;
        break;
    default:
        break;
    }
}

void BallGame::mousePressEvent(QMouseEvent *event) {
	emit clicked();
}

// ============================================================================
// Get & Set
// ============================================================================

int BallGame::getPointX() const
{
    return _pointX;
}

int BallGame::getPointY() const
{
    return _pointY;
}

void BallGame::setPointX(int pointX)
{
    _pointX = pointX;
}

void BallGame::setPointY(int pointY)
{
    _pointY = pointY;
}

int BallGame::getStep() const
{
    return _step;
}

void BallGame::setStep(int step)
{
    _step = step;
}

void BallGame::setEllipseHeight(int ellipseHeight)
{
    _ellipseHeight = ellipseHeight;
}


void BallGame::setEllipseWidth(int ellipseWidth)
{
    _ellipseWidth = ellipseWidth;
}

int BallGame::getEllipseHeight() const
{
    return _ellipseHeight;
}

int BallGame::getEllipseWidth() const
{
    return _ellipseWidth;
}

int BallGame::getEllipsePen() const
{
    return _ellipsePen;
}

void BallGame::setEllipsePen(int ellipsePen)
{
    _ellipsePen = ellipsePen;
}
