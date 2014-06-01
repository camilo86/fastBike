char input[20];
int index = 0;
int hallEffectSensor = 2;

void setup() {
  delay(10);
  Serial.begin(9600);
  pinMode(hallEffectSensor, INPUT);
  digitalWrite(hallEffectSensor, HIGH);
  Serial.println("Welcome to Smart Bike, by Camilo Gonzalez");
}

void loop() {
  if(Serial.available() == 0) {
    index = 0;
  }
  if(Serial.available() > 0) {
    while(1) {
      input[index] = Serial.read();
      if(input[index] == '\n') break;
      if(input[index] == -1) continue;
      index++;
    }
    Serial.print("input ");
    Serial.println(input);
    memset(input, '\0', 10);
  }
}

boolean getHallEffect(int pin) {
  boolean value = false;
  int pinInput = digitalRead(pin);
  
  if(pinInput == 0) {
    value = true;
  }else {
    value = false;
  }
  return value;
}

