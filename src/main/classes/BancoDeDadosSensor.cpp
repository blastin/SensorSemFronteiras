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
#include <string.h>

const char * TABELA_SENSOR_LUMINOSIDADE = "Sensor_luminosidade_ambiente";
const char * TABELA_SENSOR_QUALIDADE_AR = "Sensor_qualidade_do_ar";
const char * TABELA_SENSOR_VIBRACOES = "Sensor_vibracoes";
const char * TABELA_SENSOR_PRESSAO_TEMPERATURA = "Sensor_pressao_temperatura";

static const char * DATABASE_NAME = "{database}";

static void replacestr(char *line, const char *search, const char *replace);

void SensorMySQL::criarQuery(){

/*
	Generic Tabela:

		nome   : nome do sensor
		medida : medida calculada do sensor
		unidade: unidade da medida
		qualidade : Caso haja alguma informação sobre o ambiente, será inserido aqui.
	
*/

	char INSERT_SQL[] = "INSERT INTO #DATABASE.#TABELA (nome,medida,unidade,qualidade)  \
				VALUES (\'#nomeSensor\',#medida,\'#unidade_medida\',\'#qualidade\')";
				
	char buffer[10];
	
	sprintf(buffer,"%.2f",medida);
	
	replacestr(INSERT_SQL,"#DATABASE",DATABASE_NAME);
	replacestr(INSERT_SQL,"#TABELA",  nomeTabela);
	replacestr(INSERT_SQL,"#nomeSensor",nomeSensor);
	replacestr(INSERT_SQL,"#medida", buffer);
	replacestr(INSERT_SQL,"#unidade_medida",unidade_medida);
	replacestr(INSERT_SQL,"#qualidade", qualidade);
		
	strcpy(query,INSERT_SQL);
}

bool SensorMySQL::insert(MySQL_Connection& connector) {
	
	bool boolean;
	
	// Initiate the query class instance
	MySQL_Cursor *cur_mem = new MySQL_Cursor(&connector);

	// Execute the query
	boolean = cur_mem->execute(query);

	// Note: since there are no results, we do not need to read any data
	// Deleting the cursor also frees up memory used
	delete cur_mem;
	
	// Limpa o buffer da variavel query;
	memset(query,0,sizeof(query));
	
	return boolean;
}

static void replacestr(char *line, const char *search, const char *replace)
{
	/*
	 * Esse algoritmo pode ser encontrado em :
	 * 
	 * @fonte: stackoverflow.com/questions/779875/what-is-the-function-to-replace-string-in-c
	 *
	 * 
	 */
	 
     char *sp;

     if ((sp = strstr(line, search)) == NULL) {
         return;
     }
     
     int search_len = strlen(search);
     int replace_len = strlen(replace);
     int tail_len = strlen(sp+search_len);

     memmove(sp+replace_len,sp+search_len,tail_len+1);
     memcpy(sp, replace, replace_len);
     
}
