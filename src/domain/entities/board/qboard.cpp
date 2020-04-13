#include "qboard.hpp"

QBoard::QBoard(std::unique_ptr<ISprite> sprite)
{
    decore(std::move(sprite));
}

void QBoard::decore(std::unique_ptr<ISprite> sprite)
{
    decoratedSprite_ = std::move(sprite);
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
