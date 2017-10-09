#include "pg_sprite.h"

PG_Sprite::PG_Sprite(QObject *parent) : QObject(parent)
{

}

void PG_Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(pointCenter.x(),    // x
                        pointCenter.y(),    // y
                        *spriteImage,       // Pixmap
                        frameCurrent,       // x from png
                        0,                  // y from png
                        frameWidth,         // width
                        frameHeight);       // height
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

PG_Sprite &PG_Sprite::getInstance()
{
    static PG_Sprite instance;
    return instance;
}

void PG_Sprite::frameLeft()
{
    frameCurrent -= frameWidth;

    if (frameCurrent <= frameMin)
    {
        frameCurrent = frameMiddle - frameWidth;
    }
    pointCenter.setX(pointCenter.x() - offset);

    this->update(gameRectangle);
}

void PG_Sprite::frameRight()
{
    frameCurrent += frameWidth;
    if (frameCurrent <= frameMiddle)
    {

    }
    if (frameCurrent >= frameMax)
    {
        frameCurrent = frameMiddle;
    }
    pointCenter.setX(pointCenter.x() + offset);

    this->update(gameRectangle);
}

QRectF PG_Sprite::boundingRect() const
{
    return QRectF(gameRectangle);
}
