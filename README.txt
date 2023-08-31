
TO RUN:
./chat_server server_configuration_file
./chat_client client_configuration_file


INSTRUCTIONS:

Edit the client configuration file to have the correct ip address of the host
start the server.
start the clients on the same host with the server (e.g. linprog8)
In the case where server and clients are started on linprog8 server, the client configuration
file contains the ip address: 128.186.120.192.



USE OF COMMANDS:

login <username>
logout
exit
chat <@user>[optional] <message>


Using Pthread()
The use of Pthread allows for the creation of several threads to serve various customers.
The server will accept a connection request from a client and start a new thread to process the data that has been sent to it.



Use of Select()
By detecting the sockets' state and reading and listening to them, the select() function was put into use for socket monitoring.
To determine whether to accept a connection, for instance, I utilized it in my software.
	

