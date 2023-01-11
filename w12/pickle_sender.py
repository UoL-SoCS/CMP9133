#!/usr/bin/env python

import socket
import pickle

HOST = '127.0.0.1'
PORT = 65432

my_dict = {"name": "Alice", "age": "27"}
data = pickle.dumps(my_dict)
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(data)
