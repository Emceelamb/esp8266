# Touch sensor with KY-36

import machine

# connect Digital Out to GPIO 16

touch = machine.Pin(16, Pin.IN)

# read pin value 

touch.value()
