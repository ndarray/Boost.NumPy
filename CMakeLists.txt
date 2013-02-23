cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/libs/numpy/cmake)

find_package(PythonInterp REQUIRED)
find_package(PythonLibsNew REQUIRED)
find_package(NumPy REQUIRED)

FIND_PACKAGE(Boost COMPONENTS python)

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
