//---------------------------------------------------------------
//PROTÓTIPOS DE FUNÇÕES
//---------------------------------------------------------------

//Principais
void setup();
void loop();

//Reset
void software_Reset();

//Serial
void serialEvent();
void iniciaSerial(int Velocidade);
void trataDadosRecebidosSerial();

//JSON
void criarJSON();

//EEPROM
void   escreveInt(int endereco1, int endereco2, int valor);
int    lerInt(int endereco1, int endereco2);
void   escreveString(int enderecoBase, String mensagem);
String leString(int enderecoBase);

//Threads
void configuraThreads();
void processaThreads();

//---------------------------------------------------------------
//VARIÁVEIS GLOBAIS
//---------------------------------------------------------------

float gbCurrent = 0;
float gbVoltage = 0;

//---------------------------------------------------------------
//CONSTANTES
//---------------------------------------------------------------

#define BDRT_SERIAL    19200
#define END1_REMOTA        1
#define END2_REMOTA        2
#define END_NOME_REM       3
#define NUM_CHARS_RX     200
#define JSON_BYTES       200
#define THREAD_SERIAL      1
#define THREAD_CURRENT  1000
#define THREAD_VOLTAGE  1500

//---------------------------------------------------------------
//FUNÇÕES PRINCIPAIS
//---------------------------------------------------------------

//Função Setup usada para configurações iniciais
void setup() 
{
  //Iniciando serial
  iniciaSerial(BDRT_SERIAL);

  //Configurando threads
  configuraThreads();

  //RETIRAR
  randomSeed(analogRead(0));
}

//---------------------------------------------------------------

//Função loop usada para processamento, loop eterno 
void loop() 
{
  //Inicia threads
  processaThreads();
}

//---------------------------------------------------------------
//RESET
//---------------------------------------------------------------

//Procedimento usado para resetar código
void software_Reset() 
{
  //Voltando para a primeira linha de código
  asm volatile ("  jmp 0");  
} 
