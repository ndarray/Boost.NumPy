cmake_minimum_required(VERSION 2.8.3)

# put our local cmake find scripts at the beginning of the cmake
# module search path
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/libs/numpy/cmake ${CMAKE_MODULE_PATH})

# configure output folders so artifacts are built into a single set of
# top-level folders rather than the default cmake build structure that
# matches the source tree.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib 
    CACHE PATH "Output directory for static libraries.")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    CACHE PATH "Output directory for shared libraries.")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    CACHE PATH "Output directory for executables and DLL's.")

find_package(PythonInterp REQUIRED)
find_package(PythonLibsNew REQUIRED)
find_package(NumPy REQUIRED)

# set(Boost_USE_STATIC_LIBS ON)
# set(Boost_USE_MULTITHREADED ON) 
# set(Boost_USE_STATIC_RUNTIME ON)
FIND_PACKAGE(Boost COMPONENTS python REQUIRED)

message( STATUS "found boost:"
  "\nINCLUDE: ${Boost_INCLUDE_DIRS}"
  "\nLIB: ${Boost_LIBRARIES}"
)

# add_definitions( -DBOOST_ALL_NO_LIB )
# In some cases, you may need to explicitly specify that a dynamic Boost is used; if so use:
# add_definitions( -DBOOST_ALL_DYN_LINK )

if (NOT WIN32)
  add_definitions(-fPIC)
endif()

ENABLE_TESTING()

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PYTHON_INCLUDE_DIRS}
  ${NUMPY_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS} 
  )

LINK_LIBRARIES(${Boost_LIBRARIES}) # Deprecated but so convenient!
LINK_LIBRARIES(${PYTHON_LIBRARY})

ADD_SUBDIRECTORY(libs/numpy/src)
ADD_SUBDIRECTORY(libs/numpy/example)
ADD_SUBDIRECTORY(libs/numpy/test)
