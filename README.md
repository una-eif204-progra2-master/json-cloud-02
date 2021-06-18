# Example READ file from the cloud

The following example is to demostrate how to use external libraries to read files from cloud.

## Description of the usage

### Requirements

- C++ compilers: [MingGW](http://mingw-w64.org/doku.php) or [Visual Studio](https://visualstudio.microsoft.com/downloads/)
- Build Tool: [CMake](https://cmake.org/)
- Git access to: [Curl Library](https://github.com/curl/curl)

## CMake configuration

#### CMakeList.txt Top Level

https://github.com/una-eif204-progra2-master/json-cloud-02/blob/main/CMakeLists.txt

```cmake
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
```

#### CMakeList.Text Source Level

https://github.com/una-eif204-progra2-master/json-cloud-02/blob/main/src/CMakeLists.txt

```cmake
set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

target_link_libraries(${BINARY}_run PRIVATE CURL::libcurl)
```

