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

public:
    QRectF boundingRect() const override;

public:
    virtual void frameLeft();
    virtual void frameRight();
    virtual void shoot();
    virtual bool getBulletColor();

    int getX();
    int getLeftBorder();
    int getRightBorder();

protected:
    const int startY = 250;
    int spriteCurrent;

    int frameHeight;
    int frameWidth;

    // параметры вектора спрайтов
    int countStepLeft;
    int countStepRight;
    int currentStepLeft;
    int currentStepRight;

    // границы экрана
    const int windowBorderLeft = 0;
    const int windowBorderRight = 750;

    QPixmap *tempSpriteImage;
    QPoint pointCenter;
    QRectF gameRectangle {0, 0, 800, 500};
    QVector<QPixmap *> spriteVector;

    // направление пулей
    // true ->
    // false <-
    bool bulletSide;
};

#endif // PG_SPRITE_H
