#include "gamewindow.h"
#include "ui_gamewindow.h"

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
    scene->setBackgroundBrush(pictureBackGround.scaled(windowWidth,
                                                       windowHeight,
                                                       Qt::IgnoreAspectRatio,
                                                       Qt::SmoothTransformation));

    music();
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
        bulletSideDroid = false;
    }
    if(keyboardKeys[Qt::Key_D])
    {
        droid->frameRight();
        bulletSideDroid = true;
    }
    if(keyboardKeys[Qt::Key_W])
    {
        droid->frameUp();
    }
    if(keyboardKeys[Qt::Key_S])
    {
        droid->frameDown();
    }
    if(keyboardKeys[Qt::Key_Space])
    {
        createBulletDroid(droid, bulletSideDroid);
    }

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
    if(keyboardKeys[Qt::Key_8])
    {
        stormTrooper->frameUp();
    }
    if(keyboardKeys[Qt::Key_2])
    {
        stormTrooper->frameDown();
    }
    if(keyboardKeys[Qt::Key_Control])
    {
        createBulletStormTrooper(stormTrooper, bulletSideStormTrooper);
    }

    checkBulletOutOfScreen();
    checkCollise();
    checkDeath();

    qDebug() << droid->getHealth();
    qDebug() << stormTrooper->getHealth();

    update();
}

bool GameWindow::checkHit(PG_Sprite *person, PG_Sprite *bullet)
{
    if (bullet->getTopBorder() > person->getTopBorder() &&
            bullet->getBottomBorder() < person->getBottomBorder())
    {
        if ((bullet->getRightBorder() > person->getLeftBorder() &&
             bullet->getRightBorder() < person->getRightBorder())
                ||
                (bullet->getLeftBorder() < person->getRightBorder() &&
                 bullet->getLeftBorder() > person->getLeftBorder()))
            return true;
        else
            return false;
    }
}

void GameWindow::checkCollise()
{
    for(auto bullet = bullets.begin(); bullet < bullets.end(); bullet++)
    {
        resultOfHit = checkHit(stormTrooper, (*bullet));
        if (resultOfHit)
        {
            (*bullet)->deleteLater();
            bullets.erase(bullet);
            stormTrooper->takeDamage();
        }

        resultOfHit = checkHit(droid, (*bullet));
        if (resultOfHit)
        {
            (*bullet)->deleteLater();
            bullets.erase(bullet);
            droid->takeDamage();
        }
    }
}

void GameWindow::checkBulletOutOfScreen()
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

void GameWindow::checkDeath()
{
    if (droid->getHealth() <= 0)
        droid->death();
    if (stormTrooper->getHealth() <= 0)
        stormTrooper->death();
}

void GameWindow::createBulletDroid(PG_Sprite* person, bool personSide)
{
    if(countDroid < 5)
    {
        countDroid++;
        return;
    }

    int flag = -1;
    if (personSide)
        flag = 1;

    auto newBullet = new PG_Bullet(person->getX() + 30*flag, person->getY(), personSide, person->getBulletColor());
    bullets.push_back(newBullet);

    scene->addItem(newBullet);
    ui->graphicsView->setScene(scene);
    countDroid = 0;
}

void GameWindow::createBulletStormTrooper(PG_Sprite *person, bool personSide)
{
    if(countStormTrooper < 5)
    {
        countStormTrooper++;
        return;
    }

    int flag = -1;
    if (personSide)
        flag = 1;

    auto newBullet = new PG_Bullet(person->getX() + 30*flag, person->getY(), personSide, person->getBulletColor());
    bullets.push_back(newBullet);

    scene->addItem(newBullet);
    ui->graphicsView->setScene(scene);
    countStormTrooper = 0;
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
