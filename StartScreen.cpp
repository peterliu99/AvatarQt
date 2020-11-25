#include "StartScreen.h"
#include "Storyline.h"
#include "MusicToggleButton.h"


StartScreen::StartScreen():
    mw(nullptr),
    start_button(nullptr),
    title(nullptr),
    startscreen_layout(nullptr),
    intro_music(nullptr)
{}


StartScreen::StartScreen(MainWindow* w):
    mw(w),
    start_button(new QPushButton("Play")),
    title(new QLabel("         Avatar:\n The Last Airbender ")),
    startscreen_layout(new QGridLayout),
    intro_music(new QMediaPlayer(this)),
    music_button(new MusicToggleButton(intro_music))

{


    // Title label related graphics
    QFont title_font("title_font", 60, QFont::ExtraBold);
    title->setStyleSheet("QLabel { background-color: rgba(209, 245, 255, 50); color: darkblue; }");
    title->setFont(title_font);
    startscreen_layout -> addWidget(title, 1, 1, Qt::AlignCenter);

    // Start button related
    start_button -> setParent(this);
    start_button -> setStyleSheet("background-color: lightgreen; font: bold 25px; width: 50px; height: 30px;");
    mw -> set_background(":/resources/img/avatar.jpg");
    startscreen_layout -> addWidget(start_button, 2, 1, Qt::AlignCenter);
    QObject::connect(start_button,SIGNAL(clicked()),this,SLOT(create_storyline()));

    // Music button related
    music_button->setParent(this);

    // Intro music
    intro_music->setMedia(QUrl("qrc:resources/sound/intro.mp3"));
    intro_music->play();

    setLayout(startscreen_layout);
}


void StartScreen::create_storyline() const {
    Storyline* s = new Storyline(mw);
    mw->setCentralWidget(s);
    delete this;
}



