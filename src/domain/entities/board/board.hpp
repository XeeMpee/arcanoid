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
    Board(double length = 100, const std::string& id = "");
    const std::string getId() override;
    double getXPos() override;
    double getYPos() override;
    void setXPos(double x) override;
    void setYPos(double y) override;
    
    const double getLength();
    void setLength(const double length);



    ~Board() override = default;
};
