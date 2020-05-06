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

const double QBall::getXPos()
{
    return decoratedSprite_->getXPos();
}

const double QBall::getYPos()
{
    return decoratedSprite_->getYPos();
}

void QBall::setXPos(const double x)
{
    decoratedSprite_->setXPos(x);
}

void QBall::setYPos(const double y)
{
    decoratedSprite_->setYPos(y);
}

