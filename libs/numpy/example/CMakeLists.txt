
PYTHON_ADD_MODULE(gaussian gaussian.cpp)
TARGET_LINK_LIBRARIES(gaussian boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})

ADD_EXECUTABLE(dtype dtype.cpp)
TARGET_LINK_LIBRARIES(dtype  boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})

ADD_EXECUTABLE(fromdata fromdata.cpp)
TARGET_LINK_LIBRARIES(fromdata  boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})

ADD_EXECUTABLE(ndarray ndarray.cpp)
TARGET_LINK_LIBRARIES(ndarray  boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})

ADD_EXECUTABLE(simple simple.cpp)
TARGET_LINK_LIBRARIES(simple  boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})

ADD_EXECUTABLE(ufunc ufunc.cpp)
TARGET_LINK_LIBRARIES(ufunc boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})

ADD_EXECUTABLE(wrap wrap.cpp)
TARGET_LINK_LIBRARIES(wrap  boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
