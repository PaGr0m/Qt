#ifndef PG_SPRITE_H
#define PG_SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class PG_Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit PG_Sprite(QObject *parent = nullptr);

private:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;

public:
    virtual void frameLeft();
    virtual void frameRight();
    virtual void shoot(bool side);

    int getX();

protected:
    int spriteCurrent;

    const int startY = 250;

    // границы экрана
    const int windowBorderLeft = 0;
    const int windowBorderRight = 600;

    QPoint pointCenter;
    QPixmap *spriteImage;
    QRectF gameRectangle {0, 0, 700, 400};
    QVector<QPixmap *> spriteVector;
};

#endif // PG_SPRITE_H
