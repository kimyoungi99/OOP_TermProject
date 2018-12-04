#pragma once

#include <QtWidgets/QMainWindow>
#include "Clock.h"
#include "FastClicking.h"
#include "GameEvent.h"
#include "FastAimming.h"
#include "Jump.h"

[event_receiver(native)]
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	void setNextGame(int gamenumber);
private:
	time_t starttime;
	time_t endtime;
	Clock *timer;
	FastClicking *game1;
	FastAimming *game2;
	Jump *game3;
	QVBoxLayout *layout;
	QPushButton *startbutton; 
	//GameEndSource *endSource;
	void End();
	void timerStart();


private slots:
	void startButtonClicked();
};



/*[event_receiver(native)]
class GameEndReceiver {
public :


};*/