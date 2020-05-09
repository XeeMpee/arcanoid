#pragma once

#include <QGuiApplication>
#include <QQuickView>
#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>

#include "i_view_object.hpp"
#include "domain/entities/i_sprite.hpp"
#include <domain/game/qgame.hpp>

class QViewObject : public IViewObject
{
public:
    QViewObject();
    ~QViewObject() override = default;

    void initGame(std::shared_ptr<IGame> game) override;
    template<typename SpriteQType>
    void initSprites(std::vector<std::shared_ptr<ISprite>> sprites);
    void initSprites(std::vector<std::shared_ptr<Board>> sprites) override;
    void initSprites(std::vector<std::shared_ptr<Ball>> sprites) override;
    void initSprites(std::vector<std::shared_ptr<Block>> sprites) override;

private:
    int argcFake{0};
    std::unique_ptr<QQuickView> view_;
    QGuiApplication app_;
    int width_{1080};
    int height_{720};

    std::shared_ptr<QGame> game_{nullptr};
    std::vector<std::unique_ptr<ISprite>> sprites_{};

    void registerQmlTypes();
    void setViewProperties();
    void show();
};
