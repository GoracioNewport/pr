from websocket import create_connection
import json

t = {
 	'name':"123",
  'age':33,
  'ts':'0',
  'kids':'1.4',
  'kidsage':'',
  'pet':0,
  'salary':6400,
  'mark':11
}

sock = create_connection("ws://45.90.34.131:5005")


for i in range(-100000000000000, 100):
	print(i)
	sock.send(json.dumps(t))
	f = json.loads(sock.recv())

	if (f['state'][0] != 'т'): print(f)
