#include "Storyline.h"
#include "Instructions.h"
#include <QTimer>


Storyline::Storyline():
    mw(nullptr),
    instructions_button(nullptr),
    storyline_layout(nullptr),
    line1(nullptr),
    line2(nullptr),
    line3(nullptr),
    line4(nullptr),
    story_music(nullptr),
    music_button(nullptr)
{}


Storyline::Storyline(MainWindow* w) :
    mw(w),
    instructions_button(new QPushButton("Go to Instructions")),
    storyline_layout(new QGridLayout),
    story_music(new QMediaPlayer(this)),
    music_button(new MusicToggleButton(story_music)),
    line1( new QLabel("Avatar: The Last Airbender is set in a world where human civilization consists of four nations, ")),
    line2(new QLabel("named after the four classical elements: ")),
    line3(new QLabel("the Water Tribes, the Earth Kingdom, the Fire Nation, and the Air Nomads")),
    line4(new QLabel("As a master of elements, you must defeat the Fire Nation and save humanity"))
{
    // Creation of line labels
    mw->set_background(":/resources/img/menu.jpg");

    // Setting font of line labels
    QFont myfont("myfont", 12, QFont::Bold);
    line1->setFont(myfont);
    line2->setFont(myfont);
    line3->setFont(myfont);
    line4->setFont(myfont);

    // Music button related
    music_button->setParent(this);

    // Intro music
    story_music->setMedia(QUrl("qrc:resources/sound/intro.mp3"));
    story_music->play();

    // Starting sequence of line labels by first displaying line1
    storyline_layout -> addWidget(line1, 1, 1, Qt::AlignCenter);
    setLayout(storyline_layout);
    QTimer::singleShot(1000, this, SLOT(updatecaption1()));
}

Storyline::~Storyline()
{
    // instructions_button handled via parent
    delete storyline_layout;
    storyline_layout = nullptr;
    //Lines deleted in updating of captions
    delete story_music;
    story_music = nullptr;
    // music_button handled by parent
}


void Storyline::updatecaption1() {
    delete line1;
    line1=nullptr;
    storyline_layout->addWidget(line2, 1, 1,Qt::AlignCenter);
    QTimer::singleShot(1000, this, SLOT(updatecaption2()));
}


void Storyline::updatecaption2() {
    delete line2;
    line2=nullptr;
    storyline_layout->addWidget(line3, 1, 1, Qt::AlignCenter);
    QTimer::singleShot(1000, this, SLOT(updatecaption3()));
}


void Storyline::updatecaption3() {
    delete line3;
    line3=nullptr;
    storyline_layout->addWidget(line4, 1, 1, Qt::AlignCenter);
    QTimer::singleShot(1000, this, SLOT(show_begin_button()));
}

void Storyline::show_begin_button() {
    delete line4;
    line4 = nullptr;
    instructions_button->setParent(this);
    instructions_button->setStyleSheet("background-color: lightgreen; font: bold 15px; width: 200px; height: 30px;");

    storyline_layout->addWidget(instructions_button, 1, 1, Qt::AlignCenter);
    QObject::connect(instructions_button,SIGNAL(clicked()),this,SLOT(create_instructions()));
}


void Storyline::create_instructions() {
    Instructions* ins = new Instructions(mw);
    mw->setCentralWidget(ins);
    delete this;
}
