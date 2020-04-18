#pragma once

#include <memory>
#include <any>
#include "i_sprite.hpp"

class ISpriteDecorator : public ISprite
{
public:
    virtual void decore(std::unique_ptr<ISprite> sprite) = 0;
};