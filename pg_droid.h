#ifndef PG_DROID_H
#define PG_DROID_H

//#include <QObject>

#include "pg_sprite.h"

class PG_Droid : public PG_Sprite
{
    Q_OBJECT
public:
    explicit PG_Droid(PG_Sprite *parent = nullptr);

signals:

protected:
    int frameCurrent;
    const int frameCenter = 288;
    const int frameHeight = 53;
    const int frameWidth = 36;
    const int frameMax = 576;
    const int frameMin = 0;
    const int frameMiddle = 288;
    const int offset = 10;

    QPoint pointCenter;
    QVector<QPixmap *> spriteVector;
};

#endif // PG_DROID_H
