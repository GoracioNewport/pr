import serial
import ast

prefix = "[ARDUINO]"

def init():
	global arduino
	arduino = serial.Serial("/dev/ttyACM0", 9600, timeout=3)


def read():

	global arduino
	data = arduino.readline()

	decodedData = dict()

	try:

		decodedData = ast.literal_eval(str(data[0:len(data)].decode("utf-8")))

		for key, val in decodedData.items():
			if (val[-3:] == '.00'): 
				decodedData[key] = int(val[:-3])


		decodedData['ok'] = True

	except:
		decodedData['ok'] = False

	print(prefix, decodedData)
	return decodedData


def close():
	arduino.close()

