include_directories(..)

file(GLOB CPP_SOURCES  "*/*.cpp" "*/*.cc" main.cpp)
file(GLOB HPP_SOURCES  "*/*.h"   "*/*.hpp")

add_executable(app ${CPP_SOURCES} ${HPP_SOURCES} )
target_link_libraries(app glfw OpenGL::GL glad Core Shapes)