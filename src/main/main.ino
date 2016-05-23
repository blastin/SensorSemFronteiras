
#include "./Luminosidade.h"
#include "./MySQL_Sensores.h"

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

  Ethernet.begin(mac_addr);

  if (connection.connect(server_addr, 3306, user, password)) {
    Serial.println("Connected!");
  } else {
    Serial.println("Connection failed.");
  }

  luminosidade = new Luminosidade(A0, TABELA_SENSOR_LUMINOSIDADE);

}

void loop() {

  // read the input on analog pin 0:
  leitura(luminosidade);

  //Calcular medida
  medir(luminosidade);

  //Gerar Query
  gerarQuery(luminosidade);

  //Insert Query
  insertMySQL(luminosidade);

  delay(2000);

}

void leitura(Sensor * sensor) {
  sensor->setLeitura(analogRead(sensor->getPorta()));
}

void medir(Sensor * sensor) {
  sensor->medir();
}

void gerarQuery(Sensor * sensor) {
  sensor->construirQuery();
}

void insertMySQL(Sensor * sensor) {
  sensor->insertMySql(connection);
}

