#include <serialPortHandler.hpp>
#include <SerialComManager.hpp>
#include <MessageHandler.hpp>
#include <Message.hpp>
#include <boost/function.hpp>
#include<example1.hpp>



void print(std::string str){
	std::cout<<str<<std::endl;
}

int main(int argc, char* argv[])
{
	try
	{
		// Create a resnponse handler object
		ResponseHandler  	l_responseHandler;
		// Create a communication manager object
		SerialComManager 	l_communicationManager(l_responseHandler);


		// Create a callback object for response handling
		ResponseHandler::CallbackFncPtrType l_callbackFncObj=ResponseHandler::createCallbackFncPtr(&print);
		// Attach object to Move and Brake response
		l_responseHandler.attach(message::MCTL,l_callbackFncObj);
		l_responseHandler.attach(message::BRAK,l_callbackFncObj);
		// Create a move object
		CMoveExample		l_moveObj(l_communicationManager);
		// Run the move object 
		l_moveObj.run();

		l_responseHandler.detach(message::MCTL,l_callbackFncObj);
		l_responseHandler.detach(message::BRAK,l_callbackFncObj);
		// Close all ports and threads
		l_communicationManager.closeAll();
	}
	catch (exception& e)
	{
		cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
