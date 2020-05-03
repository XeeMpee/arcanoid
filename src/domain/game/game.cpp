#include "game.hpp"

#include <memory>
#include <future>
#include <thread>
#include <chrono>

#include <spdlog/spdlog.h>

#include "domain/entities/i_sprite_decorator.hpp"
#include "domain/entities/board/qboard.hpp"

Game::Game(std::shared_ptr<IViewObjectGeneralized> view)
    : view_(std::move(view))
{

    view_->initSprites({std::make_shared<QBoard>(board_)});
}

Game::~Game()
{
    stop();
}

void Game::run()
{
    if (isRunning_)
    {
        throw std::runtime_error{fmt::format("")};
    }

    // Game loop:
    gameRunTask_ = std::async(std::launch::async, [this]() {
        unsigned int cycle = 0;
        isRunning_ = true;
        while (isRunning_)
        {
            std::lock_guard<std::mutex> lock{gameLoopMutex_};
            cycle++;
            spdlog::info("Tick: {}", cycle);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
}

void Game::stop() {
    isRunning_ = false;
    gameRunTask_.get();
}