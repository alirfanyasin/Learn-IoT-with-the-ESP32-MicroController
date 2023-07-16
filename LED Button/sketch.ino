int ledPin = 2;
int btnPin = 32;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Program Button LED");
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT);
}

void loop() {
  if(digitalRead(btnPin) == HIGH){
    digitalWrite(ledPin, HIGH);
    Serial.println("Lampu Hidup");
    delay(500);
  }else {
    digitalWrite(ledPin, LOW);
    Serial.println("Lampu Mati");
    delay(500);
  }

}
