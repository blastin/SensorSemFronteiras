
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

    @author Modelo Abstrato : Jefferson Lisboa.

*/

#ifndef SENSOR_QUALIDADE_AR_CLASSE_H
#define SENSOR_QUALIDADE_AR_CLASSE_H

#include "Sensor.h"

class QualidadeDoAr: public Sensor {

  public:

    QualidadeDoAr() :
      Sensor(int porta) {

      nomeTabela = F("SensorQuAr");

      nomeSensor = F("Qualidade do Ar");

      this->porta = porta;

    }

    void construirInformacoes();
    void leituraSensor();

  private:
    int leitura;
    int porta;
};

#endif




