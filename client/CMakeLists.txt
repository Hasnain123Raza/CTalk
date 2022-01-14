set(
    CTALKC_SOURCES
    src/main.c
    src/Client.c
)

add_executable(ctalkc ${CTALKC_SOURCES})
target_include_directories(ctalkc PRIVATE include)