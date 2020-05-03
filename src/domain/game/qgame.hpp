#pragma once
#include <QObject>
#include <memory>

#include "domain/game/i_game_decorator.hpp"

/**
 *  Decorator for qt presentation layer implementation.
 */
class QGame : public QObject, public IGameDecorator
{
    Q_OBJECT

public:
    QGame(std::shared_ptr<IGame> game = nullptr);
    ~QGame() override = default;

    void decorate(std::shared_ptr<IGame> game) override;

    Q_INVOKABLE void run() override;
    Q_INVOKABLE void stop() override;

private:
    std::shared_ptr<IGame> game_{nullptr};
};
