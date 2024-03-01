set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wextra -Werror -Wpadantic")
set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB SOURCES "*.cpp")

include_directories(${PROJECT_SOURCE_DIR})

add_library(libcommon STATIC ${SOURCES})

list(APPEND LIBS libcommon)
list(APPEND LIBS pthread)

add_executable(thread_example thread_example.cpp)
target_link_libraries(thread_example PUBLIC ${LIBS})

add_executable(lf_queue_example mem_pool_example.cpp)
target_link_libraries(mem_pool_example PUBLIC ${LIBS})

add_executable(logging_example logging_example.cpp)
target_link_libraries(logging_example PUBLIC ${LIBS})

add_executable(socket_example socket_example.cpp)
target_link_libraries(socket_example PUBLIC ${LIBS})
