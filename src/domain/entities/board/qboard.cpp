#include <spdlog/spdlog.h>
#include <boost/type_index.hpp>

#include "qboard.hpp"
#include "utils/downcaster.hpp"


QBoard::QBoard(std::shared_ptr<ISprite> sprite)
{
    decorate(sprite);
}



/**
 *  Decorates sprite with <QBoard>
 * 
 *  Strong binding - requires sprite to be <Board> type. 
 *  @param sprite sprite to decoration, needs to be exactly <Board> type
 */
void QBoard::decorate(std::shared_ptr<ISprite> sprite)
{
    decoratedSprite_ = Downcaster::cast<ISprite, Board>(sprite, "QBoard decorator must decorate Board sprite.");
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
    emit xPosChanged(x);
}


void QBoard::setYPos(double y)
{
    decoratedSprite_->setYPos(y);
    emit yPosChanged(y);
}


const double QBoard::getLength()
{
    return decoratedSprite_->getLength();
}


void QBoard::setLength(const double length)
{
    decoratedSprite_->setLength(length);
}
