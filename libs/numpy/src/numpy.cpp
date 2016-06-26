// Copyright Jim Bosch 2010-2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_NUMPY_INTERNAL_MAIN
#include <boost/numpy/internal.hpp>
#include <boost/numpy/dtype.hpp>

namespace boost 
{
namespace numpy 
{

// NumPy's import_* macros always return if they encounter an error,
// but in Python 2 there's no return value, while Python 3 returns
// null on an error.  The machinery below produces the same behavior
// on both Python versions: initialize returns false with an exception
// raised if there is an exception.

static
#if PY_MAJOR_VERSION == 2
void
#else
PyObject *
#endif
wrap_imports()
{
  import_array();
  import_ufunc();
#if PY_MAJOR_VERSION > 2
  Py_RETURN_NONE;
#endif
}

bool initialize(bool register_scalar_converters) 
{
#if PY_MAJOR_VERSION == 2
  wrap_imports();
  if (PyErr_Occurred()) return false;
#else
  PyObject * r = wrap_imports();
  if (!r) return false;
  Py_DECREF(r);
#endif
  if (register_scalar_converters)
	dtype::register_scalar_converters();
  return true;
}

}
}
