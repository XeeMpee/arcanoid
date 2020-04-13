#pragma once
#include <vector>
#include <memory>

template<typename T>
class IViewObjectGeneralized
{
public:
    virtual void initSprites(std::vector<std::shared_ptr<T>> sprites) = 0;
    virtual ~IViewObjectGeneralized() = default;
};


