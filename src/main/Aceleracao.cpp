
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

#define CONST_VARIACAO 10

void Aceleracao::leituraSensor() {

  calcular(x, y, z);

}

void Aceleracao::construirInformacoes() {

  float variacaoX, variacaoY, variacaoZ;

  variacaoX = fabs(x - xantigo);
  variacaoY = fabs(y - yantigo);
  variacaoZ = fabs(z - zantigo);

  if (variacaoX > CONST_VARIACAO && variacaoY < CONST_VARIACAO && variacaoZ < CONST_VARIACAO) {

    if (x > xantigo) {
      informacao = "Prototipo esta inclinado positivamente no eixo x";
    } else {
      informacao = "Protitipo esta inclinado negativamente no eixo x";
    }

    xantigo = x;

  } else if (variacaoY > CONST_VARIACAO && variacaoX < CONST_VARIACAO && variacaoZ < CONST_VARIACAO) {

    if (y > yantigo) {
      informacao = "Prototipo esta inclinado positivamente no eixo y";
    } else {
      informacao = "Prototipo esta inclinado negativamente no eixo y";
    }

    yantigo = y;

  } else if (variacaoX > CONST_VARIACAO / 2 && variacaoY > CONST_VARIACAO / 2 && variacaoZ > CONST_VARIACAO / 2) {

    informacao = "O prototipo esta em um ambiente irregular";

    xantigo = x;
    yantigo = y;
    zantigo = z;

  } else if (variacaoX < CONST_VARIACAO && variacaoY < CONST_VARIACAO && variacaoZ > CONST_VARIACAO) {
    zantigo = z;
  } else {
    informacao = "Prototipo estavel";
  }



}

void Aceleracao::setup_Aceleracao() {

  accelero.begin(13, 12, 11, 10, A1, A2, A3);
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


