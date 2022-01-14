set(PACKAGE_NAME "ctalks")
set(PACKAGE_VERSION "1.0")
set(PACKAGE_BUGREPORT "${PROJECT_BUGREPORT}")

set(
    SOURCES
    src/main.c
    src/Server.c
)

add_executable("${PACKAGE_NAME}" ${SOURCES})
configure_file(config.h.in config.h)
target_include_directories(
    "${PACKAGE_NAME}" 
    PRIVATE include
    PUBLIC "${CMAKE_CURRENT_BINARY_DIR}"
)
target_link_libraries("${PACKAGE_NAME}" PRIVATE ctalkp)