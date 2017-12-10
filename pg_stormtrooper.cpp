#include "pg_stormtrooper.h"
#include <QDebug>

PG_StormTrooper::PG_StormTrooper(PG_Sprite *parent) : PG_Sprite(parent)
{
    pointCenter.setX(startX);
    pointCenter.setY(startY);

    currentStepLeft = 0;
    currentStepRight = 0;


    vectorStepLeft = loadVector(pathToFileStepLeft);
    vectorStepRight = loadVector(pathToFileStepRight);

    countStepLeft = vectorStepLeft.count();
    countStepRight = vectorStepRight.count();

    outputSprite = vectorStepLeft.at(0);
}

void PG_StormTrooper::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(pointCenter.x(),
                        pointCenter.y(),
                        *outputSprite);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void PG_StormTrooper::frameLeft()
{
    if (currentStepLeft == countStepLeft - 1)
        currentStepLeft = 0;
    else currentStepLeft ++;

    if (pointCenter.x() > windowBorderLeft)
        pointCenter.setX(pointCenter.x() - spriteSpeed);

    outputSprite = vectorStepLeft.at(currentStepLeft);

    this->update(gameRectangle);
}

void PG_StormTrooper::frameRight()
{
    if (currentStepRight == countStepRight - 1)
        currentStepRight = 0;
    else currentStepRight ++;

    if (pointCenter.x() < windowBorderRight)
        pointCenter.setX(pointCenter.x() + spriteSpeed);

    outputSprite = vectorStepRight.at(currentStepRight);

    this->update(gameRectangle);
}

QVector<QPixmap *> PG_StormTrooper::loadVector(QString path)
{
    tempSpriteImage = new QPixmap(path);
    QVector<QPixmap *> vector;

    for (int x = 0; x < tempSpriteImage->width(); x += frameWidth)
    {
        QPixmap tempPix = tempSpriteImage->copy(x, 0, frameWidth, frameHeight);
        vector.append(new QPixmap(tempPix));
    }

    return vector;
}
