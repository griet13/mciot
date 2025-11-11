// Pin declarations
#define TRIG 14
#define ECHO 25
#define BUZZER 15
#define YELLOW_LED 5
#define GREEN_LED 2

long duration;
float distance;

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.println("Home Safety and Security System Initialized");
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read the echo pulse
  duration = pulseIn(ECHO, HIGH);
  distance = (duration * 0.0343) / 2; // Convert time to distance (cm)

  // Print the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Determine safety level
  if (distance > 200) {
    Serial.println("✅ Safe - No one near the door");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    noTone(BUZZER);
  }
  else if (distance >= 50 && distance <= 200) {
    Serial.println("⚠️  Someone approaching the door!");
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    tone(BUZZER, 1000);
    delay(200);
    noTone(BUZZER);
  }
  else {
    Serial.println("🚨 Person very close to the door!");
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    tone(BUZZER, 1500);
    delay(300);
    noTone(BUZZER);
  }

  delay(1000);
}
