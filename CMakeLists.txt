cmake_minimum_required(VERSION 3.1)
cmake_policy(VERSION 3.1)

# Enable policy to not use RPATH settings for install_name on macOS.
if(POLICY CMP0068)
  cmake_policy(SET CMP0068 NEW)
endif()

# Consider changing the project name to something relevant for you.
project(shiboken_demo)

add_subdirectory(cpp)
add_subdirectory(python)
