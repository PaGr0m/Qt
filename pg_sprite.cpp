#include "pg_sprite.h"
#include <QDebug>

PG_Sprite::PG_Sprite(QObject *parent) : QObject(parent)
{

}

void PG_Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void PG_Sprite::frameLeft()
{

}

void PG_Sprite::frameRight()
{

}

void PG_Sprite::shoot()
{

}

bool PG_Sprite::getBulletColor()
{

}

int PG_Sprite::getX()
{
//    return pointCenter.x() + frameWidth/2;
    return pointCenter.x() + frameWidth/2;
}

int PG_Sprite::getLeftBorder()
{
    return pointCenter.x();
}

int PG_Sprite::getRightBorder()
{
    return pointCenter.x() + frameWidth;
}

QRectF PG_Sprite::boundingRect() const
{
    return QRectF(gameRectangle);
}
