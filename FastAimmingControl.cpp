#include "FastAimmingControl.h"

FastAimmingControl::FastAimmingControl(int target_num, QWidget *parent): target_number(target_num), QWidget(parent){
    this->leftTarget = 0;
    this->gameNum = 1;    //°ÔÀÓ È½¼ö 
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 20; j++) {
            this->board[i][j] = new Target(i, j);
            //connect(this->board[i][j], SIGNAL(clicked()), this->board[i][j], SLOT(labelClicked()));
            connect(this->board[i][j], SIGNAL(clicked()), this, SLOT(board_clicked()));
            this->board[i][j]->setStyleSheet("QPushButton { background-color: white; border: none; margin: 0px; padding: 0px;}");
            this->board[i][j]->setFixedSize(QSize(40, 40));
        }
    this->throw_target(target_num);
	this->image.addFile(":/FastAiming/Target");
}

FastAimmingControl::~FastAimmingControl() {

}

void FastAimmingControl::throw_target(int num) {
    srand(time(NULL));
    bool target_array[15][20] = { 0 };
    int target_i = 0;
    int target_j = 0;
    int target_num = 0;
    std::pair<int, int> element;
    this->deque.clear();
    while(target_num < num) {
        target_i = rand() % 15;
        target_j = rand() % 20;
        element.first = target_i;
        element.second = target_j;
        if (target_array[target_i][target_j] == false) {
            target_array[target_i][target_j] = true;
            this->set_target(target_i, target_j);
            deque.push_back(element);
            target_num++;
        }
    }
    this->gameNum--;
    this->leftTarget = target_num;
}

void FastAimmingControl::board_clicked() {
    //QSound::play("/Users/yk0318ha/Desktop/gunShot.wav");
    Target* clickedButton = qobject_cast<Target *>(sender());
    if(clickedButton->isTarget && this->leftTarget > 1) {
        this->remove_target(clickedButton->getI(), clickedButton->getJ());
    }
    else if(clickedButton->isTarget && this->leftTarget == 1 && this->gameNum == 0) {
        this->remove_target(clickedButton->getI(), clickedButton->getJ());
       /* QMessageBox msg;
        msg.setText("Wins!!!!!");
        msg.exec();
		*/
		GameEndSource::endSource->GameEndEvent(1);
    }
    else if(clickedButton->isTarget && this->leftTarget == 1) {
        this->remove_target(clickedButton->getI(), clickedButton->getJ());
        this->throw_target(this->target_number);
    }
    else {
        this->replay();
    }
}

void FastAimmingControl::set_target(int i, int j) {
    this->board[i][j]->isTarget = true;
    this->board[i][j]->setIconSize(QSize(40, 40));
    this->board[i][j]->setIcon(image);
}

void FastAimmingControl::remove_target(int i, int j) {
    this->leftTarget--;
    this->board[i][j]->isTarget = false;
    this->board[i][j]->setIcon(QIcon());
}

void FastAimmingControl::replay() {
    int target_num = 0;
    std::pair<int, int> element;
    while(target_num < this->target_number) {
        element = deque.back();
        deque.pop_back();
        deque.push_front(element);
        set_target(element.first, element.second);
        target_num++;
    }
    this->leftTarget = target_num;
}

/*void Game::setEndSource(GameEndSource *newSource) {
	endSource = newSource;
}*/