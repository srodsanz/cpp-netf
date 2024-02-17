cmake_minimum_required(VERSION 3.8.0...3.12.0)
project(nlos-nerf LANGUAGES C CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR})

# Configure CUDA
find_package(CUDA)
find_library(LIBNVTOOLSEXT
    NAMES nvToolsExt
    HINTS
        ENV CUDA_TOOLKIT_ROOT_DIR
        ENV CONDA_PREFIX
    PATH_SUFFIXES lib64 lib
)

#build dependencies as submodules
message(STATUS "Building dependencies added as submodules")
add_subdirectory(${CMAKE_SOURCE_DIR}/ext)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(cNeRF src/main.cpp src/model.cpp src/renderer.cpp src/utils.cpp)
target_include_directories(cNeRF PUBLIC include)
target_link_libraries(cNeRF ${TORCH_LIBRARIES} ${OpenCV_LIBS} ${CUDA_LIBRARIES})
