#include "MainWindow.h"
#include <thread>
GameEndSource* GameEndSource::endSource = NULL;
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{

	timer = new Clock();
	game1 = new FastClicking();
	game2 = new FastAimming();
	game3 = new Jump();
	layout = new QVBoxLayout();

	GameEndSource::endSource = new GameEndSource();
	__hook(&GameEndSource::GameEndEvent, GameEndSource::endSource, &MainWindow::setNextGame);
	//game1->setEndSource(GameEndSource::endSource);
	//game2->game->setEndSource(GameEndSource::endSource);
	layout->addWidget(timer);
	layout->addWidget(game1);

	QWidget *temp = new QWidget();
	temp->setLayout(layout);
	this->setCentralWidget(temp);

	this->show();

	startbutton = new QPushButton();
	startbutton->setText("START");
	startbutton->setFixedSize(QSize(150, 150));
	startbutton->show();
	connect(startbutton, SIGNAL(clicked()), this, SLOT(startButtonClicked()));
}

void MainWindow::startButtonClicked() {
	starttime = clock();
	//std::thread t1(&MainWindow::timerStart, 1);
	this->timerStart();
	delete startbutton;
	//t1.join();
}

void MainWindow::setNextGame(int gamenumber) {
	switch (gamenumber) {
	case 0 :
		layout->removeWidget(game1);
		delete game1;
		layout->addWidget(game2);
		break;
	case 1:
		layout->removeWidget(game2);
		delete game2;
		layout->addWidget(game3);
		break;
	case 2:
		this->End();
		break;
	}
}

void MainWindow::End() {
	endtime = clock();
	timer->setEndTime(endtime);
	timer->stop();
}

void MainWindow::timerStart() {
	timer->setStartTime(starttime);
	timer->start();
}
