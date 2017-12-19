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
    virtual bool getBulletColor();
    virtual void frameLeft();
    virtual void frameRight();
    virtual void frameUp();
    virtual void frameDown();
    virtual void death();
    virtual void shoot();    

    void takeDamage();
    int getHealth();

    int getX();
    int getY();
    int getLeftBorder();
    int getRightBorder();
    int getTopBorder();
    int getBottomBorder();

protected:
    int startY = 250;
    int speed = 5;

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
    const int windowBorderTop = 0;
    const int windowVorderBottom = 500;

    QPixmap *tempSpriteImage;
    QPoint pointCenter;
    QRectF gameRectangle {0, 0, 800, 500};
    QVector<QPixmap *> spriteVector;

    // направление пулей
    // true ->
    // false <-
    bool bulletSide;

    int healthPoint = 100;
};

#endif // PG_SPRITE_H
