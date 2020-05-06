#include "qblock.hpp"

QBlock::QBlock(std::shared_ptr<ISprite> sprite)
{
    decorate(sprite);
}

void QBlock::decorate(std::shared_ptr<ISprite> sprite)
{
    decoratedSprite_ = sprite;
}

const std::string QBlock::getId() {
    return decoratedSprite_->getId();
}

const double QBlock::getXPos()
{
    return decoratedSprite_->getXPos();
}

const double QBlock::getYPos()
{
    return decoratedSprite_->getYPos();
}

void QBlock::setXPos(const double x)
{
    decoratedSprite_->setXPos(x);
}

void QBlock::setYPos(const double y)
{
    decoratedSprite_->setYPos(y);
}

