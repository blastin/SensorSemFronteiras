
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

    @author construtor : Jefferson Lisboa.

*/

#include "./Luminosidade.h"
#include "./MySQL_Sensores.h"


const String TABELA_SENSOR_LUMINOSIDADE = "Sensor_luminosidade_ambiente";
const String TABELA_SENSOR_QUALIDADE_AR = "Sensor_qualidade_do_ar";
const String TABELA_SENSOR_VIBRACOES = "Sensor_vibracoes";
const String TABELA_SENSOR_PRESSAO_TEMPERATURA = "Sensor_pressao_temperatura";
const String DATABASE_NAME = "{database}";

/* Setup for Ethernet Library */
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server_addr(85, 10, 205, 173); // endereço do servidor db4free.net
EthernetClient client;

/* Setup for the Connector/Arduino */
MySQL_Connection connection((Client *)&client);
char user[]     = "{nomedousuario}";
char password[] = "{senhadousuario}";

Sensor * luminosidade;

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  Ethernet.begin(mac_addr);

  if (connection.connect(server_addr, 3306, user, password)) {
    Serial.println("Connected!");
  } else {
    Serial.println("Connection failed.");
  }

  luminosidade = new Luminosidade(A0, TABELA_SENSOR_LUMINOSIDADE);

}

void loop() {

  digitalWrite(13, HIGH);

  // read the input on analog pin 0:
  leitura(luminosidade);

  //Calcular medida
  medir(luminosidade);

  //Gerar Query
  criarQuery(luminosidade);

  //Insert Query
  //insertMySQL(luminosidade);

  delay(1000);

  digitalWrite(13, LOW);

  delay(1000);

}

void leitura(Sensor * sensor) {
  sensor->setLeitura(analogRead(sensor->getPorta()));
}

void medir(Sensor * sensor) {
  sensor->medir();
}

void criarQuery(Sensor * sensor) {
  sensor->construirQuery(DATABASE_NAME);
}

void insertMySQL(Sensor * sensor) {
  sensor->insertMySql(connection);
}

