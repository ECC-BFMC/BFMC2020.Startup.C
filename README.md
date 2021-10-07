# BFMC Startup C

This repository contains a small example application written in C/C++ to communication and control the robot movements. It runs on Raspberry Pi.

## Requirements
You need to install **cmake** and **boost** library for compilation.

## Compilation
You need to type the following lines:
    
    mkdir build
    cd build
    cmake ..
    make

If the compilation terminates correctly, in the folder `build` appears a `app1` named application. 
You can run it. It's a simple example, which moves the robot forward. 