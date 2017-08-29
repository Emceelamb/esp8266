import time
import machine

servo = machine.PWM(machine.Pin(2), freq = 50)

x = True

while True:
    if x:
        servo.duty(1)
        x = False
    else:
        servo.duty(179)
        x = True
    time.sleep(0.1)