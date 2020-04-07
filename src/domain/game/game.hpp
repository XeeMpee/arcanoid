#pragma once
#include <vector>
#include <memory>

#include "domain/entities/board/board.hpp"

class Game
{
private:
    std::vector<std::shared_ptr<Board>> boards;
public:
    Game(/* args */);
    ~Game();
};


