cmake_minimum_required(VERSION 3.10)
project(CMathTest)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include)

add_custom_target(
    build_sub_makefile ALL
    COMMAND ${CMAKE_MAKE_PROGRAM} -C ${CMAKE_CURRENT_SOURCE_DIR}/ft_printf
    COMMENT "Building external project using its Makefile"
)

add_executable(test_ft_printf test_ft_printf.cpp)

add_dependencies(test_ft_printf build_sub_makefile)

target_link_libraries(test_ft_printf gtest gtest_main pthread ${CMAKE_CURRENT_SOURCE_DIR}/../libftprintf.a)

include(GoogleTest)
gtest_discover_tests(test_ft_printf)