cmake_minimum_required(VERSION 3.14)

project(modisteTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(modiste REQUIRED)
  enable_testing()
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ---- Tests ----

add_executable(modiste_test source/modiste_test.cpp)
target_link_libraries(
    modiste_test PRIVATE
    modiste::modiste
    GTest::gtest_main 
)
target_compile_features(modiste_test PRIVATE cxx_std_20)

include(GoogleTest)
gtest_discover_tests(modiste_test)

# ---- End-of-file commands ----

add_folders(Test)
