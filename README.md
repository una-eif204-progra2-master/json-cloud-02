# Example READ file from the cloud

The following example demonstrates how to use and link external libraries (CURL) to a C++ project with a CMake configuration. The objective of this example is to create a GET request for a website in the cloud.

## Description of the usage

### Video tutorial

https://youtu.be/ho9f0WiA-1o

### Requirements

- C++ compilers: [MingGW](http://mingw-w64.org/doku.php) or [Visual Studio](https://visualstudio.microsoft.com/downloads/)
- Build Tool: [CMake](https://cmake.org/)
- Git access to: [Curl Library](https://github.com/curl/curl)

### Building using vcpkg

#### x86-Windows

```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
C:\vcpkg>bootstrap-vcpkg.bat
C:\vcpkg>vcpkg.exe integrate install
C:\vcpkg>vcpkg.exe install curl[tool]
```

#### x64-Windows

```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
C:\vcpkg>bootstrap-vcpkg.bat
C:\vcpkg>vcpkg.exe integrate install
C:\vcpkg>vcpkg.exe install curl:x64-windows
```

## CMake configuration

### CMake Options

#### x64-Windows

```properties
-DVCPKG_TARGET_TRIPLET=x64-windows 
-DCMAKE_TOOLCHAIN_FILE=C:<your-location-inpc>/vcpkg/scripts/buildsystems/vcpkg.cmake
```

#### x86-Windows

```properties
-DVCPKG_TARGET_TRIPLET=x86-windows 
-DCMAKE_TOOLCHAIN_FILE=C:<your-location-inpc>/vcpkg/scripts/buildsystems/vcpkg.cmake
```

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

