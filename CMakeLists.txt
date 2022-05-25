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
    third-party/jsoncpp/include
    src
    src/my-libs/casts
    src/my-libs/random
    src/game_engine
    src/game_engine/classes
    src/game_engine/characters
    src/game_engine/monsters
    src/ihm/menus
    src/ihm/inputs
)

# Add the jsoncpp library
add_subdirectory(${CMAKE_SOURCE_DIR}/third-party/jsoncpp)
target_link_libraries(${PROJECT_NAME} PRIVATE jsoncpp_lib)

# Add all the files
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS src/*)
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE src)

#Add a post build operation to copy assets folder to the output folder
include("CMakeUtils/files_and_folders.cmake")
Cool__target_copy_folder(${PROJECT_NAME} ${PROJECT_NAME} "assets")