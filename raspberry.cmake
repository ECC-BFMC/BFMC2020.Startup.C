SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_SYSROOT "C:/SysGCC/Raspberry/arm-linux-gnueabihf/sysroot")
# specify the cross compiler

SET(CMAKE_C_COMPILER  "C:/SysGCC/Raspberry/bin/arm-linux-gnueabihf-gcc.exe")
SET(CMAKE_CXX_COMPILER "C:/SysGCC/Raspberry/bin/arm-linux-gnueabihf-g++.exe")

# where is the target environment
SET(CMAKE_FIND_ROOT_PATH  "C:/SysGCC/Raspberry/arm-linux-gnueabihf")
# search for programs in the build host directories
# SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)