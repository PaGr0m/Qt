#include "pg_droid.h"

PG_Droid::PG_Droid(PG_Sprite *parent) : PG_Sprite(parent)
{
    pointCenter.setX(0);
    pointCenter.setY(50);

    spriteImage = new QPixmap(":/StarWars/Sprites/Test_1.png");

    for (int i = 0; i < 12; i++)
    {

        spriteVector += spriteImage->
                new QPixmap(0,0,10,10);
    }

    frameCurrent = frameCenter;

}
