#define pinSensorA A0
#define pinSensorD 8
int umidade;
int botao = 0;
int solenoide = 9;
bool ligado=false;

void setup()
{
    pinMode(pinSensorD, INPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(8, INPUT);
    pinMode(9, OUTPUT);
    Serial.begin(9600);
}

void loop() {

  if(digitalRead(8))
  {
    ligado=true;
    Serial.println("Ligado");
  }
 
  if (!ligado)
  {
    Serial.println("Desligado");
    delay(1000);
    return;
  }
 
Serial.print("Status: ");

if (analogRead(pinSensorA) > 290)
{
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(solenoide, HIGH);
    Serial.print("SEM UMIDADE   ");
    Serial.print(" Atuador: ");
    Serial.print("SOLENOIDE LIGADO     ");
}

else {
    Serial.print("COM UMIDADE   ");
    digitalWrite(solenoide, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    Serial.print(" Atuador: ");
    Serial.print("SOLENOIDE DESLIGADO   ");
    
}

  Serial.print(" Porcentagem: ");
  umidade = analogRead(pinSensorA);
  umidade = map(umidade, 1023, 0, 0, 100);
  Serial.print(umidade);
  Serial.println(" % ");

  delay(4000);
}