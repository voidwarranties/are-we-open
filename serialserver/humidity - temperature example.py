import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=2)
connected = False
while not connected:
	ser.read()
	connected = True

ser.write('1')
temphumidity = ser.read(100)
temp = temphumidity.split("-")[0]
humidity = temphumidity.split("-")[1]
print "temperature: " + temp
print "humidity: " + humidity
