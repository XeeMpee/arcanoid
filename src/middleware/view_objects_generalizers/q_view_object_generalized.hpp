#pragma once

#include <QGuiApplication>
#include <QQuickView>
#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>

#include "i_view_object_generalized.hpp"

#include "domain/entities/i_sprite.hpp"
#include <domain/game/qgame.hpp>
#include <domain/entities/board/qboard.hpp>

class QViewObjectGeneralized : public IViewObjectGeneralized
{

public:
    QViewObjectGeneralized();
    ~QViewObjectGeneralized() override = default;

    void initGame(std::shared_ptr<IGame> game) override;
    void initSprites(std::vector<std::shared_ptr<ISprite>> sprites) override;

private:
    int argcFake{0};
    std::unique_ptr<QQuickView> view_;
    QGuiApplication app_;

    std::shared_ptr<QGame> game_{nullptr};

    void registerQmlTypes();
    void show();
};
