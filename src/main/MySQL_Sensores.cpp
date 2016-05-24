
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

    @author construtor e abstrato : Jefferson Lisboa.

*/

#include <Arduino.h>

#include "MySQL_Sensores.h"
#include "Sensor.h"

static const String DatabaseName = "DB_NAME";

void Sensor::construirQuery() {

  /*
    Generic Tabela:

    nome   : nome do sensor
    medida : medida calculada do sensor
    unidade: unidade da medida
    qualidade : Caso haja alguma informação sobre o ambiente, será inserido aqui.

  */

  query = F("INSERT INTO database.tabela (nome,medida,unidade,qualidade) VALUES ('nomeSensor',$medida,'unidade_medida','$qualidade')");

  String medidaString = String(medida, 4);
  
  query.replace(F("database"), DatabaseName);
  query.replace(F("tabela"), nomeTabela);
  query.replace(F("nomeSensor"), nomeSensor);
  query.replace(F("$medida"), medidaString);
  query.replace(F("unidade_medida"), unidadeMedida);
  query.replace(F("$qualidade"), qualidade);

  Serial.print(F("Sensor :"));
  Serial.print(nomeSensor);
  Serial.print(F("\t <> \t"));
  Serial.println(query);

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


