#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include <future>

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
    Game(std::shared_ptr<IViewObjectGeneralized> view);
    ~Game();
    std::future<void> run();

private:
    std::shared_ptr<IViewObjectGeneralized> view_;
    std::shared_ptr<ISprite> board_{new Board(100, "board")};

    bool isRunning_;
    std::mutex isRunningMutex_;
};


