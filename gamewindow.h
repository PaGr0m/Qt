#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>

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

private:
    Ui::GameWindow *ui;

    QGraphicsScene *scene;
    QTimer *timer;

    QMap <int, bool> keyboardKeys;

    PG_Sprite *droid;
    PG_Sprite *stormTrooper;
};

#endif // GAMEWINDOW_H
