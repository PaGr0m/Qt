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

    bool checkCol(QPointF person, QPointF bullet);
    void checkBullet();
    void createBullet(PG_Sprite *person, bool personSide);
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

};

#endif // GAMEWINDOW_H
