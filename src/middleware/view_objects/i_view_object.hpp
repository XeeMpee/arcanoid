#pragma once
#include <vector>
#include <memory>

#include "domain/game/i_game.hpp"
#include "domain/entities/i_sprite.hpp"

#include "domain/entities/board/board.hpp"
#include "domain/entities/ball/ball.hpp"
#include "domain/entities/block/block.hpp"

/**
 * Class IViewObjectGeneralized
 *
 */
class IViewObject
{
public:
    virtual ~IViewObject() = default;
    virtual void initGame(std::shared_ptr<IGame> game) = 0;
    virtual void initSprites(std::vector<std::shared_ptr<Board>> sprites) = 0;
    virtual void initSprites(std::vector<std::shared_ptr<Ball>> sprites) = 0;
    virtual void initSprites(std::vector<std::shared_ptr<Block>> sprites) = 0;
    virtual void show() = 0;
};
