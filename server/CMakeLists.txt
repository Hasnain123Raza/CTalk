set(
    CTALKS_SOURCES
    src/main.c
    src/Server.c
)

add_executable(ctalks ${CTALKS_SOURCES})
target_include_directories(ctalks PRIVATE include)
target_link_libraries(ctalks PRIVATE ctalkp)