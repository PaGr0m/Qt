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

protected:
    // параметры спрайта
    const int startX = 50;
    const int frameHeight = 53;
    const int frameWidth = 36;
    const int spriteSpeed = 10;

    // количество спрайтов для движения
    int countStepLeft;
    int countStepRight;

    // вектор и пути
    QVector<QPixmap *> spriteVector;
    QString pathToStepLeft = ":/StarWars/Sprites/Test_1.png";
    QString pathToStepRight = ":/StarWars/Sprites/Test_1.png";
};

#endif // PG_DROID_H
