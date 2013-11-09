import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=2)
connected = False
while not connected:
	ser.read()
	connected = True

ser.write('t')
print ser.read(100)
time.sleep(2)
ser.write('h')
print ser.read(100)
