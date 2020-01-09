#include <example2.hpp>



std::array<float,5> CSensorEchoer::message2Values(std::string f_response){
    std::array<float,5> l_sensors;
    boost::char_separator<char> sep(";");
    boost::tokenizer<boost::char_separator<char>> tokens(f_response,sep);
    unsigned int i=0;
    for(std::string words:tokens){
        if(i>5) break;
        try{
            l_sensors[i]=std::stof(words);
        }catch(std::exception& e){
            l_sensors[i]=NAN;
        }
        ++i;
    }
    return l_sensors;
}


void CSensorEchoer::callback(std::string f_response){
     std::array<float,5> l_sensors;
     l_sensors=CSensorEchoer::message2Values(f_response);
     std::cout<<"----------------Distance Sensors-------------"<<std::endl;
     for (unsigned int i=0;i<l_sensors.size() ;++i){
         std::cout<<"Distance sensor nr."<<i<<":"<<l_sensors[i]<<std::endl;
     }
     std::cout<<"---------------------------------------------"<<std::endl;
}