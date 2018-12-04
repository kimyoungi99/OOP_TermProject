#include "FastClicking.h"

FastClicking::FastClicking(QWidget *parent)
	: QWidget(parent)
{
	this->setWindowTitle(QString("Fast Clicking"));
	//set clickButton
	clickButton = new QPushButton();
	clickButton->setFixedSize(800, 500);
	clickButton->setText("Click!");
	clickButton->setStyleSheet("font:48pt; border:none; background:yellow");
	//set clickedNumberLabel
	clickedNumberLabel = new QLabel();
	clickedNumberLabel->setFixedSize(800, 100);
	clickedNumberLabel->setText(QString::number(clickedNumber) + QString('/') + QString::number(destNumber));
	clickedNumberLabel->setAlignment(Qt::AlignCenter);
	clickedNumberLabel->setStyleSheet("font:32pt;");
	//add Clock
	//Timer = new Clock();
	//set VLayout
	VLayout = new QVBoxLayout();
	//VLayout->addWidget(Timer);
	VLayout->addWidget(clickButton);
	VLayout->addWidget(clickedNumberLabel);
	connect(clickButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
	this->setLayout(VLayout);
	//this->show();
	//set startMessageBox
	//	startMessageBox = new QMessageBox();
	//	startMessageBox->setStyleSheet("QLabel{min-width:400; min-height:300 px; font-size: 24px;} QPushButton{ min-width:400px; min-height:100px; font-size: 18px; }");
	//	startMessageBox->setText("<p align='center'>Click to Start");
	//	startMessageBox->exec();

	//	startTime = clock();
	//Timer->setStartTime(startTime);
	//Timer->start();
}

void FastClicking::ButtonClicked() {
	//	endTime = clock();
	clickedNumber++;
	clickedNumberLabel->setText(QString::number(clickedNumber) + QString('/') + QString::number(destNumber));

	if (clickedNumber == destNumber) {
		//Timer->setEndTime(endTime);
		//Timer->stop();
		QString temp;
		//		temp.sprintf("%.3f", (float)(endTime - startTime) / CLOCKS_PER_SEC);
		disconnect(clickButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
		clickButton->setText(QString("Finished\nResult : ") + temp + QString(" sec"));
		__raise GameEndSource::endSource->GameEndEvent(0);
	}
}

FastClicking::~FastClicking() {
	delete clickButton;
	delete clickedNumberLabel;
	delete VLayout;
}

/*void FastClicking::setEndSource(GameEndSource *newSource) {
	endSource = newSource;
}*/