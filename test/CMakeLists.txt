SET(TEST_UNIT ${APPLICATION_BINARY_NAME}Tests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if(NOT GTEST_FOUND)
    message(WARNING "Failed to find the GTest libraries.")
endif()

file(GLOB_RECURSE TEST_SOURCE_FILES ${CMAKE_HOME_DIRECTORY}/test/*.cpp)

add_executable(${TEST_UNIT} ${TEST_SOURCE_FILES})
target_link_libraries(${TEST_UNIT} gtest gtest_main pthread ${APPLICATION_BINARY_NAME})

add_test(NAME ${TEST_UNIT} COMMAND ${TEST_UNIT})
