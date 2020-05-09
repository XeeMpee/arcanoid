#pragma once

#include <QObject>
#include "domain/entities/i_sprite_decorator.hpp"

class QBall : public QObject, public ISpriteDecorator
{
    Q_OBJECT

private:
    std::shared_ptr<ISprite> decoratedSprite_;

public:
    QBall() = default;
    QBall(std::shared_ptr<ISprite> sprite);
    ~QBall() = default;

    void decorate(std::shared_ptr<ISprite> sprite) override;

    const std::string getId() override;
    double getXPos() override;
    double getYPos() override;
    void setXPos(const double x) override;
    void setYPos(const double y) override;
};
