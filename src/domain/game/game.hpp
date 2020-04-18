#pragma once
#include <vector>
#include <memory>
#include <mutex>

#include "domain/entities/board/board.hpp"
#include "domain/entities/i_sprite.hpp"

#include "middleware/view_objects_generalizers/i_view_object_generalized.hpp"

/**
    Docs
    describe
 */
class Game
{
public:
    Game(std::unique_ptr<IViewObjectGeneralized> view);
    ~Game();
    void run();

private:
    std::unique_ptr<IViewObjectGeneralized> view_;
    std::shared_ptr<ISprite> board_{new Board(100, "board")};

    bool isRunning_;
    std::mutex isRunningMutex_;
};


