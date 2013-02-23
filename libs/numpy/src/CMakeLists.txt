# PYTHON_ADD_MODULE(boost_numpy 
add_library(boost_numpy STATIC
  dtype.cpp
  scalars.cpp
  ndarray.cpp
  matrix.cpp
  ufunc.cpp
  numpy.cpp
)
