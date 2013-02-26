=============
 CMake Build
=============

Borrowed from opencv:

.. code-block:: cmake

   set(BUILD_DOCS ON CACHE BOOL "Build OpenCV Documentation")

   if(BUILD_DOCS)
    include(OpenCVFindLATEX.cmake REQUIRED)
   endif()


   # documentation
   status("")
   status("  Documentation:")
   status("    Sphinx:"              HAVE_SPHINX              THEN "${SPHINX_BUILD} (ver ${SPHINX_VERSION})" ELSE NO)
   status("    PdfLaTeX compiler:"   PDFLATEX_COMPILER        THEN "${PDFLATEX_COMPILER}" ELSE NO)
   if (BUILD_DOCS AND HAVE_SPHINX)
     status("    Build Documentation:" PDFLATEX_COMPILER THEN YES ELSE "YES (only HTML without math formulas)")
   else()
     status("    Build Documentation:" NO)
   endif()

   execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "import sphinx; print sphinx.__version__"
     RESULT_VARIABLE SPHINX_PROCESS
     OUTPUT_VARIABLE SPHINX_VERSION
     OUTPUT_STRIP_TRAILING_WHITESPACE)

   set(HAVE_SPHINX 0)
   if(SPHINX_PROCESS EQUAL 0)
     find_host_program(SPHINX_BUILD sphinx-build)
     if(SPHINX_BUILD)
       set(HAVE_SPHINX 1)
       message(STATUS "    Found Sphinx ${SPHINX_VERSION}: ${SPHINX_BUILD}")
     endif()
   endif()





