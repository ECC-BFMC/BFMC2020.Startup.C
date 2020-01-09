/**
 * message.cpp - Implementation file
 * message converter functions definitions
 */

#include <stdio.h>
#include <Message.hpp>

/**
 * @name    getTextForKey
 * @brief   
 *
 * Provide the cmd key associated to an action.
 *
 * @param [in] enumVal     The integer value corresponding to the action, in the action enumeration
 *                         (zero-indexed).
 *
 * @retval String associated to the action.
 *
 * Example Usage:
 * @code
 *    getTextForKey(1);
 * @endcode
 */
std::string message::getTextForKey(int enumVal){
    return ActionStrings[enumVal];
}

/**
 * @name    moving
 * @brief   
 *
 * Construct the string to be sent, associated to an action.
 *
 * @param [in] f_velocity  Velocity.
 * @param [in] f_angle     Angle.
 *
 * @retval Complete string for send command.
 *
 * Example Usage:
 * @code
 *    moving(1.234,5.678);
 * @endcode
 */
std::string message::moving(float f_velocity,float f_angle){
    std::stringstream strs;
    char buff[100];
    snprintf(buff, sizeof(buff),"%.2f;%.2f;;\r\n",f_velocity,f_angle);
    strs<<"#"<<getTextForKey(0)<<":"<<buff;
    return strs.str();
}

/**
 * @name    brake
 * @brief   
 *
 * Provide the cmd key associated to an action.
 *
 * @param [in] f_angle     Angle.
 *
 * Construct the string to be sent, associated to an action.
 *
 * Example Usage:
 * @code
 *    brake(1.234);
 * @endcode
 */
std::string message::brake(float f_angle){
    std::stringstream strs;
    char buff[100];
    snprintf(buff, sizeof(buff),"%.2f;;\r\n",f_angle);
    strs<<"#"<<getTextForKey(1)<<":"<<buff;
    return strs.str();
}

/**
 * @name    spline
 * @brief   
 *
 * Construct the string to be sent, associated to the spline,
 *           complex numbers as params.
 *
 * @param [in] A           A - complex number.
 * @param [in] B           B - complex number.
 * @param [in] C           C - complex number.
 * @param [in] D           D - complex number.
 * @param [in] dur_sec     dur_sec.
 * @param [in] isForward   isForward.
 *
 * @retval Complete string for send command.
 *
 * Example Usage:
 * @code
 *    spline(vala,valb,valc,vald,123.456,true);
 * @endcode
 */
std::string message::spline(
                std::complex<double> A,
                std::complex<double> B,
                std::complex<double> C,
                std::complex<double> D,
                float dur_sec,
                bool isForward){
    std::stringstream strs;
    char buff[100];
    snprintf(
        buff, 
        sizeof(buff),
        "%d;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;;\r\n",
        isForward,
        A.real(),
        A.imag(),
        B.real(),
        B.imag(),
        C.real(),
        C.imag(),
        D.real(),
        D.imag(),
        dur_sec);
    strs<<"#"<<getTextForKey(2)<<":"<<buff;
    return strs.str();
}

/**
 * @name    spline
 * @brief   
 *
 * Construct the string to be sent, associated to the spline,
 *           complex numbers as params.
 *
 * @param [in] A           A - 2 element array.
 * @param [in] B           B - 2 element array.
 * @param [in] C           C - 2 element array.
 * @param [in] D           D - 2 element array.
 * @param [in] dur_sec     dur_sec.
 * @param [in] isForward   isForward.
 *
 * @retval Complete string for send command.
 *
 * Example Usage:
 * @code
 *    spline(arraya,arrayb,arrayc,arrayd,789.12,false);
 * @endcode
 */
std::string message::spline(
                float A[2],
                float B[2],
                float C[2],
                float D[2],
                float dur_sec,
                bool isForward){
    std::stringstream strs;
    char buff[100];
    snprintf(
        buff, 
        sizeof(buff),
        "%d;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;;\r\n",
        isForward,
        A[0],
        A[1],
        B[0],
        B[1],
        C[0],
        C[1],
        D[0],
        D[1],
        dur_sec);
    strs<<"#"<<getTextForKey(2)<<":"<<buff;
    return strs.str();   
}

/**
 * @name    pids
 * @brief   
 *
 * Construct the string to be sent, associated to pid settig.
 *
 * @param [in] kp          Param kp.
 * @param [in] ki          Param ki.
 * @param [in] kd          Param kd.
 * @param [in] tf          Param tf.
 *
 * @retval Complete string for send command.
 *
 * Example Usage:
 * @code
 *    pids(1.234567,7.654321,12.12121212,3.4567890);
 * @endcode
 */
std::string message::pids(float kp,float ki,float kd,float tf){
    std::stringstream strs;
    char buff[100];
    snprintf(buff, sizeof(buff),"%.5f;%.5f;%.5f;%.5f;;\r\n",kp,ki,kd,tf);
    strs<<"#"<<getTextForKey(3)<<":"<<buff;
    return strs.str();
}

/**
 * @name    pida
 * @brief   
 *
 * Construct the string to be sent, associated to pid activating.
 *
 * @param [in] activate     Set PID active or not.
 *
 * @retval Complete string for send command.
 *
 * Example Usage:
 * @code
 *    pida(true);
 * @endcode
 */
std::string message::pida(bool activate){
    std::stringstream strs;
    char buff[100];
    snprintf(buff, sizeof(buff),"%d;;\r\n",activate);
    strs<<"#"<<getTextForKey(4)<<":"<<buff;
    return strs.str();
}

/**
 * @name    sfbr
 * @brief   
 *
 * Construct the string to be sent, associated to SFBR activating.
 *
 * @param [in] activate     Set SFBR active or not.
 *
 * @retval Complete string for send command.
 *
 * Example Usage:
 * @code
 *    sfbr(true);
 * @endcode
 */
std::string message::sfbr(bool activate){
    std::stringstream strs;
    char buff[100];
    snprintf(buff, sizeof(buff),"%d;;\r\n",activate);
    strs<<"#"<<getTextForKey(5)<<":"<<buff;
    return strs.str();
}

/**
 * @name    dspb
 * @brief   
 *
 * Construct the string to be sent, associated to  activate the  distance sensors publicating.
 *
 * @param [in] activate     Set Distance Sensor Pub. active or not.
 *
 * @retval Complete string for send command.
 *
 * Example Usage:
 * @code
 *    dspb(true);
 * @endcode
 */
std::string message::dspb(bool activate){
    std::stringstream strs;
    char buff[100];
    snprintf(buff, sizeof(buff),"%d;;\r\n",activate);
    strs<<"#"<<getTextForKey(DSPB)<<":"<<buff;
    return strs.str();
}



message::Actions message::text2Key(const std::string f_keyStr){
    unsigned int length=static_cast<unsigned int>(sizeof(ActionStrings)/sizeof(ActionStrings[0]));
    for (unsigned int i=0; i<length ;++i){
        if(f_keyStr.compare(ActionStrings[i])==0){
            return static_cast<message::Actions>(i);
        }
    }
    return NONV;
}