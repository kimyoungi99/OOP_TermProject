#ifndef GAME_H
#define GAME_H
#include "Target.h"
#include "GameEvent.h"
#include <cstdlib>
#include <deque>
#include <ctime>
#include <QWidget>
#include <QMessageBox>
#include <QtDebug>
#include <QIcon>


class FastAimmingControl: public QWidget
{
    Q_OBJECT
public:
    FastAimmingControl(int target_num, QWidget *parnet = 0);
	~FastAimmingControl();
    void throw_target(int num);
    Target *board[15][20];
    void set_target(int i, int j);
    void remove_target(int i, int j);
    void replay();
	//void setEndSource(GameEndSource *newSource);
    std::deque<std::pair<int, int>> deque;
	QIcon image;
private:
    int leftTarget;
    int gameNum;
    int target_number;
	//GameEndSource *endSource;
public slots:
    void board_clicked();
};

#endif // GAME_H
