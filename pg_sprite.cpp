#include "pg_sprite.h"
#include <QDebug>

PG_Sprite::PG_Sprite(QObject *parent) : QObject(parent)
{

}

void PG_Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->drawPixmap(pointCenter.x(),
//                        pointCenter.y(),
//                        *spriteVector.at(spriteCurrent));
//    Q_UNUSED(option);
//    Q_UNUSED(widget);
}

void PG_Sprite::frameLeft()
{

}

void PG_Sprite::frameRight()
{

}

void PG_Sprite::shoot(bool side)
{

}

int PG_Sprite::getX()
{
    return pointCenter.x();
}

QRectF PG_Sprite::boundingRect() const
{
    return QRectF(gameRectangle);
}
