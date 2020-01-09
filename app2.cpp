#include <serialPortHandler.hpp>
#include <SerialComManager.hpp>
#include <MessageHandler.hpp>
#include <Message.hpp>
#include <boost/function.hpp>

#include<example2.hpp>


int main(int argc, char* argv[])
{
	try
	{
        // Create a resnponse handler object
		ResponseHandler  	l_responseHandler;
        // Create a communication manager object
		SerialComManager 	l_communicationManager(l_responseHandler);
        // Create a echoer object, which prints the received sensor data on the console 
        CSensorEchoer       l_echoer;
        // Create a callback function object, through which you can reach the function
        ResponseHandler::CallbackFncPtrType l_callbackFncObj=ResponseHandler::createCallbackFncPtr(&CSensorEchoer::callback,&l_echoer);
        // Attach the callback function to the message key. If the response was received with this special key word, the response handler object will call automatically the callback function.  
        l_responseHandler.attach(message::DSPB,l_callbackFncObj);
		usleep(5.e6);
        // After applying detach function, the callback function will not be called.
        l_responseHandler.detach(message::DSPB,l_callbackFncObj);
        usleep(5.e6);
        // Close all ports and threads
		l_communicationManager.closeAll();
	}
	catch (exception& e)
	{
		cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
