CC=gcc
CFLAGS = -Wall -Wextra -pthread
DEPS = CreateTCPClientSocket.h CreateTCPServerSocket.h HandleTCPClient.h

all:TCPChatClient

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TCPEchoClient: TCPEchoClient.o Auxiliary.o CreateTCPClientSocket.o
	$(CC) -o $@ $^ $(CFLAGS)

TCPEchoServer:TCPEchoServer.o Auxiliary.o CreateTCPServerSocket.o AcceptTCPConnection.o HandleTCPClient.o
	$(CC) -o $@ $^ $(CFLAGS)

TCPChatServer:TCPChatServer.o Auxiliary.o CreateTCPServerSocket.o AcceptTCPConnection.o HandleTCPChatClient.o
	$(CC) -o $@ $^ $(CFLAGS)

TCPChatClient: TCPChatClient.o Auxiliary.o CreateTCPClientSocket.o
	$(CC) -o $@ $^ $(CFLAGS)