#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include "Target.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QWidget>
#include <Qt>

class Target : public QPushButton {
    Q_OBJECT

public:
    explicit Target(int i, int j, QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~Target();
    int getI(){
        return i;
    }
    int getJ(){
        return j;
    }
    bool isTarget;

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    int i, j;

};

#endif // CLICKABLELABEL_H
