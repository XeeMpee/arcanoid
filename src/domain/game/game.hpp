#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include <future>

#include "domain/game/i_game.hpp"
#include "domain/entities/board/board.hpp"
#include "domain/entities/i_sprite.hpp"

#include "middleware/view_objects/i_view_object.hpp"

/**
    Docs
    describe
 */
class Game : public std::enable_shared_from_this<IGame>, public IGame
{
public:
    Game(std::shared_ptr<IViewObject> view);
    ~Game();
    void run() override;
    void stop() override;

private:
    std::shared_ptr<IViewObject> view_;
    std::shared_ptr<Board> board_{new Board(100, "board")};

    std::atomic<bool> isRunning_{false};
    std::shared_future<void> gameRunTask_;
    std::mutex gameLoopMutex_;
};
