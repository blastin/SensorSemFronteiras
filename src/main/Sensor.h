
#ifndef SENSOR_CLASSE_H
#define SENSOR_CLASSE_H

#include <Arduino.h>
#include "./MySQL_Sensores.h"

class Sensor {

  public:

    explicit
    Sensor(int porta) {
      this->porta = porta;
    }
    
    virtual void medir() = 0;

    void construirQuery();

    void insertMySql(MySQL_Connection& connector);
    
    void setLeitura(int leitura) {
      this->leitura = leitura;
    }

  private:
  
    int porta;
    String query;

  protected:
    
    int   leitura;
    float medida;
    String nomeTabela;
    String nomeSensor;
    String unidadeMedida;
    String qualidade;
    
};

#endif



