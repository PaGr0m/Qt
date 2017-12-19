#include "pg_sprite.h"


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

void PG_Sprite::frameUp()
{
    if (pointCenter.y() > windowBorderTop)
    {
        pointCenter.setY(pointCenter.y() - speed);
        this->update(gameRectangle);
    }
}

void PG_Sprite::frameDown()
{
    if (pointCenter.y() < windowVorderBottom - frameHeight)
    {
        pointCenter.setY(pointCenter.y() + speed);
        this->update(gameRectangle);
    }
}

void PG_Sprite::shoot()
{

}

bool PG_Sprite::getBulletColor()
{

}

void PG_Sprite::takeDamage()
{
    healthPoint -= 10;
}

void PG_Sprite::death()
{
    qDebug() << "You minion is dead";
}

int PG_Sprite::getHealth()
{
    return healthPoint;
}

int PG_Sprite::getX()
{
    return pointCenter.x() + frameWidth/2;
}

int PG_Sprite::getY()
{
    return pointCenter.y() + frameHeight/2 - 10;
}

int PG_Sprite::getLeftBorder()
{
    return pointCenter.x();
}

int PG_Sprite::getRightBorder()
{
    return pointCenter.x() + frameWidth;
}

int PG_Sprite::getTopBorder()
{
    return pointCenter.y();
}

int PG_Sprite::getBottomBorder()
{
    return pointCenter.y() + frameHeight;
}

QRectF PG_Sprite::boundingRect() const
{
    return QRectF(gameRectangle);
}
