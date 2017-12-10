#ifndef PG_BULLET_H
#define PG_BULLET_H

#include "pg_sprite.h"
#include <QTimer>

class PG_Bullet : public PG_Sprite
{
public:
    PG_Bullet(int x);

private:

public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void shoot(bool side);

    void slotTimerBullet();

protected:
    // параметры спрайта
    const int frameHeight = 176; // y
    const int frameWidth = 114;  // x
    const int bulletSpeed = 11;
    const int startY = 270;

    // вектор и путь
    QVector<QPixmap *> vectorBullet;
    QString pathToFileBullet = ":/StarWars/Resourses/Bullet/LaserBlue.png";
};

#endif // PG_BULLET_H
