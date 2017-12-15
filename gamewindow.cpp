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
    this->setWindowTitle("Star fighting");

    QPixmap pictureBackGround(pathToFileBackGround);

    scene = new QGraphicsScene(0, 0, windowWidth, windowHeight);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); // сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    droid = new PG_Droid();
    stormTrooper = new PG_StormTrooper();

    scene->addItem(droid);
    scene->addItem(stormTrooper);
//    scene->setBackgroundBrush(pictureBackGround.scaled(windowWidth,
//                                                       windowHeight,
//                                                       Qt::IgnoreAspectRatio,
//                                                       Qt::SmoothTransformation));

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
//    qDebug() << "List of keys" << keyboardKeys;

    if(keyboardKeys[Qt::Key_A])
    {
        droid->frameLeft();
        bulletSideDroid = false;
    }
    if(keyboardKeys[Qt::Key_D])
    {
        droid->frameRight();
        bulletSideDroid = true;
    }
    if(keyboardKeys[Qt::Key_Space]) createBullet(droid, bulletSideDroid);

    if(keyboardKeys[Qt::Key_4])
    {
        stormTrooper->frameLeft();
        bulletSideStormTrooper = false;
    }
    if(keyboardKeys[Qt::Key_6])
    {
        stormTrooper->frameRight();
        bulletSideStormTrooper = true;
    }
    if(keyboardKeys[Qt::Key_Control]) createBullet(stormTrooper, bulletSideStormTrooper);

//    droid->mapRectFromItem();
    checkBullet();
    for(auto b: bullets)
    {
        auto res = checkCol(stormTrooper->pos(), b->pos());
        qDebug() << res;
        if (res)
        {
//            b->deleteLater();
//            bullets.erase(*b);
            qDebug() << "Попал";
        }
    }

    update();
}

bool GameWindow::checkCol(QPointF person, QPointF bullet)
{
    if (bullet.x() == person.x())
        return true;
    else
        return false;

//    if (bullet.x() > person.x() &&
//        bullet.x() < (person.x() + person.width()))
//        return true;
//    else if ((bullet.x() + bullet.width()) > person.x() &&
//             (bullet.x() + bullet.width()) < (person.x() + person.width()))
//        return true;
//    else return false;
}

void GameWindow::checkBullet()
{
    for(auto bullet = bullets.begin(); bullet < bullets.end(); bullet++)
    {
        (*bullet)->shoot();
        if (((*bullet)->getX() < windowBorderLeft) ||
            ((*bullet)->getX() > windowBorderRight))
        {
            (*bullet)->deleteLater();
            bullets.erase(bullet);
        }
    }
}

void GameWindow::createBullet(PG_Sprite* person, bool personSide)
{
    auto newBullet = new PG_Bullet(person->getX(), personSide, person->getBulletColor());
    bullets.push_back(newBullet);

    scene->addItem(newBullet);
    ui->graphicsView->setScene(scene);
}

void GameWindow::music()
{
    media_player = new QMediaPlayer(this);
    media_playlist = new QMediaPlaylist(media_player);

    media_player->setPlaylist(media_playlist);
    media_playlist->addMedia(QUrl("qrc:/StarWars/Resourses/Music/Star Wars - Imperial March (8-bit).mp3"));

    media_player->setVolume(5);
    media_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

    media_player->play();
}
