/* 
 * File:   ServerSocket.cpp
 * Author: danny
 * 
 * Created on January 29, 2015, 10:50 AM
 */

#include "ServerSocket.h"
#include "SocketException.h"

ServerSocket::ServerSocket(const int port)
{
      if ( ! Socket::Create() )
        {
          throw SocketException ( "Could not create server socket." );
        }

      if ( ! Socket::Bind ( port ) )
        {
          throw SocketException ( "Could not bind to port." );
        }

      if ( ! Socket::Listen() )
        {
          throw SocketException ( "Could not listen to socket." );
        }
}

ServerSocket::~ServerSocket()
{
}

void ServerSocket::Accept(Socket& socket)
{
      if ( ! Socket::Accept ( socket ) )
        {
          throw SocketException ( "Could not accept socket." );
        }
}

