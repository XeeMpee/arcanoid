#pragma once
#include <vector>
#include <memory>
#include <mutex>

#include "domain/entities/board/board.hpp"
#include "domain/entities/i_sprite.hpp"

/**
    Docs
 */
class Game
{
private:
    std::shared_ptr<Board> board_;
    std::vector<std::shared_ptr<ISprite>> sprites_;

    bool isRunning_;
    std::mutex isRunningMutex_;

public:
    Game();
    ~Game();
    void run();

};


