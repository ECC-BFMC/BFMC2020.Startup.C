# BFMC - Startup C Project

The project contains the firmware for communicating with the Nucleo and control the robot movements (Speed with constant current consumption, speed with constant speed and steering);

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