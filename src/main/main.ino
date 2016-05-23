
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

#include <SPI.h>
#include <Ethernet.h>

#include "./MySQL_Sensores.h"
#include "./Sensores.h"

/* Setup for Ethernet Library */
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server_addr(85, 10, 205, 173); // endereço do servidor db4free.net
EthernetClient client;

/* Setup for the Connector/Arduino */
MySQL_Connection connection((Client *)&client);
char user[]     = "{nomedousuario}";
char password[] = "{senhadousuario}";

Sensor * luminosidade;
Sensor * qualidadeDoAr;
Sensor * pressaoTemperatura;
Sensor * vibracao;

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  Ethernet.begin(mac_addr);

  if (connection.connect(server_addr, 3306, user, password)) {
    Serial.println(F("Connected!"));
  } else {
    Serial.println(F("Connection failed."));
  }

  luminosidade        = new Luminosidade(A0);
  qualidadeDoAr       = new QualidadeDoAr(A1);
  pressaoTemperatura  = new PressaoTemperatura(A2);
  vibracao            = new Vibracao(A3);

}

void loop() {

  /*Leitura analógica de cada sensor.*/
  AnalogRead(luminosidade);
  AnalogRead(qualidadeDoAr);
  AnalogRead(pressaoTemperatura);
  AnalogRead(vibracao);

  /* Calcular medida,
     especificar unidade
     detalhar informações adicionais do ambiente
  */
  construirInformacoes(luminosidade);
  construirInformacoes(qualidadeDoAr);
  construirInformacoes(pressaoTemperatura);
  construirInformacoes(vibracao);


  /*
     Gerar String formatada para a biblioteca MySQL inserir no banco de dados.
  */
  gerenciarQuery(luminosidade);
  gerenciarQuery(qualidadeDoAr);
  gerenciarQuery(pressaoTemperatura);
  gerenciarQuery(vibracao);

  /* Armazenar informações do sensor no banco de dados */
  insertMySQL(luminosidade);
  insertMySQL(qualidadeDoAr);
  insertMySQL(pressaoTemperatura);
  insertMySQL(vibracao);

  delay(3000);

}

void AnalogRead(Sensor * sensor) {
  // read the input on analog pin N:
  sensor->setLeitura(analogRead(sensor->getPorta()));
}

void construirInformacoes(Sensor * sensor) {
  sensor->construirInformacoes();
}

void gerenciarQuery(Sensor * sensor) {
  sensor->construirQuery();
}

void insertMySQL(Sensor * sensor) {
  sensor->insertMySql(connection);
}

