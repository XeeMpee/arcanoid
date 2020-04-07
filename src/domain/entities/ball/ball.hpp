#pragma once
#include "domain/entities/i_sprite.hpp"

class Ball : public ISprite
{
private:
    double xPos_{0};
    double yPos_{0};
    double length_;

public:
    Ball(double length = 100);
    const double getXPos() override;
    const double getYPos() override;
    const double getLength();
    void setXPos(const double x) override;
    void setYPos(const double y) override;
    void setLength(const double length);

    ~Ball() override = default;
};
