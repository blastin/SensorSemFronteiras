
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


#include "MySQL_Sensores.h"
#include "Sensores.h"

/* Setup for Ethernet Library */
byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server_addr(54, 215, 148, 52); // endereço do servidor freesqldatabase.com
//IPAddress ip();
EthernetClient client;

/* Setup for the Connector/Arduino */
MySQL_Connection connection((Client *)&client);
char user[]     = "sql3120763";
char password[] = "";

Sensor * luminosidade;
//Sensor * qualidadeDoAr;
//Sensor * pressaoTemperatura;
//Sensor * aceleracao;

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("\n");
  
  /*Ethernet.begin(mac_addr);

    if (connection.connect(server_addr, 3306, user, password)) {
    Serial.println(F("Connected!"));
    } else {
    Serial.println(F("Connection failed."));
    }*/

  luminosidade          = new Luminosidade(A0);
  //qualidadeDoAr       = new QualidadeDoAr(A1);
  //pressaoTemperatura  = new PressaoTemperatura(A2);
  //aceleracao            = new Aceleracao(A3);

}

void loop() {

  /*Leitura analógica de cada sensor.*/
  leitura(luminosidade);
  //leitura(qualidadeDoAr);
  //leitura(pressaoTemperatura);
  //leitura(aceleracao);

  /* Calcular medida,
     especificar unidade
     detalhar informações adicionais do ambiente
  */
  construirInformacoes(luminosidade);
  //construirInformacoes(qualidadeDoAr);
  //construirInformacoes(pressaoTemperatura);
  //construirInformacoes(aceleracao);


  /*
     Gerar String formatada para a biblioteca MySQL inserir no banco de dados.
  */
  gerenciarQuery(luminosidade);
  //gerenciarQuery(qualidadeDoAr);
  //gerenciarQuery(pressaoTemperatura);
  //gerenciarQuery(aceleracao);

  /* Armazenar informações do sensor no banco de dados */
  //insertMySQL(luminosidade);
  //insertMySQL(qualidadeDoAr);
  //insertMySQL(pressaoTemperatura);
  //insertMySQL(aceleracao);

  delay(3000);

}

void leitura(Sensor * sensor) {
  sensor->leituraSensor();
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


