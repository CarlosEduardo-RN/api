//---------------------------------------------------------------
//BIBLIOTECAS
//---------------------------------------------------------------

#include <Thread.h>
#include <ThreadController.h>

//---------------------------------------------------------------
//PROTÓTIPO DE FUNÇÕES
//---------------------------------------------------------------

void recebeCurrent();
void recebeVoltage();

//---------------------------------------------------------------
//VARIÁVEIS GLOBAIS
//---------------------------------------------------------------

//Controlador de threads
ThreadController controll = ThreadController();

//Thread serial
Thread* threadSerial = new Thread();

//Threads sensores
Thread* threadSensorCurrent = new Thread();                      //Corrente
Thread* threadSensorVoltage = new Thread();                      //Tensão

//---------------------------------------------------------------
//FUNÇÕES
//---------------------------------------------------------------

//Procedimento usado para configurar threads
void configuraThreads()
{
  //Mensagem
  Serial.println("Configurando threads...");  

  //Thread serial
  threadSerial->onRun(trataDadosRecebidosSerial);
  threadSerial->setInterval(THREAD_SERIAL);

  //Thread corrente
  threadSensorCurrent->onRun(recebeCurrent);
  threadSensorCurrent->setInterval(THREAD_CURRENT);

  //Thread tensão
  threadSensorVoltage->onRun(recebeVoltage);
  threadSensorVoltage->setInterval(THREAD_VOLTAGE);

  //-------------------------------------------------------------

  //Adicionando threads ao controlador
  controll.add(threadSerial);
  controll.add(threadSensorCurrent);
  controll.add(threadSensorVoltage);
}

//---------------------------------------------------------------

//Procedimento usado para processar threads
void processaThreads()
{
  //Verifica todas as threads do controlador de threads
  controll.run();
}

//---------------------------------------------------------------

//Função usada na thread para receber dado de corrente
void recebeCurrent()
{ 
  //Pegando dado de corrente
  gbCurrent = random(0, 1000)/100.0; 
}

//---------------------------------------------------------------

//Função usada na thread para receber dado de tensão
void recebeVoltage()
{
  //Pegando dado de tensão
  gbVoltage = random(21000, 25000)/100.0; 
}
