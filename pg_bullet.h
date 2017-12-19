#ifndef PG_BULLET_H
#define PG_BULLET_H

#include "pg_sprite.h"
#include <QTimer>

class PG_Bullet : public PG_Sprite
{
public:
    PG_Bullet(int x, bool side, bool color);

public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void shoot();

protected:
    // параметры спрайта
    const int frameHeight = 7; // y
//    const int frameWidth = 12;  // x
    const int bulletSpeed = 5;
    const int startY = 270;

    // вектор и путь
    QVector<QPixmap *> vectorBullet;
    QString pathToFileBulletBlue = ":/StarWars/Resourses/Bullet/LaserBlue.png";
    QString pathToFileBulletRed = ":/StarWars/Resourses/Bullet/LaserRed.png";
};

#endif // PG_BULLET_H
