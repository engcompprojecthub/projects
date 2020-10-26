///////////////////////////////////////////////////////////////////
//      @file Jack_O_Lantern.ino                                 //
//      @brief Halloween => Photoresistor LED Controller         //
//      @author Lucas Lopes - @engcompprojecthub                 // 
//      @date 25/10/2020                                         // 
///////////////////////////////////////////////////////////////////
#define pinoLED5 5
#define pinoLED6 6
#define pinoLED7 7


int leitura = 0;

float vLDR, vR, i, resLDR;

void setup() {
  pinMode(A0, INPUT); 
  pinMode(pinoLED7, OUTPUT);
  pinMode(pinoLED6, OUTPUT);
  pinMode(pinoLED5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  leitura = analogRead(A0);
  vR = leitura * 0.0048828125;
  vLDR = 5 - vR;
  i = vR / 10; 
  resLDR = vLDR / i;
  
  //Variavel leitura (0 a 1023) => 1024 valores
  Serial.print("A0: ");
  Serial.print(leitura);

  //Tensão no resistor de 10k ohms (volts)
  Serial.print("\t\t");
  Serial.print("R 10kΩ: ");
  Serial.print(vR, 5);
  Serial.print(" V");

  //Tensão no LDR (volts)
  Serial.print("\t\t");
  Serial.print("LDR: ");
  Serial.print(vLDR, 5);
  Serial.print(" V");

  //Resistência no LDR (kilo ohms)
  Serial.print("\t\t");
  Serial.print("resLDR: ");
  Serial.print(resLDR, 5);
  Serial.print(" kΩ");

  //Corrente no LDR e resistor 10k (mA)
  Serial.print("\t\t");
  Serial.print("i = ");
  Serial.print(i, 5);
  Serial.println(" mA");
  
  if(leitura < 80){
    digitalWrite(pinoLED7, HIGH);
    digitalWrite(pinoLED6, HIGH);
    digitalWrite(pinoLED5, HIGH);
  }
  else {
    digitalWrite(pinoLED7, LOW);
    digitalWrite(pinoLED6, LOW);
    digitalWrite(pinoLED5, LOW);
  }
  delay(100);
}
