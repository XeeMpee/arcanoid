#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include <future>

#include "domain/game/i_game.hpp"
#include "domain/entities/board/board.hpp"
#include "domain/entities/i_sprite.hpp"

#include "middleware/view_objects_generalizers/i_view_object_generalized.hpp"

/**
    Docs
    describe
 */
class Game : public IGame
{
public:
    Game(std::shared_ptr<IViewObjectGeneralized> view);
    ~Game();
    void run() override;
    void stop() override;

private:
    std::shared_ptr<IViewObjectGeneralized> view_;
    std::shared_ptr<ISprite> board_{new Board(100, "board")};

    std::atomic<bool> isRunning_{false};
    std::future<void> gameRunTask_;
    std::mutex gameLoopMutex_;
};


