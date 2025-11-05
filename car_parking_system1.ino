#define trigPin 9
#define echoPin 10
#define ledRed 3
#define ledGreen 4

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 10) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
  } else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
  }

  delay(500);
}
