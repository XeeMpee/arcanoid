#pragma once

#include <domain/entities/i_sprite.hpp>

class Block : public ISprite
{
private:
    std::string id_;
    double xPos_{0};
    double yPos_{0};
    double length_;

public:
    Block(double length = 100, const std::string& id = "");
    ~Block() override = default;
    const std::string getId() override;
    double getXPos() override;
    double getYPos() override;
    void setXPos(double x) override;
    void setYPos(double y) override;
};
