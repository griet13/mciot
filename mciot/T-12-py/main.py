#Import all libraries/modules
import library_ultrasensor
import Oled_library
from machine import Pin,SoftI2C,PWM
from utime import sleep


#Pin declaration
yellow_alarm= Pin(5,Pin.OUT)
green_alarm = Pin(2,Pin.OUT)
TRIG = Pin(14,Pin.IN)
ECHO = Pin(25,Pin.OUT)
Buzzer_Pin = Pin(15,Pin.OUT)
pir = Pin(13,Pin.OUT)

pin_oled = SoftI2C(scl=Pin(22), sda=Pin(21))

#Lets create a name for our OLED Screen:
#Name = licraries name . class name
skrin = Oled_library.SSD1306_I2C(width=128, height=64, i2c=pin_oled)


#Declare/Create object name for sensors with libraries
#object_name =LIBRARY_NAME,CLASS_NAME(......)

Ssonic = library_ultrasensor.HCSR04(trigger_pin=TRIG, echo_pin=ECHO) 


#Main program
while True:
  #ULTRASONIC PART
  jarak_dalam_cm = Ssonic.distance_cm()
  print('An object is Detected within :',jarak_dalam_cm,'cm')

  #DOOR SENSOR
  if jarak_dalam_cm > 200:
      print("Someone is coming, in range 200")
      for a in range (3):
        tone_buzzer = PWM(Buzzer_Pin,freq = 500, duty = 400)
        sleep(0.5)
        tone_buzzer =PWM(Buzzer_Pin,freq = 1,duty = 0)
        sleep(0.5)
        skrin.fill(1)
        skrin.text("Someone is coming:/",10,20,0)
        skrin.text("in range 200",15,40,0)
        skrin.show()  
        yellow_alarm.on()
        sleep(0.5) 
        yellow_alarm.off()
        sleep(0.5) 

  elif 50 <= jarak_dalam_cm < 200:
      print("Someone is coming.in below range 200!!!")
      for a in range (3):
        tone_buzzer = PWM(Buzzer_Pin,freq = 1000, duty = 400)
        sleep(0.1)
        tone_buzzer =PWM(Buzzer_Pin,freq = 1,duty = 0)
        sleep(0.1)
        skrin.fill(1)
        skrin.text("Someone is coming:/",10,20,0)
        skrin.text("below range 200",10,40,0)
        skrin.show()  
        yellow_alarm.on()
        sleep(0.1)
        yellow_alarm.off()
        sleep(0.1)

  else :
        print("\n\t_________________\n")
        tone_buzzer = PWM(Buzzer_Pin,freq = 1400, duty = 400)
        sleep(0.01)
        tone_buzzer =PWM(Buzzer_Pin,freq = 1,duty = 0)
        sleep(0.01)
        yellow_alarm.on()
        sleep(0.01)
        yellow_alarm.off()
        sleep(0.01)
      

  motion = pir.value()
  if motion == 1:
      print("\n\tSOMEONE CROSSED THE DOOR\n")
      skrin.fill(1)
      skrin.text("someone crossed the door:/",10,20,0)
      skrin.text("!!!",40,40,0)
      skrin.show()  
      for u in range (3):
        green_alarm.on()
        sleep(1.5)
        green_alarm.off()

      sleep(2)
      
        
  else :
      print("\n\tNO ONE APPROACHED THE DOOR\n")
      skrin.fill(1)
      skrin.text("no one approached:/",10,20,0)
      skrin.text("the door",30,40,0)
      skrin.show() 

      

        