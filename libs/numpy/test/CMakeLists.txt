CONFIGURE_FILE( runCmakeTest.sh.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runCmakeTest.sh @ONLY )
GET_FILENAME_COMPONENT( TEST_SOURCE_DIR runCmakeTest.sh.in ABSOLUTE )
GET_FILENAME_COMPONENT( TEST_SOURCE_DIR ${TEST_SOURCE_DIR} PATH )

PYTHON_ADD_MODULE(dtype_mod dtype_mod.cpp)
TARGET_LINK_LIBRARIES(dtype_mod boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
ADD_TEST(dtype_mod ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runCmakeTest.sh ${TEST_SOURCE_DIR}/dtype.py)

PYTHON_ADD_MODULE(indexing_mod indexing_mod.cpp)
TARGET_LINK_LIBRARIES(indexing_mod boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
ADD_TEST(indexing_mod ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runCmakeTest.sh ${TEST_SOURCE_DIR}/indexing.py)

PYTHON_ADD_MODULE(ndarray_mod ndarray_mod.cpp)
TARGET_LINK_LIBRARIES(ndarray_mod boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
ADD_TEST(ndarray_mod ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runCmakeTest.sh ${TEST_SOURCE_DIR}/ndarray.py)

PYTHON_ADD_MODULE(shapes_mod shapes_mod.cpp)
TARGET_LINK_LIBRARIES(shapes_mod boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
ADD_TEST(shapes_mod ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runCmakeTest.sh ${TEST_SOURCE_DIR}/shapes.py)

PYTHON_ADD_MODULE(templates_mod templates_mod.cpp)
TARGET_LINK_LIBRARIES(templates_mod boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
ADD_TEST(templates_mod ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runCmakeTest.sh ${TEST_SOURCE_DIR}/templates.py)

PYTHON_ADD_MODULE(ufunc_mod ufunc_mod.cpp)
TARGET_LINK_LIBRARIES(ufunc_mod boost_numpy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
ADD_TEST(ufunc_mod ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runCmakeTest.sh ${TEST_SOURCE_DIR}/ufunc.py)

set(DEST_TEST boost.numpy/test)

install(TARGETS dtype_mod indexing_mod ndarray_mod shapes_mod templates_mod ufunc_mod LIBRARY
  DESTINATION ${DEST_TEST}
  ${INSTALL_PERMSSIONS_RUNTIME}
  )

install(FILES dtype.py indexing.py ndarray.py shapes.py templates.py ufunc.py
  DESTINATION ${DEST_TEST}
  ${INSTALL_PERMSSIONS_SRC}
  )
