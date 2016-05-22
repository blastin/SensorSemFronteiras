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

#include "./classes/Sensores.h"
#include "./classes/BancoDeDadosSensor.h"

/* Setup for Ethernet Library */
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server_addr(85, 10, 205, 173); // endereço do servidor db4free.net

/* Setup for the Connector/Arduino */
Connector connection; // The Connector/Arduino reference
char user[] = "{nomedousuario}";
char password[] = "{senhadousuario}";

Sensor * sensor_de_luminosidade;
Sensor * sensor_de_qualidade_do_ar;
Sensor * sensor_de_vibracao;
Sensor * sensor_de_pressao_e_temperatura;

void setup() {

  sensor_de_luminosidade          = new Luminosidade(A0, TABELA_SENSOR_LUMINOSIDADE);
  sensor_de_qualidade_do_ar       = new Qualidade_do_ar(A1, TABELA_SENSOR_QUALIDADE_AR);
  sensor_de_vibracao              = new Vibracao(A2, TABELA_SENSOR_VIBRACOES);
  sensor_de_pressao_e_temperatura = new Pressao_Temperatura(A3, TABELA_SENSOR_PRESSAO_TEMPERATURA);

  Serial.begin(9600);

  pinMode(13, OUTPUT);

  Ethernet.begin(mac_addr);

  if (connection.mysql_connect(server_addr, 3306, user, password)) {
    Serial.println("Connected!");
  } else {
    Serial.println("Connection failed.");
  }

}

void loop() {

  digitalWrite(13, HIGH);

    leitura(sensor_de_luminosidade);
    leitura(sensor_de_qualidade_do_ar);
    leitura(sensor_de_vibracao);
    leitura(sensor_de_pressao_e_temperatura);
  
    converterParaMedida(sensor_de_luminosidade);
    converterParaMedida(sensor_de_qualidade_do_ar);
    converterParaMedida(sensor_de_vibracao);
    converterParaMedida(sensor_de_pressao_e_temperatura);

  delay(1000);

  digitalWrite(13, LOW);

  delay(1000);
}

inline
void leitura(Sensor * sensor) {
  sensor->leitura = analogRead(sensor->getPortaSensor());
}

inline
void converterParaMedida(Sensor * sensor) {
  sensor->calcular_medida();
}

