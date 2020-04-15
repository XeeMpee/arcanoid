#pragma once
#include "domain/entities/i_sprite.hpp"

namespace Arcanoid {

class Ball : public ISprite
{
private:
    std::string id_;
    double xPos_{0};
    double yPos_{0};

public:
    Ball(const std::string& id="");
    const std::string getId() override;
    const double getXPos() override;
    const double getYPos() override;
    const double getLength();
    void setXPos(const double x) override;
    void setYPos(const double y) override;

    ~Ball() override = default;
};

}