
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

#ifndef SENSOR_PRESSAO_CLASSE_H
#define SENSOR_PRESSAO_CLASSE_H

#include "Sensor.h"
#include "modulo_dht_bmp.h"

class Pressao: public Sensor {

  public:

    Pressao() :
      Sensor() {

      nomeTabela = "SensorPressao";

      nomeSensor = "Pressao";
      
    }

    void construirInformacoes();
    void leituraSensor();

  private:
    sensors_event_t event;
};

#endif




