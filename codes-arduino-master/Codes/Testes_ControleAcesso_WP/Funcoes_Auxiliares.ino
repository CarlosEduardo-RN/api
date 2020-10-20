//-----------------------------------------------------------------------------------------------------

//BUZZER

//-----------------------------------------------------------------------------------------------------

//Função usada para acionar buzzer
void AcionaBuzzer(int _intQnt, int _intTempo_milisegHIGH, int _intTempo_milisegLOW)
{
  //Buzzer
  for (byte i=0; i<_intQnt; i++)
  {
    //Ativa
    digitalWrite(PIN_BUZZER, HIGH);  

    //Delay
    delay(_intTempo_milisegHIGH);  

    //Desativa
    digitalWrite(PIN_BUZZER, LOW);
   
    //Delay
    delay(_intTempo_milisegLOW); 
  }
}

//-----------------------------------------------------------------------------------------------------

//FUNÇÕES PARA USO DE ARRAY DE CHAR

//-----------------------------------------------------------------------------------------------------

//Função usada para contar tamanho do array da char
byte charTam(char str[])
{
  //Variáveis
  byte tam;

  //Contando tamanho
  for (tam=0; str[tam]!='\0'; tam++);   

  //Retorno
  return tam;
}

//-----------------------------------------------------------------------------------------------------

//Função usada para verificar se dois arrays de char são iguais
bool charIgual(char str1[], char str2[])
{  
  //Comparando tamanho de dados
  if (charTam(str1) != charTam(str2))  return false;

  //Procurando diferenças
  for (int i=0; str1[i]!='\0'; i++)
  {
    //Comparando caracteres
    if (str1[i]!=str2[i]) return false;
  }

  //Palavras iguais
  return true;
}

//-----------------------------------------------------------------------------------------------------

//Função usada para transformar as contantes RFID de string para char
void charConstRFID(String str1, String str2)
{
  //Transformando
  for (byte i=0; i<8; i++)
  {
    CARTAO_ADD[i] = str1[i];
    CARTAO_DEL[i] = str2[i];  
  }

  //Caracter de finalização
  CARTAO_ADD[8] = '\0'; 
  CARTAO_DEL[8] = '\0'; 
}

//-----------------------------------------------------------------------------------------------------

//RESETAR

//-----------------------------------------------------------------------------------------------------

//Função usada para reiniciar o código
void software_Reset() 
{
  asm volatile ("  jmp 0");  
}

