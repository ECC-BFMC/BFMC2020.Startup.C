#include <example1.hpp>

CMoveExample::CMoveExample(SerialComManager& f_comManager)
                            :m_comManager(f_comManager)
{}


void CMoveExample::run(){
    
    std::array<float,9> l_pwmMotor_values={7.0,8.0,9.0,10.0,11.0,10.0,9.0,8.0,7.0};
    float l_steeringAngle=0.0;

    for (unsigned int i=0;i<l_pwmMotor_values.size();++i){
       float l_pwmMotor= l_pwmMotor_values[i];
       m_comManager.sendMove(l_pwmMotor,l_steeringAngle);
       usleep(0.4e6);
    }
    m_comManager.sendBrake(l_steeringAngle);
    usleep(0.5e6);
}
