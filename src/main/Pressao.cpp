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

#include "Pressao.h"

void Pressao::leituraSensor() {}

void Pressao::construirInformacoes() {
  
  bmp.getEvent(&event);
  
  if (event.pressure) {

    float pressao = event.pressure;

    pressao = pressao / 1.3332239;
    pressao = pressao / 760; //transforma em atm
     
    if (pressao > 0.88 && pressao <= 1.2) {
      informacao = "Zona próxima ao nivel do mar";
    } else if (pressao > 1.2 && pressao <= 2.2) {
      informacao = "Zona um pouco afastada do nivel do mar";
    } else if (pressao > 2.2 && pressao <= 3.2) {
      informacao = "Zona de pressao intermediaria";
    } else if (pressao > 3.2) {
      informacao = "Zona de alta pressao";
    }
  }

}

