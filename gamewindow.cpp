#include "gamewindow.h"
#include "ui_gamewindow.h"

#include "pg_droid.h"
#include "pg_stormtrooper.h"
#include "pg_bullet.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    this->resize(800, 500);
    this->setFixedSize(800, 500);

    droid = new PG_Droid();
    stormTrooper = new PG_StormTrooper();

    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); // сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->addItem(droid);
    scene->addItem(stormTrooper);
    scene->addLine(0,0, 100, 0, QPen(Qt::green));
    scene->addRect(0, 0, 700, 400, QPen(Qt::red));

//    music();
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

    if(keyboardKeys[Qt::Key_A]) droid->frameLeft();
    if(keyboardKeys[Qt::Key_D]) droid->frameRight();
    if(keyboardKeys[Qt::Key_Space]) createBullet();

    if(keyboardKeys[Qt::Key_4]) stormTrooper->frameLeft();
    if(keyboardKeys[Qt::Key_6]) stormTrooper->frameRight();
    if(keyboardKeys[Qt::Key_Control]) createBullet();

    checkBullet();
    update();
}

void GameWindow::checkBullet()
{
    for(auto bullet = bullets.begin(); bullet < bullets.end(); bullet++)
    {
        (*bullet)->shoot(true);
        if (((*bullet)->getX() < windowBorderLeft) ||
            ((*bullet)->getX() > windowBorderRight))
        {
            (*bullet)->deleteLater();
            bullets.erase(bullet);
        }
    }
}

void GameWindow::createBullet()
{
    auto newBullet = new PG_Bullet(droid->getX());
    bullets.push_back(newBullet);

    scene->addItem(newBullet);
    ui->graphicsView->setScene(scene);
}

void GameWindow::music()
{
    media_player = new QMediaPlayer(this);
    media_playlist = new QMediaPlaylist(media_player);

    media_player->setPlaylist(media_playlist);
    media_playlist->addMedia(QUrl("qrc:/StarWars/Sprites/SW.mp3"));

    media_player->setVolume(5);
    media_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

    media_player->play();
}
