#include "MainWindow.h"
#include "Storyline.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1200,800);
}


void MainWindow::set_background(const QString & filename) {
    QPixmap bg(filename);
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette bg_palette;
    bg_palette.setBrush(QPalette::Background, bg);
    this->setPalette(bg_palette);
}
