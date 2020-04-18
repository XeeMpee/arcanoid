#include "game.hpp"

Game::Game(std::unique_ptr<IViewObjectGeneralized> view)
    : view_(std::move(view))
{

    view_->initSprites({board_});
}

Game::~Game() {}

void Game::run()
{
    while (isRunning_) {}
}