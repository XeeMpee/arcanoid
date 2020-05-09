#include "qball.hpp"

QBall::QBall(std::shared_ptr<ISprite> sprite)
{
    decorate(sprite);
}

void QBall::decorate(std::shared_ptr<ISprite> sprite)
{
    decoratedSprite_ = sprite;
}

const std::string QBall::getId() {
    return decoratedSprite_->getId();
}

double QBall::getXPos()
{
    return decoratedSprite_->getXPos();
}

double QBall::getYPos()
{
    return decoratedSprite_->getYPos();
}

void QBall::setXPos(double x)
{
    decoratedSprite_->setXPos(x);
}

void QBall::setYPos(double y)
{
    decoratedSprite_->setYPos(y);
}

