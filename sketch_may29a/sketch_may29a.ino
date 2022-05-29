// inclui a biblioteca:


// variáveis do programa
const int pinoSensor = A0;
const int pinoValvula = 10;
const int limiarSeco = 74;
const int tempoRega = 50; // Tempo de rega em segundos
int umidadeSolo = 0;

void setup() {
  
  pinMode(pinoValvula, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Desliga a válvula
  digitalWrite(pinoValvula, HIGH);
  // Exibe a mensagem:
  Serial.print(" Rega ");

  Serial.begin(9600);


}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); //Liga led azul indicando que está em standBy
  // Mede a umidade a cada segundo. Faz isso durante uma hora (3600 segundos).
  for(int i=0; i < 5; i++) {
    // Exibe a mensagem:
    Serial.print("Umidade: ");
    // Faz a leitura do sensor de umidade do solo
    umidadeSolo = analogRead(pinoSensor);
    // Converte a variação do sensor de 0 a 1023 para 0 a 100
    umidadeSolo = map(umidadeSolo, 1023, 0, 0, 100);
    // Exibe a mensagem no Display LCD:
    Serial.print(umidadeSolo);
    Serial.print(" %    ");
    // Espera um segundo
    delay(1000);
  }
    //Confere umidade do solo para iniciar a rega
  if(umidadeSolo < limiarSeco) {
    digitalWrite(LED_BUILTIN, LOW);    //Desliga o Led azul para tirar do standBy
    digitalWrite(LED_BUILTIN, HIGH);   // liga o led verde mostrando que está sendo regado 
    delay(1000);                       // Espera um segundo
    Serial.println("Solo está sendo regado") //
    // Liga a válvula
    digitalWrite(pinoValvula, LOW);
    // Espera o tempo estipulado
    delay(tempoRega*1000);
    digitalWrite(pinoValvula, HIGH);
      }
  else {
    digitalWrite(LED_BUILTIN, LOW);    //Desliga o Led azul para tirar do standBy
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH); //Liga o led Vermelho indicado o término do regamento
    // Exibe a mensagem no Display LCD:
    Serial.println("Solo Encharcado ");
    // Espera o tempo estipulado
    delay(3000);
    digitalWrite(LED_BUILTIN, HIGH); //Desliga Led Vermelho
  }
}
