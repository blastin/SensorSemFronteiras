/*
    This file is part of S.S.F.
    This S.S.F is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    @author Modelo Abstrato : Jefferson Lisboa
    @author Medida do sensor: Arthur Ladislau Pereira

*/

#include "PressaoTemperatura.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include "DHT.h"

#define DHTPIN 37
#define DHTTYPE DHT11

static DHT dht(DHTPIN, DHTTYPE);
static Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

void PressaoTemperatura::leituraSensor() {

  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

}

void PressaoTemperatura::construirInformacoes() {

  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure) {

    float temperaturebmp180;
    float pressao = event.pressure;

    pressao = pressao / 1.3332239;
    pressao = pressao / 760; //transforma em atm

    informacao = "P(";
    informacao.concat(pressao);
    informacao.concat(F(") atm >> "));

    bmp.getTemperature(&temperaturebmp180);// leitura de temperatura

    if (temperaturebmp180 > 0 && temperaturebmp180 < 50) temperaturebmp180 = (temperaturebmp180 + temperature) / 2;

    informacao.concat(temperaturebmp180);
    informacao.concat(F(" °C:"));

    if (temperaturebmp180 <= 23) informacao.concat(F("friozinho"));
    else if (temperaturebmp180 <= 30) informacao.concat(F("agradavel"));
    else if (temperaturebmp180 <= 35) informacao.concat(F("quente"));
    else if (temperaturebmp180 > 40) informacao.concat(F("quente demais"));

    informacao.concat(F(" >> Ar "));

    if (humidity < 40) informacao.concat(F("muito seco\t"));
    else if (humidity < 60) informacao.concat(F("ideal"));
    else if (humidity < 70) informacao.concat(F("umido"));
    else if (humidity < 70) informacao.concat(F("umido demais"));

    informacao.concat(F("\t"));

  }

}

void PressaoTemperatura::setupPressaoTemperatura() {

  dht.begin();

  if (!bmp.begin()) {
    /* There was a problem detecting the BMP085 ... check your connections */
    Serial.print("Ooops, no BMP180 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }

}




