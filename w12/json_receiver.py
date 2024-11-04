#!/usr/bin/env python

import socket
import json

HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        while True:
            data = conn.recv(1024)
            if not data:
                break
            # my_dict = json.loads(data)
            my_dict = data
            print("I've received the following: ", my_dict)
