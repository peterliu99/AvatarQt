#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "MainWindow.h"
#include <QGraphicsEffect>
#include <QPropertyAnimation>

class Instructions : public QWidget
{
    Q_OBJECT

private:
    MainWindow* mw;
    QPushButton* skipButton;
    QTextEdit* paragraph;
    QPropertyAnimation *a;
    QGraphicsOpacityEffect *eff;

public:
    /**
        constructs the instructions screen and initializes all
        private variables
    */
    Instructions();

    /**
        constructs the intrsuctions screen
        @param MainWindow* the window used to put the screen on
    */
    Instructions(MainWindow* w);

    /**
        destructs the instructions screen
    */
    ~Instructions();

public slots:
    /**
        creates the avatat map once the button has been clicked
    */
    void createMap();
};

#endif // INSTRUCTIONS_H
