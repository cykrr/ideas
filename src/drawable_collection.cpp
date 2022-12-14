#include "drawable_collection.hpp"
#include "ball.hpp"
#include "text_ball.hpp"

template <typename T>
DrawableCollection<T>::DrawableCollection()
{
}

template <typename T>
DrawableCollection<T>::~DrawableCollection()
{
}

template <typename T>
void
DrawableCollection<T>::draw() const
{
    for (T * drawable : elements)    
    {
        // drawable->draw_collision_box();
        drawable->draw();

    }

}

template <typename T>
void
DrawableCollection<T>::update() const
{
    // for (Drawable * drawable : elements)    
    //     drawable->update_collision_box();
}


template <typename T>
void
DrawableCollection<T>::clear()
{
    this->elements.clear();
}

template <typename T>
T *
DrawableCollection<T>::insert_element(T * drawable)
{
    this->elements.push_back(drawable);
    return drawable;
}

template <typename T>
T*
DrawableCollection<T>::check_collision(const Vector2 & position) const
{
    T * ret = NULL;

    for (T *d : elements)
    {
        if (d->check_collision(position)) return d;
    }

    return ret;
}

template <typename T>
int
DrawableCollection<T>::get_count() const
{
    return this->elements.size();
}

template class DrawableCollection<Ball>;
template class DrawableCollection<TextBall>;
