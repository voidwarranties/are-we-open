import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=2)
connected = False
while not connected:
	ser.read()
	connected = True

ser.write('s')
print ser.read(1)
