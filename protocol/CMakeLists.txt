set(
    CTALKP_SOURCES
    src/Protocol.c
)

add_library(ctalkp SHARED ${CTALKP_SOURCES})
target_include_directories(ctalkp PUBLIC include)