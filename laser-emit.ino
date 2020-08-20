// Open Source
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int laser = 2; // Declaração do pino conectado ao módulo LASER (Porta Digital 3);
int ldr = A0;  // Declaração do pino conectado ao LDR (Porta analógica A0)
int led = 3; // &quot; &quot; &quot; ao LED (Porta digital 2)
int valor  = 0; // Variável que irá armazenar a leitura analógica do LDR
int buzzer = 4;

void setup() {
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  pinMode(laser, OUTPUT); // Declaração do módulo laser como saída.
  pinMode(led, OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
digitalWrite(laser, HIGH); // ativando o módulo laser
valor = analogRead(ldr); //  leitura do LDR

 if( valor >= 100) // valor lido no primeiro código de calibragem
 {
  digitalWrite(led, HIGH); //Acende o LED
  delay(500);
  digitalWrite(led, LOW); // Apaga o LED
  Serial.println("ALARME DISPARADO");
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("ALARME DISPARADO"); //IMPRIME O TEXTO NO DISPLAY LCD
  // Aciona o buzzer na frequencia relativa ao Dó em Hz
  tone(buzzer,261);    
  // Espera um tempo para Desativar
  delay(200);
  //Desativa o buzzer
  noTone(buzzer); 
  // Aciona o buzzer na frequencia relativa ao Ré em Hz   
  tone(buzzer,293);             
  delay(200);    
  noTone(buzzer); 
  // Aciona o buzzer na frequencia relativa ao Mi em Hz
  tone(buzzer,329);      
  delay(200);
  noTone(buzzer);     
  // Aciona o buzzer na frequencia relativa ao Fá em Hz
  tone(buzzer,349);    
  delay(200);    
  noTone(buzzer); 
  // Aciona o buzzer na frequencia relativa ao Sol em Hz
  tone(buzzer,392);            
  delay(200);
  noTone(buzzer);
}

else{
  digitalWrite(led, HIGH); //LED acende, caso nada tenha acontecido,e  fica aceso constantemente até mude
  Serial.println("ALARME ARMADO");
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("ALARME ARMADO"); //IMPRIME O TEXTO NO DISPLAY LCD
}
}
