#include "pg_stormtrooper.h"
#include <QDebug>

PG_StormTrooper::PG_StormTrooper(PG_Sprite *parent) : PG_Sprite(parent)
{
    spriteCurrent = 0;
    pointCenter.setX(startX);
    pointCenter.setY(startY);

    spriteImage = new QPixmap(":/StarWars/Sprites/Test_2.png");

    for (int i = 0; i < 12; i++)
    {
        QPixmap tpix = spriteImage->copy(copyX, 0, frameWidth, frameHeight);
        spriteVector.append(new QPixmap(tpix));
        this->copyX += frameWidth;

        qDebug() << spriteVector.at(i);
    }

    countFrame = spriteVector.count();
}

void PG_StormTrooper::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(pointCenter.x(),
                        pointCenter.y(),
                        *spriteVector.at(spriteCurrent));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void PG_StormTrooper::frameLeft()
{
    if (spriteCurrent >= countFrame/2 /*5*/) spriteCurrent = 0;
    else spriteCurrent ++;

    if (pointCenter.x() > 0)
        pointCenter.setX(pointCenter.x() - offset);

    this->update(gameRectangle);
}

void PG_StormTrooper::frameRight()
{
    if (spriteCurrent < countFrame/2 || spriteCurrent == countFrame/2 - 1) spriteCurrent = countFrame/2 + 1;
    else spriteCurrent ++;

    if (pointCenter.x() < 700 - 40)
        pointCenter.setX(pointCenter.x() + offset);

    this->update(gameRectangle);
}
