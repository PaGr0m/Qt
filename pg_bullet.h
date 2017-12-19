#ifndef PG_BULLET_H
#define PG_BULLET_H

#include "pg_sprite.h"

class PG_Bullet : public PG_Sprite
{
public:
    PG_Bullet(int x, int y, bool side, bool color);

public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void shoot();

protected:
    // вектор и путь
    QVector<QPixmap *> vectorBullet;
    QString pathToFileBulletBlue = ":/StarWars/Resourses/Bullet/LaserBlue.png";
    QString pathToFileBulletRed = ":/StarWars/Resourses/Bullet/LaserRed.png";
};

#endif // PG_BULLET_H
