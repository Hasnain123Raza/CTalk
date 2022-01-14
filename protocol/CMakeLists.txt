set(PACKAGE_NAME "ctalkp")
set(PACKAGE_VERSION "1.0")
set(PACKAGE_BUGREPORT "${PROJECT_BUGREPORT}")

set(
    SOURCES
    src/Protocol.c
)

add_library("${PACKAGE_NAME}" SHARED ${SOURCES})
configure_file(config.h.in config.h)
target_include_directories(
    "${PACKAGE_NAME}"
    PUBLIC include
    PUBLIC "${CMAKE_CURRENT_BINARY_DIR}"
)