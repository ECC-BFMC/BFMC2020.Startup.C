//SerialComManager.hpp - Header file
//class implementation for serial communication handling
#include <SerialComManager.hpp>


SerialComManager::SerialComManager(BaseResponseHandler& f_responseHandler)
                                :SerialComManager(230400,"/dev/ttyACM0",f_responseHandler)
{
}

SerialComManager::SerialComManager( unsigned int                f_baudrate
                                    ,const std::string          f_dev
                                    ,BaseResponseHandler&        f_responseHandler)
                                    :m_responseHandler(f_responseHandler)
                                    ,m_io_service()
                                    ,m_io_serviceThread(NULL)
                                    ,m_responseHandlerThread(NULL)
	                                ,m_serialPort(m_io_service,f_baudrate,f_dev,m_responseHandler)
{
    m_io_serviceThread=new boost::thread(boost::bind(&boost::asio::io_service::run, &m_io_service));
    m_responseHandlerThread=new boost::thread(boost::bind(&BaseResponseHandler::_run, &m_responseHandler));
}

SerialComManager::~SerialComManager()
{
    delete m_io_serviceThread;
}

void SerialComManager::closeAll(){
    m_serialPort.close();
    m_responseHandler.deactive();
    m_responseHandlerThread->join();
    m_io_serviceThread->join();
}

// COMMENTARIILE


void SerialComManager::sendMove(float f_vel,float f_angle){
    std::string l_msg=message::moving(f_vel,f_angle);
    m_serialPort.write(l_msg);
}

void SerialComManager::sendBrake(float f_angle){
    std::string l_msg=message::brake(f_angle);
    m_serialPort.write(l_msg);
}
void SerialComManager::sendSpline(std::complex<double> f_A,std::complex<double> f_B,std::complex<double> f_C,std::complex<double> f_D,float f_duration,bool f_isForward){
    std::string l_msg=message::spline(f_A,f_B,f_C,f_D,f_duration,f_isForward);
    m_serialPort.write(l_msg);
}
void SerialComManager::sendSpline(float A[2],float B[2],float C[2],float D[2],float f_duration,bool f_isForward){
    std::string l_msg=message::spline(A,B,C,D,f_duration,f_isForward);
    m_serialPort.write(l_msg);
}
void SerialComManager::sendPidParam(float f_kp,float f_ki,float f_kd,float f_tf){
    std::string l_msg=message::pids(f_kp,f_ki,f_kd,f_tf);
    m_serialPort.write(l_msg);
}
void SerialComManager::sendPidState(bool f_activate){
    std::string l_msg=message::pida(f_activate);
    m_serialPort.write(l_msg);
}
void SerialComManager::sendSafetyStopState(bool f_activate){
    std::string l_msg=message::sfbr(f_activate);
    m_serialPort.write(l_msg);
}

void SerialComManager::sendDistanceSensorPublisherState(bool f_activate){
    std::string l_msg=message::dspb(f_activate);
    m_serialPort.write(l_msg);
}