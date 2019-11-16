#!/usr/bin/env python   
  
import time
import serial
           
ser = serial.Serial(            
 port='/dev/ttyACM1',
 baudrate = 9600,
 parity=serial.PARITY_NONE,
 stopbits=serial.STOPBITS_ONE,
 bytesize=serial.EIGHTBITS,
 timeout=1
)


def doorRelayCoin():

    ser.write('3'.encode())
    
    

def doorRelayBank():

    ser.write('4'.encode())
    

def stopDoorLock():

    ser.write('5'.encode())
    


##    ser.close()




        
