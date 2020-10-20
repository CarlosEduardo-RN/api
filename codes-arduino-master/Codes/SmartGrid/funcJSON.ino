//---------------------------------------------------------------
//BIBLIOTECAS
//---------------------------------------------------------------

#include <ArduinoJson.h>

//---------------------------------------------------------------
//FUNÇÕES
//---------------------------------------------------------------

//Procedimento usado para criar JSON
void criarJSON()
{
  //Variáveis locais
  StaticJsonBuffer<JSON_BYTES> jsonSmartGrid;

  //-------------------------------------------------------------

  //Criando objeto JSON
  JsonObject& root = jsonSmartGrid.createObject();

  //Adicionando dados
  root["remota"]  = lerInt(END1_REMOTA, END2_REMOTA);
  root["nome"]    = leString(END_NOME_REM);
  root["current"] = gbCurrent;
  root["voltage"] = gbVoltage;
  root["power"]   = gbCurrent * gbVoltage;

  //Formas de printar
  #ifdef PRETTY
    root.prettyPrintTo(Serial);
  #endif

  //Mostrando dados do JSON
  #ifndef PRETTY
    root.printTo(Serial);
  #endif
}
