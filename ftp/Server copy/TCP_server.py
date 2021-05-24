#Class to handle TCP server connection
#Faheem Moolla (1234085)

import socket

BUFFER_SIZE = 8192
BUFFER = ''
ENCODING_SCHEME = 'UTF-8'

class TCP:
    #Initialization
    def __init__(self, serverAddress, serverPort):
        self._serverAdress = serverAddress
        self._serverPort = serverPort
        self._serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._clientSocket =None
        self._clientAddress = None


    def __exit__(self):
        self._serverSocket.close()


    #Listens for data connections
    def listen(self,amount):
        self._serverSocket.listen(amount)


    #Encodes data and transmit
    def transmitAll(self, s):
        self._serverSocket.sendall(s.encode(ENCODING_SCHEME))


    #Accepts a connection
    def acceptConnection(self):
        self._clientSocket, self._clientAddress =  self._serverSocket.accept()


    #Return function
    def getServerSocket(self):
        return self._serverSocket


    #Return function
    def getServerAdress(self):
        return self._serverAdress


    #Return function
    def getClientSocket(self):
        return self._clientSocket


    #Return function
    def getClientAdress(self):
        return self._clientAddress


    #Binds the socket
    def bindSocket(self, address, port):
        self._serverSocket.bind(("", port))


    #Closes socket
    def close(self):
        self._serverSocket.close()
