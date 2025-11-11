void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  int i = analogRead(A0);
  Serial.println(i);
  if (i > 100) {
    digitalWrite(8, 1);
  } else {
    digitalWrite(8, 0);
  }
  delay(500);
}
