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

    @author Modelo Abstrato : Jefferson Lisboa
    @author Medida do sensor: Arthur Ladislau Pereira

*/

#include "Temperatura.h"


void Temperatura::leituraSensor() {

  temperature = dht.readTemperature();
  bmp.getTemperature(&temperaturebmp180);// leitura de temperatura
}

void Temperatura::construirInformacoes() {

  bmp.getEvent(&event);

  if (event.pressure) {

    if (temperaturebmp180 > 0 && temperaturebmp180 < 50)
      temperaturebmp180 = (temperaturebmp180 + temperature) / 2;
      
    if (temperaturebmp180 <= 23)
      informacao = "friozinho";
    else if (temperaturebmp180 <= 30)
      informacao = "agradavel";
    else if (temperaturebmp180 <= 35)
      informacao = "quente";
    else if (temperaturebmp180 > 40)
      informacao  = "quente demais";

  }

}

