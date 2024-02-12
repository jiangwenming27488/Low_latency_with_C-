set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wextra -Werror -Wpedatic")
set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB SOURCES "*cpp")

include_directories(${PROJECT_SORURCE_DIR})

add_library(libcommon STATIC ${SOURCES})
