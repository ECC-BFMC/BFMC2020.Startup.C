#ifndef EXAMPLE2_HPP
#define EXAMPLE2_HPP

#include <string>
#include <boost/tokenizer.hpp>
#include <iostream>
#include <array>

class CSensorEchoer{
    public:
        void callback(std::string);
        static std::array<float,5> message2Values(std::string);
    private:
};

#endif