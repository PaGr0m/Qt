#include "gamewindow.h"
#include "ui_gamewindow.h"

#include "pg_droid.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    this->resize(800, 800);
    this->setFixedSize(800, 800);

    droid = new PG_Droid();
    stormTrooper = new PG_Sprite();
    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); // сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->addItem(droid);
    scene->addItem(stormTrooper);
    scene->addLine(0,0, 100, 0, QPen(Qt::green));
    scene->addRect(0, 0, 700, 400, QPen(Qt::red));

    // ???   scene->setSceneRect(-250, -250, 500, 500);
    // ???   scene->setSceneRect(0, 0, 1000, 1000);

    startTimer(25);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    this->keyboardKeys[event->key()] = true;
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    this->keyboardKeys[event->key()] = false;
}

void GameWindow::timerEvent(QTimerEvent *)
{
    qDebug() << "List of keys" << keyboardKeys;

    if(keyboardKeys[Qt::Key_A])
    {
        droid->frameLeft();
    }

    if(keyboardKeys[Qt::Key_D])
    {
        droid->frameRight();
    }

    if(keyboardKeys[Qt::Key_4])
    {
        stormTrooper->frameLeft();
    }

    if(keyboardKeys[Qt::Key_6])
    {
        stormTrooper->frameRight();
    }
    update();
}
