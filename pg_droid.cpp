#include "pg_droid.h"
#include <QDebug>

PG_Droid::PG_Droid(PG_Sprite *parent) : PG_Sprite(parent)
{
    pointCenter.setX(startX);
    pointCenter.setY(startY);
    spriteCurrent = 0;

    spriteImage = new QPixmap(pathToStepLeft);

    for (int x = 0; x < spriteImage->width(); x += frameWidth)
    {
        QPixmap tempPix = spriteImage->copy(x, 0, frameWidth, frameHeight);
        spriteVector.append(new QPixmap(tempPix));
    }

    countStepLeft = spriteVector.count();
    countStepRight = spriteVector.count();
}

void PG_Droid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(pointCenter.x(),
                        pointCenter.y(),
                        *spriteVector.at(spriteCurrent));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void PG_Droid::frameLeft()
{
    if (spriteCurrent > countStepLeft)
        spriteCurrent = 0;
    else spriteCurrent ++;

    if (pointCenter.x() > windowBorderLeft)
        pointCenter.setX(pointCenter.x() - spriteSpeed);

    this->update(gameRectangle);
}

void PG_Droid::frameRight()
{
    if (spriteCurrent > countStepRight)
        spriteCurrent = 0;
    else spriteCurrent ++;

    if (pointCenter.x() < windowBorderRight)
        pointCenter.setX(pointCenter.x() + spriteSpeed);

    this->update(gameRectangle);
}
