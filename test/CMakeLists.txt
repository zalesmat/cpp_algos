project(MZ_ALGOS_UT)

set(TEST_SRC
        test_misc_gcd.cpp
        test_misc_qs.cpp)

add_executable(${PROJECT_NAME} ${TEST_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc/)

target_link_libraries(${PROJECT_NAME}
        gtest
        pthread
        ${MZALG} )