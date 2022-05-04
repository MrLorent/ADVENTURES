cmake_minimum_required(VERSION 3.8)

project(Adventure)
add_executable(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Enable many good warnings
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W3)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# Set the folder where the executable is created
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# Add all our src code directories to our dev environement
include_directories(
    src
    src/random
    src/ihm/menus
    src/ihm/inputs
    src/characters
)

# Add all the files
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS src/*)
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE src)