## Use CMake 2.8 or newer 
cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR) 
## set the project name 
project(BOOST_NUMPY)
## use Python 
find_package(PythonLibs 2.7 REQUIRED)
if(PYTHONLIBS_FOUND)
    include_directories(${PYTHON_INCLUDE_DIRS})
endif(PYTHONLIBS_FOUND)
## use BOOST.Python  
find_package(Boost 1.49 COMPONENTS python REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    set(Boost_USE_MULTITHREADED ON) 
    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_STATIC_RUNTIME OFF)
endif(Boost_FOUND)
find_package(ZLIB REQUIRED)

## add project root to header file search path
include_directories(".")
## set default C++ compiler flag
set(CMAKE_CXX_FLAGS_DISTRIBUTION "-g -O2")
## add src folder 
add_subdirectory(libs/numpy/src)
## install headers 
set(PROJECT_INCLUDE_DIR boost)
install(DIRECTORY ${PROJECT_INCLUDE_DIR}/
    DESTINATION "include/boost"
    FILES_MATCHING
    PATTERN "*.hpp"
    PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)



