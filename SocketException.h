/* 
 * File:   SocketException.h
 * Author: danny
 *
 * Created on January 29, 2015, 10:49 AM
 */

#ifndef SocketException_H
#define SocketException_H

#include <string>

class SocketException
{
    public:
        SocketException ( std::string description ) : m_description( description ) {};
        ~SocketException (){};

        std::string Description() { return m_description; }

 private:
        std::string m_description;
};


#endif


