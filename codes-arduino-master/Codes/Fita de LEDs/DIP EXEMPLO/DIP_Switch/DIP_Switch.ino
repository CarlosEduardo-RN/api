//-----------------------------------------------------------------------------------------------------

//BIBLIOTECAS

//-----------------------------------------------------------------------------------------------------

#include <Thread.h>
#include <ThreadController.h>
#include <FastLED.h>

//-----------------------------------------------------------------------------------------------------

//DEFINIÇÕES

//-----------------------------------------------------------------------------------------------------

//Pinos
#define DIP_1   11
#define DIP_2   10
#define DIP_3    9
#define ALTO     A1
#define BAIXO    A0
#define LED_PIN  3

//-----------------------------------------------------------------------------------------------------

//VARIÁVEIS GLOBAIS

//-----------------------------------------------------------------------------------------------------

//Threads
ThreadController controle  = ThreadController();
Thread           *LeSerial = new Thread();

//Declarando variáveis globais
int config   = 0;
int fc_alto  = 0;
int fc_baixo = 0;
int rdAux    = 0;

//Tempo threads
#define tempoVerificaSerial 2

//Fita de LEDs
#define NUM_LEDS    19
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 100

CRGB          leds[NUM_LEDS];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern       CRGBPalette16     myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

//-----------------------------------------------------------------------------------------------------

//SETUP

//-----------------------------------------------------------------------------------------------------

//Procedimento usado para configuração
void setup() 
{
  //Iniciando porta serial a 19200
  Serial.begin(19200); 
  
  //Definição de pinos
  pinMode(DIP_1, INPUT_PULLUP);
  pinMode(DIP_2, INPUT_PULLUP);
  pinMode(DIP_3, INPUT_PULLUP);
  //pinMode(ALTO,  INPUT_PULLUP);
  //pinMode(BAIXO, INPUT_PULLUP);

  //Threads
    //Adicionando threads ao controle de threads
    controle.add(LeSerial);

    //Configuração da thread de leitura da serial
    LeSerial->onRun(thread_leSerial);
    LeSerial->setInterval(tempoVerificaSerial);

  //LEDS
  delay(1000); 
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
  currentPalette  = RainbowColors_p;
  currentBlending = LINEARBLEND;
}

//-----------------------------------------------------------------------------------------------------

//LOOP

//-----------------------------------------------------------------------------------------------------

//Procedimento usado para execução
void loop() 
{    
  //Iniciando a thread de controle (thread busca_remotas embarcada)
  controle.run();  

  //Status do DIP Switch
  config = bin2int(3, 11, 10, 9);

  //Fim de curso
  fc_alto  = analogRead(ALTO);
  fc_baixo = analogRead(BAIXO);

  

  if ((fc_alto > 50) and (fc_baixo > 50))
  {
    if (fc_baixo > rdAux)
    {
      sinelon(150);
      Serial.println("Meio - Subindo");  
    }
    
    if (fc_alto < rdAux)
    {
      sinelon(100);
      Serial.println("Meio - Baixando");    
    }
  }
  else
  {
    if (fc_alto <= 50)
    {
      //Leitura atual
      rdAux = 1023;
      
      sinelon(200);
      Serial.println("Alto");
    }
  
    if (fc_baixo <= 50)
    {
      //Leitura atual
      rdAux = 0; 
   
      sinelon(50);
      Serial.println("Baixo");
    }  
  }
  
    //Escolhendo efeito
    //escolheEfeito(config);

    //static uint8_t startIndex = 0;
    //startIndex  = startIndex + 1; /* motion speed */
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}
