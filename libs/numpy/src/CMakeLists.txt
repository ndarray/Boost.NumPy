# PYTHON_ADD_MODULE(boost_numpy 
add_library(boost_numpy STATIC
  ../../../boost/numpy/dtype.hpp
  ../../../boost/numpy/internal.hpp
  ../../../boost/numpy/invoke_matching.hpp
  ../../../boost/numpy/matrix.hpp
  ../../../boost/numpy/ndarray.hpp
  ../../../boost/numpy/numpy_object_mgr_traits.hpp
  ../../../boost/numpy/scalars.hpp
  ../../../boost/numpy/ufunc.hpp

  dtype.cpp
  scalars.cpp
  ndarray.cpp
  matrix.cpp
  ufunc.cpp
  numpy.cpp
)
