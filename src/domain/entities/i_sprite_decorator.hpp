#pragma once

#include <memory>
#include "i_sprite.hpp"

class ISpriteDecorator : public ISprite
{
public:
    virtual void decorate(std::shared_ptr<ISprite> sprite) = 0;
};