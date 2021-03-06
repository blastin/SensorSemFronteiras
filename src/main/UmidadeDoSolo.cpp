
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

  int porcentagem_umidade = map(leitura, 1023, 0, 0, 100);

  if (porcentagem_umidade >= 25) {

    informacao = "Alta umidade do solo";

  } else if (porcentagem_umidade >= 10) {

    informacao = "Media umidade do solo";

  } else if (porcentagem_umidade >= 4) {

    informacao = "Baixa umidade do solo";

  } else {

    informacao = "Solo seco ou degradavel";

  }

}




