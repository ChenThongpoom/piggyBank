#!/usr/bin/env python   
  
import time
import serial
           
ser = serial.Serial(            
 port='/dev/ttyACM0',
 baudrate = 9600,
 parity=serial.PARITY_NONE,
 stopbits=serial.STOPBITS_ONE,
 bytesize=serial.EIGHTBITS,
 timeout=1
)

def servo(x):
    ser.write(str(x).encode())
    
    return colorSensor(x)

def servo90(): #100
    ser.write('9'.encode())
    print(ser.read(ser.inWaiting()))

def servo20(): #20
    ser.write('2'.encode())
    print(ser.read(ser.inWaiting()))
    
def servo50(): #50
    ser.write('5'.encode())

def servo120(): #500
    ser.write('7'.encode())
    time.sleep(3)
    print(ser.read(ser.inWaiting()))

def servo150(): #1000
    ser.write('8'.encode())


def colorSensor(x):
    
    ser.write(str(x).encode())
    time.sleep(1)
    return ser.read(ser.inWaiting())
#while True:
#servo150()
#time.sleep(1)
##while True:
##    print(colorSensor(6))

##    servo90()
##servo50()
##time.sleep(3)
##
##servo120()
##time.sleep(3)
##
##servo150()
##time.sleep(3)
##
##servo90()
##time.sleep(3)
