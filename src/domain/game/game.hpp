#pragma once
#include <vector>
#include <memory>
#include <mutex>
#include <future>

#include "domain/game/i_game.hpp"
#include "domain/entities/i_sprite.hpp"
#include "domain/entities/board/board.hpp"
#include "domain/entities/ball/ball.hpp"

#include "middleware/view_objects/i_view_object.hpp"


/**
 *  @brief Game basic class.
 * 
 *  Game classes for specific presentation layer can be decorated wit it
 *  using IGameDecorator. 
 */
class Game : public std::enable_shared_from_this<IGame>, public IGame
{
public:
    Game(std::shared_ptr<IViewObject> view);
    ~Game();
    void run() override;
    void stop() override;

private:
    // View object:
    std::shared_ptr<IViewObject> view_;
    
    // Entities:
    std::shared_ptr<Board> board_;
    std::shared_ptr<Ball> ball_{new Ball("ball")};
    std::vector<std::shared_ptr<Block>> blocks_{};

    // Game main loop:
    std::atomic<bool> isRunning_{false};
    std::shared_future<void> gameRunTask_;
    std::mutex gameLoopMutex_;
};
