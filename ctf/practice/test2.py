from websocket import create_connection
import json

sock = create_connection("ws://45.90.34.131:5003")

y = 1

for x in range(10000):
	sock.send(str(x))