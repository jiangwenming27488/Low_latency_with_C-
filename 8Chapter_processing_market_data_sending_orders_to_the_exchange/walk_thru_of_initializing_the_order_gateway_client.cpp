/*The constructor accepts the "client_id" ID of the trading client, a pointer to a "ClientRequestsLFQueue" object ("client_requests"), a pointer to a "ClientResponseLFQueue" object ("client_responses"), and the "ip", "port", and interface information ("iface") to TCP connections
It initializes its own internal variables with these arguments and initializes the "Logger" data member ("logger_") with a filename for the order gateway logs for this client. 
It updates the "recv_callback_" member inside the "tcp_socket_" variable of the "TCPSocket" type so that callbacks dispatched on data reads will go to the "OrderGateway::recvCallback()" method. */


/*Like the design of our other components, we will add a "start()" method, which will enable the "run_" flag and create and launch a thread to execute the "run(): method. 
We will also initialize our "tcp_socket_" member variable and have it connect to the "ip_" and "port_" interface information of the order gateway server at the exchange:*/ 



/*The distructor for the "OrderGateway" class calls the "stop()" method to stop the execution of the "run()" method and waits for a little bit before returning.*/


/*The "stop()" method simply sets the "run_" flag to be "false" to stop the execution of the "run()" loop: */
