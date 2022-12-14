#include <vector>
#include "drawable.hpp"

template <typename T>
class DrawableCollection
{
public:
    DrawableCollection();
    ~DrawableCollection();
    T *insert_element(T * drawable);
    void draw() const;
    void update() const;
    void clear();
    T *check_collision(const Vector2 & position) const;
    int get_count() const;

private:
    std::vector<T *> elements;
    
};
