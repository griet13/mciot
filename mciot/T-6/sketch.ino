#include<Adafruit_SSD1306.h>
#include<Adafruit_MPU6050.h>
#include<Adafruit_Sensor.h>
#include<Wire.h>

Adafruit_SSD1306 display(128,64,&Wire);
Adafruit_MPU6050 mpu;

void setup(){
  Serial.begin(115200);
  mpu.begin();
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.setTextColor(WHITE);
}

void loop(){
  sensors_event_t a,g,t;
  mpu.getEvent(&a,&g,&t);
  Serial.printf("A: %.1f %.1f %.1f | G: %.1f %.1f %.1f | T:%.1f\n",
  a.acceleration.x,a.acceleration.y,a.acceleration.z,g.gyro.x,g.gyro.y,
  g.gyro.z,t.temperature);
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("A:");
  display.print(a.acceleration.x,1);
  display.print(" ");
  display.print(a.acceleration.y,1);
  display.print(" ");
  display.print(a.acceleration.z,1);
  display.println();
  display.print("G:");
  display.print(g.gyro.x,1);
  display.print(" ");
  display.print(g.gyro.y,1);
  display.print(" ");
  display.print(g.gyro.z,1);
  display.println();
  display.print("T:");
  display.print(t.temperature,1);
  display.println();
  display.display();
  delay(1000);
}