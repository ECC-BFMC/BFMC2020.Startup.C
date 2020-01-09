#ifndef EXAMPLE1_HPP
#define EXAMPLE1_HPP

#include <SerialComManager.hpp>
#include <array>

class CMoveExample{
    public:
        CMoveExample(SerialComManager&);
        void run();
    private:
        SerialComManager&       m_comManager;

};

#endif