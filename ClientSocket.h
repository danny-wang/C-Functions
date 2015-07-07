/* 
 * File:   ClientSocket.h
 * Author: danny
 *
 * Created on January 29, 2015, 10:53 AM
 */

#ifndef CLIENTSOCKET_H
#define	CLIENTSOCKET_H

#include "Socket.h"
#include <string>

class ClientSocket:public Socket
{
    public:
      ClientSocket (const std::string& host,const int port );
      virtual ~ClientSocket();

      bool Send(const std::string& message) ;
      int Receive(std::string& message) ;
};

#endif	/* CLIENTSOCKET_H */


