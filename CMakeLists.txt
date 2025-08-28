cmake_minimum_required(VERSION 3.10)
project(terraria)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adaugă folderele cu header și cod sursă
include_directories(include)
file(GLOB SRC_FILES src/*.cpp)

# Adaugă executabil
add_executable(${PROJECT_NAME} ${SRC_FILES}
        src/main.cpp)

# GLFW (presupunem că îl ai instalat în sistem sau ca submodul)
find_package(glfw3 3.3 REQUIRED)

# GLAD (adaugă sursele lui în proiect dacă l-ai descărcat)
add_library(glad src/glad.c
        src/Shader.h
        src/Shader.cpp)
target_include_directories(glad PUBLIC include)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
)

# Pe Linux trebuie să mai adaugi librării de sistem
if(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE dl GL)
endif()

