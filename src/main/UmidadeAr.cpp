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

#include "UmidadeAr.h"


void UmidadeAr::leituraSensor() {

  humidity = dht.readHumidity();
}

void UmidadeAr::construirInformacoes() {

  bmp.getEvent(&event);

  if (event.pressure) {

    if (humidity < 40)
      informacao = "Ar muito seco";
    else if (humidity < 60)
      informacao = "Ar ideal";
    else if (humidity < 70)
      informacao = "Boa umidade do ar";
    else if (humidity < 70)
      informacao = "Umidade relativamente alta";
      
  }

}

