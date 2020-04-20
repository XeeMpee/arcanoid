#pragma once

#include <QObject>
#include "domain/entities/i_sprite_decorator.hpp"

class QBoard : public QObject, public ISpriteDecorator
{
    Q_OBJECT

private:
    std::shared_ptr<ISprite> decoratedSprite_;

public:
    QBoard() = default;
    QBoard(std::shared_ptr<ISprite> sprite);
    ~QBoard() = default;

    void decore(std::shared_ptr<ISprite> sprite) override;

    const std::string getId() override;
    const double getXPos() override;
    const double getYPos() override;
    void setXPos(const double x) override;
    void setYPos(const double y) override;
};
