#include <Adafruit_NeoPixel.h>

#define P 0x000000//PRETO
#define Z 0x0000FF//AZUL
#define E 0x008000//VERDE
#define R 0x800080//ROXO
#define V         0xFF0000//VERMELLHO
#define L         0xFFA500//LARANJA
#define R 0xFFC0CB//ROSE
#define A 0xFFFF00//AMARELO
#define B 0xFFFFFF//BRANCO


#define PIN 4// Pino de controle
#define LED_COUNT 60// Quantidade de LED's
//Cria uma instância da Classe Adafruit NeoPixel chamado "leds"
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

unsigned long time;//Contará o tempo
unsigned long timeout;//Estouro
int brilho[3];//Recebe os valores da serial
int i=0;//Quantidade de caracteres recebida pela serial
int posicao=0;
int flag=0;//Indica que foi recebida informação pela serial
char temp,cor;//Armazena dados recebidos pela serial


void setup()
{
  Serial.begin(9600);//Inicia a serial com baud rate
  leds.begin(); // Inicia a fita de LED
  clearLEDs();   // Apaga todos os LEDs
  leds.show(); // Atualiza o estados dos LEDs
 
  
}


void loop()
{
  //------------------------------------------------------------------------------------------
  // Retorna o tempo em milisegundos desde que o Arduíno começou a rodar,
  time = millis()%2;//Divide por 2 e salva o resto
  if(time==1||time==0)//Compara se o resto é igual a 0 ou 1 e sempre vai ser
  {
  timeout++;// Cronômetro
    if (timeout>500)// Compara se houve estouro do tempo
    {
    i=0;// Zera o quantidades de caracteres recebidos
    flag=0;// Zera o aviso de que foi recebido algum dado na serial
    }  
   }
 
  //-------------------------------------------------------------------------------------------
  

  //--------------------------------------------------------------------------------------------
  if (Serial.available()>0)// Verifica se houve recepção
  {
    flag=1;//Sinaliza que houve recepção
    timeout=0;// Zera o o tempo de reset
    //------------------------------------------------------------------------------------------
    temp = Serial.read();// Armazena o que foi recebido pela serial
    
    brilho[i]=temp-48;// Decrementa 48 na tabela ascii para converter de decimal para char
    i++;// Contabiliza um recebimento
  }
   //---------------------------------------------------------------------------
if (timeout>200&&flag==1)// Compara se houve estouro do timeout(se ficou um tempo sem recepção) e se houve recepção
{
  flag=0;// Sera aviso de recepção
  

   // Envia para serial informações em % e resolução de disparo
    posicao=brilho[0];
    cor= brilho[1]+ 48;
   
    switch (cor)
    {
    case 'Z'://AZUL
      leds.setPixelColor(posicao,Z);//Aciona o LED requerido
      leds.show();//Atualiza o LED
    break;
    
     case 'E'://VERDE
    leds.setPixelColor(posicao,E);//Aciona o LED requerido
    leds.show();//Atualiza o LED
    break;
    
     case 'V'://VERMELHO
    leds.setPixelColor(posicao,V);//Aciona o LED requerido
    leds.show();//Atualiza o LED
    break;
    
     case 'A'://AMARELO
    leds.setPixelColor(posicao,A);//Aciona o LED requerido
    leds.show();//Atualiza o LED
    break;
    
     case 'B'://BRANCO
    leds.setPixelColor(posicao,B);//Aciona o LED requerido
    leds.show();//Atualiza o LED
    break;
    
    case 'P'://APAGA
    leds.setPixelColor(posicao,0);//Aciona o LED requerido
    leds.show();//Atualiza o LED
    break;
    }
}
}


//Função liga led individual
void ligaLED(int g, unsigned long fita)//Recebe a posição e tempo de Delay
{
leds.setPixelColor(g, fita);//Aciona o LED requerido
 leds.show();//Atualiza o LED
}



//Função apaga LED individual
void apagaLED(int g, unsigned long fita)//Recebe a posição e tempo de Delay
{
leds.setPixelColor(g, 0);//Desaciona o LED requerido
 leds.show();//Atualiza o LED
}

//Função apaga LEDs geral
void clearLEDs()
{
  for (int p=0; p<LED_COUNT; p++)
  {
    leds.setPixelColor(p, 0);
    leds.show();
  }
}
