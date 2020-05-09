#include <spdlog/spdlog.h>
#include <boost/type_index.hpp>
#include "qboard.hpp"

QBoard::QBoard(std::shared_ptr<ISprite> sprite)
{
    decorate(sprite);
}

void QBoard::decorate(std::shared_ptr<ISprite> sprite)
{
    decoratedSprite_ = std::dynamic_pointer_cast<Board>(sprite);
    if (!decoratedSprite_)
    {
        auto msg = fmt::format("QBoard have to decorate Board object! Try of decoration wit [{}] failed",
            boost::typeindex::type_id_runtime(sprite).pretty_name());
        spdlog::error(msg);
        throw std::runtime_error(msg);
    }
}

const std::string QBoard::getId()
{
    return decoratedSprite_->getId();
}

double QBoard::getXPos()
{
    return decoratedSprite_->getXPos();
}

double QBoard::getYPos()
{
    return decoratedSprite_->getYPos();
}

void QBoard::setXPos(double x)
{
    decoratedSprite_->setXPos(x);
}

void QBoard::setYPos(double y)
{
    decoratedSprite_->setYPos(y);
}

const double QBoard::getLength()
{
    return decoratedSprite_->getLength();
}

void QBoard::setLength(const double length)
{
    decoratedSprite_->setLength(length);
}
