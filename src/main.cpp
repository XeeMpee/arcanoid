#include <spdlog/spdlog.h>
#include <memory>

#include "domain/game/game.hpp"
#include "middleware/view_objects/q_view_object.hpp"


int main(int argc, char *argv[])
{
    spdlog::info("Application running...");
    std::shared_ptr<IViewObject> view = std::make_shared<QViewObject>();
    spdlog::info("View has been initialized");
    std::shared_ptr<IGame> game = std::make_shared<Game>(view);
    view->show();

    spdlog::info("Exiting app");
}
