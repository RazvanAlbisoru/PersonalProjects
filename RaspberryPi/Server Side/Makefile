SOURCES =  AcceptTCPConnection.c Auxiliary.c CreateTCPServerSocket.c HandleTCPChatClient.c TCPEchoServer-Fork.c Xpad.c
OBJECTS = $(SOURCES:.c=.o)

TARGET = TCPEchoServer-Fork

$(TARGET): $(OBJECTS)
	arm-linux-gcc $^ -o $@ -Wall -Wextra -lusb-1.0

%.o: %.c
	arm-linux-gcc -c $< -o $@ -Wall -Wextra -lusb-1.0

clean:
	rm *.o AcceptTCPConnection Auxiliary CreateTCPServerSocket HandleTCPChatClient TCPEchoServer-Fork Xpad

access:
	ssh 'root@10.0.0.42' 
copy:
	scp TCPEchoServer-Fork root@10.0.0.42:/bin