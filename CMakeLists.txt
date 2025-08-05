cmake_minimum_required(VERSION 3.30)
project(MyMeditationsCli)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vendor")

include(CTest)
enable_testing()

include_directories("src")

add_subdirectory(src)
add_subdirectory(unit_tests)

execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        src/compile_commands.json
        compile_commands.json
)
