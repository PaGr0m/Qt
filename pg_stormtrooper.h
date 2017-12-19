#ifndef PG_STORMTROOPER_H
#define PG_STORMTROOPER_H

#include "pg_sprite.h"

class PG_StormTrooper : public PG_Sprite
{

public:
    explicit PG_StormTrooper(PG_Sprite *parent = nullptr);

private:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void frameLeft();
    virtual void frameRight();
    virtual bool getBulletColor();

    QVector<QPixmap *> loadVector(QString path);

protected:
    // параметры спрайта
    const int startX = 600;

    // вектор и пути
    QPixmap *tempSpriteImage;
    QPixmap *outputSprite;
    QVector<QPixmap *> vectorStepLeft;
    QVector<QPixmap *> vectorStepRight;
    QString pathToFileStepLeft = ":/StarWars/Resourses/StormTrooper/StepLeft.png";
    QString pathToFileStepRight = ":/StarWars/Resourses/StormTrooper/StepRight.png";
};

#endif // PG_STORMTROOPER_H
