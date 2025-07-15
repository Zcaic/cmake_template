cmake_minimum_required(VERSION 3.26.0)
project(template VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
set(CMAKE_VERBOSE_MAKEFILE ON)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
set(FMT_TEST OFF)
set(FMT_DOC OFF)
set(FMT_FUZZ=OFF OFF) 
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(FMT_UNICODE ON)
FetchContent_Declare(
    fmt
    URL "${CMAKE_SOURCE_DIR}/externals/fmt-11.2.0.zip"
    URL_HASH SHA256=203EB4E8AA0D746C62D8F903DF58E0419E3751591BB53FF971096EAA0EBD4EC3
)

set(BUILD_TESTING OFF)
FetchContent_Declare(
    Eigen3
    URL "${CMAKE_SOURCE_DIR}/externals/eigen-3.4.0.zip"
    URL_HASH SHA256=EBA3F3D414D2F8CBA2919C78EC6DAAB08FC71BA2BA4AE502B7E5D4D99FC02CDA
)


FetchContent_MakeAvailable(fmt Eigen3)

add_executable(template "./src/main.cpp")
set_target_properties(template PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)
target_link_libraries(template PRIVATE fmt::fmt)
target_link_libraries(template PRIVATE Eigen3::Eigen)
target_link_options(template PRIVATE -static)
# set_target_properties(template PROPERTIES LINK_FLAGS "-static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic")







# add_custom_command(TARGET test POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy -t "$<TARGET_FILE_DIR:test>" "$<TARGET_RUNTIME_DLLS:test>" COMMAND_EXPAND_LISTS)