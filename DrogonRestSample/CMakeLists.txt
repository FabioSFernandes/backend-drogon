cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set project name
project("DrogonRestSample")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Vcpkg integration
# Use barras normais (/) para maior compatibilidade no CMake no Windows
set(CMAKE_TOOLCHAIN_FILE "C:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Find Drogon
find_package(Drogon CONFIG REQUIRED)

# Add executable
add_executable(${PROJECT_NAME} src/DrogonRestSample.cpp)

# Link Drogon to the project
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
