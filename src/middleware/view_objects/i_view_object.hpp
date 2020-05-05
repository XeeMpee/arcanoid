#pragma once
#include <vector>
#include <memory>

#include "domain/game/i_game.hpp"
#include "domain/entities/i_sprite.hpp"
#include "domain/entities/board/board.hpp"

/**
 * Class IViewObjectGeneralized 
 * 
 */
class IViewObject
{
public:
    /// Inits passed sprites.
    virtual void initGame(std::shared_ptr<IGame> game) = 0;
    virtual void initSprites(std::vector<std::shared_ptr<Board>> boards) = 0;
    virtual void show() = 0;
    virtual ~IViewObject() = default;
};


