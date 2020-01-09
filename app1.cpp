#include <serialPortHandler.hpp>
#include <SerialComManager.hpp>
#include <MessageHandler.hpp>
#include <Message.hpp>
#include <boost/function.hpp>
#include<example1.hpp>



int main(int argc, char* argv[])
{
	try
	{
		// Create a resnponse handler object
		ResponseHandler  	l_responseHandler;
		// Create a communication manager object
		SerialComManager 	l_communicationManager(l_responseHandler);
		// Create a move object
		CMoveExample		l_moveObj(l_communicationManager);
		// Run the move object 
		l_moveObj.run();
		// Close all ports and threads
		l_communicationManager.closeAll();
	}
	catch (exception& e)
	{
		cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
