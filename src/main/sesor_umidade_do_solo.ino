//#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
 ////// lcd libs ////
 
int umidade;
 
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, LOW);
  //lcd.setCursor(0, 0); //lcd code
  umidade = analogRead(A0);
  umidade = map(umidade, 1023, 0, 0, 200);

  if (umidade >= 65){

    Serial.println("Alta Umidade");
    
  }else if ((umidade < 65) && (umidade >= 40)){

    Serial.println("Média Umidade");
    
  }else{

    Serial.println("Baixa Umidade");
    
  }
  
  /* //Exibição de valores//
  Serial.println("Umidade em: ");
  Serial.println(umidade);
  Serial.println("%");
  //lcd.print("Umidade em:"); //lcd code
  //lcd.print(umidade); //lcd code
  //lcd.print(" %"); //lcd code
  if(umidade < 20)
  {
       digitalWrite(13, HIGH);
  }
  delay(500);*/
  //lcd.clear(); //lcd code
}
