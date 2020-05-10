#include "game.hpp"

#include <memory>
#include <future>
#include <thread>
#include <chrono>

#include <spdlog/spdlog.h>

#include "domain/entities/i_sprite_decorator.hpp"
#include "domain/entities/board/qboard.hpp"
#include "domain/game/qgame.hpp"

Game::Game(std::shared_ptr<IViewObject> view)
    : view_{view}
    , board_{std::make_shared<Board>("board", 150, view_->getWidth() / 2 - 75, view->getHeight() * 0.8)}
    , ball_{std::make_shared<Ball>("ball")}
{
    auto wptr = std::shared_ptr<IGame>(this, [](IGame *) {});

    view_->initGame(shared_from_this());
    view_->initSprites({board_});
}

Game::~Game()
{
    stop();
}

void Game::run()
{
    if (isRunning_)
    {
        throw std::logic_error{fmt::format("Game::run() | Game has been alreadey ran")};
    }

    // Game loop:
    gameRunTask_ = std::async(std::launch::async, [this]() {
        isRunning_ = true;
        spdlog::info("Game main loop started.");
        while (isRunning_)
        {
            std::lock_guard<std::mutex> lock{gameLoopMutex_};
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps_));
        }
    });
}

void Game::stop()
{
    isRunning_ = false;
    gameRunTask_.get();
}