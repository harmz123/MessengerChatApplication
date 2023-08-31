#Makefile

all: prog1 prog2

prog1:
	g++ -o chat_client chat_client.cpp -pthread

prog2:
	g++ -o chat_server chat_server.cpp -pthread

clean:
	rm -f chat_client chat_server *.o

