
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

#include "Sensor.h"

void Sensor::construirQuery() {

  /*
    Generic Tabela:

    nome   : nome do sensor
    informacao : Caso haja alguma informação sobre o ambiente, será inserido aqui.

  */

  String query;

  query = nomeTabela;
  query.concat(":");
  query.concat(nomeSensor);
  query.concat(",");
  query.concat(informacao);

  Serial.println(query);

}

