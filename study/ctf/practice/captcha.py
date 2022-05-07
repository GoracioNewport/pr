from websocket import create_connection
import json

sock = create_connection("ws://45.90.34.131:5004")

sock.send("aaa")
a = (sock.recv())
sock.send(a)
print(sock.recv())