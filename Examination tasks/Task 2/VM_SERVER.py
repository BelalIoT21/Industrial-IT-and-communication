"""
Server receiver of the file
"""
import socket
import os

# device's IP address
SERVER_HOST = "0.0.0.0"
SERVER_PORT = 5001

# receive 4096 bytes each time
BUFFER_SIZE = 4096

# create the server socket
# TCP socket
s = socket.socket()
# bind the socket to our local address
s.bind((SERVER_HOST, SERVER_PORT))
# enabling our server to accept connections
# 5 here is the number of unaccepted connections that
# the system will allow before refusing new connections
s.listen(5)
print("[*] Listening as " , SERVER_HOST, ":", SERVER_PORT)
# accept connection if there is any
client_socket, address = s.accept() 

# if below code is executed, that means the sender is connected
print("[+] {address} is connected.")

# the while loop checks if there data in received and act accordingly
while True:

# receive the file infos
# receive using client socket, not server socket
	received = client_socket.recv(BUFFER_SIZE)
	# if the received data is below 0 then set the LED color to red
	if int (received) < 0:
		LEDColor = "Red"
	# if the received data is above 0 then set the LED color to green
	if int (received) > 0:
		LEDColor = "Green"
	# if there is data in received print the degree and the LED color
	if received:
		print("The temperture is %s degrees" % received)
		print(LEDColor)

# close the client socket
client_socket.close()
# close the server socket
s.close()
