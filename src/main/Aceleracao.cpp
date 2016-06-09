
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
    @author Medida do sensor: Thiago Yuji

*/

#include "Aceleracao.h"
#include <math.h>

void Aceleracao::leituraSensor() {
  calcular(x,y,z); 
}

void Aceleracao::construirInformacoes() {

  informacao = "(x,y,z) => Variacao(";

  if ( fabs(x - xantigo) > 3 ) {
    informacao.concat(F("x"));
    xantigo = x;
  }
  informacao.concat(F(","));
  if ( fabs(y - yantigo) > 3 ) {
    informacao.concat(F("y"));
    yantigo = y;
  }
  informacao.concat(F(","));
  if ( fabs(z - zantigo) > 3 ) {
    informacao.concat(F("z"));
    zantigo = z;
  }

  informacao.concat(F(")"));

}

void Aceleracao::setup_Aceleracao() {

  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);
  accelero.setSensitivity(LOW);

  calcular(xantigo, yantigo, zantigo);

}

inline
void Aceleracao::calcular(float &vetor_i, float& vetor_j, float& vetor_k) {

  vetor_i = accelero.getXAccel(); //Obtem o valor do eixo X
  vetor_j = accelero.getYAccel(); //Obtem o valor do eixo Y
  vetor_k = accelero.getZAccel(); //Obtem o valor do eixo Z

}


