cmake_minimum_required(VERSION 4.0)
project(openGL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_OSX_ARCHITECTURES  "arm64" CACHE STRING "Build architectures for Mac OS X" FORCE)

set(LOCAL_H /opt/homebrew/include)
include_directories(${LOCAL_H})

set(GLEW_H /opt/homebrew/Cellar/glew/2.2.0_1/include/GL)
set(GLFW_H /opt/homebrew/Cellar/glfw/3.4/include/GLFW)

link_directories(${GLEW_H} ${GLFW_H})

set(GLEW_LINK /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib)
set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.4/lib/libglfw.3.dylib)

link_libraries(${GLEW_LINK} ${GLFW_LINK})

find_package(assimp REQUIRED)


add_executable(model
        src/main.cpp
        src/glad.c
        src/shader.h
        src/camera.h
        src/model.h
        src/mesh.h
        src/stb_image.h
)

add_executable(loadFbx
        src/glad.c
        src/shader.h
        src/camera.h
        src/model.h
        src/mesh.h
        src/stb_image.h
        loadFbx.cpp
        loadFbx.h
)


if (APPLE)
    target_link_libraries(model "-framework OpenGL")
    target_link_libraries(model "-framework GLUT")
    target_link_libraries(model assimp::assimp)
endif ()

if (APPLE)
    target_link_libraries(loadFbx "-framework OpenGL")
    target_link_libraries(loadFbx "-framework GLUT")
    target_link_libraries(loadFbx assimp::assimp)
endif ()
