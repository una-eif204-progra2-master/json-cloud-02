cmake_minimum_required(VERSION 3.17)
project(cloud_file_test)

set(CMAKE_CXX_STANDARD 14)

find_package(CURL CONFIG REQUIRED)

include_directories(src)
include_directories(${CURL_INCLUDE_DIR})

add_subdirectory(src)
## add_subdirectory(tst)

## Use next line if you are going to use Google Test
## add_subdirectory(lib/googletest)