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

Game::~Game() {}

std::future<void> Game::run()
{
    return std::async(std::launch::async, [this]() {
        unsigned int cycle = 0;
        while (isRunning_)
        {
            cycle++;
            spdlog::info("Clock tick {}...", cycle); // TODO: delete
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
}