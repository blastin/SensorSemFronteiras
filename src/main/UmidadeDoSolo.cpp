
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
    @author Medida do sensor: Otavio Teodoro Souza Silva

*/

#include "UmidadeDoSolo.h"

void UmidadeDoSolo::leituraSensor() {

  leitura = analogRead(porta);

}

void UmidadeDoSolo::construirInformacoes() {

  int umidade = map(umidade, 1023, 0, 0, 200);

  if (umidade >= 65) {

    informacao = F("Alta Umidade");

  } else if ((umidade < 65) && (umidade >= 40)) {

    informacao = F("Media Umidade");

  } else {

    informacao = F("Baixa Umidade");

  }
  
}




