#define pinSensorA A0
#define pinSensorD 8
//Variavel para armazenar valor de umidade
int umidade;
// variavel para controlar valor do botão ligado = 1 e desligado = 0
int botao = 0;
// variavel que verificar se o programa está ligado ou desligado
bool ligado=false;

void setup()
{
  // iniciando botões e leds com a portas do arduino e comandos de entrada
    pinMode(pinSensorD, INPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(8, INPUT);
    Serial.begin(9600);
}

void loop() {

  if(digitalRead(8))// if verificador para saber se o botão foi apertado
  {
    ligado=true;
    Serial.println("Ligado");
  }
 
  if (!ligado) // if verificador mostrado antes de ser apertado o botão
  {
    Serial.println("Desligado");
    delay(1000);
    return;
  }
 
Serial.print("Status: "); // mostra o status

if (analogRead(pinSensorA) > 450) // lê a umidade de printa na tela através do código abaixo:
{
    digitalWrite(5, HIGH); // liga o led verde
    digitalWrite(6, LOW); // desliga o led vermelho
    Serial.print("SEM UMIDADE   "); // mostra que o solo está sem umidade
    Serial.print(" Atuador: "); // mostra o atuador
    Serial.print("SOLENOIDE LIGADO     "); // mostra que o solenoide está ligado 
    //digitalWrite(pinSolenoide, HIGH);
}

else { //Caso a umidade esteja baixa é feito está parte do código; 
    Serial.print("COM UMIDADE   "); // mostra que o solo já apresenta umidade
    digitalWrite(5, LOW); // desliga o led verde
    digitalWrite(6, HIGH); // liga o led vermelho
    Serial.print(" Atuador: ");
    Serial.print("SOLENOIDE DESLIGADO   "); // printa que o solenoide está desligado
    //digitalWrite(pinSolenoide, LOW);
}

  Serial.print(" Porcentagem: "); // printa a porcetangem 
  umidade = analogRead(pinSensorA); // adiciona o valor de umidade para o sensor 
  umidade = map(umidade, 1023, 0, 0, 100); // realiza um map do valor da umidade 
  Serial.print(umidade); // mostra o valor de umidade
  Serial.println(" % "); // coloca em porcentagem

  delay(4000);
}
