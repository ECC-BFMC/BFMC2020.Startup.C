//MessageHandler.cpp - Implementation file
//class implemetnation for response processining
#include <MessageHandler.hpp>


/**
 * @name    deactive
 * @brief   set the m_actice to false value
 *
 * @retval none.
 *
 * Example Usage:
 * @code
 *    deactivate()
 * @endcode
 */	
void BaseResponseHandler::deactive(){
    m_active=false;
}



ResponseHandler::ResponseHandler()
                                :m_isResponse(false)
{
    m_active=true;
}


/**
 * @name    operator()
 * @brief   copy the characters from input buffer to the class buffer
 *
 * @param [in]  buffer              pointer to the buffer
 * @param [in]  bytes_transferred   nr. byte transferred 
 *
 * @retval none.
 *
 * Example Usage:
 * @code
 *    
 * @endcode
 */	
void ResponseHandler::operator()(const char* buffer,const size_t bytes_transferred){
    for (unsigned int i=0; i < bytes_transferred ;++i){
        read_msgs_.push_back(buffer[i]);
    }
}

/**
 * @name    _run
 * @brief   while the m_actice is true, the _run executing cyclically, 
 *          read a character from the buffer and process it.
 *
 * @retval none.
 *
 * Example Usage:
 * @code
 *    boost::thread t(boost::bind(&ResponseHandler::_run, &responseHandler)
 * @endcode
 */	
void ResponseHandler::_run(){
    while(m_active){
        if(!read_msgs_.empty()){
            char l_c=read_msgs_.front();
            read_msgs_.pop_front();
            processChr(l_c);
        }
    }
}


/**
 * @name    createCallbackFncPtr
 * @brief   static function
 *          create a callback function object, through which can be called a class member function
 *
 * @retval new object
 *
 * Example Usage:
 * @code
 *     ResponseHandler::CallbackFncPtrType l_callbackFncObj=ResponseHandler::createCallbackFncPtr(&ClassName::FunctionName,&ObjectName);
 *     (*l_callbackFncObj)(response);
 * @endcode
 */	
// template<class T>
// ResponseHandler::CallbackFncPtrType ResponseHandler::createCallbackFncPtr(void (T::*f)(std::string),T* obj){
//         return  new CallbackFncType( std::bind1st(std::mem_fun(f),obj));
// }


/**
 * @name    createCallbackFncPtr 
 * @brief   static function
 *          Create a callback function object, through which can be called a function
 *
 * @retval new object
 *
 * Example Usage:
 * @code
 *     ResponseHandler::CallbackFncPtrType l_callbackFncObj=ResponseHandler::createCallbackFncPtr(&functionName);
 *     (*l_callbackFncObj)(response);
 * @endcode
 */
ResponseHandler::CallbackFncPtrType ResponseHandler::createCallbackFncPtr(void (*f)(std::string)){
    return  new CallbackFncType(f);
}


/**
 * @name    attach
 * @brief   Attach the callback function  to the response key word. This callback function will be called automatically, when will be received the key word.
 *          More functions can be attach  to the one key word. 
 *
 * @retval new object
 *
 * Example Usage:
 * @code
 *     l_responseHandler.attach(message::KEY,l_callbackFncObj)
 *     
 *     
 * @endcode
 */
void ResponseHandler::attach(message::Actions f_action,CallbackFncPtrType waiter){
    if(m_keyCallbackFncMap.count(f_action)>0){
        CallbackFncContainer* l_container=&(m_keyCallbackFncMap[f_action]);
        l_container->push_back(waiter);
    }else{
        CallbackFncContainer l_container;
        l_container.push_back(waiter);
        m_keyCallbackFncMap[f_action]=l_container;
    }
}



/**
 * @name    detach
 * @brief   After applying detach function, the callback function will not be called
 *
 * @retval new object
 *
 * Example Usage:
 * @code
 *      l_responseHandler.attach(message::KEY,l_callbackFncObj)
 * @endcode
 */
void ResponseHandler::detach(message::Actions f_action,CallbackFncPtrType waiter){
    if(m_keyCallbackFncMap.count(f_action)>0){
        CallbackFncContainer *l_container=(&m_keyCallbackFncMap[f_action]);
        CallbackFncContainer::iterator it=std::find(l_container->begin(),l_container->end(),waiter);
        if(it!=l_container->end()){  
            l_container->erase(it);
        } 
        else{
            std::cout<<"Not found!"<<std::endl;   
        }
        
    }else{
        std::cout<<"Container is empty!"<<std::endl;   
    }
}



void ResponseHandler::processChr(const char f_received_chr){
    if (f_received_chr=='@'){
        if (!m_valid_response.empty()){
            checkResponse();
            m_valid_response.clear();
        }
        m_isResponse=true;
    }
    else if(f_received_chr=='\r'){
        if (!m_valid_response.empty()){
            checkResponse();
            m_valid_response.clear();
        }
        m_isResponse=false;
    }
    if(m_isResponse){
        m_valid_response.push_back(f_received_chr);
    }                
}

void ResponseHandler::checkResponse(){
    std::string l_responseFull(m_valid_response.begin(),m_valid_response.end());
    std::string l_keyStr=l_responseFull.substr(1,4);
    std::string l_reponseStr=l_responseFull.substr(6,l_responseFull.length()-8);
    message::Actions l_key=message::text2Key(l_keyStr);
    if(m_keyCallbackFncMap.count(l_key)>0){
        CallbackFncContainer l_cointaner=m_keyCallbackFncMap[l_key];
        for(CallbackFncContainer::iterator it=l_cointaner.begin();it!=l_cointaner.end();++it){
            (**it)(l_reponseStr);
        }
    }
    else{
        std::cout<<"";
    }
}

