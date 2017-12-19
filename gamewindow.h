#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "pg_sprite.h"
#include "pg_droid.h"
#include "pg_stormtrooper.h"
#include "pg_bullet.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);

    bool checkHit(PG_Sprite *person, PG_Sprite *bullet);
    void checkCollise();
    void checkBulletOutOfScreen();
    void checkDeath();

    void createBulletDroid(PG_Sprite *person, bool personSide);
    void createBulletStormTrooper(PG_Sprite *person, bool personSide);
    void music();

private:
    Ui::GameWindow *ui;

    QGraphicsScene *scene;
    QMap <int, bool> keyboardKeys;
    QString pathToFileBackGround = ":/StarWars/Resourses/Music/BackGround.jpg";

    // спрайты
    PG_Sprite *droid;
    PG_Sprite *stormTrooper;
    QVector<PG_Sprite *> bullets;

    // музыка
    QMediaPlayer *media_player;
    QMediaPlaylist *media_playlist;

    // границы экрана
    const int windowBorderLeft = 0;
    const int windowBorderRight = 800;

    // параметры окна
    const int windowWidth = 800;
    const int windowHeight = 500;

    // направление пулей
    // true ->
    // false <-
    bool bulletSideDroid = true;
    bool bulletSideStormTrooper = false;

    // цвет пули
    // true - blue
    // false - red
    bool bulletColor;

    // for collise
    int countDroid = 0;
    int countStormTrooper = 0;
    bool resultOfHit;

};

#endif // GAMEWINDOW_H
