#include "Clock.h"
Clock::Clock(QWidget *parent) : QLCDNumber(parent) {
	setSegmentStyle(Filled);

	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &Clock::showTime);
	this->setDigitCount(6);
	setFixedSize(800, 200);
}

void Clock::showTime() {
	TshowTime();
}

void Clock::setStartTime(time_t newST) {
	starttime = newST;
}

void Clock::setEndTime(time_t newET) {
	endtime = newET;
}

void Clock::start() {
	timer->start(10);
	showTime();
}

void Clock::stop() {
	timer->stop();
	QString text;
	text.sprintf("%6.3f", (float)(endtime - starttime) / CLOCKS_PER_SEC);
	display(text);
}

void Clock::TshowTime() {
	QString text;
	text.sprintf("%6.3f", (float)(clock() - starttime) / CLOCKS_PER_SEC);
	display(text);
}