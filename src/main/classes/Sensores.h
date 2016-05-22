/*
 * Sensores.h
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

#ifndef SENSORES_CLASS_SENSORES_H
#define SENSORES_CLASS_SENSORES_H

#include "./BancoDeDadosSensor.h"

class SensorMySQL {

public:

    short leitura;

    SensorMySQL(int porta) { this->porta = porta; }

    int getPortaSensor(){ return porta; }

    virtual void calcular_medida() = 0;

    void criarQuery();

    bool insert(MySQL_Connection& connector);

private:
    int porta;
    char query[2<<9];
protected:
    const char * nomeSensor;
    const char * unidade_medida;
    const char * nomeTabela;
    char  qualidade[2<<5];
    float medida;
};

class Qualidade_do_ar : public SensorMySQL {

public:

    Qualidade_do_ar(int porta, const char * nomeTabela) : SensorMySQL(porta) {

	nomeSensor = "Sensor de qualidade do ar"; 
	unidade_medida = "{unidade}"; 

	this->nomeTabela = nomeTabela;

	}

    void calcular_medida();

};

class Vibracao : public SensorMySQL {

public:

    Vibracao(int porta, const char * nomeTabela) : SensorMySQL(porta){

	nomeSensor = "Sensor de vibração"; 
	unidade_medida = "{unidade}"; 

	this->nomeTabela = nomeTabela;

	}

    void calcular_medida();
};

class Pressao_Temperatura : public SensorMySQL {

public:

    Pressao_Temperatura(int porta, const char * nomeTabela) : SensorMySQL(porta) {

	nomeSensor = "Sensor de pressão e temperatura"; 
	unidade_medida = "{unidade}"; 

	this->nomeTabela = nomeTabela;

	}

    void calcular_medida();

};

class Luminosidade : public SensorMySQL {

public:

    Luminosidade(int porta, const char * nomeTabela) : SensorMySQL(porta) {
	
	nomeSensor = "Sensor de luminosidade ambiente"; 
	unidade_medida = "{unidade}";

	this->nomeTabela = nomeTabela;

	}

    void calcular_medida();

};

#endif //SENSORES_CLASS_SENSORES_H
