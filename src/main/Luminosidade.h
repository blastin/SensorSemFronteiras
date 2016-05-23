
#ifndef SENSOR_LUMINOSIDADE_CLASSE_H
#define SENSOR_LUMINOSIDADE_CLASSE_H

#include "Sensor.h"

class Luminosidade: public Sensor {

  public:

    Luminosidade(int porta, String nomeTabela) :
      Sensor(porta) {

      this->nomeTabela = nomeTabela;
      nomeSensor = "Sensor de luminosidade ambiente";

    }
    
    void medir();

};

#endif



