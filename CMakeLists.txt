cmake_minimum_required(VERSION 3.5)
project(CatDetectionProject)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Find OpenCV packages
find_package(OpenCV REQUIRED)

# Include directories for OpenCV and project headers
include_directories(${OpenCV_INCLUDE_DIRS} include)

# Set source files
set(SOURCES
    src/kittyeats.cpp
    src/detection.cpp
    src/notification.cpp
    src/yolo.cpp
)

# Add executable target
add_executable(CatDetectionProject ${SOURCES})

# Link libraries
target_link_libraries(CatDetectionProject ${OpenCV_LIBS})
