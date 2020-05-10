#pragma once
#include <memory>
#include <string>

/**
 *  @brief Tool for casting objects of specyfied type to object of its subtype.
 */
struct Downcaster
{
    /**
     *  @brief Cast object og BasicClass to object of SubClass
     * 
     *  SubClass have to inherit BasicClass. 
     *  Uses dynamic cast.
     * 
     *  @tparam BasicClass  class of passed object
     *  @tparam SubClass    class of returned value, must inherit BasicClass
     *  @param obj  objct passed to get its subtype object
     *  @param errorMessage message dispayed on error
     */
    template<typename BasicClass, typename SubClass>
    static std::shared_ptr<SubClass> cast(std::shared_ptr<BasicClass> obj, const std::string &errorMessage = "")
    {
        std::shared_ptr<SubClass> subObject = std::dynamic_pointer_cast<SubClass>(obj);
        if (!subObject)
        {
            auto msg = fmt::format("Downcasting error: from {} to {}. {}", boost::typeindex::type_id_runtime(obj).pretty_name(),
                boost::typeindex::type_id_runtime(subObject).pretty_name(), errorMessage);

            spdlog::error(msg);
            throw std::runtime_error(msg);
        }
        return subObject;
    }
};
