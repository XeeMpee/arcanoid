#include "qboard.hpp"

QBoard::QBoard(std::shared_ptr<ISprite> sprite)
{
    decore(sprite);
}

void QBoard::decore(std::shared_ptr<ISprite> sprite)
{
    decoratedSprite_ = sprite;
}

const std::string QBoard::getId() {
    return decoratedSprite_->getId();
}

const double QBoard::getXPos()
{
    return decoratedSprite_->getXPos();
}

const double QBoard::getYPos()
{
    return decoratedSprite_->getYPos();
}

void QBoard::setXPos(const double x)
{
    decoratedSprite_->setXPos(x);
}

void QBoard::setYPos(const double y)
{
    decoratedSprite_->setYPos(y);
}

