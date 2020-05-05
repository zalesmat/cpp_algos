set(algos_ut "MZ_ALGOS_UT")

set(TEST_SRC
        test_misc_gcd.cpp
        test_misc_qs.cpp)

add_executable(${algos_ut} ${TEST_SRC})

target_include_directories(${algos_ut} PRIVATE ${CMAKE_SOURCE_DIR}/inc/)

target_link_libraries(${algos_ut}
        ${CLANG_COVERAGE_COMPILE_FLAGS}
        gtest
        pthread
        ${MZALG} )
set_target_properties(${algos_ut} PROPERTIES COMPILE_FLAGS ${CLANG_COVERAGE_COMPILE_FLAGS})
