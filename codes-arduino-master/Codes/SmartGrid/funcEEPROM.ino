//---------------------------------------------------------------
//BIBLIOTECAS
//---------------------------------------------------------------

#include <EEPROM.h>

//---------------------------------------------------------------
//FUNÇÕES
//---------------------------------------------------------------

//Procedimento usado para escrever inteiro de 2 bytes na EEPROM
void escreveInt(int endereco1, int endereco2, int valor)
{
  //Variáveis locais inicializadas
  int valorAtual = lerInt(endereco1, endereco2); 

  //-------------------------------------------------------------

  //Testa valor
  if (valorAtual == valor)
  { 
    //Retorna valor redundante
    return;
  }
  else
  { 
    //Variáveis locais 
    byte primeiroByte = valor & 0xff;                            //Máscara com 1111 1111
    byte segundoByte  = (valor >> 8) & 0xff;                     //Máscara com 1111 1111 e posição deslocada 8 bits para direita

    //-----------------------------------------------------------

    //Escrita de bytes nos endereços
    EEPROM.write(endereco1, primeiroByte); 
    EEPROM.write(endereco2, segundoByte); 
  }
}

//---------------------------------------------------------------

//Função usada para ler inteiro de 2 bytes na EEPROM
int lerInt(int endereco1, int endereco2)
{ 
  //Variáveis locais inicializadas
  int  valor        = 0; 
  byte primeiroByte = EEPROM.read(endereco1);
  byte segundoByte  = EEPROM.read(endereco2); 

  //-------------------------------------------------------------

  //Deslocamento do segundo byte 8x para esquerda, formando o MSB ea soma com o primeiro byte LSB
  valor = (segundoByte << 8) + primeiroByte; 

  //Retorno do valor lido
  return valor; 
}

//---------------------------------------------------------------

//Procedimento usado para escrever string na EEPROM
void escreveString(int enderecoBase, String mensagem)
{ 
  //Verificação do tamanho da string a ser escrita e o tamanho disponível da EEPROM
  if (mensagem.length()>EEPROM.length() || (enderecoBase+mensagem.length()) >EEPROM.length())
  {
    //Mensagem de erro
    Serial.println ("A sua String não cabe na EEPROM"); 
  }
  else
  { 
    //Varrendo a string a ser adicionada na EEPROM
    for (int i = 0; i<mensagem.length(); i++)
    { 
      //Escrita na EEPROM de forma sequencial
      EEPROM.write(enderecoBase, mensagem[i]); 
       
      //Acrescenta endereço
      enderecoBase++; 
    }

    //Byte de fim de string
    EEPROM.write(enderecoBase,'\0'); 
  }
}

//---------------------------------------------------------------

//Função usada para escrever string na EEPROM
String leString(int enderecoBase)
{
  //Variáveis locais
  String mensagem = "";

  //-------------------------------------------------------------

  //Teste do endereço
  if (enderecoBase>EEPROM.length())
  { 
    //Retorna string vazia
    return mensagem;
  }
  else 
  { 
    //Variáveis locais
    char pos;

    //-----------------------------------------------------------

    //Armazena caracter até chegar no byte de fim de string
    do
    {
      //Posição de leitura
      pos = EEPROM.read(enderecoBase); 

      //Acrescenta endereço
      enderecoBase++; 

      //Concatenação de caracteres
      mensagem = mensagem + pos; 
    }
    while (pos != '\0'); 
  }

  //Retorno da string
  return mensagem; 
}
