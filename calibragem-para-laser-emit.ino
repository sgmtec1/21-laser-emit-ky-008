//Open Source
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int laser = 2; // Declaração do pino conectado ao módulo LASER (Porta Digital 3);
int ldr = A0;  // Declaração do pino conectado ao LDR (Porta analógica A0)
int valor = 0; //Variável que irá armazenar a leitura analógica do LDR

void setup() {
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  pinMode(laser, OUTPUT); // Declaração do módulo laser como saída.
  Serial.begin(9600);
}

void loop() {

  digitalWrite(laser, HIGH); // ativando o módulo laser
  valor = analogRead(ldr); //  leitura do LDR
  Serial.println(valor); // Printa os valores da leitura
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("VALOR CALIBRADO:"); //IMPRIME O TEXTO NO DISPLAY LCD
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print(valor); //IMPRIME O TEXTO NO DISPLAY LCD
  delay(5000);    
  lcd.clear();
}
