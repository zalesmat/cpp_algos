cmake_minimum_required(VERSION 3.10)
project(MZ_ALGOS)

set(CMAKE_CXX_STANDARD 14)

set(CLANG_COVERAGE_COMPILE_FLAGS
    "-fprofile-instr-generate=codecov_data.profraw -fcoverage-mapping")
set(CMAKE_CXX_FLAGS "-g -O0")

set (SRC
        src/misc.cpp
        src/convex_hull.cpp)

set(MZALG "_mz_algos")
add_library(${MZALG} ${SRC})
target_include_directories(${MZALG} PRIVATE
        inc/)
set_target_properties(${MZALG} PROPERTIES COMPILE_FLAGS ${CLANG_COVERAGE_COMPILE_FLAGS})

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE inc/)
target_link_libraries(${PROJECT_NAME} ${MZALG})

include(gtest.cmake)

add_subdirectory(test)
