cmake_minimum_required(VERSION 3.20)

project(DistributedStore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Store
    src/storage.cpp
)

target_include_directories(Store
    PUBLIC
        src
)

add_executable(DistributedStore
    src/main.cpp
)

target_link_libraries(DistributedStore
    PRIVATE
        Store
)

# Enable CTest
include(CTest)

if(BUILD_TESTING)

    # Download GoogleTest
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(DistributedStoreTests
        tests/test.cpp
    )

    target_link_libraries(DistributedStoreTests
        PRIVATE
            Store
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(DistributedStoreTests)

endif()