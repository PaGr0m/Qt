#include "pg_bullet.h"
#include "pg_sprite.h"

#include <QDebug>

PG_Bullet::PG_Bullet(int x, bool side, bool color)
{
    pointCenter.setX(x);
    pointCenter.setY(startY);

    bulletSide = side;

    if (color) tempSpriteImage = new QPixmap(pathToFileBulletBlue);
    else tempSpriteImage = new QPixmap(pathToFileBulletRed);
}

void PG_Bullet::shoot()
{
    if (bulletSide)
        pointCenter.setX(pointCenter.x() + bulletSpeed);
    else if (!bulletSide)
        pointCenter.setX(pointCenter.x() - bulletSpeed);

    this->update(gameRectangle);
}

void PG_Bullet::slotTimerBullet()
{
//    setPos(mapToParent(0, -10));

//    QList <QGraphicsItem *> foundItems = scene()->items(QPolygonF()
//                                                        << mapToScene(0, 0)
//                                                        << mapToScene(-1, -1)
//                                                        << mapToScene(1, -1));

//    foreach (QGraphicsItem *item, foundItems)
//    {
//        if (item == this || item->type() ==)
//            continue;

//        scene()->addItem(new Sprite(this->pos()));
//        callbackFunc(item);     // Вызываем CallBack функцию
//        this->deleteLater();    // Уничтожаем пулю
//    }

}

void PG_Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(pointCenter.x(),
                        pointCenter.y(),
                        *tempSpriteImage);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
