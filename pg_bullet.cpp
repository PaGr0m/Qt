#include "pg_bullet.h"
#include "pg_sprite.h"

#include <QDebug>

PG_Bullet::PG_Bullet(int x, int y, bool side, bool color)
{
    frameWidth = 12;
    frameHeight = 7;

//    startY = 270;
    speed = 8;

    pointCenter.setX(x);
    pointCenter.setY(y);

    bulletSide = side;

    if (color) tempSpriteImage = new QPixmap(pathToFileBulletBlue);
    else tempSpriteImage = new QPixmap(pathToFileBulletRed);
}

void PG_Bullet::shoot()
{
    if (bulletSide)
        pointCenter.setX(pointCenter.x() + speed);
    else if (!bulletSide)
        pointCenter.setX(pointCenter.x() - speed);

    this->update(gameRectangle);
}

void PG_Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(pointCenter.x(),
                        pointCenter.y(),
                        *tempSpriteImage);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
