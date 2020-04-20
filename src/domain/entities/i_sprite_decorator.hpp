#pragma once

#include <memory>
#include <any>
#include "i_sprite.hpp"

class ISpriteDecorator : public ISprite
{
public:
    virtual void decore(std::shared_ptr<ISprite> sprite) = 0;
};