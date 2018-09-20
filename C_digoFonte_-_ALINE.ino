/*Declaração das portas de 
saída para o DEMUX*/
byte demuxA = 2;
byte demuxB = 3;
byte demuxC = 4;
byte demuxD = 5;
String historico="";
byte npisca = 3;

void setup() {
  /*Configuração das portas
   * de saída para o DEMUX */
   pinMode(demuxA, OUTPUT);
   pinMode(demuxB, OUTPUT);
   pinMode(demuxC, OUTPUT);
   pinMode(demuxD, OUTPUT);
   //Estabelece comunicação serial
   Serial.begin(9600);
   //Apaga todos os LEDs
   digitalWrite(demuxD, HIGH);
}

void loop() {
  char z;
  /*Recebe o identificador requisitado
   * pelo app   */
   z=Serial.read();
   if(z=='A') demux( LOW, LOW, LOW);
   if(z=='B') demux( LOW, LOW, HIGH);
   if(z=='C') demux( LOW, HIGH, LOW);
   if(z=='D') demux( LOW, HIGH, HIGH);
   if(z=='E') demux( HIGH, LOW, LOW);
   if(z=='F') demux( HIGH, LOW, HIGH);
   if(z=='G') demux( HIGH, HIGH, LOW);
   if(z=='H') demux( HIGH, HIGH, HIGH);
   if(z=='h') Serial.println(historico);
   /*Armazena no histórico todas as
    * requisições   */
   historico.concat(z);
   historico.concat(' ');
}

void demux(bool c, bool b, bool a){
  /*Envia a configuração requisitada
   * para o DEMUX   */
  for(int i=0;i<npisca;i++){ //Piscar LEDs
    digitalWrite(demuxD, LOW);
    digitalWrite(demuxC, c);
    digitalWrite(demuxB, b);
    digitalWrite(demuxA, a);
    delay(500);
    digitalWrite(demuxD, HIGH);
    digitalWrite(demuxC, LOW);
    digitalWrite(demuxB, LOW);
    digitalWrite(demuxA, LOW);
    delay(500);
  }
  delay(1000);
}

