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


def coinsensor():
    ser.write('1'.encode())
    time.sleep(0.05)
    
def interupt():
    i = 0
    l = []
    d = {}
    ser.write('2'.encode())
    time.sleep(1)
    #print(ser.read(ser.inWaiting()))
    
    return ser.read(ser.inWaiting())
#coinsensor()
#time.sleep(15)
print(interupt())
