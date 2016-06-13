# C-Functions
How to use socket.h     reference: http://www.cnblogs.com/-Lei/archive/2012/09/04/2670942.html

server:
//============================================================================

//============================================================================

#include <iostream>
#include <string>
#include "ServerSocket.h"
#include "SocketException.h"
using namespace std;

int main()
{
    cout<<"Running server..."<<endl;
    try
    {
        ServerSocket server(8080);

        while(true)
        {
            Socket newSocket;
            server.Accept(newSocket);

            try
            {
                string message;
                server.Receive(newSocket,message);
                cout<<"Receive message: "<<message<<endl;
                message="Here is server";
                server.Send(newSocket,message);
            }
            catch(SocketException&){}
        }
    }
    catch(SocketException& ex)
    {
         cout << "Exception was caught:" << ex.Description() << "\nExiting.\n";
    }
    return 0;
}

client:
//============================================================================

//============================================================================

#include <iostream>
#include <string>
#include "ClientSocket.h"
#include "SocketException.h"
using namespace std;

int main()
{
    cout<<"Running client...."<<endl;
    try
    {
        ClientSocket clientSocket("127.0.0.1",8080);
        clientSocket.Send("Hello,here is client");
        string message;
        clientSocket.Receive(message);
        cout<<"Response from server: "<<message<<endl;
    }
    catch(SocketException& ex)
    {
        cout << "Exception was caught:" << ex.Description() << "\n";
    }
    return 0;
}
