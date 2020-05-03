#pragma once
#include "i_game.hpp"
#include <memory>

/**
 *  Decorator of IGames.
 *  Allows to adjust game to  presentation layer implementation .
 */
class IGameDecorator : public IGame
{
public:
    virtual ~IGameDecorator() = default;
    virtual void decorate(std::shared_ptr<IGame> game) = 0;
};