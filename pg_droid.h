#ifndef PG_DROID_H
#define PG_DROID_H

#include "pg_sprite.h"

class PG_Droid : public PG_Sprite
{
public:
    explicit PG_Droid(PG_Sprite *parent = nullptr);

private:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void frameLeft();
    virtual void frameRight();
    virtual bool getBulletColor();

    QVector<QPixmap *> loadVector(QString path);

protected:
    // параметры спрайта
    const int startX = 50;
    const int frameHeight = 53; // y
//    const int frameWidth = 36;  // x
    const int spriteSpeed = 5;

    // вектор и пути
    QPixmap *tempSpriteImage;
    QPixmap *outputSprite;
    QVector<QPixmap *> vectorStepLeft;
    QVector<QPixmap *> vectorStepRight;
    QString pathToFileStepLeft = ":/StarWars/Resourses/Droid/StepLeft.png";
    QString pathToFileStepRight = ":/StarWars/Resourses/Droid/StepRight.png";
};

#endif // PG_DROID_H
