#Class to handle TCP control connection
#Faheem Moolla (1234085)

import socket

BUFFER_SIZE = 8192
BUFFER = ''
ENCODING_SCHEME = 'UTF-8'

class TCP:
    #Initialization
    def __init__(self, serverSocket, clientSocket, clientAdd):

        self._serverSocket = serverSocket
        self._clientAddress = clientAdd
        self._clientSocket = clientSocket


    #Encode the data and transmit it to the client.
    def transmit(self, s: object) -> object:
        self._clientSocket.send(s.encode(ENCODING_SCHEME))


    #Transmits all data to client
    def transmitAll(self, s):
        self._clientSocket.sendall(s.encode(ENCODING_SCHEME))


    #Closes socket
    def __exit__(self):
        self.transmit('Closing socket' + '\r\n')
        self._clientSocket.close()


    #Recieves the data and decodes it
    def receive(self, size=BUFFER_SIZE, codec=ENCODING_SCHEME):
        clientResponse = self._clientSocket.recv(size).decode(codec)
        return clientResponse


    #Accepts the connection from the client.
    def acceptConnection(self):
        self._clientSocket, self._clientAddress =  self._serverSocket.accept()


    #Closes socket
    def close(self):
        self._clientSocket.close()


    #Return function
    def getSocket(self):
        return self._clientSocket


    #Return function
    def getAdress(self):
        return self._clientAddress
