# BFMC Startup C

This repository contains a small example application written in C/C++ to communication and control the robot movements. It runs on Raspberry Pi 4b.

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


**Note**: The baud rate of serial communication is changed from `256000` to `230400`. 
You need to set the same value on the micro-controller side (BFMC2020.Embedded.Platform). 
