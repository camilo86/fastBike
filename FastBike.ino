char input[20];
int index = 0;

void setup() {
  delay(10);
  Serial.begin(9600);
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
    Serial.println("input ");
    Serial.println(input);
    memset(input, '\0', 10);
  }
}

