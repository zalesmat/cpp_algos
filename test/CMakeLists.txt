set(algos_ut "MZ_ALGOS_UT")

set(TEST_SRC
        test_convex_hull.cpp
        test_misc_gcd.cpp
        test_misc_qs.cpp)

add_executable(${algos_ut} ${TEST_SRC})

target_include_directories(${algos_ut} PRIVATE ${CMAKE_SOURCE_DIR}/inc/)
target_compile_options(${algos_ut} PRIVATE "-g" "-O0" ${CLANG_COVERAGE_COMPILE_FLAGS})
target_link_libraries(${algos_ut}
        gtest
        pthread
        ${MZALG} )
