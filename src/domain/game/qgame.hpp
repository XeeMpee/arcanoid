#pragma once
#include <QObject>
#include <memory>

#include "domain/game/i_game_decorator.hpp"

/** 
 *  @brief Game class specyfic for QT based presentation layer.
 * 
 *  Should decorate Game class or any other IGameDecorator,
 *  which decorates Game.
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
