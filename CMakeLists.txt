
cmake_minimum_required(VERSION 3.25)

project(HeraldPP
	VERSION 1.0.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
	Slint
	GIT_REPOSITORY https://github.com/slint-ui/slint.git
	GIT_TAG release/1
	SOURCE_SUBDIR api/cpp
)

FetchContent_MakeAvailable(Slint)

# Collect C++ source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Collect Slint UI files (including nested directories)
file(GLOB_RECURSE UI_FILES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/ui/*.slint"
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Register Slint UI files
slint_target_sources(${PROJECT_NAME} ${UI_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	Slint::Slint
)

target_compile_options(${PROJECT_NAME} PRIVATE
	-Wall
	-Wextra
	-Wpedantic
)
