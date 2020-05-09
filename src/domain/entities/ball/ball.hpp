#pragma once
#include "domain/entities/i_sprite.hpp"

class Ball : public ISprite
{
private:
    std::string id_;
    double xPos_{0};
    double yPos_{0};

public:
    Ball(const std::string& id="");
    const std::string getId() override;
    double getXPos() override;
    double getYPos() override;
    void setXPos(double x) override;
    void setYPos(double y) override;

    ~Ball() override = default;
};
