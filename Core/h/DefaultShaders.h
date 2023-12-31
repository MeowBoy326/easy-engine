#pragma once

namespace easy::core {

    static const char* DEFAULT_VERTEX_SHADER_SOURCE = R"(
        #version 460 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec4 aColor;
        out vec4 outColor;
        void main()
        {
            gl_Position = vec4(aPos, 1.0);
            outColor = aColor;
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
