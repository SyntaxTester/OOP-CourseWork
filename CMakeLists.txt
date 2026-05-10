cmake_minimum_required(VERSION 3.14)
project(TaskManager CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_manager
    main.cpp
    Task.cpp
    WorkTask.cpp
    UrgentWorkTask.cpp
    StudyTask.cpp
    TaskManager.cpp
)

target_compile_options(task_manager PRIVATE -Wall -Wextra)
