#include "pg_bullet.h"
#include "pg_sprite.h"

#include <QDebug>

PG_Bullet::PG_Bullet(int x)
{
    pointCenter.setX(x);
    pointCenter.setY(startY);

    tempSpriteImage = new QPixmap(pathToFileBullet);
}

void PG_Bullet::shoot(bool side)
{
    if (side)
        pointCenter.setX(pointCenter.x() + bulletSpeed);
    else if (!side)
        pointCenter.setX(pointCenter.x() - bulletSpeed);

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
