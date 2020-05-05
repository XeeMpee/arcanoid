#include <vector>
#include <memory>

struct VectorSubtypeConverter
{
    template<typename BaseType, typename SubType>
    static std::vector<std::shared_ptr<BaseType>> convert(std::vector<std::shared_ptr<SubType>> vector)
    {
        std::vector<std::shared_ptr<BaseType>> newVector{};
        for (auto &i : vector)
        {
            newVector.push_back(i);
        }
        return newVector;
    }
};