cmake_minimum_required(VERSION 3.14)

project(modisteTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(modiste REQUIRED)
  enable_testing()
endif()

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(modiste_test source/modiste_test.cpp)
target_link_libraries(
    modiste_test PRIVATE
    modiste::modiste
    Catch2::Catch2WithMain
)
target_compile_features(modiste_test PRIVATE cxx_std_17)

catch_discover_tests(modiste_test)

# ---- End-of-file commands ----

add_folders(Test)
