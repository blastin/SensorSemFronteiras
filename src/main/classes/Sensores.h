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

class Sensor {

public:

    explicit
    Sensor(int porta) { this->porta = porta; }

    virtual void calcular_medida() = 0;

    void setLeitura(int leitura) {
        this->leitura = leitura;
    }

    int getLeitura(){
	return leitura;
    }

    float getMedida() {
        return medida;
    }

    int getPortaSensor(){
	return porta;
    }

private:
    int porta;
    int leitura;

protected:

    float medida;
    const char *nomeSensor;

    void setNomeDoSensor(const char* nomeSensor) {
	this->nomeSensor = nomeSensor;
    }

};

class Qualidade_do_ar : public Sensor {

public:

    Qualidade_do_ar(int porta) : Sensor(porta) { setNomeDoSensor("Sensor de qualidade do ar"); }

    void calcular_medida();

};

class Vibracao : public Sensor {

public:

    Vibracao(int porta) : Sensor(porta) { setNomeDoSensor("Sensor de vibração"); }

    void calcular_medida();
};

class Pressao_Temperatura : public Sensor {

public:

    Pressao_Temperatura(int porta) : Sensor(porta) { setNomeDoSensor("Sensor de pressão e temperatura"); }

    void calcular_medida();

};

class Luminosidade : public Sensor {

public:

    Luminosidade(int porta) : Sensor(porta) { setNomeDoSensor("Sensor de luminosidade ambiente"); }

    void calcular_medida();

};

#endif //SENSORES_CLASS_SENSORES_H
