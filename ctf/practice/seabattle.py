from websocket import create_connection
import json, math

def get_intersections(x0, y0, r0, x1, y1, r1):
    # circle 1: (x0, y0), radius r0
    # circle 2: (x1, y1), radius r1

    d=math.sqrt((x1-x0)**2 + (y1-y0)**2)
    
    # non intersecting
    if d > r0 + r1 :
        return None
    # One circle within other
    if d < abs(r0-r1):
        return None
    # coincident circles
    if d == 0 and r0 == r1:
        return None
    else:
        a=(r0**2-r1**2+d**2)/(2*d)
        h=math.sqrt(r0**2-a**2)
        x2=x0+a*(x1-x0)/d   
        y2=y0+a*(y1-y0)/d   
        x3=x2+h*(y1-y0)/d     
        y3=y2-h*(x1-x0)/d 

        x4=x2-h*(y1-y0)/d
        y4=y2+h*(x1-x0)/d
        
        return (x3, y3, x4, y4)

sock = create_connection("ws://45.90.34.131:5002")

data = {
	'x': '0',
	'y': '0'
}

sock.send(json.dumps(data))
z = json.loads(sock.recv())

data['x'] = 1000
data['y'] = 1000

sock.send(json.dumps(data))
t = json.loads(sock.recv())

print(z, t)

ans = get_intersections(0, 0, z['distance'], 1000, 1000, t['distance'])

data['x'] = ans[0]
data['y'] = ans[1]

sock.send(json.dumps(data))
print(sock.recv())

data['x'] = ans[2]
data['y'] = ans[3]

sock.send(json.dumps(data))
print(sock.recv())