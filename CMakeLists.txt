cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    modiste
    VERSION 0.1.0
    DESCRIPTION "C++ template library for handling structured data across specialised and distributed systems."
    HOMEPAGE_URL "https://github.com/okinskas/modiste"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(modiste_modiste INTERFACE)
add_library(modiste::modiste ALIAS modiste_modiste)

set_property(
    TARGET modiste_modiste PROPERTY
    EXPORT_NAME modiste
)

target_include_directories(
    modiste_modiste ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(modiste_modiste INTERFACE cxx_std_20)

# ---- Depedencies ----

find_package(fmt REQUIRED)
find_package(Protobuf REQUIRED)

# ---- Link ----

target_link_libraries(modiste_modiste INTERFACE
  fmt::fmt
  protobuf::libprotobuf
)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT modiste_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of modiste"
  )
endif()

include(cmake/dev-mode.cmake)
