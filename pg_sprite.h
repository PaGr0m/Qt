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
    static PG_Sprite& getInstance();

private:
    //***
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;
    //***

public:
    virtual void frameLeft();
    virtual void frameRight();

protected:
    QVector<QPixmap *> spriteVector;

    int frameCurrent;
    int frameCenter;
    int frameHeight;
    int frameWidth;
    int frameMax;
    int frameMin;
    int frameMiddle;
    int offset;
    QPoint pointCenter;

    QTimer *timer;
    QPixmap *spriteImage;
    QRectF gameRectangle{0, 0, 700, 400};
};

#endif // PG_SPRITE_H
