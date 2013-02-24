add_library(boost_numpy SHARED dtype.cpp matrix.cpp ndarray.cpp scalars.cpp ufunc.cpp numpy.cpp)
set_target_properties(boost_numpy PROPERTIES VERSION ${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION})
target_link_libraries(boost_numpy ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} ${ZLIB_LIBRARIES} dl util)
install(TARGETS boost_numpy LIBRARY DESTINATION lib PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
