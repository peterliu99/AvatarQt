#include "WinScreen.h"
#include "EndCredits.h"


WinScreen::WinScreen(MainWindow *mw):w(mw),
    continue_button(new QPushButton("Continue"))
{
    w->set_background(":/resources/img/avatar_win.png");

    continue_button->setParent(this);

    continue_button->setGeometry(600,600,100,50);
    continue_button->setStyleSheet("background: rgb(255,195,185); font: bold 15px; width: 200px; height: 30px;");

    QObject::connect(continue_button,SIGNAL(clicked()),this,SLOT(create_EndCredit()));

}

void WinScreen::create_EndCredit()
{
    EndCredits* credit_page = new EndCredits(w);
    w->setCentralWidget(credit_page);
    delete this;

}
