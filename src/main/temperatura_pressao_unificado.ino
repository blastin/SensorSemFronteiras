#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include "DHT.h"
#define DHTPIN 2  
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

/*///////////////*desnecessario* ////////////////////////////////
void displaySensorDetails(void) //dados do sensor
{
  sensor_t sensor;
  bmp.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" hPa");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" hPa");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" hPa");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}
////////////////////*desnecessario///////////////////////////////*/

void setup() {
 Serial.begin(9600);
 dht.begin();
 if(!bmp.begin())
  {
    /* There was a problem detecting the BMP085 ... check your connections */
    Serial.print("Ooops, no BMP180 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
}


void loop() {
  sensors_event_t event;
  bmp.getEvent(&event);
  float h = dht.readHumidity();//calcula a umidade do ar
  float t = dht.readTemperature();// calcula a temperatura pelo dht11(sensor azul)

    if (event.pressure)
  {
    /* Display atmospheric pressue in hPa */
    float pressao = event.pressure; //calcula pressao atmosferica
    pressao = pressao / 1.3332239;//converte de hPa para mmHg
    Serial.print("Pressure:    ");
    Serial.print(pressao);
    Serial.println(" mmHg");
    

    Serial.print("Humidity: ");
    Serial.print(h);// entrega umidade
    Serial.print(" %\t");// por cento
    if(h<20) Serial.println("criticamente seco");// classificacao da umidade
    else if(h<40) Serial.println("muito seco");
    else if(h<50) Serial.println("seco");
    else if(h<60) Serial.println("ideal");
    else if(h<70) Serial.println("umido");
    else if(h<80) Serial.println("muito umido");
    else if(h<70) Serial.println("umido demais");
  
    float temperature;// temperatura lida pelo bmp180
    float tempf;// temperatura final
    bmp.getTemperature(&temperature);// leitura de temperatura
    if(temperature<=0) tempf= temperature;//temperatura final
    else tempf = (t+temperature)/2;// calcula media das leituras dos dois sensores
    Serial.print("Temperature: ");
    Serial.print(tempf); //imprime temperatura
    Serial.print(" C"); //medida
    if(tempf<=10) Serial.println("\t muito frio");// classificacao de temperatura
    else if(tempf<=15) Serial.println("\tfrio");
    else if(tempf<=20) Serial.println("\tfriozinho");
    else if(tempf<=25) Serial.println("\tagradavel");
    else if(tempf<=30) Serial.println("\tquente");
    else if(tempf<=35) Serial.println("\tmuito quente");
    else if(tempf>35) Serial.println("\tquente demais");

    /* Then convert the atmospheric pressure, and SLP to altitude         */
    /* Update this next line with the current SLP for better results      */
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    float a = (bmp.pressureToAltitude(seaLevelPressure,event.pressure)); // calcula altitude e armazena em 'a'
    Serial.print("Altitude:    "); 
    Serial.print(a); //imprime altitude
    Serial.println(" m"); //medida
    Serial.println("");


  }
    else
  {
    Serial.println("Sensor error");
  }

 delay(1000);

}
