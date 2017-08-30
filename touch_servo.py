import machine
import time

touch = machine.Pin(16, Pin.IN)
servo = machine.PWM(machine.Pin(2), freq = 50)

x = True

while True:
    
    if touch.value() == 1:
        print("hnnngh")
        if x:
            servo.duty(1)
            x = False
        else:
            servo.duty(179)
            x = True
        time.sleep(0.1)
    else:
        print("touch me")
