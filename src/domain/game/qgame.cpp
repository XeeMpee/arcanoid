#include "qgame.hpp"

QGame::QGame(std::shared_ptr<IGame> game)
    : game_(game)
{
    if (game)
        decorate(game);
}

void QGame::decorate(std::shared_ptr<IGame> game)
{
    game_ = game;
}

void QGame::run()
{
    game_->run();
}

void QGame::stop()
{
    game_->stop();
}