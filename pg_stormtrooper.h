#ifndef PG_STORMTROOPER_H
#define PG_STORMTROOPER_H

#include "pg_sprite.h"

class PG_StormTrooper : public PG_Sprite
{
//    Q_OBJECT
public:
    explicit PG_StormTrooper(PG_Sprite *parent = nullptr);

private:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void frameLeft();
    virtual void frameRight();

protected:
    int frameCurrent;
    int copyX = 0;
//    int copyY = 0;
//    int copyWidth = 0;
//    int copyHeight = 0;

    const int frameCenter = 288;
    const int frameHeight = 58;
    const int frameWidth = 43;
    const int frameMax = 576;
    const int frameMin = 0;
    const int frameMiddle = 288;
    const int offset = 10;

    QPixmap qwe;
    QPoint pointCenter;
    QVector<QPixmap *> spriteVector;

    const int startX = 650 - frameWidth;
    int countFrame;
};

#endif // PG_STORMTROOPER_H
