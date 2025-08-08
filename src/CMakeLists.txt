cmake_minimum_required(VERSION 3.30)
project(MyMeditationsCliLib)

add_library(${PROJECT_NAME} 
	Database.cpp
	UiHandler.cpp
	App.cpp
)

add_executable(App MyMeditationsCli.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC . )
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/vendor)

target_link_libraries(App PRIVATE ${PROJECT_NAME})
