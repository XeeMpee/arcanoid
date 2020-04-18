#include <QQmlContext>
#include <QQuickStyle>

#include "q_view_object_generalized.hpp"
#include <domain/entities/board/qboard.hpp>

/**
 * Initialize qt view
 * Registers ISpriteDecotation QT using classes.
 *
 */
QViewObjectGeneralized::QViewObjectGeneralized()
    : app_{argcFake, {}}
    , view_{nullptr}
{
    // Qt App initialization:
    spdlog::info("Initialing QT based view...");
    int args = 0;
    // Registing types types:
    registerQmlTypes();
    // Qt View initialization:
    view_ = std::make_unique<QQuickView>();
    view_->setSource(QUrl("qrc:///qml/Main.qml"));
}

/**
 * Registers QML Types
 * To register new class invoke qmlRegister<NewType>(<params>) function.
 */
void QViewObjectGeneralized::registerQmlTypes()
{

    qmlRegisterType<QBoard>("com.arcanoid.entities", 1, 0, "Board");
}

/**
 * Set context properties in root context of QQuickView
 * @param sprites decorated sprites with qt object derivered decorator
 * @throw std::runtime_error when downcasting fails
 */
void QViewObjectGeneralized::initSprites(std::vector<std::shared_ptr<ISprite>> sprites)
{
    for (auto i : sprites)
    {
        auto qsprite = std::dynamic_pointer_cast<QObject>(i);
        if (qsprite == nullptr)
        {
            const std::string errorMessage =
                fmt::format("QViewObjectGeneralized::initSprites() | Sprite downcasting error: {} smart pointer to QObject smart pointer.", i->getId());
            spdlog::error(errorMessage);
            throw std::runtime_error{errorMessage};
        }
        view_->rootContext()->setContextProperty(i->getId().c_str(), qsprite.get());
    }
}

void QViewObjectGeneralized::show()
{
    app_.exec();
}
