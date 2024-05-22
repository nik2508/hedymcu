const int IR_SENSOR_PIN = D1; 
const int RELAY_PIN = D4;
bool isRoomOccupied = false; 
unsigned long lastDetectionTime = 0; 
const unsigned long detectionDelay = 10000; 

void setup() 
{
  Serial.begin(115200);
  
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW); 
}

void loop() {
  int sensorState = digitalRead(IR_SENSOR_PIN);

  if(sensorState == LOW) 
  {
    isRoomOccupied = true;
    digitalWrite(RELAY_PIN, HIGH); 
    lastDetectionTime = millis(); 
  } 
  else if (sensorState == HIGH && isRoomOccupied) 
  {
    if(millis() - lastDetectionTime > detectionDelay)
    {
      isRoomOccupied = false;
      digitalWrite(RELAY_PIN, LOW); 
    }
  }

  delay(100); 
}
