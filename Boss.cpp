
#include "Boss.h"
#include <QDebug>

Boss::Boss(Player* player, BossHealth* boss_health) :
    health(50),
    health_bar(boss_health),
    sprayAttack_timer(new QTimer()), move_timer(new QTimer),
    opponent(player)
{
    // Setting boss image
    QPixmap temp(":/resources/img/boss.png");
    setPixmap(temp.scaled(325,400));


    // Setting periodic spray attacks from boss
    QObject::connect(sprayAttack_timer,SIGNAL(timeout()),this,SLOT(sprayAttack()));
    sprayAttack_timer -> start(1500);
    move_timer->start(17);

    QPixmap temp2(":/resources/img/fireball.png");
    weapon = new QPixmap(temp2.scaled(50,50));

}


unsigned short int Boss::get_health() const
{
    return health;
}


unsigned short int Boss::decrease_health(unsigned short int amount)
{
    health = health - amount;
    health_bar->update(health);
    qDebug() << "Boss now has " << health << " health";
    return health;
}


void Boss::sprayAttack()
{
    sprayAttack_timer->stop();

    for (size_t i = 0; i < 40; i++) { // creates the 30 fireballs that release in a circle
        BossSprayAttackSingle* bullet = new BossSprayAttackSingle(x()+162,y()+200,opponent,move_timer);
        scene()->addItem(bullet);
        bullet->setPixmap(*weapon);
    }

    // Sets the timer to time out at somewhere between 500 and 1500 ms
    int random_number = (rand() % 1000) + 700;
    sprayAttack_timer->start(random_number);
}
