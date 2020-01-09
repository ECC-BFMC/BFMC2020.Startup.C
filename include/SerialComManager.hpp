//SerialComManager.hpp - Header file
//class declaration for serial communication handling

#ifndef SERIAL_COM_MANAGER_HPP
#define SERIAL_COM_MANAGER_HPP

#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <serialPortHandler.hpp>
#include <MessageHandler.hpp>
#include <Message.hpp>

class SerialComManager{
    public:
        SerialComManager(unsigned int, const std::string,BaseResponseHandler&);
        SerialComManager(BaseResponseHandler&);
        virtual ~SerialComManager();
        // void start();
        void closeAll();

        void sendMove(float,float);
        void sendBrake(float);
        void sendSpline(std::complex<double>,std::complex<double>,std::complex<double>,std::complex<double>,float,bool);
        void sendSpline(float A[2],float B[2],float C[2],float D[2],float,bool);
        void sendPidParam(float,float,float,float);
        void sendPidState(bool);
        void sendSafetyStopState(bool);
        void sendDistanceSensorPublisherState(bool);
        
    private:
        BaseResponseHandler&             m_responseHandler;
        boost::asio::io_service 		 m_io_service;
        boost::thread*                   m_io_serviceThread;
        boost::thread*                   m_responseHandlerThread;
        serialPortHandler 				m_serialPort;
};

#endif