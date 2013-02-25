project(doc-html)
add_custom_target(doc-html make -C ${PROJECT_SOURCE_DIR} html BUILDDIR=${PROJECT_BINARY_DIR}/_build)

project(doc-pdf)
add_custom_target(doc-pdf make -C ${PROJECT_SOURCE_DIR} latexpdf BUILDDIR=${PROJECT_BINARY_DIR}/_build)

install(DIRECTORY ${PROJECT_BINARY_DIR}/_build/html
  DESTINATION boost.numpy/doc
  ${INSTALL_PERMISSIONS_SRC}
  )

install(FILES ${PROJECT_BINARY_DIR}/_build/latex/BoostNumPy.pdf
  DESTINATION boost.numpy/doc
  ${INSTALL_PERMISSIONS_SRC}
  )
