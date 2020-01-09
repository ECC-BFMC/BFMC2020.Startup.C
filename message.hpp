
/**
 * message.hpp - Header file
 * message converter functions declarations
 */

#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_

#include <string>
#include <sstream>
#include <complex>

namespace message{

    //enum for defining the actions that can be performed  
    enum Actions{MCTL, BRAKE, SPLN, PIDS, PIDA, SFBR};
    //the strings associated to each action
    static std::string ActionStrings[] = { "MCTL", "BRAK", "SPLN" , "PIDS" , "PIDA" , "SFBR" };

    std::string getTextForKey(int);
    std::string moving(float,float);
    std::string brake(float);
    std::string spline(std::complex<double>,std::complex<double>,std::complex<double>,std::complex<double>,float,bool);
    std::string spline(float A[2],float B[2],float C[2],float D[2],float,bool);
    std::string pids(float,float,float,float);
    std::string pida(bool);
    std::string sfbr(bool);
};

#endif