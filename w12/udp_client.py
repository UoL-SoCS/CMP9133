#!/usr/bin/env python

import socket
HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    s.sendto(b'Hello, world', (HOST, PORT))
    data = s.recvfrom(1024)
    print('Message from server:', repr(data))
