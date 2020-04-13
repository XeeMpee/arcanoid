#pragma once 

#include <QObject>
#include "domain/entities/i_sprite_decorator.hpp"

class QBoard : public ISpriteDecorator, public QObject
{
private:
    std::unique_ptr<ISprite> decoratedSprite_;
    /* data */
public:
    QBoard(std::unique_ptr<ISprite> sprite);
    ~QBoard() = default;

    void decore(std::unique_ptr<ISprite> sprite) override;
    const double getXPos() override;
    const double getYPos() override;
    void setXPos(const double x) override;
    void setYPos(const double y) override;
};
