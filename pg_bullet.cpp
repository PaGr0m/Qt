#include "pg_bullet.h"
#include "pg_sprite.h"

#include <QDebug>

PG_Bullet::PG_Bullet(int x)
{
    pointCenter.setX(x);
    pointCenter.setY(startY);

    spriteCurrent = 0;

    spriteImage = new QPixmap(":/StarWars/Sprites/sprite_sheet.png");
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
                        *spriteImage);
//                        *spriteVector.at(spriteCurrent));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
