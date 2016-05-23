
#include <Arduino.h>
#include <stdlib.h>

#include "MySQL_Sensores.h"
#include "Sensor.h"


void Sensor::construirQuery() {

  /*
    Generic Tabela:

    nome   : nome do sensor
    medida : medida calculada do sensor
    unidade: unidade da medida
    qualidade : Caso haja alguma informação sobre o ambiente, será inserido aqui.

  */

  query = "INSERT INTO database.tabela (nome,medida,unidade,qualidade) VALUES ('nomeSensor',$medida,'unidade_medida','$qualidade')";

  String medidaString = String(medida, 4);

  query.replace("database", DATABASE_NAME);
  query.replace("tabela", nomeTabela);
  query.replace("nomeSensor", nomeSensor);
  query.replace("$medida", medidaString);
  query.replace("unidade_medida", unidadeMedida);
  query.replace("$qualidade", qualidade);
  
}

void Sensor::insertMySql(MySQL_Connection& connector) {

  char queryChar[query.length() + 1];

  // Initiate the query class instance
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&connector);

  //gerando char[]
  query.toCharArray(queryChar, query.length());

  // Execute the query
  cur_mem->execute(queryChar);

  // Note: since there are no results, we do not need to read any data
  // Deleting the cursor also frees up memory used
  delete cur_mem;

}


