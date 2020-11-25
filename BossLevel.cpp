#include "BossLevel.h"
#include "AvatarMap.h"
#include "Player.h"
#include "LoseScreen.h"
#include <QMovie>
#include <QDebug>


extern BossLevel* boss_game;

BossLevel::BossLevel(MainWindow* w) : mw(w),
    scene(new QGraphicsScene)
{
    mw->set_background(":/resources/img/bossBackground.jpg");

    // Scene setup
   // scene = new QGraphicsScene;
    scene->setSceneRect(0,0,1200,800);

    // View setup
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1200,800);
    view->setStyleSheet("background-color: transparent");

    create_player();
    create_boss_health();
    create_boss();
}


void BossLevel::create_player()
{
    player = new Player(scene);
    player->set_bomb_bool_active(1);
    player->set_can_go_invincible(1);
    QPixmap temp(":/resources/img/player.png");
    player->setPixmap(temp.scaled(130,130));
    player -> setPos(200, 500);
    scene->addItem(player);
}


void BossLevel::create_boss_health()
{
    boss_health = new BossHealth(scene);
}


void BossLevel::create_boss()
{
    boss = new Boss(player, boss_health);
    boss->setPos(550,200);
    scene->addItem(boss);
}


QGraphicsView* BossLevel::get_view() const {
    return view;
}


void BossLevel::create_AvatarMap()
{
    AvatarMap* avatar_map = new AvatarMap(mw,3);
    mw->setCentralWidget(avatar_map);
    boss_game = nullptr;
    delete this;
}


void BossLevel::create_WinScreen()
{
    WinScreen* win_page = new WinScreen(mw);
    mw->setCentralWidget(win_page);
    boss_game = nullptr;
    delete this;
}


BossLevel::~BossLevel()
{
    // No need to delete scene as all is deleted individually
    // Deleting scene here will crash
    scene = nullptr;
    delete view;
    view = nullptr;
}


void BossLevel::create_Losescreen()
{
    LoseScreen* lose_page = new LoseScreen(mw);
    mw->setCentralWidget(lose_page);
    delete this;
    boss_game = nullptr;
}

Player* BossLevel::get_player() const
{
    return player;
}
