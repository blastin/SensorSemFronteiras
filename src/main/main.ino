
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

*/

#include <SPI.h>
#include <Ethernet.h>

#include <MySQL_Encrypt_Sha1.h>
#include <MySQL_Packet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

#include "./classes/Sensores.h"

Sensor * sensor_de_luminosidade;
Sensor * sensor_de_qualidade_do_ar;
Sensor * sensor_de_vibracao;
Sensor * sensor_de_pressao_e_temperatura;

void setup() {

  sensor_de_luminosidade          = new Luminosidade(A0);
  sensor_de_qualidade_do_ar       = new Qualidade_do_ar(A1);
  sensor_de_vibracao              = new Vibracao(A2);
  sensor_de_pressao_e_temperatura = new Pressao_Temperatura(A3);
  
  Serial.begin(9600);

}

void loop() {

  leitura(sensor_de_luminosidade);
  leitura(sensor_de_qualidade_do_ar);
  leitura(sensor_de_vibracao);
  leitura(sensor_de_pressao_e_temperatura);
  
  delay(1 * 1000);
  
}

inline
void leitura(Sensor * sensor) {

  sensor->setLeitura
  (
    analogRead(sensor->getPortaSensor())
  );
}

