#include <Shapes/h/Rectangle.h>

namespace easy::shapes {
    Rectangle::Rectangle() : Shape(GL_ARRAY_BUFFER)
    {
        vertices_.Push({});
        vertices_.Push({});
        vertices_.Push({});
        vertices_.Push({});
        Update();
    }

    Rectangle::Rectangle(const core::Position& position, float width, float height) : Shape(GL_ARRAY_BUFFER)
    {
        vertices_.Push(position);
        vertices_.Push({ {position.x + width, position.y} });
        vertices_.Push({ {position.x        , position.y - height} });
        vertices_.Push({ {position.x + width, position.y - height} });
        Update();
    }

    void Rectangle::Draw()
    {
        BaseDraw(vertices_, GL_TRIANGLE_STRIP);
    }
}
