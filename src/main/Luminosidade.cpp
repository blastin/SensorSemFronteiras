
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
    @author Medida do sensor: Jefferson Lisboa.

*/

#include "Luminosidade.h"

#define FATOR_AMBIENTAL 0.25 //Esse valor é alterado conforme o ambiente. Logo, antes de compilar, deve-se estabelecer seu valor

void Luminosidade::leituraSensor() {

  leitura = analogRead(porta);
}

void Luminosidade::construirInformacoes() {

  float medida = leitura * (5.0 / 1023.0);

  Serial.println(medida);

  if (medida > (1.76 - FATOR_AMBIENTAL))
    informacao = "alta luminosidade";
  else if (medida > (0.98 - FATOR_AMBIENTAL / 2))
    informacao = "boa luminosidade";
  else if (medida > (0.61 - FATOR_AMBIENTAL / 3))
    informacao = "luminosidade regular";
  else if (medida > (0.39 - FATOR_AMBIENTAL / 4))
    informacao = "pessima luminosidade";
  else if (medida > (0.199 - FATOR_AMBIENTAL / 5))
    informacao = "ambiente escuro";
  else
    informacao = "ambiente sem luminosidade";

}




