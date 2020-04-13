#pragma once
#include <QQuickView>
#include <QQmlContext>
#include <QVector>
#include "domain/entities/i_sprite.hpp"
#include "i_view_object_generalized.hpp"

template<typename T>
class QViewObjectGeneralized : public IViewObjectGeneralized<T>
{
private:
    QQuickView *view_;

public:
    QViewObjectGeneralized(QQuickView *view);
    ~QViewObjectGeneralized();

    void initSprites(std::vector<std::shared_ptr<T>> sprites) override;
};

template<typename T>
QViewObjectGeneralized<T>::QViewObjectGeneralized(QQuickView *view)
    : view_(view)
{}

template<typename T>
QViewObjectGeneralized<T>::~QViewObjectGeneralized()
{}

template<typename T>
void QViewObjectGeneralized<T>::initSprites(std::vector<std::shared_ptr<T>> sprites)
{
    for(auto i : sprites) {
        view_->rootContext()->setContextProperty(i->getId(), i.get());
    }
}
