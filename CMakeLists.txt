macro(copy_directory _src _dst)
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${_src} ${_dst}
        RESULT_VARIABLE _res
        OUTPUT_VARIABLE _out
        ERROR_VARIABLE  _err
    )
    if(_err)
        message(FATAL_ERROR "ERROR ---> could not be copied: ${_err}")
    endif()
endmacro()

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(graphics main.cpp)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/include/SFML/lib/cmake/SFML")

target_link_libraries(graphics sfml-graphics)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake_modules)
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)  

copy_directory(${CMAKE_SOURCE_DIR}/res ${CMAKE_CURRENT_LIST_DIR}/build/res)

ADD_LIBRARY(MyLibs
    "${CMAKE_SOURCE_DIR}/lib/UI.cpp"
    "${CMAKE_SOURCE_DIR}/lib/resources.hpp"
)
target_link_libraries(MyLibs sfml-graphics)
target_link_libraries(graphics MyLibs)