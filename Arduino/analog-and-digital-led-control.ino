// Furkan Karabulut
// https://github.com/Ntelhon
// 23/10/2021 - 00:25 UTC+3
const int button = 3;
const int digitalLed = 4;
const int analogLed = 5;

void setup() {
  Serial.begin(1200);

  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if(digitalRead(button) == HIGH){
    digitalWrite(digitalLed, HIGH);
  }else if(digitalRead(button) == LOW){
    digitalWrite(digitalLed, LOW);
  }

  int analogValue = analogRead(A5);
  Serial.print("Analog Input: ");
  Serial.println(analogValue);
  Serial.print("Active Analog Controlled Output: ");
  Serial.println(analogValue * (5.0 / 1023.0));

  analogWrite(analogLed, analogValue);
}
