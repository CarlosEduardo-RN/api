//-----------------------------------------------------------------------------------------------------

//BIBLIOTECAS

//-----------------------------------------------------------------------------------------------------

#include <Thread.h>
#include <ThreadController.h>
#include <MFRC522.h>
#include <EEPROMex.h>

//-----------------------------------------------------------------------------------------------------

//DEFINIÇÕES

//-----------------------------------------------------------------------------------------------------

//Pinos
#define PIN_BTN     6
#define PIN_RELE    7
#define PIN_BUZZER  8
#define RST_PIN     9 
#define SS_PIN     10

//Tamanho dado
#define TAM_CRED 8

//Tempo threads
#define tempoVerificaSerial         2
#define TIME_REFRESH_LEITURA     1500
#define TIME_ACIONAMENTO         5000

//-----------------------------------------------------------------------------------------------------

//VARIÁVEIS GLOBAIS

//-----------------------------------------------------------------------------------------------------

//Threads
ThreadController controle  = ThreadController();
Thread           *LeSerial = new Thread();

//RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

//Cartões
String STR_CARTAO_ADD = "DD641B76";
String STR_CARTAO_DEL = "FD62FC75"; 
bool   boolAcrescenta = false;
bool   boolDeleta     = false;
char   CARTAO_ADD[9], CARTAO_DEL[9];
byte   valorContEEPROM;

//-----------------------------------------------------------------------------------------------------

//SETUP

//-----------------------------------------------------------------------------------------------------

//Função para configuração inicial
void setup() 
{  
  //Iniciando porta serial a 19200
  Serial.begin(19200); 

  //Iniciando comunicação SPI
  SPI.begin(); 
  
  //Iniciando MFRC522
  mfrc522.PCD_Init();
    
  //Define o pino 9 como saída
  pinMode(PIN_BTN,    OUTPUT);
  digitalWrite(PIN_BTN, HIGH);
  pinMode(PIN_RELE,   OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  //Inicia rele
  setup_Rele();

  //Threads
    //Adicionando threads ao controle de threads
    controle.add(LeSerial);

    //Configuração da thread de leitura da serial
    LeSerial->onRun(thread_leSerial);
    LeSerial->setInterval(tempoVerificaSerial);

  //Constantes RFID
  charConstRFID(STR_CARTAO_ADD, STR_CARTAO_DEL); 
}

//-----------------------------------------------------------------------------------------------------

//LOOP

//-----------------------------------------------------------------------------------------------------

//Função principal do programa
void loop() 
{
  //Iniciando a thread de controle (thread busca_remotas embarcada)
  controle.run();   

  //Leitura do cartão
  loop_RFID();

  //Botoeira
  loop_Btn();
}
