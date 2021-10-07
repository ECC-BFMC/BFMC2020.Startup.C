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

#include <serialPortHandler.hpp>
#include <SerialComManager.hpp>
#include <ResponseHandler.hpp>
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

		// Create a callback object for response handling, which in this case only prints the returned message.
		ResponseHandler::CallbackFncPtrType l_callbackFncObj=ResponseHandler::createCallbackFncPtr(&print);

		// Attach the callback function to the following messages.
		l_responseHandler.attach(message::STER,l_callbackFncObj);
		l_responseHandler.attach(message::SPED,l_callbackFncObj);
		l_responseHandler.attach(message::BRAK,l_callbackFncObj);
		l_responseHandler.attach(message::PIDA,l_callbackFncObj);

		// Create a move object and run it
		CMoveExample		l_moveObj(l_communicationManager);
		l_moveObj.run();

		l_responseHandler.detach(message::STER,l_callbackFncObj);
		l_responseHandler.detach(message::SPED,l_callbackFncObj);
		l_responseHandler.detach(message::BRAK,l_callbackFncObj);
		l_responseHandler.detach(message::PIDA,l_callbackFncObj);

		delete l_callbackFncObj;
		// Close all threads
		l_communicationManager.closeAll();
	}
	catch (exception& e)
	{
		cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
