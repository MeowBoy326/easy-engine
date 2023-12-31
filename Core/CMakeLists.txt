include_directories(..)

#lib name
set(LIB_NAME "Core")

# Per example: LIBS_DEPENDENCIES OpenSSL::SSL OpenSSL::Crypto
set(LIBS_DEPENDENCIES boost::boost glfw OpenGL::GL glad)

#define lib sources
file(GLOB CPP_SOURCES  "c/*.cpp" "c/*.cc")
file(GLOB HPP_SOURCES  "h/*.h" "h/*.hpp")

# Support IDE Visualization
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CPP_SOURCES} ${HPP_SOURCES})

#define lib
if (BUILD_SHARED_LIBS)
	add_library(${LIB_NAME} SHARED ${CPP_SOURCES} ${HPP_SOURCES})
else()
	add_library(${LIB_NAME} STATIC ${CPP_SOURCES} ${HPP_SOURCES})
endif()

# Define Target Properties and Optional OpenSSL Dependency
generate_export_header(${LIB_NAME} EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/${LIB_NAME}_api.h)

target_include_directories(${LIB_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/exports>
	..
)

if(LIBS_DEPENDENCIES)
	target_link_libraries(${LIB_NAME} PUBLIC ${LIBS_DEPENDENCIES})
endif()