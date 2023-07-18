#pragma once

namespace easy::graphics::core {

    static const char* DEFAULT_VERTEX_SHADER_SOURCE = R"(#version 460 core
        layout (location = 0) in vec3 aPos;
        void main()
        {
           gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
    )";

    static const char* DEFAULT_FRAGMENT_SHADER_SOURCE = R"(
        #version 460 core
        out vec4 FragColor;
        in vec4 outColor;
        void main()
        {
           FragColor = outColor;
        }
    )";

}
