cmake_minimum_required(VERSION 3.23...3.28)

project(calculator-project LANGUAGES C)

set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set_property(CACHE CMAKE_INSTALL_PREFIX PROPERTY VALUE "${CMAKE_BINARY_DIR}/dist")
endif()

add_subdirectory(${PROJECT_ROOT}/assets)
add_subdirectory(${PROJECT_ROOT}/external/their)
add_subdirectory(${PROJECT_ROOT}/src/calculator)
add_subdirectory(${PROJECT_ROOT}/src/operations)
include(CTest)  # defines BUILD_TESTING
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # I'm the top-most project
    option(OPERATIONS_BUILD_TESTING "Whether to build the liboperations tests" ${BUILD_TESTING})
    if ((BUILD_TESTING AND NOT OPERATIONS_BUILD_TESTING) OR
        (NOT BUILD_TESTING AND OPERATIONS_BUILD_TESTING))
        message(WARNING, " will use more specific -DOPERATIONS_BUILD_TESTING=${OPERATIONS_BUILD_TESTING} over -DBUILD_TESTING=${BUILD_TESTING}")
    endif()
else()
    # I'm not the top-most project, use OPERATIONS_BUILD_TESTING as-is
    option(OPERATIONS_BUILD_TESTING "Whether to build the liboperations tests" OFF)
endif()
if (OPERATIONS_BUILD_TESTING)
    add_subdirectory(${PROJECT_ROOT}/test/operations)
endif()
