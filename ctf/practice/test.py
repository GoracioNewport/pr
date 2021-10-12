from websocket import create_connection
import json

sock = create_connection("w")
s://45.90.34.131:5002
y = 1

for x in range(100):
	fire = {
		'x': str(x),
		'y': str(y)
	} 
	sock.send(json.dumps(fire))
	print(web.recv())