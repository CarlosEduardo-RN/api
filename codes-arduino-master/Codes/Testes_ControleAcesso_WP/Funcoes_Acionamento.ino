//-----------------------------------------------------------------------------------------------------

//FUNÇÕES ACIONAMENTO

//-----------------------------------------------------------------------------------------------------

//Função usada para configurar o rele
void setup_Rele()
{
  //Desliga rele
  digitalWrite(PIN_RELE, HIGH);
}

//-----------------------------------------------------------------------------------------------------

//Função usada para ligar/temporalizar/desligar o rele
void acionamento_Rele()
{
  //Liga rele
  digitalWrite(PIN_RELE, LOW);  
  
  //Atraso
  delay(TIME_ACIONAMENTO);

  //Desliga rele
  digitalWrite(PIN_RELE, HIGH);
}

//-----------------------------------------------------------------------------------------------------

//Função usada pela botoeira para ligar/temporalizar/desligar o rele
void loop_Btn()
{
  //Botão nível alto
  if (!digitalRead(PIN_BTN))
  {
    //Debouncer
    while(!digitalRead(PIN_BTN)) delay(100);
  
    //Aciona porta
    acionamento_Rele();
  } 
}
