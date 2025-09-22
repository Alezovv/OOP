cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции (УЛУЧШЕННАЯ ВЕРСИЯ)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
# Werror=maybe-uninitialized может быть слишком строгим для начала

# Установка Google Test (ИСПРАВЛЕННАЯ ВЕРСИЯ)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Библиотека unset_bits
add_library(unset_bits src/unset_bits.cpp)
target_include_directories(unset_bits 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Основной исполняемый файл
add_executable(main main.cpp)
target_include_directories(main PRIVATE include)
target_link_libraries(main PRIVATE unset_bits)

# Добавление тестов
enable_testing()
add_executable(tests test/tests01.cpp)
target_include_directories(tests PRIVATE include)  # УБРАЛ src - заголовки в include

# Связываем с библиотекой и gtest
target_link_libraries(tests PRIVATE unset_bits gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME MyProjectTests COMMAND tests)

add_custom_command(TARGET tests
    POST_BUILD
    COMMAND tests
    COMMENT "Running unit tests after build"
)