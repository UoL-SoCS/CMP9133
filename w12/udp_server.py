#!/usr/bin/env python

import socket
HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    s.bind((HOST, PORT))
    while True:
        data, address = s.recvfrom(1024)
        if not data:
            break
        print('Message from client:', repr(data))
        s.sendto(data, address)
