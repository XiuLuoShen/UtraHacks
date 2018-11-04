// defines pins numbers
const int trigPin1 = 10;
const int echoPin1 = 9;
const int trigPin2 = 12;
const int echoPin2 = 11;
const int trigPin3 = 5;
const int echoPin3 = 3;
const int alarmLight = 13;

// defines variables
long distance;
long duration;
long distance1;
long duration2;
long distance2;
long duration3;
long distance3;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(alarmLight, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  delay(500);
  SonarSensor(trigPin3, echoPin3);
  distance3 = distance;
  delay(50);
  SonarSensor(trigPin1, echoPin1);
  distance1 = distance;
  delay(50);
  SonarSensor(trigPin2, echoPin2);
  distance2 = distance;
  // Prints the distance on the Serial Monitor
  Serial.println("Distances: ");
  Serial.println(distance1);
  Serial.println(distance2);
  Serial.println(distance3);
  if (distance1 >10 && distance2 > 11 && distance3 > 11){
    // send enable out
    digitalWrite(alarmLight, LOW);
  }
  else{
      Serial.println("Not empty");
    digitalWrite(alarmLight, HIGH);
  }
}

void SonarSensor(int trigPin,int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)*0.034;
 
}
