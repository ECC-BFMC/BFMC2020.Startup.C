/**
 * Copyright (c) 2019, Bosch Engineering Center Cluj and BFMC organizers
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:

 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.

 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.

 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
*/

#include <example1.hpp>

/*
* This class is an example of sent messages over the serial. 
*/

CMoveExample::CMoveExample(SerialComManager& f_comManager)
                            :m_comManager(f_comManager)
{}


void CMoveExample::run(){
    
    std::array<float,9> l_pwmMotor_values=  {0.15,0.17,0.19,0.22,0.19,0.170,0.150,0.00};
    std::array<float,9> l_steerAngle_values={0.00,8.10,17.4,20.2,11.2,-11.2,-20.2,0.00};

    for (unsigned int i=0;i<l_pwmMotor_values.size();++i){
       float l_pwmMotor      = l_pwmMotor_values[i];
       float l_steeringAngle = l_steerAngle_values[i];
       m_comManager.sendSpeed(l_pwmMotor);
       usleep(0.4e6);
       m_comManager.sendSteer(l_steeringAngle);
       usleep(0.4e6);
    }
    m_comManager.sendBrake(0.0);
    usleep(0.5e6);
}
