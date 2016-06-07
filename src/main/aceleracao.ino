#include <AcceleroMMA7361.h>
#include <math.h>

AcceleroMMA7361 accelero;
float x, y, z, media;
float xantigo, yantigo, zantigo;

void setup()  {
  Serial.begin(9600);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);
  accelero.setSensitivity(LOW);
  accelero.calibrate();

  calcular(xantigo, yantigo, zantigo);

  Serial.println("Aceleracao(i,j,k) => Variacao(i,j,k)\n");
  
}

void loop()  {

  calcular(x, y, z);

   Serial.print("Aceleracao(i,j,k) => Variacao(");
   
   if ( fabs(x - xantigo) > 7 ) {
        Serial.print("i");
         xantigo = x;
   }
   Serial.print(",");
   if ( fabs(y - yantigo) > 7 ) {
        Serial.print("j");
        yantigo = y;
   }
   Serial.print(",");
   if ( fabs(z - zantigo) > 7 ) {
        Serial.print("k");
        zantigo = z;
   }
   
  Serial.println(")");
  delay (500); 
}


inline
void calcular(float &vetor_i, float& vetor_j, float& vetor_k) {

  vetor_i = accelero.getXAccel(); //Obtem o valor do eixo X
  vetor_j = accelero.getYAccel(); //Obtem o valor do eixo Y
  vetor_k = accelero.getZAccel(); //Obtem o valor do eixo Z

}
