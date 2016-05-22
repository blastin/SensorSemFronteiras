
/*
 * BancoDeDadosSensor.ino
    Copyright (C) <2016>  <Jeff>

    This program is free software: you can redistribute it and/or modify
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

#include "./Sensores.h"
#include "./BancoDeDadosSensor.h"

const char * TABELA_SENSOR_LUMINOSIDADE = "Sensor_luminosidade_ambiente";
const char * TABELA_SENSOR_QUALIDADE_AR = "Sensor_qualidade_do_ar";
const char * TABELA_SENSOR_VIBRACOES = "Sensor_vibracoes";
const char * TABELA_SENSOR_PRESSAO_TEMPERATURA = "Sensor_pressao_temperatura";
const char * DATABASE_NAME = "{database}";

void SensorMySQL::criarQuery(){

/*
	Generic Tabela:

		nome   : nome do sensor
		medida : medida calculada do sensor
		unidade: unidade da medida
		qualidade : Caso haja alguma informação sobre o ambiente, será inserido aqui.
	
*/


}

bool SensorMySQL::insert(MySQL_Connection& connector) {

	// Initiate the query class instance
	MySQL_Cursor *cur_mem = new MySQL_Cursor(&connector);

	// Execute the query
	cur_mem->execute(query);

	// Note: since there are no results, we do not need to read any data
	// Deleting the cursor also frees up memory used
	delete cur_mem;

	return true;
}