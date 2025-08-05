cmake_minimum_required(VERSION 3.30)
project(unit_tests)

add_executable(meditation_test meditation_test.cpp)
target_link_libraries(meditation_test MyMeditationsCliLib)
add_test(NAME meditation_test COMMAND meditation_test)

add_executable(database_test database_test.cpp)
target_link_libraries(database_test MyMeditationsCliLib)
add_test(NAME database_test COMMAND database_test)

