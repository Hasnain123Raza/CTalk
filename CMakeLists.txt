cmake_minimum_required(VERSION 3.16.3)

project(ctalk)

set(PROJECT_BUGREPORT "hasnain.mohsan@gmail.com")

add_subdirectory(protocol)
add_subdirectory(server)
add_subdirectory(client)