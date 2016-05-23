
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

    @author abstração e modelagem : Jefferson Lisboa.

*/

#ifndef SENSOR_CLASSE_H
#define SENSOR_CLASSE_H

#include <Arduino.h>
#include "./MySQL_Sensores.h"

class Sensor {

  public:

    explicit
    Sensor(int porta) {
      this->porta = porta;
    }

    virtual void medir() = 0;

    void construirQuery();

    void insertMySql(MySQL_Connection& connector);

    void setLeitura(int leitura) {
      this->leitura = leitura;
    }

    int getPorta() {
      return porta;
    }

  private:

    int porta;
    String query;

  protected:
    String nomeTabela;
    String  nomeSensor;
    String  unidadeMedida;
    String  qualidade;
    int     leitura;
    float   medida;

};

#endif

