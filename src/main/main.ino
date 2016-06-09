
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

    @author construtor : Jefferson Lisboa.

*/

#include "Sensores.h"

Sensor * luminosidade;
//Sensor * qualidadeDoAr;
Sensor * pressaoTemperatura;
Sensor * aceleracao;


void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("\n");
  
  luminosidade          = new Luminosidade(A3);
  //qualidadeDoAr       = new QualidadeDoAr(A1);
  pressaoTemperatura  = new PressaoTemperatura();
  aceleracao            = new Aceleracao();

}

void loop() {

  /*Leitura analógica e/ou digital de cada sensor.*/
  leitura(luminosidade);
  //leitura(qualidadeDoAr);
  leitura(pressaoTemperatura);
  leitura(aceleracao);

  /* Calcular medida,
     especificar unidade
     detalhar informações adicionais do ambiente
  */
  construirInformacoes(luminosidade);
  //construirInformacoes(qualidadeDoAr);
  construirInformacoes(pressaoTemperatura);
  construirInformacoes(aceleracao);
  
  /*
     Gerar String formatada para a biblioteca MySQL inserir no banco de dados.
  */
  gerenciarQuery(luminosidade);
  //gerenciarQuery(qualidadeDoAr);
  gerenciarQuery(pressaoTemperatura);
  gerenciarQuery(aceleracao);
  
  delay(1000);
  
}

void leitura(Sensor * sensor) {
  sensor->leituraSensor();
}

void construirInformacoes(Sensor * sensor) {
  sensor->construirInformacoes();
}

void gerenciarQuery(Sensor * sensor) {
  sensor->construirQuery();
}


