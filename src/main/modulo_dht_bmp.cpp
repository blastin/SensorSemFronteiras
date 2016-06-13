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

#include "modulo_dht_bmp.h"


DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

void setupDHT_BMP() {

   dht.begin();

  if (!bmp.begin()) {
    /* There was a problem detecting the BMP085 ... check your connections */
    //Serial.print("Ooops, no BMP180 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }
   
}




