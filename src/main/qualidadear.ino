void setup() {
  Serial.begin(9600);
}

void loop() {
  int QualidadeAr = analogRead(A7);
  if (QualidadeAr < 90) {
    Serial.println("Ar fresco");
  }
  else if (QualidadeAr < 340) {
    Serial.println("Pouco poluido");
  }
  else if (QualidadeAr < 650) {
    Serial.println("Bem poluido");
  }
  else {
    Serial.println("Muito poluido");
  }
  delay(1000);        // delay in between reads for stability
}
