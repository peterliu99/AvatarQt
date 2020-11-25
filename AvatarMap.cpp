#include "AvatarMap.h"
#include "MainWindow.h"
#include "Game.h"
#include "WaterGame.h"
#include "EarthGame.h"
#include "BossLevel.h"

#include <QPixmap>
#include <QIcon>
#include <QStyleOption>
#include <QPainter>

extern WaterGame* water_game;
extern EarthGame* earth_game;
extern BossLevel* boss_game;

AvatarMap::AvatarMap(MainWindow* mainwindow, int i):
    mw(mainwindow),
    water_button_north(new QPushButton),
    water_button_south(new QPushButton),
    earth_button(new QPushButton),
    fire_button(new QPushButton),
    end_button(nullptr)

{
    complete_level = i;

    earth_button->setParent(this);
    fire_button->setParent(this);
    water_button_north->setParent(this);
    water_button_south->setParent(this);



    //sets position of the button on the screen
    water_button_north->setGeometry(483,48,250,110);
    water_button_south->setGeometry(437,612,300,170);
    fire_button->setGeometry(100,275,405,200);
    earth_button->setGeometry(380,100,720,550);

    //sets nackground color and hover effect to buttons
    water_button_north->setStyleSheet( "QPushButton{background-color: transparent}"
                                       "QPushButton:hover{background-color: rgba(100, 100, 255, 30)}");
    water_button_south->setStyleSheet( "QPushButton{background-color: transparent}"
                                       "QPushButton:hover{background-color: rgba(100, 100, 255, 30)}");
    fire_button->setStyleSheet( "QPushButton{background-color: transparent}"
                                "QPushButton:hover{background-color: rgba(255, 0, 0, 20)}");
    earth_button->setStyleSheet( "QPushButton{background-color: transparent}"
                                 "QPushButton:hover{background-color: rgba(0, 255, 0, 20)}");

    //sets buttons for each nation
    QPixmap water_north_temp(":/resources/img/water_nation_north.png"); //create pixmap of button
    QPixmap water_north_pixmap = water_north_temp.scaled(325,140);
    QIcon water_north_icon(water_north_pixmap); // create icon from pixmap

    QPixmap water_south_temp(":/resources/img/water_nation_south.png");
    QPixmap water_south_pixmap = water_south_temp.scaled(380,155);
    QIcon eater_south_icon(water_south_pixmap);

    QPixmap earth_temp(":/resources/img/earth_nation.png");
    QPixmap earth_pixmap = earth_temp.scaled(800,560);
    QIcon earth_icon(earth_pixmap);

    QPixmap fire_temp(":/resources/img/fire_nation.png");
    QPixmap fire_pixmap = fire_temp.scaled(435,230);
    QIcon fire_icon(fire_pixmap);

    if(complete_level<1) //if the water level is complete set the water level beaten badge
    {
        earth_button->setIcon(earth_pixmap);
        earth_button->setIconSize(earth_button->size());
    }

    if(complete_level<2)//if the earth level is complete set the earth level beaten badge
    {
        fire_button->setIcon(fire_pixmap);
        fire_button->setIconSize(earth_button->size());
    }

    water_complete = new QPushButton;


    if (complete_level>=1){//if the water level is complete set the water level beaten badge
         water_complete->setParent(this);
         water_complete->setGeometry(530,85,50,50);
         //set pixmap for badge
         QPixmap waterIcon_temp(":/resources/img/water.png");
         QPixmap waterIcon_pixmap = waterIcon_temp.scaled(50,50);
         QIcon waterIcon(waterIcon_pixmap);
         //set pixmap as the icon
         water_complete->setIcon(waterIcon_pixmap);
         water_complete->setIconSize(water_complete->size());

         water_complete->setStyleSheet("QPushButton{background-color: transparent}");
    }

    earth_complete = new QPushButton;


    if (complete_level>=2){ //if more than two levels are complete set earth game complete badge

         earth_complete->setParent(this);
         earth_complete->setGeometry(720,350,60,60);
         //set pixmap for earth badge
         QPixmap earthIcon_temp(":/resources/img/earth.png");
         QPixmap earthIcon_pixmap = earthIcon_temp.scaled(60,60);
         QIcon earthIcon(earthIcon_pixmap);
         //set earth complete icon
         earth_complete->setIcon(earthIcon_pixmap);
         earth_complete->setIconSize(earth_complete->size());

         earth_complete->setStyleSheet("QPushButton{background-color: transparent}");

    }

    fire_complete = new QPushButton;

    if (complete_level>=3){ // if three or more levels are complete, we would have completed the game
         fire_complete->setParent(this);
         fire_complete->setGeometry(300,350,50,50);
         //set fire nation pixmap
         QPixmap fireIcon_temp("qrc:/resources/img/fire.png");
         QPixmap fireIcon_pixmap = fireIcon_temp.scaled(50,50);
         QIcon fireIcon(fireIcon_pixmap);
         //set icon for fire nation
         fire_complete->setIcon(fireIcon_pixmap);
         fire_complete->setIconSize(fire_complete->size());

         fire_complete->setStyleSheet("QPushButton{background-color: transparent}");
    }

    //set pixmaps for each nation
    water_button_north->setIcon(water_north_pixmap);
    water_button_north->setIconSize(water_button_north->size());

    water_button_south->setIcon(water_south_pixmap);
    water_button_south->setIconSize(water_button_south->size());

    //connect button clicked() to the correct slot for each nation
    connect(water_button_north,SIGNAL(clicked()),this,SLOT(create_WaterGame()));
    connect(water_button_south,SIGNAL(clicked()),this,SLOT(create_WaterGame()));
    connect(earth_button,SIGNAL(clicked()),this,SLOT(create_EarthGame()));
    connect(fire_button,SIGNAL(clicked()),this,SLOT(create_BossGame()));

}


void AvatarMap::paintEvent(QPaintEvent *event)
{
    QPixmap bg(":/resources/img/avatar_map.jpg"); // set background (fit for resizing)
    bg = bg.scaled(mw->size(), Qt::IgnoreAspectRatio);
    QPalette bg_palette;
    bg_palette.setBrush(QPalette::Background, bg);
    mw->setPalette(bg_palette);
}


void AvatarMap::create_WaterGame()
{
    mw->hide(); // hide then show fixes problem of focus
    water_game = new WaterGame(mw,":/resources/img/blue_cave.jpg"); // create water game
    QGraphicsView* view = water_game->get_view(); // get view from game
    mw->setCentralWidget(view); // give view to main window
    mw->show();
    delete this;
}


void AvatarMap::create_EarthGame()
{
    mw->hide(); // hide then show fixes problem of focus
    earth_game = new EarthGame(mw,":/resources/img/forest.jpg"); // create water game
    QGraphicsView* view = earth_game->get_view(); // get view from game
    mw->setCentralWidget(view); // give view to main window
    mw->show();
    delete this;
}


void AvatarMap::create_BossGame()
{
    mw->hide();
    boss_game = new BossLevel(mw);//create boss level
    QGraphicsView* view = boss_game->get_view();
    mw->setCentralWidget(view);
    mw->show();
    delete this;//delete avatar map after the boss level has been created
}
// No destructor needed here. No memory leaks
