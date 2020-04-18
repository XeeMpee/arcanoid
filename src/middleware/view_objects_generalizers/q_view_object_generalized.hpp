#pragma once

#include <QGuiApplication>
#include <QQuickView>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>

#include "domain/entities/i_sprite.hpp"
#include "i_view_object_generalized.hpp"

class QViewObjectGeneralized : public IViewObjectGeneralized
{

public:
    QViewObjectGeneralized();
    ~QViewObjectGeneralized() override = default;

    void initSprites(std::vector<std::shared_ptr<ISprite>> sprites) override;

private:
    std::unique_ptr<QQuickView> view_;
    QGuiApplication app_;
    int argcFake{0};

    void registerQmlTypes();
    void show();
};
