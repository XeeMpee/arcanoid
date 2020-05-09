#include <spdlog/spdlog.h>
#include "board.hpp"


Board::Board(double length, const std::string &id)
    : length_(length)
    , id_(id)
{}


const std::string Board::getId()
{
    return id_;
}


double Board::getXPos()
{
    return xPos_;
}


double Board::getYPos()
{
    return yPos_;
}


void Board::setXPos(double x)
{

    spdlog::info("Moving board x: {}", xPos_);
    xPos_ = x;
}


void Board::setYPos(double y)
{
    yPos_ = y;
}


const double Board::getLength()
{
    return length_;
}


void Board::setLength(const double length)
{
    length_ = length;
}