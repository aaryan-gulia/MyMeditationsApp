cmake_minimum_required(VERSION 3.30)
project(MyMeditationsCliLib)

add_library(${PROJECT_NAME} 
	MyMeditationsCli.cpp
	Database.cpp
)


target_include_directories(${PROJECT_NAME} PUBLIC . )
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/vendor)
