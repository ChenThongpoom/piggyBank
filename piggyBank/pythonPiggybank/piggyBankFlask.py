from flask import Flask, jsonify, request
import time
from searchlatest import checkFinger
from flask_cors import CORS
from enroll import register
from doorLock_serial import doorRelayCoin, doorRelayBank, stopDoorLock
from serial_read2 import *
from BankDep_Serial import servo, colorSensor

app = Flask(__name__)
CORS(app)

@app.route('/')    
def index():
    return checkFinger()

@app.route('/enroll')
def enroll_page():
    return register()

@app.route('/coinDeposit')
def coinDep():
    coinsensor()
    return "OK"

@app.route('/stopDep')
def stopSensor():
    return jsonify(interupt())
    

@app.route('/bankDeposit',methods = ['POST'])
def bankDep():
    index = request.form["amount"]
    #print(index)
    
    return servo(index)

@app.route('/coinWithdraw')
def coinWith():
    doorRelayCoin()
    return "success"

@app.route('/banknotesWithdraw')
def bankWith():
    doorRelayBank()
    return "success"

@app.route('/stopWithdraw')
def stopWith():
    stopDoorLock()
    return "success"


        
        

if __name__=='__main__':
    app.run(debug=True, port=80, host='0.0.0.0')
    
