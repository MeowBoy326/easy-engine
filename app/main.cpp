#include <iostream>

#include <Core/h/Vertex.h>
#include <Core/h/VertexVector.h>

int main()
{
    easy::graphics::core::VertexVector vector{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (size_t i = 0; i < vector.Size() * 3; ++i) 
    {
        std::cout << *((float*)vector.GetRaw() + i) << std::endl;
    }
}

