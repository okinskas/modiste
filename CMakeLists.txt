cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    modiste
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
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

target_compile_features(modiste_modiste INTERFACE cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(modiste_modiste INTERFACE fmt::fmt)

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
