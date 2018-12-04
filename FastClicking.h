#pragma once

#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <ctime>
#include "Clock.h"
#include "GameEvent.h"

class FastClicking : public QWidget
{
	Q_OBJECT

public:
	FastClicking(QWidget *parent = Q_NULLPTR);
	~FastClicking();
private:
	//time_t startTime;
	//time_t endTime;
	//GameEndSource *endSource;
	QPushButton *clickButton;
	QLabel *clickedNumberLabel;
	QVBoxLayout *VLayout;
	QMessageBox *startMessageBox;
	//Clock *Timer;
	int clickedNumber = 0;
	int destNumber = 20;
public:
	//void setEndSource(GameEndSource *newSource);
private slots :
	void ButtonClicked();
};
