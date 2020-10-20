//-----------------------------------------------------------------------------------------------------

//FUNÇÕES EEPROM

//-----------------------------------------------------------------------------------------------------

//Função usada para verificar a existência de uma credencial na EEPROM
int verificaCredencial(char strCred[])
{
  //Variáveis 
  byte tam = charTam(strCred);
  char strAux[]      = "00000000";
  char strCredRead[] = "        ";   

  //---------------------------------------------------------------------------------------------------

  //Completando com zeros a esquerda
  for (byte i=0; i<tam; i++) strAux[TAM_CRED-tam+i] = strCred[i];
  
  //Mostrando dados
  for (int i=0; i<512; i=i+TAM_CRED)
  {
    //Lendo EEPROM
    EEPROM.readBlock<char>(i, strCredRead, TAM_CRED); 

    //Achou ocorrência, retorna posição
    if (charIgual(strCredRead, strAux)) return i;
  }

  //Retorna posição -1 (Inválida)
  return -1;
}

//-----------------------------------------------------------------------------------------------------

//Função usada para verificar a existência de uma espaço vazio para nova credencial na EEPROM
int verificaEspacoParaCredencial()
{
  //Variáveis
  char strCredRead[] = "        "; 

  //---------------------------------------------------------------------------------------------------

  //Mostrando dados
  for (int i=0; i<512; i=i+TAM_CRED)
  {
    //Lendo EEPROM
    EEPROM.readBlock<char>(i, strCredRead, TAM_CRED); 

    //Achou ocorrência, retorna posição
    if (charIgual(strCredRead, "")) return i;
  }

  //Retorna posição -1 (Inválida)
  return -1;
}

//-----------------------------------------------------------------------------------------------------

//Função usada para adicionar dados na EEPROM
void adicionaCredencialEEPROM(char strCred[])
{ 
  //Variáveis
  byte tam = charTam(strCred);
  char strAux[] = "00000000";

  //---------------------------------------------------------------------------------------------------

  //Verificando se existe local para salvar
  if (verificaEspacoParaCredencial() == -1)
  {
    //Mensagem
    Serial.println("Não há espaço!");

    //Buzzer
    AcionaBuzzer(3, 3000, 3000);

    //Saindo da função
    return;
  }
  
  //Completando com zeros a esquerda
  for (byte i=0; i<tam; i++) strAux[TAM_CRED-tam+i] = strCred[i];
   
  //Escrevendo credencial do tipo LONG na EEPROM
  EEPROM.writeBlock<char>(verificaEspacoParaCredencial(), strAux, TAM_CRED);  

  //Buzzer de adicição
  AcionaBuzzer(1, 1000, 500);
  AcionaBuzzer(1,   50,  50);
}

//-----------------------------------------------------------------------------------------------------

//Função usada para deletar dados na EEPROM
void deletaCredencialEEPROM(char strCred[])
{
  //Lendo EEPROM
  EEPROM.writeBlock<char>(verificaCredencial(strCred), "", TAM_CRED); 

  //Buzzer de deletando
  AcionaBuzzer(3, 500, 500);
}

//-----------------------------------------------------------------------------------------------------

//Função usada para mostrar a contagem da EEPROM
byte contagemEEPROM()
{
  //Variáveis 
  byte cont          = 0;
  char strCredRead[] = "        ";

  //---------------------------------------------------------------------------------------------------

  //Mostrando dados
  for (int i=0; i<512; i=i+TAM_CRED)
  {
    //Leitura EEPROM
    EEPROM.readBlock<char>(i, strCredRead, TAM_CRED); 

    //Contagem
    if (charTam(strCredRead) != 0) cont++;
  }

  //Retona contagem
  return cont;
}

//-----------------------------------------------------------------------------------------------------

//Função usada para limpar a EEPROM 
void limpaEEPROM()
{
  //Zerando valores da EEPROM
  for(int i=0; i<512; i++) EEPROM.write(i, 0); 
}

//-----------------------------------------------------------------------------------------------------

//Função usada para mostrar todos os dados gravados na EEPROM
void mostraEEPROM()
{
  //Variáveis 
  char strCredRead[] = "        ";

  //---------------------------------------------------------------------------------------------------

  //Mostrando dados
  for (int i=0; i<512; i=i+TAM_CRED)
  {
    EEPROM.readBlock<char>(i, strCredRead, TAM_CRED); 
    Serial.println("[" + String(i) + "] = " + strCredRead);
  }
}
