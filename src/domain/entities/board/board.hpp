#pragma once

#include <domain/entities/i_sprite.hpp>

class Board : public ISprite
{
private:
    std::string id_;
    double xPos_{0};
    double yPos_{0};
    double length_;

public:
    Board(const std::string &id = "", double length = 200, double x = 0, double y = 0);
    const std::string getId() override;
    double getXPos() override;
    double getYPos() override;
    void setXPos(double x) override;
    void setYPos(double y) override;

    const double getLength();
    void setLength(const double length);

    ~Board() override = default;
};
