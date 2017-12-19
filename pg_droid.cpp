#include "pg_droid.h"
#include <QDebug>

PG_Droid::PG_Droid(PG_Sprite *parent) :
    PG_Sprite(parent)
{
    frameWidth = 36;
    frameHeight = 53;

    pointCenter.setX(startX);
    pointCenter.setY(startY);    

    currentStepLeft = 0;
    currentStepRight = 0;

    vectorStepLeft = loadVector(pathToFileStepLeft);
    vectorStepRight = loadVector(pathToFileStepRight);

    countStepLeft = vectorStepLeft.count();
    countStepRight = vectorStepRight.count();

    outputSprite = vectorStepRight.at(0);

}

void PG_Droid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(pointCenter.x(),
                        pointCenter.y(),
                        *outputSprite);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void PG_Droid::frameLeft()
{
    if (currentStepLeft == countStepLeft - 1)
        currentStepLeft = 0;
    else currentStepLeft ++;

    if (pointCenter.x() > windowBorderLeft)
        pointCenter.setX(pointCenter.x() - speed);

    outputSprite = vectorStepLeft.at(currentStepLeft);

    this->update(gameRectangle);
}

void PG_Droid::frameRight()
{
    if (currentStepRight == countStepRight - 1)
        currentStepRight = 0;
    else currentStepRight ++;

    if (pointCenter.x() < windowBorderRight)
        pointCenter.setX(pointCenter.x() + speed);

    outputSprite = vectorStepRight.at(currentStepRight);

    this->update(gameRectangle);
}

bool PG_Droid::getBulletColor()
{
    return true;
}

QVector<QPixmap *> PG_Droid::loadVector(QString path)
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
