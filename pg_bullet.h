#ifndef PG_BULLET_H
#define PG_BULLET_H

#include "pg_sprite.h"
#include <QTimer>

class PG_Bullet : public PG_Sprite
{
public:
    PG_Bullet(int x);

private:

public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void shoot(bool side);

protected:
    QVector<QPixmap *> spriteVector;
    QTimer *timer;

    const int bulletSpeed = 1;

    const int frameHeight = 200;
    const int frameWidth = 20;

    QString pathToFile =
};

#endif // PG_BULLET_H
