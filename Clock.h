#pragma once
#include <QtWidgets>
#include <QLCDNumber>
#include <ctime>
#include <QThread>

class Clock : public QLCDNumber {
	Q_OBJECT
private:
	time_t starttime;
	time_t endtime;
	QTimer *timer;
public:
	Clock(QWidget *parent = 0);
	void setStartTime(time_t newST);
	void setEndTime(time_t newET);
	void start();
	void stop();
	void TshowTime();
	private slots :
	void showTime();
};